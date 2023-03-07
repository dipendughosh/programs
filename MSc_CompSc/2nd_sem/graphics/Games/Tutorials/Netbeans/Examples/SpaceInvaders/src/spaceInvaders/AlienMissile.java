package spaceInvaders;

import game.assets.*;
import game.engine.GameLayer;
import game.geometry.*;

/**
 * Game object representing the missile fired by an alien ship
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 *
 * @see Missile
 */

public class AlienMissile extends Missile {

    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Alien missile at the specified offset and play an
     * appropiate sound effect.
     *
     * @param  gameLayer GameLayer to which this missile will be added
     * @param  x x location at which this missile should be added
     * @param  y y location at which this missile should be added
     */
    public AlienMissile(GameLayer gameLayer, double x, double y) {
        super(gameLayer, x, y);

        setRealisationAndGeometry("AlienMissileImg");

        // Play the alien shot sound
        assetManager.retrieveSoundAssetArchetype("AlienShotSfx").play();

        // By default the alien missile assumes the default missile speed
        this.yVel = MISSILE_SPEED;
    }
}