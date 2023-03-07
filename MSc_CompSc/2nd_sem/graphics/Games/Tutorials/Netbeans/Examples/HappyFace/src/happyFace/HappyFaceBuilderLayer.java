package happyFace;

import game.assets.*;
import game.engine.*;
import game.physics.*;
import game.components.*;
import java.awt.*;
import java.awt.geom.*;
import java.awt.event.*;
import java.util.*;
import java.text.DecimalFormat;
import java.net.*;
import java.io.*;

/**
 * HappyFaceBuilderLayer provides the key builder layer, containing
 * all the methods responsible for building, modifying, editing 
 * and saving/loading levels. The render for this layer displays 
 * the created layer. 
 * <P>
 * The layer is closely linked to the HappyFaceBuilderLayerGUI which 
 * provides the GUI that controls the methods implemented within this
 * layer
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class HappyFaceBuilderLayer extends CollisionSpace {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                           //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Default size of the game layer within which levels can be created
     * along with the default reference x and y origin (the origin is merely
     * used to draw a x and y axis that can be used to plan level 
     * arrangement)
     */    
    private static final double BUILDER_LAYER_SIZE = 100000.0;
    private static final double BUILDER_X_ORIGIN = 1000.0;
    private static final double BUILDER_Y_ORIGIN = 1000.0;

    /**
     * Enumerated type defining different builder states, alongside the 
     * current state. 
     */
    private enum BuilderState { None, Creation, Trigger }
    private BuilderState currentState = BuilderState.None;

    /**
     * Variables used to track the shape creation outline drawn to the
     * screen whenever the user drags out a region
     */
    private Point shapeStart = new Point();
    private Rectangle shapeOutline = new Rectangle();

    /**
     * Collections used to track selected bodies or shapes
     */
    private ArrayList<Body> selectedObjects = new ArrayList<Body>();
    private ArrayList<game.geometry.Shape> selectedShapes 
            = new ArrayList<game.geometry.Shape>();

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Create a new happy face builder layer
     */
    public HappyFaceBuilderLayer(String gameLayerName, GameEngine gameEngine) {
        super(gameLayerName, gameEngine, 
                BUILDER_LAYER_SIZE, BUILDER_LAYER_SIZE, 
                BUILDER_X_ORIGIN, BUILDER_Y_ORIGIN);

        // Create a new HappyFaceBuilderLayerGUI for this builder layer.
        // The GUI sits on top of the builder layer and provides a means of
        // accessing the methods defined within this class
        HappyFaceBuilderLayerGUI builderControlLayer 
                = new HappyFaceBuilderLayerGUI("BuilderControlLayer", gameEngine);
        builderControlLayer.setDrawOrder(this.drawOrder + 1);
        gameEngine.addGameLayer(builderControlLayer);

        // Create collections for the types of object to be built        
        this.addGameObjectCollection("StaticObjects");
        this.addGameObjectCollection("InteractiveObjects");
        this.addGameObjectCollection("Triggers");

        // Create and add a brackgound for the builder layer
        ImageAssetTile builderBackgroundTile = (ImageAssetTile) 
                assetManager.retrieveAssetArchetype( "BuilderBackgroundTile" );
        builderBackgroundTile.setViewPort( gameEngine.screenWidth, gameEngine.screenHeight);

        ImageAssetTile builderGridTile = (ImageAssetTile) 
                assetManager.retrieveAssetArchetype( "BuilderGridTile" );
        builderGridTile.setViewPort( gameEngine.screenWidth, gameEngine.screenHeight);

        GameObject builderBackground 
                = new GameObject(this, viewPortLayerX, viewPortLayerY, 0);
        builderBackground.setRealisation((ImageAssetTile) 
                assetManager.retrieveAsset( "BuilderBackgroundTile" ));
        builderBackground.setName("BuilderBackground");
        addGameObject(builderBackground);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Layer State Change                                           //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Whenever this layer enters into a visible state, also ensure that the
     * builder GUI layer enters a visible state
     */
    @Override
    protected void enterVisibleState() {
        super.enterInvisibleState();
        if (gameEngine.gameLayers.containsKey("BuilderControlLayer")) {
            gameEngine.getGameLayer("BuilderControlLayer").
                    setVisibility(GameLayer.GameLayerVisibility.VISIBLE);
        }
    }

    /**
     * Whenever this layer enters into an invisible state, also ensure that the
     * builder GUI layer enters an invisible state
     */
    @Override
    protected void enterInvisibleState() {
        super.enterInvisibleState();
        if (gameEngine.gameLayers.containsKey("BuilderControlLayer")) {
            gameEngine.getGameLayer("BuilderControlLayer").
                    setVisibility(GameLayer.GameLayerVisibility.INVISIBLE);
        }
    }

    /**
     * Whenever this layer enters into an active state, also ensure that the
     * builder GUI layer enters an active state
     */
    @Override
    protected void enterActiveState() {
        super.enterActiveState();
        if (gameEngine.gameLayers.containsKey("BuilderControlLayer")) {
            gameEngine.getGameLayer("BuilderControlLayer").
                    setActivity(GameLayer.GameLayerActivity.ACTIVE);
        }
    }

    /**
     * Whenever this layer enters into an inactive state, also ensure that the
     * builder GUI layer enters an inactive state
     */
    @Override
    protected void enterInactiveState() {
        super.enterInactiveState();
        if (gameEngine.gameLayers.containsKey("BuilderControlLayer")) {
            gameEngine.getGameLayer("BuilderControlLayer").
                    setActivity(GameLayer.GameLayerActivity.INACTIVE);
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Update and creation methods                                  //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Update the builder layer, considering user input
     */
    @Override
    public void update() {
        // Move and/or scale the viewport and also update the background
        // to take account of viewport change
        moveAndScaleViewportOnMouseInteraction();
        updateBackground();

        // Consider key input and builder GUI layer button presses
        considerKeyInput();
        considerButtonInput();

        // If the builder GUI control layer has mouse focus, then return
        HappyFaceBuilderLayerGUI controlLayer = (HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" );
        if (controlLayer.hasMouseFocus()) 
            return;

        // If the builder layer has mouse focus, then if the mouse is currently
        // over a body consider updating the selected shapes, otherwise consider
        // create a new body
        if (mouseOverBody()) {
            updateSelectedShapes();
        } else {
            considerBodyCreation();
        }
    }

    /**
     * Update the builder background to reflect any changes in the layer viewport
     */
    private final void updateBackground() {
        GameObject builderBackground = getGameObject("BuilderBackground");
        builderBackground.x = viewPortLayerX;
        builderBackground.y = viewPortLayerY;

        ImageAssetTile tile = (ImageAssetTile) builderBackground.getRealisation(0);
        tile.setViewPort((int) viewPortLayerX, (int) viewPortLayerY);
        tile.setViewPortDimension((int) (gameEngine.screenWidth / drawScaleFactor), (
                int) (gameEngine.screenHeight / drawScaleFactor));
    }
    
    /**
     * Consider key input from the user
     */
    public void considerKeyInput() {
        
        /**
         * Test for movement (of selected objects, or viewport if no objects
         * are selected) 
         */        
        if (inputEvent.keyTyped(KeyEvent.VK_LEFT)) moveLeft();
        else if (inputEvent.keyTyped(KeyEvent.VK_RIGHT)) moveRight();
        else if (inputEvent.keyTyped(KeyEvent.VK_UP)) moveUp();
        else if (inputEvent.keyTyped(KeyEvent.VK_DOWN)) moveDown();

        /**
         * Test for selected object rotation
         */
        else if (inputEvent.keyTyped(KeyEvent.VK_COMMA)) rotateLeft();
        else if (inputEvent.keyTyped(KeyEvent.VK_PERIOD)) rotateRight();

        /**
         * Test for object creation and/or deletion
         */
        else if (inputEvent.keyTyped(KeyEvent.VK_E)) createAIEmoticon();
        else if (inputEvent.keyTyped(KeyEvent.VK_I)) createInteraction();
        else if (inputEvent.keyTyped(KeyEvent.VK_D)) createDecoration();
        else if (inputEvent.keyTyped(KeyEvent.VK_C)) createCollectable();
        else if (inputEvent.keyTyped(KeyEvent.VK_BACK_SPACE) 
                || inputEvent.keyTyped(KeyEvent.VK_DELETE))
            removeBodiesAndJoints(true, true);
        
        /**
         * Test for start and exit markers
         */        
        else if (inputEvent.keyTyped(KeyEvent.VK_S)) placePlayerStart();
        else if (inputEvent.keyTyped(KeyEvent.VK_F)) placeLevelExit();
        
        /**
         * Test for trigger creation
         */
        else if (inputEvent.keyTyped(KeyEvent.VK_1)) considerTriggerCreation(1);
        else if (inputEvent.keyTyped(KeyEvent.VK_2)) considerTriggerCreation(2);
        else if (inputEvent.keyTyped(KeyEvent.VK_3)) considerTriggerCreation(3);
        else if (inputEvent.keyTyped(KeyEvent.VK_4)) considerTriggerCreation(4);
        else if (inputEvent.keyTyped(KeyEvent.VK_5)) considerTriggerCreation(5);
        else if (inputEvent.keyTyped(KeyEvent.VK_6)) considerTriggerCreation(6);
        else if (inputEvent.keyTyped(KeyEvent.VK_7)) considerTriggerCreation(7);
        else if (inputEvent.keyTyped(KeyEvent.VK_8)) considerTriggerCreation(8);
        else if (inputEvent.keyTyped(KeyEvent.VK_9)) considerTriggerCreation(9);
        else if (inputEvent.keyTyped(KeyEvent.VK_0)) considerTriggerCreation(0);
    }

    /**
     * Consider button presses within the builder GUI layer
     */
    private void considerButtonInput() {

        // Increase or decrease the draw order of selected objects if requested
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderIncreaseDrawOrder", "BuilderControlLayer" )).buttonClicked())
            increaseDrawOrder();
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderDecreaseDrawOrder", "BuilderControlLayer" )).buttonClicked())
            decreaseDrawOrder();
        
        // Delete selected bodies or joints from bodies if requested        
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "DeleteJoints", "BuilderControlLayer" )).buttonClicked())
            removeBodiesAndJoints(true, false);
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "DeleteBodies", "BuilderControlLayer" )).buttonClicked())
            removeBodiesAndJoints(false, true);
        
        // Select all bodies or unselected all selected bodies if requested
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "SelectAllBodies", "BuilderControlLayer" )).buttonClicked()) {
            unselectAllBodies(); selectAllBodies();
        }                
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "UnselectAllBodies", "BuilderControlLayer" )).buttonClicked())
            unselectAllBodies();

        // Test out the created level if requested
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderFinish", "BuilderControlLayer" )).buttonClicked())
            considerBuilderFinish();
        
        // Test for level save requests        
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderSaveSlot1", "BuilderControlLayer" )).buttonClicked())
            saveState("BuilderLayerSaveSlot1.dat");
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderSaveSlot2", "BuilderControlLayer" )).buttonClicked())
            saveState("BuilderLayerSaveSlot2.dat");
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderSaveSlot3", "BuilderControlLayer" )).buttonClicked())
            saveState("BuilderLayerSaveSlot3.dat");

        // Test for level load requests        
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderLoadSlot1", "BuilderControlLayer" )).buttonClicked())
            loadState("BuilderLayerSaveSlot1.dat");
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderLoadSlot2", "BuilderControlLayer" )).buttonClicked())
            loadState("BuilderLayerSaveSlot2.dat");
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "BuilderLoadSlot3", "BuilderControlLayer" )).buttonClicked())
            loadState("BuilderLayerSaveSlot3.dat");
        
        // Test for joint formation or body merging if requested
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "JoinBodies", "BuilderControlLayer" )).buttonClicked())
            considerJointFormation();
        if (((game.components.Button) gameEngine.getGameObjectFromLayer( 
                "MergeBodies", "BuilderControlLayer" )).buttonClicked())
            considerBodyMerges();
    }

    /**
     * Consider the creation of a new trigger based on the currently 
     * selected region
     */
    private void considerTriggerCreation(int triggerNumber) {
        // Check that a region has been selected
        if (currentState == BuilderState.Creation && inputEvent.mouseButton1Pressed) {
            
            // Check the specified triggerNumber (which will be in the range 0 to 9)
            // against existing triggers and increase if needed (e.g. pick the next
            // free trigger in the range)
            GameObjectCollection triggers = getGameObjectCollection("Triggers");
            boolean found = false;
            do {
                found = false;
                for (int idx = 0; idx < triggers.size; idx++) {
                    if (((Trigger) triggers.gameObjects[idx]).getTriggerNumber() == triggerNumber) {
                        triggerNumber += 10;
                        found = true;
                    }
                }
            } while (found);

            // Create and add the trigger
            Trigger trigger = new Trigger(this, 
                    shapeStart.x + shapeOutline.width / 2, 
                    shapeStart.y + shapeOutline.height / 2, 
                    shapeOutline.width, shapeOutline.height, 2, triggerNumber);
            trigger.setDisplayTrigger(true);
            addGameObject(trigger, "Triggers");

            // Change the current builder state to trigger (i.e. the selected 
            // region has already been used to create a trigger
            currentState = BuilderState.Trigger;
        }
    }

    /**
     * Create and add a new collectable type based on the currently 
     * selected collectable icon
     */
    private void createCollectable() {
        // Get the name of the currently selected collectable icon
        String collectableName = ((HappyFaceBuilderLayerGUI) gameEngine.
                getGameLayer( "BuilderControlLayer" )).getSelectedColleable();

        CollectableBody.CollectableType collectableType = null;
        if (collectableName.compareTo("SmallBombUnlit") == 0) {
            collectableType = CollectableBody.CollectableType.SmallBomb;
        } else if (collectableName.compareTo("MediumBombUnlit") == 0) {
            collectableType = CollectableBody.CollectableType.MediumBomb;
        } else if (collectableName.compareTo("LargeBombUnlit") == 0) {
            collectableType = CollectableBody.CollectableType.LargeBomb;
        } else if (collectableName.compareTo("LargeHealth") == 0) {
            collectableType = CollectableBody.CollectableType.LargeHealth;
        } else if (collectableName.compareTo("SmallHealth") == 0) {
            collectableType = CollectableBody.CollectableType.SmallHealth;
        } else if (collectableName.compareTo("Life") == 0) {
            collectableType = CollectableBody.CollectableType.Life;
        } else if (collectableName.compareTo("Diamond") == 0) {
            collectableType = CollectableBody.CollectableType.Diamond;
        }
        
        // Create and add a new collectable item
        CollectableBody collectableBody = new CollectableBody(this, 
                getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                getLayerPositionFromScreenY(inputEvent.mouseYCoordinate), 
                HappyFaceLevelLayer.ITEM_DRAW_ORDER, collectableName, collectableType);
        this.addGameObject(collectableBody, "InteractiveObjects");
    }

    /**
     * Create and add a new decorative element 
     */
    private void createDecoration() {
        // Get the name of the currently selected decorative icon
        String decorationName = ((HappyFaceBuilderLayerGUI) gameEngine.
                getGameLayer( "BuilderControlLayer" )).getSelectedDecoration();

        // Create and add a new decorative item
        Body decoration = new Body(this, 
                getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                getLayerPositionFromScreenY(inputEvent.mouseYCoordinate), 
                HappyFaceLevelLayer.ITEM_DRAW_ORDER);
        decoration.setRealisationAndGeometry(assetManager.retrieveGraphicalAsset(decorationName));
        decoration.setCanIntersectOtherGraphicalObjects(false);
        decoration.gravityEffected = false;

        this.addGameObject(decoration, "StaticObjects");
    }

    /**
     * Create and add a new interative item
     */
    private void createInteraction() {
        // Get the name of the currently selected interactive icon
        String interactionName = ((HappyFaceBuilderLayerGUI) gameEngine.
                getGameLayer( "BuilderControlLayer" )).getSelectedInteraction();

        // Determine the type of interactive element that is selected
        InteractingBody.InteractionType interactionType = null;
        if (interactionName.indexOf("Spiky") == 0) {
            interactionType = InteractingBody.InteractionType.Spiky;
        } else if (interactionName.indexOf("Bouncer") == 0) {
            interactionType = InteractingBody.InteractionType.Bouncer;
        }
        
        // If the unmoveable toggle button has clicked, then set up the
        // interactive object so that it cannot be moved
        boolean moveable = true;
        if (((ToggleButton) gameEngine.getGameObjectFromLayer( 
                        "UnmovableBody", "BuilderControlLayer" )).isSelected())
            moveable = false;

        // Create and add a new interactive item
        InteractingBody interactingBody = new InteractingBody(this, 
                getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                getLayerPositionFromScreenY(inputEvent.mouseYCoordinate), 
                HappyFaceLevelLayer.ITEM_DRAW_ORDER, interactionName, 
                interactionType, InteractingBody.InteractionStrength.Mild, moveable);
        this.addGameObject(interactingBody, "InteractiveObjects");
    }

    /**
     * Create and add a new AI emoticon
     */
    private void createAIEmoticon() {
        // Get the name of the currently selected AI emoticon icon
        String emoticonType = ((HappyFaceBuilderLayerGUI) gameEngine.
                getGameLayer( "BuilderControlLayer" )).getSelectedEmoticon();

        // Create a new AI emoticon based on the selected type
        EmoticonAI newSprite = new EmoticonAI(this, emoticonType, 
                getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                getLayerPositionFromScreenY(inputEvent.mouseYCoordinate), 
                HappyFaceLevelLayer.EMOTICON_DRAW_ORDER);

        // Define the AI parameters of the AI emoticon based on current selection
        String aiControlMovement = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).aiControlMovement;
        if (aiControlMovement.compareTo("BuilderAIStationary") == 0)
            newSprite.setMovementAI(EmoticonAI.MovementAI.Stationary);
        else if (aiControlMovement.compareTo("BuilderAIPatrol") == 0)
            newSprite.setMovementAI(EmoticonAI.MovementAI.Patrol);
        
        String aiControlChase = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).aiControlChase;
        if (aiControlChase.compareTo("BuilderAIIgnore") == 0)
            newSprite.setChaseAI(EmoticonAI.ChaseAI.Ignore);
        else if (aiControlChase.compareTo("BuilderAIChase") == 0)
            newSprite.setChaseAI(EmoticonAI.ChaseAI.Chase);
        else if (aiControlChase.compareTo("BuilderAIChaseInRange") == 0)
            newSprite.setChaseAI(EmoticonAI.ChaseAI.ChaseInRange);

        String aiVisibleRange = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).aiVisibleRange;
        if (aiVisibleRange.compareTo("BuilderAIVisibleRangeXS") == 0)
            newSprite.setVisibleRange(EmoticonAI.VISIBLE_RANGE_XS);
        else if (aiVisibleRange.compareTo("BuilderAIVisibleRangeS") == 0)
            newSprite.setVisibleRange(EmoticonAI.VISIBLE_RANGE_S);
        else if (aiVisibleRange.compareTo("BuilderAIVisibleRangeM") == 0)
            newSprite.setVisibleRange(EmoticonAI.VISIBLE_RANGE_M);
        else if (aiVisibleRange.compareTo("BuilderAIVisibleRangeL") == 0)
            newSprite.setVisibleRange(EmoticonAI.VISIBLE_RANGE_L);
        else if (aiVisibleRange.compareTo("BuilderAIVisibleRangeXL") == 0)
            newSprite.setVisibleRange(EmoticonAI.VISIBLE_RANGE_XL);

        String aiChaseRange = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).aiChaseRange;
        if (aiChaseRange.compareTo("BuilderAIChaseRangeXS") == 0)
            newSprite.setChaseRange(EmoticonAI.CHASE_RANGE_XS);
        else if (aiChaseRange.compareTo("BuilderAIChaseRangeS") == 0)
            newSprite.setChaseRange(EmoticonAI.CHASE_RANGE_S);
        else if (aiChaseRange.compareTo("BuilderAIChaseRangeM") == 0)
            newSprite.setChaseRange(EmoticonAI.CHASE_RANGE_M);
        else if (aiChaseRange.compareTo("BuilderAIChaseRangeL") == 0)
            newSprite.setChaseRange(EmoticonAI.CHASE_RANGE_L);
        else if (aiChaseRange.compareTo("BuilderAIChaseRangeXL") == 0)
            newSprite.setChaseRange(EmoticonAI.CHASE_RANGE_XL);

        String aiPatrolRange = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).aiPatrolRange;
        if (aiPatrolRange.compareTo("BuilderAIPatrolRangeXS") == 0)
            newSprite.setPatrolRange(EmoticonAI.PATROL_RANGE_XS);
        else if (aiPatrolRange.compareTo("BuilderAIPatrolRangeS") == 0)
            newSprite.setPatrolRange(EmoticonAI.PATROL_RANGE_S);
        else if (aiPatrolRange.compareTo("BuilderAIPatrolRangeM") == 0)
            newSprite.setPatrolRange(EmoticonAI.PATROL_RANGE_M);
        else if (aiPatrolRange.compareTo("BuilderAIPatrolRangeL") == 0)
            newSprite.setPatrolRange(EmoticonAI.PATROL_RANGE_L);
        else if (aiPatrolRange.compareTo("BuilderAIPatrolRangeXL") == 0)
            newSprite.setPatrolRange(EmoticonAI.PATROL_RANGE_XL);

        String aiJumpProbability = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).aiJumpProbability;
        if (aiJumpProbability.compareTo("BuilderAIJumpProbabilityXS") == 0)
            newSprite.setJumpProbability(EmoticonAI.JUMP_PROBABILITY_XS);
        else if (aiJumpProbability.compareTo("BuilderAIJumpProbabilityS") == 0)
            newSprite.setJumpProbability(EmoticonAI.JUMP_PROBABILITY_S);
        else if (aiJumpProbability.compareTo("BuilderAIJumpProbabilityM") == 0)
            newSprite.setJumpProbability(EmoticonAI.JUMP_PROBABILITY_M);
        else if (aiJumpProbability.compareTo("BuilderAIJumpProbabilityL") == 0)
            newSprite.setJumpProbability(EmoticonAI.JUMP_PROBABILITY_L);
        else if (aiJumpProbability.compareTo("BuilderAIJumpProbabilityXL") == 0)
            newSprite.setJumpProbability(EmoticonAI.JUMP_PROBABILITY_XL);

        String aiJumpFrequency = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).aiJumpFrequency;
        if (aiJumpFrequency.compareTo("BuilderAIJumpFrequencyXS") == 0)
            newSprite.setJumpFrequency(EmoticonAI.JUMP_FREQUENCY_XS);
        else if (aiJumpFrequency.compareTo("BuilderAIJumpFrequencyS") == 0)
            newSprite.setJumpFrequency(EmoticonAI.JUMP_FREQUENCY_S);
        else if (aiJumpFrequency.compareTo("BuilderAIJumpFrequencyM") == 0)
            newSprite.setJumpFrequency(EmoticonAI.JUMP_FREQUENCY_M);
        else if (aiJumpFrequency.compareTo("BuilderAIJumpFrequencyL") == 0)
            newSprite.setJumpFrequency(EmoticonAI.JUMP_FREQUENCY_L);
        else if (aiJumpFrequency.compareTo("BuilderAIJumpFrequencyXL") == 0)
            newSprite.setJumpFrequency(EmoticonAI.JUMP_FREQUENCY_XL);

        this.addGameObject(newSprite, "InteractiveObjects");
    }

    /**
     * Consider the creation of a new body based on the selected region
     */
    public void considerBodyCreation() {
        HappyFaceBuilderLayerGUI.BlockType blockType = ((HappyFaceBuilderLayerGUI) 
                gameEngine.getGameLayer( "BuilderControlLayer" )).getSelectedBlockInfo();
        GraphicalAsset block = (GraphicalAsset) 
                assetManager.retrieveAssetArchetype(blockType.assetNames[0]);

        // If a trigger has just been created then return
        if (currentState == BuilderState.Trigger 
                && !inputEvent.mouseButton1Pressed) {
            currentState = BuilderState.None;

        // If the user has started to select a region then set the shape region
        } else if (currentState == BuilderState.None 
                && inputEvent.mouseButton1Pressed) {
            currentState = BuilderState.Creation;
            
            // The start x and y is mapped onto then nearest 10 pixel point
            // i.e. a crude grid is employed to help body placement
            shapeStart.x = 10 * (int) Math.floor((this.viewPortLayerX + 
                            (inputEvent.mouseXCoordinate - this.viewPortScreenX)
                            /drawScaleFactor)/10.0);
            shapeStart.y = 10 * (int) Math.floor((this.viewPortLayerY + 
                            (inputEvent.mouseYCoordinate - this.viewPortScreenY)
                            /drawScaleFactor)/10.0);

            // Setup the shape outline region
            shapeOutline.x = shapeStart.x; shapeOutline.y = shapeStart.y;
            shapeOutline.width = block.width; shapeOutline.height = block.height;

        // If the user is currently selecting a region then update the shape region
        } else if (currentState == BuilderState.Creation && inputEvent.mouseButton1Pressed) {
            // Work out the position and dimension of the updated shape
            int x = (int) (this.viewPortLayerX + (inputEvent.mouseXCoordinate 
                    - this.viewPortScreenX)/drawScaleFactor);
            int y = (int) (this.viewPortLayerY + (inputEvent.mouseYCoordinate 
                    - this.viewPortScreenY)/drawScaleFactor);
            int width = x - shapeStart.x, height = y - shapeStart.y;

            // Map the width of the region onto the dimensions of the currently
            // selected block
            width = (int) Math.ceil( width/(double)block.width) * block.width;
            height = (int) Math.ceil( height/(double)block.height) * block.height;

            // Check for a change in shape direction around the starting x point
            if (width < 0) {
                shapeOutline.x = shapeStart.x + width;
                shapeOutline.width = -width;
            } else {
                shapeOutline.x = shapeStart.x;
                shapeOutline.width = width;
            }

            // Check for a change in shape direction around the starting y point
            if (height < 0) {
                shapeOutline.y = shapeStart.y + height;
                shapeOutline.height = -height;
            } else {
                shapeOutline.y = shapeStart.y;
                shapeOutline.height = height;
            }            
            
        // If the user has finished selecting a region and wishes to create a body
        } else if (currentState == BuilderState.Creation 
                && (inputEvent.mouseClicked(MouseEvent.BUTTON1) || !inputEvent.mouseButton1Pressed)) {

            // Calculate the width of the shape to be created in terms of body geometry
            int boxWidth = (shapeOutline.width / block.width);
            if (boxWidth == 0) boxWidth = 1;
            int boxHeight = (shapeOutline.height / block.height);
            if (boxHeight == 0) boxHeight = 1;

            // Create a new body and define it's geometry
            Body newBody;
            if (blockType.fixedOrderSelection) {
                newBody = BodyBuilder.buildConnectedBoxBody(
                        boxWidth, boxHeight, 1000.0, 
                        blockType.breakingImpulse, 0.7, 0.5, 
                        blockType.assetNames, 
                        blockType.fixedOrderWidth, blockType.fixedOrderHeight, this);
            } else {
                newBody = BodyBuilder.buildConnectedBoxBody(
                        boxWidth, boxHeight, 1000.0, 
                        blockType.breakingImpulse, 0.7, 0.5, 
                        blockType.assetNames, this);
            }
                
            // Set the body x, y to the center of the shape outline
            newBody.x = shapeOutline.x + shapeOutline.width / 2.0;
            newBody.y = shapeOutline.y + shapeOutline.height / 2.0;

            // Provide the body with a default draw order
            if (blockType.assetNames[0].indexOf("Background") < 0)
                newBody.setDrawOrder(HappyFaceLevelLayer.TEXTURE_DRAW_ORDER);
            else
                newBody.setDrawOrder(HappyFaceLevelLayer.BACKGROUND_DRAW_ORDER);
            
            // If the created body is unbreakable then rework the geometry
            if (((ToggleButton) gameEngine.getGameObjectFromLayer( 
                        "UnbreakableBody", "BuilderControlLayer" )).isSelected())
                newBody.setGeometry(
                        new game.geometry.Box(0, 0, newBody.width, newBody.height));
            
            // If the body is to be non interacting then update
            if (((ToggleButton) gameEngine.getGameObjectFromLayer( 
                        "NoninteractingBody", "BuilderControlLayer" )).isSelected())
                newBody.canIntersectOtherGraphicalObjects = false;
            
            // If the body is to be unmoveable then set to infinite mass and
            // define the assumed breaking mass if the body is breakable.
            // If the body is breakable then set the mass based on the 
            // pixel size of the created block, i.e. all created objects
            // are assumed to be of equal density
            if (((ToggleButton) gameEngine.getGameObjectFromLayer( 
                        "UnmovableBody", "BuilderControlLayer" )).isSelected()) {
                newBody.setMass(Body.INFINITE_MASS);
                if (((ToggleButton) gameEngine.getGameObjectFromLayer( 
                            "UnbreakableBody", "BuilderControlLayer" )).isSelected() == false) {
                    newBody.setBreakingImpulseAssumedBodyMass(boxWidth * boxHeight * 100.0);
                }
            } else {
                newBody.setMass(boxWidth * boxHeight * 100.0);
            }
            
            // If the created body is an edge, then update its breaking behaviour
            // to destory the edge on a breaking impulse            
            if (blockType.assetNames[0].indexOf("Edging") >= 0) {
                if (newBody.geometry.length > 1)
                    newBody.breakingImpulseImmovableDestroyMoveable = true;
                else
                    newBody.breakingImpulseDestroyBody = true;
            }
            
            // Now that the block has been constructed, check to see if it needs to be
            // converted from a static object into an interactive object (in 
            // effect nulling a lot of the previous setup - Yes, this method 
            // could have been written to place this condition earlier)
            if (blockType.liquidBlock == true) {
                InteractingBody.InteractionStrength interactionStrength = null;
                if (blockType.assetNames[0].indexOf("Water") >= 0)
                    interactionStrength = InteractingBody.InteractionStrength.Weak;
                else if (blockType.assetNames[0].indexOf("Acid") >= 0)
                    interactionStrength = InteractingBody.InteractionStrength.Mild;
                else if (blockType.assetNames[0].indexOf("Lava") >= 0)
                    interactionStrength = InteractingBody.InteractionStrength.Strong;

                // Create and add an interactive object based on the created body
                InteractingBody interactingBody = new InteractingBody(
                        this, newBody.x, newBody.y, newBody.getDrawOrder(), 
                        newBody.graphicalRealisation, newBody.geometry, 
                        InteractingBody.InteractionType.Liquid, interactionStrength, false);
                addGameObject(interactingBody, "InteractiveObjects");
            } else {
                // Add the created body
                addGameObject(newBody, "StaticObjects");
            }
            
            currentState = BuilderState.None;
        }
    }

    /**
     * Consider the creation of a new joint based on the selected bodies or
     * shapes
     */
    private void considerJointFormation() {
        // Test if two or more bodies have been selected
        if (selectedObjects.size() >= 2) {
            // Connect each of the selected shapes to one another
            for (int bodyIdx = 0; bodyIdx < selectedObjects.size(); bodyIdx++) {
                for (int otherIdx = bodyIdx + 1; otherIdx < selectedObjects.size(); otherIdx++) {
                    Body body1 = selectedObjects.get(bodyIdx);
                    body1.setEnableAtRestDetermination(false);
                    Body body2 = selectedObjects.get(otherIdx);
                    body2.setEnableAtRestDetermination(false);

                    HingedJoint newJoint = new HingedJoint(this, 
                        body1, body2, (body1.x+body2.x)/2.0, (body1.y+body2.y)/2.0 );
                    //newJoint.setRelaxation(0.5);
                    newJoint.setRelaxation(1.0);

                    // If it was to be a fixed joint the code would be:
                    //FixedJoint newJoint = new FixedJoint(this, 
                    //selectedObjects.get(bodyIdx), selectedObjects.get(otherIdx));
                    newJoint.setBreakingImpulse(Double.MAX_VALUE);
                    //newJoint.setBreakingImpulse(500000.0);
                    addJoint(newJoint);
                }
            }
        // Test if two or more shapes have been selected
        } else if (selectedShapes.size() >= 2) {
            // Connect the bodies associated with each selected shape together
            // based on the selected shapes
            Body referenceBody = selectedShapes.get(0).body;
            int firstShapeIdx = 0, secondShapeIdx = 0;
            while (firstShapeIdx < selectedShapes.size()) {
                // Find the next shape that does not match the current body
                while (++secondShapeIdx < selectedShapes.size() 
                        && selectedShapes.get(secondShapeIdx).body.uniqueGameObjectID 
                            == referenceBody.uniqueGameObjectID); 

                // Joint the two bodies
                if (secondShapeIdx < selectedShapes.size()) {
                    game.geometry.Shape shape1 = selectedShapes.get(firstShapeIdx);
                    shape1.body.setEnableAtRestDetermination(false);
                    game.geometry.Shape shape2 = selectedShapes.get(secondShapeIdx);
                    shape2.body.setEnableAtRestDetermination(false);
                    
                    HingedJoint newJoint = new HingedJoint(this, 
                        shape1, shape2, (shape1.body.x+shape2.body.x)/2.0, 
                        (shape1.body.y+shape2.body.y)/2.0 );
                    //newJoint.setRelaxation(0.5);
                    newJoint.setRelaxation(1.0);

                    // If it was to be a fixed joint the code would be:
                    //FixedJoint newJoint = new FixedJoint(this, 
                    //        selectedShapes.get(firstShapeIdx), 
                    //        selectedShapes.get(secondShapeIdx));
                    newJoint.setBreakingImpulse(Double.MAX_VALUE);
                    //newJoint.setBreakingImpulse(500000.0);
                    addJoint(newJoint);
                }

                // Find the next shape that does not match the current body
                while (++firstShapeIdx < selectedShapes.size() 
                        && selectedShapes.get(firstShapeIdx).body.uniqueGameObjectID 
                            != referenceBody.uniqueGameObjectID);
            }
        }
    }
    
    /**
     * Remove the selected bodies and/or joints
     */
    private void removeBodiesAndJoints(boolean removeJoints, boolean removeBodies) {
        GameObjectCollection joints = getGameObjectCollection("Joints");

        // Remove selected joints if requested
        if (removeJoints) {
            // Remove joints associated with any selected bodies
            for (Body body : selectedObjects) {
                removeJointsWithBody(body);
            }

            // Remove joints associated with any selected shapes
            for (game.geometry.Shape shape : selectedShapes) {
                int jointIdx = 0;
                while (jointIdx < joints.size) {
                    Joint joint = (Joint) joints.gameObjects[jointIdx];
                    if (joint.connector == Joint.Connector.SHAPE) {
                        if (shape.uniqueShapeID == joint.shape1.uniqueShapeID 
                                || shape.uniqueShapeID == joint.shape2.uniqueShapeID) {
                            removeJoint(joint);
                        } else {
                            jointIdx++;
                        }
                    }
                }
            }
        }

        // Remove bodies if requested
        if (removeBodies) {

            // Remove selected bodies (and any associated joints)
            for (Body body : selectedObjects) {
                removeGameObject(body);
                removeJointsWithBody(body);
            }
            selectedObjects.clear();

            // Remove bodies (and any associated joints) from selected
            // shapes
            for (game.geometry.Shape shape : selectedShapes) {
                if (gameObjects.containsKey(shape.body.getName())) {
                    removeGameObject(shape.body);
                    removeJointsWithBody(shape.body);
                }
            }
            selectedShapes.clear();
        }
    }

    /**
     * Remove any joints associated with the specified body
     */
    private void removeJointsWithBody(Body body) {
        GameObjectCollection joints = getGameObjectCollection("Joints");
        int jointIdx = 0;
        while (jointIdx < joints.size) {
            Joint joint = (Joint) joints.gameObjects[jointIdx];
            if (joint.connector == Joint.Connector.BODY) {
                // Remove any joints attached to this body
                if (body.uniqueGameObjectID == joint.body1.uniqueGameObjectID 
                        || body.uniqueGameObjectID == joint.body2.uniqueGameObjectID) {
                    removeJoint(joint);
                } else {
                    jointIdx++;
                }
            } else {
                // Remove any joints attached to this body
                if (body.uniqueGameObjectID == joint.shape1.body.uniqueGameObjectID 
                        || body.uniqueGameObjectID == joint.shape2.body.uniqueGameObjectID) {
                    removeJoint(joint);
                } else {
                    jointIdx++;
                }
            }
        }
    }

    /**
     * Based on the selected bodies, consider merging them into a single body 
     * with a combined geometry
     */
    private void considerBodyMerges() {
        // Define an 2D-array of array lists of shapes to hold linking shapes
        ArrayList<game.geometry.Shape>[] overlappingShapes 
                = new ArrayList[]{new ArrayList<game.geometry.Shape>(), 
                    new ArrayList<game.geometry.Shape>()};

        if (selectedObjects.size() > 1) {
            // Test each specified body to confirm that there is some degree
            // of overlap between all bodies (i.e. all bodies are touching)
            // The bodies could be merged without touching, but not in this
            // implementation which will connect bodies based on their 
            // touching shape elements.            
            boolean bodiesConnected = false;
            for (int body1Idx = 0; body1Idx < selectedObjects.size() - 1; body1Idx++) {
                for (int body2Idx = body1Idx + 1; body2Idx < selectedObjects.size(); body2Idx++) {
                    if (GameObjectCollider.isIntersection(
                            selectedObjects.get(body1Idx), selectedObjects.get(body2Idx))) {
                        bodiesConnected = true;

                        // Store details of the connected shapes to be used
                        // later to connect the shapes
                        ArrayList<game.geometry.Shape>[] overlap 
                                = GameObjectCollider.getIntersection(
                                selectedObjects.get(body1Idx), selectedObjects.get(body2Idx));
                        for (int shapeIdx = 0; shapeIdx < overlap[0].size(); shapeIdx++) {
                            overlappingShapes[0].add(overlap[0].get(shapeIdx));
                            overlappingShapes[1].add(overlap[1].get(shapeIdx));
                        }
                    }
                }
            }
            
            // If connecting shapes were found then merge the bodies and 
            // connect the shape geometry on the touching shapes
            if (bodiesConnected) {
                Body mergedBody = selectedObjects.get(0);
                for (int bodyIdx = 1; bodyIdx < selectedObjects.size(); bodyIdx++) {
                    mergedBody = mergeBodies(
                            mergedBody, selectedObjects.get(bodyIdx), overlappingShapes);
                }
                
                for (int bodyIdx = 0; bodyIdx < selectedObjects.size(); bodyIdx++) {
                    // PJH: This method really should also delete any joints 
                    // associated with merged bodies
                    removeGameObject(selectedObjects.get(bodyIdx));
                }
                
                // Add the merged body and clear the selected elements
                mergedBody.setDrawOrder(1);
                addGameObject(mergedBody, "StaticObjects");
                selectedObjects.clear();
                selectedShapes.clear();
            }
        }
    }

    /**
     * Merge the two specified bodies, jointing the bodies based on the 
     * specified overlapping shapes
     */
    private Body mergeBodies(Body body1, Body body2, 
            ArrayList<game.geometry.Shape>[] overlappingShapes) {
        
        // Determine the size of the merged body and create suitable
        // storge for the realisation, geometry and shape connections
        int newSize = body1.geometry.length + body2.geometry.length;
        game.geometry.Shape[] newGeometry = new game.geometry.Shape[newSize];
        game.geometry.Shape[][] newShapeConnections 
                = new game.geometry.Shape[newSize][Body.MAX_SINGLE_SHAPE_CONNECTIONS];
        GraphicalAsset[] newRealisation = new GraphicalAsset[newSize];

        // Copy across the realisation, geometry, etc. for the first body
        for (int idx = 0; idx < body1.geometry.length; idx++) {
            newGeometry[idx] = body1.geometry[idx];
            newShapeConnections[idx] = body1.shapeConnections[idx];
            newRealisation[idx] = body1.graphicalRealisation[idx];
        }

        // Merge the realisation, geometry, etc. for the second body
        for (int idx = 0; idx < body2.geometry.length; idx++) {
            double sRc1x = Math.cos(body2.rotation);
            double sRc1y = Math.sin(body2.rotation);
            double sRc2x = -sRc1y, sRc2y = sRc1x;

            double offsetX = body2.x + (sRc1x * body2.geometry[idx].offsetX 
                    + sRc2x * body2.geometry[idx].offsetY) - body1.x;
            double offsetY = body2.y + (sRc1y * body2.geometry[idx].offsetX 
                    + sRc2y * body2.geometry[idx].offsetY) - body1.y;

            int newIdx = body1.geometry.length + idx;
            
            newGeometry[newIdx] = body2.geometry[idx];
            newGeometry[newIdx].offsetX = offsetX;
            newGeometry[newIdx].offsetY = offsetY;

            newShapeConnections[newIdx] = body2.shapeConnections[idx];

            newRealisation[newIdx] = body2.graphicalRealisation[idx];
            newRealisation[newIdx].offsetX = offsetX;
            newRealisation[newIdx].offsetY = offsetY;
        }

        // Determine center, bound, surface area, etc. of the new body
        double totalSurfaceArea = 0.0;
        double leftBound = Double.MAX_VALUE, rightBound = -Double.MAX_VALUE;
        double topBound = Double.MAX_VALUE, bottomBound = -Double.MAX_VALUE;
        for (int idx = 0; idx < newSize; idx++) {
            double surfaceArea = newGeometry[idx].surfaceArea;
            totalSurfaceArea += surfaceArea;

            if (newGeometry[idx].offsetX < leftBound) {
                leftBound = newGeometry[idx].offsetX;
            } else if (newGeometry[idx].offsetX > rightBound) {
                rightBound = newGeometry[idx].offsetX;
            }
            if (newGeometry[idx].offsetY < topBound) {
                topBound = newGeometry[idx].offsetY;
            } else if (newGeometry[idx].offsetY > bottomBound) {
                bottomBound = newGeometry[idx].offsetY;
            }
        }
        double centerX = (leftBound + rightBound) / 2.0;
        double centerY = (topBound + bottomBound) / 2.0;

        // Translate each shape relative to the calculated center X and Y
        for (int idx = 0; idx < newSize; idx++) {
            newGeometry[idx].offsetX -= centerX;
            newGeometry[idx].offsetY -= centerY;
            newRealisation[idx].offsetX = newGeometry[idx].offsetX;
            newRealisation[idx].offsetY = newGeometry[idx].offsetY;
        }

        double sRc1x = Math.cos(body1.rotation);
        double sRc1y = Math.sin(body1.rotation);
        double sRc2x = -sRc1y, sRc2y = sRc1x;

        Body newBody = new Body(this);
        if (body1.getMass() == Body.INFINITE_MASS) {
            newBody.setMass(Body.INFINITE_MASS);
        } else {
            newBody.setMass(body1.getMass() * totalSurfaceArea / body1.getSurfaceArea());
        }
        newBody.setGeometry(newGeometry);
        newBody.setShapeConnections(newShapeConnections);
        newBody.setRealisation(newRealisation);

        // Connect any overlapping shapes
        for (int shapeIdx = 0; shapeIdx < overlappingShapes[0].size(); shapeIdx++) {
            game.geometry.Shape firstShape = overlappingShapes[0].get(shapeIdx);
            game.geometry.Shape secondShape = overlappingShapes[1].get(shapeIdx);

            boolean firstShapeFound = false;
            boolean secondShapeFound = false;

            for (int idx = 0; idx < newBody.geometry.length; idx++) {
                if (newBody.geometry[idx].uniqueShapeID == firstShape.uniqueShapeID) {
                    firstShapeFound = true;
                }
                if (newBody.geometry[idx].uniqueShapeID == secondShape.uniqueShapeID) {
                    secondShapeFound = true;
                }
            }

            if (firstShapeFound && secondShapeFound) {
                newBody.connectShape(firstShape, secondShape);
            }
        }

        // Copy across any remaining 
        newBody.x = body1.x + (sRc1x * centerX + sRc2x * centerY);
        newBody.y = body1.y + (sRc1y * centerX + sRc2y * centerY);

        newBody.rotation = body1.rotation;
        newBody.friction = body1.friction;
        newBody.restitution = body1.restitution;

        newBody.breakingImpulse = body1.breakingImpulse;
        newBody.breakingImpulseBrittleness = body1.breakingImpulseBrittleness;
        newBody.breakingImpulsePropagation = body1.breakingImpulsePropagation;
        newBody.breakingImpulseDestroyBody = body1.breakingImpulseDestroyBody;
        newBody.breakingImpulseAssumedBodyMass = body1.breakingImpulseAssumedBodyMass;
        newBody.breakingImpulseImmovableIntegrityFactor 
                = body1.breakingImpulseImmovableIntegrityFactor;
        newBody.breakingImpulseImmovableMinimumIntegrity
                = body1.breakingImpulseImmovableMinimumIntegrity;
        newBody.breakingImpulseImmovableDestroyMoveable 
                = body1.breakingImpulseImmovableDestroyMoveable;
                
        return newBody;
    }

    /**
     * Consider shape updates by testing for selects/unselects on 
     * a particular shape
     */
    private final void updateSelectedShapes() {
        // Return if the LMB has not been clicked
        if (!inputEvent.mouseClicked(MouseEvent.BUTTON1))
            return;

        // Consider each body
        boolean bodyClicked = false;
        GameObjectCollection bodies = getGameObjectCollection("Bodies");
        for (int bodyIdx = 0; bodyIdx < bodies.size; bodyIdx++) {
            // Get the on-screen location of the current body
            Body body = (Body) bodies.gameObjects[bodyIdx];
            int bodyX = getGameObjectScreenX(body);
            int bodyY = getGameObjectScreenY(body);
            int bodyWidth = getGameObjectScreenWidth(body);
            int bodyHeight = getGameObjectScreenHeight(body);

            // Obtain a rotated bound for the specified body
            Rectangle bound = new Rectangle(bodyX - bodyWidth / 2, 
                    bodyY - bodyHeight / 2, bodyWidth, bodyHeight);
            AffineTransform rotation = 
                    AffineTransform.getRotateInstance(body.rotation, bodyX, bodyY);
            Shape rotatedBound = rotation.createTransformedShape(bound);

            // Test if the mouse clicks falls within the rotated body bound
            if (rotatedBound.contains(
                    inputEvent.mouseXCoordinate, inputEvent.mouseYCoordinate)) {
                bodyClicked = true;
                
                if (inputEvent.keyPressed[KeyEvent.VK_SHIFT] 
                        || inputEvent.keyPressed[KeyEvent.VK_CONTROL]) {
                    // Pressing the shift or control key can be used to select
                    // individual shapes within a body. In doing so, any
                    // currently seleced bodies (but not other selected shapes)
                    // will be deseleced
                    selectedObjects.clear();

                    // Test each shape within the clicked body to find which one
                    // was clicked
                    for (int shapeIdx = 0; shapeIdx < body.geometry.length; shapeIdx++) {
                        game.geometry.Shape shape = body.geometry[shapeIdx];

                        double rc1x = Math.cos(body.rotation);
                        double rc1y = Math.sin(body.rotation);
                        double rc2x = -rc1y, rc2y = rc1x;

                        int shapeX = getGameObjectScreenX(body) + 
                                (int) (rc1x * shape.offsetX*drawScaleFactor 
                                + rc2x * shape.offsetY*drawScaleFactor );
                        int shapeY = getGameObjectScreenY(body) + 
                                (int) (rc1y * shape.offsetX*drawScaleFactor 
                                + rc2y * shape.offsetY*drawScaleFactor );

                        int shapeWidth = (int) (shape.boundDimension*drawScaleFactor);
                        int shapeHeight = (int) (shape.boundDimension*drawScaleFactor);

                        if (shape instanceof game.geometry.Box) {
                            shapeWidth = (int) (((game.geometry.Box)shape).width*drawScaleFactor);
                            shapeHeight = (int) (((game.geometry.Box)shape).height*drawScaleFactor);
                        }

                        // Deterimine the on screen bound of the current shape
                        Rectangle shapeBound = new Rectangle(shapeX - shapeWidth / 2, 
                                shapeY - shapeHeight / 2, shapeWidth, shapeHeight);
                        rotation = AffineTransform.getRotateInstance(body.rotation, shapeX, shapeY);
                        Shape rotatedShapeBound = rotation.createTransformedShape(shapeBound);

                        // If the mouse click was within the shape then add to the 
                        // list of currently selected shapes (or remove it if it 
                        // is already in the selected shape list
                        if (rotatedShapeBound.contains(
                                inputEvent.mouseXCoordinate, inputEvent.mouseYCoordinate)) {
                            if (selectedShapes.contains(shape)) {
                                selectedShapes.remove(shape);
                            } else {
                                selectedShapes.add(shape);
                            }
                        }
                    }
                } else {
                    // If the mouse click was on a body then clear any selected
                    // shapes (other selected bodies remain selected) and 
                    // add the clicked body (or remove it if the body is already
                    // in the list of selected bodies.
                    selectedShapes.clear();
                    if (selectedObjects.contains(body)) {
                        selectedObjects.remove(body);
                    } else {
                        selectedObjects.add(body);
                    }
                }
            }
        }
    }

    /**
     * Place the level exit at the current cursor location
     */
    private void placeLevelExit() {
        GameObject levelExit = getGameObject("LevelExit");
        if (levelExit == null) {
            levelExit = new GameObject(this, 
                    getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                    getLayerPositionFromScreenY(inputEvent.mouseYCoordinate), 1000);
            levelExit.setName("LevelExit");
            levelExit.setRealisationAndGeometry("LevelExit");
            addGameObject(levelExit);
        } else {
            levelExit.setPosition(
                    getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                    getLayerPositionFromScreenY(inputEvent.mouseYCoordinate));
        }
    }

    /**
     * Place the level start at the current cursor location
     */
    private void placePlayerStart() {
        GameObject playerStart = getGameObject("PlayerStart");
        if (playerStart == null) {
            playerStart = new GameObject(this, 
                    getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                    getLayerPositionFromScreenY(inputEvent.mouseYCoordinate), 1000);
            playerStart.setName("PlayerStart");
            playerStart.setRealisationAndGeometry("BuilderPlayerStart");
            addGameObject(playerStart);
        } else {
            playerStart.setPosition(
                    getLayerPositionFromScreenX(inputEvent.mouseXCoordinate), 
                    getLayerPositionFromScreenY(inputEvent.mouseYCoordinate));
        }
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Utility and Viewport methods                                 //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Increase the draw order of all selected bodies
     */
    private void increaseDrawOrder() {
        if (selectedObjects.size() >= 1) {
            for (int idx = 0; idx < selectedObjects.size(); idx++) {
                selectedObjects.get(idx).setDrawOrder(
                        selectedObjects.get(idx).getDrawOrder() + 1);
            }
        }
    }

    /**
     * Decrease the draw order of all selected bodies
     */
    private void decreaseDrawOrder() {
        if (selectedObjects.size() >= 1) {
            for (int idx = 0; idx < selectedObjects.size(); idx++) {
                if (selectedObjects.get(idx).getDrawOrder() > 1) {
                    selectedObjects.get(idx).setDrawOrder(
                            selectedObjects.get(idx).getDrawOrder() - 1);
                }
            }
        }
    }

    /**
     * Move all selected bodies to the left (or if no bodies are
     * selected, move the viewport to the left)
     */
    public void moveLeft() {
        int distance = (int) (Math.ceil(VIEWPORT_MOUSE_SCROLL_SPEED / drawScaleFactor));
        if (selectedObjects.size() == 0) {
            moveViewPortLeft(distance);
        } else {
            for (Body body : selectedObjects) {
                body.x -= distance;
            }
        }
    }

    /**
     * Move all selected bodies to the right (or if no bodies are
     * selected, move the viewport to the right)
     */
    public void moveRight() {
        int distance = (int) (Math.ceil(VIEWPORT_MOUSE_SCROLL_SPEED / drawScaleFactor));
        if (selectedObjects.size() == 0) {
            moveViewPortRight(distance);
        } else {
            for (Body body : selectedObjects) {
                body.x += distance;
            }
        }
    }

    /**
     * Move all selected bodies to up (or if no bodies are
     * selected, move the viewport up)
     */
    public void moveUp() {
        int distance = (int) (Math.ceil(VIEWPORT_MOUSE_SCROLL_SPEED / drawScaleFactor));
        if (selectedObjects.size() == 0) {
            moveViewPortUp(distance);
        } else {
            for (Body body : selectedObjects) {
                body.y -= distance;
            }
        }
    }

    /**
     * Move all selected bodies to down (or if no bodies are
     * selected, move the viewport down )
     */
    public void moveDown() {
        int distance = (int) (Math.ceil(VIEWPORT_MOUSE_SCROLL_SPEED / drawScaleFactor));
        if (selectedObjects.size() == 0) {
            moveViewPortDown(distance);
        } else {
            for (Body body : selectedObjects) {
                body.y += distance;
            }
        }
    }

    /**
     * Rotate all selected bodies to the left
     */
    public void rotateLeft() {
        double rotation = Math.toRadians(2.0 / drawScaleFactor);
        for (Body body : selectedObjects) {
            body.rotation -= rotation;
        }
    }

    /**
     * Rotate all selected bodies to the right
     */
    public void rotateRight() {
        double rotation = Math.toRadians(2.0 / drawScaleFactor);
        for (Body body : selectedObjects) {
            body.rotation += rotation;
        }
    }

    /**
     * Unselect all bodies (and shapes)
     */
    private void unselectAllBodies() {
        selectedObjects.clear();
        selectedShapes.clear();
    }

    /**
     * Select all bodies
     */
    private void selectAllBodies() {
        GameObjectCollection bodies = getGameObjectCollection("Bodies");
        for (int idx = 0; idx < bodies.size; idx++) {
            selectedObjects.add((Body) bodies.gameObjects[idx]);
        }
    }

    /**
     * Utility method that will return true if the mouse is currently
     * over a body, otherwise false
     */
    private boolean mouseOverBody() {
        GameObjectCollection bodies = getGameObjectCollection("Bodies");

        for (int bodyIdx = 0; bodyIdx < bodies.size; bodyIdx++) {
            Body body = (Body) bodies.gameObjects[bodyIdx];
            int bodyX = getGameObjectScreenX(body);
            int bodyY = getGameObjectScreenY(body);
            int bodyWidth = getGameObjectScreenWidth(body);
            int bodyHeight = getGameObjectScreenHeight(body);

            Rectangle bound = new Rectangle(bodyX - bodyWidth / 2, 
                    bodyY - bodyHeight / 2, bodyWidth, bodyHeight);
            AffineTransform rotation = 
                    AffineTransform.getRotateInstance(body.rotation, bodyX, bodyY);
            Shape rotatedBound = rotation.createTransformedShape(bound);

            if (rotatedBound.contains(
                    inputEvent.mouseXCoordinate, inputEvent.mouseYCoordinate)) {
                return true;
            }
        }

        return false;
    }

    /**
     * If the finish button has been pressed then setup a HappyFaceLevelLayer 
     * with the created level for testing
     */
    private void considerBuilderFinish() {
        // Save the build state to permit retreival once the level testing has finished
        saveState("TempState.dat");

        // Retrieve the level layer and remove any old bodies, etc.
        HappyFaceLevelLayer collisionSpace 
                = (HappyFaceLevelLayer) gameEngine.getGameLayer( "LevelLayer" );
        collisionSpace.removeAllBodiesAndJoints();
        collisionSpace.setDebugMode(true);

        // Move all static bodies into the level layer
        GameObjectCollection staticBodies = getGameObjectCollection("StaticObjects");
        for (int bodyIdx = 0; bodyIdx < staticBodies.size; bodyIdx++) {
            Body staticBody = (Body) staticBodies.gameObjects[bodyIdx];
            staticBody.setGameLayer(collisionSpace);

            if (staticBody.graphicalRealisation[0] instanceof ImageAssetSequence) {
                collisionSpace.addGameObject(staticBody, "DecorativeAnimations");
            } else {
                collisionSpace.addGameObject(staticBody);
            }
        }

        // Move all interactive bodies into the level layer
        GameObjectCollection interactiveBodies = getGameObjectCollection("InteractiveObjects");
        for (int bodyIdx = 0; bodyIdx < interactiveBodies.size; bodyIdx++) {
            Body interactiveBody = (Body) interactiveBodies.gameObjects[bodyIdx];
            interactiveBody.setGameLayer(collisionSpace);
            if (interactiveBody instanceof Emoticon) {
                collisionSpace.addGameObject(interactiveBody, "Emoticons");
            } else if (interactiveBody instanceof InteractingBody) {
                collisionSpace.addGameObject(interactiveBody, "InteractingBodies");
            } else if (interactiveBody instanceof CollectableBody) {
                collisionSpace.addGameObject(interactiveBody, "CollectableBodies");
            } else {
                collisionSpace.addGameObject(interactiveBody);
            }
        }

        // Move all joints into the level layer
        GameObjectCollection joints = getGameObjectCollection("Joints");
        for (int jointIdx = 0; jointIdx < joints.size; jointIdx++) {
            collisionSpace.addJoint((Joint) joints.gameObjects[jointIdx]);
        }
        
        // Move all triggers into the level layer        
        GameObjectCollection triggers = getGameObjectCollection("Triggers");
        for (int triggerIdx = 0; triggerIdx < triggers.size; triggerIdx++) {
            Trigger trigger = (Trigger) triggers.gameObjects[triggerIdx];
            trigger.setDisplayTrigger(false);
            collisionSpace.addGameObject(trigger, "Triggers");
        }

        // Move the level start marker into the level layer
        GameObject playerStart = getGameObject("PlayerStart");
        if (playerStart != null) {
            collisionSpace.placePlayerSpawnAtLocation(playerStart.x, playerStart.y);
            collisionSpace.spawnPlayer();
        }

        // Move the level exit marker into the level layer
        GameObject levelExit = getGameObject("LevelExit");
        if (levelExit != null) {
            collisionSpace.placeLevelExitAtLocation(levelExit.x, levelExit.y);
        }
        
        collisionSpace.viewPortLayerX = BUILDER_X_ORIGIN;
        collisionSpace.viewPortLayerY = BUILDER_Y_ORIGIN;

        // Make this layer invisible and inactive and the level layer
        // visible and active
        this.setVisibility(HappyFaceLevelLayer.GameLayerVisibility.INVISIBLE);
        this.setActivity(HappyFaceLevelLayer.GameLayerActivity.INACTIVE);
        collisionSpace.setVisibility(HappyFaceLevelLayer.GameLayerVisibility.VISIBLE);
        collisionSpace.setActivity(HappyFaceLevelLayer.GameLayerActivity.ACTIVE);
        collisionSpace.setupLevel();
    }

    /**
     * This method is called whenever testing has finished withint he level
     * layer and control is to be passed back to the editor
     */
    public void initialiseBuilderReturn() {
        // Remove all objects from the builder layer 
        GameObjectCollection staticObjects = getGameObjectCollection("StaticObjects");
        GameObjectCollection interactiveObjects = getGameObjectCollection("InteractiveObjects");
        GameObjectCollection triggers = getGameObjectCollection("Triggers");

        staticObjects.clear();
        interactiveObjects.clear();
        triggers.clear();

        // Load the level state saved before level testing was started
        loadState("TempState.dat");
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Load and Save                                                //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Save the current layer state to the specified save file name
     */
    private void saveState(String saveFilename) {
        try {
            // Create the save file
            ObjectOutputStream saveFile = new ObjectOutputStream(
                    new FileOutputStream(getClass().getResource(
                        "levels\\builder\\").toURI().getPath() + saveFilename));
            
            GameObjectCollection staticObjects = getGameObjectCollection("StaticObjects");
            GameObjectCollection interactiveObjects 
                    = getGameObjectCollection("InteractiveObjects");

            // Store the number of bodies
            saveFile.writeInt(staticObjects.size + interactiveObjects.size);

            // Save each static object
            for (int idx = 0; idx < staticObjects.size; idx++)
                GameObjectSerialiser.serialiseGameObject(
                        saveFile, staticObjects.gameObjects[idx]);

            // Save each interactive object
            for (int idx = 0; idx < interactiveObjects.size; idx++)
                GameObjectSerialiser.serialiseGameObject(
                        saveFile, interactiveObjects.gameObjects[idx]);

            // Save each joint
            GameObjectCollection joints = getGameObjectCollection("Joints");
            saveFile.writeInt(joints.size);
            for (int idx = 0; idx < joints.size; idx++)
                GameObjectSerialiser.serialiseJoint(
                        saveFile, (Joint) joints.gameObjects[idx]);

            // Save each trigger
            GameObjectCollection triggers = getGameObjectCollection("Triggers");
            saveFile.writeInt(triggers.size);
            for (int idx = 0; idx < triggers.size; idx++)
                GameObjectSerialiser.serialiseGameObject(
                        saveFile, triggers.gameObjects[idx]);

            // Save the level start marker
            GameObject playerStart = getGameObject("PlayerStart");
            if (playerStart == null) {
                saveFile.writeBoolean(false);
            } else {
                saveFile.writeBoolean(true);
                saveFile.writeDouble(playerStart.x);
                saveFile.writeDouble(playerStart.y);
            }

            // Save the level exit marker
            GameObject levelExit = getGameObject("LevelExit");
            if (levelExit == null) {
                saveFile.writeBoolean(false);
            } else {
                saveFile.writeBoolean(true);
                saveFile.writeDouble(levelExit.x);
                saveFile.writeDouble(levelExit.y);
            }

            saveFile.close();
        } catch (IOException ioException) {
            System.err.println("HappyFaceBuilderLayer: Error opening file: " 
                    + ioException.toString());
            ioException.printStackTrace();
        } catch (URISyntaxException exception) {
            exception.printStackTrace();
        }
    }

    /**
     * Load the layer state from the specified load file name
     */
    private void loadState(String loadFilename) {
        try {
            // Open the input file
            ObjectInputStream inputFile = new ObjectInputStream(
                    new FileInputStream(getClass().getResource(
                        "levels\\builder\\").toURI().getPath() + loadFilename));

            // Clear existing layer of all bodies
            this.removeAllBodiesAndJoints();

            // Load in all bodies from the save file
            int numBodiesToLoad = inputFile.readInt();
            for (int bodyIdx = 0; bodyIdx < numBodiesToLoad; bodyIdx++)
                GameObjectSerialiser.loadGameObjectIntoLayer(inputFile, this);

            // Load in all joints from the save file
            int numJointsToLoad = inputFile.readInt();
            for (int jointIdx = 0; jointIdx < numJointsToLoad; jointIdx++)
                GameObjectSerialiser.loadJointIntoLayer(inputFile, this);

            // Load in all triggers from the save file
            int numTriggersToLoad = inputFile.readInt();
            for (int triggerIdx = 0; triggerIdx < numTriggersToLoad; triggerIdx++)
                GameObjectSerialiser.loadGameObjectIntoLayer(inputFile, this);

            // Load in the level start marker
            if (inputFile.readBoolean() == false) {
                GameObject playerStart = getGameObject("PlayerStart");
                if (playerStart != null) {
                    removeGameObject(playerStart);
                }
            } else {
                GameObject playerStart = getGameObject("PlayerStart");
                if (playerStart != null) {
                    playerStart.x = inputFile.readDouble();
                    playerStart.y = inputFile.readDouble();
                } else {
                    playerStart = new GameObject(this, inputFile.readDouble(), inputFile.readDouble(), 1000);
                    playerStart.setName("PlayerStart");
                    playerStart.setRealisationAndGeometry("BuilderPlayerStart");
                    addGameObject(playerStart);
                }
            }

            // Load in the level exit marker
            if (inputFile.readBoolean() == false) {
                GameObject levelExit = getGameObject("LevelExit");
                if (levelExit != null) {
                    removeGameObject(levelExit);
                }
            } else {
                GameObject levelExit = getGameObject("LevelExit");
                if (levelExit != null) {
                    levelExit.x = inputFile.readDouble();
                    levelExit.y = inputFile.readDouble();
                } else {
                    levelExit = new GameObject(this, inputFile.readDouble(), inputFile.readDouble(), 1000);
                    levelExit.setName("LevelExit");
                    levelExit.setRealisationAndGeometry("LevelExit");
                    addGameObject(levelExit);
                }
            }

            inputFile.close();
        } catch (IOException ioException) {
            System.err.println("HappyFaceBuilderLayer: Error loading from file: " 
                    + ioException.toString());
            ioException.printStackTrace();
        } catch (URISyntaxException exception) {
            exception.printStackTrace();
        }
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Draw                                                         //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Render the layer by firstly callling the inherited draw method and 
     * then adding a selection rectangle if needed and also highlighting
     * any selected bodies or shapes, or drawing outlines, etc.
     */
    @Override
    public void draw(Graphics2D graphics2D) {
        super.draw(graphics2D);

        double originXScreen = viewPortScreenX 
                + (BUILDER_X_ORIGIN - viewPortLayerX) * drawScaleFactor;
        double originYScreen = viewPortScreenY 
                + (BUILDER_Y_ORIGIN - viewPortLayerY) * drawScaleFactor;

        // Draw the origin lines
        graphics2D.setColor(Color.WHITE);
        if (originXScreen > viewPortScreenX - viewPortWidth / 2.0 
                && originXScreen < viewPortScreenX + viewPortWidth / 2.0) {
            graphics2D.drawLine((int) originXScreen, 
                    (int) (viewPortScreenY-viewPortHeight/2.0), 
                    (int) originXScreen, (int) (viewPortScreenY+viewPortHeight/2.0));
        }
        if (originYScreen > viewPortScreenY - viewPortHeight / 2.0 
                && originYScreen < viewPortScreenY + viewPortHeight / 2.0) {
            graphics2D.drawLine((int) (viewPortScreenX-viewPortWidth/2.0), 
                    (int) originYScreen, (int) (viewPortScreenX+viewPortWidth/2.0), (int) originYScreen);
        }

        // Highlight any selected bodies or shapes
        if (selectedObjects.size() > 0 || selectedShapes.size() > 0) {
            java.awt.Color originalColor = graphics2D.getColor();
            graphics2D.setColor(new Color(255, 255, 255, 100));
            AffineTransform originalTransform = graphics2D.getTransform();

            for (Body body : selectedObjects) {
                Rectangle bodyBound = getGameObjectScreenRectangle(body);
                graphics2D.fillRect(
                        bodyBound.x, bodyBound.y, bodyBound.width, bodyBound.height);
            }

            for (game.geometry.Shape shape : selectedShapes) {
                double rc1x = Math.cos(shape.body.rotation);
                double rc1y = Math.sin(shape.body.rotation);
                double rc2x = -rc1y, rc2y = rc1x;

                int shapeX = getGameObjectScreenX(shape.body) + 
                        (int) (rc1x * shape.offsetX*drawScaleFactor 
                            + rc2x * shape.offsetY*drawScaleFactor );
                int shapeY = getGameObjectScreenY(shape.body) + 
                        (int) (rc1y * shape.offsetX*drawScaleFactor 
                            + rc2y * shape.offsetY*drawScaleFactor );

                int shapeWidth = (int) (shape.boundDimension*drawScaleFactor);
                int shapeHeight = (int) (shape.boundDimension*drawScaleFactor);

                if (shape instanceof game.geometry.Box) {
                    shapeWidth = (int) (((game.geometry.Box)shape).width*drawScaleFactor);
                    shapeHeight = (int) (((game.geometry.Box)shape).height*drawScaleFactor);
                }

                AffineTransform rotation = 
                        AffineTransform.getRotateInstance(shape.body.rotation, shapeX, shapeY);
                graphics2D.transform(rotation);
                graphics2D.fillRect(shapeX - shapeWidth / 2, 
                        shapeY - shapeHeight / 2, shapeWidth, shapeHeight);
                graphics2D.setTransform(originalTransform);
            }

            graphics2D.setColor(originalColor);
        }

        // If shape outlines are to be drawn, then draw shape outline
        if (((HappyFaceBuilderLayerGUI) gameEngine.getGameLayer( 
                "BuilderControlLayer" )).drawOutlines()) {
            GameObjectCollection bodies = getGameObjectCollection("Bodies");
            GameObjectCollection joints = getGameObjectCollection("Joints");

            java.awt.Color originalColor = graphics2D.getColor();
            java.awt.Stroke originalStroke = graphics2D.getStroke();
            graphics2D.setStroke(new java.awt.BasicStroke(3.0f));

            for (int bodyIdx = 0; bodyIdx < bodies.size; bodyIdx++) {
                Body body = (Body) bodies.gameObjects[bodyIdx];
                Rectangle bodyBound = getGameObjectScreenRectangle(body);
                if (body.getMass() == Body.INFINITE_MASS) {
                    graphics2D.setColor(Color.GREEN);
                } else {
                    graphics2D.setColor(Color.YELLOW);
                }
                graphics2D.drawRect(bodyBound.x, bodyBound.y, 
                        bodyBound.width, bodyBound.height);
            }

            graphics2D.setColor(Color.RED);
            for (int jointIdx = 0; jointIdx < joints.size(); jointIdx++) {
                Joint joint = (Joint) joints.gameObjects[jointIdx];

                Body body1, body2;
                int x1, y1, x2, y2;

                if (joint.connector == Joint.Connector.BODY) {
                    body1 = joint.body1;
                    body2 = joint.body2;
                    x1 = getGameObjectScreenX(body1);
                    y1 = getGameObjectScreenY(body1);
                    x2 = getGameObjectScreenX(body2);
                    y2 = getGameObjectScreenY(body2);
                } else {
                    body1 = joint.shape1.body;
                    body2 = joint.shape2.body;

                    double rc1x = Math.cos(body1.rotation);
                    double rc1y = Math.sin(body1.rotation);
                    double rc2x = -rc1y, rc2y = rc1x;
                    x1 = getGameObjectScreenX(body1) + 
                            (int) (rc1x * joint.shape1.offsetX*drawScaleFactor 
                                + rc2x * joint.shape1.offsetY*drawScaleFactor );
                    y1 = getGameObjectScreenY(body1) + 
                            (int) (rc1y * joint.shape1.offsetX*drawScaleFactor 
                                + rc2y * joint.shape1.offsetY*drawScaleFactor );

                    rc1x = Math.cos(body1.rotation);
                    rc1y = Math.sin(body1.rotation);
                    rc2x = -rc1y; rc2y = rc1x;
                    x2 = getGameObjectScreenX(body2) + 
                            (int) (rc1x * joint.shape2.offsetX*drawScaleFactor 
                                + rc2x * joint.shape2.offsetY*drawScaleFactor );
                    y2 = getGameObjectScreenY(body2) + 
                            (int) (rc1y * joint.shape2.offsetX*drawScaleFactor 
                                + rc2y * joint.shape2.offsetY*drawScaleFactor );
                }

                graphics2D.drawLine(x1, y1, x2, y2);
            }

            graphics2D.setStroke(originalStroke);
            graphics2D.setColor(originalColor);
        }

        // Draw the selected region if needed
        if (currentState == BuilderState.Creation) {
            graphics2D.setColor(new Color(0, 180, 0, 128));
            graphics2D.fillRect(
                    (int) (viewPortScreenX + (shapeOutline.x - this.viewPortLayerX)*drawScaleFactor), 
                    (int) (viewPortScreenY + (shapeOutline.y - this.viewPortLayerY)*drawScaleFactor), 
                    (int) (shapeOutline.width * drawScaleFactor), 
                    (int) (shapeOutline.height * drawScaleFactor));
        }

        //Display textual summary information
        drawObjectDetails(graphics2D);
    }


    /**
     * Display textual summary information including the number of 
     * current shapes, the draw order of a single selected body
     * and the layer cursor position.
     */
    public void drawObjectDetails(Graphics2D graphics2D) {
        Color originalColour = graphics2D.getColor();
        Font originalFont = graphics2D.getFont();

        graphics2D.setColor(new Color(0, 0, 0, 55));
        graphics2D.fillRect(150, 0, 150, 55);

        graphics2D.setColor(Color.white);
        graphics2D.setFont(new Font("MONOSPACED", Font.BOLD, 12));

        int numShapes = 0;
        GameObjectCollection bodies = getGameObjectCollection("Bodies");
        for (int idx = 0; idx < bodies.size; idx++) {
            numShapes += bodies.gameObjects[idx].geometry.length;
        }
        graphics2D.drawString("Num Shapes = " + numShapes, 160, 12);
        graphics2D.drawString("Draw Order = " + 
                ((selectedObjects.size() == 1) ? 
                    "[" + selectedObjects.get(0).getDrawOrder() +"]" 
                    : "NA"), 160, 24);
        graphics2D.drawString("Pos: [" + 
                (int) getLayerPositionFromScreenX( inputEvent.mouseXCoordinate ) + "," + 
                (int) getLayerPositionFromScreenY( inputEvent.mouseYCoordinate ) + "]", 160, 36);
        graphics2D.drawString("Press RMB for menu", 160, 48);

        graphics2D.setColor(originalColour);
        graphics2D.setFont(originalFont);
    }
}