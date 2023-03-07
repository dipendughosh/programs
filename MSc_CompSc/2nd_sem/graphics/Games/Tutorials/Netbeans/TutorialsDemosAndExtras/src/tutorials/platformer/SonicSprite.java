package tutorials.platformer;

import game.engine.*;
import game.assets.*;
import game.physics.*;
import game.geometry.*;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.image.*;

/**
 * Example sprite that can be used within platform games
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class SonicSprite extends Body {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * The Sonic sprite can be in one of three different states,
     * running, waiting or jumping. The current state that the
     * sprite is in will determine the graphical realisation that
     * is used by the sprite.
     */
    public enum SonicState { RUNNING, WAITING, JUMPING }
    private SonicState sonicState;
    
    /**
     * The Sonic sprite can either be facing left or right. As with
     * the SonicState enumerated type, this type is used to
     * determine in which directions the graphical images should
     * be drawn (this sprite only loads in right facing images,
     * if the sprite is facing to the left, then the images will
     * be flipped before they are drawn).
     */
    public enum SonicFacing { LEFT, RIGHT }
    private SonicFacing sonicFacing;

    /**
     * Define the run, fly and jump velocities
     */
    private double SPRITE_BASE_RUN_VELOCITY = 10.0;
    private double SPRITE_BASE_FLY_VELOCITY = 20.0;
    private double SPRITE_BASE_JUMP_VELOCITY = 250.0;
    
    /**
     * Define the maximum player x velocity
     */
    private double SPRITE_MAX_X_VELOCITY = 400.0;
    
    /**
     * Define the x velocity deceleration, i.e. the amount the 
     * velocity will be reduced by each update towards zero.
     */
    private static final double X_VELOCITY_DECELERATION = 20.0;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Sonic sprite
     *
     * @param gameLayer GameLayer instance to which the shield belongs
     */
    public SonicSprite( GameLayer gameLayer ) {
        super( gameLayer );
        
        // Give this sprite a name which we permit us to retrieve it if needed
        setName( "Sonic" );
        
        // Give each sprite a large mass - this permits the sprite to easily
        // push past large numbers of ball sprites. You might want to vary
        // this to explore different effects.
        setMass( 500.0 );
        
        // Set the resitution of the sprite to 0.0, i.e. the sprite won't
        // 'bounce' if it falls against the ground from a fall - although
        // it might be nice to have some bouncing for certain types of game.
        restitution = 0.0;
        
        // Setup the defaut Sonic game state and graphical realisation
        sonicState = SonicState.WAITING;
        sonicFacing = SonicFacing.RIGHT;
                
        // Define the graphical look of the sprite and also setup the sprite's
        // geometry. The geometry is sized to be slightly less than the width
        // of the sonic waiting image to reflect that the sonic image has
        // spiky hair that sticks out! A better appraoach would have been
        // to define a proper geometry based on the image and then to swap
        // that geometry around as the sprite changes direction.
        GraphicalAsset sonicWaiting 
                = assetManager.retrieveGraphicalAsset("SonicWaiting");
        setRealisationAndGeometry( sonicWaiting );
        setGeometry( new Box( 0, 0, sonicWaiting.width-20, sonicWaiting.height ) );        
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the Sonic sprite
     */
    @Override
    public void update() {
        // Record the Sonic state upon entry - towards the end of the update
        // we will check to see if the Sonic state has changed, if so, then
        // we'll change the graphical realisation to reflect the new state.
        SonicState sonicStateOnEntry = sonicState;
        
        ///////////////////////////////////////////////////////
        // Up and down movement                              //
        ///////////////////////////////////////////////////////
        
        // Check to see if the player wish to move up or down, if so then
        // increase (or decrease) the y velocity by an appropriate amount.
        if( inputEvent.keyPressed[ KeyEvent.VK_UP ]
                && !inputEvent.keyPressed[ KeyEvent.VK_DOWN ] ) {
            velocityy -= SPRITE_BASE_FLY_VELOCITY;
        } else if( inputEvent.keyPressed[ KeyEvent.VK_DOWN ]
                && !inputEvent.keyPressed[ KeyEvent.VK_UP ] ) {
            velocityy += SPRITE_BASE_FLY_VELOCITY;
        }
        
        ///////////////////////////////////////////////////////
        // Left, right movement                              //
        ///////////////////////////////////////////////////////
        
        if( inputEvent.keyPressed[ KeyEvent.VK_RIGHT ]
                && !inputEvent.keyPressed[ KeyEvent.VK_LEFT ] ) {
            // If the player wishes to move to the right then
            // update the facing, and provided we are not
            // currently in a jumping state, set the
            // Sonic state to running and update the x velocity.
            // If we are currently jumping, then do not
            // change the state to running and update the
            // x velocity by a smaller amount.
            
            sonicFacing = SonicFacing.RIGHT;
            
            if( sonicState != SonicState.JUMPING ) {
                sonicState = SonicState.RUNNING;
                velocityx += SPRITE_BASE_RUN_VELOCITY;
            } else
                velocityx += 0.25 * SPRITE_BASE_RUN_VELOCITY;
        } else if( inputEvent.keyPressed[ KeyEvent.VK_LEFT ]
                && !inputEvent.keyPressed[ KeyEvent.VK_RIGHT ] ) {
            // If the player wishes to move to the left then
            // update the facing, and provided we are not
            // currently in a jumping state, set the
            // Sonic state to running and update the x velocity.
            // If we are currently jumping, then do not
            // change the state to running and update the
            // x velocity by a smaller amount.
            
            sonicFacing = SonicFacing.LEFT;
            
            if( sonicState != SonicState.JUMPING ) {
                sonicState = SonicState.RUNNING;
                velocityx -= SPRITE_BASE_RUN_VELOCITY;
            } else
                velocityx -= 0.25 * SPRITE_BASE_RUN_VELOCITY;
        } else {
            // If the player does not want to move to the left
            // or the right, then if we're not jumping (which
            // includes falling down) then set the Sonic state
            // to waiting and decrease the x velocity by the
            // specified amount (towards a zero x velocity).
            // If we are currently jumping, then we still decrease
            // the x velocity but by a smaller amount.
            
            if( sonicState != SonicState.JUMPING ) {
                sonicState = SonicState.WAITING;
                
                GameObjectUtilities.dampenVelocities(this,
                        X_VELOCITY_DECELERATION, X_VELOCITY_DECELERATION,
                        0.0, 0.0, 0.0, 0.0);
            } else {
                GameObjectUtilities.dampenVelocities(this,
                        X_VELOCITY_DECELERATION*0.2, X_VELOCITY_DECELERATION*0.2,
                        0.0, 0.0, 0.0, 0.0);
            }
        }
        
        ///////////////////////////////////////////////////////
        // Jumping  / Falling                                //
        ///////////////////////////////////////////////////////
        
        /**
         * Work out if we are currently touching a platform. The calculation for
         * this is approximate in that each platform is considered and if the 
         * sonic sprite is on top of the platform (including a 1 pixel overlap)
         * and within 10 pixels either above or below the platform, then it 
         * is considered to be touching the platform. The test could be made
         * more demanding by requiring the sprite to overlap the platform by 
         * at least x pixels (in have a good enough 'foothold' to jump). The
         * value of 10 above or 10 below was selected to reflect the fact
         * that the physics simulation is not 100% precise (i.e. the physics
         * simulation permits objects to overlap, with the overlap then 
         * corrected - i.e. sonic may be slightly below the surface during
         * one update and then slightly above during the next corrected update).
         */
        boolean touchingPlatform = false;
        GameObjectCollection platforms =
                gameLayer.getGameObjectCollection("Platforms" );
        double sonicBasey = this.y+this.height/2;
        for( int idx = 0; !touchingPlatform && idx < platforms.size; idx++ ) {
            double overlap = 10.0;
            Body platform = (Body)platforms.gameObjects[idx];
            if(
                    sonicBasey - (platform.y-platform.height/2) < 10.0
                    && sonicBasey - (platform.y-platform.height/2) > -10.0
                    && this.x + this.width/2 - overlap > platform.x - platform.width/2
                    && this.x - this.width/2 + overlap < platform.x + platform.width/2 )
                touchingPlatform = true;
        }

        /**
         * If the sprite is in the jumping state and also touching a platform, then
         * set the state to waiting (i.e. the sprite has managed to hit ground)
         */
        if( sonicState == SonicState.JUMPING )
            if( touchingPlatform )
                if( this.velocityy < SPRITE_BASE_JUMP_VELOCITY )
                    sonicState = SonicState.WAITING;

        /**
         * If we can jump and the player wishes to jump, then set the sprite
         * state to jumping and give us a suitably strong upwards velocity.
         */
        if( inputEvent.keyPressed[ KeyEvent.VK_SPACE] ) {
            if( touchingPlatform ) {
                // If we can jump and the player wishes to jump, then set the sprite
                // state to jumping and give us a suitably strong upwards velocity.
                sonicState = SonicState.JUMPING;
                velocityy -= SPRITE_BASE_JUMP_VELOCITY;
            }
        }
        
        ///////////////////////////////////////////////////////
        // Position Update and Falling                       //
        ///////////////////////////////////////////////////////
        
        // If the player walks, or jumps, of the edge of a platform
        // the sprite will fall downwards. We wish to detect this to
        // enable a suitable animation to be set (we use the same
        // animation as used for jumping, but you could have an
        // explicit fall animation if desired).        
        if( velocityy > ((CollisionSpace)gameLayer).getGravityY() /  10.0 )
            sonicState = SonicState.JUMPING;
        
        
        // If we have a change in state of the sprite, then update the
        // graphical realisation to one that is appropriate to the new state
        // The geometry does not change from the starting at rest geometry
        if( this.sonicState != sonicStateOnEntry ) {
            switch( sonicState ) {
                case RUNNING: setRealisation( "SonicRunning" ); break;
                case WAITING: setRealisation( "SonicWaiting" ); break;
                case JUMPING: setRealisation( "SonicJumping" ); break;
            }
        }

        // Use one of the methods within the GameObjectUtilities class to
        // ensure that the sprite's x velocity cannot exceed the 
        // defined maximum values
        GameObjectUtilities.clampVelocities(this,
                SPRITE_MAX_X_VELOCITY, SPRITE_MAX_X_VELOCITY,
                Double.MAX_VALUE, Double.MAX_VALUE,  0.0, 0.0 );
        
        // Finally, ensure that the sonic sprite is always pointing upwards.
        // The physics simulation may give the sprite a rotation or angular
        // velocity as it moves about the level, by setting things to zero we
        // ensure that the sprite always remains upright. 
        this.rotation = 0.0;
        this.angularVelocity = 0.0;        
    }
    
    /**
     * This is an overloaded version of the GameObject draw method
     * which is obtained through inheritance. As we only have right facing
     * animations, if we are facing to the left, then we flip the images to
     * the left. Note the actual GameObject draw method is a tad more
     * complex as it support game objects with multipe graphical assets,
     * however, we know for this class we will only have one graphical
     * realisation shown at a time.
     */
    @Override
    public void draw( Graphics2D graphics2D, int drawX, int drawY ) {
        BufferedImage currentRealisation = getRealisation(0).getImageRealisation();
        int width = currentRealisation.getWidth();
        int height = currentRealisation.getHeight();
        
        if( this.sonicFacing == SonicFacing.LEFT )
            graphics2D.drawImage( currentRealisation,
                    drawX+width/2, drawY-height/2, drawX-width/2, drawY+height/2,
                    0, 0, width, height, null );
        else
            graphics2D.drawImage( currentRealisation,
                    drawX-width/2, drawY-height/2, drawX+width/2, drawY+height/2,
                    0, 0, width, height, null );
    }
}