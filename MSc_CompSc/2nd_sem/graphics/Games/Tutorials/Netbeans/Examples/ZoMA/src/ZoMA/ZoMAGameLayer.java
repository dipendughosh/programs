package ZoMA;

import game.engine.*;
import game.geometry.*;
import game.components.*;
import game.assets.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.util.*;

/**
 * ZoMAGameLayer provides the superclass of all tests and provides a 
 * default structure and control mechanism for all tests. A number
 * of blank methods are defined which can be overloaded by extending
 * class to provide task specific actions.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class ZoMAGameLayer extends GameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define a number of draw orders that provide a common reference point
     * when specifying the draw order of the various graphical objects
     */
    protected static final int GUI_BACKGROUND_DRAW_ORDER = 0;
    protected static final int GUI_UNDER_TARGET_DRAW_ORDER = 1;
    protected static final int GUI_TARGET_DRAW_ORDER = 2;
    protected static final int GUI_OVER_TARGET_DRAW_ORDER = 3;
    protected static final int GUI_SIGHT_DRAW_ORDER = 4;

    /**
     * The amount of time needed to move the mouse once the target
     * appears to measured. The number of pixels that the mouse must be
     * moved to trigger this measurement is specified by 
     * THRESHOLD_MOVEMENT_DELTA
     */
    protected static final double THRESHOLD_MOVEMENT_DELTA = 2.0;

    /**
     * AVERAGE_SAMPLING_CORRECTION provides a measure of the average
     * number of ms that each measurement will be out by (and is
     * subtracted from the measurements). The value arises as the 
     * input event sampling is only performed each 16.6ms (for 60UPS),
     * i.e. a mouse click will have occurred somewhere within the
     * last update period, with an average correction of, for 60UPS,
     * 16.6/2ms
     */
    protected static long AVERAGE_SAMPLING_CORRECTION;

    /**
     * Enumerated type and variable holding the form of target that will be
     * used - currently two types of target are supported: a bullseye and
     * a body.
     */
    public enum TargetType { BullsEye, Body }
    protected Target target;

    /**
     * Enumerated type and variable holding the form of sight that will be
     * used - currently only one form of sight is supported by the tests.
     */    
    public enum SightType { Crosshairs }
    protected Sight sight;

    /**
     * Enumerated type and variable holding the test phase, which starts
     * with a single Initialisation phase and then sequences through 
     * the CountDown, ShowTarget and ResetTarget depending upon the 
     * individual form of test, before entering a single Finalisation phase.
     * The phases are used to control the sequencing of the test, with a 
     * number of extendable methods available for individuals forms of 
     * test to introduce test specific behaviour.
     */
    protected enum ShotMode { 
        Initialisation, CountDown, ShowTarget, ResetTarget, Finalisation }
    protected ShotMode shotMode;

    /**
     * Boolean flag indicating if the test is ranked, alongside a link
     * to the player profile that maybe be updated following the test.
     */
    protected boolean rankedTest;
    protected Profile playerProfile;

    /**
     * Variables holding the number of tests to be performed, alongside the 
     * current test number
     */ 
    protected int numberOfTests;
    protected int currentTest;
    
    /**
     * Key boolean variables that are set by extending instances of this 
     * class to signify that the reset target and finalisiation phases 
     * have completed.
     */ 
    protected boolean resetTarget;
    protected boolean finished;
    
    /**
     * Variables specifying the initialisation delay and a minimum and 
     * maximum delay within the CountDown phase before the target is
     * shown
     */
    protected int initialisationDelay;
    protected int countDownMinimumDelay;
    protected int countDownMaximumDelay;

    /**
     * Variables indicating if the test is timed and, if so, the total test
     * duration and current test duration
     */
    protected boolean timedTest;
    protected int testDuration;
    protected int currentDuration;

    /**
     * Variables indicating if the test imposes a shot limit and, if so,
     * the total number of shots permitted, alongside the current fired number
     */
    protected boolean shotLimitPerTest;
    protected int maximumShotsPerTest;
    protected int currentShotsThisTest;

    /**
     * Counters used to target the number of update ticks
     */
    protected long updateCounter;
    protected long updateTarget;

    /**
     * Variables used to define a rectangular region, within which targets
     * are permitted to spawn
     */
    protected double targetSpawnX;
    protected double targetSpawnY;
    protected double targetSpawnWidth;
    protected double targetSpawnHeight;

    /**
     * Variable holding the particular time that the target was shown,
     * alongside the time that the mouse was moved and a shot fired
     */
    protected long targetSpawnTime;
    protected long mouseMoveTime;
    protected long shotTime;

    /**
     * Region of the target that was hit, as reported by the Target instance
     */
    protected double shotAccuracy;

    /**
     * Arrays holding the mouse move times, shot times and shot accuracies
     * across each test
     */
    protected int[] mouseMoveTimes;
    protected int[][] shotTimes;
    protected double[][] shotAccuracies;

    /**
     * Boolean flag indicating if the mouse has been pressed
     */
    protected boolean mousePressed;

    /**
     * Default background colour and a link to the TextElement to be used
     * to build and display GUI messages
     */
    protected Color backgroundColour = new Color(230, 233, 230, 255);
    protected TextElement guiFont;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Construct a new ZoMAGameLayer instance using the specified variables
     */
    public ZoMAGameLayer(GameEngine gameEngine, boolean rankedTest, Profile playerProfile, 
            int numberOfTests, int testDuration, int maximumShotsPerTest) {
        super("ZoMAGameLayer", gameEngine, gameEngine.screenWidth, gameEngine.screenHeight);

        this.rankedTest = rankedTest;
        this.playerProfile = playerProfile;
        this.numberOfTests = numberOfTests;

        if (testDuration > 0) {
            timedTest = true;
            this.testDuration = testDuration;
        }
        
        if (maximumShotsPerTest > 0) {
            shotLimitPerTest = true;
            this.maximumShotsPerTest = maximumShotsPerTest;
        }

        initaliseTestParameters();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Initialisation and Setup                                     //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Initalise the variables used to track/measure the test
     */
    protected void initaliseTestParameters() {
        // Determine the sampling correction based upon the game engine's
        // current half-update period.
        AVERAGE_SAMPLING_CORRECTION 
                = (gameEngine.getGameUpdatePeriod() / 1000000L) / 2L;

        // Initialise instance variables to their starting values
        currentTest = 0; currentDuration = 0; currentShotsThisTest = 0;
        targetSpawnTime = -1; mouseMoveTime = -1; shotTime = -1;
        shotAccuracy = 0.0; updateCounter = 0; initialisationDelay = 150;
        resetTarget = false; finished = false; mousePressed = false;

        // Set the starting mode to Initialisation
        shotMode = ShotMode.Initialisation;

        // Create sufficient storrage to hold statistics on each test
        mouseMoveTimes = new int[numberOfTests];
        shotTimes = new int[numberOfTests][maximumShotsPerTest];
        shotAccuracies = new double[numberOfTests][maximumShotsPerTest];
    }

    /**
     * Define the target to be used within this test
     */    
    protected void defineTarget(TargetType targetType, double targetScaleFactor, 
            String targetMovePattern, int targetMoveChallenge, String targetDisplayRegion) {

        String realisationAssetName = null;
        String targetHitAssetName = null;
        Shape[] hitRegions = null;
        double[] hitRegionWeightings = null;

        switch (targetType) {
            case BullsEye:
                // A BullsEye target defines a geometry consisting of a number of
                // circle, with the inner circles worth more points
                realisationAssetName = "Target";
                targetHitAssetName = "BulletHoles";
                hitRegions = new Shape[]{new Circle(0.0, 0.0, 100.0), 
                    new Circle(0.0, 0.0, 70.0), new Circle(0.0, 0.0, 45.0), 
                    new Circle(0.0, 0.0, 15.0)};
                hitRegionWeightings = new double[]{1.0, 2.0, 3.0, 4.0};
                break;
            case Body:
                // A Body defines a course body geometry with region designated
                // as a head shot
                realisationAssetName = "Body";
                targetHitAssetName = "BulletHoles";
                hitRegions = new Shape[]{new Box(-2, 119, 105, 42), 
                    new Box(-3, -2, 82, 200), new Box(-73, 32, 30, 90), 
                    new Box(68, 33, 35, 86), new Box(1, -55, 117, 90), 
                    new Box(-1, -119, 44, 37)};
                hitRegionWeightings = new double[]{1.0, 1.0, 1.0, 1.0, 1.0, 2.0};
                break;
        }

        // Create the target and defined its realisation, geometry and draw
        // scale factor
        target = new Target(this, realisationAssetName, hitRegions, hitRegionWeightings);
        target.setName("Target");
        target.setTargetHitImageAsset(targetHitAssetName);
        target.setDrawOrder(GUI_TARGET_DRAW_ORDER);
        target.setTargetSizeScaleFactor(targetScaleFactor);

        // Setup the target's movement pattern
        if (targetMovePattern.equals("Static")) {
            target.defineMovementType(Target.MovementType.Static);
        } else if (targetMovePattern.equals("Horizontal")) {
            target.defineMovementType(Target.MovementType.HorizontalIrregular);
            targetDisplayRegion = "Center";
        } else if (targetMovePattern.equals("Vertical")) {
            target.defineMovementType(Target.MovementType.VerticalIrregular);
            targetDisplayRegion = "Center";
        } else if (targetMovePattern.equals("Circular")) {
            target.defineMovementType(Target.MovementType.CircularRegular);
            targetDisplayRegion = "Center";
        } else if (targetMovePattern.equals("SlightCurved")) {
            target.defineMovementType(Target.MovementType.LinearRandom);
        } else if (targetMovePattern.equals("HeavyCurved")) {
            target.defineMovementType(Target.MovementType.CurvedRandom);
        }

        // Setup the target's display region
        if (targetDisplayRegion.equals("Random")) {
            targetSpawnX = target.width / 2;
            targetSpawnWidth = this.width - target.width;
            targetSpawnY = target.height / 2;
            targetSpawnHeight = this.height - target.height;
        } else if (targetDisplayRegion.equals("Top")) {
            targetSpawnX = target.width / 2;
            targetSpawnWidth = this.width - target.width;
            targetSpawnY = target.height / 2;
            targetSpawnHeight = this.height / 2 - target.height;
        } else if (targetDisplayRegion.equals("Bottom")) {
            targetSpawnX = target.width / 2;
            targetSpawnWidth = this.width - target.width;
            targetSpawnY = this.height / 2 + target.height / 2;
            targetSpawnHeight = this.height / 2 - target.height;
        } else if (targetDisplayRegion.equals("Left")) {
            targetSpawnX = target.width / 2;
            targetSpawnWidth = this.width / 2 - target.width;
            targetSpawnY = target.height / 2;
            targetSpawnHeight = this.height - target.height;
        } else if (targetDisplayRegion.equals("Right")) {
            targetSpawnX = this.width / 2 + target.width / 2;
            targetSpawnWidth = this.width / 2 - target.width;
            targetSpawnY = target.height / 2;
            targetSpawnHeight = this.height - target.height;
        } else if (targetDisplayRegion.equals("Center")) {
            targetSpawnX = this.width / 2;
            targetSpawnWidth = 0;
            targetSpawnY = this.height / 2;
            targetSpawnHeight = 0;
        }
        
        // Define the target’s movement challenge
        target.defineDifficultyLevel(targetMoveChallenge);

       // Add the object, initially positioned off the screen
        target.x = -width;
        target.y = -height;
        addGameObject(target);
    }

    /**
     * Define the sight to be used within this test
     */        
    protected void defineSight(SightType sightType, 
            double sightSensitivity, double sightWobbleFactor, double sightRecoilFactor) {

        sight = new Sight(this, "Sight");
        sight.setSightSensitivity(sightSensitivity);
        sight.setSightWobbleFactor(sightWobbleFactor);
        sight.setSightRecoilFactor(sightRecoilFactor);
        sight.centerSight();

        sight.setDrawOrder(GUI_SIGHT_DRAW_ORDER);
        addGameObject(sight);
    }

    /**
     * Setup the initial GUI - which comprises of the 'Get' 'Ready' message
     * that is displayed during test initialisation
     */        
    protected void setupGUI() {
        GameObject get = new GameObject(this);
        get.setName("StartMessageGet");
        get.setRealisationAndGeometry("StartMessageGet");
        get.x = -get.width / 2.0;
        get.y = this.height / 2 - get.height / 2.0 - 170;
        addGameObject(get);

        GameObject ready = new GameObject(this);
        ready.setName("StartMessageReady");
        ready.setRealisationAndGeometry("StartMessageReady");
        ready.x = -ready.width / 2.0;
        ready.y = this.height / 2 - ready.height / 2.0 - 30;
        addGameObject(ready);

        // Create a new TextElement containing the GUI font to be used
        // to create textual messages, etc.
        guiFont = new game.components.TextElement(this, 
                (ImageAssetSequence) assetManager.retrieveAsset( "GUIFontSmall" ), 
                0, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890!\"%*()-+=[]:,.? ", "");

        // Remove the mouse cursor (the defined Sight instance will provide
        // mouse support
        gameEngine.setMouseCursor(null, 0, 0);
    }

    /**
     * Helper method that can be called by an extending class to place a
     * specified textual message at a specified location
     */        
    protected void buildMessage(String message, double x, double y) {
        TextElement textElement = guiFont.getMatchingElement(message);
        textElement.setPosition(x, y);
        textElement.setDrawOrder(GUI_OVER_TARGET_DRAW_ORDER);

        queueGameObjectToAdd(textElement);
    }

    /**
     * Helper method that can be called by an extending class to place a
     * specified, named, textual message at a specified location
     */        
    protected void buildMessage(String messageObjectName, String message, 
            double x, double y) {
        TextElement textElement = guiFont.getMatchingElement(message);
        textElement.setName(messageObjectName);
        textElement.setPosition(x, y);
        textElement.setDrawOrder(GUI_OVER_TARGET_DRAW_ORDER);

        queueGameObjectToAdd(textElement);
    }

    /**
     * Helper method that can be called by an extending class to place a
     * clickable button, constructed using the specified asset base
     * name, at the specified location
     */        
    protected void buildButton(String objectName, String assetBaseName, 
            double x, double y) {
        Button button = new Button(this, objectName, assetBaseName, 
                assetBaseName + "Mouseover", assetBaseName + "Clicked", 
                "Mouseover", "Click", x, y, GUI_OVER_TARGET_DRAW_ORDER);
        queueGameObjectToAdd(button);
    }

    /**
     * Helper method that can be called by an extending class to place a
     * basic graphical image at the specified location
     */        
    protected void buildNonInteractiveGraphicalObject(String assetName, 
            double x, double y) {
        GameObject gameObject 
                = new GameObject(this, x, y, GUI_UNDER_TARGET_DRAW_ORDER);
        gameObject.setRealisationAndGeometry(assetName);
        queueGameObjectToAdd(gameObject);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update                                                       //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Update the test based upon the current test phase
     */
    @Override
    public void update() {
        switch (shotMode) {
            case Initialisation: initialisation(); break;
            case CountDown: updateCountDown(); break;
            case ShowTarget: updateShowTarget(); break;
            case ResetTarget: updateResetTarget(); break;
            case Finalisation: finalisation(); break;
        }

        super.update();
        updateCounter++;
    }

    /**
     * Initialisation update
     */
    private void initialisation() {
        // If the initialisation has just started, then play a get ready sound
        if (updateCounter == 0)
            assetManager.retrieveSoundAssetArchetype("GetReady").play();

        /**
         * Animate the 'Get' and 'Ready' messages, which fly in from the of the
         * screen, pause in the middle of the screen, and then fly out to the 
         * right of the screen
         */
        
        GameObject get = getGameObject("StartMessageGet");
        GameObject ready = getGameObject("StartMessageReady");
        
        double overShoot = 100.0;
        if (updateCounter < initialisationDelay * 0.10) {
            get.x = (width / 2.0 + overShoot) * updateCounter / (initialisationDelay * 0.10);
        } else if (updateCounter < initialisationDelay * 0.15) {
            get.x = width / 2.0 + overShoot * (1.0 - (updateCounter - 
                    initialisationDelay * 0.10) / (initialisationDelay * 0.05));
        } else if (updateCounter > initialisationDelay * 0.80 
                && updateCounter < initialisationDelay * 0.90) {
            get.x = width / 2.0 + (width / 2.0 + get.width) * (updateCounter - 
                    initialisationDelay * 0.80) / (initialisationDelay * 0.10);
        } else if (updateCounter > initialisationDelay * 0.90) {
            get.x = -width;
        }
        
        if (updateCounter > initialisationDelay * 0.05 
                && updateCounter < initialisationDelay * 0.15) {
            ready.x = (width / 2.0 + overShoot) * (updateCounter - 
                    initialisationDelay * 0.05) / (initialisationDelay * 0.1);
        } else if (updateCounter > initialisationDelay * 0.15 
                && updateCounter < initialisationDelay * 0.2) {
            ready.x = width / 2.0 + overShoot * (1.0 - (updateCounter - 
                    initialisationDelay * 0.15) / (initialisationDelay * 0.05));
        } else if (updateCounter > initialisationDelay * 0.9) {
            ready.x = width / 2.0 + (width / 2.0 + ready.width) * (updateCounter - 
                    initialisationDelay * 0.9) / (initialisationDelay * 0.1);
        }

        // If the initialisation phase has finished, then get ready to go onto
        // the first CountDown phase and call the initialisationFinished method        
        if (updateCounter == initialisationDelay) {
            updateCounter = -1;
            shotMode = ShotMode.CountDown;
            inputEvent.resetInputEvents();
            initialisationFinished();
        }
    }

    /**
     * Count down update
     */
    private void updateCountDown() {
        // If the count down has just started, then determine the count down 
        // duration and call the updateCountDownStarted method
        if (updateCounter == 0) {
            updateTarget = countDownMinimumDelay + 
                    ((countDownMaximumDelay - countDownMinimumDelay > 0) ? 
                        (new Random()).nextInt(countDownMaximumDelay - countDownMinimumDelay) : 0);
            updateCountDownStarted();
        }

        updateCountDownInProgress();

        // If the count down has just finished, then get ready to go onto the 
        // show target phase and call the updateCountDownFinished method.
        // Note: the sight is also centered and any queued input events removed
        if (updateCounter >= updateTarget) {
            updateCounter = -1;
            shotMode = ShotMode.ShowTarget;
            sight.centerSight();
            updateCountDownFinished();
            inputEvent.resetInputEvents();
        }
    }

    /**
     * Show target update
     */
    private void updateShowTarget() {
        // If the show target phase has just started, then workout the spawn point
        // for the target and call the updateShowTargetStarted method
        if (updateCounter == 0) {
            target.x = targetSpawnX + Math.random() * targetSpawnWidth;
            target.y = targetSpawnY + Math.random() * targetSpawnHeight;
            target.setBaseXandY(target.x, target.y);

            targetSpawnTime = System.nanoTime();
            mouseMoveTime = -1L;
            shotTime = -1L;
            updateShowTargetStarted();
        }

        // Update the target and the sight 
        target.update();
        sight.update();

        currentDuration++;

        // If the mouse has just moved following the display of the target
        // then record the time and call updateShowTargetMouseMoved
        if (mouseMoveTime == -1L && (Math.abs(sight.getDeltaX()) 
                    > THRESHOLD_MOVEMENT_DELTA 
                || Math.abs(sight.getDeltaY()) > THRESHOLD_MOVEMENT_DELTA)) {
            mouseMoveTime = System.nanoTime();
            updateShowTargetMouseMoved();
        }

        if (shotLimitPerTest) {
            if (!mousePressed && inputEvent.mouseButton1Pressed) {
                // Record the time of the shot
                mousePressed = true;
                shotTime = System.nanoTime();

                // Store the mouse move, shot time and shot accuracy for the test
                mouseMoveTimes[currentTest] = (int) (
                        (mouseMoveTime-targetSpawnTime)/1000000L - AVERAGE_SAMPLING_CORRECTION);
                if (mouseMoveTimes[currentTest] < 0) mouseMoveTimes[currentTest] = 0;
                shotAccuracy = 0.0;
                if (target.getBoundingRectangle().contains(sight.x, sight.y))
                    shotAccuracy = target.considerTargetHit(
                            sight.x - target.x, sight.y - target.y);
                shotTimes[currentTest][currentShotsThisTest] = 
                        (int) ((shotTime-targetSpawnTime)/1000000L - AVERAGE_SAMPLING_CORRECTION);
                shotAccuracies[currentTest][currentShotsThisTest] = shotAccuracy;

                updateShowTargetMousePressed();
                
                currentShotsThisTest++;
            } else if (mousePressed && !inputEvent.mouseButton1Pressed) {
                mousePressed = false;
            }
        }

        updateShowTargetInProgress();

        // If the end condition on the individual test has been reached,
        // then go onto the reset target phase and call updateShowTargetFinished
        if ((timedTest && currentDuration >= testDuration) 
                || (shotLimitPerTest && currentShotsThisTest >= maximumShotsPerTest)) {
            updateCounter = -1;
            shotMode = ShotMode.ResetTarget;
            updateShowTargetFinished();
            inputEvent.resetInputEvents();
        }
    }

    /**
     * Reset target update
     */
    private void updateResetTarget() {
        // If the reset target phase has just started, then call 
        // updateResetTargetStarted and reset the termination flag
        if (updateCounter == 0) {
            resetTarget = false;
            updateResetTargetStarted();
        }

        updateResetTargetInProgress();

        // If the termination flag has been set (assuming that the overloaded
        // updateResetTargetInProgress will do so in a test specified manner)
        // then if more test remain, go back to the count down phase, else
        // enter into the finalistion phase. In all cases, updateResetTargetFinished
        // is called
        if (resetTarget) {
            updateCounter = -1;
            updateResetTargetFinished();

            currentTest++;
            currentShotsThisTest = 0;
            if (currentTest >= numberOfTests) {
                shotMode = ShotMode.Finalisation;
            } else {
                shotMode = ShotMode.CountDown;
            }
            inputEvent.resetInputEvents();
        }
    }

    /**
     * Finalisation update
     */
    private void finalisation() {
        // If the finalisation phase has only just begun, then remove the
        // sight and turn the mouse pointer back on. updateFinalisationStarted
        // is also called
        if (updateCounter == 0) {
            sight.x = -width;
            gameEngine.setMouseCursor("MenuCursor", 0, 0);

            updateFinalisationStarted();
        }

        updateFinalisationInProgress();

        // If the termination flag has been set (assuming that the overloaded
        // updateFinalisationInProgress will do so in a test specified manner)
        // then go back to the menu layer and remove this game layer
        if (finished) {
            GameLayer zomaMenu = gameEngine.getGameLayer("ZoMAMenuLayer");

            zomaMenu.setActivity(GameLayerActivity.ACTIVE);
            zomaMenu.setVisibility(gameLayerVisibility.VISIBLE);

            gameEngine.removeGameLayer(this.gameLayerName);
        }
    }

    /**
     * This method is automatically called whenever the initialisation phase
     * has finished and is intended to provide test specific actions.
     */ 
    protected void initialisationFinished() {
    }

    /**
     * This method is automatically called whenever the count down phase has
     * just started and is intended to provide test specific actions.
     */ 
    protected void updateCountDownStarted() {
    }

    /**
     * This method is automatically and repeatedly called once the count
     * down phase is in progress and is intended to provide test specific 
     * actions.
     */ 
    protected void updateCountDownInProgress() {
    }

    /**
     * This method is automatically called whenever the count down phase 
     * has just completed and is intended to provide test specific actions.
     */ 
    protected void updateCountDownFinished() {
    }

    /**
     * This method is automatically called whenever the target has
     * just been shown and is intended to provide test specific actions.
     */ 
    protected void updateShowTargetStarted() {
    }

    /**
     * This method is automatically called whenever the mouse is moved during
     * the show target phase and is intended to provide test specific actions.
     */ 
    protected void updateShowTargetMouseMoved() {
    }

    /**
     * This method is automatically called whenever the LMB is pressed during
     * the show target phase and is intended to provide test specific actions.
     */ 
    protected void updateShowTargetMousePressed() {
    }

    /**
     * This method is automatically called whenever the show target 
     * phase is in progress and is intended to provide test specific actions.
     */ 
    protected void updateShowTargetInProgress() {
    }

    /**
     * This method is automatically called whenever the show target phase
     * has just finished and is intended to provide test specific actions.
     */ 
    protected void updateShowTargetFinished() {
    }

    /**
     * This method is automatically called whenever the reset target phase
     * has started and is intended to provide test specific actions.
     */ 
    protected void updateResetTargetStarted() {
    }

    /**
     * This method is automatically called whenever the reset target phase
     * is in progress and is intended to provide test specific actions.
     */ 
    protected void updateResetTargetInProgress() {
    }

    /**
     * This method is automatically called whenever the reset target phase
     * has been finished and is intended to provide test specific actions.
     */ 
    protected void updateResetTargetFinished() {
    }

    /**
     * This method is automatically called whenever the test finalisation
     * phase has just started and is intended to provide test specific actions.
     */ 
    protected void updateFinalisationStarted() {
    }

    /**
     * This method is automatically called whenever the test finalisation
     * phase is in progress  and is intended to provide test specific actions.
     */ 
    protected void updateFinalisationInProgress() {
    }

    /**
     * Fill the screen to the specified background colour and then draw
     * all game objects
     */
    @Override
    public void draw(Graphics2D graphics2D) {
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(backgroundColour);
        graphics2D.fillRect(0, 0, gameEngine.screenWidth, gameEngine.screenHeight);
        graphics2D.setColor(originalColour);
        graphics2D.setColor(originalColour);

        super.draw(graphics2D);
    }
}
