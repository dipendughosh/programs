package spaceInvaders;

import game.assets.ImageAssetSequence;
import game.engine.GameLayer;
import game.engine.GameObject;
import java.util.*;

/**
 * Explosion effect for exploding ships
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class Explosion extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of explosions
     */
    protected static final int EXPLOSION_DRAW_ORDER = 4;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new explosion at the specified offset and play an appropriate
     * sound effect
     *
     * @param  x x location at which this explosion should be added
     * @param  y y location at which this explosion should be added
     * @param  gameLayer GameLayer to which this explosion will be added
     */
    public Explosion(GameLayer gameLayer, double x, double y) {
        super(gameLayer);

        this.x = x;
        this.y = y;
        this.drawOrder = EXPLOSION_DRAW_ORDER;

        ImageAssetSequence explosion = 
                (ImageAssetSequence) assetManager.retrieveAsset( "ExplosionAnim" );
        setRealisationAndGeometry(explosion);

        // Randomise the explosion period within a defined interval
        explosion.setAnimationPeriod((new Random()).nextInt(800) + 200);

        // As we want to tell the game layer to which we belong that we can
        // removed once the explosion is completed, set this game object
        // to be an observer of the explosion animation.
        explosion.addObserver(this);

        // Play the explosion sound effect
        assetManager.retrieveSoundAssetArchetype("ShipExplodeSfx").play();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * This method is invoked whenever the explosion animation associated with
     * this game object has finished (at which point this game object queues
     * itself to be removed from its game layer).
     *
     * @param  observableObject observed object
     * @param  message message from the observed object
     */
    public void update(Observable observableObject, Object message) {
        // Once the animation has completed, remove this object from its
        // corresponding game layer.
        if (((String) message).compareTo("AnimationCompleted") == 0) {
            gameLayer.queueGameObjectToRemove(this);
        }
    }
}
