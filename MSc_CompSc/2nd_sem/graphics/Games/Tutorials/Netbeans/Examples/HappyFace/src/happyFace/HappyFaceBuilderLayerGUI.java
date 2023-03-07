package happyFace;

import game.assets.*;
import game.engine.*;
import game.components.*;
import java.util.*;
import java.awt.Rectangle;
import java.awt.Graphics2D;
import java.awt.Font;
import java.awt.Color;

/**
 * HappyFaceBuilderLayerGUI provides the GUI onto the builder layer,
 * offering a number of buttons and selectable elements that control
 * how the level is to be constructed.
 * <P>
 * Note: although the logic within this class is very simple, it is
 * overly long due to the large number of defined buttons and
 * selectable elements.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class HappyFaceBuilderLayerGUI extends GameLayer {
    
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the different breaking impulses that will be used to
     * setout breaking impulses
     */
    private static final double UNBREAKABLE_IMPULSE = Double.MAX_VALUE;
    private static final double SMALL_BRICK_BREAKING_IMPULSE = 100000.0;
    private static final double LARGE_BRICK_BREAKING_IMPULSE = 300000.0;
    private static final double STONE_BREAKING_IMPULSE = 8000000.0;
    private static final double MISC_BREAKING_IMPULSE = 5000000.0;
    
    /**
     * An inner class is defined that will hold together details of
     * the currently selected block element
     */
    public class BlockType {
        
        // Array of the assets used to build up the block. If the
        // fixed order selection is set to false then the assets
        // are randomly selected from the specified asset name,
        // otherwise the assets are selected in a fixed ordered
        // based on a 2D grid specified by the fixed order width
        // and height.
        String[] assetNames;
        boolean fixedOrderSelection = false;
        int fixedOrderWidth = -1;
        int fixedOrderHeight = -1;
        
        // Flag indicating if this is a lique
        boolean liquidBlock = false;
        
        // Breaking impulse to be used for the block
        double breakingImpulse = 300000;
        
        // Create a new non-fixed order block
        BlockType(String[] assetNames, double breakingImpulse) {
            this.assetNames = assetNames;
            this.breakingImpulse = breakingImpulse;
        }
        
        // Create a new fixed order block
        BlockType(String[] assetNames, boolean fixedOrderSelection,
                int fixedOrderWidth, int fixedOrderHeight, double breakingImpulse) {
            this.assetNames = assetNames;
            this.fixedOrderSelection = fixedOrderSelection;
            this.fixedOrderWidth = fixedOrderWidth;
            this.fixedOrderHeight = fixedOrderHeight;
            this.breakingImpulse = breakingImpulse;
        }
    }
    
    /**
     * Define a hash map to be used to store the block type information
     */
    private HashMap<String, BlockType> blockTypeInfo = new HashMap<String, BlockType>();
    
    /**
     * Variables holding the currently selected block type, emoticon type,
     * interactive type, decorative type and collectable type.
     */
    private String currentBlockType;
    private String currentEmoticonType;
    private String currentInteractionType;
    private String currentDecorativeType;
    private String currentCollectableType;
    
    /**
     * Variables holding the current AI emoticon parameters
     */
    protected String aiControlChase;
    protected String aiControlMovement;
    protected String aiVisibleRange;
    protected String aiChaseRange;
    protected String aiPatrolRange;
    protected String aiJumpProbability;
    protected String aiJumpFrequency;
    
    /**
     * Flags specifying if the body outlines, grid or controls are to be drawn
     */
    private boolean drawBodyOutlines = false;
    private boolean drawGrid = false;
    private boolean drawControls = false;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new happy face builder layer GUI
     */
    public HappyFaceBuilderLayerGUI(String gameLayerName, GameEngine gameEngine) {
        super(gameLayerName, gameEngine);
        
        // Define the game object collections that will be needed
        addGameObjectCollection( "ControlButtons" );
        addGameObjectCollection( "BlockSelectionButtons" );
        addGameObjectCollection( "EmoticonSelectionButtons" );
        addGameObjectCollection( "InteractionSelectionButtons" );
        addGameObjectCollection( "DecorativeSelectionButtons" );
        addGameObjectCollection( "CollectableSelectionButtons" );
        
        addGameObjectCollection( "AIControlButtonsChase" );
        addGameObjectCollection( "AIControlButtonsMovement" );
        addGameObjectCollection( "AIControlVisibleRange" );
        addGameObjectCollection( "AIControlChaseRange" );
        addGameObjectCollection( "AIControlPatrolRange" );
        addGameObjectCollection( "AIControlJumpProbability" );
        addGameObjectCollection( "AIControlJumpFrequency" );
        
        // Build the various menu components
        buildControls();
        buildBlockSelection();
        buildEmoticonSelection();
        buildInteractableCollectableAndDecorative();
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Menu builders                                                //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Build the control menu
     */
    public void buildControls() {
        double controlsXOffset = 292.0;
        double controlsYOffset = gameEngine.screenHeight - 508.0;
        
        GameObject builderControlBackground
                = new GameObject( this, controlsXOffset, controlsYOffset, 1 );
        builderControlBackground.setRealisationAndGeometry( "BuilderControlBackground" );
        builderControlBackground.setName( "BuilderControlBackground" );
        addGameObject( builderControlBackground );
        
        buildStandardMessage( "Builder Controls", 28, controlsXOffset-120.0, controlsYOffset-225 );
        
        buildStandardMessage( "Load & Save", 22, controlsXOffset-180.0, controlsYOffset-200 );
        buildStandardButton( "BuilderLoadSlot1", "BuilderLoadSlot1", "ControlButtons", controlsXOffset-230, controlsYOffset - 170.0 );
        buildStandardButton( "BuilderLoadSlot2", "BuilderLoadSlot2", "ControlButtons", controlsXOffset-230, controlsYOffset - 140.0 );
        buildStandardButton( "BuilderLoadSlot3", "BuilderLoadSlot3", "ControlButtons", controlsXOffset-230, controlsYOffset - 110.0 );
        buildStandardButton( "BuilderSaveSlot1", "BuilderSaveSlot1", "ControlButtons", controlsXOffset-130, controlsYOffset - 170.0 );
        buildStandardButton( "BuilderSaveSlot2", "BuilderSaveSlot2", "ControlButtons", controlsXOffset-130, controlsYOffset - 140.0 );
        buildStandardButton( "BuilderSaveSlot3", "BuilderSaveSlot3", "ControlButtons", controlsXOffset-130, controlsYOffset - 110.0 );
        
        buildStandardMessage( "Move & Rotate", 22, controlsXOffset+40.0, controlsYOffset-200 );
        buildStandardButton( "ScrollUp", "BuilderUpArrow", "ControlButtons", controlsXOffset+40, controlsYOffset - 165.0 );
        buildStandardButton( "ScrollRight", "BuilderRightArrow", "ControlButtons", controlsXOffset+70, controlsYOffset - 145.0 );
        buildStandardButton( "ScrollLeft", "BuilderLeftArrow", "ControlButtons", controlsXOffset+10, controlsYOffset - 145.0 );
        buildStandardButton( "ScrollDown", "BuilderDownArrow", "ControlButtons", controlsXOffset+40, controlsYOffset - 125.0 );
        buildStandardButton( "RotateRight", "BuilderRotateRight", "ControlButtons", controlsXOffset+90, controlsYOffset - 115.0 );
        buildStandardButton( "RotateLeft", "BuilderRotateLeft", "ControlButtons", controlsXOffset-10, controlsYOffset - 115.0 );
        
        buildStandardMessage( "Draw Order", 22, controlsXOffset+200.0, controlsYOffset-200 );
        buildStandardButton( "BuilderIncreaseDrawOrder", "BuilderUpArrow", "ControlButtons", controlsXOffset+200, controlsYOffset - 165.0 );
        buildStandardButton( "BuilderDecreaseDrawOrder", "BuilderDownArrow", "ControlButtons", controlsXOffset+200, controlsYOffset - 125.0 );
        
        buildStandardMessage( "Select", 22, controlsXOffset-215.0, controlsYOffset-65 );
        buildStandardButton( "SelectAllBodies", "BuilderSelectAll", "ControlButtons", controlsXOffset-215, controlsYOffset - 40.0 );
        buildStandardButton( "UnselectAllBodies", "BuilderUnselectAll", "ControlButtons", controlsXOffset-215, controlsYOffset - 10.0 );
        
        buildStandardMessage( "Display", 22, controlsXOffset-80.0, controlsYOffset-70 );
        buildStandardToggleButton( "ToggleGrid", "BuilderControlToggleGrid", "ControlButtons", controlsXOffset-80, controlsYOffset - 40.0 );
        buildStandardToggleButton( "ToggleOutlines", "BuilderToggleOutlines", "ControlButtons", controlsXOffset-80, controlsYOffset - 10.0 );
        
        buildStandardMessage( "Merge", 22, controlsXOffset-215.0, controlsYOffset+25 );
        buildStandardButton( "MergeBodies", "BuilderMergeBodies", "ControlButtons", controlsXOffset-215, controlsYOffset + 55.0 );
        buildStandardButton( "JoinBodies", "BuilderJoinBodies", "ControlButtons", controlsXOffset-215, controlsYOffset + 85.0 );
        
        buildStandardMessage( "Delete", 22, controlsXOffset-80.0, controlsYOffset+30 );
        buildStandardButton( "DeleteJoints", "BuilderDeleteJoints", "ControlButtons", controlsXOffset-80, controlsYOffset + 55.0 );
        buildStandardButton( "DeleteBodies", "BuilderDeleteBodies", "ControlButtons", controlsXOffset-80, controlsYOffset + 85.0 );
        
        buildStandardMessage( "Type", 22, controlsXOffset-215.0, controlsYOffset+120 );
        buildStandardToggleButton( "UnbreakableBody", "BuilderUnbreakable", "ControlButtons", controlsXOffset-215, controlsYOffset + 150.0 );
        buildStandardToggleButton( "UnmovableBody", "BuilderUnmovable", "ControlButtons", controlsXOffset-215, controlsYOffset + 180.0 );
        buildStandardToggleButton( "NoninteractingBody", "BuilderNoninteracting", "ControlButtons", controlsXOffset-215, controlsYOffset + 210.0 );
        
        buildStandardButton( "BuilderFinish", "BuilderFinish", "ControlButtons", controlsXOffset-80, controlsYOffset + 210.0 );
        
        GameObject builderKeyControls = new GameObject( this, controlsXOffset+140.0, controlsYOffset+70.0, 2 );
        builderKeyControls.setRealisation( "BuilderKeyControls" );
        addGameObject( builderKeyControls );
    }
    
    /**
     * Build the block selection menu
     */
    private void buildBlockSelection() {
        double blockSelectionXOffset = 755.0;
        double blockSelectionYOffset = gameEngine.screenHeight - 382.0;
        
        GameObject builderBlockSelectionBackground
                = new GameObject( this, blockSelectionXOffset, blockSelectionYOffset, 1 );
        builderBlockSelectionBackground.setRealisationAndGeometry( "BuilderPanelBackground" );
        builderBlockSelectionBackground.setName( "BuilderBlockSelectionBackground" );
        addGameObject( builderBlockSelectionBackground );
        
        buildStandardMessage( "Brick Sets", 22, blockSelectionXOffset, blockSelectionYOffset-360.0 );
        
        buildBrickSet( "A", 7, blockSelectionXOffset-135.0, blockSelectionYOffset-337.0 ).setSelected(true);
        buildBrickSet( "B", 6, blockSelectionXOffset-100.0, blockSelectionYOffset-337.0 );
        buildBrickSet( "C", 6, blockSelectionXOffset-65.0, blockSelectionYOffset-337.0 );
        buildBrickSet( "D", 6, blockSelectionXOffset-30.0, blockSelectionYOffset-337.0 );
        buildBrickSet( "E", 4, blockSelectionXOffset+5.0, blockSelectionYOffset-337.0 );
        buildBrickSet( "F", 4, blockSelectionXOffset+40.0, blockSelectionYOffset-337.0 );
        buildBrickSet( "G", 5, blockSelectionXOffset+75.0, blockSelectionYOffset-337.0 );
        buildBrickSet( "H", 6, blockSelectionXOffset+110.0, blockSelectionYOffset-337.0 );
        
        buildBrickSet( "I", 6, blockSelectionXOffset-135.0, blockSelectionYOffset-304.0 );
        buildBrickSet( "J", 5, blockSelectionXOffset-100.0, blockSelectionYOffset-304.0 );
        buildBrickSet( "K", 5, blockSelectionXOffset-65.0, blockSelectionYOffset-304.0 );
        buildBrickSet( "L", 6, blockSelectionXOffset-30.0, blockSelectionYOffset-304.0 );
        buildBrickSet( "M", 6, blockSelectionXOffset+5.0, blockSelectionYOffset-304.0 );
        buildBrickSet( "N", 5, blockSelectionXOffset+40.0, blockSelectionYOffset-304.0 );
        buildBrickSet( "O", 3, blockSelectionXOffset+75.0, blockSelectionYOffset-304.0 );
        buildBrickSet( "P", 5, blockSelectionXOffset+110.0, blockSelectionYOffset-304.0 );
        
        currentBlockType = "BrickSetA";
        
        buildStandardMessage( "Brick Tiles", 22, blockSelectionXOffset, blockSelectionYOffset-275.0 );
        
        buildTextureButton44( "BrickTextureA", blockSelectionXOffset - 140.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureB", blockSelectionXOffset - 100.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureC", blockSelectionXOffset - 60.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureD", blockSelectionXOffset - 20.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureE", blockSelectionXOffset + 20.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureF", blockSelectionXOffset + 60.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureG", blockSelectionXOffset + 100.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureH", blockSelectionXOffset + 140.0, blockSelectionYOffset -245.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureI", blockSelectionXOffset - 140.0, blockSelectionYOffset -207.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureJ", blockSelectionXOffset - 100.0, blockSelectionYOffset -207.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureK", blockSelectionXOffset - 60.0, blockSelectionYOffset -207.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureL", blockSelectionXOffset - 20.0, blockSelectionYOffset -207.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureM", blockSelectionXOffset + 20.0, blockSelectionYOffset -207.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureN", blockSelectionXOffset + 60.0, blockSelectionYOffset -207.0, LARGE_BRICK_BREAKING_IMPULSE );
        buildTextureButton44( "BrickTextureO", blockSelectionXOffset + 100.0, blockSelectionYOffset -207.0, LARGE_BRICK_BREAKING_IMPULSE );
        
        buildStandardMessage( "Stone Tiles", 22, blockSelectionXOffset, blockSelectionYOffset-170.0 );
        
        buildTextureButton44( "StoneTextureA", blockSelectionXOffset - 140.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureB", blockSelectionXOffset - 100.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureC", blockSelectionXOffset - 60.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureD", blockSelectionXOffset - 20.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureE", blockSelectionXOffset + 20.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureF", blockSelectionXOffset + 60.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureG", blockSelectionXOffset + 100.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureH", blockSelectionXOffset + 140.0, blockSelectionYOffset -140.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureI", blockSelectionXOffset - 140.0, blockSelectionYOffset -102.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureJ", blockSelectionXOffset - 100.0, blockSelectionYOffset -102.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureK", blockSelectionXOffset - 60.0, blockSelectionYOffset -102.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureL", blockSelectionXOffset - 20.0, blockSelectionYOffset -102.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureM", blockSelectionXOffset + 20.0, blockSelectionYOffset -102.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureN", blockSelectionXOffset + 60.0, blockSelectionYOffset -102.0, STONE_BREAKING_IMPULSE );
        buildTextureButton44( "StoneTextureO", blockSelectionXOffset + 100.0, blockSelectionYOffset -102.0, STONE_BREAKING_IMPULSE );
        
        buildStandardMessage( "Background Tiles", 22, blockSelectionXOffset, blockSelectionYOffset-68.0 );
        
        buildTextureButton11( "BackgroundTile1", blockSelectionXOffset - 140.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile2", blockSelectionXOffset - 100.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile3", blockSelectionXOffset - 60.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile4", blockSelectionXOffset - 20.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile5", blockSelectionXOffset + 20.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile6", blockSelectionXOffset + 60.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile7", blockSelectionXOffset + 100.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile8", blockSelectionXOffset + 140.0, blockSelectionYOffset -35.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile9", blockSelectionXOffset - 140.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile10", blockSelectionXOffset - 100.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile11", blockSelectionXOffset - 60.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile12", blockSelectionXOffset - 20.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile13", blockSelectionXOffset + 20.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile14", blockSelectionXOffset + 60.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile15", blockSelectionXOffset + 100.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile16", blockSelectionXOffset + 140.0, blockSelectionYOffset +5.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile17", blockSelectionXOffset - 140.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile18", blockSelectionXOffset - 100.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile19", blockSelectionXOffset - 60.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile20", blockSelectionXOffset - 20.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile21", blockSelectionXOffset + 20.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile22", blockSelectionXOffset + 60.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile23", blockSelectionXOffset + 100.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile24", blockSelectionXOffset + 140.0, blockSelectionYOffset +45.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile25", blockSelectionXOffset - 140.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile26", blockSelectionXOffset - 100.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile27", blockSelectionXOffset - 60.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile28", blockSelectionXOffset - 20.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile29", blockSelectionXOffset + 20.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile30", blockSelectionXOffset + 60.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile31", blockSelectionXOffset + 100.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "BackgroundTile32", blockSelectionXOffset + 140.0, blockSelectionYOffset +85.0, false, UNBREAKABLE_IMPULSE );
        
        buildStandardMessage( "Miscellaneous", 22, blockSelectionXOffset, blockSelectionYOffset+123.0 );
        
        buildTextureButton44( "MiscTextureA", blockSelectionXOffset - 140.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureB", blockSelectionXOffset - 100.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureC", blockSelectionXOffset - 60.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureD", blockSelectionXOffset - 20.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureE", blockSelectionXOffset + 20.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureF", blockSelectionXOffset + 60.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureG", blockSelectionXOffset + 100.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureH", blockSelectionXOffset + 140.0, blockSelectionYOffset + 149.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureI", blockSelectionXOffset - 140.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureJ", blockSelectionXOffset - 100.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureK", blockSelectionXOffset - 60.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureL", blockSelectionXOffset - 20.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureM", blockSelectionXOffset + 20.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureN", blockSelectionXOffset + 60.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureO", blockSelectionXOffset + 100.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureP", blockSelectionXOffset + 140.0, blockSelectionYOffset + 187.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureQ", blockSelectionXOffset - 140.0, blockSelectionYOffset + 225.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureR", blockSelectionXOffset - 100.0, blockSelectionYOffset + 225.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureS", blockSelectionXOffset - 60.0, blockSelectionYOffset + 225.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureT", blockSelectionXOffset - 20.0, blockSelectionYOffset + 225.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureU", blockSelectionXOffset + 20.0, blockSelectionYOffset + 225.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureV", blockSelectionXOffset + 60.0, blockSelectionYOffset + 225.0, MISC_BREAKING_IMPULSE );
        buildTextureButton44( "MiscTextureW", blockSelectionXOffset + 100.0, blockSelectionYOffset + 225.0, MISC_BREAKING_IMPULSE );
        
        buildStandardMessage( "Edgings", 22, blockSelectionXOffset, blockSelectionYOffset+257.0 );
        
        buildTextureButton31( "StoneTextureAEdging", blockSelectionXOffset - 140.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureBEdging", blockSelectionXOffset - 100.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureCEdging", blockSelectionXOffset - 60.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureDEdging", blockSelectionXOffset - 20.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureEEdging", blockSelectionXOffset + 20.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureFEdging", blockSelectionXOffset + 60.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureGEdging", blockSelectionXOffset + 100.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureHEdging", blockSelectionXOffset + 140.0, blockSelectionYOffset + 280.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureIEdging", blockSelectionXOffset - 140.0, blockSelectionYOffset + 295.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureJEdging", blockSelectionXOffset - 100.0, blockSelectionYOffset + 295.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureKEdging", blockSelectionXOffset - 60.0, blockSelectionYOffset + 295.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureLEdging", blockSelectionXOffset - 20.0, blockSelectionYOffset + 295.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureMEdging", blockSelectionXOffset + 20.0, blockSelectionYOffset + 295.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureNEdging", blockSelectionXOffset + 60.0, blockSelectionYOffset + 295.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "StoneTextureOEdging", blockSelectionXOffset + 100.0, blockSelectionYOffset + 295.0, SMALL_BRICK_BREAKING_IMPULSE );
        
        buildTextureButton31( "MiscTextureAEdging", blockSelectionXOffset - 140.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureBEdging", blockSelectionXOffset - 100.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureCEdging", blockSelectionXOffset - 60.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureDEdging", blockSelectionXOffset - 20.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureEEdging", blockSelectionXOffset + 20.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureFEdging", blockSelectionXOffset + 60.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureGEdging", blockSelectionXOffset + 100.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureHEdging", blockSelectionXOffset + 140.0, blockSelectionYOffset + 310.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureIEdging", blockSelectionXOffset - 140.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureJEdging", blockSelectionXOffset - 100.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureKEdging", blockSelectionXOffset - 60.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureLEdging", blockSelectionXOffset - 20.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureMEdging", blockSelectionXOffset + 20.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureNEdging", blockSelectionXOffset + 60.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureOEdging", blockSelectionXOffset + 100.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTexturePEdging", blockSelectionXOffset + 140.0, blockSelectionYOffset + 325.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureQEdging", blockSelectionXOffset - 140.0, blockSelectionYOffset + 340.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureREdging", blockSelectionXOffset - 100.0, blockSelectionYOffset + 340.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureSEdging", blockSelectionXOffset - 60.0, blockSelectionYOffset + 340.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureTEdging", blockSelectionXOffset - 20.0, blockSelectionYOffset + 340.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureUEdging", blockSelectionXOffset + 20.0, blockSelectionYOffset + 340.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureVEdging", blockSelectionXOffset + 60.0, blockSelectionYOffset + 340.0, SMALL_BRICK_BREAKING_IMPULSE );
        buildTextureButton31( "MiscTextureWEdging", blockSelectionXOffset + 100.0, blockSelectionYOffset + 340.0, SMALL_BRICK_BREAKING_IMPULSE );
    }
    
    /**
     * Build the emoticon selection menu
     */
    private void buildEmoticonSelection() {
        double spriteSelectionXOffset = 292.0;
        double spriteSelectionYOffset = gameEngine.screenHeight - 128.0;
        
        GameObject builderControlSpriteBackground
                = new GameObject( this, spriteSelectionXOffset, spriteSelectionYOffset, 1 );
        builderControlSpriteBackground.setRealisationAndGeometry( "BuilderControlEmoticonBackground" );
        builderControlSpriteBackground.setName( "BuilderControlSpriteBackground" );
        addGameObject( builderControlSpriteBackground );
        
        buildStandardMessage( "Emoticons", 28, spriteSelectionXOffset-160.0, spriteSelectionYOffset-100.0 );
        
        buildStandardMessage( "Movement", 18, spriteSelectionXOffset-225.0, spriteSelectionYOffset-75.0 );
        buildStandardToggleButton( "BuilderAIStationary", "BuilderAIStationary", "AIControlButtonsMovement", spriteSelectionXOffset - 225.0, spriteSelectionYOffset - 55.0 );
        buildStandardToggleButton( "BuilderAIPatrol", "BuilderAIPatrol", "AIControlButtonsMovement", spriteSelectionXOffset - 225.0, spriteSelectionYOffset - 35.0 );
        aiControlMovement = "BuilderAIStationary";
        ((ToggleButton)getGameObject( "BuilderAIStationary" )).setSelected( true );
        
        buildStandardMessage( "Chase", 18, spriteSelectionXOffset-120.0, spriteSelectionYOffset-75.0 );
        buildStandardToggleButton( "BuilderAIIgnore", "BuilderAIIgnore", "AIControlButtonsChase", spriteSelectionXOffset - 120.0, spriteSelectionYOffset - 55.0 );
        buildStandardToggleButton( "BuilderAIChase", "BuilderAIChase", "AIControlButtonsChase", spriteSelectionXOffset - 120.0, spriteSelectionYOffset - 35.0 );
        aiControlChase = "BuilderAIIgnore";
        ((ToggleButton)getGameObject( "BuilderAIIgnore" )).setSelected( true );
        
        buildStandardMessage( "Visible Rng", 18, spriteSelectionXOffset-65.0, spriteSelectionYOffset-10.0 );
        buildStandardToggleButton( "BuilderAIVisibleRangeXS", "BuilderXS", "AIControlVisibleRange", spriteSelectionXOffset - 260.0, spriteSelectionYOffset - 10.0 );
        buildStandardToggleButton( "BuilderAIVisibleRangeS", "BuilderS", "AIControlVisibleRange", spriteSelectionXOffset - 230.0, spriteSelectionYOffset - 10.0 );
        buildStandardToggleButton( "BuilderAIVisibleRangeM", "BuilderM", "AIControlVisibleRange", spriteSelectionXOffset - 200.0, spriteSelectionYOffset - 10.0 );
        buildStandardToggleButton( "BuilderAIVisibleRangeL", "BuilderL", "AIControlVisibleRange", spriteSelectionXOffset - 170.0, spriteSelectionYOffset - 10.0 );
        buildStandardToggleButton( "BuilderAIVisibleRangeXL", "BuilderXL", "AIControlVisibleRange", spriteSelectionXOffset - 140.0, spriteSelectionYOffset - 10.0 );
        aiVisibleRange = "BuilderAIVisibleRangeM";
        ((ToggleButton)getGameObject( "BuilderAIVisibleRangeM" )).setSelected( true );
        
        buildStandardMessage( "Chase Rng", 18, spriteSelectionXOffset-65.0, spriteSelectionYOffset+15.0 );
        buildStandardToggleButton( "BuilderAIChaseRangeXS", "BuilderXS", "AIControlChaseRange", spriteSelectionXOffset - 260.0, spriteSelectionYOffset + 15.0 );
        buildStandardToggleButton( "BuilderAIChaseRangeS", "BuilderS", "AIControlChaseRange", spriteSelectionXOffset - 230.0, spriteSelectionYOffset + 15.0 );
        buildStandardToggleButton( "BuilderAIChaseRangeM", "BuilderM", "AIControlChaseRange", spriteSelectionXOffset - 200.0, spriteSelectionYOffset + 15.0 );
        buildStandardToggleButton( "BuilderAIChaseRangeL", "BuilderL", "AIControlChaseRange", spriteSelectionXOffset - 170.0, spriteSelectionYOffset + 15.0 );
        buildStandardToggleButton( "BuilderAIChaseRangeXL", "BuilderXL", "AIControlChaseRange", spriteSelectionXOffset - 140.0, spriteSelectionYOffset + 15.0 );
        aiChaseRange = "BuilderAIChaseRangeM";
        ((ToggleButton)getGameObject( "BuilderAIChaseRangeM" )).setSelected( true );
        
        buildStandardMessage( "Patrol Rng", 18, spriteSelectionXOffset-65.0, spriteSelectionYOffset+35.0 );
        buildStandardToggleButton( "BuilderAIPatrolRangeXS", "BuilderXS", "AIControlPatrolRange", spriteSelectionXOffset - 260.0, spriteSelectionYOffset + 35.0 );
        buildStandardToggleButton( "BuilderAIPatrolRangeS", "BuilderS", "AIControlPatrolRange", spriteSelectionXOffset - 230.0, spriteSelectionYOffset + 35.0 );
        buildStandardToggleButton( "BuilderAIPatrolRangeM", "BuilderM", "AIControlPatrolRange", spriteSelectionXOffset - 200.0, spriteSelectionYOffset + 35.0 );
        buildStandardToggleButton( "BuilderAIPatrolRangeL", "BuilderL", "AIControlPatrolRange", spriteSelectionXOffset - 170.0, spriteSelectionYOffset + 35.0 );
        buildStandardToggleButton( "BuilderAIPatrolRangeXL", "BuilderXL", "AIControlPatrolRange", spriteSelectionXOffset - 140.0, spriteSelectionYOffset + 35.0 );
        aiPatrolRange = "BuilderAIPatrolRangeM";
        ((ToggleButton)getGameObject( "BuilderAIPatrolRangeM" )).setSelected( true );
        
        buildStandardMessage( "Jump Prob", 18, spriteSelectionXOffset-67.0, spriteSelectionYOffset+60.0 );
        buildStandardToggleButton( "BuilderAIJumpProbabilityXS", "BuilderXS", "AIControlJumpProbability", spriteSelectionXOffset - 260.0, spriteSelectionYOffset + 60.0 );
        buildStandardToggleButton( "BuilderAIJumpProbabilityS", "BuilderS", "AIControlJumpProbability", spriteSelectionXOffset - 230.0, spriteSelectionYOffset + 60.0 );
        buildStandardToggleButton( "BuilderAIJumpProbabilityM", "BuilderM", "AIControlJumpProbability", spriteSelectionXOffset - 200.0, spriteSelectionYOffset + 60.0 );
        buildStandardToggleButton( "BuilderAIJumpProbabilityL", "BuilderL", "AIControlJumpProbability", spriteSelectionXOffset - 170.0, spriteSelectionYOffset + 60.0 );
        buildStandardToggleButton( "BuilderAIJumpProbabilityXL", "BuilderXL", "AIControlJumpProbability", spriteSelectionXOffset - 140.0, spriteSelectionYOffset + 60.0 );
        aiJumpProbability = "BuilderAIJumpProbabilityM";
        ((ToggleButton)getGameObject( "BuilderAIJumpProbabilityM" )).setSelected( true );
        
        buildStandardMessage( "Jump Freq", 18, spriteSelectionXOffset-67.0, spriteSelectionYOffset+80.0 );
        buildStandardToggleButton( "BuilderAIJumpFrequencyXS", "BuilderXS", "AIControlJumpFrequency", spriteSelectionXOffset - 260.0, spriteSelectionYOffset + 80.0 );
        buildStandardToggleButton( "BuilderAIJumpFrequencyS", "BuilderS", "AIControlJumpFrequency", spriteSelectionXOffset - 230.0, spriteSelectionYOffset + 80.0 );
        buildStandardToggleButton( "BuilderAIJumpFrequencyM", "BuilderM", "AIControlJumpFrequency", spriteSelectionXOffset - 200.0, spriteSelectionYOffset + 80.0 );
        buildStandardToggleButton( "BuilderAIJumpFrequencyL", "BuilderL", "AIControlJumpFrequency", spriteSelectionXOffset - 170.0, spriteSelectionYOffset + 80.0 );
        buildStandardToggleButton( "BuilderAIJumpFrequencyXL", "BuilderXL", "AIControlJumpFrequency", spriteSelectionXOffset - 140.0, spriteSelectionYOffset + 80.0 );
        aiJumpFrequency = "BuilderAIJumpFrequencyM";
        ((ToggleButton)getGameObject( "BuilderAIJumpFrequencyM" )).setSelected( true );
        
        buildBasicToggleButton( "EmoticonSetAHappy1", "EmoticonSetAHappy1", "EmoticonSelectionButtons", spriteSelectionXOffset + 15.0, spriteSelectionYOffset - 80.0 );
        buildBasicToggleButton( "EmoticonSetAHappy2", "EmoticonSetAHappy2", "EmoticonSelectionButtons", spriteSelectionXOffset + 15.0, spriteSelectionYOffset - 40.0 );
        buildBasicToggleButton( "EmoticonSetAHappy3", "EmoticonSetAHappy3", "EmoticonSelectionButtons", spriteSelectionXOffset + 15.0, spriteSelectionYOffset + 00.0 );
        buildBasicToggleButton( "EmoticonSetAHappy4", "EmoticonSetAHappy4", "EmoticonSelectionButtons", spriteSelectionXOffset + 15.0, spriteSelectionYOffset + 40.0 );
        buildBasicToggleButton( "EmoticonSetAUnhappy", "EmoticonSetAUnhappy", "EmoticonSelectionButtons", spriteSelectionXOffset + 15.0, spriteSelectionYOffset + 80.0 );
        
        buildBasicToggleButton( "EmoticonSetBHappy1", "EmoticonSetBHappy1", "EmoticonSelectionButtons", spriteSelectionXOffset + 65.0, spriteSelectionYOffset - 80.0 );
        buildBasicToggleButton( "EmoticonSetBHappy2", "EmoticonSetBHappy2", "EmoticonSelectionButtons", spriteSelectionXOffset + 65.0, spriteSelectionYOffset - 40.0 );
        buildBasicToggleButton( "EmoticonSetBHappy3", "EmoticonSetBHappy3", "EmoticonSelectionButtons", spriteSelectionXOffset + 65.0, spriteSelectionYOffset + 00.0 );
        buildBasicToggleButton( "EmoticonSetBHappy4", "EmoticonSetBHappy4", "EmoticonSelectionButtons", spriteSelectionXOffset + 65.0, spriteSelectionYOffset + 40.0 );
        buildBasicToggleButton( "EmoticonSetBUnhappy", "EmoticonSetBUnhappy", "EmoticonSelectionButtons", spriteSelectionXOffset + 65.0, spriteSelectionYOffset + 80.0 );
        
        buildBasicToggleButton( "EmoticonSetCHappy1", "EmoticonSetCHappy1", "EmoticonSelectionButtons", spriteSelectionXOffset + 115.0, spriteSelectionYOffset - 80.0 );
        buildBasicToggleButton( "EmoticonSetCHappy2", "EmoticonSetCHappy2", "EmoticonSelectionButtons", spriteSelectionXOffset + 115.0, spriteSelectionYOffset - 40.0 );
        buildBasicToggleButton( "EmoticonSetCHappy3", "EmoticonSetCHappy3", "EmoticonSelectionButtons", spriteSelectionXOffset + 115.0, spriteSelectionYOffset + 00.0 );
        buildBasicToggleButton( "EmoticonSetCHappy4", "EmoticonSetCHappy4", "EmoticonSelectionButtons", spriteSelectionXOffset + 115.0, spriteSelectionYOffset + 40.0 );
        buildBasicToggleButton( "EmoticonSetCUnhappy", "EmoticonSetCUnhappy", "EmoticonSelectionButtons", spriteSelectionXOffset + 115.0, spriteSelectionYOffset + 80.0 );
        
        buildBasicToggleButton( "EmoticonSetDHappy1", "EmoticonSetDHappy1", "EmoticonSelectionButtons", spriteSelectionXOffset + 165.0, spriteSelectionYOffset - 80.0 );
        buildBasicToggleButton( "EmoticonSetDHappy2", "EmoticonSetDHappy2", "EmoticonSelectionButtons", spriteSelectionXOffset + 165.0, spriteSelectionYOffset - 40.0 );
        buildBasicToggleButton( "EmoticonSetDHappy3", "EmoticonSetDHappy3", "EmoticonSelectionButtons", spriteSelectionXOffset + 165.0, spriteSelectionYOffset + 00.0 );
        buildBasicToggleButton( "EmoticonSetDHappy4", "EmoticonSetDHappy4", "EmoticonSelectionButtons", spriteSelectionXOffset + 165.0, spriteSelectionYOffset + 40.0 );
        buildBasicToggleButton( "EmoticonSetDUnhappy", "EmoticonSetDUnhappy", "EmoticonSelectionButtons", spriteSelectionXOffset + 165.0, spriteSelectionYOffset + 80.0 );
        
        buildBasicToggleButton( "EmoticonAngel", "EmoticonAngel", "EmoticonSelectionButtons", spriteSelectionXOffset + 215.0, spriteSelectionYOffset - 20.0 );
        buildBasicToggleButton( "EmoticonGhost", "EmoticonGhost", "EmoticonSelectionButtons", spriteSelectionXOffset + 260.0, spriteSelectionYOffset - 20.0 );
        buildBasicToggleButton( "EmoticonDevil", "EmoticonDevil", "EmoticonSelectionButtons", spriteSelectionXOffset + 215.0, spriteSelectionYOffset - 60.0 );
        buildBasicToggleButton( "EmoticonFloater", "EmoticonFloater", "EmoticonSelectionButtons", spriteSelectionXOffset + 260.0, spriteSelectionYOffset - 60.0 );
        buildBasicToggleButton( "EmoticonDestroyer", "EmoticonDestroyerIcon", "EmoticonSelectionButtons", spriteSelectionXOffset + 205.0, spriteSelectionYOffset + 50.0 );
        buildBasicToggleButton( "EmoticonBoss", "EmoticonBossIcon", "EmoticonSelectionButtons", spriteSelectionXOffset + 250.0, spriteSelectionYOffset + 50.0 );
        
        ToggleButton initialEmoticon = (ToggleButton)getGameObject( "EmoticonDevil" );
        initialEmoticon.setSelected( true );
        currentEmoticonType = initialEmoticon.getName();
    }
    
    /**
     * Builder interactive, collectable and decorative elements
     */
    private void buildInteractableCollectableAndDecorative() {
        double interactionXOffset = 1100.0;
        double interactionYOffset = gameEngine.screenHeight - 382.0;
        
        GameObject builderBouncerBackground
                = new GameObject( this, interactionXOffset, interactionYOffset, 1 );
        builderBouncerBackground.setRealisationAndGeometry( "BuilderPanelBackground" );
        builderBouncerBackground.setName( "BuilderInteractionBackground" );
        addGameObject( builderBouncerBackground );
        
        buildStandardMessage( "Interactive", 22, interactionXOffset, interactionYOffset-335 );
        
        buildBasicToggleButton( "BouncerBeam1", "BouncerBeam1Icon", "InteractionSelectionButtons", interactionXOffset - 130.0, interactionYOffset - 305.0 );
        buildBasicToggleButton( "BouncerBeam2", "BouncerBeam2Icon", "InteractionSelectionButtons", interactionXOffset - 70.0, interactionYOffset - 305.0 );
        buildBasicToggleButton( "BouncerBeam3", "BouncerBeam3Icon", "InteractionSelectionButtons", interactionXOffset - 10.0, interactionYOffset - 305.0 );
        buildBasicToggleButton( "BouncerBeam4", "BouncerBeam4Icon", "InteractionSelectionButtons", interactionXOffset + 50.0, interactionYOffset - 305.0 );
        
        buildBasicToggleButton( "BouncerBlock1", "BouncerBlock1Icon", "InteractionSelectionButtons", interactionXOffset - 135.0, interactionYOffset - 270.0 );
        buildBasicToggleButton( "BouncerBlock2", "BouncerBlock2Icon", "InteractionSelectionButtons",interactionXOffset - 95.0, interactionYOffset - 270.0 );
        buildBasicToggleButton( "BouncerBlock3", "BouncerBlock3Icon", "InteractionSelectionButtons", interactionXOffset - 55.0, interactionYOffset - 270.0 );
        buildBasicToggleButton( "BouncerBlock4", "BouncerBlock4Icon", "InteractionSelectionButtons", interactionXOffset - 15.0, interactionYOffset - 270.0 );
        
        buildBasicToggleButton( "BouncerCircle1", "BouncerCircle1Icon", "InteractionSelectionButtons", interactionXOffset - 135.0, interactionYOffset - 230.0 );
        buildBasicToggleButton( "BouncerCircle2", "BouncerCircle2Icon", "InteractionSelectionButtons", interactionXOffset - 95.0, interactionYOffset - 230.0 );
        buildBasicToggleButton( "BouncerCircle3", "BouncerCircle3Icon", "InteractionSelectionButtons", interactionXOffset - 55.0, interactionYOffset - 230.0 );
        buildBasicToggleButton( "BouncerCircle4", "BouncerCircle4Icon", "InteractionSelectionButtons", interactionXOffset - 15.0, interactionYOffset - 230.0 );
        buildBasicToggleButton( "BouncerCircle5", "BouncerCircle5Icon", "InteractionSelectionButtons", interactionXOffset + 25.0, interactionYOffset - 230.0 );
        buildBasicToggleButton( "BouncerCircle6", "BouncerCircle6Icon", "InteractionSelectionButtons", interactionXOffset + 65.0, interactionYOffset - 230.0 );
        buildBasicToggleButton( "BouncerCircle7", "BouncerCircle7Icon", "InteractionSelectionButtons", interactionXOffset + 105.0, interactionYOffset - 230.0 );
        buildBasicToggleButton( "BouncerCircle8", "BouncerCircle8Icon", "InteractionSelectionButtons", interactionXOffset + 145.0, interactionYOffset - 230.0 );
        
        buildBasicToggleButton( "SpikyBall1", "SpikyBall1Icon", "InteractionSelectionButtons", interactionXOffset - 135.0, interactionYOffset - 190.0 );
        buildBasicToggleButton( "SpikyBall2", "SpikyBall2Icon", "InteractionSelectionButtons", interactionXOffset - 95.0, interactionYOffset - 190.0 );
        buildBasicToggleButton( "SpikyColumn1", "SpikyColumn1Icon", "InteractionSelectionButtons", interactionXOffset - 55.0, interactionYOffset - 190.0 );
        buildBasicToggleButton( "SpikyColumn2", "SpikyColumn2Icon", "InteractionSelectionButtons", interactionXOffset - 15.0, interactionYOffset - 190.0 );
        buildBasicToggleButton( "SpikyColumn3", "SpikyColumn3Icon", "InteractionSelectionButtons", interactionXOffset + 25.0, interactionYOffset - 190.0 );
        buildBasicToggleButton( "SpikyColumn4", "SpikyColumn4Icon", "InteractionSelectionButtons", interactionXOffset + 65.0, interactionYOffset - 190.0 );
        buildBasicToggleButton( "SpikyPlatform1", "SpikyPlatform1Icon", "InteractionSelectionButtons", interactionXOffset + 105.0, interactionYOffset - 190.0 );
        buildBasicToggleButton( "SpikyPlatform2", "SpikyPlatform2Icon", "InteractionSelectionButtons", interactionXOffset + 145.0, interactionYOffset - 190.0 );
        
        buildTextureButton11( "PoolAcid1", interactionXOffset - 135.0, interactionYOffset - 150.0, true, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "PoolAcid2", interactionXOffset - 95.0, interactionYOffset - 150.0, true, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "PoolLava1", interactionXOffset - 55.0, interactionYOffset - 150.0, true, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "PoolLava2", interactionXOffset - 15.0, interactionYOffset - 150.0, true, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "PoolWater1", interactionXOffset + 25.0, interactionYOffset - 150.0, true, UNBREAKABLE_IMPULSE );
        buildTextureButton11( "PoolWater2", interactionXOffset + 65.0, interactionYOffset - 150.0, true, UNBREAKABLE_IMPULSE );
        
        buildStandardMessage( "Decoration", 22, interactionXOffset, interactionYOffset-100.0 );
        
        buildBasicToggleButton( "Column1", "Column1Icon", "DecorativeSelectionButtons", interactionXOffset - 135.0, interactionYOffset -60.0 );
        buildBasicToggleButton( "Column2", "Column2Icon", "DecorativeSelectionButtons", interactionXOffset - 120.0, interactionYOffset -60.0 );
        buildBasicToggleButton( "Column3", "Column3Icon", "DecorativeSelectionButtons", interactionXOffset - 105.0, interactionYOffset -60.0 );
        buildBasicToggleButton( "Column4", "Column4Icon", "DecorativeSelectionButtons", interactionXOffset - 90.0, interactionYOffset -60.0 );
        buildBasicToggleButton( "Column5", "Column5Icon", "DecorativeSelectionButtons", interactionXOffset - 75.0, interactionYOffset -60.0 );
        
        buildBasicToggleButton( "Grass1", "Grass1Icon", "DecorativeSelectionButtons", interactionXOffset - 30.0, interactionYOffset -60.0 );
        buildBasicToggleButton( "Grass2", "Grass2Icon", "DecorativeSelectionButtons", interactionXOffset + 20.0, interactionYOffset -60.0 );
        buildBasicToggleButton( "Grass3", "Grass3Icon", "DecorativeSelectionButtons", interactionXOffset + 60.0, interactionYOffset -60.0 );
        
        buildBasicToggleButton( "Cloud1", "Cloud1Icon", "DecorativeSelectionButtons", interactionXOffset + 100.0, interactionYOffset -60.0 );
        buildBasicToggleButton( "Sun1", "Sun1Icon", "DecorativeSelectionButtons", interactionXOffset + 140.0, interactionYOffset - 60.0 );
        
        buildBasicToggleButton( "Tree1", "Tree1Icon", "DecorativeSelectionButtons", interactionXOffset - 140.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree2", "Tree2Icon", "DecorativeSelectionButtons", interactionXOffset - 110.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree3", "Tree3Icon", "DecorativeSelectionButtons", interactionXOffset - 80.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree4", "Tree4Icon", "DecorativeSelectionButtons", interactionXOffset - 50.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree5", "Tree5Icon", "DecorativeSelectionButtons", interactionXOffset - 20.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree6", "Tree6Icon", "DecorativeSelectionButtons", interactionXOffset + 10.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree7", "Tree7Icon", "DecorativeSelectionButtons", interactionXOffset + 40.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree8", "Tree8Icon", "DecorativeSelectionButtons", interactionXOffset + 70.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree9", "Tree9Icon", "DecorativeSelectionButtons", interactionXOffset + 100.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree10", "Tree10Icon", "DecorativeSelectionButtons", interactionXOffset + 130.0, interactionYOffset -10.0 );
        buildBasicToggleButton( "Tree11", "Tree11Icon", "DecorativeSelectionButtons", interactionXOffset - 140.0, interactionYOffset + 40.0 );
        buildBasicToggleButton( "Tree12", "Tree12Icon", "DecorativeSelectionButtons", interactionXOffset - 110.0, interactionYOffset + 40.0 );
        buildBasicToggleButton( "Tree13", "Tree13Icon", "DecorativeSelectionButtons", interactionXOffset - 80.0, interactionYOffset + 40.0 );
        buildBasicToggleButton( "Tree14", "Tree14Icon", "DecorativeSelectionButtons", interactionXOffset - 50.0, interactionYOffset + 40.0 );
        
        buildBasicToggleButton( "Barrel1", "Barrel1Icon", "DecorativeSelectionButtons", interactionXOffset - 20.0, interactionYOffset + 40.0 );
        
        buildBasicToggleButton( "Flower1", "Flower1Icon", "DecorativeSelectionButtons", interactionXOffset - 140.0, interactionYOffset + 80.0 );
        buildBasicToggleButton( "Flower2", "Flower2Icon", "DecorativeSelectionButtons", interactionXOffset - 100.0, interactionYOffset + 80.0 );
        buildBasicToggleButton( "Flower3", "Flower3Icon", "DecorativeSelectionButtons", interactionXOffset - 60.0, interactionYOffset + 80.0 );
        buildBasicToggleButton( "Flower4", "Flower4Icon", "DecorativeSelectionButtons", interactionXOffset - 20.0, interactionYOffset + 80.0 );
        buildBasicToggleButton( "Flower5", "Flower5Icon", "DecorativeSelectionButtons", interactionXOffset + 20.0, interactionYOffset + 80.0 );
        buildBasicToggleButton( "Flower6", "Flower6Icon", "DecorativeSelectionButtons", interactionXOffset + 60.0, interactionYOffset + 80.0 );
        
        buildBasicToggleButton( "FlowerOpen1", "FlowerOpen1Icon", "DecorativeSelectionButtons", interactionXOffset + 100.0, interactionYOffset + 80.0 );
        buildBasicToggleButton( "FlowerOpen2", "FlowerOpen2Icon", "DecorativeSelectionButtons", interactionXOffset + 140.0, interactionYOffset + 80.0 );
        buildBasicToggleButton( "FlowerOpen3", "FlowerOpen3Icon", "DecorativeSelectionButtons", interactionXOffset - 140.0, interactionYOffset + 130.0 );
        buildBasicToggleButton( "FlowerOpen4", "FlowerOpen4Icon", "DecorativeSelectionButtons", interactionXOffset - 100.0, interactionYOffset + 130.0 );
        buildBasicToggleButton( "FlowerOpen5", "FlowerOpen5Icon", "DecorativeSelectionButtons", interactionXOffset - 60.0, interactionYOffset + 130.0 );
        buildBasicToggleButton( "FlowerOpen6", "FlowerOpen6Icon", "DecorativeSelectionButtons", interactionXOffset - 20.0, interactionYOffset + 130.0 );
        buildBasicToggleButton( "FlowerOpen7", "FlowerOpen7Icon", "DecorativeSelectionButtons", interactionXOffset + 20.0, interactionYOffset + 130.0 );
        
        buildBasicToggleButton( "FlowerSet1", "FlowerSet1Icon", "DecorativeSelectionButtons", interactionXOffset + 60.0, interactionYOffset + 130.0 );
        buildBasicToggleButton( "FlowerSet2", "FlowerSet2Icon", "DecorativeSelectionButtons", interactionXOffset + 100.0, interactionYOffset + 130.0 );
        buildBasicToggleButton( "FlowerSet3", "FlowerSet3Icon", "DecorativeSelectionButtons", interactionXOffset + 140.0, interactionYOffset + 130.0 );
        buildBasicToggleButton( "FlowerSet4", "FlowerSet4Icon", "DecorativeSelectionButtons", interactionXOffset - 140.0, interactionYOffset + 180.0 );
        
        buildBasicToggleButton( "FlowerSwaying1", "FlowerSwaying1Icon", "DecorativeSelectionButtons", interactionXOffset - 140.0, interactionYOffset + 180.0 );
        buildBasicToggleButton( "FlowerSwaying2", "FlowerSwaying2Icon", "DecorativeSelectionButtons", interactionXOffset - 100.0, interactionYOffset + 180.0 );
        buildBasicToggleButton( "FlowerSwaying3", "FlowerSwaying3Icon", "DecorativeSelectionButtons", interactionXOffset - 60.0, interactionYOffset + 180.0 );
        buildBasicToggleButton( "FlowerSwaying4", "FlowerSwaying4Icon", "DecorativeSelectionButtons", interactionXOffset - 20.0, interactionYOffset + 180.0 );
        
        buildBasicToggleButton( "Mushroom1", "Mushroom1Icon", "DecorativeSelectionButtons", interactionXOffset + 20.0, interactionYOffset + 180.0 );
        buildBasicToggleButton( "Mushroom2", "Mushroom2Icon", "DecorativeSelectionButtons", interactionXOffset + 60.0, interactionYOffset + 180.0 );
        buildBasicToggleButton( "Mushroom3", "Mushroom3Icon", "DecorativeSelectionButtons", interactionXOffset + 100.0, interactionYOffset + 180.0 );
        buildBasicToggleButton( "Mushroom4", "Mushroom4Icon", "DecorativeSelectionButtons", interactionXOffset + 140.0, interactionYOffset + 180.0 );
        
        buildBasicToggleButton( "Crystal", "CrystalIcon", "DecorativeSelectionButtons", interactionXOffset - 140.0, interactionYOffset + 230.0 );
        buildBasicToggleButton( "GoLeftSign", "GoLeftSignIcon", "DecorativeSelectionButtons", interactionXOffset - 100.0, interactionYOffset + 230.0 );
        buildBasicToggleButton( "GoRightSign", "GoRightSignIcon", "DecorativeSelectionButtons", interactionXOffset - 60.0, interactionYOffset + 230.0 );
        buildBasicToggleButton( "Info", "InfoIcon", "DecorativeSelectionButtons", interactionXOffset - 20.0, interactionYOffset + 230.0 );
        
        buildBasicToggleButton( "UpArrow", "UpArrowIcon", "DecorativeSelectionButtons", interactionXOffset + 60.0, interactionYOffset + 230.0 );
        buildBasicToggleButton( "RightArrow", "RightArrowIcon", "DecorativeSelectionButtons", interactionXOffset + 100.0, interactionYOffset + 230.0 );
        buildBasicToggleButton( "LeftArrow", "LeftArrowIcon", "DecorativeSelectionButtons", interactionXOffset + 140.0, interactionYOffset + 230.0 );
        
        buildStandardMessage( "Collectable", 22, interactionXOffset, interactionYOffset+280.0 );
        
        buildBasicToggleButton( "SmallBombUnlit", "SmallBombUnlit", "CollectableSelectionButtons", interactionXOffset - 140.0, interactionYOffset +320.0 );
        buildBasicToggleButton( "MediumBombUnlit", "MediumBombUnlit", "CollectableSelectionButtons", interactionXOffset - 100.0, interactionYOffset +320.0 );
        buildBasicToggleButton( "LargeBombUnlit", "LargeBombUnlit", "CollectableSelectionButtons", interactionXOffset - 60.0, interactionYOffset +320.0 );
        buildBasicToggleButton( "LargeHealth", "LargeHealth", "CollectableSelectionButtons", interactionXOffset - 20.0, interactionYOffset +320.0 );
        buildBasicToggleButton( "SmallHealth", "SmallHealth", "CollectableSelectionButtons", interactionXOffset + 20.0, interactionYOffset +320.0 );
        buildBasicToggleButton( "Life", "Life", "CollectableSelectionButtons", interactionXOffset + 60.0, interactionYOffset +320.0 );
        buildBasicToggleButton( "Diamond", "Diamond", "CollectableSelectionButtons", interactionXOffset + 100.0, interactionYOffset +320.0 );
        
        ToggleButton initialInteraction = (ToggleButton)getGameObject( "Column1" );
        initialInteraction.setSelected( true );
        currentDecorativeType = initialInteraction.getName();
        
        initialInteraction = (ToggleButton)getGameObject( "BouncerBeam1" );
        initialInteraction.setSelected( true );
        currentInteractionType = initialInteraction.getName();
        
        initialInteraction = (ToggleButton)getGameObject( "SmallBombUnlit" );
        initialInteraction.setSelected( true );
        currentCollectableType = initialInteraction.getName();
    }
    
    /**
     * Build a texture button for a single asset texture
     */
    private void buildTextureButton11( String base,
            double xLocation, double yLocation,
            boolean liquidBlock, double breakingImpulse ) {
        ToggleButton button = new ToggleButton( this, base,
                base+"Icon", base+"Icon", base+"Icon", xLocation, yLocation, 2 );
        addGameObject( button, "BlockSelectionButtons" );
        
        BlockType textureInfo = new BlockType(
                new String[] { base }, breakingImpulse );
        textureInfo.liquidBlock = liquidBlock;
        blockTypeInfo.put( base, textureInfo );
    }
    
    /**
     * Build a texture button for a 3x3 asset texture
     */
    private void buildTextureButton33( String base,
            double xLocation, double yLocation, double breakingImpulse ) {
        ToggleButton button = new ToggleButton( this, base,
                base+"Icon", base+"Icon", base+"Icon", xLocation, yLocation, 2 );
        addGameObject( button, "BlockSelectionButtons" );
        
        BlockType textureInfo = new BlockType( new String[] {
            base+"00", base+"01", base+"02",
            base+"10", base+"11", base+"12",
            base+"20", base+"21", base+"22" },
                true, 3, 3, breakingImpulse );
        blockTypeInfo.put( base, textureInfo );
    }
    
    /**
     * Build a texture button for a 3x1 asset texture
     */
    private void buildTextureButton31( String base,
            double xLocation, double yLocation, double breakingImpulse ) {
        ToggleButton button = new ToggleButton( this, base,
                base+"Icon", base+"Icon", base+"Icon", xLocation, yLocation, 2 );
        addGameObject( button, "BlockSelectionButtons" );
        
        BlockType textureInfo = new BlockType( new String[] {
            base+"00", base+"01", base+"02" },
                true, 3, 1, breakingImpulse );
        blockTypeInfo.put( base, textureInfo );
    }
    
    /**
     * Build a texture button for a 4x4 asset texture
     */
    private void buildTextureButton44( String base,
            double xLocation, double yLocation, double breakingImpulse ) {
        ToggleButton button = new ToggleButton( this, base,
                base+"Icon", base+"Icon", base+"Icon", xLocation, yLocation, 2 );
        addGameObject( button, "BlockSelectionButtons" );
        
        BlockType textureInfo = new BlockType( new String[] {
            base+"00", base+"01", base+"02", base+"03",
            base+"10", base+"11", base+"12", base+"13",
            base+"20", base+"21", base+"22", base+"23",
            base+"30", base+"31", base+"32", base+"33" },
                true, 4, 4, breakingImpulse );
        blockTypeInfo.put( base, textureInfo );
    }
    
    /**
     * Return a toggle button for the specified brick set
     */
    private ToggleButton buildBrickSet( String brickSetIdentifier,
            int numOfBricks, double xLocation, double yLocation ) {
        
        String brickSetName = "BrickSet"+brickSetIdentifier;
        ToggleButton brickSet =
                new ToggleButton( this, brickSetName,
                brickSetName+"1", brickSetName+"1", brickSetName+"1",
                xLocation, yLocation, 2 );
        addGameObject( brickSet, "BlockSelectionButtons" );
        
        String brickSetBrickNames[] = new String[numOfBricks];
        for( int idx = 0; idx < numOfBricks; idx++ )
            brickSetBrickNames[idx] =  "BrickSet"+brickSetIdentifier+(idx+1);
        
        BlockType brickSetInfo = new BlockType(
                brickSetBrickNames, SMALL_BRICK_BREAKING_IMPULSE );
        blockTypeInfo.put( brickSetName, brickSetInfo );
        
        return brickSet;
    }
    
    /**
     * Build a standard toggle button
     */
    private void buildStandardToggleButton( String toggleButtonName,
            String assetBaseName, String gameObjectSet, double x, double y ) {
        ToggleButton button = new ToggleButton( this, toggleButtonName,
                assetBaseName, assetBaseName+"Mouseover",
                assetBaseName+"Selected", x, y, 2 );
        addGameObject( button, gameObjectSet );
    }
    
    /**
     * Build a basic toggle button
     */
    private void buildBasicToggleButton( String toggleButtonName,
            String assetBaseName, String gameObjectSet, double x, double y ) {
        ToggleButton button = new ToggleButton( this, toggleButtonName,
                assetBaseName, assetBaseName, assetBaseName, x, y, 2 );
        addGameObject( button, gameObjectSet );
    }
    
    /**
     * Build a standard button
     */
    private void buildStandardButton( String buttonName,
            String assetBaseName, String gameObjectSet, double x, double y ) {
        Button button = new Button( this, buttonName,
                assetBaseName, assetBaseName+"Mouseover",
                assetBaseName+"Clicked", null, null, x, y, 2 );
        addGameObject( button, gameObjectSet );
    }
    
    /**
     * Build a message
     */
    private void buildStandardMessage( String messageText, int fontSize, double x, double y ) {
        GameObject message = new GameObject( this, x, y, 2 );
        message.setRealisationAndGeometry( new DrawnAssetMessage(
                messageText, messageText, new Font( "SANS_SERIF", Font.BOLD, fontSize ),
                new Color( 255, 255, 255, 50 ) ) );
        addGameObject( message );
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Get/Utility methods                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Get details of the currently selected block type
     */    
    public BlockType getSelectedBlockInfo() {
        return blockTypeInfo.get(currentBlockType);
    }
    
    /**
     * Get details of the currently selected emoticon type
     */    
    public String getSelectedEmoticon() {
        return currentEmoticonType;
    }
    
    /**
     * Get details of the currently selected interactive type
     */    
    public String getSelectedInteraction() {
        return currentInteractionType;
    }
    
    /**
     * Get details of the currently selected decorative type
     */    
    public String getSelectedDecoration() {
        return currentDecorativeType;
    }
    
    /**
     * Get details of the currently selected collectable type
     */    
    public String getSelectedColleable() {
        return currentCollectableType;
    }
    
    /**
     * Return if the builder GUI has current mouse focus, i.e.
     * it is displayed and the mouse is currently over one of the
     * windows.
     */    
    public final boolean hasMouseFocus() {
        if (drawControls == false) {
            return false;
        }
        
        GameObject controls = getGameObject("BuilderControlBackground");
        GameObject blocks = getGameObject("BuilderBlockSelectionBackground");
        GameObject sprites = getGameObject("BuilderControlSpriteBackground");
        GameObject interactions = getGameObject("BuilderInteractionBackground");
        
        boolean hasFocus = false;
        
        if (inputEvent.mouseXCoordinate > controls.x - controls.width / 2.0 
                && inputEvent.mouseXCoordinate < controls.x + controls.width / 2.0 
                && inputEvent.mouseYCoordinate > controls.y - controls.height / 2.0 
                && inputEvent.mouseYCoordinate < controls.y + controls.height / 2.0)
            hasFocus = true;
        
        if ( !hasFocus && inputEvent.mouseXCoordinate > blocks.x - blocks.width / 2.0 
                && inputEvent.mouseXCoordinate < blocks.x + blocks.width / 2.0 
                && inputEvent.mouseYCoordinate > blocks.y - blocks.height / 2.0 
                && inputEvent.mouseYCoordinate < blocks.y + blocks.height / 2.0)
            hasFocus = true;

        if (!hasFocus && inputEvent.mouseXCoordinate > sprites.x - sprites.width / 2.0 
                && inputEvent.mouseXCoordinate < sprites.x + sprites.width / 2.0 
                && inputEvent.mouseYCoordinate > sprites.y - sprites.height / 2.0 
                && inputEvent.mouseYCoordinate < sprites.y + sprites.height / 2.0)
            hasFocus = true;

        if (!hasFocus && inputEvent.mouseXCoordinate > interactions.x - interactions.width / 2.0 
                && inputEvent.mouseXCoordinate < interactions.x + interactions.width / 2.0 
                && inputEvent.mouseYCoordinate > interactions.y - interactions.height / 2.0 
                && inputEvent.mouseYCoordinate < interactions.y + interactions.height / 2.0)
            hasFocus = true;

        return hasFocus;
    }
    
    /**
     * Return true if the body outlines are currently being drawn
     */        
    public final boolean drawOutlines() {
        return drawBodyOutlines;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update/draw                                                  //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Update the GUI by deciding the controls need to be drawn, or if the
     * currently selected block, collectable, etc. has been changed, or if
     * a button click has occurred.
     */    
    @Override
    public void update() {
        /**
         * Check if the RMB has been presed and if so, display the menus
         */
        if( !inputEvent.mouseButton3Pressed ) {
            if( drawControls == true )
                drawControls = false;
            return;
        } else {
            if( drawControls == false )
                drawControls = true;
        }

        // Update the object selections by storing the object that 
        // is currently selected
        currentBlockType = updateButtonSet( "BlockSelectionButtons" );
        currentEmoticonType = updateButtonSet( "EmoticonSelectionButtons" );
        currentInteractionType = updateButtonSet( "InteractionSelectionButtons" );
        currentDecorativeType = updateButtonSet( "DecorativeSelectionButtons" );
        currentCollectableType = updateButtonSet( "CollectableSelectionButtons" );
        
        // Update the AI parameters based on the currently selected
        // values
        aiControlChase = updateButtonSet( "AIControlButtonsChase" );
        aiControlMovement = updateButtonSet( "AIControlButtonsMovement" );
        aiVisibleRange = updateButtonSet( "AIControlVisibleRange" );
        aiChaseRange = updateButtonSet( "AIControlChaseRange" );
        aiPatrolRange = updateButtonSet( "AIControlPatrolRange" );
        aiJumpProbability = updateButtonSet( "AIControlJumpProbability" );
        aiJumpFrequency = updateButtonSet( "AIControlJumpFrequency" );
        
        // Update each control button to check for button interaction
        GameObjectCollection controlButtons 
                = getGameObjectCollection( "ControlButtons" );        
        for( int buttonIdx = 0; buttonIdx < controlButtons.size; buttonIdx++ ) {
            GameObject button = controlButtons.gameObjects[buttonIdx];
            button.update();
        }

        // Toggle the display of the grid if needed
        ToggleButton toggleGrid = (ToggleButton)getGameObject( "ToggleGrid" );
        GameObject grid = getGameObject( "Grid" );
        if( toggleGrid.isSelected() && grid == null ) {
            grid = new GameObject( this, 
                    gameEngine.screenWidth/2, gameEngine.screenHeight/2, 0 );            
            ImageAssetTile gridTile = (ImageAssetTile)
                    assetManager.retrieveAsset( "BuilderGridTile" );
            gridTile.setViewPort( 0, 0 );
            gridTile.setViewPortDimension( 
                    gameEngine.screenWidth, gameEngine.screenHeight );
            grid.setRealisation( gridTile );
            grid.setName( "Grid" );
            addGameObject( grid );
            drawGrid = true;
        } else if( !toggleGrid.isSelected() && grid != null ) {
            removeGameObject( grid );
            drawGrid = false;
        }
        
        // Toggle the display of body outlines if needed
        ToggleButton toggleOutlines = (ToggleButton)getGameObject( "ToggleOutlines" );
        if( toggleOutlines.isSelected() )
            drawBodyOutlines = true;
        else
            drawBodyOutlines = false;
        
        // Consider scroll requests
        Button scrollUp = (Button)getGameObject( "ScrollUp" );
        if( scrollUp.buttonClicked() )
            ((HappyFaceBuilderLayer)gameEngine.
                    getGameLayer( "BuilderLayer" )).moveUp();
        
        Button scrollDown = (Button)getGameObject( "ScrollDown" );
        if( scrollDown.buttonClicked() )
            ((HappyFaceBuilderLayer)gameEngine.
                    getGameLayer( "BuilderLayer" )).moveDown();
        
        Button scrollRight = (Button)getGameObject( "ScrollRight" );
        if( scrollRight.buttonClicked() )
            ((HappyFaceBuilderLayer)gameEngine.
                    getGameLayer( "BuilderLayer" )).moveRight();
        
        Button scrollLeft = (Button)getGameObject( "ScrollLeft" );
        if( scrollLeft.buttonClicked() )
            ((HappyFaceBuilderLayer)gameEngine.
                    getGameLayer( "BuilderLayer" )).moveLeft();
        
        // Consider selection rotation requests if needed
        Button rotateLeft = (Button)getGameObject( "RotateLeft" );
        if( rotateLeft.buttonClicked() )
            ((HappyFaceBuilderLayer)gameEngine.
                    getGameLayer( "BuilderLayer" )).rotateLeft();
        
        Button rotateRight = (Button)getGameObject( "RotateRight" );
        if( rotateRight.buttonClicked() )
            ((HappyFaceBuilderLayer)gameEngine.
                    getGameLayer( "BuilderLayer" )).rotateRight();        
    }
    
    /**
     * Update the specified button set by iterating through the
     * set of toggle buttons and ensuring that at most one 
     * button in the set can be selected at any one time. The name 
     * of the selected button within the set will be returned
     * from this method
     */
    private String updateButtonSet(String gameObjectCollectionName) {
        String selectedType = "";
        
        GameObjectCollection buttons 
                = getGameObjectCollection(gameObjectCollectionName);
        for (int buttonIdx = 0; buttonIdx < buttons.size; buttonIdx++) {
            ToggleButton button = (ToggleButton) buttons.gameObjects[buttonIdx];

            // Update the button, making a note of the state prior to update
            boolean preUpdateState = button.isSelected();
            button.update();

            // If the button state has changed then, if the change is from
            // unselected to selected, set the button to be selected and
            // unselect all other buttons within the set
            if (button.isSelected() != preUpdateState) {
                if (preUpdateState == true) {
                    button.setSelected(true);
                } else {
                    for (int otherButtonIdx = 0; 
                            otherButtonIdx < buttons.size; otherButtonIdx++) {
                        if (otherButtonIdx == buttonIdx) {
                            continue;
                        } else {
                            ((ToggleButton) buttons.gameObjects[otherButtonIdx]).
                                    setSelected(false);
                        }
                    }
                }
            }

            // If needed, store the name of the selected button
            if (button.isSelected()) {
                selectedType = button.getName();
            }
        }
        
        return selectedType;
    }
    
    /**
     * Draw out the GUI components and then add a highlight to each of the
     * selected buttons within the various button sets. If needed also 
     * draw an grid overlay if not drawing the controls.
     */    
    @Override
    public void draw( Graphics2D graphics2D ) {
        if( drawControls ) {
            super.draw( graphics2D );
            
            GameObject currentBlock = getGameObject( currentBlockType );
            Rectangle screenRect = getGameObjectScreenRectangle(currentBlock );
            graphics2D.drawRect( screenRect.x, screenRect.y, 
                    screenRect.width, screenRect.height );
            
            GameObject currentEmoticon = getGameObject( currentEmoticonType );
            screenRect = getGameObjectScreenRectangle( currentEmoticon );
            graphics2D.drawRect( screenRect.x, screenRect.y, 
                    screenRect.width, screenRect.height );
            
            GameObject currentInteraction = getGameObject( currentInteractionType );
            screenRect = getGameObjectScreenRectangle( currentInteraction );
            graphics2D.drawRect( screenRect.x, screenRect.y, 
                    screenRect.width, screenRect.height );
            
            GameObject currentDecoration = getGameObject( currentDecorativeType );
            screenRect = getGameObjectScreenRectangle( currentDecoration );
            graphics2D.drawRect( screenRect.x, screenRect.y, 
                    screenRect.width, screenRect.height );
            
            GameObject currentCollectable = getGameObject( currentCollectableType );
            screenRect = getGameObjectScreenRectangle( currentCollectable );
            graphics2D.drawRect( screenRect.x, screenRect.y, 
                    screenRect.width, screenRect.height );
            
        } else if( drawGrid ) {
            GameObject grid = getGameObject( "Grid" );
            grid.draw( graphics2D );
        }
    }
}
