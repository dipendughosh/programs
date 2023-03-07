package tutorials.topDownScroller;

import game.assets.ImageAssetSequence;
import game.engine.GameLayer;

import game.physics.*;

/**
 * Projectile
 * <P>
 * A number of different types of projectile can be supported within this
 * class. Each projectile will travel and disappear once the travel
 * range has been exceeded. It is assumed that hit projectile detection 
 * will be dealt with within the parent GameLayer.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class Projectile extends Body {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the current state of the projectile, i.e. is it moving,
     * has hit something or extended its maximum travel time and is
     * disappearing.
     */
    protected enum ProjectileState { Move, Hit, Disappear }
    protected ProjectileState projectileState = ProjectileState.Move;
    
    /**
     * Amount of damage which will result should this projectile hit
     */
    protected double projectileDamage;
        
    /**
     * Define the projectiles acceleration, maximum travel speed and
     * maximum travel time (in ms)
     */
    private double projectileAcceleration;
    private double projectileMaxSpeed;
    private long projectileMaxTime;
    
    /**
     * Define the current projectile trigger time (this can be multifaced,
     * i.e. the time can be since the projectile was created, or since the
     * hit animation started playing, etc.
     */
    private long projectileTriggerTime;
    
    /**
     * Define the graphicals assets to be used whenever this projectile hits
     * something or exceeds its travel time
     */
    private String hitAsset;
    private String disappearAsset;
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new projectile of the specified type with the specified
     * parameters.
     *
     * @param  projectileType Type of projectile to create
     * @param  x x location at which the projectile should be created
     * @param  y y location at which the projectile should be created
     * @param  rotation Rotation of the projectile
     * @param gameLayer GameLayer instance to which the projectile belongs
     */
    public Projectile( String projectileType,
            double x, double y, double rotation, GameLayer gameLayer ) {
        super( gameLayer, x, y );
        
        this.rotation = rotation;
        
        defineWeaponType( projectileType );        
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Projectile setup and state change                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the characteristics of this projectile. Note, only one type
     * of projectile is currently defined within this class, although 
     * others could be easily added.
     */
    private void defineWeaponType( String weaponType ) {
        if( weaponType.equals("Bullet")) {
            // Define the projectile speed, acceleration and damage
            projectileMaxSpeed = 1000.0;
            projectileAcceleration = 100.0;
            projectileDamage = 100.0;

            // Define the projectile travel time and record the current time
            projectileMaxTime = 2000;            
            projectileTriggerTime = System.nanoTime();

            // Set the projectile's realisation and record the assets to 
            // be used for hit and disappear
            setRealisationAndGeometry( "EnergyBall" );
            hitAsset = "EnergyBallExplode";
            disappearAsset = "EnergyBallDisappear";

            // Give this projectile a mass and restiution. This does not
            // make a lot of sense in the current setup, although it would
            // if enemy planes, etc. were added, e.g. enable the projectile
            // to 'thump' into whatever is it, or deflect, etc.
            setMass( 5.0 );
            restitution = 1.0;
        }
    }
    
    /**
     * Display the projectile hit animation.
     */
    public void triggerProjectileHit() {
        projectileState = ProjectileState.Hit;
        
        setRealisation( hitAsset );

        // It is assumed that once hit a projectile stops (i.e. explodes
        // and cannot interact other objects). This is not a necessary 
        // assumption and could be extended to support projectiles that
        // can bounce off a number of different objects, etc.
        velocityx = 0.0;
        velocityy = 0.0;        
        canIntersectOtherGraphicalObjects = false;
        
        projectileTriggerTime = System.nanoTime();
    }
    
    /**
     * Display the projectile disappearing animation, triggered
     * once the projectile goes beyond the maximum travel distance
     */
    private void triggerProjectDisappear() {
        projectileState = ProjectileState.Disappear;
        
        setRealisation( disappearAsset );
        
        canIntersectOtherGraphicalObjects = false;
        
        projectileTriggerTime = System.nanoTime();
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update methods                                               //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the projectile, triggering the disappearing animation if needed
     */
    public void update() {
        // If the current projectile realisation is an image animation, e.g.
        // hit/disappear animations, then update the animation frame
        if( getRealisation(0) instanceof ImageAssetSequence )
            getRealisation(0).update();
        
        // If the projectile is in the hit or disappear state, then remove
        // the object once the hit/disppear animation has finished playing
        if( projectileState != ProjectileState.Move ) {
            if( (System.nanoTime() - projectileTriggerTime)/1000000L >
                    ((ImageAssetSequence)getRealisation(0)).getAnimationPeriod() )
                gameLayer.queueGameObjectToRemove(this);
        }
        
        // If the projectile has not hit, then update velocity based upon
        // the current projectile rotation and maximum speed
        if( projectileState != ProjectileState.Hit ) {
            if( velocityx*velocityx + velocityy*velocityy
                    < projectileMaxSpeed*projectileMaxSpeed ) {
                velocityx += projectileAcceleration * Math.sin(rotation);
                velocityy -= projectileAcceleration * Math.cos(rotation);
            }

            // If the maximum movemement time has been exceeded, then 
            // trigger the project disappear
            if( projectileState == ProjectileState.Move )
                if( (System.nanoTime() - projectileTriggerTime)/1000000L > projectileMaxTime )
                    triggerProjectDisappear();
        }
    }
}