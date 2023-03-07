package spaceInvaders;

import game.engine.GameLayer;
import game.geometry.*;

/**
 * Game object representing the missile fired by the player ship
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 *
 * @see Missile
 */

public class PlayerMissile extends Missile {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Boolean variable used to determine if this player missile object has
     * already hit something (and can be considered to have exploded).
     */
    private boolean hasHit = false;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Player missile at the specified offset and play an
     * appropriate sound effect.
     *
     * @param  gameLayer GameLayer to which this missile will be added
     * @param  x x location at which this missile should be added
     * @param  y y location at which this missile should be added
     */
    public PlayerMissile(GameLayer gameLayer, double x, double y) {
        super(gameLayer, x, y);

        // Name this game object to permit ease of retrieval
        setName("PlayerMissile");

        setRealisation(assetManager.retrieveGraphicalAsset("PlayerMissileImg"));
        setGeometry(new Circle(0, 0, 10));

        // By default, the player missile is twice as fast as alien missiles
        yVel = -MISSILE_SPEED * 2;

        assetManager.retrieveSoundAssetArchetype("PlayerShotSfx").play();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Indicate if this missile has already hit something
     *
     * @return boolean true if this missile has already hit something, otherwise false
     */
    public boolean hasAlreadyHit() {
        return hasHit;
    }

    /**
     * Record that this missile has hit something
     */
    public void recordHasHit() {
        hasHit = true;
    }
}
