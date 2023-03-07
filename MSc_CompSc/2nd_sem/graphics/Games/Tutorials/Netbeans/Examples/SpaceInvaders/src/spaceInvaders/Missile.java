package spaceInvaders;

import game.engine.GameLayer;
import game.engine.GameObject;

/**
 * Generic game object representing a missile
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 *
 * @see Missile
 */

public class Missile extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of missiles
     */
    protected static final int MISSILE_DRAW_ORDER = 3;

    /**
     * Default missile movement speed in terms of pixels/update
     */
    protected static final double MISSILE_SPEED = 10.0;

    /**
     * Actual missile movement speed in terms of pixels/update
     */
    protected double yVel;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Generic constructor for missiles, storing the x and y location
     *
     * @param  x x location at which this missile should be added
     * @param  y y location at which this missile should be added
     * @param  gameLayer GameLayer to which this missile will be added
     */
    public Missile(GameLayer gameLayer, double x, double y) {
        super(gameLayer);

        this.x = x;
        this.y = y;
        this.drawOrder = MISSILE_DRAW_ORDER;
    }
}
