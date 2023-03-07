package ZoMA;

import game.engine.*;
import java.awt.*;

/**
 * The Sight class provides software based mouse pointer sight. As
 * such the sight can be subject to definable wobble (i.e. random
 * movement) maximum travel speed, and recoil following a shot. The
 * sight can also be setup with variable sensitivity (i.e. travel
 * distance given a defined mouse travel distance).
 * <P>
 * Note: The disadvantage of this class is that the software mouse
 * pointer will typically lag behind the hardware mouse pointer 
 * location by one update period (i.e. up to 16ms for 60 UPS). 
 * This delay, albeit slight, is noticeable in terms of mouse
 * responsiveness.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class Sight extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Sight sensitivity factor, i.e. how much each pixel moved
     * by the hardware mouse pointer will equate into pixels moved
     * by the sight object.
     */
    private double sightSensitivity = 1.0;

    /**
     * Maximum travel distance in pixels during a single update
     * (a value of 1000 is effectively unreachable, i.e. by
     * default the sight speed is not limited).
     */
    private double maximumSightSpeed = 1000.0;

    /**
     * Amount of 'random' wobble to be introduced into the sight location
     */
    private double sightWobbleFactor = 0.0;

    /**
     * Amount of sight recoil following a shot
     */    
    private double sightRecoilFactor = 0.0;

    /**
     * Last x and y point of the mouse location and delta x and y
     * amounts that the mouse has moved from the last position 
     * within the update
     */    
    private int lastX, lastY;
    private double deltaX, deltaY;

    /**
     * Robot instance which will be used to rest the hardware mouse 
     * to the center of the screen
     */
    Robot mouseMover;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /** 
     * Create a new Sight instance with the specified graphical realisation
     */ 
    public Sight(GameLayer gameLayer, String sightRealisation) {
        super(gameLayer);

        // Set the name and graphical realisation. Give the game object a high
        // draw order so that it is drawn on top of other game objects
        setName("Sight");
        setRealisation(sightRealisation);
        setDrawOrder(100);

        try {
            mouseMover = new Robot();
        } catch (AWTException e) {
            System.out.println(e.toString());
            e.printStackTrace();
        }

        // Initially set the mouse to the centre of the screen
        lastX = gameEngine.screenWidth / 2;
        lastY = gameEngine.screenHeight / 2;
        mouseMover.mouseMove(lastX, lastY);
    }

    /** 
     * Return the current sight sensitivity
     */ 
    public double getSightSensitivity() {
        return sightSensitivity;
    }

    /** 
     * Set the current sight sensitivity to that specified
     */ 
    public void setSightSensitivity(double sightSensitivity) {
        this.sightSensitivity = sightSensitivity;
    }

    /** 
     * Return the current maximum sight speed 
     */ 
    public double getMaximumSightSpeed() {
        return maximumSightSpeed;
    }

    /** 
     * Set the current maximum sight speed to that specified
     */ 
    public void setMaximumSightSpeed(double maximumSightSpeed) {
        this.maximumSightSpeed = maximumSightSpeed;
    }

    /** 
     * Return the current sight recoil factor
     */ 
    public double getSightRecoilFactor() {
        return sightRecoilFactor;
    }

    /** 
     * Set the current sight recoil factor to that specified
     */ 
    public void setSightRecoilFactor(double sightRecoilFactor) {
        this.sightRecoilFactor = sightRecoilFactor;
    }

    /** 
     * Return the current sight wobble factor
     */ 
    public double getSightWobbleFactor() {
        return sightWobbleFactor;
    }

    /** 
     * Set the current sight wobble factor to that specified
     */ 
    public void setSightWobbleFactor(double sightWobbleFactor) {
        this.sightWobbleFactor = sightWobbleFactor;
    }

    /** 
     * Return the current delta x movement 
     */ 
    public double getDeltaX() {
        return deltaX;
    }

    /** 
     * Return the current delta y movement 
     */ 
    public double getDeltaY() {
        return deltaY;
    }

    /** 
     * Center the sight to the center of the screen
     */ 
    public void centerSight() {
        lastX = gameEngine.screenWidth / 2;
        lastY = gameEngine.screenHeight / 2;
        x = lastX;
        y = lastY;
        mouseMover.mouseMove(lastX, lastY);
        deltaX = 0;
        deltaY = 0;
    }

    /** 
     * Recoil the sight based upon the specified sight recoil factor
     */ 
    public void recoilSight() {
        if (sightRecoilFactor > 0.0) {
            x += sightRecoilFactor / 2.0 * (Math.random() - 0.5);
            if (x - width / 2.0 < 0.0) {
                x = width / 2.0;
            } else if (x + width / 2.0 > gameLayer.width) {
                x = gameLayer.width - width / 2.0;
            }
            y -= sightRecoilFactor / 2.0 + sightRecoilFactor / 2.0 * Math.random();
            if (y - height / 2.0 < 0.0) {
                y = height / 2.0;
            } else if (y + height / 2.0 > gameLayer.height) {
                y = gameLayer.height - height / 2.0;
            }
        }
    }

    /** 
     * Update the position of the sight based upon the amount of movement and
     * the defined parameters of the sight instance
     */ 
    @Override
    public void update() {
        // Determine how far the mouse has moved since the last update
        deltaX = sightSensitivity * (double) (inputEvent.mouseXCoordinate - lastX);
        deltaY = sightSensitivity * (double) (inputEvent.mouseYCoordinate - lastY);
        
        // If needed reduce the movement if the maximum sight movement speed
        // has been exceeded
        if (deltaX * deltaX + deltaY * deltaY > maximumSightSpeed * maximumSightSpeed) {
            double magnitude = Math.sqrt(deltaX * deltaX + deltaY * deltaY);
            deltaX = deltaX / magnitude * maximumSightSpeed;
            deltaY = deltaY / magnitude * maximumSightSpeed;
        }

        // Update the x location of the sight
        x += deltaX;
        if (x < 0.0) x = 0.0;
        else if (x > gameLayer.width) x = gameLayer.width;

        // Update the y location of the sight
        y += deltaY;
        if (y < 0.0) y = 0.0;
        else if (y > gameLayer.height) y = gameLayer.height;
        
        // If needed reset the hardware mouse location back to the centre 
        // of the screen. Update the last x and y location.
        if( inputEvent.mouseXCoordinate < gameEngine.screenWidth/2
                || inputEvent.mouseXCoordinate > gameEngine.screenWidth*3/4
                || inputEvent.mouseYCoordinate < gameEngine.screenHeight/2
                || inputEvent.mouseYCoordinate > gameEngine.screenHeight*3/4 ) {                
            lastX = gameEngine.screenWidth/2;
            lastY = gameEngine.screenHeight/2;
            mouseMover.mouseMove( lastX, lastY );            
        } else {
            lastX = inputEvent.mouseXCoordinate;
            lastY = inputEvent.mouseYCoordinate;
        }

        // Introduce sight wobble if needed
        if (sightWobbleFactor > 0.0) {
            double offset = (double) gameEngine.updateCounter / 100.0;

            x += sightWobbleFactor * Math.sin(1.75 * Math.PI 
                    * Math.cos(offset + (sightWobbleFactor > 1.0 ? 
                        Math.random() / sightWobbleFactor : Math.random())));
            y += sightWobbleFactor * Math.cos(1.75 * Math.PI 
                    * Math.sin(offset + (sightWobbleFactor > 1.0 ? 
                        Math.random() / sightWobbleFactor : Math.random())));
        }
    }
}
