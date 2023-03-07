package happyFace;

import game.assets.*;
import game.engine.*;
import game.physics.*;
import game.geometry.*;
import java.io.*;

/**
 * Superclass of all Emoticon objects, be they player or AI controller. Each
 * emoticon instance has a number of defining characteristics and can move
 * about in accordance with set movement forces.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class Emoticon extends Body {

    ///////////////////////////////////////////////////////////////////////////
    // Class data:                                                           //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Type of emoticon represented by this Emoticon instance
     */
    public String emoticonType;

    /**
     * Key defining emoticon information, including if this is a happy
     * emoticon (i.e. enemy of the player), the emoticon's health and
     * number of points if it is killed/released. The collision damage
     * is also stored of the damage imparted on a hostile impact.
     */
    protected boolean happyEmoticon;
    protected double health;
    protected double collisionDamage;
    protected int points;

    /**
     * Flag specifying if the emoticons avoid interactive forms of damange,
     * e.g. spikes, acid, etc.
     */
    protected boolean ignoreInteractiveDamage = false;
    
    /**
     * Flags specifying if the emoticon instance is currently attempting
     * to move left, right up or down.
     */
    protected boolean moveLeft = false;
    protected boolean moveRight = false;
    protected boolean moveUp = false;
    protected boolean moveDown = false;

    /**
     * Force with which this emoticon can move in different directions,
     * determining the acceleration of the emoticon (in combination
     * with it's mass) and the emoticon's ability to push other objects
     * out of the way. A jump velocity is also stored, which is the
     * instantaneous upwards velocity applied whenever the emoticon
     * jumps
     */
    protected double moveLeftForce;
    protected double moveRightForce;
    protected double moveUpForce;
    protected double moveDownForce;
    protected double jumpVelocity;

    /**
     * The restitution of the emoticon when jumping, contracted or
     * by default. These values are mostly of interest to the
     * player controlled emoticon as they entail that the emoticon
     * comes more bouncy when jumping and less so when contacted
     * (i.e. crouched)
     */
    protected double jumpingRestitution;
    protected double restingRestitution;
    protected double contractedRestitution;

    /**
     * Flag specifying if this emoticon can fly, i.e. if it is,
     * in effect, not subject to gravitational pull. 
     */
    protected boolean flyingEmoticon = false;
    
    /**
     * Each jump has a minimum reset delay as specified by
     * JUMPDELAYPERIOD before the emoticon can jump again
     */
    protected int JUMPDELAYPERIOD = 30;
    protected int jumpDelay = 0;

    /**
     * Each attack has a minimum reset delay as specified by
     * ATTACKDELAYPERIOD before the emoticon can damage again
     */
    protected int ATTACKDELAYPERIOD = 60;
    protected int attackDelay = 0;
        
    /**
     * As each emoticon need to track if it is currently on
     * a solid surface before it is permitted, a history
     * is held of recent intersections. Any intersection
     * within the bottom of the emoticon and another object
     * within the period entails that the emoticon can jump
     */
    protected int HISTORYLENGTH = 15;
    protected int contactOffset = 0;
    protected boolean[] contactHistory;

    /**
     * Emoticons can be limited in terms of their maximum
     * travel velocities
     */
    protected double maximumXVelocity = Double.MAX_VALUE;
    protected double maximumYVelocity = Double.MAX_VALUE;

    /**
     * Variables tracking the state of the emoticon.
     * Once dead or released a fade animation is played
     */
    protected static int NUM_ANIMATION_FADE_FRAMES = 80;
    protected int emoticonAnimationFrame = 0;
    protected boolean emoticonDead = false;
    protected boolean emoticonRelease = false;

    /**
     * Emoticons can have sound effects associated and played
     * whenever they jump, are killed or hit something.
     */
    protected static final double JUMP_SFX_RANGE = 3000.0;
    protected String jumpSoundEffect = null;
    protected String deadSoundEffect = null;
    protected String hitSoundEffect = null;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Construct a default (i.e. Devil) emoticon
     */
    public Emoticon(GameLayer gameLayer) {
        this(gameLayer, "EmoticonDevil", 0.0, 0.0, 0);
    }

    /**
     * Construct an emoticon of the specified type
     */
    public Emoticon(GameLayer gameLayer, String emoticonType) {
        this(gameLayer, emoticonType, 0.0, 0.0, 0);
    }

    /**
     * Construct an emoticon of the specified type at the specified location
     */
    public Emoticon(GameLayer gameLayer, String emoticonType, 
            double x, double y) {
        this(gameLayer, emoticonType, x, y, 0);
    }

    /**
     * Construct an emoticon of the specified type at the specified location
     * and with the specified draw order
     */
    public Emoticon(GameLayer gameLayer, String emoticonType, 
            double x, double y, int drawOrder) {
        super(gameLayer, x, y, drawOrder);

        // Create and clear the contact history for this emoticon
        contactHistory = new boolean[HISTORYLENGTH];
        for (int idx = 0; idx < HISTORYLENGTH; idx++) {
            contactHistory[idx] = false;
        }

        // Setup parameters based upon the type of emoticon
        defineEmoticonType(emoticonType);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Definition/Set/Get                                           //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Setup emoticon parameters based upon the specified type of emoticon
     */
    protected void defineEmoticonType(String emoticonType) {
        this.emoticonType = emoticonType;

        GraphicalAsset realisation 
                = assetManager.retrieveGraphicalAsset(emoticonType);

        if (emoticonType.compareTo("EmoticonDevil") == 0) {
            // Define the player control emoticon
            
            ATTACKDELAYPERIOD = 30;
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 60000.0;
            moveRightForce = 60000.0;
            jumpVelocity = 350.0;
            realisation.offsetX = -1.0;
            realisation.offsetY = -2.0;
            health = 200.0;
            collisionDamage = 50.0;
            points = 250;
            maximumXVelocity = 1000.0;
            maximumYVelocity = 1000.0;
            setMass(100.0);
            setGeometry(new Circle(0, 0, 20));

            jumpSoundEffect = "EmoticonDevilJump";
            deadSoundEffect = "EmoticonDevilDead";
            hitSoundEffect = "EmoticonDevilHit";
            
        } else if (emoticonType.compareTo("EmoticonFloater") == 0) {
            // Define a basic flying emoticon (not overly difficult)  
            
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 60000.0;
            moveRightForce = 60000.0;
            moveUpForce = 60000.0;
            moveDownForce = 60000.0;
            flyingEmoticon = true;
            health = 50.0;
            collisionDamage = 20.0;
            points = 100;
            maximumXVelocity = 200.0;
            maximumYVelocity = 500.0;
            breakingImpulse = 300000.0;
            setMass(100.0);
            setGeometry(new Circle(0, 0, 20));
            setGravityEffected(false);

            jumpSoundEffect = null;
            deadSoundEffect = "EmoticonFloaterDead";
            hitSoundEffect = "EmoticonFloaterHit";
            
        } else if (emoticonType.compareTo("EmoticonGhost") == 0) {
            // Define a flying emoticon that will be able to pass through
            // other bodies (stronger than the floater and more difficult 
            // to attack
            
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 60000.0;
            moveRightForce = 60000.0;
            moveUpForce = 60000.0;
            moveDownForce = 60000.0;
            flyingEmoticon = true;
            health = 100.0;
            collisionDamage = 30.0;
            points = 200;
            maximumXVelocity = 150.0;
            maximumYVelocity = 500.0;
            breakingImpulse = 300000.0;
            setMass(100.0);
            setGeometry(new Circle(0, 0, 20));
            setGravityEffected(false);
            this.setCanIntersectOtherGraphicalObjects(false);

            jumpSoundEffect = null;
            deadSoundEffect = "EmoticonGhostDead";
            hitSoundEffect = "EmoticonGhostHit";
            
        } else if (emoticonType.compareTo("EmoticonAngel") == 0) {
            // Define a difficult flying emoticon that can dish out 
            // a lot of damage and is difficult to kill
            
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 60000.0;
            moveRightForce = 60000.0;
            moveUpForce = 60000.0;
            moveDownForce = 60000.0;
            flyingEmoticon = true;
            health = 150.0;
            points = 400;
            collisionDamage = 40.0;
            maximumXVelocity = 250.0;
            maximumYVelocity = 500.0;
            breakingImpulse = 300000.0;
            setMass(100.0);
            setGeometry(new Circle(0, 0, 20));
            setGravityEffected(false);

            jumpSoundEffect = null;
            deadSoundEffect = "EmoticonAngelDead";
            hitSoundEffect = "EmoticonAngelHit";
            
        } else if (emoticonType.compareTo("EmoticonDestroyer") == 0) {
            // Define a near indestructible emoticon that is also nearly
            // unstoppable, short of immoveable objects. It is worth zero
            // points as it is not intended to be something that can be
            // killed and should not contribute to the pool for available
            // points of a level
            
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 1.0;
            contractedRestitution = 1.0;
            moveLeftForce = 3.0E7; 
            moveRightForce = 3.0E7;
            moveUpForce = 3.0E7;
            moveDownForce = 3.0E7;
            flyingEmoticon = true;
            health = 1.0E8;
            points = 0;
            collisionDamage = 50.0;
            maximumXVelocity = 400.0;
            maximumYVelocity = 400.0;
            breakingImpulse = Double.MAX_VALUE;
            setMass(1000000.0);
            setGeometry(new Circle(0, 0, 40));
            setGravityEffected(false);
            ignoreInteractiveDamage = true;

            jumpSoundEffect = null;
            deadSoundEffect = null;
            hitSoundEffect = "EmoticonDestroyerHit";

        } else if (emoticonType.compareTo("EmoticonBoss") == 0) {
            // The ultimate emoticon - well, apart from the one above
            // this entry... a rather nasty emoticon that the player
            // will need to defeat at the end to be successful -
            // has customised AI to make it more challenging
            
            happyEmoticon = true;
            friction = 2.0;
            jumpingRestitution = 2.0;
            restingRestitution = 2.0;
            contractedRestitution = 2.0;
            moveLeftForce = 10000000; 
            moveRightForce = 10000000;
            moveUpForce = 10000000;
            moveDownForce = 5000000;
            flyingEmoticon = true;
            health = 1000;
            points = 10000;
            collisionDamage = 35.0;
            maximumXVelocity = 400.0;
            maximumYVelocity = 400.0;
            breakingImpulse = Double.MAX_VALUE;
            setMass(20000.0);
            setGeometry(new Circle(0, 0, 100));
            setGravityEffected(false);
            ignoreInteractiveDamage = true;

            jumpSoundEffect = null;
            deadSoundEffect = "EmoticonBossDead";
            hitSoundEffect = "EmoticonBossHit";
            
        } else if (emoticonType.compareTo("EmoticonSetAHappy1") == 0 
                || emoticonType.compareTo("EmoticonSetBHappy1") == 0 
                || emoticonType.compareTo("EmoticonSetCHappy1") == 0 
                || emoticonType.compareTo("EmoticonSetDHappy1") == 0) {
            // Define a basic emoticon that is weak, slow and does not
            // do mcuh damage, i.e. easy cannon fodder
            
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 60000.0;
            moveRightForce = 60000.0;
            jumpVelocity = 350.0;
            maximumXVelocity = 100.0;
            maximumYVelocity = 500.0;
            health = 50.0;
            collisionDamage = 20.0;
            points = 50;
            breakingImpulse = 300000.0;
            setMass(100.0);
            setGeometry(new Circle(0, 0, 20));

            jumpSoundEffect = "Emoticon1Jump";
            deadSoundEffect = "EmoticonDead1";
            hitSoundEffect = "Emoticon1Hit";
            
        } else if (emoticonType.compareTo("EmoticonSetAHappy2") == 0 
                || emoticonType.compareTo("EmoticonSetBHappy2") == 0 
                || emoticonType.compareTo("EmoticonSetCHappy2") == 0 
                || emoticonType.compareTo("EmoticonSetDHappy2") == 0) {
            // Define an emoticon that is slow but can take a lot of
            // damage and also dish out a lot of damage
            
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 60000.0;
            moveRightForce = 60000.0;
            jumpVelocity = 350.0;
            health = 200.0;
            collisionDamage = 50.0;
            points = 100;
            maximumXVelocity = 100.0;
            maximumYVelocity = 500.0;
            breakingImpulse = 300000.0;
            setMass(150.0);
            setGeometry(new Circle(0, 0, 20));

            jumpSoundEffect = "Emoticon2Jump";
            deadSoundEffect = "EmoticonDead2";
            hitSoundEffect = "Emoticon2Hit";
            
        } else if (emoticonType.compareTo("EmoticonSetAHappy3") == 0 
                || emoticonType.compareTo("EmoticonSetBHappy3") == 0 
                || emoticonType.compareTo("EmoticonSetCHappy3") == 0 
                || emoticonType.compareTo("EmoticonSetDHappy3") == 0) {
            // Define an emoticon that is very fast, but has limited
            // health and does not do a lot of damage. Still, given its
            // speed, it can be problematic

            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 100000.0;
            moveRightForce = 100000.0;
            jumpVelocity = 500.0;
            health = 100.0;
            collisionDamage = 20.0;
            points = 100;
            maximumXVelocity = 600.0;
            maximumYVelocity = 500.0;
            breakingImpulse = 300000.0;
            setMass(50.0);
            setGeometry(new Circle(0, 0, 20));

            jumpSoundEffect = "Emoticon3Jump";
            deadSoundEffect = "EmoticonDead1";
            hitSoundEffect = "Emoticon3Hit";
            
        } else if (emoticonType.compareTo("EmoticonSetAHappy4") == 0 
                || emoticonType.compareTo("EmoticonSetBHappy4") == 0 
                || emoticonType.compareTo("EmoticonSetCHappy4") == 0 
                || emoticonType.compareTo("EmoticonSetDHappy4") == 0) {
            // Define an emoticon that is fast, strong and hits hard
            
            happyEmoticon = true;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 0.7;
            contractedRestitution = 0.7;
            moveLeftForce = 150000.0;
            moveRightForce = 150000.0;
            jumpVelocity = 400.0;
            health = 150.0;
            collisionDamage = 40.0;
            points = 200;
            maximumXVelocity = 600.0;
            maximumYVelocity = 400.0;
            breakingImpulse = 300000.0;
            setMass(120.0);
            setGeometry(new Circle(0, 0, 20));

            jumpSoundEffect = "Emoticon4Jump";
            deadSoundEffect = "EmoticonDead2";
            hitSoundEffect = "Emoticon4Hit";
            
        } else if (emoticonType.compareTo("EmoticonSetAUnhappy") == 0 
                || emoticonType.compareTo("EmoticonSetBUnhappy") == 0 
                || emoticonType.compareTo("EmoticonSetCUnhappy") == 0 
                || emoticonType.compareTo("EmoticonSetDUnhappy") == 0) {
            // Define the basic unhappy emoticon, i.e. the ones to be rescued
            
            happyEmoticon = false;
            friction = 1.0;
            jumpingRestitution = 1.0;
            restingRestitution = 1.0;
            contractedRestitution = 1.0;
            moveLeftForce = 100000.0;
            moveRightForce = 100000.0;
            jumpVelocity = 200.0;
            health = 100.0;
            collisionDamage = 0.0;
            points = 100;
            maximumXVelocity = 200.0;
            maximumYVelocity = 500.0;
            breakingImpulse = 300000.0;
            setMass(100.0);
            setGeometry(new Circle(0, 0, 20));

            jumpSoundEffect = "Emoticon1Jump";
            deadSoundEffect = "EmoticonDead1";
            hitSoundEffect = "Emoticon1Hit";
        } else {
            throw new IllegalStateException("Emoticon.defineEmoticonType: " + 
                    "Unknown emoticon type: " + emoticonType);
        }
        
        setGravityEffected(flyingEmoticon ? false : true);
        setEnableAtRestDetermination(false);
        setRealisation(realisation);
    }

    /**
     * Return the current health of this emoticon
     */
    public final double getHealth() {
        return health;
    }

    /**
     * Add the specified amount to the current health of this emoticon
     */
    public void addHealth(double health) {
        this.health += health;
    }

    /**
     * Subtract the specified amount from the current health of this emoticon
     * <P>
     * Note: The health cannot be set to a value lower than zero
     */
    public void subHealth(double health) {
        this.health -= health;
        if (health < 0) {
            health = 0;
        }
    }
    
    /**
     * Set the current health of this emoticon to that specified
     */
    public void setHealth(double health) {
        this.health = health;
    }

    /**
     * Return if this emoticn can avoid interactive forms of damage
     */
    public boolean canIgnoreInteractiveDamage() {
        return ignoreInteractiveDamage; 
    }  
    
    /**
     * Set if this emoticn can avoid interactive forms of damage
     */
    public void setIgnoreInteractiveDamage(boolean ignoreInteractiveDamage) {
        this.ignoreInteractiveDamage = ignoreInteractiveDamage; 
    }  
    
    /**
     * Return if this is a happy emoticon
     */
    public boolean isHappyEmoticon() {
        return happyEmoticon;
    }

    /**
     * Return if this emoticon can damage another emoticon (this method
     * takes into account any attack delay)
     */
    public boolean canAttack() {
        return (attackDelay == 0);
    }
    
    /**
     * Called whenever the emoticon has attacked (with a attack delay 
     * set to that specified for the emoticon)
     */
    public void hasAttacked() {
        attackDelay = ATTACKDELAYPERIOD;
    }
    
    /**
     * Get the collision damage of this emoticon
     */
    public double getCollisionDamage() {
        return collisionDamage;
    }

    /**
     * Get the number of points associated with this emoticon
     * (when killed or released)
     */
    public int getPoints() {
        return points;
    }

    /**
     * Return the name of the hit sound asset
     */
    public String getHitSoundEffect() {
        return hitSoundEffect;
    }

    /**
     * Return the name of the dead sound asset
     */
    public String getDeadSoundEffect() {
        return deadSoundEffect;
    }

    /**
     * Return the name of the jump sound asset
     */
    public String getJumpSoundEffect() {
        return jumpSoundEffect;
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update                                                       //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Update the emoticon's state
     */
    @Override
    public void update() {        
        // Update the contact history, i.e. determine if the lower half of
        // this emoticon is touching another body
        contactOffset = (contactOffset + 1) % HISTORYLENGTH;
        contactHistory[contactOffset] = determineIfTouchingOtherBody();
        
        // Update the graphical realisation associated with the emoticon
        graphicalRealisation[0].update();

        // Based upon the set movement flags, update the forces applied
        // to the emoticon
        reflectState();
    }

    /**
     * Determine if the lower half of this emoticon is touching another body,
     * i.e. if the emoticon is viewed as being able to jump
     */
    private final boolean determineIfTouchingOtherBody() {
        boolean contact = false;
        
        // Test each arbiter for a point of contact with this emoticon
        for (Arbiter arbiter : ((CollisionSpace) gameLayer).arbiters.values()) {
            if (arbiter.body1.uniqueGameObjectID == this.uniqueGameObjectID 
                    || arbiter.body2.uniqueGameObjectID == this.uniqueGameObjectID) {
                
                // Skip if the body cannot interact other objects
                if (arbiter.body1.canIntersectOtherGraphicalObjects == false 
                        || arbiter.body2.canIntersectOtherGraphicalObjects == false)
                    continue;

                // Check to see if any of the points of contact are below a mid point
                // ie. will assume downwards contact
                for (int contactIdx = 0; !contact && 
                        contactIdx < arbiter.getNumContacts(); contactIdx++) {
                    Contact arbiterContact = arbiter.getContact(contactIdx);
                    if (arbiterContact.y > this.y + this.height / 4.0) {
                        contact = true;
                    }
                }
            }

            // Stop iterating once a contact has been found
            if (contact) {
                break;
            }
        }

        return contact;
    }

    /**
     * Update the state of the emoticon based upon the current set flags
     */
    private final void reflectState() {
        if (flyingEmoticon) {
           // If this is a flying emoticon then update any relevant movement forces
            if (moveLeft) forcex = -moveLeftForce;
            if (moveRight) forcex = moveRightForce;
            if (moveUp) forcey = -moveUpForce;
            if (moveDown) forcey = moveDownForce;
        } else {
            // If this is non a flying emoticon then update the jump delay counter            
            if (jumpDelay > 0)
                jumpDelay--;

            // Determine if this emoticon is in contact with a surface
            boolean contact = false;
            for (int idx = 0; idx < HISTORYLENGTH && !contact; idx++)
                if (contactHistory[idx] == true)
                    contact = true;

            // Update the left and right movement forces. An emoticon that is
            // contact with a surface can apply the full movement force, 
            // otherwise a reduced force is applied (although a player 
            // emoticon receives a less strong penalty, i.e. it can be 
            // more easily controlled when falling
            if (this instanceof EmoticonPlayer) {
                if (moveLeft) 
                    forcex = contact ? -moveLeftForce : -moveLeftForce / 1.5;
                if (moveRight) 
                    forcex = contact ? moveRightForce : moveRightForce / 1.5;
            } else {
                if (moveLeft) 
                    forcex = contact ? -moveLeftForce : -moveLeftForce / 2.0;
                if (moveRight) 
                    forcex = contact ? moveRightForce : moveRightForce / 2.0;
            }

            // If moving down then using the contacted restitution (i.e. this 
            // can be used to stop bouncing more quickly
            if (moveDown) 
                restitution = contractedRestitution;

            // If moving up, then use the jumping resolution. Additionally, 
            // if moving up and the emoticon is in contact with a surface
            // and the jump timer has reset, then jump upwards
            if (moveUp) {
                restitution = jumpingRestitution;
                if (contact && jumpDelay == 0) {
                    velocityy -= jumpVelocity;
                    jumpDelay = JUMPDELAYPERIOD;

                    // If needed play a jump sound effect. The volume of the 
                    // jump sound effect is scaled based upon the distance
                    // of the jumping emoticon from the player emoticon
                    if (jumpSoundEffect != null) {
                        GameObject player = gameLayer.getGameObject("Player");
                        if (player != null) {
                            float sfxVolume = 0.5f - (float) (((this.x-player.x)*(this.x-player.x)
                                    + (this.y-player.y)*(this.y-player.y)) 
                                    / (JUMP_SFX_RANGE*JUMP_SFX_RANGE));
                            if (sfxVolume > 0.0f) {
                                SoundAssetAssembly jumpSfx = (SoundAssetAssembly) 
                                        assetManager.retrieveSoundAssetArchetype( jumpSoundEffect );
                                jumpSfx.setVolume(sfxVolume + 0.5F);
                                jumpSfx.play();
                            }
                        }
                    }
                }
            }

            // Revert to the resting restitution if needed
            if (!moveUp && !moveDown)
                restitution = restingRestitution;
            
            // Based upon the current movement speed, determine a suitable rotational 
            // velocity. If not in contact with a surface, the rotational velocity
            // is slowly reduced
            if (contact) {
                angularVelocity = velocityx / ((Circle) this.geometry[0]).radius;
            } else {
                angularVelocity /= 1.02;
            }
        }

        // An emoticon that is flying or has a small angular velocity will
        // automatically try to orientate itself upwards - this helps to 
        // keep emoticon broadly the right way up if they are not rolling    
        double selfRightingRotation = flyingEmoticon ? 0.03 : 0.02;
        if (flyingEmoticon || Math.abs(angularVelocity) < 1.0) {
            double rotationOffset = rotation % 6.28;
            if (rotationOffset < 0.0) {
                rotationOffset += 6.28;
            }
            if (rotationOffset <= selfRightingRotation 
                    || rotationOffset >= 6.28 - selfRightingRotation) {
                rotation = 0.0;
            } else {
                if (rotationOffset > 3.14 ) {                    
                    rotation += selfRightingRotation;
                } else {
                    rotation -= selfRightingRotation;
                }
            }
        }

        // Clamp the x and y velocities of the emoticon based upon the 
        // specified maximum values
        GameObjectUtilities.clampVelocities(this, 
                maximumXVelocity, maximumXVelocity, maximumYVelocity, maximumYVelocity, 
                Double.MAX_VALUE, Double.MAX_VALUE);
        
        // Reduce the attack delay if needed
        if( attackDelay > 0 )
            attackDelay--;
    }

    /**
     * This method can be called whenever the emoticon has been killed and should
     * commence its remove animation
     */
    public void triggerEmoticonDeath() {
        // Return if this has been called a second time
        if (emoticonDead)
            return;
        emoticonDead = true;

        // Ensure the emoticon cannot intersect anything else and will be drawn
        // on top of other objects
        canIntersectOtherGraphicalObjects = false;
        setDrawOrder(100);

        // Play a dead sound effect if needed
        if (deadSoundEffect != null) {
            assetManager.retrieveSoundAssetArchetype(deadSoundEffect).play();
        }

        // If a happy emoticon is killed, then add on the score to the player       
        // and update the number of happy emoticons killed
        if (this.isHappyEmoticon()) {
            if (gameLayer.getGameObject("Player") != null) {
                ((EmoticonPlayer) gameLayer.getGameObject("Player")).
                        addScore(this.getPoints());
            }
            ((HappyFaceLevelLayer) gameLayer).currentNumEmoticonsKilled++;
        }
        
        // If this is an emoticon boss, then remove any joint connections to
        // the emoticon
        if( emoticonType.equals("EmoticonBoss")) {
            GameObjectCollection joints = ((CollisionSpace)gameLayer).getJoints(); 
            for(int idx = 0; idx < joints.size; idx++) {
                Joint joint = (Joint)joints.gameObjects[idx];
                if(joint.body1.equals(this) || joint.body2.equals(this))
                    ((CollisionSpace)gameLayer).removeJoint(joint);
            }
        }
    }

    /**
     * This method can be called whenever the emoticon has been released and should
     * commence its remove animation
     */    
    public void triggerEmoticonRelease() {
        // Return if this has been called a second time
        if (emoticonRelease)
            return;        
        emoticonRelease = true;
        
        // Ensure the emoticon cannot intersect anything else and will be drawn
        // on top of other objects
        canIntersectOtherGraphicalObjects = false;
        setDrawOrder(100);

        // Add on the emoticon's score to the player emoticon
        if (gameLayer.getGameObject("Player") != null) {
            ((EmoticonPlayer) gameLayer.getGameObject("Player")).addScore(this.getPoints());
        }
    }

    /**
     * This method is called whenever the emoticon receives an impulse beyond
     * the defined breaking impulse (i.e. thereby killing the emoticon)
     */
    @Override
    public int breakBody(CollisionSpace collisionSpace, double impulse, Shape shape) {
        if (impulse > breakingImpulse) {
            triggerEmoticonDeath();
            return 0;
        } else {
            return -1;
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Serialisation                                                //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Overload the GameObject serialisation method to provide serialisation  
     * support for CollectableBody objects     
    */
    @Override
    public void serialiseGameObjectState(
            ObjectOutputStream stream, GameObject gameObject) throws IOException {
        super.serialiseGameObjectState(stream, gameObject);

        // Only the emoticon type needs to be stored 
        stream.writeUTF(emoticonType);
    }

    /**
     * Overload the GameObject serialisation method to provide serialisation  
     * support for CollectableBody objects     
    */
    @Override
    public void loadGameObjectState(
            ObjectInputStream stream, GameLayer gameLayer) throws IOException {
        super.loadGameObjectState(stream, gameLayer);

        // Recreate the emoticon based upon the specified type
        defineEmoticonType(stream.readUTF());
    }
}
