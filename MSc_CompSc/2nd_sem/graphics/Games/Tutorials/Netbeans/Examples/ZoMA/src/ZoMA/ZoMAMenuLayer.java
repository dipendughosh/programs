package ZoMA;

import game.engine.*;
import game.components.*;
import game.assets.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.awt.Rectangle;
import java.awt.geom.*;
import java.awt.event.*;
import java.awt.image.BufferedImage;
import java.awt.Composite;
import java.awt.AlphaComposite;

/**
 * ZoMAMenuLayer provides the main menu for the ZoMA game.
 * <P>
 * Note: The logic and code contained within this class is fairly 
 * simple - mostly consisting of specifying how menus are to be built 
 * and updated - however, the code is excessively long and would 
 * likely benefit from being split up into a number of smaller classes.  
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class ZoMAMenuLayer extends GameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Define a number of draw orders that provide a common reference point
     * when specifying the draw order of the various graphical objects
     */    
    private static final int GUI_SUBTEXT_DRAW_ORDER = 1;
    private static final int GUI_TEXT_DRAW_ORDER = 2;
    private static final int GUI_POSTTEXT_DRAW_ORDER = 3;

    /**
     * Enumerated type and variable holding the current top-level menu
     * that is selected
     */    
    private enum Menu { Loader, Main, Profile, Performance, Training, Ranking }
    private Menu currentMenu;

    /**
     * Enumerated type and variable holding the current performance 
     * category that is displayed
     */    
    private enum PerformanceDisplay { None, ReactionTime, SnapShotOverview, 
        SnapShotRegional, Tracking, SniperShot, Awards }
    private PerformanceDisplay performanceDisplay = PerformanceDisplay.ReactionTime;

    /**
     * Enumerated type and variable holding the current training menu
     * category that is displayed
     */    
    private enum TrainingDisplay { None, ReactionTime, SnapShot, Tracking, SniperShot }
    private TrainingDisplay trainingDisplay = TrainingDisplay.ReactionTime;
    
    /**
     * Enumerated type and variable holding the current rank category
     * that is displayed
     */    
    private enum RankDisplay { None, ReactionTime, SnapShot, Tracking, SniperShot }
    private RankDisplay rankDisplay = RankDisplay.ReactionTime;

    /**
     * Variables holding the profile collection, alongside the current profile
     * selected from the within the collection
     */
    private ProfileCollection profileCollection;
    private String selectedProfileName;
    private Profile playerProfile;

    /**
     * Default menu item values for the reaction test
     */
    private int reactionNumberOfTests = 5;
    private double reactionTriggerSizeScale = 1.0;
    private boolean changeScreenColour = true;
    private boolean playSoundOnTargetDisplay = true;

    /**
     * Default menu item values for the snap shot test
     */
    private int snapShotNumberOfTests = 5;
    private double snapShotMouseMovementSpeed = 1.0;
    private double snapShotTargetSize = 1.0;
    private String snapShotTargetRegion = "Random";

    /**
     * Default menu item values for the tracking test
     */
    private int trackingDuration = 30;
    private double trackingMouseMovementSpeed = 1.0;
    private double trackingTargetSize = 1.0;
    private String trackingMovementType = "SlightCurved";
    private int trackingChallenge = 5;

    /**
     * Default menu item values for the sniper shot test
     */
    private int sniperTargetHitPoints = 5;
    private double sniperMouseMovementSpeed = 1.0;
    private double sniperSightWobble = 1.0;
    private double sniperTargetSize = 1.0;
    private String sniperMovementType = "SlightCurved";
    private int sniperChallenge = 5;

    /**
     * Variable used to track if the menu assets have been loaded
     * (this is used on start up)
     */
    private boolean loadMenuAssets = false;

    /**
     * Text element holding a GUI set that can be used to form 
     * textual messages to be displayed on screen
     */
    private TextElement guiFont;

    /**
     * Variables used to track the position and rotation of the 
     * background images
     */
    private BufferedImage rotatedBackground;
    private double rotatedBackgroundX;
    private double rotatedBackgroundY;
    private double rotatedBackgroundRotation;
    private double rotatedBackgroundScale;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new ZoMA menu instance.
     * <P>
     * Note: The ZoMAMenuLayer also acts as a loader layer, i.e. a splash screen
     * will be displayed until the menu assets has been loaded
     */ 
    public ZoMAMenuLayer(GameEngine gameEngine, ProfileCollection profileCollection) {
        super("ZoMAMenuLayer", gameEngine, gameEngine.screenWidth, gameEngine.screenHeight);

        this.profileCollection = profileCollection;

        // Create game object collection that will be used to hold the different
        // types of menu element (the collections are used to provide easy update
        // access).
        addGameObjectCollection("InteractiveElements");
        addGameObjectCollection("NonInteractiveMenuElements");
        addGameObjectCollection("InteractiveTextElements");

        // If the game is running at a resolution lower than 1280x1024 (i.e the
        // minimum resolution needed to display the menu elements) then work
        // out a scaling factor that will display all the menu.
        double drawScaleFactor = Math.min((double) gameEngine.screenWidth / 1280.0, 
                (double) gameEngine.screenHeight / 1024.0);
        if (drawScaleFactor < 1.0) {
            setDrawScaleFactor(drawScaleFactor);
        }

        // Built key menu items
        buildKeyMenuItems();

        // Initially load the assets needed to display all the menus
        currentMenu = Menu.Loader;
        buildCurrentMenu();
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Activity                                                     //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Whenever this layer enters the active state (e.g. through normal test
     * completion or via the user hitting escape during a test), display
     * the default mouse menu cursor and build the currently selected menu
     */
    @Override
    protected void enterActiveState() {
        super.enterActiveState();
        gameEngine.setMouseCursor("MenuCursor", 0, 0);
        buildCurrentMenu();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Menu Construction                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Build graphical components that are used across all layers
     */
    private void buildKeyMenuItems() {
        // Build a TextElement that will be used to create all textual messages
        guiFont =  new game.components.TextElement( this, 
            (ImageAssetSequence)assetManager.retrieveAsset( "GUIFont" ), 0,
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" +
                "1234567890!\"%*()-+=[]:,.? ", "" );       

        // Setup the mouse cursor
        gameEngine.setMouseCursor( "MenuCursor", 0, 0 );

        // Introduce the background that will be rotated
        rotatedBackground = assetManager.retrieveGraphicalAsset( 
                "ZoMABackground" ).getImageRealisation();
        rotatedBackgroundX = gameEngine.screenWidth/2.0;
        rotatedBackgroundY = gameEngine.screenHeight/2.0;
        rotatedBackgroundRotation = 0.0;
        rotatedBackgroundScale = 1.6 * Math.max( 
                ((double)gameEngine.screenWidth) / (double)rotatedBackground.getWidth(),    
                ((double)gameEngine.screenHeight) / (double)rotatedBackground.getHeight() );
    }

    /**
     * Build the current menu
     */
    private void buildCurrentMenu() {
        
         // Before building the menu delete any content associated with the
         // previous menu
        GameObjectCollection interactiveElements 
                = getGameObjectCollection( "InteractiveElements" );
        for( int idx = 0; idx < interactiveElements.size; idx++ )
            queueGameObjectToRemove( interactiveElements.gameObjects[idx] ); 
        
        GameObjectCollection nonInteractiveMenuElements 
                = getGameObjectCollection( "NonInteractiveMenuElements" );
        for( int idx = 0; idx < nonInteractiveMenuElements.size; idx++ )
            queueGameObjectToRemove( nonInteractiveMenuElements.gameObjects[idx] ); 
        
        GameObjectCollection interactiveTextElements 
                = getGameObjectCollection( "InteractiveTextElements" );
        for( int idx = 0; idx < interactiveTextElements.size; idx++ )
            queueGameObjectToRemove( interactiveTextElements.gameObjects[idx] );
                
        // Build the current menu
        switch( currentMenu ) {
            case Loader: buildLoaderMenu(); break;
            case Main: buildMainMenu(); break;
            case Profile: buildProfileMenu(); break;
            case Performance: buildPerformanceMenu(); break;
            case Training: buildTrainingMenu(); break;
            case Ranking: buildRankingMenu(); break;
        }                
    }
    
    /**
     * Build the loader menu
     */    
    private void buildLoaderMenu() {
        double centerX = width/2.0, centerY = height/2.0;
        
        buildNonInteractiveGraphicalObject( "ZoMA", centerX-200, centerY-200, GUI_TEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "ZoMAText", centerX-195, centerY-100, GUI_POSTTEXT_DRAW_ORDER );
        
        buildMessage( "Loading... ", centerX, centerY );
    }

    /**
     * Build the main menu
     */    
    private void buildMainMenu() {
        double centerX = width/2.0, centerY = height/2.0;
        
        // Display the Zoma title 
        buildNonInteractiveGraphicalObject( "ZoMA", centerX-210, centerY-100, GUI_TEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "ZoMAText", centerX-205, centerY-00, GUI_POSTTEXT_DRAW_ORDER );
        
        // Display the main menu border
        buildNonInteractiveGraphicalObject( "MainMenuBorder", centerX+290, centerY-80, GUI_POSTTEXT_DRAW_ORDER );
         
        // Display text requiring the user to select a profile if one has not 
        // been loaded, otherwise display the menu options for the profile.
        if( playerProfile == null ) {
            buildMessage( "Click on the", centerX+300, centerY-180 );
            buildMessage( "Profile button", centerX+300, centerY-140 );
            buildMessage( "to create or ", centerX+300, centerY-100 );
            buildMessage( "load a profile.", centerX+300, centerY-60 );
            buildButton( "Profile", "Profile", centerX+300, centerY+20, GUI_TEXT_DRAW_ORDER );            
        } else {
            buildButton( "Profile", "Profile", centerX+300, centerY-200, GUI_TEXT_DRAW_ORDER );
            buildButton( "Performance", "Performance", centerX+300, centerY-140, GUI_TEXT_DRAW_ORDER );
            buildButton( "Training", "Training", centerX+300, centerY-80, GUI_TEXT_DRAW_ORDER );
            buildButton( "Ranking", "Ranking", centerX+300, centerY-20, GUI_TEXT_DRAW_ORDER );
            buildButton( "Quit", "Quit", centerX+300, centerY+40, GUI_TEXT_DRAW_ORDER );
        }        
    }

     /**
     * Build the main menu
     */    
   private void buildProfileMenu() {
        double centerX = width/2.0, centerY = height/2.0;
        
        // Display the profile menu title and provide a main menu button
        buildNonInteractiveGraphicalObject( "ProfileTitle", centerX-350, centerY-380, GUI_SUBTEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "TitleBar", centerX, centerY-300, GUI_TEXT_DRAW_ORDER );
        buildButton( "MainMenu", "MainMenu", centerX+460, centerY-340, GUI_TEXT_DRAW_ORDER );
        
        // Display the create new profile menu components
        buildNonInteractiveGraphicalObject( "CreateProfileTitle", centerX-350, centerY-200, GUI_TEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "ProfileCreateBox", "ProfileCreateBox", centerX, centerY-170, GUI_SUBTEXT_DRAW_ORDER );
        buildMessage( "Enter name:", centerX+60, centerY-200 );
        buildButton( "Create", "Create", centerX+460, centerY-120, GUI_TEXT_DRAW_ORDER );

        // Introduce a text field for new profile names to be entered
        TextField profileName = new TextField( "ProfileName", this, 
            (ImageAssetSequence)assetManager.retrieveAsset( "GUIFont" ), 0,
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" +
                "1234567890!\"%*()-+=[]:,.? " );       
        profileName.x = centerX+200; profileName.y = centerY-200;
        profileName.setDrawOrder( GUI_POSTTEXT_DRAW_ORDER );
        profileName.setMaximumFieldTextLength( 10 );
        profileName.setCursorWidth( 4 );
        profileName.setKeyClickSound( assetManager.retrieveSoundAssetArchetype( "KeyClick" ) );
        queueGameObjectToAdd( profileName, "InteractiveElements" );
                
        // Display the load existing profile menu components
        buildNonInteractiveGraphicalObject( "LoadProfileTitle", centerX-400, centerY+20, GUI_TEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "ProfileLoadBox", centerX, centerY+200, GUI_SUBTEXT_DRAW_ORDER );
        buildButton( "Load", "Load", centerX-480, centerY+350, GUI_TEXT_DRAW_ORDER );
        buildButton( "Delete", "Delete", centerX-330, centerY+350, GUI_TEXT_DRAW_ORDER );
    
        // Add the name of each profile contained within the profile collection
        double offsetY = 30;
        for( int idx = 0; idx < profileCollection.getNumProfiles(); idx++ ) {         
            String storedProfileName = profileCollection.getProfile(idx).getProfileName();
            buildInteractiveText( storedProfileName, storedProfileName, centerX-50, centerY+offsetY);
            offsetY += 70;
        }
        
        // If a profile has been selected from the list, then display an overview
        // of the ranks associated with that profile
        if( selectedProfileName != null ) {
            Profile selectedProfile = profileCollection.getProfile( selectedProfileName );            
            buildMessage( "Reaction", centerX+230, centerY+30 );            
            buildNonInteractiveGraphicalObject( "Medal"+selectedProfile.getReactionTimeRank()+"Icon", 
                        centerX+230, centerY+120, GUI_TEXT_DRAW_ORDER );                                
            buildMessage( "Snap Shot", centerX+480, centerY+30 );            
            buildNonInteractiveGraphicalObject( "Medal"+selectedProfile.getSnapShotRank()+"Icon", 
                        centerX+480, centerY+120, GUI_TEXT_DRAW_ORDER );                                
            buildMessage( "Tracking", centerX+230, centerY+250 );            
            buildNonInteractiveGraphicalObject( "Medal"+selectedProfile.getTrackingRank()+"Icon", 
                        centerX+230, centerY+340, GUI_TEXT_DRAW_ORDER );                                
            buildMessage( "Sniper Shot", centerX+480, centerY+250 );            
            buildNonInteractiveGraphicalObject( "Medal"+selectedProfile.getSniperShotRank()+"Icon", 
                        centerX+480, centerY+340, GUI_TEXT_DRAW_ORDER );                                                
        }        
    }

     /**
     * Build the performance menu
     */    
    private void buildPerformanceMenu() {
        double centerX = width/2.0;
        double centerY = height/2.0;
        
        // Display the performance menu title and provide a main menu button
        buildNonInteractiveGraphicalObject( "PerformanceTitle", centerX-180, centerY-380, GUI_SUBTEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "TitleBar", centerX, centerY-300, GUI_TEXT_DRAW_ORDER );
        buildButton( "MainMenu", "MainMenu", centerX+460, centerY-340, GUI_TEXT_DRAW_ORDER );
        
        // Display the different performance categories that can be selected
        buildNonInteractiveGraphicalObject( "CategoryTitle", centerX-440, centerY-190, GUI_TEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "MenuBorder", centerX-430, centerY+70, GUI_TEXT_DRAW_ORDER );
        
        buildButton( "ReactionTime", "ReactionTime", centerX-420, centerY-80, GUI_TEXT_DRAW_ORDER );
        buildButton( "SnapShotOverview", "SnapShotOverview", centerX-420, centerY-10, GUI_TEXT_DRAW_ORDER );
        buildButton( "SnapShotRegional", "SnapShotRegional", centerX-420, centerY+60, GUI_TEXT_DRAW_ORDER );
        buildButton( "Tracking", "Tracking", centerX-420, centerY+130, GUI_TEXT_DRAW_ORDER );
        buildButton( "SniperShot", "SniperShot", centerX-420, centerY+200, GUI_TEXT_DRAW_ORDER );
        buildButton( "Awards", "Awards", centerX-420, centerY+270, GUI_TEXT_DRAW_ORDER );  
        
        // Based upon the performance category that is selected, display relevant
        // performance overview statistics
        if( performanceDisplay != PerformanceDisplay.None ) {
            buildNonInteractiveGraphicalObject( "ContentBorder", centerX+205, centerY+65, GUI_SUBTEXT_DRAW_ORDER );  
                        
            switch( performanceDisplay ) {
                case ReactionTime: 
                    // Display an overview of the reaction times grouped into different time periods
                    if( playerProfile.getReactionTimeRank() != Profile.Rank.Unranked )
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getReactionTimeRank()+"Icon", centerX+540, centerY-170, GUI_TEXT_DRAW_ORDER );                                
                    buildNonInteractiveGraphicalObject( "ReactionTimeTitle", centerX+70, centerY-198, GUI_SUBTEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "ReactionTimePyramid", centerX+200, centerY+85, GUI_SUBTEXT_DRAW_ORDER );                    
                    buildMessage( ""+(int)playerProfile.getPercentageReactionTestsSub150ms()+"%", centerX+200, centerY-35 );
                    buildMessage( ""+(int)playerProfile.getPercentageReactionTests150To200ms()+"%", centerX+200, centerY+22 );
                    buildMessage( ""+(int)playerProfile.getPercentageReactionTests200To250ms()+"%", centerX+200, centerY+81 );
                    buildMessage( ""+(int)playerProfile.getPercentageReactionTests250To300ms()+"%", centerX+200, centerY+139 );
                    buildMessage( ""+(int)playerProfile.getPercentageReactionTests300To350ms()+"%", centerX+200, centerY+197 );
                    buildMessage( ""+(int)playerProfile.getPercentageReactionTestsMoreThan350ms()+"%", centerX+200, centerY+260 );                    
                    buildMessage( "Num reaction tests: " + playerProfile.getNumTotalReactionTests(), centerX+200, centerY+350 );
                    break;
                    
                case SnapShotOverview:
                    // Display an overview of the snap shot averages, including target accuracy
                    if( playerProfile.getSnapShotRank() != Profile.Rank.Unranked )
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getSnapShotRank()+"Icon", centerX+540, centerY-170, GUI_TEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "SnapShotOverviewTitle", centerX+145, centerY-192, GUI_SUBTEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "TargetReport", centerX+220, centerY+160, GUI_SUBTEXT_DRAW_ORDER );                    
                    buildMessage( "Av. Reaction Time: " + (int)playerProfile.getAverageReactionTime()+"ms", centerX+200, centerY-120 );
                    buildMessage( "Av. Shot Time: " + (int)playerProfile.getAverageShotTime()+"ms", centerX+200, centerY-75 );
                    buildMessage( "Target hit: " + (int)playerProfile.getTargetHitPercentage()+"%", centerX+200, centerY-30 );
                    buildMessage( "" + (int)playerProfile.getBand1HitPercentage()+"%", centerX+450, centerY+30 );
                    buildMessage( "" + (int)playerProfile.getBand2HitPercentage()+"%", centerX+450, centerY+75 );
                    buildMessage( "" + (int)playerProfile.getBand3HitPercentage()+"%", centerX+450, centerY+120 );
                    buildMessage( "" + (int)playerProfile.getBand4HitPercentage()+"%", centerX+450, centerY+165 );
                    buildMessage( "" + (int)playerProfile.getBandMissPercentage()+"%", centerX+450, centerY+210 );
                    buildMessage( "Num snap shots: " + playerProfile.getTotalSnapShots(), centerX+200, centerY+350 );
                    break;
                    
                case SnapShotRegional:
                    // Display an overview of the snap shot regional accuracy information 
                    if( playerProfile.getSnapShotRank() != Profile.Rank.Unranked )
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getSnapShotRank()+"Icon", centerX+540, centerY-170, GUI_TEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "SnapShotRegionalTitle", centerX+145, centerY-190, GUI_SUBTEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "SnapShotRegions", centerX+205, centerY+110, GUI_SUBTEXT_DRAW_ORDER );                    
                    buildButton( "SnapShotRegionalShotTime", "ShotTime", centerX+50, centerY-120, GUI_TEXT_DRAW_ORDER );
                    buildButton( "SnapShotRegionalAccuracy", "Accuracy", centerX+365, centerY-120, GUI_TEXT_DRAW_ORDER );
                    buildMessage( "SnapShotFTRReport", "" + (int)playerProfile.getFarTopRightShotAccuracy()+"%", centerX+400, centerY-50 );
                    buildMessage( "SnapShotFTLReport", "" + (int)playerProfile.getFarTopLeftShotAccuracy()+"%", centerX+25, centerY-50 );
                    buildMessage( "SnapShotNTRReport", "" + (int)playerProfile.getNearTopRightShotAccuracy()+"%", centerX+290, centerY+65 );
                    buildMessage( "SnapShotNTLReport", "" + (int)playerProfile.getNearTopLeftShotAccuracy()+"%", centerX+110, centerY+65 );
                    buildMessage( "SnapShotFBRReport", "" + (int)playerProfile.getFarBottomRightShotAccuracy()+"%", centerX+400, centerY+260 );
                    buildMessage( "SnapShotFBLReport", "" + (int)playerProfile.getFarBottomLeftShotAccuracy()+"%", centerX+25, centerY+260 );
                    buildMessage( "SnapShotNBRReport", "" + (int)playerProfile.getNearBottomRightShotAccuracy()+"%", centerX+290, centerY+150 );
                    buildMessage( "SnapShotNBLReport", "" + (int)playerProfile.getNearBottomLeftShotAccuracy()+"%", centerX+110, centerY+150 );
                    buildMessage( "Num snap shots: " + playerProfile.getTotalSnapShots(), centerX+200, centerY+350 );
                    break;
                    
                case Tracking:
                    // Display an overview of the ranked tracking accuracies
                    if( playerProfile.getTrackingRank() != Profile.Rank.Unranked )
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getTrackingRank()+"Icon", centerX+540, centerY-170, GUI_TEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "TrackingTitle", centerX-35, centerY-190, GUI_SUBTEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "TargetBackground", centerX+200, centerY+70, GUI_SUBTEXT_DRAW_ORDER );                    
                    buildMessage( "Rank :  Bull  :  Target :  Miss", centerX+200, centerY-85 );
                    int offsetY = -30;
                    for( int levelIdx = 0; levelIdx < 6; levelIdx++ ) {
                        buildMessage( ""+(levelIdx+1), centerX-50, centerY+offsetY );
                        buildMessage( ""+(int)Math.round(playerProfile.getPercentageBullTrackTimeForLevel(levelIdx))+"%", centerX+105, centerY+offsetY );
                        buildMessage( ""+(int)Math.round(playerProfile.getPercentageTargetTrackTimeForLevel(levelIdx))+"%", centerX+270, centerY+offsetY );
                        buildMessage( ""+(int)Math.round(playerProfile.getPercentageMissTrackTimeForLevel(levelIdx))+"%", centerX+460, centerY+offsetY );
                        offsetY+=50;
                    }                        
                    buildMessage( "Num tracking seconds: " + playerProfile.getTotalTrackSeconds(), centerX+200, centerY+350 );
                    break;
                    
                case SniperShot:
                    // Display an overview of the ranked sniper shot accuracies
                    if( playerProfile.getSniperShotRank() != Profile.Rank.Unranked )
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getSniperShotRank()+"Icon", centerX+540, centerY-170, GUI_TEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "SniperShotTitle", centerX+0, centerY-190, GUI_SUBTEXT_DRAW_ORDER );            
                    buildNonInteractiveGraphicalObject( "SniperTargetBackground", centerX+200, centerY+80, GUI_SUBTEXT_DRAW_ORDER );                    
                    buildMessage( "Rank :  Head  :  Target  : Miss", centerX+200, centerY-85 );
                    offsetY = -30;
                    for( int levelIdx = 0; levelIdx < 6; levelIdx++ ) {
                        buildMessage( ""+(levelIdx+1), centerX-60, centerY+offsetY );
                        buildMessage( ""+(int)Math.round(playerProfile.getPercentageHeadShotsForLevel(levelIdx))+"%", centerX+110, centerY+offsetY );
                        buildMessage( ""+(int)Math.round(playerProfile.getPercentageBodyShotsForLevel(levelIdx))+"%", centerX+285, centerY+offsetY );
                        buildMessage( ""+(int)Math.round(playerProfile.getPercentageMissShotsForLevel(levelIdx))+"%", centerX+475, centerY+offsetY );
                        offsetY+=50;
                    }                        
                    buildMessage( "Num sniper shots: " + playerProfile.getTotalSniperShots(), centerX+200, centerY+350 );
                    break;
                    
                case Awards:
                    // Display details of the rank awards that the player has been given                    
                    buildNonInteractiveGraphicalObject( "AwardsTitle", centerX-50, centerY-195, GUI_TEXT_DRAW_ORDER );                    
                    buildNonInteractiveGraphicalObject( "MedalRank1Icon", centerX+140, centerY-190, GUI_TEXT_DRAW_ORDER );                    
                    buildNonInteractiveGraphicalObject( "MedalRank2Icon", centerX+220, centerY-190, GUI_TEXT_DRAW_ORDER );                    
                    buildNonInteractiveGraphicalObject( "MedalRank3Icon", centerX+300, centerY-190, GUI_TEXT_DRAW_ORDER );                    
                    buildNonInteractiveGraphicalObject( "MedalRank4Icon", centerX+380, centerY-190, GUI_TEXT_DRAW_ORDER );                    
                    buildNonInteractiveGraphicalObject( "MedalRank5Icon", centerX+460, centerY-190, GUI_TEXT_DRAW_ORDER );                    
                    buildNonInteractiveGraphicalObject( "MedalRank6Icon", centerX+540, centerY-190, GUI_TEXT_DRAW_ORDER );                    
                    
                    buildMessage( "Reaction", centerX-100, centerY-50 );                    
                    buildMessage( "Time", centerX-100, centerY-10 );                    
                    if( playerProfile.getReactionTimeRank() != Profile.Rank.Unranked ) {
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getReactionTimeRank(), centerX-100, centerY+170, GUI_TEXT_DRAW_ORDER );            
                        buildMessage( ""+playerProfile.getReactionTimeRank(), centerX-100, centerY+330 );
                    } else
                        buildMessage( "Unranked", centerX-100, centerY+100 );                    
                                            
                    buildMessage( "Snap", centerX+100, centerY-50 );                    
                    buildMessage( "Shot", centerX+100, centerY-10 );                    
                    if( playerProfile.getSnapShotRank() != Profile.Rank.Unranked ) {
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getSnapShotRank(), centerX+100, centerY+170, GUI_TEXT_DRAW_ORDER );            
                        buildMessage( ""+playerProfile.getSnapShotRank(), centerX+100, centerY+330 );
                    } else
                        buildMessage( "Unranked", centerX+100, centerY+100 );                    
                    
                    buildMessage( "Tracking", centerX+300, centerY-50 );                    
                    if( playerProfile.getTrackingRank() != Profile.Rank.Unranked ) {
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getTrackingRank(), centerX+300, centerY+170, GUI_TEXT_DRAW_ORDER );            
                        buildMessage( ""+playerProfile.getTrackingRank(), centerX+300, centerY+330 );
                    } else
                        buildMessage( "Unranked", centerX+300, centerY+100 );                    
                    
                    buildMessage( "Sniper", centerX+500, centerY-50 );                    
                    buildMessage( "Shot", centerX+500, centerY-10 );                    
                    if( playerProfile.getSniperShotRank() != Profile.Rank.Unranked ) {
                        buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getSniperShotRank(), centerX+500, centerY+170, GUI_TEXT_DRAW_ORDER );            
                        buildMessage( ""+playerProfile.getSniperShotRank(), centerX+500, centerY+330 );
                    } else
                        buildMessage( "Unranked", centerX+500, centerY+100 );                    
                    break;
            }
        }
    }

     /**
     * Build the training menu
     */    
    private void buildTrainingMenu() {
        double centerX = width/2.0, centerY = height/2.0;
                
        // Display the training menu title and provide a main menu button
        buildNonInteractiveGraphicalObject( "TrainingTitle", centerX-330, centerY-380, GUI_SUBTEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "TitleBar", centerX, centerY-300, GUI_TEXT_DRAW_ORDER );
        buildButton( "MainMenu", "MainMenu", centerX+460, centerY-340, GUI_TEXT_DRAW_ORDER );

        // Display the different test types on which training is available
        buildNonInteractiveGraphicalObject( "TrainTitle", centerX-440, centerY-190, GUI_TEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "MenuBorder", centerX-430, centerY+70, GUI_TEXT_DRAW_ORDER );

        buildButton( "ReactionTime", "ReactionTime", centerX-420, centerY-80, GUI_TEXT_DRAW_ORDER );
        buildButton( "SnapShot", "SnapShot", centerX-420, centerY-10, GUI_TEXT_DRAW_ORDER );
        buildButton( "Tracking", "Tracking", centerX-420, centerY+60, GUI_TEXT_DRAW_ORDER );
        buildButton( "SniperShot", "SniperShot", centerX-420, centerY+130, GUI_TEXT_DRAW_ORDER );
        
        // Based upon the training category that is selected, display relevant control
        // parameters that can be used to fine tune the type of training 
        if( trainingDisplay != TrainingDisplay.None ) {
            buildNonInteractiveGraphicalObject( "ContentBorder", centerX+205, centerY+65, GUI_SUBTEXT_DRAW_ORDER );  
            buildButton( "Start", "Start", centerX+460, centerY-190, GUI_TEXT_DRAW_ORDER );

            switch( trainingDisplay ) {
                case ReactionTime:
                    // Display available training parameters for the reaction time test
                    buildNonInteractiveGraphicalObject( "ReactionTimeTitle", centerX+70, centerY-198, GUI_SUBTEXT_DRAW_ORDER );            
                    buildMessage( "This is a test of your reaction time.", centerX+200, centerY-120 );                    
                    buildMessage( "Whenever the target appears on the", centerX+200, centerY-75 );                    
                    buildMessage( "screen, click the left mouse button", centerX+200, centerY-30 );                    
                    buildMessage( "as quickly as you can.", centerX+200, centerY+15 );                    

                    buildNonInteractiveGraphicalObject( "SeparatorBar", centerX+200, centerY+60, GUI_SUBTEXT_DRAW_ORDER );                      
                    
                    buildMessage( "Number of tests:", centerX-5, centerY+105 );                    
                    buildInteractiveText( "NumTests5", "5", centerX+200, centerY+105);
                    buildInteractiveText( "NumTests10", "10", centerX+270, centerY+105 );
                    buildInteractiveText( "NumTests20", "20", centerX+340, centerY+105 );
                    buildInteractiveText( "NumTests50", "50", centerX+410, centerY+105 );
                    
                    buildMessage( "Target size:", centerX-60, centerY+170 );                    
                    buildInteractiveText( "TriggerSize0.25", "V.Small", centerX+140, centerY+170 );
                    buildInteractiveText( "TriggerSize0.5", "Small", centerX+275, centerY+170 );
                    buildInteractiveText( "TriggerSize1.0", "Medium", centerX+410, centerY+170 );
                    buildInteractiveText( "TriggerSize2.0", "Large", centerX+545, centerY+170 );

                    buildMessage( "Target highlight:", centerX-15, centerY+235 );                    
                    buildInteractiveText( "ChangeColourtrue", "True", centerX+200, centerY+235 );
                    buildInteractiveText( "ChangeColourfalse", "False", centerX+320, centerY+235 );
                    
                    buildMessage( "Play target sound:", centerX+10, centerY+300 );                    
                    buildInteractiveText( "PlaySoundtrue", "True", centerX+250, centerY+300 );
                    buildInteractiveText( "PlaySoundfalse", "False", centerX+370, centerY+300 );
                    break;
                    
                case SnapShot:
                    // Display available training parameters for the snap shot test                    
                    buildNonInteractiveGraphicalObject( "SnapShotTitle", centerX-10, centerY-190, GUI_SUBTEXT_DRAW_ORDER );            
                    buildMessage( "In this test you must hit targets as", centerX+200, centerY-120 );                    
                    buildMessage( "quickly as possible after they spawn.", centerX+200, centerY-75 );                    
                    buildMessage( "Performance is dependent upon your", centerX+200, centerY-30 );                    
                    buildMessage( "reaction speed and target accuracy.", centerX+200, centerY+15 );                    

                    buildNonInteractiveGraphicalObject( "SeparatorBar", centerX+200, centerY+60, GUI_SUBTEXT_DRAW_ORDER );                      

                    buildMessage( "Number of tests:", centerX-5, centerY+105 );                    
                    buildInteractiveText( "NumTests5", "5", centerX+200, centerY+105 );
                    buildInteractiveText( "NumTests10", "10", centerX+270, centerY+105 );
                    buildInteractiveText( "NumTests20", "20", centerX+340, centerY+105 );
                    buildInteractiveText( "NumTests50", "50", centerX+410, centerY+105 );

                    buildMessage( "Mouse speed:", centerX-40, centerY+170 );                    
                    buildInteractiveText( "MouseSpeed0.5", "x0.5", centerX+140, centerY+170 );
                    buildInteractiveText( "MouseSpeed0.7", "x0.7", centerX+240, centerY+170 );
                    buildInteractiveText( "MouseSpeed1.0", "x1.0", centerX+340, centerY+170 );
                    buildInteractiveText( "MouseSpeed1.5", "x1.5", centerX+440, centerY+170 );
                    buildInteractiveText( "MouseSpeed2.0", "x2.0", centerX+540, centerY+170 );

                    buildMessage( "Target size:", centerX-60, centerY+235 );                    
                    buildInteractiveText( "TargetSize0.25", "V.Small", centerX+140, centerY+235 );
                    buildInteractiveText( "TargetSize0.5", "Small", centerX+275, centerY+235 );
                    buildInteractiveText( "TargetSize1.0", "Medium", centerX+410, centerY+235 );
                    buildInteractiveText( "TargetSize2.0", "Large", centerX+545, centerY+235 );
                    
                    buildMessage( "Region:", centerX-105, centerY+300 );                    
                    buildInteractiveText( "SpawnRandom", "Random", centerX+60, centerY+300);
                    buildInteractiveText( "SpawnTop", "Up", centerX+180, centerY+300 );
                    buildInteractiveText( "SpawnBottom", "Down", centerX+280, centerY+300 );
                    buildInteractiveText( "SpawnRight", "Right", centerX+400, centerY+300 );
                    buildInteractiveText( "SpawnLeft", "Left", centerX+510, centerY+300 );                    
                    break;
                    
                case Tracking:
                    // Display available training parameters for the tracking test
                    buildNonInteractiveGraphicalObject( "TrackingTitle", centerX-35, centerY-190, GUI_SUBTEXT_DRAW_ORDER );            
                    buildMessage( "In this test you must keep the mouse", centerX+200, centerY-120 );                    
                    buildMessage( "sight on the center of the target.", centerX+200, centerY-75 );                    

                    buildNonInteractiveGraphicalObject( "SeparatorBar", centerX+200, centerY-15, GUI_SUBTEXT_DRAW_ORDER );                      

                    buildMessage( "Track duration(s):", centerX-10, centerY+35 );                    
                    buildInteractiveText( "Duration10", "10", centerX+200, centerY+35 );
                    buildInteractiveText( "Duration30", "30", centerX+270, centerY+35 );
                    buildInteractiveText( "Duration60", "60", centerX+340, centerY+35 );
                    buildInteractiveText( "Duration120", "120", centerX+420, centerY+35 );

                    buildMessage( "Mouse speed:", centerX-40, centerY+100 );                    
                    buildInteractiveText( "MouseSpeed0.5", "x0.5", centerX+140, centerY+100 );
                    buildInteractiveText( "MouseSpeed0.7", "x0.7", centerX+240, centerY+100 );
                    buildInteractiveText( "MouseSpeed1.0", "x1.0", centerX+340, centerY+100 );
                    buildInteractiveText( "MouseSpeed1.5", "x1.5", centerX+440, centerY+100 );
                    buildInteractiveText( "MouseSpeed2.0", "x2.0", centerX+540, centerY+100 );
                    
                    buildMessage( "Target size:", centerX-60, centerY+165 );                    
                    buildInteractiveText( "TargetSize0.25", "V.Small", centerX+140, centerY+165 );
                    buildInteractiveText( "TargetSize0.5", "Small", centerX+275, centerY+165 );
                    buildInteractiveText( "TargetSize1.0", "Medium", centerX+410, centerY+165 );
                    buildInteractiveText( "TargetSize2.0", "Large", centerX+545, centerY+165 );
                    
                    buildMessage( "Movement:", centerX-70, centerY+230 );                    
                    buildInteractiveText( "MoveHorizontal", "Horizontal", centerX+150, centerY+230 );
                    buildInteractiveText( "MoveVertical", "Vertical", centerX+340, centerY+230 );
                    buildInteractiveText( "MoveCircular", "Circular", centerX+510, centerY+230 );
                    buildInteractiveText( "MoveSlightCurved", "Slight Curved", centerX+140, centerY+285 );
                    buildInteractiveText( "MoveHeavyCurved", "Heavy Curved", centerX+440, centerY+285 );
                    
                    buildMessage( "Challenge:", centerX-80, centerY+350 );                    
                    buildInteractiveText( "Challenge1", "1", centerX+50, centerY+350);
                    buildInteractiveText( "Challenge2", "2", centerX+100, centerY+350 );
                    buildInteractiveText( "Challenge3", "3", centerX+150, centerY+350 );
                    buildInteractiveText( "Challenge4", "4", centerX+200, centerY+350 );
                    buildInteractiveText( "Challenge5", "5", centerX+250, centerY+350 );                    
                    buildInteractiveText( "Challenge6", "6", centerX+300, centerY+350);
                    buildInteractiveText( "Challenge7", "7", centerX+350, centerY+350 );
                    buildInteractiveText( "Challenge8", "8", centerX+400, centerY+350 );
                    buildInteractiveText( "Challenge9", "9", centerX+450, centerY+350 );
                    buildInteractiveText( "Challenge10", "10", centerX+510, centerY+350 );                    
                    
                    break;
                case SniperShot:
                    // Display available training parameters for the sniper shot test                    
                    buildNonInteractiveGraphicalObject( "SniperShotTitle", centerX+0, centerY-190, GUI_SUBTEXT_DRAW_ORDER );                                
                    buildMessage( "Snipe that target... (in the head)", centerX+200, centerY-120 );                    

                    buildNonInteractiveGraphicalObject( "SeparatorBar", centerX+200, centerY-80, GUI_SUBTEXT_DRAW_ORDER );                      

                    buildMessage( "Target hit points:", centerX-10, centerY-30 );                    
                    buildInteractiveText( "Hitpoints2", "2", centerX+200, centerY-30 );
                    buildInteractiveText( "Hitpoints5", "5", centerX+270, centerY-30 );
                    buildInteractiveText( "Hitpoints10", "10", centerX+340, centerY-30 );
                    buildInteractiveText( "Hitpoints20", "20", centerX+420, centerY-30 );

                    buildMessage( "Mouse speed:", centerX-40, centerY+35 );                    
                    buildInteractiveText( "MouseSpeed0.5", "x0.5", centerX+140, centerY+35 );
                    buildInteractiveText( "MouseSpeed0.7", "x0.7", centerX+240, centerY+35 );
                    buildInteractiveText( "MouseSpeed1.0", "x1.0", centerX+340, centerY+35 );
                    buildInteractiveText( "MouseSpeed1.5", "x1.5", centerX+440, centerY+35 );
                    buildInteractiveText( "MouseSpeed2.0", "x2.0", centerX+540, centerY+35 );
                    
                    buildMessage( "Sight wobble:", centerX-45, centerY+100 );                    
                    buildInteractiveText( "Wobble0.0", "None", centerX+140, centerY+100 );
                    buildInteractiveText( "Wobble0.5", "Minor", centerX+260, centerY+100 );
                    buildInteractiveText( "Wobble1.0", "Normal", centerX+400, centerY+100 );
                    buildInteractiveText( "Wobble1.5", "Major", centerX+540, centerY+100 );
                     
                    buildMessage( "Target size:", centerX-60, centerY+165 );                    
                    buildInteractiveText( "TargetSize0.25", "V.Small", centerX+140, centerY+165 );
                    buildInteractiveText( "TargetSize0.5", "Small", centerX+275, centerY+165 );
                    buildInteractiveText( "TargetSize1.0", "Medium", centerX+410, centerY+165 );
                    buildInteractiveText( "TargetSize2.0", "Large", centerX+545, centerY+165 );
                    
                    buildMessage( "Movement:", centerX-70, centerY+230 );                    
                    buildInteractiveText( "MoveHorizontal", "Horizontal", centerX+150, centerY+230 );
                    buildInteractiveText( "MoveVertical", "Vertical", centerX+340, centerY+230 );
                    buildInteractiveText( "MoveCircular", "Circular", centerX+510, centerY+230 );
                    buildInteractiveText( "MoveSlightCurved", "Slight Curved", centerX+140, centerY+285 );
                    buildInteractiveText( "MoveHeavyCurved", "Heavy Curved", centerX+440, centerY+285 );
                    
                    buildMessage( "Challenge:", centerX-80, centerY+350 );                    
                    buildInteractiveText( "Challenge1", "1", centerX+50, centerY+350);
                    buildInteractiveText( "Challenge2", "2", centerX+100, centerY+350 );
                    buildInteractiveText( "Challenge3", "3", centerX+150, centerY+350 );
                    buildInteractiveText( "Challenge4", "4", centerX+200, centerY+350 );
                    buildInteractiveText( "Challenge5", "5", centerX+250, centerY+350 );                    
                    buildInteractiveText( "Challenge6", "6", centerX+300, centerY+350);
                    buildInteractiveText( "Challenge7", "7", centerX+350, centerY+350 );
                    buildInteractiveText( "Challenge8", "8", centerX+400, centerY+350 );
                    buildInteractiveText( "Challenge9", "9", centerX+450, centerY+350 );
                    buildInteractiveText( "Challenge10", "10", centerX+510, centerY+350 );                                        
                    break;
            }
        }
    }

     /**
     * Build the ranking menu
     */    
    private void buildRankingMenu() {
        double centerX = width/2.0, centerY = height/2.0;
        
        // Display the ranking menu title and provide a main menu button
        buildNonInteractiveGraphicalObject( "RankingTitle", centerX-340, centerY-380, GUI_SUBTEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "TitleBar", centerX, centerY-300, GUI_TEXT_DRAW_ORDER );
        buildButton( "MainMenu", "MainMenu", centerX+460, centerY-340, GUI_TEXT_DRAW_ORDER );
        
        // Display the different types of ranked test that are available
        buildNonInteractiveGraphicalObject( "TestTitle", centerX-440, centerY-190, GUI_TEXT_DRAW_ORDER );
        buildNonInteractiveGraphicalObject( "MenuBorder", centerX-430, centerY+70, GUI_TEXT_DRAW_ORDER );

        buildButton( "ReactionTime", "ReactionTime", centerX-420, centerY-80, GUI_TEXT_DRAW_ORDER );
        buildButton( "SnapShot", "SnapShot", centerX-420, centerY-10, GUI_TEXT_DRAW_ORDER );
        buildButton( "Tracking", "Tracking", centerX-420, centerY+60, GUI_TEXT_DRAW_ORDER );
        buildButton( "SniperShot", "SniperShot", centerX-420, centerY+130, GUI_TEXT_DRAW_ORDER );
        
        // Based upon the ranked category that is selected, display details of the 
        // current player rank and the requirements of the next rank
        if( rankDisplay != RankDisplay.None ) {
            buildNonInteractiveGraphicalObject( "CurrentRankBorder", centerX-50, centerY+65, GUI_SUBTEXT_DRAW_ORDER );  
            buildNonInteractiveGraphicalObject( "RankTitle", centerX-65, centerY-200, GUI_TEXT_DRAW_ORDER );            
            buildNonInteractiveGraphicalObject( "NextRankBorder", centerX+380, centerY+65, GUI_SUBTEXT_DRAW_ORDER );  
            buildNonInteractiveGraphicalObject( "NextRankTitle", centerX+360, centerY-200, GUI_SUBTEXT_DRAW_ORDER );  
            buildButton( "Start", "Start", centerX+550, centerY+360, GUI_TEXT_DRAW_ORDER );

            switch( rankDisplay ) {
                case ReactionTime:
                    // Display information on the next reaction time rank
                    buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getReactionTimeRank(), centerX-65, centerY+40, GUI_TEXT_DRAW_ORDER );                                                    
                    buildMessage( ""+playerProfile.getReactionTimeRank(), centerX-65, centerY+210 );                    
                    
                    buildMessage( "Reaction Time: " + (playerProfile.getReactionTimeRank() == Profile.Rank.Rank6 ? 
                                "Rank 6" : playerProfile.getNextReactionTimeRank() ), centerX+360, centerY-80 );
                    
                    if( playerProfile.getReactionTimeRank() == Profile.Rank.Rank6 ) {
                        buildMessage( "You already have", centerX+360, centerY+20 );                                            
                        buildMessage( "the highest rank.", centerX+360, centerY+70 );                                            
                        buildMessage( "Click start to", centerX+360, centerY+120 );                                            
                        buildMessage( "retake the test.", centerX+360, centerY+170 );                                            
                    } else {
                        Profile.Rank nextRank = playerProfile.getNextReactionTimeRank();
                        buildMessage( "Achieve an average", centerX+360, centerY+20 );
                        buildMessage( "reaction time of at", centerX+360, centerY+70 );
                        buildMessage( "most " + Profile.getAverageReactionTimeForRank( nextRank )
                                + "ms to be", centerX+360, centerY+120 );
                        buildMessage( "awarded Rank " + nextRank.toString().substring(4,5)                                
                                , centerX+360, centerY+170 );
                    }                    
                    break;
                    
                case SnapShot:
                    // Display information on the next snap shot rank                    
                    buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getSnapShotRank(), centerX-65, centerY+40, GUI_TEXT_DRAW_ORDER );                                                    
                    buildMessage( ""+playerProfile.getSnapShotRank(), centerX-65, centerY+210 );                    

                    buildMessage( "Snap Shot: " + (playerProfile.getSnapShotRank() == Profile.Rank.Rank6 ? 
                                "Rank 6" : playerProfile.getNextSnapShotRank() ), centerX+360, centerY-80 );
                    
                    if( playerProfile.getSnapShotRank() == Profile.Rank.Rank6 ) {
                        buildMessage( "You already have", centerX+360, centerY+20 );                                            
                        buildMessage( "the highest rank.", centerX+360, centerY+70 );                                            
                        buildMessage( "Click start to", centerX+360, centerY+120 );                                            
                        buildMessage( "retake the test.", centerX+360, centerY+170 );                                            
                    } else {
                        Profile.Rank nextRank = playerProfile.getNextSnapShotRank();                        
                        buildMessage( "Achieve an average", centerX+360, centerY+20 );
                        buildMessage( "target accuracy of at", centerX+360, centerY+70 );
                        buildMessage( "least " + Profile.getSnapShotTargetAccuracyForRank( nextRank )
                                + "% with an", centerX+360, centerY+120 );
                        buildMessage( "average shot time of", centerX+360, centerY+170 );
                        buildMessage( "at most " + Profile.getAverageSnapShotTimeForRank( nextRank )
                                + "ms to", centerX+360, centerY+220 );
                        buildMessage( "be awarded Rank " + nextRank.toString().substring(4,5),
                                centerX+360, centerY+270 );                        
                    }                    
                    break;
                    
                case Tracking:
                    // Display information on the next tracking rank
                    buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getTrackingRank(), centerX-65, centerY+40, GUI_TEXT_DRAW_ORDER );                                                    
                    buildMessage( ""+playerProfile.getTrackingRank(), centerX-65, centerY+210 );                    

                    buildMessage( "Tracking: " + (playerProfile.getTrackingRank() == Profile.Rank.Rank6 ? 
                                "Rank 6" : playerProfile.getNextTrackingRank() ), centerX+360, centerY-80 );
                    
                    if( playerProfile.getTrackingRank() == Profile.Rank.Rank6 ) {
                        buildMessage( "You already have", centerX+360, centerY+20 );                                            
                        buildMessage( "the highest rank.", centerX+360, centerY+70 );                                            
                        buildMessage( "Click start to", centerX+360, centerY+120 );                                            
                        buildMessage( "retake the test.", centerX+360, centerY+170 );                                            
                    } else {
                        Profile.Rank nextRank = playerProfile.getNextTrackingRank();                        
                        buildMessage( "Achieve an average on", centerX+360, centerY+20 );
                        buildMessage( "target accuracy of at", centerX+360, centerY+70 );
                        buildMessage( "least " + Profile.getTargetTrackingAccuracyForRank( nextRank )
                                + "% with an", centerX+360, centerY+120 );
                        buildMessage( "average bull accuracy", centerX+360, centerY+170 );
                        buildMessage( "of at least " + Profile.getBullTrackingAccuracyForRank( nextRank )
                                + "% to", centerX+360, centerY+220 );
                        buildMessage( "be awarded Rank " + nextRank.toString().substring(4,5),
                                centerX+360, centerY+270 );                        
                    }                    
                    break;
                    
                case SniperShot:
                    // Display information on the next sniper shot rank                    
                    buildNonInteractiveGraphicalObject( "Medal"+playerProfile.getSniperShotRank(), centerX-65, centerY+40, GUI_TEXT_DRAW_ORDER );                                                    
                    buildMessage( ""+playerProfile.getSniperShotRank(), centerX-65, centerY+210 );                    

                    buildMessage( "Sniper Shot: " + (playerProfile.getSniperShotRank() == Profile.Rank.Rank6 ? 
                                "Rank 6" : playerProfile.getNextSniperShotRank() ), centerX+360, centerY-80 );
                    
                    if( playerProfile.getSniperShotRank() == Profile.Rank.Rank6 ) {
                        buildMessage( "You already have", centerX+360, centerY+20 );                                            
                        buildMessage( "the highest rank.", centerX+360, centerY+70 );                                            
                        buildMessage( "Click start to", centerX+360, centerY+120 );                                            
                        buildMessage( "retake the test.", centerX+360, centerY+170 );                                            
                    } else {
                        Profile.Rank nextRank = playerProfile.getNextSniperShotRank();                        
                        buildMessage( "Achieve an average on", centerX+360, centerY+20 );
                        buildMessage( "body accuracy of at", centerX+360, centerY+70 );
                        buildMessage( "least " + Profile.getBodyShotsAccuracyForRank( nextRank )
                                + "% with an", centerX+360, centerY+120 );
                        buildMessage( "average head accuracy", centerX+360, centerY+170 );
                        buildMessage( "of at least " + Profile.getHeadShotsAccuracyForRank( nextRank )
                                + "% to", centerX+360, centerY+220 );
                        buildMessage( "be awarded Rank " + nextRank.toString().substring(4,5),
                                centerX+360, centerY+270 );                        
                    }                    
                    break;
            }                        
        }        
    }
    
    /**
     * Helper method that builds a basic, named, non-interactive, graphical 
     * element at the specified location and with the specified draw order
     */            
    private void buildNonInteractiveGraphicalObject( 
            String gameObjectName, String assetName, double x, double y, int drawOrder ) {
        GameObject gameObject = new GameObject( this, x, y, drawOrder );  
        gameObject.setName( gameObjectName );
        gameObject.setRealisationAndGeometry( assetName );                
        queueGameObjectToAdd( gameObject, "NonInteractiveMenuElements" );
    }
    
    /**
     * Helper method that builds a basic, non-interactive, graphical 
     * element at the specified location and with the specified draw order
     */            
    private void buildNonInteractiveGraphicalObject( 
            String assetName, double x, double y, int drawOrder ) {
        GameObject gameObject = new GameObject( this, x, y, drawOrder );  
        gameObject.setRealisationAndGeometry( assetName );                
        queueGameObjectToAdd( gameObject, "NonInteractiveMenuElements" );
    }

    /**
     * Helper method that builds a named textual message at the specified
     * location with the default text draw order
     */            
    private void buildMessage( String gameObjectName, String message, double x, double y ) {
        TextElement textElement = guiFont.getMatchingElement( message );
        textElement.setName( gameObjectName );
        textElement.setPosition( x, y );
        textElement.setDrawOrder( GUI_TEXT_DRAW_ORDER );

        queueGameObjectToAdd( textElement, "NonInteractiveMenuElements" );
    }
        
    /**
     * Helper method that builds a textual message at the specified
     * location with the default text draw order
     */            
    private void buildMessage( String message, double x, double y ) {
        TextElement textElement = guiFont.getMatchingElement( message );
        textElement.setPosition( x, y );
        textElement.setDrawOrder( GUI_TEXT_DRAW_ORDER );

        queueGameObjectToAdd( textElement, "NonInteractiveMenuElements" );
    }

    /**
     * Helper method that builds an interactive textual message at the specified
     * location with the default text draw order. Interactive text elements
     * are added to the InteractiveTextElements game object collection
     * and processed during the update tick
     */            
    private void buildInteractiveText( String gameObjectName, String message, double x, double y ) {
        TextElement textElement = guiFont.getMatchingElement( message );
        textElement.setName( gameObjectName );
        textElement.setPosition( x, y );
        textElement.setDrawOrder( GUI_TEXT_DRAW_ORDER );
        queueGameObjectToAdd( textElement, "InteractiveTextElements" );
    }
    
    /**
     * Helper method that can be called by an extending class to place a
     * clickable button, constructed using the specified asset base
     * name, at the specified location and with the specified draw
     * order
     */        
    private void buildButton( String objectName, String assetBaseName, 
            double x, double y, int drawOrder ) {
        Button button = new Button( this, objectName,
            assetBaseName, assetBaseName+"Mouseover", assetBaseName+"Clicked",
                "Mouseover", "Click", x, y, drawOrder );
        queueGameObjectToAdd( button, "InteractiveElements" );
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Menu Update                                                  //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Update the menus
     */  
    @Override
    public void update()
    {
        super.update();
    
        // Update all defined interactive GUI element
        GameObjectCollection interactiveElements = getGameObjectCollection( "InteractiveElements" );
            for( int idx = 0; idx < interactiveElements.size; idx++ )
                interactiveElements.gameObjects[idx].update();

        // Update all defined interactive text element
        GameObjectCollection interactiveTestElements = getGameObjectCollection( "InteractiveTextElements" );
            for( int idx = 0; idx < interactiveTestElements.size; idx++ )
                interactiveTestElements.gameObjects[idx].update();

        // Based upon the current menu, call the relevant update method
        switch( currentMenu ) {
            case Loader: updateLoaderMenu(); break;
            case Main: updateMainMenu(); break;
            case Profile: updateProfileMenu(); break;
            case Performance: updatePerformanceMenu(); break;
            case Training: updateTrainingMenu(); break;
            case Ranking: updateRankingMenu(); break;
        }                        
    }
    
    /**
     * Update the loader menu
     */  
    private void updateLoaderMenu() {
        if( loadMenuAssets == false ) {
            // Force the game engine to render the next draw (i.e. displaying
            // the splash loader screen            
            loadMenuAssets = true;
            gameEngine.doNotSkipNextRender();
        } else {
            // Load in the various asset set used by ZoMA
            assetManager.loadAssetsFromFile( this.getClass().getResource( "images/ZoMAMenuAssets.txt" ) );
            assetManager.loadAssetsFromFile( this.getClass().getResource( "images/ZoMAGameAssets.txt" ) );            
            assetManager.loadAssetsFromFile( this.getClass().getResource( "sounds/ZoMASoundAssets.txt" ) );                        

            // Change the current menu to the main menu and build it
            currentMenu = Menu.Main;
            buildCurrentMenu();
        }        
    }
    
    /**
     * Update the main menu
     */  
    private void updateMainMenu() {
        // Check if the profile button has been pressed
        if( ((Button)getGameObject( "Profile" )).buttonClicked() ) {
            currentMenu = Menu.Profile;
            buildCurrentMenu();            
        } 
        
        // If a profile has been loaded and then for other button presses
        if( playerProfile != null ) {
            if( ((Button)getGameObject( "Performance" )).buttonClicked() ) {
                currentMenu = Menu.Performance;
                buildCurrentMenu();            
            } else if( ((Button)getGameObject( "Training" )).buttonClicked() ) {
                currentMenu = Menu.Training;
                buildCurrentMenu();            
            } else if( ((Button)getGameObject( "Ranking" )).buttonClicked() ) {
                currentMenu = Menu.Ranking;
                buildCurrentMenu();            
            } else if( ((Button)getGameObject( "Quit" )).buttonClicked() ) {
                gameEngine.terminateProcess();
            }         
        }
    }

    /**
     * Update the profile menu
     */  
    private void updateProfileMenu() {
        // If needed, return to the main menu
        if( ((Button)getGameObject( "MainMenu" )).buttonClicked() ) {
            currentMenu = Menu.Main;
            buildCurrentMenu();    
        }        

        // Determine the bounds of the box for creating new profiles
        GameObject profileCreateBox = getGameObject( "ProfileCreateBox" );            
        double x = getGameObjectScreenX( profileCreateBox );
        double y = getGameObjectScreenY( profileCreateBox );
        double halfWidth = getGameObjectScreenWidth( profileCreateBox )/2.0;
        double halfHeight = getGameObjectScreenHeight( profileCreateBox )/2.0;

        // If the mouse is within the create new profile box, then give
        // the textfield for entering the new profile name the input focus
        if( inputEvent.mouseXCoordinate > x-halfWidth 
                && inputEvent.mouseXCoordinate < x+halfWidth
                && inputEvent.mouseYCoordinate > y-halfHeight
                && inputEvent.mouseYCoordinate < y+halfHeight ) {
            if( ((TextField)getGameObject( "ProfileName" )).hasFocus() == false )
                ((TextField)getGameObject( "ProfileName" )).setFocus( true, true );
        } else
            ((TextField)getGameObject( "ProfileName" )).setFocus( false, false );                        

        // Check if the create new profile button has been clicked
        if( ((Button)getGameObject( "Create" )).buttonClicked() ) {
            // Remove any previous profile messages (e.g. previous error messages)
            if( getGameObject( "ProfileMessage" ) != null )
                queueGameObjectToRemove( getGameObject( "ProfileMessage" ) );

            // Check that a profile name has been entered
            String profileName = ((TextField)getGameObject( "ProfileName" )).getText();
            if( profileName.length() == 0 ) {
                buildMessage( "ProfileMessage", "No profile name entered.", 
                    (width/2.0)-330.0, (height/2.0)-120.0 );
                assetManager.retrieveSoundAssetArchetype( "Error" ).play();
            } else {
                // Check to see if the profile name already exists with the
                // profile collection and display an error message if needed
                boolean profileNameAlreadyExists = false;
                for( int idx = 0; idx < profileCollection.getNumProfiles(); idx++ )
                    if( profileCollection.getProfile(idx).getProfileName().equals( profileName ) )
                        profileNameAlreadyExists = true;
                
                if( profileNameAlreadyExists  ) {
                    buildMessage( "ProfileMessage", "Profile name already used.", 
                        (width/2.0)-320.0, (height/2.0)-120.0 );
                    assetManager.retrieveSoundAssetArchetype( "Error" ).play();                
                } else if( profileCollection.getNumProfiles() == profileCollection.getMaxProfiles() ) {
                    // Check if the maximum number of profiles has been reached
                    buildMessage( "ProfileMessage", "Maximum number of profiles reached.", 
                        (width/2.0)-220.0, (height/2.0)-120.0 );
                    assetManager.retrieveSoundAssetArchetype( "Error" ).play();
                } else {
                    // If all the tests are passed, then create a new profile
                    // and add it to the profile collection. The created
                    // profile becomes the current profile
                    profileCollection.addNewProfile( profileName, 
                            gameEngine.screenWidth, gameEngine.screenHeight );
                    playerProfile = profileCollection.getProfile( profileName );
                    currentMenu = Menu.Main;
                    buildCurrentMenu();
                }
            }                
        }        
                
        // If the mouse button has been clicked, then check the available profile
        // names (as listed in the profile box) to see if the user has clicked
        // upon of the profiles. If so, then select this profile and rebuild
        // the menu (which will display profile information on the selected
        // profile).
        if( inputEvent.mouseClicked( MouseEvent.BUTTON1 ) ) {
            int[] clickLocation = inputEvent.getMouseClickLocation();
                
            String selectedProfileName = updateInteractiveText( clickLocation[0], clickLocation[1] );
            if( selectedProfileName != null ) {
                this.selectedProfileName = selectedProfileName;
                buildCurrentMenu();
            }
        }

        // Check to see if the delete button has been pressed
        if( ((Button)getGameObject( "Delete" )).buttonClicked() ) {
            // Remove any previous profile messages (e.g. previous error messages)
            if( getGameObject( "ProfileMessage" ) != null )
                queueGameObjectToRemove( getGameObject( "ProfileMessage" ) );

            // Check if a profile has been selected
            if( selectedProfileName == null ) {
                // If no profile has been selected then display an error message
                buildMessage( "ProfileMessage", "No profile selected.", (width/2.0)-400.0, (height/2.0)+395.0 );
                assetManager.retrieveSoundAssetArchetype( "Error" ).play();
            } else {
                // Delete the selected profile
                buildMessage( "ProfileMessage", "Profile deleted.", (width/2.0)-400.0, (height/2.0)+395.0 );
                if( playerProfile != null && playerProfile.getProfileName().equals( 
                        profileCollection.getProfile(selectedProfileName).getProfileName() ) )
                    playerProfile = null;

                profileCollection.deleteProfile( selectedProfileName );
                selectedProfileName = null;
                
                buildCurrentMenu();
            }                
        }
            
        // Check to see if the load button has been pressed
        if( ((Button)getGameObject( "Load" )).buttonClicked() ) {
            if( getGameObject( "ProfileMessage" ) != null )
                queueGameObjectToRemove( getGameObject( "ProfileMessage" ) );

            // Check if a profile has been selected
            if( selectedProfileName == null ) {
                // If no profile has been selected then display an error message
                buildMessage( "ProfileMessage", "No profile selected.", (width/2.0)-400.0, (height/2.0)+395.0 );
                assetManager.retrieveSoundAssetArchetype( "Error" ).play();
            } else {
                // Select the profile from the profile collection and return
                // to the main menu
                playerProfile = profileCollection.getProfile(selectedProfileName);
                currentMenu = Menu.Main;
                buildCurrentMenu();
            }
        }
    }
    
    /**
     * Update the performance menu
     */  
    private void updatePerformanceMenu() {
        // Toggle between the display of regional snap spot accuracy and
        // regional snap shot times if needed
        if( performanceDisplay == PerformanceDisplay.SnapShotRegional ) {
            if( ((Button)getGameObject( "SnapShotRegionalAccuracy" )).buttonClicked() ) {
                ((TextElement)getGameObject( "SnapShotFTRReport" )).setText( ""+(int)playerProfile.getFarTopRightShotAccuracy()+"%" );
                ((TextElement)getGameObject( "SnapShotFTLReport" )).setText( ""+(int)playerProfile.getFarTopLeftShotAccuracy()+"%" );
                ((TextElement)getGameObject( "SnapShotNTRReport" )).setText( ""+(int)playerProfile.getNearTopRightShotAccuracy()+"%" );
                ((TextElement)getGameObject( "SnapShotNTLReport" )).setText( ""+(int)playerProfile.getNearTopLeftShotAccuracy()+"%" );
                ((TextElement)getGameObject( "SnapShotFBRReport" )).setText( ""+(int)playerProfile.getFarBottomRightShotAccuracy()+"%" );
                ((TextElement)getGameObject( "SnapShotFBLReport" )).setText( ""+(int)playerProfile.getFarBottomLeftShotAccuracy()+"%" );
                ((TextElement)getGameObject( "SnapShotNBRReport" )).setText( ""+(int)playerProfile.getNearBottomRightShotAccuracy()+"%" );
                ((TextElement)getGameObject( "SnapShotNBLReport" )).setText( ""+(int)playerProfile.getNearBottomLeftShotAccuracy()+"%" );                
            } else if( ((Button)getGameObject( "SnapShotRegionalShotTime" )).buttonClicked() ) {
                ((TextElement)getGameObject( "SnapShotFTRReport" )).setText( ""+(int)playerProfile.getFarTopRightShotTime()+"ms" );
                ((TextElement)getGameObject( "SnapShotFTLReport" )).setText( ""+(int)playerProfile.getFarTopLeftShotTime()+"ms" );
                ((TextElement)getGameObject( "SnapShotNTRReport" )).setText( ""+(int)playerProfile.getNearTopRightShotTime()+"ms" );
                ((TextElement)getGameObject( "SnapShotNTLReport" )).setText( ""+(int)playerProfile.getNearTopLeftShotTime()+"ms" );
                ((TextElement)getGameObject( "SnapShotFBRReport" )).setText( ""+(int)playerProfile.getFarBottomRightShotTime()+"ms" );
                ((TextElement)getGameObject( "SnapShotFBLReport" )).setText( ""+(int)playerProfile.getFarBottomLeftShotTime()+"ms" );
                ((TextElement)getGameObject( "SnapShotNBRReport" )).setText( ""+(int)playerProfile.getNearBottomRightShotTime()+"ms" );
                ((TextElement)getGameObject( "SnapShotNBLReport" )).setText( ""+(int)playerProfile.getNearBottomLeftShotTime()+"ms" );                                
            }
        }
                
        // Check for changes in the performance menu that is displayed, or return
        // to the main menu if needed
        if( ((Button)getGameObject( "MainMenu" )).buttonClicked() ) {
            currentMenu = Menu.Main;
            buildCurrentMenu();    
        } else if( ((Button)getGameObject( "ReactionTime" )).buttonClicked() ) {
            performanceDisplay = PerformanceDisplay.ReactionTime;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "SnapShotOverview" )).buttonClicked() ) {
            performanceDisplay = PerformanceDisplay.SnapShotOverview;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "SnapShotRegional" )).buttonClicked() ) {
            performanceDisplay = PerformanceDisplay.SnapShotRegional;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "Tracking" )).buttonClicked() ) {
            performanceDisplay = PerformanceDisplay.Tracking;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "SniperShot" )).buttonClicked() ) {
            performanceDisplay = PerformanceDisplay.SniperShot;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "Awards" )).buttonClicked() ) {
            performanceDisplay = PerformanceDisplay.Awards;
            buildCurrentMenu();            
        }        
    }

    /**
     * Update the training menu
     */  
    
    private void updateTrainingMenu() {
        if( trainingDisplay != TrainingDisplay.None ) {
            // Check if a training session should be started back on the 
            // currently defined session parameters
            if( ((Button)getGameObject( "Start" )).buttonClicked() )
                startTrainingSession();

            // Test if the mouse has been clicked
            if( inputEvent.mouseClicked( MouseEvent.BUTTON1 ) ) {
                // Determine if the click was on top of an interactive text element
                int[] clickLocation = inputEvent.getMouseClickLocation();                
                String clickedButtonName = updateInteractiveText( clickLocation[0], clickLocation[1] );

                if( clickedButtonName != null ) { 
                    // Play a button click sound
                    assetManager.retrieveSoundAssetArchetype( "Click" ).play();

                    // Depending upon which training menu is displayed, update
                    // the relevant test session parmaeter
                    switch( trainingDisplay ) {
                        case ReactionTime:
                            if( clickedButtonName.startsWith( "NumTests" ) )
                                reactionNumberOfTests = Integer.parseInt( clickedButtonName.substring( 8 ) );
                            else if( clickedButtonName.startsWith( "TriggerSize" ) )
                                reactionTriggerSizeScale = Double.parseDouble( clickedButtonName.substring( 11 ) );
                            else if( clickedButtonName.startsWith( "ChangeColour" ) )
                                changeScreenColour = Boolean.parseBoolean( clickedButtonName.substring( 12 ) );
                            else if( clickedButtonName.startsWith( "PlaySound" ) )
                                playSoundOnTargetDisplay = Boolean.parseBoolean( clickedButtonName.substring( 9 ) );
                            break;
                            
                        case SnapShot:
                            if( clickedButtonName.startsWith( "NumTests" ) )
                                snapShotNumberOfTests = Integer.parseInt( clickedButtonName.substring( 8 ) );
                            else if( clickedButtonName.startsWith( "MouseSpeed" ) )
                                snapShotMouseMovementSpeed = Double.parseDouble( clickedButtonName.substring( 10 ) );
                            else if( clickedButtonName.startsWith( "TargetSize" ) )
                                snapShotTargetSize = Double.parseDouble( clickedButtonName.substring( 10 ) );
                            else if( clickedButtonName.startsWith( "Spawn" ) )
                                snapShotTargetRegion = clickedButtonName.substring( 5 );
                            break;
                            
                        case Tracking:
                            if( clickedButtonName.startsWith( "Duration" ) )
                                trackingDuration = Integer.parseInt( clickedButtonName.substring( 8 ) );
                            else if( clickedButtonName.startsWith( "MouseSpeed" ) )
                                trackingMouseMovementSpeed = Double.parseDouble( clickedButtonName.substring( 10 ) );
                            else if( clickedButtonName.startsWith( "TargetSize" ) )
                                trackingTargetSize = Double.parseDouble( clickedButtonName.substring( 10 ) );
                            else if( clickedButtonName.startsWith( "Move" ) )
                                trackingMovementType = clickedButtonName.substring( 4 );
                            else if( clickedButtonName.startsWith( "Challenge" ) )
                                trackingChallenge = Integer.parseInt( clickedButtonName.substring( 9 ) );
                            break;
                            
                        case SniperShot:
                            if( clickedButtonName.startsWith( "Hitpoints" ) )
                                sniperTargetHitPoints = Integer.parseInt( clickedButtonName.substring( 9 ) );
                            else if( clickedButtonName.startsWith( "MouseSpeed" ) )
                                sniperMouseMovementSpeed = Double.parseDouble( clickedButtonName.substring( 10 ) );
                            else if( clickedButtonName.startsWith( "Wobble" ) )
                                sniperSightWobble = Double.parseDouble( clickedButtonName.substring( 6 ) );
                            else if( clickedButtonName.startsWith( "TargetSize" ) )
                                sniperTargetSize = Double.parseDouble( clickedButtonName.substring( 10 ) );
                            else if( clickedButtonName.startsWith( "Move" ) )
                                sniperMovementType = clickedButtonName.substring( 4 );
                            else if( clickedButtonName.startsWith( "Challenge" ) )
                                sniperChallenge = Integer.parseInt( clickedButtonName.substring( 9 ) );
                            break;
                    }
                }
            }
        }
        
        // Check for changings to the training menu that is displayed,
        // or if we should return to the main menu
        if( ((Button)getGameObject( "MainMenu" )).buttonClicked() ) {
            currentMenu = Menu.Main;
            buildCurrentMenu();    
        } else if( ((Button)getGameObject( "ReactionTime" )).buttonClicked() ) {
            trainingDisplay = TrainingDisplay.ReactionTime;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "SnapShot" )).buttonClicked() ) {
            trainingDisplay = TrainingDisplay.SnapShot;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "Tracking" )).buttonClicked() ) {
            trainingDisplay = TrainingDisplay.Tracking;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "SniperShot" )).buttonClicked() ) {
            trainingDisplay = TrainingDisplay.SniperShot;
            buildCurrentMenu();           
        }
    }

    /**
     * Update the ranking menu
     */  
    private void updateRankingMenu() {
        // Test if a ranked session should be started
        if( this.rankDisplay != RankDisplay.None ) {            
            if( ((Button)getGameObject( "Start" )).buttonClicked() )
                startRankingSession();        
        }    
        
        // Update the rank that is displayed or return to the main menu
        // if needed
        if( ((Button)getGameObject( "MainMenu" )).buttonClicked() ) {
            currentMenu = Menu.Main;
            buildCurrentMenu();    
        } else if( ((Button)getGameObject( "ReactionTime" )).buttonClicked() ) {
            rankDisplay = RankDisplay.ReactionTime;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "SnapShot" )).buttonClicked() ) {
            rankDisplay = RankDisplay.SnapShot;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "Tracking" )).buttonClicked() ) {
            rankDisplay = RankDisplay.Tracking;
            buildCurrentMenu();            
        } else if( ((Button)getGameObject( "SniperShot" )).buttonClicked() ) {
            rankDisplay = RankDisplay.SniperShot;
            buildCurrentMenu();           
        }
    }
    
    /**
     * Update all interactive text based on the specified location of a 
     * mouse click, returning the name of any clicked element.
     * <P>
     * Note: All elements within the InteractiveTextElements game object
     * collection is compared within this method.
     */  
    private String updateInteractiveText( int clickX, int clickY ) {    
        String clickedButtonName = null;
        
        GameObjectCollection interactiveText = getGameObjectCollection( "InteractiveTextElements" );
        for( int textIdx = 0; clickedButtonName == null && textIdx < interactiveText.size; textIdx++ ) {            
            TextElement textElement = (TextElement)interactiveText.gameObjects[textIdx];

            Rectangle screenBound = getGameObjectScreenRectangle( textElement );
            if( screenBound.x < clickX
                    && screenBound.y < clickY
                    && screenBound.x + screenBound.width > clickX
                    && screenBound.y + screenBound.height -10 > clickY )
                    clickedButtonName = textElement.getName();
        }       
        
        return clickedButtonName;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Start game                                                   //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Start a training session based upon the selected session parameters
     */
    private void startTrainingSession() {
        ZoMAGameLayer zomaGame = null;
        
        switch( trainingDisplay ) {
            case ReactionTime:
                zomaGame = new ZoMAReactionTest( gameEngine, false, playerProfile,
                    reactionNumberOfTests, reactionTriggerSizeScale, 
                    changeScreenColour, playSoundOnTargetDisplay );
                break;
            case SnapShot:
                zomaGame = new ZoMASnapShotTest( gameEngine, false, playerProfile, 
                    snapShotNumberOfTests, snapShotMouseMovementSpeed, 
                    snapShotTargetSize, snapShotTargetRegion );
                break;
            case Tracking:
                zomaGame = new ZoMATrackingTest( gameEngine, false, playerProfile,
                    trackingDuration, trackingMouseMovementSpeed, 
                    trackingTargetSize, trackingMovementType, trackingChallenge );                        
                break;
            case SniperShot:
                zomaGame = new ZoMASniperShotTest( gameEngine, false, playerProfile,
                    sniperTargetHitPoints, sniperMouseMovementSpeed,
                    sniperSightWobble, sniperTargetSize, sniperMovementType, sniperChallenge );
                break;                        
        }
        
        // Activate and display the ZoMA game layer
        gameEngine.addGameLayer( zomaGame );
        zomaGame.setActivity( GameLayerActivity.ACTIVE );
        zomaGame.setVisibility( gameLayerVisibility.VISIBLE );

        // Deactivate and hide the menu layer
        this.setActivity( GameLayerActivity.INACTIVE );
        this.setVisibility( gameLayerVisibility.INVISIBLE );        
    }
    
    /**
     * Start a ranked session based upon the target rank parameters
     */    
    private void startRankingSession() {
        ZoMAGameLayer zomaGame = null;
        
        switch( rankDisplay ) {
            case ReactionTime:
                zomaGame = new ZoMAReactionTest( 
                        gameEngine, true, playerProfile, 10, 1.0, true, true );
                break;
            case SnapShot:
                double targetScaleFactor = 0.5 * height / 1024;
                zomaGame = new ZoMASnapShotTest( 
                        gameEngine, true, playerProfile, 10, 1.0, targetScaleFactor, "Random" );
                break;
            case Tracking:
                int challenge = (playerProfile.getTrackingRank() == Profile.Rank.Rank6 ?
                    6 : Integer.parseInt( 
                    playerProfile.getNextTrackingRank().toString().substring(4,5)) );                        
                zomaGame = new ZoMATrackingTest( gameEngine, true, playerProfile,
                    30, 1.0, 1.0, (challenge <= 3 ? "SlightCurved" : "HeavyCurved"), 
                    (int)(challenge*1.25)+1);                        
                break;
            case SniperShot:
                challenge = (playerProfile.getSniperShotRank() == Profile.Rank.Rank6 ?
                    6 : Integer.parseInt( 
                    playerProfile.getNextSniperShotRank().toString().substring(4,5)) );                        
                zomaGame = new ZoMASniperShotTest( gameEngine, true , playerProfile,
                    10, 1.0, 1.0, 1.0, "SlightCurved", (int)(challenge*1.25)+1);
                break;
        }
        
        // Activate and display the ZoMA game layer
        gameEngine.addGameLayer( zomaGame );
        zomaGame.setActivity( GameLayerActivity.ACTIVE );
        zomaGame.setVisibility( gameLayerVisibility.VISIBLE );

        // Deactivate and hide the menu layer
        this.setActivity( GameLayerActivity.INACTIVE );
        this.setVisibility( gameLayerVisibility.INVISIBLE );
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Draw methods                                                 //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the background and draw all menu elements
     */
    @Override
    public void draw( Graphics2D graphics2D ) {
        // Draw the background
        drawBackground( graphics2D );
        
        // Highlight any selected text elements
        drawInteractiveTextHighlights( graphics2D );

        // Draw all menu elements
        super.draw( graphics2D );
    }    
    
    /**
     * Draw the background, which consists of two layered, semi-
     * transparent images which are rotated and drawn on top
     * of each other.
     */    
    private void drawBackground( Graphics2D graphics2D ) {
        // Rotate the background slightly
        rotatedBackgroundRotation += 0.001;
        
        AffineTransform originalTransform = graphics2D.getTransform();        
        Composite originalComposite = graphics2D.getComposite();  

        // Create a rotation transform for the first layered image
        // and composite this on top of the existing screen
        // contents (i.e. the contents from the previous draw tick)
        AffineTransform backgroundTransform = new AffineTransform();
        backgroundTransform.rotate( -rotatedBackgroundRotation, 
                rotatedBackgroundX, rotatedBackgroundY );
        graphics2D.transform( backgroundTransform );
        graphics2D.setComposite( 
                AlphaComposite.getInstance( AlphaComposite.SRC_OVER, 
                (float)Math.abs( Math.sin( (double)gameEngine.updateCounter/360.0 )) )); 

        graphics2D.drawImage( rotatedBackground, 
                (int)( width/5.0 * Math.cos( rotatedBackgroundRotation ) + 
                    rotatedBackgroundX-rotatedBackgroundScale*rotatedBackground.getWidth()/2),
                (int)( 0.0 * Math.sin(  rotatedBackgroundRotation ) + 
                    rotatedBackgroundY-rotatedBackgroundScale*rotatedBackground.getHeight()/2),
                (int)(rotatedBackgroundScale*rotatedBackground.getWidth()),
                (int)(rotatedBackgroundScale*rotatedBackground.getHeight()), null );

        // Create a second rotational transform for the next layered image
        // and composite this on top of the existing screen
        backgroundTransform.rotate( -rotatedBackgroundRotation*0.3, 
                rotatedBackgroundX, rotatedBackgroundY );
        graphics2D.transform( backgroundTransform );
        graphics2D.setComposite( 
                AlphaComposite.getInstance( AlphaComposite.SRC_OVER, 
                (float)Math.abs( Math.cos( (double)gameEngine.updateCounter/360.0 )) )); 
        
        graphics2D.drawImage( rotatedBackground, 
                (int)( 0.0 * Math.sin( rotatedBackgroundRotation ) +
                    rotatedBackgroundX-rotatedBackgroundScale*rotatedBackground.getWidth()/2),
                (int)( this.height/5.0 * Math.cos( rotatedBackgroundRotation ) +
                    rotatedBackgroundY-rotatedBackgroundScale*rotatedBackground.getHeight()/2),
                (int)(rotatedBackgroundScale*rotatedBackground.getWidth()),
                (int)(rotatedBackgroundScale*rotatedBackground.getHeight()), null );
        
        graphics2D.setComposite( originalComposite );
        graphics2D.setTransform( originalTransform );        
    }
    
    /**
     * Provide a highlight for any interactive text elements. 
     */        
    private void drawInteractiveTextHighlights( Graphics2D graphics2D ) {
        Color originalColour = graphics2D.getColor();

        // If the mouse cursor is over any interactive text elements
        // then provide a highlight to
        GameObjectCollection interactiveText = getGameObjectCollection( "InteractiveTextElements" );
        for( int idx = 0; idx < interactiveText.size; idx++ ) {            
            Rectangle screenBound = getGameObjectScreenRectangle( interactiveText.gameObjects[idx] );            
            if( screenBound.x < inputEvent.mouseXCoordinate
                    && screenBound.y < inputEvent.mouseYCoordinate
                    && screenBound.x + screenBound.width > inputEvent.mouseXCoordinate
                    && screenBound.y + screenBound.height > inputEvent.mouseYCoordinate ) {

                graphics2D.setColor( new Color( 30, 30, 30, 200 ) );
                graphics2D.fillRect( screenBound.x, screenBound.y,
                        screenBound.width, screenBound.height );
            }
        }
        
        // If the current menu is the training menu, then highlight the current
        // session parameters
       if( currentMenu == Menu.Training ) {
            switch( trainingDisplay ) {
                case ReactionTime:
                    highlightTextElement( graphics2D, "TriggerSize"+reactionTriggerSizeScale );                        
                    highlightTextElement( graphics2D, "ChangeColour"+changeScreenColour );                        
                    highlightTextElement( graphics2D, "NumTests"+reactionNumberOfTests );
                    highlightTextElement( graphics2D, "PlaySound"+playSoundOnTargetDisplay );
                    break;
                    
                case SnapShot:
                    highlightTextElement( graphics2D, "NumTests"+snapShotNumberOfTests );                        
                    highlightTextElement( graphics2D, "MouseSpeed"+snapShotMouseMovementSpeed );                        
                    highlightTextElement( graphics2D, "TargetSize"+snapShotTargetSize );                        
                    highlightTextElement( graphics2D, "Spawn"+snapShotTargetRegion );
                    break;
                    
                case Tracking:
                    highlightTextElement( graphics2D, "Duration"+trackingDuration );                        
                    highlightTextElement( graphics2D, "MouseSpeed"+trackingMouseMovementSpeed );                        
                    highlightTextElement( graphics2D, "TargetSize"+trackingTargetSize );
                    highlightTextElement( graphics2D, "Move"+trackingMovementType );                        
                    highlightTextElement( graphics2D, "Challenge"+trackingChallenge );                        
                    break;
                    
                case SniperShot:
                    highlightTextElement( graphics2D, "Hitpoints"+sniperTargetHitPoints );                        
                    highlightTextElement( graphics2D, "MouseSpeed"+sniperMouseMovementSpeed );        
                    highlightTextElement( graphics2D, "Wobble"+sniperSightWobble );                            
                    highlightTextElement( graphics2D, "TargetSize"+sniperTargetSize );
                    highlightTextElement( graphics2D, "Move"+sniperMovementType );                        
                    highlightTextElement( graphics2D, "Challenge"+sniperChallenge );                        
                    break;
            }
        }
        
        // If the current menu is the profile menu, then highlight the current
        // profile selected by the user
        if( currentMenu == Menu.Profile ) {
            if( selectedProfileName != null ) 
                highlightTextElement( graphics2D, selectedProfileName );                                        
        }
                
        graphics2D.setColor( originalColour );                
    }

    /**
     * Provide a highlight for the specified text element
     */        
    private void highlightTextElement( Graphics2D graphics2D, String textElementName ) {        
        GameObject textElement = getGameObject( textElementName );
        if( textElement == null )
            return;
        
        Rectangle screenBound = getGameObjectScreenRectangle( textElement ); 
        graphics2D.setColor( new Color( 255, 255, 0, 128 ) );
        graphics2D.fillRect( screenBound.x, screenBound.y,
            screenBound.width, screenBound.height );                
    }    
}