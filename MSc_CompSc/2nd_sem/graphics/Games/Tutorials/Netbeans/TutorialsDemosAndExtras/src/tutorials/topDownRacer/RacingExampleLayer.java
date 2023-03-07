package tutorials.topDownRacer;

import game.engine.*;

import java.awt.*;
import java.awt.image.*;
import java.awt.geom.*;

/**
 * Racing car layer.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class RacingExampleLayer extends GameLayer {

    ///////////////////////////////////////////////////////////////////////////
    // Class Data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    // Define two z-depths, one for the track, another for the car
    private static final int Z_DEPTH_TRACK = 0;
    private static final int Z_DEPTH_CARS = 1;
    
    // Maintain a copy of the location map for easy access
    private BufferedImage trackHitRegions = null;
    
    // Store the car's last valid location and rotation. This will be used
    // as the revert value should the card try to enter into an 
    // impassable area
    private double carLastValidX;
    private double carLastValidY;
    private double carLastValidRotation;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
        
    public RacingExampleLayer( GameEngine gameEngine ) {
        super( "RacingLayer", gameEngine );
        
        createTrack();
        createCar();
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
        
    public void createTrack() {
        // Firstly create a new GameObject using the loaded track image. Setup its
        // z-depth and add it to the layer
        GameObject track = new GameObject( this );
        track.setRealisationAndGeometry( "Track" );
        track.setDrawOrder( Z_DEPTH_TRACK );
        addGameObject( track );
        
        // Position the track so that a layer x,y position cleanly maps onto
        // a map x,y position
        track.x = track.width/2;
        track.y = track.height/2;
        
        // Retreive and store a BufferedImage copy of the location map 
        // for the track
        trackHitRegions = 
                assetManager.retrieveGraphicalAsset( "TrackHitRegions" ).getImageRealisation();
    }
    
    public void createCar() {
        // Create a new racing car object and give it a name to permit ease of recall later
        RacingCar racingCar = new RacingCar( this );
        racingCar.setName( "RacingCar" );
        
        // Setup it's x and y location (to be on the starting grid) 
        // and give it  the correct z-depth
        racingCar.setPosition( 150, 350 );
        racingCar.setDrawOrder( Z_DEPTH_CARS );
        
        addGameObject( racingCar);
    }
    
    @Override
    public void update() {
        // Retrieve the car object and call its update method
        RacingCar racingCar = (RacingCar)this.getGameObject( "RacingCar" );
        racingCar.update();

        // Consider the location of the car and update as necessary
        considerCarLocation( racingCar );
    }
    
    private void considerCarLocation( RacingCar racingCar ) {
        // Work out the top middle point of the car. Within this simple
        // implementation only one point is tested. It would have been 
        // better to test four points, corresponding to each corner
        // of the car and then update as needed.
        Point carTopMiddle = new Point( 
                (int)(racingCar.x), (int)(racingCar.y-racingCar.width/2 ));
        
        // The car could be rotated, so create a new rotational transform, centered on the
        // middle of the car and rotated at the rotation of the car
        AffineTransform rotationalTransform = new AffineTransform();
        rotationalTransform.rotate( racingCar.rotation, racingCar.x, racingCar.y );
        
        // Find out the actual (i.e. current) top middle point of the car based on its rotation
        Point carTopMiddleRotated = new Point();
        rotationalTransform.transform( carTopMiddle, carTopMiddleRotated );
        
        // Get the pixel on the location map for the car location
        int pixelTopMiddleRotated = trackHitRegions.getRGB( 
                carTopMiddleRotated.x, carTopMiddleRotated.y );
        
        // If the pixel is red (ARGB) then it's on an impassable region, if the 
        // pixel is blue then it's off-road. If so, call the appropiate methods.
        if( (pixelTopMiddleRotated & 0x00ff0000) > 0 )
            carOutsideBounds( racingCar );
        else if( (pixelTopMiddleRotated & 0x000000ff) > 0 )
            carOnRough( racingCar );
                
        // Store the current 'valid' location of the car
        carLastValidX = racingCar.x;
        carLastValidY = racingCar.y;
        carLastValidRotation = racingCar.rotation;
    }
    
    private void carOutsideBounds( RacingCar racingCar ) {
        // Revert to the last known good position
        racingCar.x = carLastValidX;
        racingCar.y = carLastValidY;
        racingCar.rotation = carLastValidRotation;
                
        // Stop the car from moving
        racingCar.velocityx = 0.0;
        racingCar.velocityy = 0.0;
        racingCar.angularVelocity = 0.0;
    }
    
    private void carOnRough( RacingCar racingCar ) {
        // If the car is off-road then slow it down
        racingCar.velocityx *= 0.95;
        racingCar.velocityy *= 0.95;
        racingCar.angularVelocity *= 0.98;
    }
    
    @Override
    public void draw( Graphics2D graphics2D ) {        
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor( Color.black );
        graphics2D.fillRect( 0, 0, gameEngine.screenWidth, gameEngine.screenHeight );
        graphics2D.setColor( originalColour );
        
        super.draw( graphics2D );        
    }    
}