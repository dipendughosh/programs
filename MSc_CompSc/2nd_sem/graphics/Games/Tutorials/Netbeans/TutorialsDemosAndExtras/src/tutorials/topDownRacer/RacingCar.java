package tutorials.topDownRacer;

import game.engine.*;
import java.awt.event.*;

/**
 * Base racing car object.
 * <P>
 * This object provides a simple racing car (and movement model)
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class RacingCar extends GameObject {
    
    ///////////////////////////////////////////////////////////////////////////
    // Class Data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Acceleration (in pixels/update) that the car accelerate forwards
     */
    public double carForwardAcceleration = 0.10;

    /*
     * Acceleration (in pixels/update) that the car accelerate backwards
     */
    public double carBackwardAcceleration = 0.08;

    /**
     * When the breaks are applied this is the multiplier that will be applied
     * to the directional velocity, i.e. after each update the velocity will be
     * 95% (0.95) of it's original value. If this were set lower, e.g. to say 0.5,
     * then after each update the car's velocity would be 50% of that upon entry,
     * i.e. it will stop much more quickly.
     */
    public double carDeceleration = 0.975;
    
    /**
     * Acceleration (in radians rotated/update) that the car can turn
     */
    public double carTurningRate = 0.002;

    /**
     * Default frictional deceleration, i.e. representing just how
     * 'stickly' the surface is by default (i.e. if the user does not
     * accelerate, etc. then the car will slowly come to a stop.
     * <P>
     * The frictionalMovementDeceleration and frictionalAngularDeceleration
     * represent update scaling that is applied to the velocities. The 
     * frictionalDriftDeceleration represents the absolute reduction (in
     * pixels/update) that is applied to any movement 90degrees to the
     * direction of rotation of the car).
     */
    public double frictionalDriftDeceleration = 0.05;
    public double frictionalMovementDeceleration  = 0.98;
    public double frictionalAngularDeceleration  = 0.95;
    
    /**
     * Maximum directional velocities and maximum rotational velocities
     * for the car, i.e. how fast can it move, how fast can it corner.
     */
    public double maxVelocity = 5.0;
    public double maxAngularVelocity = 0.03;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
            
    public RacingCar( GameLayer gameLayer ) {
        super( gameLayer );
        
        // Give the car it's graphical realisation and setup a default bounding region
        // around the entire car. Note: this particular example does not  make use
        // of the available physics, i.e. it really does not matter what geometry
        // is assigned.
        setRealisationAndGeometry( "Car" );
    }

    @Override
    public void update() {

        // If the car is moving then apply the frictional deceleration. This
        // comes in two different components, a generic scaling that is always
        // applied and an absolute reduction of any velocity component that is
        // 90 degrees to the rotation of the car. 
        if( velocityx != 0.0 ||  velocityy != 0.0 ) {
            double absVelx = Math.abs(velocityx), absVely = Math.abs(velocityy);
            double drift = Math.abs( (absVelx/(absVelx+absVely))*Math.cos(rotation) +
                    (absVely/(absVelx+absVely)) * Math.sin(rotation) );

            double frictionDeceleration = frictionalMovementDeceleration -
                    frictionalDriftDeceleration * drift;
            
            velocityx *= frictionDeceleration;
            velocityy *= frictionDeceleration;
        }
                
        // If the brake has been applied, then slow the car down some more!
        if( inputEvent.keyPressed[ KeyEvent.VK_SPACE ] ) {
            velocityx *= carDeceleration;
            velocityy *= carDeceleration;
        }
        
        // Decrease any angular velocity
        angularVelocity *= frictionalAngularDeceleration;

        // If the player wants to accelerate forward or backwards, then change velocity
        if( inputEvent.keyPressed[ KeyEvent.VK_UP ] ) {
            velocityx += Math.sin( rotation ) * carForwardAcceleration;
            velocityy -= Math.cos( rotation ) * carForwardAcceleration;
        } else if( inputEvent.keyPressed[ KeyEvent.VK_DOWN ] ) {
            velocityx -= Math.sin( rotation ) * carBackwardAcceleration;
            velocityy += Math.cos( rotation ) * carBackwardAcceleration;
        }

        // Ensure the car cannot exceed its set maximum velocity
        double speedRatioSqrd = (velocityx*velocityx + velocityy*velocityy) 
                / (maxVelocity*maxVelocity);
        if( speedRatioSqrd > 1.0 ) {
            velocityx /= Math.sqrt(speedRatioSqrd);
            velocityy /= Math.sqrt(speedRatioSqrd);
        }
                
        // If the user is turning to the left or right, then change the rotation
        if( inputEvent.keyPressed[ KeyEvent.VK_RIGHT ] ) {
            angularVelocity += carTurningRate
                    * Math.min( 1.0, 4.0 * Math.sqrt( 
                        velocityx*velocityx+velocityy*velocityy)/maxVelocity );
        } else if( inputEvent.keyPressed[ KeyEvent.VK_LEFT ] ) {
            angularVelocity -= carTurningRate
                    * Math.min( 1.0, 4.0 * Math.sqrt( 
                        velocityx*velocityx+velocityy*velocityy)/maxVelocity );
        }

        // Ensure the care cannot exceed the set maximum turning rate
        if( Math.abs( angularVelocity ) > maxAngularVelocity )
            angularVelocity = maxAngularVelocity * Math.signum(angularVelocity);
                
        // Update the car's position and rotation
        x += velocityx;
        y += velocityy;        
        rotation += angularVelocity;
    }
}
