package spaceInvaders;

import game.assets.ImageAsset;
import game.engine.GameLayer;
import game.engine.GameObject;

/**
 * Number of player lifes graphical object.
 * <P>
 * Note: This object serves a dual purpose in terms of tackling the
 * number of player lifes and providing a suitable graphical
 * representation to the player.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class Lifes extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of GUI elements
     */
    protected static final int GUI_ELEMENT_DRAW_ORDER = 5;

    /**
     * Define the initial number of lifes afforded to the player
     * and maintain a count of the current number of assigned lifes
     */
    private static final int INITIAL_NUM_LIFES = 3;
    private int numberOfLifes;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a player life object with the default number of assigned lifes.
     *
     * @param  x x location at which the lifes should be shown
     * @param  y y location at which the lifes should be shown
     * @param  gameLayer GameLayer to which the lifes will be added
     */
    public Lifes(GameLayer gameLayer, double x, double y) {
        super(gameLayer);

        // Provide this game object with a define name to permit easy retrieval
        // within other parts of the game
        setName("Lifes");

        this.x = x;
        this.y = y;
        this.drawOrder = GUI_ELEMENT_DRAW_ORDER;

        numberOfLifes = INITIAL_NUM_LIFES;

        // As this object is not intended to interact with other objects, e.g.
        // missiles, etc., ensure that it will not be considered within
        // collision tests.
        canIntersectOtherGraphicalObjects = false;

        // Create the graphical realisation for this game object
        setRealisation();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    /**
     * Define the graphical representation for this object, based on the
     * display of one player ship per life.
     */
    private void setRealisation() {
        ImageAsset playerShipImg = 
                (ImageAsset) assetManager.retrieveAsset( "PlayerShipImg" );

        String[] assetNames = new String[numberOfLifes];
        int[] assetXOffsets = new int[numberOfLifes];
        int[] assetYOffsets = new int[numberOfLifes];

        for (int idx = 0; idx < numberOfLifes; idx++) {
            assetNames[idx] = playerShipImg.getAssetName();
            assetXOffsets[idx] = idx * playerShipImg.width 
                    - (numberOfLifes - 1) * playerShipImg.width / 2;
            assetYOffsets[idx] = 0;
        }

        setRealisationAndGeometry(assetNames, assetXOffsets, assetYOffsets);
    }

    /**
     * Return the current number of player lifes
     *
     * @return int containing the current number of player lifes
     */
    public int getNumberOfLifes() {
        return numberOfLifes;
    }

    /**
     * Reset the number of lifes to the initial default value, updating
     * the graphical representation accordingly
     */
    public void resetNumberOfLifes() {
        numberOfLifes = INITIAL_NUM_LIFES;
        setRealisation();
    }

    /**
     * Decrement the number of life by one (minimum of zero) and update the graphical
     * representation accordingly.
     */
    public void decrementLifes() {
        if (numberOfLifes > 0) {
            numberOfLifes -= 1;
        }
        setRealisation();
    }
}