package spaceInvaders;

import game.assets.*;
import game.engine.GameLayer;
import game.engine.GameObject;

/**
 * Player score graphical object.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class Score extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of GUI elements
     */
    protected static final int GUI_ELEMENT_DRAW_ORDER = 5;

    /**
     * Define the number of digits that will be shown on the screen
     * as representing the score
     */
    private static final int NUM_DIGITS = 5;

    /**
     * Define the current score and the target score. The target score
     * holds the latest score that is accumulated by the player and
     * the current score holds the current score that is reported by
     * this object (the current score is incremented by 1 per update -
     * thereby giving the impression of score spinning up).
     */
    private int targetScore;
    private int currentScore;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a player score object with a starting score of zero
     *
     * @param  gameLayer GameLayer to which the score will be added
     * @param  x x location at which the score should be shown
     * @param  y y location at which the score should be shown
     */
    public Score(GameLayer gameLayer, int x, int y) {
        super(gameLayer);

        // Name this game object to permit ease of retrieval
        setName("Score");

        this.x = x;
        this.y = y;
        this.drawOrder = GUI_ELEMENT_DRAW_ORDER;

        targetScore = 0;
        currentScore = 0;

        // As this object is not intended to interact with other objects, e.g.
        // missiles, etc., ensure that it will not be considered within
        // collision tests.
        canIntersectOtherGraphicalObjects = false;

        // Define the array of digits that will visually represent the score
        GraphicalAsset[] assets = new GraphicalAsset[NUM_DIGITS];

        // Each digit consists of an image asset sequence (holding a total of ten
        // images, from '0' through '9'. By default the 'home frame' of each
        // image asset sequence, in this case, is the digit zero.
        for (int idx = 0; idx < NUM_DIGITS; idx++) {
            ImageAssetSequence number = (ImageAssetSequence) assetManager
                        .retrieveAsset( "Numbers" );

            // Name each asset to permit ease of retrieval
            number.setAssetName(number.getAssetName() + idx);

            assets[idx] = number;
            assets[idx].offsetX = idx * number.width - (NUM_DIGITS - 1) * number.width / 2;
            assets[idx].offsetY = 0;
        }

        setRealisationAndGeometry(assets);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Reset the player score to zero
     */
    public void resetScore() {
        targetScore = 0;
        currentScore = 0;

        setRealisation();
    }

    /**
     * Set the player score to that specified.
     *
     * @param score integer player score
     */
    public void setScore(int score) {
        targetScore = score;
        currentScore = score;

        setRealisation();
    }

    /**
     * Add the specified amount onto the player score
     *
     * @param score integer additional player score
     */
    public void addScore(int score) {
        targetScore += score;
    }

    /**
     * Update the score object if necessary
     */
    @Override
    public void update() {
        if (currentScore < targetScore) {
            currentScore++;
            setRealisation();
        }
    }

    /**
     * Set the graphical realisation of the object to reflect the current score
     */
    public void setRealisation() {
        int scoreFragment = currentScore;
        for (int idx = 0; idx < graphicalRealisation.length; idx++) {
            int digit = scoreFragment % 10;
            scoreFragment = scoreFragment / 10;

            ImageAssetSequence digitImage = (ImageAssetSequence) 
                    graphicalRealisation[graphicalRealisation.length - (idx+1)];
            digitImage.setHomeFrame(digit);
            digitImage.update();
        }
    }
}