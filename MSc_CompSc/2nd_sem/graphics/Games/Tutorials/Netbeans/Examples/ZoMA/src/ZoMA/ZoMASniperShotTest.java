package ZoMA;

import game.engine.*;
import game.components.*;
import java.util.*;

/**
 * SniperShotTest is one of the four current tests supported within the ZoMA 
 * game. It displays a target on the screen and records the accuracy of a 
 * specified number of shots (in terms of on target and on head).
 * <P>
 * Note: this class extends ZoMAGameLayer which provides most of the timing
 * and control logic
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.1 $ $Date: 2007/08 $
 */

public class ZoMASniperShotTest extends ZoMAGameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Minimum count down delay for the reaction test
     */
    private static final int SNIPERSHOT_TEST_MINIMUM_DELAY = 60;

    /**
     * Maximum count down delay for the reaction test
     */
    private static final int SNIPERSHOT_TEST_MAXIMUM_DELAY = 60;

    /**
     * Average on target and on head accuracies
     */
    private double averageTargetAccuracy;
    private double averageHeadAccuracy;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Setup a new reaction test based on the specified parameters
     */ 
    public ZoMASniperShotTest(GameEngine gameEngine, boolean rankedTest, 
            Profile playerProfile, int targetHitPoints, double sightSpeedFactor, 
            double sightWobbleFactor, double targetScaleFactor, 
            String targetMovePattern, int targetMoveChallenge) {
        super(gameEngine, rankedTest, playerProfile, 1, 0, targetHitPoints);

        countDownMinimumDelay = SNIPERSHOT_TEST_MINIMUM_DELAY;
        countDownMaximumDelay = SNIPERSHOT_TEST_MAXIMUM_DELAY;

        defineTarget(TargetType.Body, targetScaleFactor, targetMovePattern, 
                targetMoveChallenge, "Random");

        if (rankedTest) {
            int rank = playerProfile.getSniperShotRank() == Profile.Rank.Rank6 ? 6 : 
                Integer.parseInt(playerProfile.getNextSniperShotRank().toString().substring(4, 5));
            defineSight(SightType.Crosshairs, sightSpeedFactor, 0.5 * rank, 40.0 * rank);
        } else {
            defineSight(SightType.Crosshairs, sightSpeedFactor, sightWobbleFactor, 150.0);
        }

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

        buildMessage( "ShotNumber", "", width/7.0, 25.0 );
        buildMessage( "Accuracy", "", width/2.0, 25.0 );        

        buildMessage( "EllapsedTime", "", width-width/7.0, 25.0 );        

        Bar sniperShotTimeBar = new Bar(
                this, "SniperShotTimeBar", "TimeBarBorder", "ShotTimeBar", 2500);
        sniperShotTimeBar.setPoints(0);
        sniperShotTimeBar.setInnerAssetOffset(-4.0, -4.0);
        sniperShotTimeBar.x = this.width / 2.0;
        sniperShotTimeBar.y = -height;
        sniperShotTimeBar.setDrawOrder(GUI_UNDER_TARGET_DRAW_ORDER);
        addGameObject(sniperShotTimeBar);
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
        // Update the number of shot remaining        
        ((TextElement) getGameObject( "ShotNumber" )).
                setText("Shots remaining: " + (maximumShotsPerTest - currentShotsThisTest));

        // Update and time elapsed and position the sniper shot time bar        
        ((TextElement) getGameObject( "EllapsedTime" )).setText("Time: 0s");
        Bar sniperShotTimeBar = (Bar) getGameObject( "SniperShotTimeBar" );
        sniperShotTimeBar.y = this.height - sniperShotTimeBar.height / 2.0;
    }

    /**
     * This method is automatically called whenever the target has
     * just been shown and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetStarted() {
        // Reset the sniper shot time bar to zero ms        
        Bar sniperShotTimeBar = (Bar) getGameObject( "SniperShotTimeBar" );
        sniperShotTimeBar.setPoints(0);

        // Play a target appear sound        
        assetManager.retrieveSoundAssetArchetype("Appear").play();
    }

    /**
     * This method is automatically called whenever the show target 
     * phase is in progress and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetInProgress() {
        // Determine how much time has ellapsed since the target
        // was shown and update the time ellapsed field and the 
        // sniper shot bar
        int timeEllapsed = (int) ((System.nanoTime()-targetSpawnTime)/1000000L);
        ((TextElement) getGameObject( "EllapsedTime" )).setText("Time: " + (timeEllapsed / 1000) + "s");

        Bar sniperShotTimeBar = (Bar) getGameObject( "SniperShotTimeBar" );
        if (timeEllapsed > 0) {
            if (timeEllapsed < sniperShotTimeBar.getMaximumPoints()) {
                sniperShotTimeBar.setPoints(timeEllapsed);
            } else {
                sniperShotTimeBar.setPoints(sniperShotTimeBar.getMaximumPoints());
            }
        }
    }

    /**
     * This method is automatically called whenever the LMB is pressed during
     * the show target phase and is intended to provide test specific actions.
     */ 
    @Override    
    protected void updateShowTargetMousePressed() {
        // Update the number of shot reamining 
        ((TextElement) getGameObject( "ShotNumber" )).setText(
                "Shots remaining: " + (maximumShotsPerTest - currentShotsThisTest - 1));
        ((Bar) getGameObject( "SniperShotTimeBar" )).setPoints(0);

        // Update the sniper shot measurements
        targetSpawnTime = System.nanoTime();
        updateSniperShotMeasurements();

        // If needed update the profile statistics
        if (rankedTest) {
            playerProfile.recordSniperShot(
                    playerProfile.getSniperShotRank() == Profile.Rank.Rank6 ? 
                        Profile.Rank.Rank6 : playerProfile.getNextSniperShotRank(), 
                        (int) shotAccuracies[currentTest][currentShotsThisTest]);
        }

        // Play a suitable shot sound effect and a hit sound effect if needed
        assetManager.retrieveSoundAssetArchetype("Shot").play();
        if (shotAccuracies[currentTest][currentShotsThisTest] > 0.0) {
            assetManager.retrieveSoundAssetArchetype("Hit").play();
        }
        
        // Recoil the sight
        sight.recoilSight();
    }

    /**
     * This method is automatically called whenever the reset target phase
     * is in progress and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateResetTargetInProgress() {
        // Each sniper shot test automatically proceeds onto the
        // next shot, i.e. simply set the rest target completed
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

        if (rankedTest) {
            // If this is a ranked test, then determine the rank average body
            // and head shot accuracies and display appropriate text depending 
            // on if the test has been passed.                        
            Profile.Rank rank = playerProfile.getSniperShotRank() == Profile.Rank.Rank6 ? 
                Profile.Rank.Rank6 : playerProfile.getNextSniperShotRank();
            String rankString = "Rank " + rank.toString().substring(4, 5);

            buildButton("Return", "Return", centerX + 50.0, centerY + 150.0);

            if (playerProfile.considerSniperShotTestForRank(
                    rank, averageTargetAccuracy, averageHeadAccuracy)) {
                buildNonInteractiveGraphicalObject("SuccessBorder", centerX, centerY);
                buildMessage("Average body shot accuracy: " + 
                        (int) (averageTargetAccuracy*100.0) + "%", centerX + 50.0, centerY - 15.0);
                buildMessage("Average head shot accuracy: " + 
                        (int) (averageHeadAccuracy*100.0) + "%", centerX + 50.0, centerY + 25.0);
                buildMessage(rankString + " obtained.", centerX + 50, centerY + 65.0);
                assetManager.retrieveSoundAssetArchetype("Success").play();
            } else {
                buildNonInteractiveGraphicalObject("FailureBorder", centerX, centerY);
                buildMessage("Average body shot accuracy: " + 
                        (int) (averageTargetAccuracy*100.0) + "%", centerX + 50.0, centerY - 35.0);
                buildMessage("Average head shot accuracy: " + 
                        (int) (averageHeadAccuracy*100.0) + "%", centerX + 50.0, centerY + 5.0);
                buildMessage(rankString + " requires an average body accuracy", 
                        centerX + 50.0, centerY + 45.0);
                buildMessage("of " + Profile.getBodyShotsAccuracyForRank(rank) + 
                        "% with a head shot accuracy of " + 
                        Profile.getHeadShotsAccuracyForRank(rank) + "%", 
                        centerX + 50.0, centerY + 85.0);
                assetManager.retrieveSoundAssetArchetype("Failure").play();
            }
        } else {
            buildMessage("Average body shot accuracy: " + 
                    (int) (averageTargetAccuracy*100.0) + "%", centerX, centerY);
            buildMessage("Average head shot accuracy: " + 
                    (int) (averageHeadAccuracy*100.0) + "%", centerX, centerY + 45.0);
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
     * Update the sniper shot measurements based upon the current shot information
     */
    private void updateSniperShotMeasurements() {
        averageTargetAccuracy = 0.0;
        averageHeadAccuracy = 0.0;

        // Update the on target and on head accuracies
        for (int idx = 0; idx < currentShotsThisTest + 1; idx++) {
            if (shotAccuracies[0][idx] > 0.0) averageTargetAccuracy += 1.0;
            if (shotAccuracies[0][idx] > 1.0) averageHeadAccuracy += 1.0;
        }

        averageTargetAccuracy /= (currentShotsThisTest + 1);
        averageHeadAccuracy /= (currentShotsThisTest + 1);

        ((TextElement) getGameObject( "Accuracy" )).
                setText("Accuracy: " + (int) (averageTargetAccuracy*100.0) + 
                "% (Head " + (int) (averageHeadAccuracy*100.0) + "%)");
    }
}