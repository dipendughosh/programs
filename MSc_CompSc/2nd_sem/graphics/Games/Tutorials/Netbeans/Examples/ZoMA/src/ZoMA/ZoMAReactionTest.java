package ZoMA;

import game.engine.*;
import game.components.*;
import java.awt.Color;

/**
 * ReactionTest is one of the four current tests supported within the ZoMA game.
 * It displays a target on the screen (alongside optional screen flash and sound
 * effect) and times the length of time needed to react to the stimulus in pressing
 * the LMB.
 * <P>
 * If the test is ranked, then the average reaction time must be below the set target
 * for the test to be successful.
 * <P>
 * Note: this class extends ZoMAGameLayer which provides most of the timing
 * and control logic
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.1 $ $Date: 2007/08 $
 */

public class ZoMAReactionTest extends ZoMAGameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Minimum count down delay for the reaction test
     */
     private final static int REACION_TEST_MINIMUM_DELAY = 90;

     /**
     * Maximum count down delay for the reaction test
     */
     private final static int REACION_TEST_MAXIMUM_DELAY = 360;
        
    /**
     * Boolean flag determining if the screen should change colour following
     * the display of the target (i.e. increasing the visual stimulus).
     */            
    private boolean reactionTestChangeScreenColour;

    /**
     * Boolean flag determining if a loud and sharp sound effect should be played
     * whenever the target is displayed (aside, this will typically reduce
     * the reaction time as most people react faster to sudden sound stimuli as 
     * compared against visual stimuli).
     */                
    private boolean playSoundOnTargetDisplay;

    /**
     * Flag tracking if an invalid test has occurred (i.e. the mouse has been 
     * clicked before the target has appeared).
     */
    private boolean invalidTest;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Setup a new reaction test based on the specified parameters
     */ 
    public ZoMAReactionTest(GameEngine gameEngine, boolean rankedTest, 
            Profile playerProfile, int numberOfTests, double targetScaleFactor, 
            boolean reactionTestChangeScreenColour, boolean playSoundOnTargetDisplay) {
        super(gameEngine, rankedTest, playerProfile, numberOfTests, 0, 1);

        this.reactionTestChangeScreenColour = reactionTestChangeScreenColour;
        this.playSoundOnTargetDisplay = playSoundOnTargetDisplay;
        
        countDownMinimumDelay = REACION_TEST_MINIMUM_DELAY;
        countDownMaximumDelay = REACION_TEST_MAXIMUM_DELAY;

        defineTarget(TargetType.BullsEye, targetScaleFactor, "Static", 5, "Random");
        defineSight(SightType.Crosshairs, 1.0, 0.0, 0.0);

        setupGUI();
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Setup                                                        //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Setup GUI components for a reaction test
     */ 
    @Override
    protected void setupGUI() {
        super.setupGUI();

        buildMessage("NumReactionTestsRemaining", "", width / 7.0, 25.0);
        buildMessage("AverageReactionTime", "", width / 2.0, 25.0);
        buildMessage("EllapsedTime", "", width - width / 7.0, 25.0);

        Bar reactionTimeBar 
                = new Bar(this, "ReactionTimeBar", "TimeBarBorder", "ReactionTimeBar", 500);
        reactionTimeBar.setPoints(0);
        reactionTimeBar.setInnerAssetOffset(-4.0, -4.0);
        reactionTimeBar.x = this.width / 2.0;
        reactionTimeBar.y = -height;
        reactionTimeBar.setDrawOrder(GUI_UNDER_TARGET_DRAW_ORDER);
        addGameObject(reactionTimeBar);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: ZoMAGameLayer control extensions                             //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * This method is automatically called whenever the count down phase has
     * just started and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateCountDownStarted() {
        // Update the test number
        ((TextElement) getGameObject( "NumReactionTestsRemaining" )).
                setText("Test: " + (currentTest + 1));

        // Update and display the average reaction time over the tests
        long averageReactionTime = 0;
        for (int idx = 0; idx < currentTest; idx++)
            averageReactionTime += shotTimes[idx][0];
        if (currentTest != 0) averageReactionTime /= currentTest;
        ((TextElement) getGameObject( "AverageReactionTime" )).
                setText("Average " + averageReactionTime + "ms");

        // Display the reaction time bar (only really needed on
        // the first test, and redundant thereafter)
        Bar reactionTimeBar = (Bar) getGameObject( "ReactionTimeBar" );
        reactionTimeBar.y = this.height - reactionTimeBar.height / 2.0;

        // Ensure the invalid test flag is set to false
        invalidTest = false;
    }

    /**
     * This method is automatically and repeatedly called once the count
     * down phase is in progress and is intended to provide test specific 
     * actions.
     */ 
    @Override
    protected void updateCountDownInProgress() {
        // Invalidate the test should the user click the LMB before the
        // target has appeared on the screen.
        if (!invalidTest && inputEvent.mouseButton1Pressed) {
            buildMessage("InvalidTestMessage1", "Target? What? Where?", 
                    width / 2.0, height / 2.0 + 50.0);
            buildMessage("InvalidTestMessage2", "Please wait for the target to appear...", 
                    width / 2.0, height / 2.0 + 100.0);

            // Reset the countdown period to display the error message for 2 seconds            
            updateCounter = 1;
            initialisationDelay = 120;
            invalidTest = true;
        }
    }

    /**
     * This method is automatically called whenever the count down phase 
     * has just completed and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateCountDownFinished() {
        // If the test was invalidated, then remove the error message and
        // restart the test
        if (invalidTest) {
            queueGameObjectToRemove(getGameObject("InvalidTestMessage1"));
            queueGameObjectToRemove(getGameObject("InvalidTestMessage2"));
            updateCounter = -1;
            shotMode = ShotMode.CountDown;
        }
    }

    /**
     * This method is automatically called whenever the target has
     * just been shown and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetStarted() {
        // Reset the reaction time bar to zero ms
        Bar reactionTimeBar = (Bar) getGameObject( "ReactionTimeBar" );
        reactionTimeBar.setPoints(0);

        // If needed change the screen colour
        if (reactionTestChangeScreenColour)
            backgroundColour = new Color(230, 50, 50, 255);

        // If needed play a sound
        if (playSoundOnTargetDisplay)
            assetManager.retrieveSoundAssetArchetype("ReactionBang").play();
    }
    
    /**
     * This method is automatically called whenever the show target 
     * phase is in progress and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetInProgress() {
        // Determine how much time has ellapsed since the target
        // was shown and update the reaction time bar and the 
        // time ellapsed text element
        int timeEllapsed = (int) ((System.nanoTime() 
            - targetSpawnTime)/1000000L - AVERAGE_SAMPLING_CORRECTION);

        ((TextElement) getGameObject( "EllapsedTime" )).setText(timeEllapsed + "ms");

        Bar reactionTimeBar = (Bar) getGameObject( "ReactionTimeBar" );
        if (timeEllapsed > 0) {
            if (timeEllapsed < reactionTimeBar.getMaximumPoints()) {
                reactionTimeBar.setPoints(timeEllapsed);
            } else {
                reactionTimeBar.setPoints(reactionTimeBar.getMaximumPoints());
            }
        }
    }
    
    /**
     * This method is automatically called whenever the LMB is pressed during
     * the show target phase and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetMousePressed() {
        // Move the target off the screen (i.e. hide it)
        target.x = -width;

        // Update the player profile with details of the test
        playerProfile.recordReactionTimeTest(shotTimes[currentTest][0]);

        // Reset the background colour
        backgroundColour = new Color(230, 233, 230, 255);
    }
    
    /**
     * This method is automatically called whenever the reset target phase
     * is in progress and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateResetTargetInProgress() {
        // Each reaction time test automatically proceeds ont the
        // next test, i.e. simply set the rest target completed
        // flag to true
        resetTarget = true;
    }

    /**
     * This method is automatically called whenever the test finalisation
     * phase has just started and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateFinalisationStarted() {
        double centerX = this.width / 2.0;
        double centerY = this.height / 2.0;

        // Determine the overall average reaction time across the tests
        int averageReactionTime = 0;
        int[] reactionTimes = new int[shotTimes.length];
        for (int idx = 0; idx < shotTimes.length; idx++) {
            reactionTimes[idx] = shotTimes[idx][0];
            averageReactionTime += shotTimes[idx][0];
        }
        averageReactionTime /= shotTimes.length;

        // Display the average reaction time
        ((TextElement) getGameObject( "AverageReactionTime" )).
                setText("Average " + averageReactionTime + "ms");

        if (rankedTest) {
            // If this is a ranked test, then determine the rank reaction time 
            // and display appropriate text depending on if the test has been 
            // passed.            
            Profile.Rank rank = playerProfile.getReactionTimeRank() == Profile.Rank.Rank6 
                    ? Profile.Rank.Rank6 : playerProfile.getNextReactionTimeRank();
            String rankString = "Rank " + rank.toString().substring(4, 5);

            buildButton("Return", "Return", centerX + 50.0, centerY + 150.0);
            buildMessage("Average reaction time: " + averageReactionTime + "ms.", 
                    centerX + 50.0, centerY);

            if (playerProfile.considerReactionTimeTestForRank(rank, averageReactionTime)) {
                buildNonInteractiveGraphicalObject("SuccessBorder", centerX, centerY);
                buildMessage(rankString + " obtained.", centerX + 50, centerY + 45.0);
                assetManager.retrieveSoundAssetArchetype("Success").play();
            } else {
                buildNonInteractiveGraphicalObject("FailureBorder", centerX, centerY);
                buildMessage(rankString + " requires an average of " 
                        + Profile.getAverageReactionTimeForRank(rank) + "ms.", 
                        centerX + 50.0, centerY + 45.0);
                assetManager.retrieveSoundAssetArchetype("Failure").play();
            }
        } else {
            // If this is not a ranked test, then just display the average reaction time
            buildMessage("Average reaction time: " + 
                    averageReactionTime + "ms.", centerX, centerY);
            buildButton("Return", "Return", centerX, centerY + 65.0);
        }
    }
    
    /**
     * This method is automatically called whenever the test finalisation
     * phase is in progress  and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateFinalisationInProgress() {
        // Signify that the test has completed whenever the return button is clicked
        if (updateCounter > 1) {
            Button finishButton = (Button) getGameObject( "Return" );
            finishButton.update();

            if (finishButton.buttonClicked()) {
                finished = true;
            }
        }
    }
}
