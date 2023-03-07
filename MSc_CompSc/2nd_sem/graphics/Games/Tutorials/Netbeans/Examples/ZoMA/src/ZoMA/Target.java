package ZoMA;

import game.assets.*;
import game.engine.*;
import game.geometry.*;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import java.util.*;

/**
 * Target provides a generic form of target object that has a certain number of hits
 * regions, and can move using a number of different movement patterns.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.1 $ $Date: 2007/08 $
 */

public class Target extends GameObject {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the different types of movement pattern that are supported by
     * this class, alongside the current active type of movement pattern
     */
    public enum MovementType {
        Static, HorizontalRegular, HorizontalIrregular, VerticalRegular, 
        VerticalIrregular, CircularRegular, CurvedRandom, LinearRandom }
    private MovementType movementType;

    /**
     * Graphical asset used to represent this target, alongside a draw
     * scale factor for the target.
     */
    private String targetHitImageAsset = null;
    private double targetSizeScaleFactor = 1.0;

    /**
     * Define the hit region weightings of each item of geometry, i.e.
     * the score multiplier for hitting each item of geometry within the 
     * target
     */
    private double[] hitRegionWeightings;

    /**
     * The different movement types can be sub-divided into those which 
     * are based on harmonic movement and those which are not
     */
    private boolean useHarmonicMovement = false;

    /**
     * Define parameters used to control non-harmonic forms of movement,
     * described in terms of a base velocity which is subject to a degree
     * of variation with a defined abruptness to the variation and a 
     * similiar set of parameters relating to rotational velocity
     */
    private double velBase, velVariation, velAbruptnessOffset;
    private double turnBase, turnVariation, turnAbruptnessOffset;
    private double velCurrent, velChange, turnCurrent, turnChange, heading;
    private int velAbruptness, turnAbruptness;
    
    /**
     * Define parameters used to control harmonic forms of movement, 
     * described in terms of base harmonic width and height and a number 
     * of related sinusoidal harmonics
     */
    private double baseX, baseY, baseHarmonicWidth, baseHarmonicHeight;
    private long sinusoidalPeriod;
    private int numXHarmonics, numYHarmonics;
    private double xAngularOffset, yAngularOffset;


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new target instance
     */ 
    public Target(GameLayer gameLayer, String realisationName, 
            Shape[] hitRegions, double[] hitRegionWeightings) {
        super(gameLayer);

        defineMovementType(MovementType.Static);
        defineTargetPositionRealisationAndGeometry(
                realisationName, hitRegions, hitRegionWeightings);
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Define the target's position, realisation and geometry
     */ 
    public void defineTargetPositionRealisationAndGeometry(
            String realisationName, Shape[] hitRegions, double[] hitRegionWeightings) {
        // Set the position to that specified
        setPosition(x, y);
        baseX = x; baseY = y;

        if (hitRegions.length != hitRegionWeightings.length)
            throw new IllegalArgumentException("Target.defineTargetRealisationAndGeometry: " + 
                    "Hit regions and hit region weightings of differing sizes");
        
        // Set the realiation, geometry and associated hit region weightings
        setRealisation(assetManager.retrieveGraphicalAsset(realisationName));
        setGeometry(hitRegions);
        this.hitRegionWeightings = hitRegionWeightings;
    }

    /**
     * Define the movement pattern to be used by this target
     */ 
    public void defineMovementType(MovementType movementType) {
        this.movementType = movementType;

        switch (movementType) {
            case Static:
                useHarmonicMovement = false;
                velBase = 0.0; velVariation = 0.0; velAbruptness = Integer.MAX_VALUE;
                turnBase = 0.0; turnVariation = 0.0; turnAbruptness = Integer.MAX_VALUE;
                velCurrent = 0.0; velChange = 0.0; 
                turnCurrent = 0.0; turnChange = 0.0; heading = 0.0;
                updateVelocityPhased();
                break;
            case HorizontalRegular:
                useHarmonicMovement = true;
                baseHarmonicWidth = 250.0; baseHarmonicHeight = 0.0; 
                sinusoidalPeriod = 60; numXHarmonics = 1; 
                xAngularOffset = 0.0; numYHarmonics = 0; yAngularOffset = 0.0;
                break;
            case HorizontalIrregular:
                useHarmonicMovement = false;
                velBase = 250.0; velVariation = 0.0; velAbruptness = 20;
                turnBase = 0.0; turnVariation = 0.0; turnAbruptness = Integer.MAX_VALUE;
                velCurrent = 0.0; velChange = 0.0;
                turnCurrent = 0.0; turnChange = 0.0; heading = 0.0;
                updateVelocityPhased();
                break;
            case VerticalRegular:
                useHarmonicMovement = true;
                baseHarmonicWidth = 0.0; baseHarmonicHeight = 250.0;
                sinusoidalPeriod = 120; numXHarmonics = 0;
                xAngularOffset = 0.0; numYHarmonics = 1; yAngularOffset = 0.0;
                break;
            case VerticalIrregular:
                useHarmonicMovement = false;
                velBase = 250.0; velVariation = 0.0; velAbruptness = 20;
                turnBase = 0.0; turnVariation = 0.0; turnAbruptness = Integer.MAX_VALUE;
                velCurrent = 0.0; velChange = 0.0;
                turnCurrent = 0.0; turnChange = 0.0; heading = -Math.PI / 2.0;
                updateVelocityPhased();
                break;
            case CircularRegular:
                useHarmonicMovement = true;
                baseHarmonicWidth = 125.0; baseHarmonicHeight = 125.0;
                sinusoidalPeriod = 120; numXHarmonics = 1;
                xAngularOffset = 0.0; numYHarmonics = 1; yAngularOffset = 0.0;
                break;
            case CurvedRandom:
                useHarmonicMovement = false;
                velBase = 80.0; velVariation = 1.0; velAbruptness = 30;
                turnBase = 0.125; turnVariation = 0.75; turnAbruptness = 60;
                velCurrent = 0.0; velChange = 0.0;
                turnCurrent = 0.0; turnChange = 0.0; heading = 0.0;
                updateVelocityPhased();
                break;
            case LinearRandom:
                useHarmonicMovement = false;
                velBase = 80.0; velVariation = 1.0; velAbruptness = 20;
                turnBase = 0.1; turnVariation = 0.75; turnAbruptness = 10;
                velCurrent = 0.0; velChange = 0.0;
                turnCurrent = 0.0; turnChange = 0.0; heading = 0.0;
                updateVelocityPhased();
                break;
            default:
                throw new IllegalStateException("Target.defineMovementType: " + 
                        "Unsupport movement type [" + movementType + "]");
        }

        if (!useHarmonicMovement) {
            velAbruptnessOffset = (new Random()).nextInt(velAbruptness);
            turnAbruptnessOffset = (new Random()).nextInt(turnAbruptness);
        }
    }

    /**
     * Define the difficulty level to be applied to the target's movement
     * pattern.
     * <P>
     * Note: It is assumed the difficulty level will be an integer in the 
     * range of 1 to 10.
     */     
    public void defineDifficultyLevel(int difficultyLevel) {
        if (useHarmonicMovement) {
            baseHarmonicWidth *= 1.0 + ((double) difficultyLevel / 5.0 - 1.0) / 5.0;
            baseHarmonicHeight *= 1.0 + ((double) difficultyLevel / 5.0 - 1.0) / 5.0;
            sinusoidalPeriod = (long) ((double)sinusoidalPeriod / ((double)difficultyLevel / 5.0));
        } else {
            velBase *= Math.pow(2.0, (difficultyLevel - 5.0) / 2.0);
        }
    }

    /**
     * Get the current target scale factor 
     */     
    public double getTargetSizeScaleFactor() {
        return targetSizeScaleFactor;
    }

    /**
     * Set the target scale factor to that specified
     */     
    public void setTargetSizeScaleFactor(double newTargetSizeScaleFactor) {
        // Scale each item of geometry based on the specified scale factor
        double relativeScaleFactor = newTargetSizeScaleFactor / targetSizeScaleFactor;
        for (int geomIdx = 0; geomIdx < geometry.length; geomIdx++) {
            geometry[geomIdx].offsetX *= relativeScaleFactor;
            geometry[geomIdx].offsetY *= relativeScaleFactor;

            if (geometry[geomIdx] instanceof Circle) {
                Circle circle = (Circle) geometry[geomIdx];
                circle.setRadius(circle.radius * relativeScaleFactor);
            } else if (geometry[geomIdx] instanceof Box) {
                Box box = (Box) geometry[geomIdx];
                box.setDimensions(box.width * relativeScaleFactor, 
                        box.height * relativeScaleFactor);
            } else {
                throw new IllegalStateException("Target.setTargetSizeScaleFactor: " +
                        "Unknown geometry type");
            }
        }

        targetSizeScaleFactor = newTargetSizeScaleFactor;
        setGeometry(geometry);
    }

    /**
     * Set the target hit image asset to that specified
     */     
    public void setTargetHitImageAsset(String targetHitImageAsset) {
        this.targetHitImageAsset = targetHitImageAsset;
    }

    /**
     * Setup the position of the target to that specified
     */ 
    @Override
    public void setPosition(double x, double y) {
        super.setPosition(x, y);
        setBaseXandY(x, y);
    }

    /**
     * Setup the base x and y for the target (this is used to 
     * provide a reference point for harmonic forms of movement)
     */ 
    public void setBaseXandY(double baseX, double baseY) {
        this.baseX = baseX;
        this.baseY = baseY;
    }

    /**
     * Consider a shot against the target at the specified x and y offset, 
     * relative to this object. The return value specifies the nature of the
     * hit - a value of 0.0 is returned if the target was missed, otherwise
     * a value will be returned based on the highest weighting assigned to
     * an item of geometry that received the shot. If the target has
     * been hit, then a hit image will be added to the target.
     */    
    public double considerTargetHit(double offsetX, double offsetY) {
        double hitWeighting = testTargetHit(offsetX, offsetY);

        if (hitWeighting > 0.0) {
            GraphicalAsset[] newRealisation 
                    = new GraphicalAsset[graphicalRealisation.length + 1];            
            for (int idx = 0; idx < graphicalRealisation.length; idx++) {
                newRealisation[idx] = graphicalRealisation[idx];
            }
            
            // If the target has been hit, then add a hit image decal to the target
            ImageAssetSequence hitImage 
                    = (ImageAssetSequence) assetManager.retrieveAsset( targetHitImageAsset );
            hitImage.offsetX = offsetX / targetSizeScaleFactor;
            hitImage.offsetY = offsetY / targetSizeScaleFactor;
            hitImage.setHomeFrame((new Random()).nextInt(hitImage.getNumberOfImages()));
            newRealisation[newRealisation.length - 1] = hitImage;

            setRealisation(newRealisation);
        }

        return hitWeighting;
    }

    /**
     * Test a shot against the target at the specified x and y offset, 
     * relative to this object. The return value specifies the nature of the
     * hit - a value of 0.0 is returned if the target was missed, otherwise
     * a value will be returned based on the highest weighting assigned to
     * an item of geometry that received the shot. No changes will be 
     * made to the target if the tested offset is a hit.
     */    
    public double testTargetHit(double offsetX, double offsetY) {
        double hitWeighting = 0.0;

        for (int geomIdx = 0; geomIdx < geometry.length; geomIdx++) {
            if (geometry[geomIdx] instanceof Circle) {
                Circle circle = (Circle) geometry[geomIdx];
                if (Math.pow(offsetX - circle.offsetX, 2) + 
                                Math.pow(offsetY - circle.offsetY, 2) 
                            < Math.pow(circle.radius, 2) 
                        && hitRegionWeightings[geomIdx] > hitWeighting) {
                    hitWeighting = hitRegionWeightings[geomIdx];
                }
            } else if (geometry[geomIdx] instanceof Box) {
                Box box = (Box) geometry[geomIdx];
                if (Math.abs(offsetX - box.offsetX) <= box.width / 2.0 
                        && Math.abs(offsetY - box.offsetY) <= box.height / 2.0 
                        && hitRegionWeightings[geomIdx] > hitWeighting) {
                    hitWeighting = hitRegionWeightings[geomIdx];
                }
            } else {
                throw new IllegalStateException("Target.getTagetHitWeighting: " + 
                        "Unknown geometry type");
            }
        }

        return hitWeighting;
    }

    /**
     * Update the target's position
     */ 
    @Override
    public void update() {
        if (useHarmonicMovement) {
            updatePositioHarmonic();
        } else {
            updatePositionPhased();
        }
    }

    /**
     * Update the target's position if using a non-harmonic form of movement,
     * i.e. one that is separated into a number of different phases
     */ 
    private void updatePositionPhased() {
        // Update velocity if needed
        if (gameEngine.updateCounter % velAbruptness == velAbruptnessOffset)
            updateVelocityPhased();

            // Update heading if needed
        if (gameEngine.updateCounter % turnAbruptness == turnAbruptnessOffset)
            updateTurnPhase();

        // Update turn and velocty and map onto x/y velocities
        velCurrent += velChange;
        turnCurrent += turnChange;
        heading += turnCurrent;

        velocityx = velCurrent * Math.cos(heading);
        velocityy = velCurrent * Math.sin(heading);

        updatePositionAndRotation(1.0 / 
                (double) (gameEngine.getGameUpdatePeriod()/1000000));

        if (GameObjectUtilities.reboundIfGameLayerExited(this)) {
            velCurrent = -velCurrent;
            velChange = -velChange;

            turnCurrent = -turnCurrent;
            turnChange = -turnChange;
        }
    }

    /**
     * Update the target's velocity if using a non-harmonic form of movement,
     * i.e. one that is separated into a number of different phases
     */     
    private void updateVelocityPhased() {
        double velHalfRange = velBase * velVariation;
        double velTarget = velBase - velHalfRange + 2.0 * velHalfRange * Math.random();
        if (Math.random() > 0.5) {
            velTarget = -velTarget;
        }
        velChange = (velTarget - velCurrent) / velAbruptness;
    }

    /**
     * Update the target's angular velocity if using a non-harmonic form of 
     * movement, i.e. one that is separated into a number of different phases
     */     
    private void updateTurnPhase() {
        double turnHalfRange = turnBase * turnVariation;
        double turnTarget = turnBase - turnHalfRange + 
                2.0 * turnHalfRange * Math.random() - turnBase / 2.0;
        turnChange = (turnTarget - turnCurrent) / turnAbruptness;
    }

    /**
     * Update the target's position if using an harmonic form of movement
     */     
    private void updatePositioHarmonic() {
        double periodOffset = 4.0 * Math.PI * 
                (double) (gameEngine.updateCounter % sinusoidalPeriod) 
                    / (double) sinusoidalPeriod;

        this.x = baseX;
        for (int harmonicIdx = 0; harmonicIdx < numXHarmonics; harmonicIdx++) {
            double harmonic = Math.pow(2.0, harmonicIdx - 1);
            this.x += baseHarmonicWidth / harmonic 
                    * Math.sin(periodOffset * harmonic + xAngularOffset);
        }

        this.y = baseY;
        for (int harmonicIdx = 0; harmonicIdx < numYHarmonics; harmonicIdx++) {
            double harmonic = Math.pow(2.0, harmonicIdx - 1);
            this.y += baseHarmonicHeight / harmonic 
                    * Math.cos(periodOffset * harmonic + yAngularOffset);
        }
    }

    /**
     * Draw the target to the specified graphics object at the specified offset
     */
    @Override
    public void draw(Graphics2D graphics2D, int drawX, int drawY) {
        if (this.graphicalRealisation.length == 0)
            return;
        
        // Record the original graphics affine transform
        AffineTransform originalAffineTransofrm = graphics2D.getTransform();

        // Create a new affine rotational transform centered on the
        // middle of the object and use this for the graphics object
        AffineTransform rotationAffineTransform = new AffineTransform();
        rotationAffineTransform.rotate(this.rotation, drawX, drawY);
        graphics2D.transform(rotationAffineTransform);
        graphics2D.transform(AffineTransform.getScaleInstance(
                targetSizeScaleFactor, targetSizeScaleFactor));

        for (int idx = 0; idx < this.graphicalRealisation.length; idx++) {
            this.graphicalRealisation[idx].draw(graphics2D, 
                    (int) (drawX/targetSizeScaleFactor + this.graphicalRealisation[idx].offsetX) 
                        - this.graphicalRealisation[idx].width / 2, 
                    (int) (drawY/targetSizeScaleFactor + (int)this.graphicalRealisation[idx].offsetY) 
                        - this.graphicalRealisation[idx].height / 2);
        }
        
        // Restore the original graphics affine transform
        graphics2D.setTransform(originalAffineTransofrm);
    }
}