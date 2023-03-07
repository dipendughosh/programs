package spaceInvaders;

import game.engine.GameLayer;
import game.engine.GameObject;
import game.geometry.*;

/**
 * Alien ship object. Currently two different types of alien ship are
 * supported which are functionally equivalent and only differ in
 * terms of the graphical realisation and their score.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class AlienShip extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of alien ships
     */
    protected static final int ALIEN_SHIP_DRAW_ORDER = 3;

    /**
     * Static variables defining the point values for the two types of
     * ships (those displayed in the top of the fleet and those in the
     * bottom of the fleet)
     */
    protected static final int TOP_FLEET_SCORE = 40;
    protected static final int BOTTOM_FLEET_SCORE = 20;

    /**
     * Score for destroying this alien ship. Currently all ships, other than the
     * mothership, are worth a default of 20 points.
     */
    protected int score;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Alien ship at the specified offset
     *
     * @param  gameLayer GameLayer to which this alien ship will be added
     * @param  shipType integer specifying the ship's graphical realisation 
     *         (currently a value of 0 or 1 is valid)
     * @param  x x location at which this alien ship should be added
     * @param  y y location at which this alien ship should be added
     *
     * @exception IllegalArgumentException if an invalid ship type is specified
     */
    public AlienShip(GameLayer gameLayer, int shipType, double x, double y) {
        super(gameLayer);

        this.x = x;
        this.y = y;
        this.drawOrder = ALIEN_SHIP_DRAW_ORDER;

        // Set the ship realisation based on the specified ship type
        if (shipType == 0) {
            setRealisation("AlienShip1Img");
            setGeometry(new Circle(0, 0, 20));
            score = TOP_FLEET_SCORE;
        } else if (shipType == 1) {
            setRealisation("AlienShip2Img");
            setGeometry(new Circle(0, 0, 20));
            score = BOTTOM_FLEET_SCORE;
        } else {
            throw new IllegalArgumentException(
                    "AlienShip.constructor: Invalid shipType specified: " + shipType);
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Return the score for destroying this ship
     *
     * @return  integer score available for destroying this ship
     */
    public int getScore() {
        return score;
    }
}
