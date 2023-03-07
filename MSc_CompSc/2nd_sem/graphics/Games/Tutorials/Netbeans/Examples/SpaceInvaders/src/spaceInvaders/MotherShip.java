package spaceInvaders;

import game.engine.GameLayer;
import game.engine.GameObject;
import java.util.Random;

/**
 * Alien mothership object. When created the alien will randomly move from
 * one side of the screen towards the other side of the screen.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class MotherShip extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of the mother ship
     */
    protected static final int MOTHER_SHIP_DRAW_ORDER = 3;

    /**
     * Score for destroying this alien mothership.
     */
    protected int score = 100;

    /**
     * Current x velocity of this mothership
     */
    protected double xVel;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Alien mothership at the specified offset
     *
     * @param  gameLayer GameLayer to which this alien ship will be added
     */
    public MotherShip(GameLayer gameLayer) {
        super(gameLayer);

        // Provide this game object with a specified name to permit ready retrieval
        setName("MotherShip");

        setRealisationAndGeometry("MothershipImg");
        drawOrder = MOTHER_SHIP_DRAW_ORDER;

        // Randomly decide the side on which the ship will enter
        if ((new Random()).nextInt(2) == 0) {
            x = 0;
            xVel = 3;
        } else {
            x = gameLayer.width - width;
            xVel = -3;
        }
        
        y = 50;
    }
}