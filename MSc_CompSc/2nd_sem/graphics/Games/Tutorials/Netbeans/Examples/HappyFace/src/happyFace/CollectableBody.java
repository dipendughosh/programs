package happyFace;

import game.engine.*;
import game.physics.*;
import game.geometry.*;
import game.assets.*;
import java.awt.Graphics2D;
import java.awt.Composite;
import java.awt.AlphaComposite;
import java.io.*;

/**
 * The CollectableBody class provides a basic body that can be collected
 * by the player, e.g. health, bombs, etc.
 * <P>
 * The class is mostly concerned with encapsulating the appearance of
 * each collectable item alongside what happens when the item is collected.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class CollectableBody extends Body {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Define the possible types of collectable body that are supported
     * by this class, alongside an instance variable holding the type
     * of a collectable instance.
     */
    public enum CollectableType {
        Life, LargeHealth, SmallHealth, SmallBomb, MediumBomb, LargeBomb, Diamond }
    CollectableType collectableType;
    
    /**
     * Whenever collected, a collectable item fades out over an interval
     * of time. This value determines the number of updates ticks that
     * will be used for the fade animation, alongside the current 
     * collected animation frame. A boolean flag is used to track if the
     * item has been collected.
     */
    private static final int NUM_COLLECTED_ANIMATION_FRAMES = 60;
    private int collectedAnimationFrame = 0;
    private boolean collected = false;
    

    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new, default, collectable body.
     * <P>
     * Note: By default a large health collectable is created
     */ 
    public CollectableBody(GameLayer gameLayer) {
        this(gameLayer, 0.0, 0.0, 2, "LargeHealth", CollectableType.LargeHealth);
    }

    /**
     * Create a new collectable body based on the specified parameters.
     * <P>
     * Note: The appearance of the collectable body is specified separately
     * from the actions that should be executed once the body is collected
     */ 
    public CollectableBody(GameLayer gameLayer, double x, double y, int drawOrder, 
            String realisationName, CollectableType collectableType) {
        super(gameLayer, x, y, drawOrder);

        this.collectableType = collectableType;
        GraphicalAsset realisation = assetManager.retrieveGraphicalAsset(realisationName);

        Shape geometry;
        switch (collectableType) {
            case Life:
                setMass(100.0);
                geometry = new Box(0.0, 0.0, realisation.width, realisation.height);
                break;
            case LargeHealth:
                setMass(50.0);
                geometry = new Box(0.0, 0.0, realisation.width, realisation.height);
                break;
            case SmallHealth:
                setMass(20.0);
                geometry = new Box(0.0, 0.0, realisation.width, realisation.height);
                break;
            case SmallBomb:
                setMass(10.0);
                geometry = new Circle(0.0, 0.0, realisation.width / 2.0);
                break;
            case MediumBomb:
                setMass(30.0);
                geometry = new Circle(0.0, 0.0, realisation.width / 2.0);
                break;
            case LargeBomb:
                setMass(50.0);
                geometry = new Box(0.0, 0.0, realisation.width, realisation.height);
                break;
            case Diamond:
                setMass(50.0);
                geometry = new Box(0.0, 0.0, realisation.width, realisation.height);
                break;
            default:
                throw new IllegalArgumentException("CollectableBody.constructor: " + 
                        "Unknown collectableType: " + collectableType);
        }

        // Setup the realisation and geometry and set the restitution of
        // the collectable to zero (i.e. no bounce)
        setRealisation(realisation);
        setGeometry(geometry);
        restitution = 0.0;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Return the number of points to be awarded whenever this item is collected
     */
    public int getPoints() {
        switch (collectableType) {
            case Life: return 50;
            case LargeHealth: return 30;
        case SmallHealth: return 10;
            case SmallBomb: return 5;
            case MediumBomb: return 10;
            case LargeBomb: return 20;
            case Diamond: return 30;
            default:
                throw new IllegalStateException("CollectableBody.getPoints: " + 
                        "Unknown collectable type: " + collectableType);
        }
    }

    /**
     * Update the collectable, i.e. test for intersection with the player
     * and, if so, execute behaviour appropriate to the type of collectable 
     */
    @Override
    public void update() {
        // If this collectable is animated, then update its animation
        if (collectableType == CollectableType.SmallHealth 
                || collectableType == CollectableType.LargeHealth 
                || collectableType == CollectableType.Life) {
            graphicalRealisation[0].update();
        }

        // Test for intersection with the player
        GameObject playerGameObject = gameLayer.getGameObject("Player");
        if (playerGameObject != null && 
                GameObjectCollider.determineIfBodiesTouching(this, (Body) playerGameObject)) {
            EmoticonPlayer player = (EmoticonPlayer) playerGameObject;
            
            // Carry out collectable specific action on collection
            switch (collectableType) {
                case Life:
                    player.addLife();
                    player.addScore(getPoints());
                    assetManager.retrieveSoundAssetArchetype("CollectExtraLife").play();
                    break;
                case LargeHealth:
                    player.addHealth(100.0);
                    player.addScore(getPoints());
                    assetManager.retrieveSoundAssetArchetype("CollectHealth").play();
                    break;
                case SmallHealth:
                    player.addHealth(50.0);
                    player.addScore(getPoints());
                    assetManager.retrieveSoundAssetArchetype("CollectHealth").play();
                    break;
                case SmallBomb:
                    player.addSmallBombs(5);
                    player.addScore(getPoints());
                    assetManager.retrieveSoundAssetArchetype("CollectBomb").play();
                    break;
                case MediumBomb:
                    player.addMediumBombs(3);
                    player.addScore(getPoints());
                    assetManager.retrieveSoundAssetArchetype("CollectBomb").play();
                    break;
                case LargeBomb:
                    player.addLargeBombs(1);
                    player.addScore(getPoints());
                    assetManager.retrieveSoundAssetArchetype("CollectBomb").play();
                    break;
                case Diamond:
                    player.addScore(getPoints());
                    assetManager.retrieveSoundAssetArchetype("CollectDiamond").play();
                    break;
                default:
                    throw new IllegalStateException("CollectableBody.update: " + 
                            "Unknown collectable type: " + collectableType);
            }

            // Signify that this item has been collected and prevent it from
            // intersecting other objects (i.e. it will fall away under the
            // influence of gravity). Any arbiters (i.e. points of contact
            // between the collectable and other objects, e.g. the ground,
            // are removed - this ensures that the body will not have
            // any interacting with other bodies.            
            collected = true;
            canIntersectOtherGraphicalObjects = false;
            ((CollisionSpace) gameLayer).removeArbitersForBody(this);
        }

        // If collected, then update the fade animation counter, and if needed
        // remove the collectable once the fade has completed
        if (collected) {
            collectedAnimationFrame++;
            if (collectedAnimationFrame >= NUM_COLLECTED_ANIMATION_FRAMES) {
                gameLayer.queueGameObjectToRemove(this);
            }
        }
    }

    /**
     * Overload the GameObject serialisation method to provide serialisation  
     * support for CollectableBody objects     
    */
    @Override
    public void serialiseGameObjectState(
            ObjectOutputStream stream, GameObject gameObject) throws IOException {
        super.serialiseGameObjectState(stream, gameObject);

        // Only the collectable type needs to be stored 
        stream.writeUTF(collectableType.toString());
    }

    /**
     * Overload the GameObject serialisation method to provide serialisation  
     * support for CollectableBody objects     
    */
    @Override
    public void loadGameObjectState(
            ObjectInputStream stream, GameLayer gameLayer) throws IOException {
        super.loadGameObjectState(stream, gameLayer);

        // Load and store what type of collectable this object is
        CollectableType collectableType;
        String collectableTypeString = stream.readUTF();
        if (collectableTypeString.compareTo("Life") == 0) {
            this.collectableType = CollectableType.Life;
        } else if (collectableTypeString.compareTo("LargeHealth") == 0) {
            this.collectableType = CollectableType.LargeHealth;
        } else if (collectableTypeString.compareTo("SmallHealth") == 0) {
            this.collectableType = CollectableType.SmallHealth;
        } else if (collectableTypeString.compareTo("SmallBomb") == 0) {
            this.collectableType = CollectableType.SmallBomb;
        } else if (collectableTypeString.compareTo("MediumBomb") == 0) {
            this.collectableType = CollectableType.MediumBomb;
        } else if (collectableTypeString.compareTo("LargeBomb") == 0) {
            this.collectableType = CollectableType.LargeBomb;
        } else if (collectableTypeString.compareTo("Diamond") == 0) {
            this.collectableType = CollectableType.Diamond;
        } else {
            throw new IllegalStateException("CollectableBody.loadGameObjectState: " + 
                    "Unknown collectableType: " + collectableTypeString);
        }
    }

    /**
     * Draw the graphical game object to the specified graphics object
     * at the specified x and y offset
     */
    @Override
    public void draw(Graphics2D graphics2D, int drawX, int drawY) {
        if (!collected) {
            super.draw(graphics2D, drawX, drawY);
        } else {
            if (collectedAnimationFrame >= NUM_COLLECTED_ANIMATION_FRAMES)
                return;

            // If the collected fade is in progress, then draw out
            // the associated image but with an increasing amount
            // of fading
            Composite originalComposite = graphics2D.getComposite();
            graphics2D.setComposite(AlphaComposite.
                    getInstance(AlphaComposite.SRC_OVER, 1.0f - 
                        (float) collectedAnimationFrame 
                            / (float) NUM_COLLECTED_ANIMATION_FRAMES));
            super.draw(graphics2D, drawX, drawY);
            graphics2D.setComposite(originalComposite);
        }
    }
}
