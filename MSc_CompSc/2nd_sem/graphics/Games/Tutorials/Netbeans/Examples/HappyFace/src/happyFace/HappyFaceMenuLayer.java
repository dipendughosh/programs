package happyFace;

import game.engine.*;
import game.components.*;
import game.assets.*;
import happyFace.levels.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.Rectangle;
import java.awt.DisplayMode;
import java.awt.image.BufferedImage;
import java.awt.Composite;
import java.awt.AlphaComposite;
import java.awt.geom.*;
import java.awt.event.*;
import java.util.*;
import java.io.*;
import java.net.*;

/**
 * HappyFaceMenuLayer provides the main menu for the HappyFace game, enabling
 * the player to change keys and resolution or play levels.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class HappyFaceMenuLayer extends GameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
     
    /**
     * Enumerated type and associated variables holding the available and 
     * current menu pages
     */
    private enum MenuPage { Main, SetupPage1, SetupPage2, Acknowledgements, Game }
    private MenuPage menuPage = MenuPage.Main;

    /**
     * Common text elements that will be used to create small, medium or large
     * text messages
     */
    private TextElement guiFontLarge;
    private TextElement guiFont;
    private TextElement guiFontSmall;

    /**
     * Image reference and associated animation parameters that will be
     * used to animate the menu background
     */
    private BufferedImage rotatedBackground;
    private double rotatedBackgroundX;
    private double rotatedBackgroundY;
    private double rotatedBackgroundRotation;
    private double rotatedBackgroundScale;

    /**
     * Variables used to record key stroke change
     */
    private boolean recordKeyStroke = false;
    private String textElementName;

    /**
     * Variables used to hold information on the available game levels
     * that can be selected from within the menu. A reference to each 
     * layer is maintained alongside variables indicating if the level
     * is unlocked or has an associated award.
     */
    private static final int NUM_GAME_LEVELS = 6;
    private HappyFaceLevelLayer[] levels = new HappyFaceLevelLayer[NUM_GAME_LEVELS];
    private boolean[] levelLocks = new boolean[NUM_GAME_LEVELS];
    private int[] levelAwards = new int[NUM_GAME_LEVELS];
    private int selectedLevelIdx = 0;    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
        
    /**
     * Create a new HappyFace menu
     */
    public HappyFaceMenuLayer(GameEngine gameEngine) {
        super("HappyFaceMenuLayer", 
                gameEngine, gameEngine.screenWidth, gameEngine.screenHeight);

        gameEngine.setMouseCursor("MousePointer", 15, 15);

        // Add in key game object collections that will be used to 
        // hold interactive buttons and text alongside non-interactive elements
        addGameObjectCollection("InteractiveButtons");
        addGameObjectCollection("NonIteractive");
        addGameObjectCollection("InteractiveText");

        // Build common menu items and the current menu
        buildKeyMenuItems();
        buildCurrentMenu();

        // Load in details of the available levels that can be played
        loadLevelDetails();
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Layer states and load/save                                   //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Whenever control is passed back to the menu from the game layer then
     * save the level details (e.g. saving a new level completion, etc.)
     * and build the current menu
     */
    @Override
    protected void enterActiveState() {
        super.enterActiveState();
        saveLevelDetails();
        buildCurrentMenu();
    }

    /**
     * Whenever the menu layer is made visible then ensure the menu mouse 
     * pointer is displayed
     */
    @Override
    protected void enterVisibleState() {
        super.enterInvisibleState();
        gameEngine.setMouseCursor("MousePointer", 15, 15);
    }

    /**
     * Whenever the menu layer is made invisible then ensure the menu mouse 
     * pointer is removed
     */
    @Override
    protected void enterInvisibleState() {
        super.enterInvisibleState();
        gameEngine.setNullMouseCursor();
    }

    /**
     * Create the various levels available within the game and load in 
     * details if the are unlocked for play and if they have associated awards
     */
    private void loadLevelDetails() {

        levels[0] = new Tutorial(gameEngine);
        levels[1] = new TheLongClimb(gameEngine);
        levels[2] = new JailBreak(gameEngine);
        levels[3] = new BootCamp(gameEngine);
        levels[4] = new FortressOfIce(gameEngine);
        levels[5] = new Heaven(gameEngine);

        try {
            BufferedReader inputFile = new BufferedReader(
                    new FileReader("Levels.txt"));

            for (int idx = 0; idx < NUM_GAME_LEVELS; idx++) {
                StringTokenizer tokenizer = new StringTokenizer(inputFile.readLine());
                levelLocks[idx] = new Boolean(tokenizer.nextToken());
                levels[idx].setLevelHighScore(Integer.parseInt(tokenizer.nextToken()));
                levelAwards[idx] = new Integer(tokenizer.nextToken());
            }

            inputFile.close();
        } catch (IOException ioException) {
            System.err.println("HappyFaceMenuLayer: Creating new level file.");
            
            for (int idx = 0; idx < NUM_GAME_LEVELS; idx++) {
                levelLocks[idx] = idx < 3 ? true : false;
                levels[idx].setLevelHighScore(0);
                levelAwards[idx] = new Integer(0);
            }
        }
    }

    /**
     * Save details of level completion and associated awards 
     */    
    private void saveLevelDetails() {
        try {
            BufferedWriter outputFile = new BufferedWriter(
                    new FileWriter(new File( "Levels.txt")));            

            for (int idx = 0; idx < NUM_GAME_LEVELS; idx++) {
                // Update variables based on the level variables, i.e. the player
                // might have played the level since the last save point and
                // update score or awards, etc.
                if (levels[idx].getLevelAward() > levelAwards[idx]) {
                    levelAwards[idx] = levels[idx].getLevelAward();
                }
                
                // Also unlock the next level if necessary
                if (idx < NUM_GAME_LEVELS - 1 && levels[idx].getLevelCompleted()) {
                    levelLocks[idx + 1] = true;
                }

                outputFile.write("" + levelLocks[idx] + " " + 
                        levels[idx].getLevelHighScore() + " " + levelAwards[idx] + "\n");
            }

            outputFile.close();
        } catch (IOException ioException) {
            System.err.println("HappyFaceMenuLayer: Error writing to file: " 
                    + ioException.toString());
            ioException.printStackTrace();
        }
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Menu builders                                                //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Build menu items common to all menus
     */    
    private void buildKeyMenuItems() {
        // Create the menu background
        GameObject menuBackground = new GameObject(this, 
                gameEngine.screenWidth / 2, gameEngine.screenHeight / 2, 0);
        menuBackground.setName("HappyFaceMenuBackground");
        menuBackground.setRealisation( "HappyFaceMenuBackground" );
        queueGameObjectToAdd(menuBackground);

        // Setup the rotating background
        double offsetX = 370 ,offsetY = 220;
        rotatedBackground = assetManager.retrieveGraphicalAsset(
                "HappyFaceRotatedBackground").getImageRealisation();
        rotatedBackgroundX = gameEngine.screenWidth / 2.0 + offsetX;
        rotatedBackgroundY = gameEngine.screenHeight / 2.0 + offsetY;
        rotatedBackgroundRotation = 0.0;
        rotatedBackgroundScale = 1.6 * 
                Math.max(((double) gameEngine.screenWidth + offsetX) 
                        / (double) rotatedBackground.getWidth(), 
                    ((double) gameEngine.screenHeight + offsetY) 
                        / (double) rotatedBackground.getHeight());

        // Create text elements to be used to build textual messages
        guiFontLarge = new game.components.TextElement(this, 
                (ImageAssetSequence) assetManager.retrieveAsset( "GUIFontLarge" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"*$%^&*()-+={}[];:'@#~,.<>/\\?           ", "");

        guiFont = new game.components.TextElement(this, 
                (ImageAssetSequence) assetManager.retrieveAsset( "GUIFont" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"*$%^&*()-+={}[];:'@#~,.<>/\\?           ", "");

        guiFontSmall = new game.components.TextElement(this, 
                (ImageAssetSequence) assetManager.retrieveAsset( "GUIFontSmall" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"*$%^&*()-+={}[];:'@#~,.<>/\\?           ", "");
    }

    /**
     * Build the current menu
     */
    private void buildCurrentMenu() {

        // Remove all components from the previous menu
        GameObjectCollection interactiveButtons = 
                getGameObjectCollection("InteractiveButtons");
        for (int idx = 0; idx < interactiveButtons.size; idx++) 
            queueGameObjectToRemove(interactiveButtons.gameObjects[idx]);

        GameObjectCollection nonIteractive = 
                getGameObjectCollection("NonIteractive");
        for (int idx = 0; idx < nonIteractive.size; idx++)
            queueGameObjectToRemove(nonIteractive.gameObjects[idx]);

        GameObjectCollection interactiveText = 
                getGameObjectCollection("InteractiveText");
        for (int idx = 0; idx < interactiveText.size; idx++)
            queueGameObjectToRemove(interactiveText.gameObjects[idx]);

        // Build the current menu
        switch (menuPage) {
            case Main: buildMainPage(); break;
            case SetupPage1: buildSetupPage1(); break;
            case SetupPage2: buildSetupPage2(); break;
            case Acknowledgements: buildAcknowledgementsPage(); break;
            case Game: buildGamePage(); break;
        }
    }

    /**
     * Build the main menu page
     */
    private void buildMainPage() {
        // Add the HappyFace title graphic
        GameObject happyFaceTitle = new GameObject(this, 
                gameEngine.screenWidth / 2 - 85, gameEngine.screenHeight / 2 - 235, 1);
        happyFaceTitle.setRealisation( "HappyFaceTitle" );
        queueGameObjectToAdd(happyFaceTitle, "NonIteractive");

        // Add a play button
        Button playButton = new Button(this, "PlayButton", 
                "PlayButton", "PlayButtonMouseover", "PlayButtonClicked", 
                "MouseRollover", "MouseClick", 
                gameEngine.screenWidth / 2 + 50, gameEngine.screenHeight / 2 + 80, 1);
        queueGameObjectToAdd(playButton, "InteractiveButtons");

        // Add a setup button
        Button setupButton = new Button(this, "SetupButton", 
                "SetupButton", "SetupButtonMouseover", "SetupButtonClicked", 
                "MouseRollover", "MouseClick", 
                gameEngine.screenWidth / 2, gameEngine.screenHeight / 2 + 200, 1);
        queueGameObjectToAdd(setupButton, "InteractiveButtons");

        // Add a quit button
        Button quitButton = new Button(this, "QuitButton", 
                "QuitButton", "QuitButtonMouseover", "QuitButtonClicked", 
                "MouseRollover", "MouseClick", 
                gameEngine.screenWidth / 2 + 50, gameEngine.screenHeight / 2 + 320, 1);
        queueGameObjectToAdd(quitButton, "InteractiveButtons");

        // Add an acknowledgements buton
        Button acknowledgementsButton = new Button(this, "AcknowledgementsButton", 
                "AcknowledgementsButton", "AcknowledgementsButtonMouseover", "AcknowledgementsButtonClicked", 
                "MouseRollover", "MouseClick", 
                gameEngine.screenWidth / 2 - 380, gameEngine.screenHeight / 2 + 355, 1);
        queueGameObjectToAdd(acknowledgementsButton, "InteractiveButtons");
    }

    /**
     * Build the first setup page - enabling keys to be configured
     */
    private void buildSetupPage1() {
        int centerX = gameEngine.screenWidth / 2, centerY = gameEngine.screenHeight / 2;

        // Add a setup title
        GameObject setupTitle = new GameObject(this, centerX - 310, centerY - 280, 1);
        setupTitle.setRealisation(assetManager.retrieveGraphicalAsset("SetupTitle"));
        queueGameObjectToAdd(setupTitle, "NonIteractive");

        // Add in the key configuration background overlay
        GameObject keyConfigBackground = 
                new GameObject(this, centerX + 10, centerY + 30, 2);
        keyConfigBackground.setRealisation( "BackgroundOverlay1" );
        queueGameObjectToAdd(keyConfigBackground, "NonIteractive");

        // Add in text elements outlining the various keys
        constructLargeFontMessage("Key Setup", centerX - 260, centerY - 160, false);

        constructFontMessage("Page 1", centerX + 220, centerY - 170, true);
        constructFontMessage("Page 2", centerX + 380, centerY - 170, true);

        constructFontMessage("Move Left : " +  KeyEvent.getKeyText(EmoticonPlayer.MOVE_LEFT_KEY), centerX - 230, centerY - 90, true);
        constructFontMessage("Move Right : " + KeyEvent.getKeyText(EmoticonPlayer.MOVE_RIGHT_KEY), centerX - 230, centerY - 50, true);
        constructFontMessage("Jump Up : " + KeyEvent.getKeyText(EmoticonPlayer.JUMP_UP_KEY), centerX - 230, centerY - 10, true);
        constructFontMessage("Stop Bounce : " + KeyEvent.getKeyText(EmoticonPlayer.STOP_BOUNCE_KEY), centerX - 230, centerY + 30, true);

        constructFontMessage("Zoom In : " + KeyEvent.getKeyText(HappyFaceLevelLayer.ZOOM_IN_KEY), centerX - 230, centerY + 80, true);
        constructFontMessage("Zoom Out : " + KeyEvent.getKeyText(HappyFaceLevelLayer.ZOOM_OUT_KEY), centerX - 230, centerY + 120, true);

        constructFontMessage("Small Bomb : " + KeyEvent.getKeyText(EmoticonPlayer.SMALL_BOMB_KEY), centerX + 220, centerY - 90, true);
        constructFontMessage("Medium Bomb : " + KeyEvent.getKeyText(EmoticonPlayer.MEDIUM_BOMB_KEY), centerX + 220, centerY - 50, true);
        constructFontMessage("Large Bomb : " + KeyEvent.getKeyText(EmoticonPlayer.LARGE_BOMB_KEY), centerX + 220, centerY - 10, true);

        constructFontMessage("Toggle Music : " + KeyEvent.getKeyText(HappyFaceLevelLayer.TOGGLE_MUSIC), centerX + 220, centerY + 40, true);
        constructFontMessage("Quit to Menu : " + KeyEvent.getKeyText(HappyFaceLevelLayer.QUIT_TO_MENU), centerX + 220, centerY + 80, true);

        constructSmallFontMessage("Note: Scroll using mouse and zoom with mouse wheel", centerX, centerY + 175, false);
        constructSmallFontMessage("CTRL-D toggle debug mode (LMB Teleport - RMB bomb)", centerX, centerY + 205, false);
        constructSmallFontMessage("CTRL-I toggle FPS/UPS", centerX, centerY + 235, false);

        // Add in a back button
        Button backButton = new Button(this, "BackButton", 
                "BackButton", "BackButtonMouseover", "BackButtonClicked", 
                "MouseRollover", "MouseClick", 
                centerX - 360, centerY + 320, 1);
        queueGameObjectToAdd(backButton, "InteractiveButtons");
    }

    /**
     * Build the second setup page - enabling the screen resolution to be changed
     */
    private void buildSetupPage2() {
        int centerX = gameEngine.screenWidth / 2, centerY = gameEngine.screenHeight / 2;

        // Add in the setup title
        GameObject setupTitle = new GameObject(this, centerX - 310, centerY - 280, 1);
        setupTitle.setRealisation(assetManager.retrieveGraphicalAsset("SetupTitle"));
        queueGameObjectToAdd(setupTitle, "NonIteractive");

        // Add in the resolution change background overlay        
        GameObject keyConfigBackground = 
                new GameObject(this, centerX + 10, centerY + 30, 2);
        keyConfigBackground.setRealisation( "BackgroundOverlay1" );
        queueGameObjectToAdd(keyConfigBackground, "NonIteractive");

        // Add in text messages for the title and setup page
        constructLargeFontMessage("Resolution", centerX - 260, centerY - 160, false);

        constructFontMessage("Page 1", centerX + 220, centerY - 170, true);
        constructFontMessage("Page 2", centerX + 380, centerY - 170, true);

        // Add in a text message for each available screen resolution
        double resolutionOffsetX = 0, resolutionOffsetY = 0;
        HashMap<String, String> addedModes = new HashMap<String, String>();
        DisplayMode[] displayModes = gameEngine.getAvailableDisplayModes();
        for (int idx = 0; idx < displayModes.length; idx++) {
            if (displayModes[idx].getWidth() >= 1024 
                    && displayModes[idx].getHeight() >= 768 
                    && displayModes[idx].getBitDepth() == 32) {

                String resolutionName = "" + displayModes[idx].getWidth() 
                        + "x" + displayModes[idx].getHeight();
                if (addedModes.containsKey(resolutionName))
                    continue;

                constructFontMessage(resolutionName, centerX - 260 + 
                        resolutionOffsetX, centerY - 90 + resolutionOffsetY, true);
                addedModes.put(resolutionName, null);

                // If needed, start another column
                resolutionOffsetY += 40.0;
                if (resolutionOffsetY == 200) {
                    resolutionOffsetX += 250.0;
                    resolutionOffsetY = 0.0;
                }
            }
        }

        constructSmallFontMessage("The screen resolutions shown above are available.", 
                centerX, centerY + 175, false);
        constructSmallFontMessage("Click on the desired resolution to change.", 
                centerX, centerY + 205, false);

        // Add in a back button
        Button backButton = new Button(this, "BackButton", 
                "BackButton", "BackButtonMouseover", "BackButtonClicked", 
                "MouseRollover", "MouseClick", 
                centerX - 360, centerY + 320, 1);
        queueGameObjectToAdd(backButton, "InteractiveButtons");
    }

    /**
     * Build the game page menu
     */
    private void buildGamePage() {
        // Add in the title graphic
        GameObject levelTitle = new GameObject(this, 
                gameEngine.screenWidth / 2 - 220, gameEngine.screenHeight / 2 - 280, 1);
        levelTitle.setRealisation( "PlayLevelTitle" );
        queueGameObjectToAdd(levelTitle, "NonIteractive");

        // Add in the level select background overlay
        GameObject levelSelectBackground = new GameObject(this, 
                gameEngine.screenWidth / 2 - 270, gameEngine.screenHeight / 2 + 30, 2);
        levelSelectBackground.setRealisation( "BackgroundOverlay2" );
        queueGameObjectToAdd(levelSelectBackground, "NonIteractive");

        // Add in the level description background overlay
        GameObject levelDescriptionBackground = new GameObject(this, 
                gameEngine.screenWidth / 2 + 200, gameEngine.screenHeight / 2 + 30, 2);
        levelDescriptionBackground.setRealisation( "BackgroundOverlay3" );
        queueGameObjectToAdd(levelDescriptionBackground, "NonIteractive");

        // Add in details of each of the available levels
        constructLargeFontMessage("Level", gameEngine.screenWidth / 2 - 280, 
                gameEngine.screenHeight / 2 - 160, false);
        int offsetY = 0;
        for (int idx = 0; idx < NUM_GAME_LEVELS; idx++) {
            constructFontMessage(levels[idx].getLevelName(), 
                    gameEngine.screenWidth / 2 - 280, 
                    gameEngine.screenHeight / 2 - 100 + offsetY, true);
            offsetY += 40;
        }

        if( levelAwards[NUM_GAME_LEVELS-1] > 0 ) {
            constructFontMessage( "Well done!!!", 
                    gameEngine.screenWidth / 2 - 280, 
                    gameEngine.screenHeight / 2 - 100 + offsetY + 20, true);
        }
        
        // Add in a play button
        Button playButton = new Button(this, "PlayButton", 
                "PlayButton", "PlayButtonMouseover", "PlayButtonClicked", 
                "MouseRollover", "MouseClick", 
                gameEngine.screenWidth / 2 + 10, gameEngine.screenHeight / 2 + 330, 1);
        queueGameObjectToAdd(playButton, "InteractiveButtons");
        
        // Add in a back button
        Button backButton = new Button(this, "BackButton", 
                "BackButton", "BackButtonMouseover", "BackButtonClicked", 
                "MouseRollover", "MouseClick", 
                gameEngine.screenWidth / 2 - 360, gameEngine.screenHeight / 2 + 320, 1);
        queueGameObjectToAdd(backButton, "InteractiveButtons");

        // Build the level overview for the currently selected level
        buildGamePageLevelOverview();
    }

    /**
     * Build a level overview for the currently selected game level
     */
    private void buildGamePageLevelOverview() {
        double offsetX = gameEngine.screenWidth / 2 + 200;
        double offsetY = gameEngine.screenHeight / 2;

        // Define variables to hold the level name, level snapshot and
        // offset display position for the snapshot
        String levelName = null;
        String levelBackgroundAssetName = null;
        double levelBackgroundOffsetX = 0.0;
        double levelBackgroundOffsetY = 0.0;

        switch (selectedLevelIdx) {
            // Setup and provide information on the tutorial level
            case 0:
                levelName = "Tutorial ";
                levelBackgroundAssetName = "TutorialSnapShot";
                levelBackgroundOffsetX = 00.0;
                levelBackgroundOffsetY = 120.0;
                constructSmallFontMessage("Surely you're the sensible type", offsetX - 10.0, offsetY - 100.0, false);
                constructSmallFontMessage("who likes to learn how to play", offsetX - 10.0, offsetY - 70.0, false);
                constructSmallFontMessage("the game, and not one of 'those'", offsetX - 10.0, offsetY - 40.0, false);
                constructSmallFontMessage("types who just jumps in", offsetX - 10.0, offsetY - 10.0, false);
                constructSmallFontMessage("(and then gets confused...)", offsetX - 10.0, offsetY + 20.0, false);
                break;

            // Setup and provide information on The Long Climb level
            case 1:
                levelName = "The Long Climb ";
                levelBackgroundAssetName = "TheLongClimbSnapShot";
                levelBackgroundOffsetX = 70.0;
                levelBackgroundOffsetY = 50.0;
                constructSmallFontMessage("Escape upwards", offsetX - 120.0, offsetY - 100.0, false);
                constructSmallFontMessage("and break free!", offsetX - 120.0, offsetY - 70.0, false);
                constructSmallFontMessage("This is mostly an", offsetX - 120.0, offsetY - 20.0, false);
                constructSmallFontMessage("advanced tutorial", offsetX - 120.0, offsetY + 10.0, false);
                constructSmallFontMessage("level on", offsetX - 120.0, offsetY + 40.0, false);
                constructSmallFontMessage("ball control", offsetX - 120.0, offsetY + 70.0, false);
                break;

            // Setup and provide information on the Jail Break level
            case 2:
                levelName = "Jail Break ";
                levelBackgroundAssetName = "JailBreakSnapShot";
                levelBackgroundOffsetX = 0.0;
                levelBackgroundOffsetY = 0.0;
                constructSmallFontMessage("Rescue the", offsetX - 120.0, offsetY + 30.0, false);
                constructSmallFontMessage("trapped and", offsetX - 120.0, offsetY + 60.0, false);
                constructSmallFontMessage("oppressed", offsetX - 120.0, offsetY + 90.0, false);
                constructSmallFontMessage("emoticons", offsetX - 120.0, offsetY + 120.0, false);
                break;

            // Setup and provide information on the Boot Camp level
            case 3:
                levelName = "Boot Camp ";
                levelBackgroundAssetName = "BootCampSnapShot";
                levelBackgroundOffsetX = 0.0;
                levelBackgroundOffsetY = 50.0;
                constructSmallFontMessage("Annihilate the happy emoticon", offsetX - 0.0, offsetY - 90.0, false);
                constructSmallFontMessage("army to avoid the possibility", offsetX - 0.0, offsetY - 60.0, false);
                constructSmallFontMessage("of reprisal", offsetX - 0.0, offsetY - 30.0, false);
                break;

            // Setup and provide information on the Fortress of Ice level
            case 4:
                levelName = "Fortress of Ice ";
                levelBackgroundAssetName = "FortressOfIceSnapShot";
                levelBackgroundOffsetX = -5.0;
                levelBackgroundOffsetY = 100.0;
                constructSmallFontMessage("Bring the fight to the happy", offsetX - 0.0, offsetY - 100.0, false);
                constructSmallFontMessage("emoticons - gain entry to", offsetX - 0.0, offsetY - 70.0, false);
                constructSmallFontMessage("emoticon heaven past the ", offsetX - 0.0, offsetY - 40.0, false);
                constructSmallFontMessage("Fortess of Ice.", offsetX - 0.0, offsetY - 10.0, false);
                constructSmallFontMessage("You will need the", offsetX + 100.0, offsetY + 120.0, false);
                constructSmallFontMessage("'help' of the cuddly", offsetX + 100.0, offsetY + 150.0, false);
                constructSmallFontMessage("Destroyer emoticon.", offsetX + 100.0, offsetY + 180.0, false);
                break;
                
            case 5:
                levelName = "Heaven ";
                levelBackgroundAssetName = "HeavenSnapShot";
                levelBackgroundOffsetX = 0.0;
                levelBackgroundOffsetY = -20.0;
                constructSmallFontMessage("Emoticon heaven - the biggest", offsetX - 0.0, offsetY + 80.0, false);
                constructSmallFontMessage("ball of joyous fury and sickening", offsetX - 0.0, offsetY + 110.0, false);
                constructSmallFontMessage("happiness gleefully awaits your", offsetX - 0.0, offsetY + 140.0, false);
                constructSmallFontMessage("arrival... don't disappoint.", offsetX - 0.0, offsetY + 170.0, false);
                break;                
                
            // Game completed option    
            case -1:
                levelName = " ";
                levelBackgroundAssetName = "GameCompleted";
                levelBackgroundOffsetX = 10.0;
                levelBackgroundOffsetY = 70.0;

                // Add in medals for each of the levels
                for( int idx = 0; idx < NUM_GAME_LEVELS; idx++) {
                    if( levelAwards[idx] > 0 ) {
                        String medalAssetName = null;
                        switch (levelAwards[idx]) {
                            case 1: medalAssetName = "BronzeMedal"; break;
                            case 2: medalAssetName = "SilverMedal"; break;
                            case 3: medalAssetName = "GoldMedal"; break;
                        }

                        GameObject levelAward = 
                            new GameObject(this,
                                offsetX + 5 + Math.sin(Math.PI/3.2+idx*
                                    (2*Math.PI/(NUM_GAME_LEVELS+2))) * 220.0,
                                offsetY + 60 + Math.cos(Math.PI/3.2+idx*
                                    (2*Math.PI/(NUM_GAME_LEVELS+2))) * 220.0, 4 );
                        levelAward.setRealisation( medalAssetName );
                        queueGameObjectToAdd(levelAward, "NonIteractive");                    
                    }
                }                
                break;                   
        }

        constructLargeFontMessage(levelName, offsetX, offsetY - 160, false);        
        if( selectedLevelIdx != -1 ) {
            constructFontMessage("Highscore: " + levels[selectedLevelIdx].getLevelHighScore(),
                    offsetX, offsetY + 230.0, false);

            // If a level award has been awarded then display it
            if (levelAwards[selectedLevelIdx] > 0) {
                String medalAssetName = null;
                switch (levelAwards[selectedLevelIdx]) {
                    case 1: medalAssetName = "BronzeMedal"; break;
                    case 2: medalAssetName = "SilverMedal"; break;
                    case 3: medalAssetName = "GoldMedal"; break;
                }

                GameObject levelAward = 
                        new GameObject(this, offsetX + 220.0, offsetY - 300.0, 4);
                levelAward.setRealisation( medalAssetName );
                queueGameObjectToAdd(levelAward, "NonIteractive");
            }
        }

        // If a level snapshot has been provided then display it
        if (levelBackgroundAssetName != null) {
            GameObject levelBackground = new GameObject(this, 
                    offsetX + levelBackgroundOffsetX, 
                    offsetY + levelBackgroundOffsetY, 4);
            levelBackground.setRealisation( levelBackgroundAssetName );
            queueGameObjectToAdd(levelBackground, "NonIteractive");
        }
    }

    /**
     * Build the acknowledgements page
     */
    private void buildAcknowledgementsPage() {
        int centerX = gameEngine.screenWidth / 2, centerY = gameEngine.screenHeight / 2;

        // Add an acknowledgement title
        GameObject setupTitle = new GameObject(this, centerX, centerY - 280, 1);
        setupTitle.setRealisation(assetManager.retrieveGraphicalAsset("AcknowledgementsTitle"));
        queueGameObjectToAdd(setupTitle, "NonIteractive");

        // Add in the acknowledgement overlay
        GameObject keyConfigBackground = 
                new GameObject(this, centerX + 10, centerY + 30, 2);
        keyConfigBackground.setRealisation( "BackgroundOverlay1" );
        queueGameObjectToAdd(keyConfigBackground, "NonIteractive");

        constructFontMessage("I am very grateful for the work of", centerX, centerY - 120.0, false);
        constructFontMessage("the artists who created the various pictures", centerX, centerY - 80.0, false);
        constructFontMessage("of emoticons and sound/music used within", centerX, centerY - 40.0, false);
        constructFontMessage("the game. The majority of the artwork was", centerX, centerY - 0.0, false);
        constructFontMessage("taken from deviantART (www.deviantart.com)", centerX, centerY + 40.0, false);
        constructFontMessage("with the MIDI files sourced from", centerX, centerY + 80.0, false);
        constructFontMessage("various locations.", centerX, centerY + 120.0, false);
        
        // Add in a back button
        Button backButton = new Button(this, "BackButton", 
                "BackButton", "BackButtonMouseover", "BackButtonClicked", 
                "MouseRollover", "MouseClick", 
                centerX - 360, centerY + 320, 1);
        queueGameObjectToAdd(backButton, "InteractiveButtons");                
    }

    /**
     * Build a font message at the specified offset. If the message is
     * interactive then it can be clicked by the user
     */
    private void constructFontMessage(
            String message, double x, double y, boolean isInteractive) {
        TextElement textElement = guiFont.getMatchingElement(message);
        textElement.setName(message);
        textElement.setPosition(x, y);
        textElement.setDrawOrder(3);

        if (isInteractive) queueGameObjectToAdd(textElement, "InteractiveText");
        else queueGameObjectToAdd(textElement, "NonIteractive");
    }

    /**
     * Build a large font message at the specified offset. If the message is
     * interactive then it can be clicked by the user
     */
    private void constructLargeFontMessage(
            String message, double x, double y, boolean isInteractive) {
        TextElement textElement = guiFontLarge.getMatchingElement(message);
        textElement.setName(message);
        textElement.setPosition(x, y);
        textElement.setDrawOrder(3);

        if (isInteractive) queueGameObjectToAdd(textElement, "InteractiveText");
        else queueGameObjectToAdd(textElement, "NonIteractive");
    }

    /**
     * Build a small font message at the specified offset. If the message is
     * interactive then it can be clicked by the user
     */
    private void constructSmallFontMessage(
            String message, double x, double y, boolean isInteractive) {
        TextElement textElement = guiFontSmall.getMatchingElement(message);
        textElement.setName(message);
        textElement.setPosition(x, y);
        textElement.setDrawOrder(3);

        if (isInteractive) queueGameObjectToAdd(textElement, "InteractiveText");
        else queueGameObjectToAdd(textElement, "NonIteractive");
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update                                                       //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the menus
     */
    @Override
    public void update() {
        super.update();

        // If changing the key assigned to a particular action then 
        // capture the next key press
        if (recordKeyStroke) {
            if (inputEvent.newKeyTyped()) {
                updateKeyMappings();
            }
        } else {
            // Update all interaction buttons and then call page specific updates            
            GameObjectCollection buttons = getGameObjectCollection("InteractiveButtons");
            for (int idx = 0; idx < buttons.size; idx++)
                buttons.gameObjects[idx].update();

            if (menuPage == MenuPage.Main) {
                updateMainPage();
            } else if (menuPage == MenuPage.SetupPage1) {
                updateSetupPage1();
            } else if (menuPage == MenuPage.SetupPage2) {
                updateSetupPage2();
            } else if (menuPage == MenuPage.Game) {
                updateGamePage();
            } else if (menuPage == MenuPage.Acknowledgements) {
                updateAcknowledgementsPage();
            }
        }
    }

    /**
     * Update the main page
     */
    private void updateMainPage() {
        Button playButton = (Button) getGameObject( "PlayButton" );
        if (playButton.buttonClicked()) {
            menuPage = MenuPage.Game;
            buildCurrentMenu();
        }

        Button setupButton = (Button) getGameObject( "SetupButton" );
        if (setupButton.buttonClicked()) {
            menuPage = MenuPage.SetupPage1;
            buildCurrentMenu();
        }

        Button acknowledgementsButton = (Button) getGameObject( "AcknowledgementsButton" );
        if (acknowledgementsButton.buttonClicked()) {
            menuPage = MenuPage.Acknowledgements;
            buildCurrentMenu();
        }

        Button quitButton = (Button) getGameObject( "QuitButton" );
        if (quitButton.buttonClicked()) {
            gameEngine.terminateProcess();
        }
    }

    /**
     * Update the key change setup page 
     */
    private void updateSetupPage1() {
        // Return to the main menu if requested
        Button backButton = (Button) getGameObject( "BackButton" );
        if (backButton.buttonClicked()) {
            menuPage = MenuPage.Main;
            buildCurrentMenu();
        }

        // Test each of the interactive text elements to determine if the
        // user has clicked on one
        if (inputEvent.mouseClicked(MouseEvent.BUTTON1)) {
            int[] clickLocation = inputEvent.getMouseClickLocation();

            GameObjectCollection textElements = 
                    getGameObjectCollection("InteractiveText");
            for (int idx = 0; idx < textElements.size; idx++) {
                Rectangle screenBound = 
                        getGameObjectScreenRectangle(textElements.gameObjects[idx]);
                if (screenBound.x < clickLocation[0] 
                        && screenBound.y < clickLocation[1] 
                        && screenBound.x + screenBound.width > clickLocation[0] 
                        && screenBound.y + screenBound.height - 10 > clickLocation[1]) {

                    // If the clicked page element is one of the setup pages,
                    // then change to the clicked setup page
                    if (textElements.gameObjects[idx].getName().indexOf("Page") != -1) {
                        if (textElements.gameObjects[idx].getName().charAt(5) == '2') {
                            menuPage = MenuPage.SetupPage2;
                            buildCurrentMenu();
                        }
                    } else {
                        // Change into record key stroke mode and clear any
                        // pending input events
                        recordKeyStroke = true;
                        textElementName = textElements.gameObjects[idx].getName();
                        inputEvent.resetInputEvents();
                    }
                }
            }
        }
    }

    /**
     * Update the resolution change setup page
     */
    private void updateSetupPage2() {
        // Return to the main menu if requested
        Button backButton = (Button) getGameObject( "BackButton" );
        if (backButton.buttonClicked()) {
            menuPage = MenuPage.Main;
            buildCurrentMenu();
        }

        // Test each of the interactive text elements to determine if the
        // user has clicked on one        
        if (inputEvent.mouseClicked(MouseEvent.BUTTON1)) {
            int[] clickLocation = inputEvent.getMouseClickLocation();

            GameObjectCollection textElements = 
                    getGameObjectCollection("InteractiveText");
            for (int idx = 0; idx < textElements.size; idx++) {
                Rectangle screenBound = 
                        getGameObjectScreenRectangle(textElements.gameObjects[idx]);
                if (screenBound.x < clickLocation[0] 
                        && screenBound.y < clickLocation[1] 
                        && screenBound.x + screenBound.width > clickLocation[0] 
                        && screenBound.y + screenBound.height - 10 > clickLocation[1]) {

                    // If the clicked page element is one of the setup pages,
                    // then change to the clicked setup page
                    if (textElements.gameObjects[idx].getName().indexOf("Page") != -1) {
                        if (textElements.gameObjects[idx].getName().charAt(5) == '1') {
                            menuPage = MenuPage.SetupPage1;
                            buildCurrentMenu();
                        }
                    } else {
                        // Extract details of the screen resolution that was 
                        // clicked and change to that resolution
                        StringTokenizer tokenizer = 
                                new StringTokenizer(textElements.gameObjects[idx].getName(), " x");
                        int screenWidth = Integer.parseInt(tokenizer.nextToken());
                        int screenHeight = Integer.parseInt(tokenizer.nextToken());
                        gameEngine.changeDisplayMode(screenWidth, screenHeight, 32);

                        // Following the resolution change reposition background elements
                        getGameObject("HappyFaceMenuBackground").setPosition(
                                screenWidth / 2, screenHeight / 2);
                        
                        double offsetX = 370, offsetY = 220;
                        rotatedBackgroundX = screenWidth / 2.0 + offsetX;
                        rotatedBackgroundY = screenHeight / 2.0 + offsetY;
                        rotatedBackgroundScale = 1.6 * 
                                Math.max(((double) screenWidth + offsetX) 
                                        / (double) rotatedBackground.getWidth(), 
                                    ((double) screenHeight + offsetY) 
                                        / (double) rotatedBackground.getHeight());
                        
                        // Rebuild the menu
                        buildCurrentMenu();

                        // Also inform each loaded level layer of the resolution change
                        for (int levelIdx = 0; levelIdx < levels.length; levelIdx++) {
                            this.levels[levelIdx].viewPortWidth = gameEngine.screenWidth;
                            this.levels[levelIdx].viewPortHeight = gameEngine.screenHeight;
                            this.levels[levelIdx].viewPortScreenX = gameEngine.screenWidth / 2;
                            this.levels[levelIdx].viewPortScreenY = gameEngine.screenHeight / 2;
                        }

                        // If a layer GUI has already been added, then reconfigure
                        // the layout for the new resolution
                        if (gameEngine.gameLayers.containsKey("LevelLayerGUI")) {
                            ((HappyFaceLevelLayerGUI) gameEngine.getGameLayer( 
                                    "LevelLayerGUI" )).reconfigureLevelLayerGUI();
                        }
                    }
                }
            }
        }
    }

    /**
     * Update key mappings following a key press
     */
    private void updateKeyMappings() {
        GameObjectCollection textElements 
                = getGameObjectCollection("InteractiveText");
        for (int idx = 0; idx < textElements.size; idx++) {
            if (textElements.gameObjects[idx].getName().compareTo(textElementName) == 0) {
                // Based on the clicked text element, update with its new
                // keyb binding
                int newKeyID = inputEvent.getNewKeyTyped();
                String newElementName = "";
                if (textElementName.startsWith("Move Left")) {
                    newElementName = "Move Left : ";
                    EmoticonPlayer.MOVE_LEFT_KEY = newKeyID;
                } else if (textElementName.startsWith("Move Right")) {
                    newElementName = "Move Right : ";
                    EmoticonPlayer.MOVE_RIGHT_KEY = newKeyID;
                } else if (textElementName.startsWith("Jump Up")) {
                    newElementName = "Jump Up : ";
                    EmoticonPlayer.JUMP_UP_KEY = newKeyID;
                } else if (textElementName.startsWith("Stop Bounce")) {
                    newElementName = "Stop Bounce : ";
                    EmoticonPlayer.STOP_BOUNCE_KEY = newKeyID;
                } else if (textElementName.startsWith("Small Bomb")) {
                    newElementName = "Small Bomb : ";
                    EmoticonPlayer.SMALL_BOMB_KEY = newKeyID;
                } else if (textElementName.startsWith("Medium Bomb")) {
                    newElementName = "Medium Bomb : ";
                    EmoticonPlayer.MEDIUM_BOMB_KEY = newKeyID;
                } else if (textElementName.startsWith("Large Bomb")) {
                    newElementName = "Large Bomb : ";
                    EmoticonPlayer.LARGE_BOMB_KEY = newKeyID;
                } else if (textElementName.startsWith("Zoom In")) {
                    newElementName = "Zoom In : ";
                    HappyFaceLevelLayer.ZOOM_IN_KEY = newKeyID;
                } else if (textElementName.startsWith("Zoom Out")) {
                    newElementName = "Zoom Out : ";
                    HappyFaceLevelLayer.ZOOM_OUT_KEY = newKeyID;
                } else if (textElementName.startsWith("Toggle Music")) {
                    newElementName = "Toggle Music : ";
                    HappyFaceLevelLayer.TOGGLE_MUSIC = newKeyID;
                } else if (textElementName.startsWith("Quit to Menu")) {
                    newElementName = "Quit to Menu : ";
                    HappyFaceLevelLayer.QUIT_TO_MENU = newKeyID;
                }

                // Update the text element to reflect the new associated key 
                newElementName = newElementName + KeyEvent.getKeyText(newKeyID);
                constructFontMessage(newElementName, textElements.gameObjects[idx].x, 
                        textElements.gameObjects[idx].y, true);
                queueGameObjectToRemove(textElements.gameObjects[idx]);
            }
        }
        recordKeyStroke = false;
    }

    /**
     * Update the game page
     */
    private void updateGamePage() {
        // Go back to the main menu if requested
        Button backButton = (Button) getGameObject( "BackButton" );
        if (backButton.buttonClicked()) {
            menuPage = MenuPage.Main;
            buildCurrentMenu();
        }

        // Play the currently selected level if the play button is clicked
        Button playButton = (Button) getGameObject( "PlayButton" );
        if (selectedLevelIdx != -1 && playButton.buttonClicked()) {
            // Make the selected level visible and active, setup the layer
            // and add it to the game engine
            levels[selectedLevelIdx].setVisibility(GameLayer.GameLayerVisibility.VISIBLE);
            levels[selectedLevelIdx].setActivity(GameLayer.GameLayerActivity.ACTIVE);
            levels[selectedLevelIdx].setupLevel();
            gameEngine.addGameLayer(levels[selectedLevelIdx]);

            // Make the menu invisible and inactive
            this.setVisibility(HappyFaceLevelLayer.GameLayerVisibility.INVISIBLE);
            this.setActivity(HappyFaceLevelLayer.GameLayerActivity.INACTIVE);
        }

        // Check if the player has clicked on one of the levels, and if so, 
        // update the menu to display information on the selected level
        if (inputEvent.mouseClicked(MouseEvent.BUTTON1)) {
            int[] clickLocation = inputEvent.getMouseClickLocation();

            GameObjectCollection textElements 
                    = getGameObjectCollection("InteractiveText");
            for (int idx = 0; idx < textElements.size; idx++) {
                Rectangle screenBound = 
                        getGameObjectScreenRectangle(textElements.gameObjects[idx]);
                if (screenBound.x < clickLocation[0] 
                        && screenBound.y < clickLocation[1] 
                        && screenBound.x + screenBound.width > clickLocation[0] 
                        && screenBound.y + screenBound.height - 10 > clickLocation[1]) {
                    for (int levelIdx = 0; levelIdx < NUM_GAME_LEVELS; levelIdx++) {
                        if (levels[levelIdx].getLevelName().compareTo(
                                    textElements.gameObjects[idx].getName()) == 0 
                                && levelLocks[levelIdx] == true) {
                            selectedLevelIdx = levelIdx;
                            buildCurrentMenu();
                        }
                    }

                    // If all levels have been completed, check if the player has 
                    // clicked on the well done button
                    if(textElements.gameObjects[idx].getName().equals("Well done!!!")) {
                        selectedLevelIdx = -1;
                        buildCurrentMenu();                        
                    }
                }
            }
        }
    }


    /**
     * Update the acknowledgements page
     */
    private void updateAcknowledgementsPage() {
        // Return to the main menu if requested
        Button backButton = (Button) getGameObject( "BackButton" );
        if (backButton.buttonClicked()) {
            menuPage = MenuPage.Main;
            buildCurrentMenu();
        }
    }    

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Draw                                                         //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Draw the menu
     */
    @Override
    public void draw(Graphics2D graphics2D) {
        // Draw the rotating background        
        drawBackground(graphics2D);

        super.draw(graphics2D);

        // Provide menu specific highlights
        if (menuPage == menuPage.SetupPage1) {
            drawCustomSetupMenuPage1(graphics2D);
        } else if (menuPage == menuPage.SetupPage2) {
            drawCustomSetupMenuPage2(graphics2D);
        } else if (menuPage == menuPage.Game) {
            drawCustomGameMenuPage(graphics2D);
        }
    }

    /**
     * Draw the rotating background
     */
    private void drawBackground(Graphics2D graphics2D) {        
        rotatedBackgroundRotation += 0.001;

        AffineTransform originalTransform = graphics2D.getTransform();
        Composite originalComposite = graphics2D.getComposite();

        AffineTransform backgroundTransform = new AffineTransform();

        // Setup and draw the first background image
        backgroundTransform.rotate(
                rotatedBackgroundRotation, rotatedBackgroundX, rotatedBackgroundY);
        graphics2D.transform(backgroundTransform);
        graphics2D.setComposite(
                AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 
                (float) Math.abs( Math.sin( (double)gameEngine.updateCounter/360.0 ))));

        graphics2D.drawImage(rotatedBackground, 
                (int) (rotatedBackgroundX-
                    rotatedBackgroundScale*rotatedBackground.getWidth()/2), 
                (int) (rotatedBackgroundY-
                    rotatedBackgroundScale*rotatedBackground.getHeight()/2), 
                (int) (rotatedBackgroundScale*rotatedBackground.getWidth()), 
                (int) (rotatedBackgroundScale*rotatedBackground.getHeight()), null);

        // Setup and draw the second background image
        backgroundTransform.rotate(
                rotatedBackgroundRotation * 0.5, rotatedBackgroundX, rotatedBackgroundY);
        graphics2D.transform(backgroundTransform);
        graphics2D.setComposite(
                AlphaComposite.getInstance(AlphaComposite.SRC_OVER, 
                (float) Math.abs( Math.cos( (double)gameEngine.updateCounter/360.0 ))));

        graphics2D.drawImage(rotatedBackground, 
                (int) (rotatedBackgroundX-
                    rotatedBackgroundScale*rotatedBackground.getWidth()/2), 
                (int) (rotatedBackgroundY-
                    rotatedBackgroundScale*rotatedBackground.getHeight()/2), 
                (int) (rotatedBackgroundScale*rotatedBackground.getWidth()), 
                (int) (rotatedBackgroundScale*rotatedBackground.getHeight()), null);

        graphics2D.setComposite(originalComposite);
        graphics2D.setTransform(originalTransform);
    }

    /**
     * Highlight interactive text elements if needed
     */
    private void drawCustomSetupMenuPage1(Graphics2D graphics2D) {
        GameObjectCollection interactiveText 
                = getGameObjectCollection("InteractiveText");
        for (int idx = 0; idx < interactiveText.size; idx++) {
            Rectangle screenBound = getGameObjectScreenRectangle(
                    interactiveText.gameObjects[idx]);
            if (!recordKeyStroke) {
                if (screenBound.x < inputEvent.mouseXCoordinate 
                        && screenBound.y < inputEvent.mouseYCoordinate 
                        && screenBound.x + screenBound.width > inputEvent.mouseXCoordinate 
                        && screenBound.y + screenBound.height - 10 > inputEvent.mouseYCoordinate) {
                    Color originalColour = graphics2D.getColor();
                    graphics2D.setColor(new Color(255, 255, 255, 100));
                    graphics2D.fillRect(screenBound.x, screenBound.y, 
                            screenBound.width, screenBound.height);
                    graphics2D.setColor(originalColour);
                }
            } else {
                if (interactiveText.gameObjects[idx].getName().
                        compareTo(textElementName) == 0) {
                    Color originalColour = graphics2D.getColor();
                    graphics2D.setColor(new Color(0, 255, 0, 100));
                    graphics2D.fillRect(screenBound.x, screenBound.y, 
                            screenBound.width, screenBound.height);
                    graphics2D.setColor(originalColour);
                }
            }
        }
    }

    /**
     * Highlight interactive text elements if needed
     */
    private void drawCustomSetupMenuPage2(Graphics2D graphics2D) {
        GameObjectCollection interactiveText = 
                getGameObjectCollection("InteractiveText");
        for (int idx = 0; idx < interactiveText.size; idx++) {
            Rectangle screenBound = getGameObjectScreenRectangle(
                    interactiveText.gameObjects[idx]);
            if (screenBound.x < inputEvent.mouseXCoordinate 
                    && screenBound.y < inputEvent.mouseYCoordinate 
                    && screenBound.x + screenBound.width > inputEvent.mouseXCoordinate 
                    && screenBound.y + screenBound.height - 10 > inputEvent.mouseYCoordinate) {
                Color originalColour = graphics2D.getColor();
                graphics2D.setColor(new Color(255, 255, 255, 100));
                graphics2D.fillRect(screenBound.x, screenBound.y, 
                        screenBound.width, screenBound.height);
                graphics2D.setColor(originalColour);
            }
        }
    }

    /**
     * Highlight interactive text elements if needed
     */
    private void drawCustomGameMenuPage(Graphics2D graphics2D) {
        GameObjectCollection interactiveText 
                = getGameObjectCollection("InteractiveText");
        for (int idx = 0; idx < interactiveText.size; idx++) {
            Rectangle screenBound = getGameObjectScreenRectangle(
                    interactiveText.gameObjects[idx]);
            if(selectedLevelIdx == -1) {
                if (interactiveText.gameObjects[idx].getName().equals("Well done!!!")) {
                    Color originalColour = graphics2D.getColor();
                    graphics2D.setColor(new Color(0, 255, 0, 100));
                    graphics2D.fillRect(screenBound.x, screenBound.y, 
                            screenBound.width, screenBound.height);
                    graphics2D.setColor(originalColour);                    
                }
            } else if (interactiveText.gameObjects[idx].getName().
                    compareTo(levels[selectedLevelIdx].getLevelName()) == 0) {
                Color originalColour = graphics2D.getColor();
                graphics2D.setColor(new Color(0, 255, 0, 100));
                graphics2D.fillRect(screenBound.x, screenBound.y, 
                        screenBound.width, screenBound.height);
                graphics2D.setColor(originalColour);
            }

            if (screenBound.x < inputEvent.mouseXCoordinate 
                    && screenBound.y < inputEvent.mouseYCoordinate 
                    && screenBound.x + screenBound.width > inputEvent.mouseXCoordinate 
                    && screenBound.y + screenBound.height - 10 > inputEvent.mouseYCoordinate) {

                boolean clickable = true;
                for (int levelIdx = 0; levelIdx < NUM_GAME_LEVELS; levelIdx++)
                    if (levels[levelIdx].getLevelName().compareTo(
                                interactiveText.gameObjects[idx].getName()) == 0 
                            && levelLocks[levelIdx] == false)
                        clickable = false;

                Color originalColour = graphics2D.getColor();
                if (clickable) {
                    graphics2D.setColor(new Color(255, 255, 255, 100));
                } else {
                    graphics2D.setColor(new Color(255, 0, 0, 100));
                }
                
                graphics2D.fillRect(screenBound.x, screenBound.y, 
                        screenBound.width, screenBound.height);
                graphics2D.setColor(originalColour);
            }
        }
    }
}