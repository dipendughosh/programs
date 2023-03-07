package spaceInvaders;

import game.assets.DrawnAssetMessage;
import game.engine.GameLayer;
import game.engine.GameObject;
import java.awt.*;
import java.util.*;

/**
 * Splash a text message onto the screen for a specified length of time
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class SplashMessage extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of GUI elements
     */
    protected static final int GUI_ELEMENT_DRAW_ORDER = 5;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new textual splash message.
     * <P>
     * Note: A message display duration of 0 (or less) will be interpreted
     * as the splash message should remain indefinitely on the screen (
     * until removed by some other mechanism).
     * <P>
     * Note: Events with this method are triggered on the draw tick, i.e.
     * if accurate or precise timing is required then a corresponding
     * accurate series of draw ticks will be needed.
     * <P>
     * Note: Once the message display time has elapsed, during the next
     * update the splash message will send all observers a
     * "SplashMessageTimeCompleted" message.
     *
     * @param  gameLayer GameLayer instance to which this object belongs
     * @param  messageText String of text to be displayed
     * @param  messageDisplayInitialPause number of ms to elapse before
     *         message is displayed
     * @param  messageDisplayDuration number of ms that the splash message
     *         will be displayed before being removed.
     */
    public SplashMessage(String messageText, long messageDisplayInitialPause, 
            long messageDisplayDuration, GameLayer gameLayer) {
        super(gameLayer);

        Font messageFont = new Font("MONOSPACED", Font.BOLD, 60);

        // Create and use a drawn asset message to display the splash message
        DrawnAssetMessage message = new DrawnAssetMessage(
                "SplashMessage", messageText, messageFont, Color.red);
        setRealisation(message);

        // Center the message on the screen
        this.x = gameLayer.gameEngine.screenWidth / 2;
        this.y = gameLayer.gameEngine.screenHeight / 2;
        this.drawOrder = GUI_ELEMENT_DRAW_ORDER;

        if (messageDisplayDuration > 0) {
            message.enableMessageDisplayTime(
                    messageDisplayInitialPause, messageDisplayDuration);
            message.addObserver(this);
        }

        // Turn off collision detection for this object
        this.canIntersectOtherGraphicalObjects = false;
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////    
    
    /**
     * This method is invoked whenever the splash message associated with
     * this game object has disappeared (at which point this game object queues
     * itself to be removed from its game layer).
     *
     * @param  observableObject observed object
     * @param  message message from the observed object
     */
    @Override
    public void update(Observable observableObject, Object message) {
        if (((String) message).compareTo("MessageDisplayTimeCompleted") == 0) {
            gameLayer.queueGameObjectToRemove(this);

            setChanged();
            notifyObservers("SplashMessageTimeCompleted");
        }
    }
}