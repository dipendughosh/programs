package happyFace;

import java.awt.Graphics2D;
import java.awt.Composite;
import java.awt.AlphaComposite;
import java.awt.geom.AffineTransform;
import java.util.*;
import game.engine.*;
import java.io.*;

/**
 * Refinement of the Emoticon class to provide AI control over the 
 * emoticon in terms of patrolling, chasing, and jumping.
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class EmoticonAI extends Emoticon {
    
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Default AI update period, i.e. every 10 update ticks the
     * AI update will fire to consider emoticon changes
     */
    public int AI_UPDATE_FREQUENCY = 10;

    /**
     * Patrol range values (from extra small or extra large)
     */
    public static final double PATROL_RANGE_XS      = 30.0;
    public static final double PATROL_RANGE_S       = 100.0;
    public static final double PATROL_RANGE_M       = 200.0;
    public static final double PATROL_RANGE_L       = 400.0;
    public static final double PATROL_RANGE_XL      = 800.0;

    /**
     * Jump probability values (from extra small or extra large)
     */
    public static final double JUMP_PROBABILITY_XS  = 0.0;
    public static final double JUMP_PROBABILITY_S   = 0.2;
    public static final double JUMP_PROBABILITY_M   = 0.5;
    public static final double JUMP_PROBABILITY_L   = 0.8;
    public static final double JUMP_PROBABILITY_XL  = 1.0;
    
    /**
     * Jump frequency values (from extra small or extra large)
     */
    public static final long JUMP_FREQUENCY_XS      = 1;
    public static final long JUMP_FREQUENCY_S       = 60;
    public static final long JUMP_FREQUENCY_M       = 240;
    public static final long JUMP_FREQUENCY_L       = 600;
    public static final long JUMP_FREQUENCY_XL      = Long.MAX_VALUE;
        
    /**
     * Chase range values (from extra small or extra large)
     */
    public static final double CHASE_RANGE_XS    = 100.0;
    public static final double CHASE_RANGE_S     = 200.0;
    public static final double CHASE_RANGE_M     = 400.0;
    public static final double CHASE_RANGE_L     = 800.0;
    public static final double CHASE_RANGE_XL    = 100000.0;
    
    /**
     * Visibility range values (from extra small or extra large)
     */
    public static final double VISIBLE_RANGE_XS    = 100.0;
    public static final double VISIBLE_RANGE_S     = 200.0;
    public static final double VISIBLE_RANGE_M     = 400.0;
    public static final double VISIBLE_RANGE_L     = 800.0;
    public static final double VISIBLE_RANGE_XL    = 100000.0;
    
    /**
     * Movement AI for the emoticon. Each AI emoticon can patrol 
     * around a central point or remain stationary
     */     
    public enum MovementAI { Stationary, Patrol }
    protected MovementAI movementAI = MovementAI.Stationary;
    
    /**
     * Chase AI for the emoticon. Each AI emoticon can either
     * ignore the player, chase the emoticon, or chase whilst
     * only in the chase range.
     */
    public enum ChaseAI { Ignore, Chase, ChaseInRange }
    protected ChaseAI chaseAI = ChaseAI.Ignore;

    /**
     * Variables holding the current AI parameter values
     */
    protected double visibleRange = VISIBLE_RANGE_M;
    protected double chaseRange = CHASE_RANGE_M;
    protected double patrolRange = PATROL_RANGE_M;    
    protected double jumpProbability = JUMP_PROBABILITY_S;
    protected long jumpFrequency = JUMP_FREQUENCY_L;
    
    /**
     * Base x and y representing the home point for the emoticon,
     * i.e. the position around which the emoticon will patrol, etc.
     */    
    protected double baseX;
    protected double baseY;
    
    /**
     * Flag indicating if the emoticon is currently patroling to
     * the right or the left (only applicable if patrolling)
     */
    protected boolean patrolRight = Math.random() > 0.5 ? true : false;

    /**
     * Flag indicating if the emoticon is currently chasing the player
     */
    protected boolean chasingPlayer = false;

    /**
     * Jump trigger offset, i.e. a random variable within the jump 
     * frequency period, thereby ensuring that all emoticons do not
     * jump on the same update tick
     */
    private int jumpTriggerOffset = 0;
    
    /**
     * Special AI parameters - that can be used by any of the special
     * AI methods
     */
    private int specialAITimer = 0;
    private double specialAIParam = -1;

    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new AI controlled emoticon 
     */
    public EmoticonAI( GameLayer gameLayer ) { 
        this( gameLayer, "EmoticonDevil", 0.0, 0.0, 0 );
    }
        
    /**
     * Create a new AI controlled emoticon of the specified type
     */
    public EmoticonAI( GameLayer  gameLayer, String emoticonType ) {
        this( gameLayer, emoticonType, 0.0, 0.0, 0 );
    }
    
    /**
     * Create a new AI controlled emoticon of the specified type at the
     * specified location
     */
    public EmoticonAI( GameLayer  gameLayer, String emoticonType, 
            double x, double y ) {
        this( gameLayer, emoticonType, x, y, 0 );
    }
    
    /**
     * Create a new AI controlled emoticon of the specified type at the
     * specified location and with the specified draw order
     */
    public EmoticonAI( GameLayer  gameLayer, String emoticonType,
            double x, double y, int drawOrder ) {
        super( gameLayer, emoticonType, x, y, drawOrder );           
        
        baseX = x;
        baseY = y;               
    }    

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Get/set methods                                              //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Set the emoticon position (and base position) to that specified
     */
    @Override
    public void setPosition( double x, double y )
    {
        super.setPosition( x, y );

        baseX = x;
        baseY = y;        
    }
    
    /**
     * Set the AI movement type to that specified
     */
    public void setMovementAI( MovementAI movementAI ) {
        this.movementAI = movementAI;
        
        if( movementAI == MovementAI.Patrol ) {
            moveRight = gameEngine.randomiser.nextDouble() < 0.5 ? true : false; 
            moveLeft = !moveRight;
        }
    }
            
    /**
     * Set the AI chase type to that specified
     */
    public void setChaseAI( ChaseAI chaseAI ) {
        this.chaseAI = chaseAI;
    }

    /**
     * Set the patrol range to that specified
     */
    public void setPatrolRange( double patrolRange ) {
        this.patrolRange = patrolRange;
    }
            
    /**
     * Set the jump probability to that specified
     */
    public void setJumpProbability( double jumpProbability ) {
        this.jumpProbability = jumpProbability;
    }
    
    /**
     * Set the jump frequency to that specified
     */
    public void setJumpFrequency( long jumpFrequency ) {
        this.jumpFrequency = jumpFrequency;
        if( jumpFrequency < Long.MAX_VALUE )
            jumpTriggerOffset = AI_UPDATE_FREQUENCY
                    * (new Random()).nextInt(
                        (int)(jumpFrequency / AI_UPDATE_FREQUENCY) + 1);
    }
    
    /**
     * Set the chase range to that specified
     */
    public void setChaseRange( double chaseRange ) {
        this.chaseRange = chaseRange;
    }

    /**
     * Set the visibility range to that specified
     */
    public void setVisibleRange( double visibleRange ) {
        this.visibleRange = visibleRange;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update                                                       //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the AI emoticon
     */    
    @Override
    public void update() {     
        // If needed update the AI variables
        if( gameEngine.updateCounter % AI_UPDATE_FREQUENCY == 0 ) {
            updateAI();                        

            // Check if emoticon specific AI update needs to be performed
            if( !emoticonDead && emoticonType.equals( "EmoticonBoss" ) )
                    updateEmoticonBossAI();
        }        
        
        // Call the normal emoticon update
        super.update();

        // If the emoticon is dead or released then provide it 
        // with a slight downwards velocity (i.e. it will leave
        // move downwards as it fades out)
        if( emoticonDead || emoticonRelease ) {
            if( emoticonDead )
                velocityy += 10.0;

            // Remove this emoticon if needed
            emoticonAnimationFrame++;
            if( emoticonAnimationFrame >= NUM_ANIMATION_FADE_FRAMES )
                gameLayer.queueGameObjectToRemove( this );
        }        
    }
       
    /**
     * Update the emoticon based on the set AI parameters
     */    
    private void updateAI() {
        
        GameObject player = gameLayer.getGameObject( "Player" );

        // Consider if the emoticon wishes to chase the player
        if( player != null && 
                ( chaseAI == ChaseAI.Chase || chaseAI == ChaseAI.ChaseInRange )) {
            double distanceSquared = 
                (player.x-this.x)*(player.x-this.x) + (player.y-this.y)*(player.y-this.y);
            
            // If the AI will chase and the player is within the visible range
            // then start chasing
            if( distanceSquared < visibleRange*visibleRange ) chasingPlayer = true;

            // If the player leaves the change range then reset the movement
            if( distanceSquared > chaseRange*chaseRange ) {
                chasingPlayer = false; moveLeft = false; moveRight = false; 
                if( flyingEmoticon ) {
                    moveUp = false; moveDown = false;
                }
            }

            // If chasing the player, then move so as to chase the player
            if( chasingPlayer ) {
                if( player.x < this.x ) { 
                    moveLeft = true; moveRight = false; 
                } else { 
                    moveLeft = false; moveRight = true; 
                }
                
                if( flyingEmoticon ) {
                    if( player.y < this.y ) { 
                        moveUp = true; moveDown = false; 
                    } else { 
                        moveUp = false; moveDown = true; 
                    }                    
                }                
            }
        }

        // If the emoticon is not chasing the player and will patrol
        if( !chasingPlayer && movementAI == MovementAI.Patrol ) {

            // If patrolling right then move right until the 
            // range has been exceeded or the emoticon hits 
            // something that stops if moving right. Perform
            // a similar set of tests if patrolling left.
            if( patrolRight ) {
                if( x-baseX > patrolRange ) {
                    patrolRight = false;
                    moveLeft = true; moveRight = false;
                } else {
                    if( x-baseX > 0.0 && velocityx < 0.0 ) {
                        patrolRight = false;
                        moveLeft = true; moveRight = false;
                    } else {
                        moveLeft = false; moveRight = true;                        
                    }
                }
            } else {
                if( baseX-x > patrolRange ) {
                    patrolRight = true;
                    moveLeft = false; moveRight = true;                    
                } else {
                    if( x-baseX < 0.0 && velocityx > 0.0 ) {                        
                        patrolRight = true;
                        moveLeft = false; moveRight = true;                    
                    } else {
                        moveLeft = true; moveRight = false;                        
                    }
                }
            }
                                
            // Ensuring a flying emoticon tries to maintain
            // a y level around the base y
            double tolerance = 50.0;
            if( flyingEmoticon ) {
                if( y < baseY-tolerance ) {
                    moveUp = false; moveDown = true; 
                } if( y > baseY+tolerance ) {
                    moveUp = true; moveDown = false; 
                }                    
            }            
        }

        // If this emoticon can jump, then if the jump frequency trigger
        // has been reached, consider the probability of jumping.        
        if( !flyingEmoticon ) {
            if( gameEngine.updateCounter % jumpFrequency == jumpTriggerOffset ) {
                if( gameEngine.randomiser.nextDouble() < jumpProbability )
                    moveUp = true;
            } else moveUp = false;
            
            // If currently chasing the player and within close proximity
            // of player, then test for another jump attempt
            if( chasingPlayer )
                if( (player.x-this.x)*(player.x-this.x) < 5000.0 
                        && gameEngine.randomiser.nextDouble() < jumpProbability )
                    moveUp = true;                
        }
    }
    
    /**
     * Update the emoticon boss AI
     */        
    private void updateEmoticonBossAI() {
        boolean hitByPlayer = (health != specialAIParam ) && specialAIParam != -1;
        specialAIParam = health;
        
        if( !hitByPlayer && !chasingPlayer && specialAITimer == 0 )
            return;

        if( hitByPlayer ) {
            torque = 50000000000.0 * (torque > 0.0 ? 1.0 : -1.0);        
        } else if( specialAITimer == 0 ) {
            if( gameEngine.randomiser.nextInt(30) == 0 ) {
                specialAITimer = (gameEngine.randomiser.nextInt(2)+5)
                        * gameEngine.randomiser.nextDouble() > 0.5 ? -1 : 1;
            }
        } else {
            if( specialAITimer > 0 ) {
                specialAITimer--;                
                torque = -100000000000.0;
            } else {
                specialAITimer++;
                torque = 100000000000.0;
            }              
        }
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Serialisation/Draw                                           //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Overload the GameObject serialisation method to provide serialisation  
     * support for CollectableBody objects     
    */
    @Override    
    public void serialiseGameObjectState( 
            ObjectOutputStream stream, GameObject gameObject ) throws IOException {         
        super.serialiseGameObjectState( stream, gameObject);

        // Store key AI parameters
        stream.writeUTF( "" + movementAI );
        stream.writeUTF( "" + chaseAI );
        stream.writeDouble( patrolRange );
        stream.writeDouble( jumpProbability );
        stream.writeLong( jumpFrequency );
        stream.writeDouble( chaseRange );
        stream.writeDouble( visibleRange );
    }

    /**
     * Overload the GameObject serialisation method to provide serialisation  
     * support for CollectableBody objects     
    */
    @Override    
    public void loadGameObjectState( 
            ObjectInputStream stream, GameLayer gameLayer ) throws IOException { 
        super.loadGameObjectState( stream, gameLayer );

        String movementAIType = stream.readUTF();
        if( movementAIType.compareTo( "Stationary" ) == 0 ) 
            movementAI = MovementAI.Stationary;
        else if( movementAIType.compareTo( "Patrol" ) == 0 ) 
            movementAI = MovementAI.Patrol;
            
        String chaseAIType = stream.readUTF();
        if( chaseAIType.compareTo( "Ignore" ) == 0 ) 
            chaseAI = ChaseAI.Ignore;
        else if( chaseAIType.compareTo( "Chase" ) == 0 ) 
            chaseAI = ChaseAI.Chase;
        else if( chaseAIType.compareTo( "ChaseInRange" ) == 0 ) 
            chaseAI = ChaseAI.ChaseInRange;
        
        patrolRange = stream.readDouble();
        jumpProbability = stream.readDouble();
        jumpFrequency = stream.readLong();
        chaseRange = stream.readDouble();
        visibleRange = stream.readDouble();

        baseX = this.x;
        baseY = this.y;
        
        if( jumpFrequency < Long.MAX_VALUE )
            jumpTriggerOffset = AI_UPDATE_FREQUENCY
                    * (new Random()).nextInt(
                        (int)(jumpFrequency / AI_UPDATE_FREQUENCY) + 1);
    }
    
    /**
     * Draw the graphical game object to the specified graphics object
     * at the specified x and y offset
     */
    @Override
    public void draw( Graphics2D graphics2D, int drawX, int drawY )
    {
        if( !emoticonDead && !emoticonRelease ) 
            super.draw( graphics2D, drawX, drawY );
        else {
            if( emoticonAnimationFrame >= NUM_ANIMATION_FADE_FRAMES )
                return;
            
            if( !emoticonRelease  ) {      
                // If the emoticon has been killed, then draw it with an
                // increasing level of fade
                Composite originalComposite = graphics2D.getComposite();
                graphics2D.setComposite( AlphaComposite.getInstance(
                    AlphaComposite.SRC_OVER, 
                    Math.min( 1.0f, 3.0f * (1.0f - (float)emoticonAnimationFrame
                        /(float)NUM_ANIMATION_FADE_FRAMES ) ) ) );
                
                super.draw( graphics2D, drawX, drawY );
                graphics2D.setComposite( originalComposite );                
            } else {
                // If the emoticon has been released, then draw it with 
                // an increasing level of fade and increasing draw scale
                double scaleFactor = 1.0 + 
                    (double)(emoticonAnimationFrame * 50)/(double)NUM_ANIMATION_FADE_FRAMES;

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
}