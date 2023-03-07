package spaceInvaders;

import game.engine.GameLayer;
import game.engine.GameObject;
import game.geometry.*;

/**
 * Player ship object.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class PlayerShip extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of the player ship
     */
    protected static final int PLAYER_SHIP_DRAW_ORDER = 3;

    /**
     * Define the default speed of the player ship
     */
    protected static final double SHIP_SPEED = 6.0;

    /**
     * Define the current x velocity of the player ship
     */
    protected double xVel;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new player ship at the specified offset
     *
     * @param  gameLayer GameLayer to which this ship will be added
     * @param  x x location at which this ship should be added
     * @param  y y location at which this ship should be added
     */
    public PlayerShip(GameLayer gameLayer, double x, double y) {
        super(gameLayer);

        // Name this game object to permit ease of retrieveal
        setName("PlayerShip");

        this.x = x;
        this.y = y;
        this.drawOrder = PLAYER_SHIP_DRAW_ORDER;

        xVel = SHIP_SPEED;

        setRealisation("PlayerShipImg");

        // Set up a number of accurate bounding regions for the player ship
        setGeometry(new Shape[]{
            new Box(0, 0, 17, 26), new Box(-15, 10, 11, 9), new Box(15, 10, 11, 9)});
    }
}
