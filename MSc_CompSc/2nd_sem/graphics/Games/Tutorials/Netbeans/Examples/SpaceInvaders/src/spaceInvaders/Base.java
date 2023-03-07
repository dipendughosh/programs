package spaceInvaders;

import game.assets.*;
import game.engine.GameLayer;
import game.engine.GameObject;
import game.geometry.*;
import java.awt.*;
import java.awt.image.*;

/**
 * Base object used within the game.
 * <P>
 * Note: Each base maintains its own graphical realisation which is
 * updated to reflect the erosion from player and alien missiles.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2006/08 $
 */

public class Base extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the draw order of bases
     */
    protected static final int BASE_DRAW_ORDER = 2;

    /**
     * Value used to determine the erosion radius when the base is hit
     * by a missile.
     */
    private static final int ERODE_RADIUS = 5;

    /**
     * Shield image to be used by this base
     */
    private ImageAsset baseCityShield = null;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new base at the specified offset
     *
     * @param  gameLayer GameLayer to which this base will be added
     * @param  x x location at which this base should be added
     * @param  y y location at which this base should be added
     */
    public Base(GameLayer gameLayer, double x, double y) {
        super(gameLayer);

        this.x = x;
        this.y = y;
        this.drawOrder = BASE_DRAW_ORDER;

        // Construct the initial, uneroded base
        constructBase();
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Construct the base to the initial, uneroded graphical state.
     * <P>
     * Note, each base consists of two graphical assets, one an unchanging city image
     * and another a shield image.
     */
    private void constructBase() {
        ImageAsset baseCityImage = (ImageAsset) assetManager.retrieveAsset( "BaseCity" );

        // Retreive a clone of the graphical asset so that this object can erode its
        // shield image independently of any other base.
        baseCityShield = (ImageAsset) assetManager.retrieveAssetClone( "BaseShield" );

        // Define the location of the shield relative to the city.
        GraphicalAsset[] assets = {baseCityImage, this.baseCityShield};
        assets[0].offsetX = 0;
        assets[1].offsetX = 0;
        assets[0].offsetY = 0;
        assets[1].offsetY = -(baseCityImage.height - baseCityShield.height) / 2;
        setRealisation(assets);

        // Define the bounding region for this object to surround the shield image.
        setGeometry(new Box(0, -(baseCityImage.height - baseCityShield.height) / 2, 
                baseCityShield.width, baseCityShield.height));
    }

    /**
     * Consider a missile hit against the base and determine if the base needs to be
     * eroded to reflect the explosion of the missile.
     * <P>
     * Not in order to determine if the missile passes through the base object without
     * colliding with an remaining sections of the base, the mid-point of the collision
     * is used to extract a 1-pixel horizontal strip through the base and this strip
     * is then tested to see if any 'remaining' bits of the base will collide with the
     * missile. If a collision occurs, then the area around the collision point is
     * eroded (painted with an alpha value of zero).
     */
    public boolean erodeBase(Missile missile) {
        ImageAsset shieldImageAsset = (ImageAsset) this.getRealisation(1);

        // Work out the mid point of the missile hit against the shield
        double missileHitMidpoint = missile.x - this.x;

        // If necessary, adjust the mid point so that it falls within the shield
        if (missileHitMidpoint < -width / 2) {
            missileHitMidpoint = -width / 2;
        } else if (missileHitMidpoint >= width / 2) {
            missileHitMidpoint = width / 2 - 1.0;
        }
        
        // Grab a horizontal 1 pixel wide strip of pixels
        // through the image at the point of missile contact
        BufferedImage shieldImage = shieldImageAsset.getImageRealisation();
        int[] baseImageSamples = new int[shieldImage.getHeight()];
        shieldImage.getRGB( (int)(missileHitMidpoint + width/2), 0, 
                1, shieldImage.getHeight(), baseImageSamples, 0, 1 );
       
        // Determine if the missile hits from above (alien fired) or below (player fired)
        // and setup the search offset accordingly
        int searchIncrement = (missile instanceof PlayerMissile) ? -1 : 1;
        int searchOffset = (missile instanceof PlayerMissile) 
                ? baseImageSamples.length - 1 : 0;

        // Search through the pixel strip and determine if we have a pixel with an
        // alpha value > 0 (i.e. the missile will hit something)
        boolean missileHit = false;
        while (!missileHit && searchOffset >= 0 
                && searchOffset <= baseImageSamples.length - 1) {
            // Extract the alpha channel from the base pixel
            int testPixelAlpha = (baseImageSamples[searchOffset] >> 24) & 0xff;
            if (testPixelAlpha > 0) {
                missileHit = true;
            } else {
                searchOffset += searchIncrement;
            }
        }

        // If we have a hit, then paint using an alpha value of zero to erode the base image
        if (missileHit == true) {
            Graphics2D graphics2D = shieldImage.createGraphics();

            Color transparentColour = new Color(0, 0, 0, 0);
            graphics2D.setColor(transparentColour);
            graphics2D.setComposite(AlphaComposite.Src);

            graphics2D.fillOval((int) (missileHitMidpoint + width/2) - ERODE_RADIUS, 
                    searchOffset - ERODE_RADIUS, ERODE_RADIUS * 2, ERODE_RADIUS * 2);
            graphics2D.dispose();
        }

        if (missileHit) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * Reconstruct the base to the original 'uneroded' status
     */
    public void reformBase() {
        this.constructBase();
    }
}
