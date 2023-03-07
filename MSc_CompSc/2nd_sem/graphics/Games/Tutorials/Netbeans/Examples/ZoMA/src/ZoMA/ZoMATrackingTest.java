package ZoMA;

import game.engine.*;
import game.components.*;

/**
 * TracingTest is one of the four current tests supported within the ZoMA game.
 * It displays a target on the screen and measures the ability of the user to
 * keep the sight on the target, which will be moving around the screen.
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

public class ZoMATrackingTest extends ZoMAGameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Minimum count down delay for the reaction test
     */
    private static final int TRACKING_TEST_MINIMUM_DELAY = 180;

    /**
     * Maximum count down delay for the reaction test
     */
    private static final int TRACKING_TEST_MAXIMUM_DELAY = 180;

    /**
     * Count of the total number of update ticks that have passed,
     * alongside counts of the number of ticks on bull, on target
     * and off target.
     */    
    private long totalTicks = 0;
    private long onTargetTicks = 0;
    private long onBullTicks = 0;
    private long offTargetTicks = 0;

    /**
     * Pixel offset that corresponds to the 100% and 0% points on the 
     * graphical scale image
     */
    private static final double SCALE_TOP_OFFSET = -385.0;
    private static final double SCALE_BOTTOM_OFFSET = 410.0;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Setup a new tracking test based on the specified parameters
     */ 
    public ZoMATrackingTest(GameEngine gameEngine, boolean rankedTest, 
            Profile playerProfile, int testDuration, double sightSpeedFactor, 
            double targetScaleFactor, String targetMovePattern, 
            int targetMoveChallenge) {
        super(gameEngine, rankedTest, playerProfile, 1, testDuration * 
                (int) (1.0/(gameEngine.getGameUpdatePeriod()/1000000000.0)), 0);

        countDownMinimumDelay = TRACKING_TEST_MINIMUM_DELAY;
        countDownMaximumDelay = TRACKING_TEST_MAXIMUM_DELAY;

        defineTarget(TargetType.BullsEye, 
                targetScaleFactor, targetMovePattern, targetMoveChallenge, "Center");

        if (rankedTest) {
            int rank = playerProfile.getTrackingRank() == Profile.Rank.Rank6 ? 
                6 : Integer.parseInt(
                    playerProfile.getNextTrackingRank().toString().substring(4, 5));
            defineSight(SightType.Crosshairs, sightSpeedFactor, rank >= 3 ? 
                0.75 * (rank - 2) : 0.0, 0.0);
        } else {
            defineSight(SightType.Crosshairs, sightSpeedFactor, 0.0, 0.0);
        }

        setupGUI();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Setup                                                        //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Setup GUI components for a reaction test
     */ 
    protected void setupGUI() {
        super.setupGUI();

        buildMessage("TrackingSecondsRemaining", "", width / 2.0, 25.0);

        GameObject trackingPercentageBar = new GameObject(this, 0.0, height / 2.0);
        trackingPercentageBar.setRealisationAndGeometry("TrackingPercentageBar");
        trackingPercentageBar.setName("TrackingPercentageBar");
        trackingPercentageBar.x = -width;
        trackingPercentageBar.setDrawOrder(GUI_BACKGROUND_DRAW_ORDER);
        addGameObject(trackingPercentageBar);

        GameObject trackingOnTargetPointer 
                = new GameObject(this, 0.0, height / 2.0 + SCALE_TOP_OFFSET);
        trackingOnTargetPointer.setRealisationAndGeometry("TrackingOnTargetPointer");
        trackingOnTargetPointer.setName("TrackingOnTargetPointer");
        trackingOnTargetPointer.x = -width;
        trackingOnTargetPointer.setDrawOrder(GUI_UNDER_TARGET_DRAW_ORDER);
        addGameObject(trackingOnTargetPointer);

        GameObject trackingOffTargetPointer 
                = new GameObject(this, 0.0, height / 2.0 + SCALE_BOTTOM_OFFSET);
        trackingOffTargetPointer.setRealisationAndGeometry("TrackingOffTargetPointer");
        trackingOffTargetPointer.setName("TrackingOffTargetPointer");
        trackingOffTargetPointer.x = -width;
        trackingOffTargetPointer.setDrawOrder(GUI_UNDER_TARGET_DRAW_ORDER);
        addGameObject(trackingOffTargetPointer);

        GameObject trackingOnBullPointer 
                = new GameObject(this, 0.0, height / 2.0 + SCALE_TOP_OFFSET);
        trackingOnBullPointer.setRealisationAndGeometry("TrackingOnBullPointer");
        trackingOnBullPointer.setName("TrackingOnBullPointer");
        trackingOnBullPointer.x = -width;
        trackingOnBullPointer.setDrawOrder(GUI_UNDER_TARGET_DRAW_ORDER);
        addGameObject(trackingOnBullPointer);
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
        // Update the number of seconds remaining
        ((TextElement) getGameObject( "TrackingSecondsRemaining" )).
                setText("Seconds remaining [" + (int) ((testDuration+1-currentDuration)
                    *(gameEngine.getGameUpdatePeriod()/1000000000.0)) + "]");

        // Update the tracking bar and tracking bar pointer
        GameObject trackingPercentageBar = getGameObject("TrackingPercentageBar");
        trackingPercentageBar.x = this.width - trackingPercentageBar.width / 2;

        GameObject trackingOnTargetPointer = getGameObject("TrackingOnTargetPointer");
        trackingOnTargetPointer.x = 
                trackingPercentageBar.x - trackingOnTargetPointer.width / 2 - 10.0;

        GameObject trackingOffTargetPointer = getGameObject("TrackingOffTargetPointer");
        trackingOffTargetPointer.x = 
                trackingPercentageBar.x - trackingOffTargetPointer.width / 2 - 10.0;

        GameObject trackingOnBullPointer = getGameObject("TrackingOnBullPointer");
        trackingOnBullPointer.x = 
                trackingPercentageBar.x - trackingOnBullPointer.width / 2 - 10.0;

        // Position the target on the center of the screen
        target.x = width / 2.0;
        target.y = height / 2.0;
    }

    /**
     * This method is automatically called whenever the target has
     * just been shown and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetStarted() {
        // Play a target appear sound and start the ticking sound
        assetManager.retrieveSoundAssetArchetype("Appear").play();
        assetManager.retrieveSoundAssetArchetype("Ticking").play();
    }

    /**
     * This method is automatically called whenever the show target 
     * phase is in progress and is intended to provide test specific actions.
     */ 
    @Override    
    protected void updateShowTargetInProgress() {
        // Update the number of seconds remaining
        ((TextElement) getGameObject( "TrackingSecondsRemaining" )).
                setText("Seconds remaining [" + (int) ((testDuration-currentDuration)
                    *(gameEngine.getGameUpdatePeriod()/1000000000.0)) + "]");

        // Update the on bull, on target and off target counters
        totalTicks++;        
        if( target.getBoundingRectangle().contains( sight.x, sight.y) ) {
            double position = target.testTargetHit( sight.x-target.x, sight.y-target.y );
            if( position == 0.0 )
                offTargetTicks++;
            else {
                onTargetTicks++;
                if( position > 2.0 )
                    onBullTicks++;
            }
        } else offTargetTicks++;
        
        // Update the pointer graphicas        
        GameObject trackingOnTargetPointer = getGameObject( "TrackingOnTargetPointer" );
        trackingOnTargetPointer.y = (height/2.0+SCALE_BOTTOM_OFFSET) +
                (SCALE_TOP_OFFSET-SCALE_BOTTOM_OFFSET)*((double)onTargetTicks/(double)totalTicks);
        
        GameObject trackingOffTargetPointer = getGameObject( "TrackingOffTargetPointer" );
        trackingOffTargetPointer.y = (height/2.0+SCALE_BOTTOM_OFFSET) +
                (SCALE_TOP_OFFSET-SCALE_BOTTOM_OFFSET)*((double)offTargetTicks/(double)totalTicks);

        GameObject trackingOnBullPointer = getGameObject( "TrackingOnBullPointer" );
        trackingOnBullPointer.y = (height/2.0+SCALE_BOTTOM_OFFSET) +
                (SCALE_TOP_OFFSET-SCALE_BOTTOM_OFFSET)*((double)onBullTicks/(double)totalTicks);        
    }

    /**
     * This method is automatically called whenever the show target 
     * phase has just completed and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateShowTargetFinished() {
        // Play a gong sound and stop the ticking sound
        assetManager.retrieveSoundAssetArchetype("Ticking").stop();
        assetManager.retrieveSoundAssetArchetype("Gong").play();
    }

    /**
     * This method is automatically called whenever the reset target phase
     * is in progress and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateResetTargetInProgress() {
        // No reset target operation is needed, i.e., immediatelly go on
        resetTarget = true;
    }

    /**
     * This method is automatically called whenever the test finalisation
     * phase has just started and is intended to provide test specific actions.
     */ 
    @Override
    protected void updateFinalisationStarted() {
        // If this is a ranked test, then update the player profile
        if (rankedTest) {
            int tickToMs = (int) (gameEngine.getGameUpdatePeriod()/1000000L);
            playerProfile.recordTrackingTest(
                    playerProfile.getTrackingRank() == Profile.Rank.Rank6 ? 
                        Profile.Rank.Rank6 : playerProfile.getNextTrackingRank(), 
                        (int) ((onTargetTicks+offTargetTicks)*tickToMs), 
                        (int) (onTargetTicks*tickToMs), (int) (onBullTicks*tickToMs));
        }

        // Move the target off the screen
        target.x = -width; target.y = -height;
        
        
        double centerX = this.width / 2.0;
        double centerY = this.height / 2.0;

        if (rankedTest) {
            // If this is a ranked test, then determine and display the average 
            // on bull, on target and off target percentages.
            Profile.Rank rank = playerProfile.getTrackingRank() == Profile.Rank.Rank6 ? 
                Profile.Rank.Rank6 : playerProfile.getNextTrackingRank();
            String rankString = "Rank " + rank.toString().substring(4, 5);

            buildButton("Return", "Return", centerX + 50.0, centerY + 150.0);

            if (playerProfile.considerTrackingTestForRank(rank, 
                    (double) onTargetTicks / (double) (onTargetTicks+offTargetTicks), 
                    (double) onBullTicks / (double) (onTargetTicks+offTargetTicks))) {
                buildNonInteractiveGraphicalObject("SuccessBorder", centerX, centerY);
                buildMessage("Average target accuracy: " + (int) (100.0*onTargetTicks
                        /(double)(onTargetTicks+offTargetTicks)) + "%", 
                            centerX + 50.0, centerY - 15.0);
                buildMessage("Average bull accuracy: " + (int) (100.0*onBullTicks
                        /(double)(onTargetTicks+offTargetTicks)) + "%", 
                            centerX + 50.0, centerY + 25.0);
                buildMessage(rankString + " obtained.", centerX + 50, centerY + 65.0);
                assetManager.retrieveSoundAssetArchetype("Success").play();
            } else {
                buildNonInteractiveGraphicalObject("FailureBorder", centerX, centerY);
                buildMessage("Average target accuracy: " + (int) (100.0*onTargetTicks
                        /(double)(onTargetTicks+offTargetTicks)) + "%", 
                            centerX + 50.0, centerY - 35.0);
                buildMessage("Average bull accuracy: " + (int) (100.0*onBullTicks
                        /(double)(onTargetTicks+offTargetTicks)) + "%", 
                            centerX + 50.0, centerY + 5.0);
                buildMessage(rankString + " requires a target accuracy", 
                        centerX + 50.0, centerY + 45.0);
                buildMessage("of " + Profile.getTargetTrackingAccuracyForRank(rank) + 
                        "% with a bull accuracy of " + 
                        Profile.getBullTrackingAccuracyForRank(rank) + "%", 
                        centerX + 50.0, centerY + 85.0);
                assetManager.retrieveSoundAssetArchetype("Failure").play();
            }
        } else {
            buildMessage("Average target accuracy: " + (int) (100.0*onTargetTicks
                        /(double)(onTargetTicks+offTargetTicks)) + "%", centerX, centerY);
            buildMessage("Average bull accuracy: " + (int) (100.0*onBullTicks
                        /(double)(onTargetTicks+offTargetTicks)) + "%", centerX, centerY + 45.0);
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
}