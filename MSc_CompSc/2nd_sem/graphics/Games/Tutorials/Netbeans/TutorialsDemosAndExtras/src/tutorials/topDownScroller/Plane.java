package tutorials.topDownScroller;

import game.engine.*;
import game.physics.*;
import game.geometry.*;

import java.awt.event.KeyEvent;
import java.util.*;

/**
 * Base plane object.
 * <P>
 * This object provide core plane functionality, including defining how each plane
 * will look (and the corresponding bounding regions), plane characteristics, and
 * core methods (e.g. the flight model, projectile fire, etc.).
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class Plane extends Body {
    
    ///////////////////////////////////////////////////////////////////////////
    // Class data: Plane movement                                             //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Enumerated type defining the possible types of forward acceleration
     */
    public enum ForwardAcceleration { Positive, Negative, None }
    protected ForwardAcceleration forwardAccelerationType = ForwardAcceleration.None;
    
    /**
     * Enumerated type defining the possible types of sideways acceleration
     */
    public enum SidewayAcceleration { Left, Right, None }
    protected SidewayAcceleration sidewayAccelerationType = SidewayAcceleration.None;
            
    /**
     * Plane forward acceleration force, i.e. determining how quickly the ship
     * can accelerate forwards and the maximum forward velocity of the plane
     */
    protected double forwardAcceleration;    
    protected double maxFowardVelocity;
    
    /**
     * Plane backward acceleration force, i.e. determining how quickly the ship
     * can accelerate backwards and the maximum backward velocity of the plane
     */
    protected double backwardAcceleration;    
    protected double maxBackwardVelocity;
    
    /**
     * Plane sideways acceleration force, i.e. determining how quickly the ship
     * can accelerate sideways and the maximum sideways velocity of the plane
     */
    protected double sidewayAcceleration;
    protected double maxSidewaysVelocity;
    
    /**
     * The plane should gradually reduce its velocity when the player is not
     * instructing it to move in a particular direction. The magnitude of this
     * value determines how quickly the velocity returns to zero.
     */    
    protected double dampeningVelocity;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Class data: Weapons, hitpoints                                        //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * An inner class is define to hold the various weapon characteristics.
     * In particular the x, y offset relative to the centre of the plane of
     * the weapon is stored, alongside the weapon's rotation, i.e. the direction
     * that projectiles will be fired in. A fire frequency and last fire time
     * is also maintained to keep track of how often the weapon can fire. 
     * Finally the type of projectile is stored, which will be used create
     * a projectile of the appropriate type.
     */
    public class Weapon {
        double xOffset, yOffset;        
        double rotation;
        
        long fireDelay = 1000, lastFireTime = 0;
        
        String projectileType;
        
        public Weapon( String type, double xOffset, double yOffset, double rotation ) {
            this.projectileType = type;
            this.xOffset = xOffset;
            this.yOffset = yOffset;
            this.rotation = rotation;
        }        
    }
    
    /**
     * Array list of weapons that are attached to this plane
     */
    protected ArrayList<Weapon> planeWeapons = new ArrayList<Weapon>();
    
    /**
     * Initial number and current number of plane hitpoints. These values
     * are not used within this example, although they would have 
     * obvious uses if a more complete game is to be developed
     */
    protected int initialHitPoints;
    protected int currentHitPoints;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new plane
     */
    public Plane( GameLayer gameLayer ) {
        super( gameLayer );
        
        // If adding support for multiple planes then the type of plane
        // to be created could be passed into the constructor and the 
        // define plane method updated to support different types of plane
        definePlane();        
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Plane Definition                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the plane based on the specified plane type
     * <P>
     * Each plane is defined in terms of its graphical realisation,
     * bounding region, maximum directional velocities, accelerative values,
     * initial hitpoints, etc.
     * <P>
     * Only one type of plane is defined at the moment, although this could
     * be extended to incorporate any number of different plane types.
     * <P>
     * Note: Ideally this particular method should load the various plane
     * parameters from a file, as opposed to having hard-coded values. The
     * obvious advantage of being able to load the values from a file is the
     * ability to change plane parameters without a need to rebuild the project.
     */
    protected void definePlane( ) {                
        // Define the graphical realisation and plane geometry
        setRealisationAndGeometry( "Plane" );        
        setGeometry( new Shape[] {
            new Box( 0, 0, 38, 140), new Box(0, 0, 117, 31) } );
        
        // Setup the movement characteristics of the plane
        maxFowardVelocity = 500.0;
        maxBackwardVelocity  = 500.0;
        maxSidewaysVelocity = 500.0;
        
        forwardAcceleration = 30.0;
        backwardAcceleration = 30.0;
        sidewayAcceleration = 30.0;
        
        dampeningVelocity = 10.0;

        // Define the plane hit points and weapon s
        currentHitPoints = initialHitPoints = 1000;
        
        planeWeapons.add( new Weapon( "Bullet", -50, -90, -0.3 ) );
        planeWeapons.add( new Weapon( "Bullet", -40, -95, 0.0 ) );
        planeWeapons.add( new Weapon( "Bullet", 40, -95, 0.0 ) );
        planeWeapons.add( new Weapon( "Bullet", 50, -90, 0.3 ) );
        
        // Give the plane an arbitrary mass - the plane should have a
        // defined mass as, by default, all Body objects are assumed
        // to have infinite mass, i.e. they don't move. The actual
        // value that is assigned would make more sense if there are
        // a number of different planes/objects that this plane can
        // bump into.
        setMass(100.0);
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Plane Acceleration                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Set the plane forward acceleration type to that specified
     *
     * @param  forwardAcclerationType ForwardAcceleration type to be used by the plane
     */
    public void setForwardAcceleration( ForwardAcceleration forwardAcclerationType ) {
        this.forwardAccelerationType = forwardAcclerationType;
    }
    
    /**
     * Set the plane sideway acceleration type to that specified
     *
     * @param  sidewayAccelerationType SidewayAcceleration type to be used by the plane
     */
    public void setSidewayAcceleration( SidewayAcceleration sidewayAccelerationType ) {
        this.sidewayAccelerationType = sidewayAccelerationType;
    }
    
        
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update and render methods                                    //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the plane's acceleration, velocity and location
     */
    @Override
    public void update() {
        // If this was an AI controlled plane then we could call the
        // AI update method here.
        updatePlayerInput();
        
        updatePlaneMovemenet();
    }
    
    /**
     * Update the forward acceleration, sideway acceleration, and associated
     * directional velocities.
     */
    public void updatePlayerInput() {
        
        // Set the type of forward acceleration based upon current key state
        if( inputEvent.keyPressed[ KeyEvent.VK_UP ]
                && !inputEvent.keyPressed[ KeyEvent.VK_DOWN ] )
            setForwardAcceleration( Plane.ForwardAcceleration.Positive );
        else if( inputEvent.keyPressed[ KeyEvent.VK_DOWN ]
                && !inputEvent.keyPressed[ KeyEvent.VK_UP ] )
            setForwardAcceleration( Plane.ForwardAcceleration.Negative );
        else
            setForwardAcceleration( Plane.ForwardAcceleration.None );
        
        // Set the type of sideway acceleration based upon current key state
        if( inputEvent.keyPressed[ KeyEvent.VK_RIGHT ]
                && !inputEvent.keyPressed[ KeyEvent.VK_LEFT ] )
            setSidewayAcceleration( Plane.SidewayAcceleration.Right );
        else if( inputEvent.keyPressed[ KeyEvent.VK_LEFT ]
                && !inputEvent.keyPressed[ KeyEvent.VK_RIGHT ] )
            setSidewayAcceleration( Plane.SidewayAcceleration.Left );
        else
            setSidewayAcceleration( Plane.SidewayAcceleration.None );
        
        // Consider if we should fire
        if( inputEvent.keyPressed[ KeyEvent.VK_SPACE ] == true )
            considerFiring();
        
    }
    
    /**
     * Update the plane's acceleration, velocity and location
     */
    private void updatePlaneMovemenet() {
        // Determine the plane's current forward acceleration
        switch( forwardAccelerationType ) {
            case Positive:
                velocityy -= forwardAcceleration; // Negative as moving 'up' the screen
                if( velocityy < -maxFowardVelocity ) velocityy = -maxFowardVelocity;
                break;
            case Negative:
                velocityy += backwardAcceleration; // Positive as moving 'down' the screen
                if( velocityy > backwardAcceleration ) velocityy = backwardAcceleration;
                break;
            case None:
                if( Math.abs(velocityy) < dampeningVelocity )
                    velocityy = 0.0;
                else
                    velocityy += (velocityy > 0.0 ? -dampeningVelocity : dampeningVelocity );
                break;
        }
        
        // Determine the plane's current sideway acceleration
        switch( sidewayAccelerationType ) {
            case Right:
                velocityx += sidewayAcceleration;
                if( velocityx > maxSidewaysVelocity ) velocityx = maxSidewaysVelocity;
                break;
            case Left:
                velocityx -= sidewayAcceleration;
                if( velocityx < -maxSidewaysVelocity ) velocityx = -maxSidewaysVelocity;
                break;
            case None:
                if( Math.abs(velocityx) < dampeningVelocity )
                    velocityx = 0.0;
                else
                    velocityx += (velocityx > 0.0 ? -dampeningVelocity : dampeningVelocity );
                break;
        }
        
        // By default all game objects can have an arbitary rotation which will be
        // updated following collisions, etc. To keep the plane pointing upwards, 
        // the rotation is continually corrected if needed.
        if( rotation != 0.0 ) {
            angularVelocity = 0.0;            
            if( Math.abs( rotation ) < 0.01 )
                rotation = 0.0;            
            else
                rotation -= 0.01 * Math.signum(rotation);
        }
    }
    
    /**
     * Consider if this plane can fire, and if so created the appropriate projectiles
     */
    protected void considerFiring() {
        long currentTime = System.nanoTime() / 1000000;
        for( Weapon weapon : planeWeapons ) {
            // If the weapon is enabled and the fire delay has elapsed then
            // create a new projectile of the appropriate type
            if( weapon.lastFireTime + weapon.fireDelay < currentTime ) {
                // Set the last fire time to the current time
                weapon.lastFireTime = currentTime;
                
                // Add a new projectile to the determined weapon fire location. The
                // projectile is defined in terms of the relevant weapon parameters.
                gameLayer.queueGameObjectToAdd(
                        new Projectile( weapon.projectileType,
                        x + weapon.xOffset, y + weapon.yOffset,
                        weapon.rotation, gameLayer ), "Projectiles" );
            }
        }
    }        
}