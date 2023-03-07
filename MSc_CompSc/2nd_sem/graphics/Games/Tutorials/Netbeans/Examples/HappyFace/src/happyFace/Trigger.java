package happyFace;

import game.engine.*;
import game.physics.*;
import game.geometry.*;
import java.awt.Graphics2D;
import java.awt.Color;
import java.io.*;

/**
 * Trigger instances provide a simple contained class for an in-game trigger,
 * defining a region that the play can be within
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */

public class Trigger extends Body {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
        
    /**
     * Trigger identifier
     */
    private int triggerNumber;

    /**
     * Variables specifying if the trigger should be visually displayed
     */
    private boolean displayTrigger = false;
    private Color drawColor = new Color(255, 0, 0, 128);

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
        
    /**
     * Create a new trigger instance
     */
    public Trigger(GameLayer gameLayer) {
        this(gameLayer, 0.0, 0.0, 1.0, 1.0, 2, 0);
    }

    /**
     * Create a new trigger instance of the specified size and position and
     * with the specified trigger number
     */
    public Trigger(GameLayer gameLayer, double x, double y, 
            double width, double height, int drawOrder, int triggerNumber) {
        super(gameLayer, x, y, drawOrder);
        
        setGeometry(new Box(0.0, 0.0, width, height));
        
        this.triggerNumber = triggerNumber;
        
        canIntersectOtherGraphicalObjects = false;
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
        
    /**
     * Return the identifier associated with this trigger
     */ 
    public int getTriggerNumber() {
        return triggerNumber;
    }

    /**
     * Return true if the specified game object is within the bounds of
     * the trigger
     */
    public boolean isTriggeredBy(GameObject gameObject) {
        canIntersectOtherGraphicalObjects = true;
        boolean triggered = GameObjectCollider.isIntersection(this, gameObject);
        canIntersectOtherGraphicalObjects = false;
        
        return triggered;
    }

    /**
     * Determine if the trigger should be graphically displayed
     */
    public void setDisplayTrigger(boolean displayTrigger) {
        this.displayTrigger = displayTrigger;
    }
    
    /**
     * Save the trigger to the specified output stream
     */
    @Override
    public void serialiseGameObjectState(
            ObjectOutputStream stream, GameObject gameObject) throws IOException {
        super.serialiseGameObjectState(stream, gameObject);
        
        stream.writeInt(triggerNumber);
        stream.writeBoolean(displayTrigger);
    }
    
    /**
     * Reform the trigger from the specified input stream
     */    
    @Override
    public void loadGameObjectState(
            ObjectInputStream stream, GameLayer gameLayer) throws IOException {
        super.loadGameObjectState(stream, gameLayer);
        
        triggerNumber = stream.readInt();
        displayTrigger = stream.readBoolean();
    }
    
    /**
     * Display the trigger if needed
     */    
    @Override
    public void draw(Graphics2D graphics2D, int drawX, int drawY) {
        if (displayTrigger == false)
            return;

        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(drawColor);
        graphics2D.fillRect(drawX - (int) width / 2, 
                drawY - (int) height / 2, (int) width, (int) height);
        graphics2D.setColor(Color.WHITE);
        graphics2D.drawString("Trigger " + triggerNumber, 
                drawX - (int) width / 2, drawY + (int) height / 3);
        graphics2D.setColor(originalColour);
    }
}