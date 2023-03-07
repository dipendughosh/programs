package ZoMA;

import game.engine.*;
import game.components.*;

/**
 * SnapShotTest is one of the four current tests supported within the ZoMA game.
 * It displays a target on the screen and measures the length of time needed 
 * for the player to react and shoot, alongside the shot accuracy.
 * <P>
 * If the test is ranked, then the test conditions must be passed for the test
 * to be successful.
 * <P>
 * Note: this class extends ZoMAGameLayer which provides most of the timing
 * and control logic
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.1 $ $Date: 2007/08 $
 */

public class ZoMASnapShotTest extends ZoMAGameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Minimum count down delay for the reaction test
     */
    private static final int SNAPSHOT_TEST_MINIMUM_DELAY = 60;

    /**
     * Maximum count down delay for the reaction test
     */
    private static final int SNAPSHOT_TEST_MAXIMUM_DELAY = 90;

    /**
     * Values recording the average mouse movement time and shot time 
     * for the target, alongside the target and bull hit averages.
     */
    private long averageMouseMoveTime;
    private long averageShotTime;
    private double averageTargetAccuracy;
    private double averageBullAccuracy;

    /**
     * Flag tracking if an invalid test has occurred (i.e. the mouse has been 
     * clicked before the target has appeared).
     */
    private boolean invalidTest;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Setup a new snap shot test based on the specified parameters
     */ 
    public ZoMASnapShotTest(GameEngine gameEngine, boolean rankedTest, Profile playerProfile, 
            int numberOfTests, double sightSpeedFactor, double targetScaleFactor, 
            String targetDisplayRegion) {
        super(gameEngine, rankedTest, playerProfile, numberOfTests, 0, 1);

        countDownMinimumDelay = SNAPSHOT_TEST_MINIMUM_DELAY;
        countDownMaximumDelay = SNAPSHOT_TEST_MAXIMUM_DELAY;

        defineTarget(TargetType.BullsEye, targetScaleFactor, "Static", 5, targetDisplayRegion);
        defineSight(SightType.Crosshairs, sightSpeedFactor, 0.0, 0.0);

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

        buildMessage( "NumSnapShotTestsRemaining", "", width/7.0, 25.0 );

        buildMessage( "MouseMoveTime", "", width/2.0, 25.0 );        
        buildMessage( "ShotTime", "", width/2.0, 70.0 );        
        buildMessage( "Accuracy", "", width/2.0, 110.0 );        

        buildMessage( "EllapsedTime", "", width-width/7.0, 25.0 );          
               
        Bar snapShotTimeBar = new Bar(
                this, "SnapShotTimeBar", "TimeBarBorder", "ShotTimeBar", 2500);
        snapShotTimeBar.setPoints(0);
        snapShotTimeBar.setInnerAssetOffset(-4.0, -4.0);
        snapShotTimeBar.x = this.width / 2.0;
        snapShotTimeBar.y = -height;
        snapShotTimeBar.setDrawOrder(GUI_UNDER_TARGET_DRAW_ORDER);
        addGameObject(snapShotTimeBar);

        GameObject sightReturnPoint = new GameObject(
                this, gameEngine.screenWidth / 2, gameEngine.screenHeight / 2);
        sightReturnPoint.setName("SightReturnPoint");
        sightReturnPoint.setRealisationAndGeometry("SightReturnPoint");
        sightReturnPoint.setDrawOrder(GUI_UNDER_TARGET_DRAW_ORDER);
        addGameObject(sightReturnPoint);
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: ZoMAGameLayer control extensions                             //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * This method is automatically called whenever the initialisation phase
     * has finished and is intended to provide test specific actions.
     */ 
    @Override
    protected void initialisationFinished() {
        // Initialise the snap shot averages
        updateSnapShotMeasurements();
    }

    /**
     * This method is automatically called whenever the count down phase has
     * just started and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateCountDownStarted() {
        // Update the test number
        ((TextElement) getGameObject( "NumSnapShotTestsRemaining" )).
                setText("Test: " + (currentTest + 1));

        // Reset the ellapsed time
        ((TextElement) getGameObject( "EllapsedTime" )).setText("0ms");

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
                    width / 2.0, height / 2.0 + 70.0);
            buildMessage("InvalidTestMessage2", "Please wait for the target to appear...", 
                    width / 2.0, height / 2.0 + 120.0);
            
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
        // Reset the shot time bar to zero ms        
        Bar snapShotTimeBar = (Bar) getGameObject( "SnapShotTimeBar" );
        snapShotTimeBar.setPoints(0);

        // Play a target display sound
        assetManager.retrieveSoundAssetArchetype("Appear").play();
    }

    /**
     * This method is automatically called whenever the show target 
     * phase is in progress and is intended to provide test specific actions.
     */ 
    @Override    
    protected void updateShowTargetInProgress() {
        // Determine how much time has ellapsed since the target
        // was shown and update the shot time bar and the 
        // time ellapsed text element
        int timeEllapsed = (int) ((System.nanoTime() 
            - targetSpawnTime)/1000000L - AVERAGE_SAMPLING_CORRECTION);

        ((TextElement) getGameObject( "EllapsedTime" )).setText(timeEllapsed + "ms");

        Bar snapShotTimeBar = (Bar) getGameObject( "SnapShotTimeBar" );
        if (timeEllapsed > 0) {
            if (timeEllapsed < snapShotTimeBar.getMaximumPoints()) {
                snapShotTimeBar.setPoints(timeEllapsed);
            } else {
                snapShotTimeBar.setPoints(snapShotTimeBar.getMaximumPoints());
            }
        }
    }

    /**
     * This method is automatically called whenever the LMB is pressed during
     * the show target phase and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetMousePressed() {
        // Update the player profile with details of the test
        playerProfile.recordSnapShot(
                getGameObjectScreenX(target), getGameObjectScreenY(target), 
                mouseMoveTimes[currentTest], shotTimes[currentTest][0], 
                (int)shotAccuracies[currentTest][0]);

        // Play a shot sound and, if the target has been hit, a hit sound
        assetManager.retrieveSoundAssetArchetype("Shot").play();
        if (shotAccuracies[currentTest][0] > 0.0) {
            assetManager.retrieveSoundAssetArchetype("Hit").play();
        }
        
        // Update the snap shot measurements
        updateSnapShotMeasurements();
    }

    /**
     * This method is automatically called whenever the reset target phase
     * has started and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateResetTargetStarted() {
        // Inform the user how go onto the next test
        buildMessage("ResetMouseMessage", 
                "Please move the mouse to the center of the screen.", 
                width / 2.0, height / 2.0 - 150.0);
    }

    /**
     * This method is automatically called whenever the reset target phase
     * is in progress and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateResetTargetInProgress() {
        // If the mouse has been returned to the center of the screen, then
        // go onto the next test
        GameObject sightReturnPoint = getGameObject("SightReturnPoint");
        if (Math.abs(sight.x - sightReturnPoint.x) > sightReturnPoint.width / 2.0 
                || Math.abs(sight.y - sightReturnPoint.y) > sightReturnPoint.height / 2.0) {
            sight.update();
        } else {
            if (updateCounter > 1) {
                resetTarget = true;
            }
        }
    }

    /**
     * This method is automatically called whenever the reset target phase
     * has been finished and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateResetTargetFinished() {
        // Reset the mouse to the exact center of the screen
        sight.centerSight();

        // Hide the target
        target.x = -width;

        // Remove the previous message
        queueGameObjectToRemove(getGameObject("ResetMouseMessage"));
    }

    /**
     * This method is automatically called whenever the test finalisation
     * phase has just started and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateFinalisationStarted() {
        double centerX = this.width / 2.0;
        double centerY = this.height / 2.0;

        queueGameObjectToRemove(getGameObject("SightReturnPoint"));

        if (rankedTest) {
            // If this is a ranked test, then determine the rank shot accuracy
            // shot time and display appropriate text depending on if the test 
            // has been passed.                        
            Profile.Rank rank = playerProfile.getSnapShotRank() == Profile.Rank.Rank6 
                    ? Profile.Rank.Rank6 : playerProfile.getNextSnapShotRank();
            String rankString = "Rank " + rank.toString().substring(4, 5);

            buildButton("Return", "Return", centerX + 50.0, centerY + 150.0);

            if (playerProfile.considerSnapShotTestForRank(
                    rank, (int) averageShotTime, averageTargetAccuracy)) {
                buildNonInteractiveGraphicalObject("SuccessBorder", centerX, centerY);
                buildMessage("Average shot accuracy: " + 
                        (int) (averageTargetAccuracy*100.0) + "%", centerX + 50.0, centerY - 15.0);
                buildMessage("Average shot time: " + 
                        (int) averageShotTime + "ms", centerX + 50.0, centerY + 25.0);
                buildMessage(rankString + " obtained.", centerX + 50, centerY + 65.0);
                assetManager.retrieveSoundAssetArchetype("Success").play();
            } else {
                buildNonInteractiveGraphicalObject("FailureBorder", centerX, centerY);
                buildMessage("Average shot accuracy: " + 
                        (int) (averageTargetAccuracy*100.0) + "%", centerX + 50.0, centerY - 35.0);
                buildMessage("Average shot time: " + 
                        (int) averageShotTime + "ms", centerX + 50.0, centerY + 5.0);
                buildMessage(rankString + " requires an average accuracy", 
                        centerX + 50.0, centerY + 45.0);
                buildMessage("of " + Profile.getSnapShotTargetAccuracyForRank(rank) + 
                        "% with a shot time of " + Profile.getAverageSnapShotTimeForRank(rank) + 
                        "ms", centerX + 50.0, centerY + 85.0);
                assetManager.retrieveSoundAssetArchetype("Failure").play();
            }
        } else {
            // If this is not a ranked test, then just display the average accuracy and shot time
            buildMessage("Average shot accuracy: " + 
                    (int) (averageTargetAccuracy*100.0) + "%", centerX, centerY);
            buildMessage("Average shot time: " + 
                    (int) averageShotTime + "%", centerX, centerY + 45.0);
            buildButton("Return", "Return", centerX, centerY + 110.0);
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

    /**
     * Update the snap shot measurements based upon the current shot information
     */
    private void updateSnapShotMeasurements() {
        // Update the average mouse movement reaction time
        averageMouseMoveTime = 0;
        for (int idx = 0; idx <= currentTest; idx++)
            averageMouseMoveTime += mouseMoveTimes[idx];
        averageMouseMoveTime /= (currentTest + 1);

        ((TextElement) getGameObject( "MouseMoveTime" )).
                setText("Move: " + mouseMoveTimes[currentTest] + "ms (Av." + 
                averageMouseMoveTime + ")");

        // Update the average shot time
        averageShotTime = 0;
        for (int idx = 0; idx <= currentTest; idx++)
            averageShotTime += shotTimes[idx][0];
        averageShotTime /= (currentTest + 1);

        ((TextElement) getGameObject( "ShotTime" )).
                setText("Shoot: " + shotTimes[currentTest][0] + "ms (Av." + 
                averageShotTime + ")");

        // Update the average on target and on bull accuracies
        averageTargetAccuracy = 0;
        averageBullAccuracy = 0;
        for (int idx = 0; idx <= currentTest; idx++) {
            if (shotAccuracies[idx][0] > 0.0) averageTargetAccuracy += 1.0;
            if (shotAccuracies[idx][0] > 2.0) averageBullAccuracy += 1.0;
        }
        averageTargetAccuracy /= (currentTest + 1);
        averageBullAccuracy /= (currentTest + 1);

        ((TextElement) getGameObject( "Accuracy" )).
                setText("Accuracy: " + (int) (averageTargetAccuracy*100.0) + 
                "% (Bull " + (int) (averageBullAccuracy*100.0) + "%)");

        Bar snapShotTimeBar = (Bar) getGameObject( "SnapShotTimeBar" );
        snapShotTimeBar.y = this.height - snapShotTimeBar.height / 2.0;
    }
}