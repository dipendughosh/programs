package happyFace;

import game.engine.*;
import game.physics.*;
import game.geometry.*;
import game.assets.*;
import java.io.*;

/**
 * InteractingBody provides the core class for non-emoticon, object
 * based player interaction, currently including to bouncers, spikes 
 * and liquids.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class InteractingBody extends Body {
    
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
        
    /**
     * Enumerates types defining the different supported forms of
     * interacting body and the strength of the interaction
     * alongside the values of this particular instance
     */
    public enum InteractionType { Bouncer, Liquid, Spiky } 
    InteractionType interactionType;

    public enum InteractionStrength { Weak, Mild, Strong }    
    InteractionStrength interactionStrength;
    
    /**
     * Sound effect variables for liquids, specifying the looping
     * sound to be played for the liquid and the range within
     * which the player can hear the sound effect (scaled with 
     * distance). An update frequency for the sound distance
     * test is also specified.
     */
    protected static final int SFX_UPDATE_FREQUENCY = 30;
    protected static final double LIQUID_SFX_RANGE = 300.0;
    SoundAssetClip liquidSfx = null;    
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new interacting body of the default type (beam bouncer)
     */        
    public InteractingBody(GameLayer gameLayer) {
        this(gameLayer, 0.0, 0.0, 2, "BouncerBeam1", 
                InteractionType.Bouncer, InteractionStrength.Mild, false);
    }
    
    /**
     * Create a new interacting body of the specified type and strength
     * <P>
     * Note: this constructor makes a number of assumptions about the type
     * of graphical asset that will realise the body (see code comments)
     */ 
    public InteractingBody(GameLayer gameLayer, 
            double x, double y, int drawOrder, String realisationName, 
            InteractionType interactionType, InteractionStrength interactionStrength, 
            boolean moveable) {

        super(gameLayer, x, y, drawOrder);
        
        // Retrieve the specified graphical realisation
        GraphicalAsset realisation = 
                assetManager.retrieveGraphicalAsset(realisationName);
        
        // Setup the realisation based on the name of the graphical realisation
        // - this does introduce assumptions concerning the name of assets
        // that can be used with this class
        Shape geometry;
        if (realisationName.indexOf("Circle", 0) >= 0) {
            geometry = new Circle(0.0, 0.0, realisation.width / 2.0);
        } else if (realisationName.indexOf("Ball", 0) >= 0) {
            geometry = new Circle(0.0, 0.0, realisation.width / 2.0 - 10.0);
        } else if (realisationName.indexOf("Column", 0) >= 0 
                || realisationName.indexOf("Platform", 0) >= 0) {
            geometry = new Box(0.0, 0.0, 
                    realisation.width - 20.0, realisation.height - 20.0);
        } else {
            geometry = new Box(0.0, 0.0, realisation.width, realisation.height);
        }
        
        setRealisation(realisation);
        setGeometry(geometry);
        
        // Setup the type of interaction to be provided by this instance
        defineInteraction(interactionType, interactionStrength, moveable);
    }
    
    /**
     * Create a new interacting body of the specified type and strength 
     * with the specified realisation and geometry
     */     
    public InteractingBody(GameLayer gameLayer, double x, double y, int drawOrder, 
            GraphicalAsset[] graphicalRealisation, Shape[] geometry, 
            InteractionType interactionType, InteractionStrength interactionStrength, 
            boolean moveable) {
        super(gameLayer, x, y, drawOrder);
        
        setRealisation(graphicalRealisation);
        setGeometry(geometry);
        
        // Setup the type of interaction to be provided by this instance        
        defineInteraction(interactionType, interactionStrength, moveable);
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////        
    
    /**
     * Setup the type of interaction to be provided by this instance
     */
    private void defineInteraction(
            InteractionType interactionType, InteractionStrength interactionStrength, 
            boolean moveable) {
        
        this.interactionType = interactionType;
        this.interactionStrength = interactionStrength;
        
        switch (interactionType) {
            // Define the parameters of a bouncer
            case Bouncer:
                restitution = 1.0;
                
                switch (interactionStrength) {
                    case Weak: restitution *= 0.3; break;
                    case Mild: restitution *= 1.0; break;
                    case Strong: restitution *= 1.5; break;
                }
                
                if (moveable) {
                    setMass(400.0);
                    setGravityEffected(true);
                } else {
                    setMass(Body.INFINITE_MASS);
                    setGravityEffected(false);
                }
                break;

            // Define the parameters of a liquid
            case Liquid:
                canIntersectOtherGraphicalObjects = false;
                setGravityEffected(false);
                
                switch (interactionStrength) {
                    case Weak:
                        liquidSfx = (SoundAssetClip) 
                                assetManager.retrieveSoundAsset( "LiquidWater" );
                        break;
                    case Mild:
                        liquidSfx = (SoundAssetClip) 
                                assetManager.retrieveSoundAsset( "LiquidAcid" );
                        break;
                    case Strong:
                        liquidSfx = (SoundAssetClip) 
                                assetManager.retrieveSoundAsset( "LiquidLava" );
                        break;
                }                
                break;
                
            // Define the parameters of a spiky object
            case Spiky:
                restitution = 0.1;
                
                if (moveable) {
                    setMass(600.0);
                    setGravityEffected(true);
                } else {
                    setMass(Body.INFINITE_MASS);
                    setGravityEffected(false);
                }
                break;
        }
    }
    
    /**
     * Update the interactive object based on other emoticon interaction
     */
    @Override
    public void update() {
        // Update any graphical animations
        for (int idx = 0; idx < graphicalRealisation.length; idx++) {
            graphicalRealisation[idx].update();
        }
        
        /**
         * Liquid update
         */
        
        if (interactionType == InteractionType.Liquid) {
            // Make this object able to intersect ther objects (to be used
            // within the collision detection algorithms - the liquid will be
            // set back to non intersecting after the check)
            this.canIntersectOtherGraphicalObjects = true;

            // Check for emoticon emersion and reduce the health of any
            // emersed emotions
            GameObjectCollection emoticons 
                    = gameLayer.getGameObjectCollection("Emoticons");
            for (int idx = 0; idx < emoticons.size; idx++) {
                if ( !((Emoticon)emoticons.gameObjects[idx]).canIgnoreInteractiveDamage() 
                        && GameObjectCollider.isIntersection(
                            this, emoticons.gameObjects[idx])) {
                    reduceHealth((Emoticon) emoticons.gameObjects[idx], 1.0);
                }
            }
            
            // Check for player emersion and reduce the health if needed
            // Also periodically update the liquid sound effect
            GameObject playerEmoticon = gameLayer.getGameObject("Player");
            if (playerEmoticon != null) {
                if (GameObjectCollider.isIntersection(this, playerEmoticon)) {
                    reduceHealth((Emoticon) playerEmoticon, 1.0);
                    
                    SoundAssetClip hitSfx = (SoundAssetClip) 
                            assetManager.retrieveSoundAssetArchetype(
                            ((Emoticon)playerEmoticon).getHitSoundEffect() );
                    if (!hitSfx.isPlaying()) {
                        hitSfx.play();
                    }
                }
                
                // If needed, determine the distance of the player is away from
                // the liquid and play a sound effect if within range
                if (gameEngine.updateCounter % SFX_UPDATE_FREQUENCY == 0) {
                    double distance = Math.pow(
                            Math.abs(this.x - playerEmoticon.x), 2.0) 
                                + Math.pow(Math.abs(this.y - playerEmoticon.y), 2.0);
                    if (distance < (LIQUID_SFX_RANGE + this.width) 
                            * (LIQUID_SFX_RANGE + this.height)) {
                        double sfxVolume = 0.4 - distance / 
                                ((LIQUID_SFX_RANGE + this.width) 
                                    * (LIQUID_SFX_RANGE + this.height) * 2.5) + 0.6;
                        if (liquidSfx.isPlaying() == false) {
                            liquidSfx.play();
                        }
                        liquidSfx.setVolume((float) sfxVolume);
                    } else {
                        if (liquidSfx.isPlaying()) {
                            liquidSfx.stop();
                        }
                    }
                }
            }
            
            // Set this object back to non-intersecting, i.e. the physics
            // update will permit other objects to overlap with the liquid
            this.canIntersectOtherGraphicalObjects = false;
        }
        
        /**
         * Spiky update
         */        
        
        if (interactionType == InteractionType.Spiky) {
            // Test for contact with emoticons and reduce their health if needed
            GameObjectCollection emoticons 
                    = gameLayer.getGameObjectCollection("Emoticons");
            for (int idx = 0; idx < emoticons.size; idx++) {
                if ( !((Emoticon)emoticons.gameObjects[idx]).canIgnoreInteractiveDamage()
                        && GameObjectCollider.isIntersection(
                            this, emoticons.gameObjects[idx])) {
                    reduceHealth((Emoticon) emoticons.gameObjects[idx], 50.0);
                }
            }
            
            // Test for contact with the player and reduce health if needed
            GameObject playerEmoticon = gameLayer.getGameObject("Player");
            if (playerEmoticon != null) {
                if (GameObjectCollider.isIntersection(this, playerEmoticon)) {
                    reduceHealth((Emoticon) playerEmoticon, 50.0);
                    
                    SoundAssetClip hitSfx = (SoundAssetClip) 
                            assetManager.retrieveSoundAssetArchetype(
                            ((Emoticon)playerEmoticon).getHitSoundEffect() );
                    if (!hitSfx.isPlaying()) {
                        hitSfx.play();
                    }
                }
            }
        }
        
        /**
         * Bouncer update
         */
        
        if (interactionType == interactionType.Bouncer) {
            // Bouncers have a high restitution by default, i.e. we only 
            // need to play a sound effect if the player hits a bouncer
            GameObject playerEmoticon = gameLayer.getGameObject("Player");
            if (playerEmoticon != null) {
                if (GameObjectCollider.isIntersection(this, playerEmoticon)) {
                    assetManager.retrieveSoundAssetArchetype("InteractiveBounce").play();
                }
            }
        }
    }
    
    /**
     * Reduce the health of the specified emoticon by the specified amount -
     * which is further scaled to take into account the strength of the 
     * interacting body and the impact velocity of the player, i.e running into
     * a spike at a high velocity will hurt a lot more than touching the spiky
     * object. 
     */
    private void reduceHealth(Emoticon emoticon, double amount) {
        amount *= (Math.pow(this.velocityx - emoticon.velocityx, 2.0) 
                + Math.pow(this.velocityy - emoticon.velocityy, 2.0)) / 1000000.0;
        if (amount < 1.0) amount = 1.0;
       
        switch (interactionStrength) {
            case Weak: emoticon.health -= amount * 0.5; break;
            case Mild: emoticon.health -= amount; break;
            case Strong: emoticon.health -= amount * 2.0; break;
        }
        
        if (emoticon.health < 0.0) {
            emoticon.triggerEmoticonDeath();
        }
    }
    
    /**
     * Store the game object state to the specified output stream
     */    
    @Override
    public void serialiseGameObjectState(
            ObjectOutputStream stream, GameObject gameObject) throws IOException {
        super.serialiseGameObjectState(stream, gameObject);
        
        // Store the interaction type and strenght
        stream.writeUTF(interactionType.toString());
        stream.writeUTF(interactionStrength.toString());
    }
        
    /**
     * Load in the game object state from the input stream
     */
    @Override
    public void loadGameObjectState(
            ObjectInputStream stream, GameLayer gameLayer) throws IOException {
        super.loadGameObjectState(stream, gameLayer);
        
        // Load the interaction type
        InteractionType interactionType;
        String interactionTypeString = stream.readUTF();
        if (interactionTypeString.compareTo("Bouncer") == 0) {
            interactionType = InteractionType.Bouncer;
        } else if (interactionTypeString.compareTo("Liquid") == 0) {
            interactionType = InteractionType.Liquid;
        } else if (interactionTypeString.compareTo("Spiky") == 0) {
            interactionType = InteractionType.Spiky;
        } else {
            throw new IllegalStateException("InteractingBody.loadGameObjectState:" 
                    + "Unsupported interaction type: " + interactionTypeString);
        }
        
        // Setup the interaction strength
        InteractionStrength interactionStrength;
        String interactionStrengthString = stream.readUTF();
        if (interactionStrengthString.compareTo("Weak") == 0) {
            interactionStrength = InteractionStrength.Weak;
        } else if (interactionStrengthString.compareTo("Mild") == 0) {
            interactionStrength = InteractionStrength.Mild;
        } else if (interactionStrengthString.compareTo("Strong") == 0) {
            interactionStrength = InteractionStrength.Strong;
        } else {
            throw new IllegalStateException("InteractingBody.loadGameObjectState:" 
                    + "Unsupported interaction strength: " + interactionStrengthString);
        }
                
        defineInteraction( interactionType, interactionStrength, 
                this.mass == Body.INFINITE_MASS ? false : true);
    }
}