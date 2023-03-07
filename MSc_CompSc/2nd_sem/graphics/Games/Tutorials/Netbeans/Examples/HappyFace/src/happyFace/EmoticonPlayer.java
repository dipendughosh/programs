package happyFace;

import java.awt.Graphics2D;
import java.awt.Composite;
import java.awt.AlphaComposite;
import java.awt.event.KeyEvent;
import java.awt.geom.AffineTransform;
import java.awt.event.KeyEvent;
import game.assets.*;
import game.engine.*;
        
/**
 * Refinement of the Emoticon class to provide a player controlled
 * emoticon.
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class EmoticonPlayer extends Emoticon {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Static key bindings for movement and/or bomb release.
     */
    public static int MOVE_LEFT_KEY = KeyEvent.VK_LEFT;
    public static int MOVE_RIGHT_KEY = KeyEvent.VK_RIGHT;
    public static int JUMP_UP_KEY = KeyEvent.VK_UP;
    public static int STOP_BOUNCE_KEY = KeyEvent.VK_DOWN;

    public static int SMALL_BOMB_KEY = KeyEvent.VK_Z;
    public static int MEDIUM_BOMB_KEY = KeyEvent.VK_X;
    public static int LARGE_BOMB_KEY = KeyEvent.VK_C;

    /**
     * Maximum player health (also equal to the initial
     * player health) alongside the number of player lifes
     */
    public static final int MAX_PLAYER_HEALTH = 200;
    public static final int INITIAL_PLAYER_LIFES = 3;
    public int numPlayerLifes = INITIAL_PLAYER_LIFES; 

    /**
     * Delay, in update ticks, between bomb throws
     */
    public static final int BOMB_THROW_DELAY = 20;
    private int bombThrowDelay = 0;
    
    /**
     * Player's score
     */
    public int playerScore = 0;

    /**
     * Current number of small, medium and large bombs
     */
    public int numSmallBombs = 0;
    public int numMediumBombs = 0;
    public int numLargeBombs = 0;

    /**
     * Player velocity from the last update which can be
     * compared against the current velocity to detect 
     * sudden changes in velocity (i.e. playing a sound effect
     * when hitting the ground from a large fall)
     */    
    private double lastVelocityx = 0.0;
    private double lastVelocityy = 0.0;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new player controlled emoticon of the default type (i.e. devil)
     */
    public EmoticonPlayer( HappyFaceLevelLayer gameLayer  ) { 
        this( gameLayer, "EmoticonDevil", 0.0, 0.0, 0 );
    }
    
    /**
     * Create a new player controlled emoticon of the specified type
     */    
    public EmoticonPlayer( HappyFaceLevelLayer gameLayer, String emoticonType  ) {
        this( gameLayer, emoticonType, 0.0, 0.0, 0 );
    }
    
    /**
     * Create a new player controlled emoticon of the specified type at
     * the specified location
     */
    public EmoticonPlayer( HappyFaceLevelLayer gameLayer, String emoticonType, 
            double x, double y  ) {
        this( gameLayer, emoticonType, 0.0, 0.0, 0 );
    }
    
    /**
     * Create a new player controlled emoticon of the specified type at
     * the specified location and with the specified draw order
     */
    public EmoticonPlayer( HappyFaceLevelLayer gameLayer, String emoticonType, 
            double x, double y, int drawOrder  ) {
        super( gameLayer, emoticonType, x, y, drawOrder );                

        happyEmoticon = false;
        
        // Set the inherited health to the maximum player health
        health = MAX_PLAYER_HEALTH;        
        
        jumpingRestitution = 2.0;
        restingRestitution = 2.0;
        contractedRestitution = 1.0;
        
        NUM_ANIMATION_FADE_FRAMES = 160;        
    }    

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Get/set methods                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Add the specified number of small bombs
     */
    public void addSmallBombs( int numSmallBombs ) {
        this.numSmallBombs += numSmallBombs;
    }
    
    /**
     * Add the specified number of medium bombs
     */
    public void addMediumBombs( int numMediumBombs ) {
        this.numMediumBombs += numMediumBombs;
    }

    /**
     * Add the specified number of large bombs
     */
    public void addLargeBombs( int numLargeBombs ) {
        this.numLargeBombs += numLargeBombs;
    }
    
    /**
     * Add the specified number of extra lifes
     */
    public void addLife() {
        numPlayerLifes++;
    }

    /**
     * Set the number of player lifes to that specified
     */
    public void setLife( int numPlayerLifes ) {
        this.numPlayerLifes = numPlayerLifes;
    }
    
    /**
     * Remove a life from the player
     */
    public void removeLife() {
        if( numPlayerLifes > 0 )
            numPlayerLifes--;
    }
    
    /**
     * Add the specified amount of health to the player
     */    
    @Override
    public void addHealth( double health ) {
        this.health += health;
        if( this.health > MAX_PLAYER_HEALTH )
            this.health = MAX_PLAYER_HEALTH;
    }
    
    /**
     * Set the player's health to that specified
     */
    @Override
    public void setHealth( double health ) {
        this.health = health;
        if( this.health > MAX_PLAYER_HEALTH )
            this.health = MAX_PLAYER_HEALTH;
    }
    
    /**
     * Return the player's score
     */ 
    public int getScore() {
        return playerScore;
    }

    /**
     * Set the player's score to that specified
     */
    public void setScore( int playerScore ) {
        this.playerScore = playerScore;
    }

    /**
     * Add the specified amount onto the player's score
     */
    public void addScore( int score ) {
        playerScore += score;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update                                                       //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the emoticon based upon player input
     */
    @Override
    public void update() {        
        if( bombThrowDelay > 0 ) 
            bombThrowDelay--;

        // If the player emoticon is alive then check for player input
        if( !emoticonDead )       
            updateStateBasedOnKeys();

        // Update the emoticons movement
        super.update();
        
        // If the emoticon is subject to rapid x deceleration then play
        // an appropriate sound effect
        if( Math.signum( velocityx ) != Math.signum( lastVelocityx ) 
                || Math.abs( velocityx ) < 100.0 ) {
            double velDifference = Math.abs( velocityx - lastVelocityx );            

            if( velDifference > 1500.0 )
                assetManager.retrieveSoundAssetArchetype( "EmoticonLandHard" ).play();
            else if( velDifference > 200.0 ) {
                SoundAssetClip landSfx = (SoundAssetClip)
                    assetManager.retrieveSoundAssetArchetype( "EmoticonLand" );               
                float volume = (float)(velDifference / 3000.0) + 0.7f;                        
                landSfx.setVolume( volume < 1.0f ? volume : 1.0f );
                landSfx.play();                
            }
        } 

        // If the emoticon is subject to rapid y deceleration then play
        // an appropriate sound effect
        if( Math.signum( velocityy ) != Math.signum( lastVelocityy ) 
                || Math.abs( velocityy ) < 100.0 ) {    
            double velDifference = Math.abs( velocityy - lastVelocityy );            
            
            if( velDifference > 1500.0 )
                assetManager.retrieveSoundAssetArchetype( "EmoticonLandHard" ).play();
            else if( velDifference > 200.0 ) {
                SoundAssetClip landSfx = (SoundAssetClip)
                    assetManager.retrieveSoundAssetArchetype( "EmoticonLand" );               
                float volume = (float)(velDifference / 3000.0) + 0.7f;                        
                landSfx.setVolume( volume < 1.0f ? volume : 1.0f );
                landSfx.play();                
            }
        }        
        
        // If the player is not pressing a key then slowly 
        // bring the emoticon to a stop
        if( !moveLeft && !moveRight && !moveUp )
            GameObjectUtilities.dampenVelocities( this, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 );

        // If the emoticon is dead, then provide it with a slightly
        // downwards movement and fade out an expanding emoticon 
        if( emoticonDead ) {
            velocityy += 1.0;
            
            emoticonAnimationFrame++;
            if( emoticonAnimationFrame == NUM_ANIMATION_FADE_FRAMES ) {
                emoticonDead = false;
                emoticonAnimationFrame = 0;
                canIntersectOtherGraphicalObjects = true;
                velocityx = 0.0; velocityy = 0.0;
                setHealth( 200.0 );
                setDrawOrder( 3 );
                setRealisation( assetManager.retrieveGraphicalAsset( "EmoticonDevil" ) );                
                ((HappyFaceLevelLayer)gameLayer).considerPlayerDeath();
            }
        }

        lastVelocityx = velocityx;
        lastVelocityy = velocityy;
    }
       
    /**
     * Update the emoticon state based on the player's input
     */    
    private void updateStateBasedOnKeys() {
        if( inputEvent.keyPressed[MOVE_LEFT_KEY] )
            moveLeft = true;
        else moveLeft = false;
        
        if( inputEvent.keyPressed[MOVE_RIGHT_KEY] )
            moveRight = true;
        else moveRight = false;

        if( inputEvent.keyPressed[JUMP_UP_KEY] )
            moveUp = true;
        else moveUp = false;

        if( inputEvent.keyPressed[STOP_BOUNCE_KEY] )
            moveDown = true;
        else moveDown = false;

        if( inputEvent.keyTyped( SMALL_BOMB_KEY ) ) {
            if( bombThrowDelay == 0 && numSmallBombs > 0 ) {
                ExplodingBody explosion = new ExplodingBody(
                        gameLayer, x, y-height, drawOrder+1,
                        ExplodingBody.ExplosionBody.SmallBomb,
                        ExplodingBody.ExplosionType.Small,
                        velocityx, velocityy );
                explosion.igniteFuse();
                gameLayer.queueGameObjectToAdd( explosion, "Explosions" );
                numSmallBombs--;
                bombThrowDelay = BOMB_THROW_DELAY;
            }
        }
        
        if( inputEvent.keyTyped( MEDIUM_BOMB_KEY ) ) {
            if( bombThrowDelay == 0 && numMediumBombs > 0 ) {
                ExplodingBody explosion = new ExplodingBody(
                        gameLayer, x, y-height, drawOrder+1,
                        ExplodingBody.ExplosionBody.MediumBomb,
                        ExplodingBody.ExplosionType.Medium,
                        velocityx, velocityy );
                explosion.igniteFuse();
                gameLayer.queueGameObjectToAdd( explosion, "Explosions" );
                numMediumBombs--;
                bombThrowDelay = BOMB_THROW_DELAY;
            }
        }
        
        if( inputEvent.keyTyped( LARGE_BOMB_KEY ) ) {
            if( bombThrowDelay == 0 && numLargeBombs > 0 ) {
                ExplodingBody explosion = new ExplodingBody(
                        gameLayer, x, y-height, drawOrder+1,
                        ExplodingBody.ExplosionBody.LargeBomb,
                        ExplodingBody.ExplosionType.Large,
                        velocityx, velocityy );
                explosion.igniteFuse();
                gameLayer.queueGameObjectToAdd( explosion, "Explosions" );
                numLargeBombs--;
                bombThrowDelay = BOMB_THROW_DELAY;
            }
        }
    }
    
    /**
     * This method can be called whenever the emoticon has been killed and should
     * commence its remove animation
     */
    @Override
    public void triggerEmoticonDeath() {
        if( emoticonDead )
            return;
        
        super.triggerEmoticonDeath();
        setRealisation( assetManager.retrieveGraphicalAsset( "PlayerDeath" ) );
        numPlayerLifes--;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Draw                                                         //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Draw the graphical game object to the specified graphics object
     * at the specified x and y offset
     */
    @Override
    public void draw( Graphics2D graphics2D, int drawX, int drawY )
    {
        if( !emoticonDead )
            super.draw( graphics2D, drawX, drawY );
        else {
            // If the emoticon has been killed, then draw it with 
            // an increasing level of fade and increasing draw scale

            if( emoticonAnimationFrame >= NUM_ANIMATION_FADE_FRAMES )
                return;
            
            double scaleFactor = 1.0 +
                    (double)(emoticonAnimationFrame * 20)/(double)NUM_ANIMATION_FADE_FRAMES;
            
            Composite originalComposite = graphics2D.getComposite();
            graphics2D.setComposite( AlphaComposite.getInstance(
                    AlphaComposite.SRC_OVER,
                    Math.min( 1.0f, 1.0f * (1.0f - (float)emoticonAnimationFrame
                    /(float)NUM_ANIMATION_FADE_FRAMES ) ) ) );
            
            AffineTransform originalTransform = graphics2D.getTransform();
            graphics2D.transform(
                    AffineTransform.getScaleInstance( scaleFactor, scaleFactor ) );
            super.draw( graphics2D, (int)(drawX/scaleFactor), (int)(drawY/scaleFactor) );
            graphics2D.setTransform( originalTransform );
            graphics2D.setComposite( originalComposite );
        }
    }
}