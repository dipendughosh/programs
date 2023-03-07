package happyFace;

import game.engine.*;
import game.physics.*;
import game.geometry.*;
import game.components.*;
import game.assets.*;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;

/**
 * ExplodingBody provides a basic class that encapsulates an exploding
 * body.
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class ExplodingBody extends Body {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Radius within which explosion sound effects can be heard
     */
    private static final double SFX_EXPLOSION_AUDIO_RADIUS = 10000.0;

    /**
     * Flag determining if a count down will be displayed over the 
     * bomb whenever the fuse has been triggered
     */
    public static boolean DISPLAY_COUNTDOWN = true;

    /**
     * Enumerated types 
     */        
    public enum ExplosionBody { SmallBomb, MediumBomb, LargeBomb }
    public enum ExplosionType { Small, Medium, Large }

    /**
     * Mass of the bomb object (before explosion)
     */    
    private double bombMass = 10.0;

    /**
     * Parameters that control the type of explosion. The fuse duration
     * determines the length of the fuse (in ms), the explosion radius
     * determines the maximum radius within which the explosion will 
     * effect other objects, the associated explosionDissipation 
     * determines the distance needed to reduce the explosive force by
     * 50%, the explosionForce and explosionVelocity determine the 
     * force (ability to break other objects) and expansive velocity
     * of the explosion. Finally, explosionTurnDuration determines the
     * length of the explosion.
     */
    private double fuseDuration = 3000;
    private double explosionRadius = 200.0;
    private double explosionDissipation = 200.0;
    private double explosionVelocity = 1000.0;
    private double explosionForce = 1000.0;
    private int explosionTurnDuration = 8;

    /**
     * Variables used to track if the fuse has been ignited or the
     * bomb has exploded alongside the count down sound effect
     * index within the sound asset assembly (i.e. for stopping
     * the relevant sound clip)
     */
    private boolean fuseIgnited = false;
    private long fuseIgnitionTime;
    private boolean exploded = false;
    private int fuseIgnitedSfxIndex = 0;

    /**
     * Center x and y of the explosion and current explosion turn
     */    
    private double centerX;
    private double centerY;
    private int currentTurn = 1;

    /**
     * Text element used to display the fuse countdown
     */
    private TextElement timeRemainingText;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////

    /** 
     * Create a new instance of ExplodiingBody 
     */
    public ExplodingBody(GameLayer gameLayer,  double x, double y, int drawOrder, 
            ExplosionBody explosionBody, ExplosionType explosionType, 
            double offsetVelocityx, double offsetVelocityy) {
        super(gameLayer, x, y, drawOrder);

        // Define the explosion parameters
        defineExplosion(explosionBody, explosionType);

        // Provide the bomb with the specified initial velocity (i.e. when
        // created a bomb takes on the velocity of the player)
        this.velocityx = offsetVelocityx;
        this.velocityy = offsetVelocityy;

        // Create a new text element of displaying the fuse count down
        timeRemainingText = new game.components.TextElement(gameLayer, 
                (ImageAssetSequence) assetManager.retrieveAsset( "GUIFontSmall" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"$%^&*()-+={}[];:'@#~,.<>/\\?            ", "");
        timeRemainingText.setAlignment(TextElement.Alignment.Centre);
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Define the type of explosion to be used
     */    
    private void defineExplosion(
            ExplosionBody explosionBody, ExplosionType explosionType) {

        switch (explosionType) {
            case Small:
                explosionRadius = 100.0;
                explosionVelocity = 1000.0;
                explosionForce = 200.0;
                explosionDissipation = 1000.0;
                explosionTurnDuration = 8;
                break;
            case Medium:
                explosionRadius = 200.0;
                explosionVelocity = 4000.0;
                explosionForce = 1000.0;
                explosionDissipation = 4000.0;
                explosionTurnDuration = 14;
                break;
            case Large:
                explosionRadius = 300.0;
                explosionVelocity = 2000.0;
                explosionForce = 3000.0;
                explosionDissipation = 3000.0;
                explosionTurnDuration = 20;
                break;
        }

        ImageAssetSequence realisation = null;
        switch (explosionBody) {
            case SmallBomb:
                bombMass = 10.0;
                fuseDuration = 3000;
                realisation = (ImageAssetSequence) assetManager.retrieveAsset( "SmallBomb" );
                realisation.offsetY = -10.0;
                setGeometry(new Circle(0.0, 0.0, 15.0));
                break;
            case MediumBomb:
                bombMass = 30.0;
                fuseDuration = 4000;
                realisation = (ImageAssetSequence) assetManager.retrieveAsset( "MediumBomb" );
                realisation.offsetX = 8.0;
                realisation.offsetY = -5.0;
                setGeometry(new Circle(0.0, 0.0, 20.0));
                break;
            case LargeBomb:
                bombMass = 50.0;
                fuseDuration = 6000;
                realisation = (ImageAssetSequence) assetManager.retrieveAsset( "LargeBomb" );
                realisation.offsetY = -5.0;
                setGeometry(new Box(0.0, 0.0, 35.0, 50.0));
                break;
        }

        setRealisation(realisation);
        setMass(bombMass);
        this.setGravityEffected(true);
        this.setEnableAtRestDetermination(false);
        
    }

    /**
     * Set the fuse duration to that specified
     */
    public void setFuseDuration(double fuseDuration) {
        this.fuseDuration = fuseDuration;
    }
    
    /**
     * Ignite the fuse, i.e. start the countdown until explosion
     */    
    public void igniteFuse() {
        fuseIgnited = true;
        fuseIgnitionTime = System.nanoTime() / 1000000L;

        SoundAssetAssembly fuseIgnitedSfx = (SoundAssetAssembly) assetManager
                .retrieveAssetArchetype( "FuseIgnited" );
        fuseIgnitedSfxIndex = fuseIgnitedSfx.play();
    }

    /**
     * Update the bomb
     */
    @Override
    public void update() {
        // Update an animation associated with the bomb
        getRealisation(0).update();
        
        // If the fuse has yet to be ignited then simply return
        if (!fuseIgnited) {
            return;
        } else if (!exploded && System.nanoTime() / 1000000L > fuseIgnitionTime + fuseDuration) {
            exploded = true;

            // If the bomb has just exploded then stop the count down sfx
            if (fuseIgnitedSfxIndex >= 0) {
                SoundAssetAssembly fuseIgnitedSfx = (SoundAssetAssembly) assetManager
                        .retrieveAssetArchetype( "FuseIgnited" );
                fuseIgnitedSfx.stop(fuseIgnitedSfxIndex);
            }

            // Play a suitable explosion sound, scaled by the display to the player
            GameObject player = gameLayer.getGameObject("Player");
            if (player != null) {
                double sfxVolume = 1.0 - Math.pow(Math.sqrt((
                        this.x - player.x) * (this.x - player.x) + 
                        (this.y - player.y) * (this.y - player.y)) 
                            / SFX_EXPLOSION_AUDIO_RADIUS, 2);

                if (sfxVolume > 0.0) {
                    SoundAssetAssembly explosionSfx = (SoundAssetAssembly) assetManager
                            .retrieveAssetArchetype( graphicalRealisation[0].getAssetName() + "Explosion" );

                    explosionSfx.setVolume((float) sfxVolume);
                    explosionSfx.play();
                }
            }

            // Store the center of the explosion and change the graphical
            // realisation of the bomb to the bomb explosion animation
            centerX = x; centerY = y;
            ImageAssetSequence realisation = 
                    (ImageAssetSequence) assetManager.retrieveAsset( "BombExplosion" );
            realisation.setAnimationPeriod( 
                    explosionTurnDuration * gameEngine.getGameUpdatePeriod() / 1000000);
            setRealisation(realisation);

            // Create a total of 8 circular bomb fragments (it is there
            // fragments that will expand outwards, based on the parameters
            // of the bomb, and interact with other game objects (i.e.
            // simulating the effect of the blast force
            for (int idx = 0; idx < 8; idx++) {
                Body fragment = new Body(gameLayer, x, y);
                fragment.setName(gameObjectName + "Element" + idx);
                fragment.setMass(explosionForce);
                fragment.setGeometry(new Circle(0.0, 0.0, 1.0));
                gameLayer.queueGameObjectToAdd(fragment);
            }

            return;
        }

        // Return if the bomb has yet to explode
        if (!exploded) {
            return;
        }
                
        if (currentTurn > explosionTurnDuration) {
            // If the bomb has finished exploding, then apply the final upate 
            // and queue the bomb object and each of the associated exploded
            // fragments to be removed
            x = centerX; y = centerY;
            velocityx = explosionVelocity * (currentTurn % 2 == 0 ? 1.0 : -1.0);
            velocityy = explosionVelocity * ((currentTurn / 2) % 2 == 0 ? 1.0 : -1.0);

            gameLayer.queueGameObjectToRemove(this);
            for (int idx = 0; idx < 8; idx++) {
                GameObject fragment = gameLayer.getGameObject(gameObjectName + "Element" + idx);
                gameLayer.queueGameObjectToRemove(fragment);
            }
        } else {
            // If the bomb is currently in the process of exploding then, reset
            // it's center of explosion and work out the current explosion radius
            // and explosive force. Based on this, each explosion fragment is 
            // updated - in effect this code will expand the radius, whilst 
            // reducing the explosive force of each bomb fragment so that it forms
            // a total of eight expanding circles that expand outwards from the 
            // center of the blast.
            x = centerX; y = centerY;

            double currentExplosionRadius = explosionRadius * 
                    ((double) currentTurn / (double) explosionTurnDuration);
            double elementRadius = currentExplosionRadius / 3.412;
            double elementOffset = elementRadius * 2.412;
            double elementForce = explosionForce / 
                    Math.pow(2.0, currentExplosionRadius / explosionDissipation);

            for (int idx = 0; idx < 8; idx++) {
                Body fragment = (Body) 
                        gameLayer.getGameObject( gameObjectName + "Element" + idx );
                fragment.x = centerX; fragment.y = centerY;
                ((Circle) fragment.geometry[0]).setRadius(elementRadius);
                fragment.setGeometry(fragment.geometry);
                fragment.setMass(elementForce);

                switch (idx) {
                    case 0:
                        fragment.x += 0.707 * elementOffset;
                        fragment.y += 0.707 * elementOffset;
                        fragment.velocityx = explosionVelocity;
                        fragment.velocityy = explosionVelocity;
                        break;
                    case 1:
                        fragment.x += elementOffset;
                        fragment.velocityx = explosionVelocity;
                        fragment.velocityy = 0.0;
                        break;
                    case 2:
                        fragment.x += 0.707 * elementOffset;
                        fragment.y -= 0.707 * elementOffset;
                        fragment.velocityx = explosionVelocity;
                        fragment.velocityy = -explosionVelocity;
                        break;
                    case 3:
                        fragment.y += elementOffset;
                        fragment.velocityx = 0.0;
                        fragment.velocityy = explosionVelocity;
                        break;
                    case 4:
                        fragment.y -= elementOffset;
                        fragment.velocityx = 0.0;
                        fragment.velocityy = -explosionVelocity;
                        break;
                    case 5:
                        fragment.x -= 0.707 * elementOffset;
                        fragment.y += 0.707 * elementOffset;
                        fragment.velocityx = -explosionVelocity;
                        fragment.velocityy = explosionVelocity;
                        break;
                    case 6:
                        fragment.x -= elementOffset;
                        fragment.velocityx = -explosionVelocity;
                        fragment.velocityy = 0.0;
                        break;
                    case 7:
                        fragment.x -= 0.707 * elementOffset;
                        fragment.y -= 0.707 * elementOffset;
                        fragment.velocityx = -explosionVelocity;
                        fragment.velocityy = -explosionVelocity;
                        break;
                }
            }
        }

        currentTurn++;
    }

    /**
     * Draw the graphical game object to the specified graphics object
     * at the specified x and y offset
     */
    @Override
    public void draw(Graphics2D graphics2D, int drawX, int drawY) {
        if (!exploded) {
            // If the bomb has yet to explode then draw the bomb image
            // and overlay the count down timer if needed
            super.draw(graphics2D, drawX, drawY);

            if (DISPLAY_COUNTDOWN && fuseIgnited) {
                int secondsRemaining = (int) (Math.ceil( (fuseDuration 
                        - (System.nanoTime()/1000000L - fuseIgnitionTime))/1000.0));
                timeRemainingText.setText("" + secondsRemaining);
                timeRemainingText.draw(graphics2D, drawX, drawY);
            }
        } else {
            // If the bomb has exploded then scale and draw the bomb
            // explosion animation to reflect the magnitude of the
            // bomb explosion
            BufferedImage explosionFrame = 
                    ((ImageAssetSequence) graphicalRealisation[0]).getImageRealisation();

            int currentExplosionRadius = (int) (1.5 * explosionRadius * 
                    ((double)currentTurn / (double)explosionTurnDuration));

            graphics2D.drawImage(explosionFrame, drawX - currentExplosionRadius, 
                    drawY - currentExplosionRadius, currentExplosionRadius * 2, 
                    currentExplosionRadius * 2, null);
        }
    }
}