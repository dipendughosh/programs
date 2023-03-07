package happyFace;

import game.engine.*;
import game.assets.*;
import game.components.*;
import java.util.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.text.DecimalFormat;

/**
 * HappyFaceLevelLayerGUI provides the game GUI that sits on top
 * of the game layer and displays core game information, e.g.
 * score, lives, bombs, etc.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class HappyFaceLevelLayerGUI extends GameLayer {

    /**
     * Define a number of intervals, in terms of update ticks, that the
     * various GUI components will be updated, e.g. the medium update
     * frequency is set to once every 10 updates (which are 60 UPS 
     * equates to 6 updates per second).
     */
    private static final int HEALTH_ANIMATION_SPEED_UPDATE_FREQUENCY = 10;
    private static final int MAXIMUM_SCORE_UPDATE_INCREMENT = 5;
    private static final int FAST_UPDATE_FREQUENCY = 4;
    private static final int MEDIUM_UPDATE_FREQUENCY = 10;
    private static final int SLOW_UPDATE_FREQUENCY = 30;

    /**
     * Define elements that will be used for creating textual messages
     */
    private DecimalFormat scoreFormat = new DecimalFormat("00000");
    private TextElement guiText;

    /**
     * Define the default separation between graphical components
     */
    private double componentSeparation = 5.0;
       
    /**
     * Create an inner class and associated array of instances that
     * can be used to store all messages to be displayed on the screen
     */  
    private class GUIMessage {
        String messageName;
        double x, y;
        double width, height;
        ArrayList<TextElement> messageLines;
    }
    private ArrayList<GUIMessage> guiMessages = new ArrayList<GUIMessage>();


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Create a new happy face level GUI
     */  
    public HappyFaceLevelLayerGUI(GameEngine gameEngine) {
        super("LevelLayerGUI", gameEngine, 
                gameEngine.screenWidth, gameEngine.screenHeight);

        // Add in a game object collection holding all GUI elements
        addGameObjectCollection("GUIElements");

        // Create a base text element to be used to create other text messages
        guiText = new game.components.TextElement(this, (ImageAssetSequence) 
                assetManager.retrieveAsset( "GUIFont" ), 0, 
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" + 
                "1234567890`!\"$%^&*()-+={}[];:'@#~,.<>/\\?            ", "");

        // Build the GUI elements
        buildGUIElements();
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Build the GUI elements used to display player and game information 
     */
    private void buildGUIElements() {
        // Display an animated health icon
        GameObject healthIcon = new GameObject(this);
        healthIcon.setName("HealthIcon");
        healthIcon.setRealisationAndGeometry("HealthIcon");
        healthIcon.setPosition(healthIcon.width / 2.0 + componentSeparation, 
                gameEngine.screenHeight - healthIcon.height / 2.0 - componentSeparation);
        addGameObject(healthIcon, "GUIElements");

        // Display a health bar
        Bar healthBar = new Bar(this, "HealthBar", "HealthbarBorder", 
                "HealthbarInner", EmoticonPlayer.MAX_PLAYER_HEALTH);
        healthBar.setInnerAssetOffset(-4.0, -2.0);
        healthBar.setMaximumUpdatePointChange(2.0);
        healthBar.setPosition(
                healthIcon.width + healthBar.width / 2.0 + componentSeparation * 2, 
                gameEngine.screenHeight - healthBar.height / 2.0 - componentSeparation);
        addGameObject(healthBar, "GUIElements");

        // Display a small bomb icon
        GameObject smallBombIcon = new GameObject(this);
        smallBombIcon.setName("SmallBombIcon");
        smallBombIcon.setRealisationAndGeometry("SmallBombIcon");
        smallBombIcon.setPosition(
                gameEngine.screenWidth - 400, gameEngine.screenHeight - 
                smallBombIcon.height / 2.0 - componentSeparation);
        addGameObject(smallBombIcon, "GUIElements");

        // Display the number of small bombs
        TextElement numSmallBombsText = guiText.getMatchingElement("0");
        numSmallBombsText.setName("NumSmallBombs");
        numSmallBombsText.setAlignment(TextElement.Alignment.Right);
        numSmallBombsText.setPosition(gameEngine.screenWidth - 350, 
                gameEngine.screenHeight - numSmallBombsText.height / 2.0 - 
                componentSeparation);
        addGameObject(numSmallBombsText, "GUIElements");

        // Display a medium bomb icon
        GameObject mediumBombIcon = new GameObject(this);
        mediumBombIcon.setName("MediumBombIcon");
        mediumBombIcon.setRealisationAndGeometry("MediumBombIcon");
        mediumBombIcon.setPosition(gameEngine.screenWidth - 250, 
                gameEngine.screenHeight - mediumBombIcon.height / 2.0 - 
                componentSeparation);
        addGameObject(mediumBombIcon, "GUIElements");

        // Display the number of medium bombs
        TextElement numMediumBombsText = guiText.getMatchingElement("0");
        numMediumBombsText.setName("NumMediumBombs");
        numMediumBombsText.setAlignment(TextElement.Alignment.Right);
        numMediumBombsText.setPosition(gameEngine.screenWidth - 200, 
                gameEngine.screenHeight - numMediumBombsText.height / 2.0 - 
                componentSeparation);
        addGameObject(numMediumBombsText, "GUIElements");

        // Display a large bomb icon
        GameObject largeBombIcon = new GameObject(this);
        largeBombIcon.setName("LargeBombIcon");
        largeBombIcon.setRealisationAndGeometry("LargeBombIcon");
        largeBombIcon.setPosition(gameEngine.screenWidth - 100, 
                gameEngine.screenHeight - largeBombIcon.height / 2.0 - 
                componentSeparation);
        addGameObject(largeBombIcon, "GUIElements");

        // Display the number of large bombs
        TextElement numLargeBombsText = guiText.getMatchingElement("0");
        numLargeBombsText.setName("NumLargeBombs");
        numLargeBombsText.setAlignment(TextElement.Alignment.Right);
        numLargeBombsText.setPosition(gameEngine.screenWidth - 50, 
                gameEngine.screenHeight - numLargeBombsText.height / 2.0 - 
                componentSeparation);
        addGameObject(numLargeBombsText, "GUIElements");

        // Display a life icon
        GameObject numLifes = new GameObject(this);
        numLifes.setName("LifesIcon");
        numLifes.setRealisationAndGeometry("Life");
        numLifes.setPosition(componentSeparation + numLifes.width / 2.0, 
                componentSeparation + numLifes.height / 2.0);
        addGameObject(numLifes, "GUIElements");

        // Display the number of lifes
        TextElement numLifesText = guiText.getMatchingElement("0");
        numLifesText.setName("NumLifes");
        numLifesText.setAlignment(TextElement.Alignment.Right);
        numLifesText.setPosition(80, 
                componentSeparation + numLifesText.height / 2.0 - 10);
        addGameObject(numLifesText, "GUIElements");

        // Display the player's score
        TextElement playerScore = guiText.getMatchingElement("00000");
        playerScore.setName("PlayerScore");
        playerScore.setAlignment(TextElement.Alignment.Centre);
        playerScore.setCharacterSeparation(-25);
        playerScore.setUseFixedWidthCharacters(true);
        playerScore.setPosition(
                gameEngine.screenWidth - playerScore.width / 2 - componentSeparation - 30,
                componentSeparation + playerScore.height / 2.0 - 10);
        addGameObject(playerScore, "GUIElements");

        // Display the number of sad emoticon set free
        TextElement numEmoticonsCollectedText = guiText.getMatchingElement("x0");
        numEmoticonsCollectedText.setName("NumEmoticonsCollectedText");
        numEmoticonsCollectedText.setAlignment(TextElement.Alignment.Centre);
        numEmoticonsCollectedText.setCharacterSeparation(-25);
        numEmoticonsCollectedText.setUseFixedWidthCharacters(true);
        numEmoticonsCollectedText.setPosition(playerScore.x - playerScore.width / 2.0 
                - numEmoticonsCollectedText.width / 2.0 - 50, 
                componentSeparation + numEmoticonsCollectedText.height / 2.0 - 10);
        addGameObject(numEmoticonsCollectedText, "GUIElements");

        // Display a sad emoticon face
        GameObject numEmoticonsCollected = new GameObject(this);
        numEmoticonsCollected.setName("NumEmoticonsCollected");
        numEmoticonsCollected.setRealisationAndGeometry("SadEmoticonIcon");
        numEmoticonsCollected.setPosition(numEmoticonsCollectedText.x - 
                numEmoticonsCollectedText.width / 2.0 - numEmoticonsCollected.width / 2.0, 
                componentSeparation + numEmoticonsCollected.height / 2.0 - 10.0);
        addGameObject(numEmoticonsCollected, "GUIElements");

        // Display the number of happy emoticons killed
        TextElement numEmoticonsKilledText = guiText.getMatchingElement("x0");
        numEmoticonsKilledText.setName("NumEmoticonsKilledText");
        numEmoticonsKilledText.setAlignment(TextElement.Alignment.Centre);
        numEmoticonsKilledText.setCharacterSeparation(-25);
        numEmoticonsKilledText.setUseFixedWidthCharacters(true);
        numEmoticonsKilledText.setPosition(numEmoticonsCollected.x - 
                numEmoticonsCollected.width / 2.0 - numEmoticonsKilledText.width / 2.0 - 
                50, componentSeparation + numEmoticonsKilledText.height / 2.0 - 10);
        addGameObject(numEmoticonsKilledText, "GUIElements");

        // Display a happy emoticon face
        GameObject numEmoticonsKilled = new GameObject(this);
        numEmoticonsKilled.setName("NumEmoticonsKilled");
        numEmoticonsKilled.setRealisationAndGeometry("HappyEmoticonIcon");
        numEmoticonsKilled.setPosition(numEmoticonsKilledText.x - 
                numEmoticonsKilledText.width / 2.0 - numEmoticonsKilled.width / 2.0, 
                componentSeparation + numEmoticonsKilled.height / 2.0 - 10.0);
        addGameObject(numEmoticonsKilled, "GUIElements");
    }
    
    /**
     * A level layer GUI, once created, is reused between games. If the user
     * changes the resolution between games, then reconfigure the GUI so that
     * it's layout is suitable for the new resolution.
     */
    public void reconfigureLevelLayerGUI() {
        GameObject healthIcon = getGameObject("HealthIcon");
        healthIcon.setPosition(healthIcon.width / 2.0 + componentSeparation, 
                gameEngine.screenHeight - healthIcon.height / 2.0 - componentSeparation);

        GameObject healthBar = getGameObject("HealthBar");
        healthBar.setPosition(healthIcon.width + healthBar.width / 2.0 + componentSeparation * 2, 
                gameEngine.screenHeight - healthBar.height / 2.0 - componentSeparation);

        GameObject smallBombIcon = getGameObject("SmallBombIcon");
        smallBombIcon.setPosition(gameEngine.screenWidth - 400, 
                gameEngine.screenHeight - smallBombIcon.height / 2.0 - componentSeparation);

        GameObject numSmallBombsText = getGameObject("NumSmallBombs");
        numSmallBombsText.setPosition(gameEngine.screenWidth - 350, 
                gameEngine.screenHeight - numSmallBombsText.height / 2.0 - componentSeparation);

        GameObject mediumBombIcon = getGameObject("MediumBombIcon");
        mediumBombIcon.setPosition(gameEngine.screenWidth - 250, 
                gameEngine.screenHeight - mediumBombIcon.height / 2.0 - componentSeparation);

        GameObject numMediumBombsText = getGameObject("NumMediumBombs");
        numMediumBombsText.setPosition(gameEngine.screenWidth - 200, 
                gameEngine.screenHeight - numMediumBombsText.height / 2.0 - componentSeparation);

        GameObject largeBombIcon = getGameObject("LargeBombIcon");
        largeBombIcon.setPosition(gameEngine.screenWidth - 100, 
                gameEngine.screenHeight - largeBombIcon.height / 2.0 - componentSeparation);

        GameObject numLargeBombsText = getGameObject("NumLargeBombs");
        numLargeBombsText.setPosition(gameEngine.screenWidth - 50, 
                gameEngine.screenHeight - numLargeBombsText.height / 2.0 - componentSeparation);

        GameObject numLifes = getGameObject("LifesIcon");
        numLifes.setPosition(componentSeparation + numLifes.width / 2.0, 
                componentSeparation + numLifes.height / 2.0);

        GameObject numLifesText = getGameObject("NumLifes");
        numLifesText.setPosition(80, componentSeparation + numLifesText.height / 2.0 - 10);

        GameObject playerScore = getGameObject("PlayerScore");
        playerScore.setPosition(gameEngine.screenWidth - playerScore.width / 2 - 
                componentSeparation - 30, componentSeparation + numLifesText.height / 2.0 - 10);

        GameObject numEmoticonsCollectedText = getGameObject("NumEmoticonsCollectedText");
        numEmoticonsCollectedText.setPosition(playerScore.x - playerScore.width / 2.0 - 
                numEmoticonsCollectedText.width / 2.0 - 50, 
                componentSeparation + numEmoticonsCollectedText.height / 2.0 - 10);

        GameObject numEmoticonsCollected = getGameObject("NumEmoticonsCollected");
        numEmoticonsCollected.setPosition(numEmoticonsCollectedText.x - 
                numEmoticonsCollectedText.width / 2.0 - numEmoticonsCollected.width / 2.0, 
                componentSeparation + numEmoticonsCollected.height / 2.0 - 10.0);

        GameObject numEmoticonsKilledText = getGameObject("NumEmoticonsKilledText");
        numEmoticonsKilledText.setPosition(numEmoticonsCollected.x - 
                numEmoticonsCollected.width / 2.0 - numEmoticonsKilledText.width / 2.0 - 50, 
                componentSeparation + numEmoticonsKilledText.height / 2.0 - 10);

        GameObject numEmoticonsKilled = getGameObject("NumEmoticonsKilled");
        numEmoticonsKilled.setPosition(numEmoticonsKilledText.x - 
                numEmoticonsKilledText.width / 2.0 - numEmoticonsKilled.width / 2.0, 
                componentSeparation + numEmoticonsKilled.height / 2.0 - 10.0);
    }

    /**
     * If requested by the game level, display a GUI message
     * <P>
     * Note: This functionality is not currently employed
     */
    public void addDisplayMessage(
            String messageName, double x, double y, ArrayList<TextElement> messageLines) {

        // Work out the combined height and maximum width of the messages
        double width = 0.0, height = 0.0;
        for (int idx = 0; idx < messageLines.size(); idx++) {
            TextElement line = messageLines.get(idx);

            if (line.width > width) {
                width = line.width;
            }
            height += line.height;
        }

        // Create and add a suitable gui message
        GUIMessage message = new GUIMessage();
        message.messageName = messageName;
        message.x = x; message.y = y;
        message.width = width; message.height = height;
        message.messageLines = messageLines;
        guiMessages.add(message);
    }

    /**
     * Remove the specified GUI message
     */
    public void removeDisplayMessage(String messageName) {
        int idx = 0;
        while (idx < guiMessages.size()) {
            if (guiMessages.get(idx).messageName.compareTo(messageName) == 0) {
                guiMessages.remove(idx);
            } else {
                idx++;
            }
        }
    }

    /**
     * Update the GUI to reflect changes in the level (e.g. player health,
     * score, etc.)
     */
    @Override
    public void update() {
        if (!gameEngine.gameLayers.containsKey("LevelLayer"))
            return;
                
        GameObject playerObject = gameEngine.getGameObjectFromLayer("Player", "LevelLayer");
        if (playerObject != null) {
            EmoticonPlayer player = (EmoticonPlayer) playerObject;

            // Update the health bar based on the player's health
            Bar healthBar = (Bar) getGameObject( "HealthBar" );
            int difference = (int) player.getHealth() - healthBar.getPoints();
            if (difference != 0)
                healthBar.addPoints(difference);
            healthBar.update();

            // Change the frequency of the health animation (a beating heart) 
            // to reflect the player's current health
            GameObject healthIcon = getGameObject("HealthIcon");
            ImageAssetSequence healthIconAnimation 
                    = (ImageAssetSequence) healthIcon.graphicalRealisation[0];
            healthIconAnimation.update();
            if (gameEngine.updateCounter % HEALTH_ANIMATION_SPEED_UPDATE_FREQUENCY == 0) {
                healthIconAnimation.setAnimationPeriod((int) (800.0 * (double)healthBar.getPoints()
                        / (double)healthBar.getMaximumPoints()) + 200);
            }
            
            // Update the sad emoticon animation
            GameObject numEmoticonsCollected = getGameObject("NumEmoticonsCollected");
            ImageAssetSequence numEmoticonsCollectedAnimation = 
                    (ImageAssetSequence) numEmoticonsCollected.graphicalRealisation[0];
            numEmoticonsCollectedAnimation.update();

            // Update the happy emoticon animation
            GameObject numEmoticonsKilled = getGameObject("NumEmoticonsKilled");
            ImageAssetSequence numEmoticonsKilledAnimation = 
                    (ImageAssetSequence) numEmoticonsKilled.graphicalRealisation[0];
            numEmoticonsKilledAnimation.update();

            // Update the life animation
            GameObject lifesIcon = getGameObject("LifesIcon");
            ImageAssetSequence lifesIconAnimation 
                    = (ImageAssetSequence) lifesIcon.graphicalRealisation[0];
            lifesIconAnimation.update();

            // Consider updates tied into the medium update frequency
            if (gameEngine.updateCounter % MEDIUM_UPDATE_FREQUENCY == 0) {
                // Update the current number of small bombs
                TextElement numSmallBombsText = (TextElement) getGameObject( "NumSmallBombs" );
                if (Integer.parseInt(numSmallBombsText.getText()) != player.numSmallBombs) 
                    numSmallBombsText.setText("" + player.numSmallBombs);

                // Update the current number of medium bombs
                TextElement numMediumBombsText = (TextElement) getGameObject( "NumMediumBombs" );
                if (Integer.parseInt(numMediumBombsText.getText()) != player.numMediumBombs)
                    numMediumBombsText.setText("" + player.numMediumBombs);

                // Update the current number of large bombs
                TextElement numLargeBombsText = (TextElement) getGameObject( "NumLargeBombs" );
                if (Integer.parseInt(numLargeBombsText.getText()) != player.numLargeBombs)
                    numLargeBombsText.setText("" + player.numLargeBombs);

                // Update the number of player lifes
                TextElement numLifes = (TextElement) getGameObject( "NumLifes" );
                if (Integer.parseInt(numLifes.getText()) != player.numPlayerLifes)
                    numLifes.setText("" + player.numPlayerLifes);

                // Update the number of emoticons collected
                TextElement numEmoticonsCollectedText 
                        = (TextElement) getGameObject( "NumEmoticonsCollectedText" );
                numEmoticonsCollectedText.setText("x" + ((HappyFaceLevelLayer) 
                        gameEngine.getGameLayer( "LevelLayer" )).currentNumEmoticonsCollected);

                // Update the number of emoticons killed
                TextElement numEmoticonsKilledText 
                        = (TextElement) getGameObject( "NumEmoticonsKilledText" );
                numEmoticonsKilledText.setText("x" + ((HappyFaceLevelLayer) 
                        gameEngine.getGameLayer( "LevelLayer" )).currentNumEmoticonsKilled);
            }

            // Consider updates tied into the fast update frequency
            if (gameEngine.updateCounter % FAST_UPDATE_FREQUENCY == 0) {
                // Update the player's score
                TextElement playerScore = (TextElement) getGameObject( "PlayerScore" );
                int displayedScore = Integer.parseInt(playerScore.getText());
                if (displayedScore != player.getScore()) {
                    displayedScore += MAXIMUM_SCORE_UPDATE_INCREMENT;
                    if (displayedScore > player.getScore())
                        displayedScore = player.getScore();
                    playerScore.setText(scoreFormat.format(displayedScore));
                }
            }
        }
    }

    /**
     * Draw the GUI and display an associated text messages
     */
    @Override
    public void draw(Graphics2D graphics2D) {
        super.draw(graphics2D);

        if (guiMessages.size() > 0) {
            for (int idx = 0; idx < guiMessages.size(); idx++) {
                GUIMessage message = guiMessages.get(idx);

                graphics2D.fillRect((int) (message.x - message.width/2), 
                        (int) (message.y - message.height/2), 
                        (int) message.width, (int) message.height);

                int lineY = (int) (message.y - message.height/2.0);
                for (int lineIdx = 0; lineIdx < message.messageLines.size(); lineIdx++) {
                    TextElement line = message.messageLines.get(lineIdx);
                    line.draw(graphics2D, (int) message.x, lineY);
                    lineY += (int) line.height;
                }
            }
        }
    }
}
