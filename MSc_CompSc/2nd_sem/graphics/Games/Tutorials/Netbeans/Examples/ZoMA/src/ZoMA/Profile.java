package ZoMA;

import java.io.Serializable;

/**
 * Profile provides a serializable object holding the Zoma profile,
 * i.e. the set of statistics collected on the particular player,
 * alongside rank information and rank requirements.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class Profile implements Serializable {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////
   
    /**
     * Player's profile name
     */
    private String profileName;

    /**
     * Defined ranks and associated current ranks across
     * the ranked test categories.
     */
    public enum Rank { 
        Unranked, Rank1, Rank2, Rank3, Rank4, Rank5, Rank6 }
    private Rank reactionTimeRank = Rank.Unranked;
    private Rank snapShotRank = Rank.Unranked;
    private Rank trackingRank = Rank.Unranked;
    private Rank sniperShotRank = Rank.Unranked;

    /**
     * Current screen dimensions (used to determine the particular
     * quadrent that a click location belongs to).
     */
    private int screenWidth = 0, screenHeight = 0;

    /**
     * Statistics realting to reaction tests (total are maintained
     * for the number of reaction tests against defined time categories
     */
    private int totalReactionTests = 0;
    
    private int total_Sub_150 = 0, total_150_200 = 0, total_200_250 = 0;
    private int total_250_300 = 0, total_300_350 = 0, total_Grt_350 = 0;

    /**
     * Statistics relating to snap shot tests. Snap shots statitics
     * are grouping according to the target accuracy and also the 
     * accuracy and time in relation to where the target appears on 
     * the screen.
     */
    private int totalSnapShots = 0;    
    
    private long totalReactionTime = 0, totalShotTime = 0;

    private int totalBand1Hits = 0, totalBand2Hits = 0, totalBand3Hits = 0;
    private int totalBand4Hits = 0, totalBandMiss = 0;

    private int totalFTRHits = 0, totalFTLHits = 0, totalNTRHits = 0; 
    private int totalNTLHits = 0, totalFBRHits = 0, totalFBLHits = 0;
    private int totalNBRHits = 0, totalNBLHits = 0;

    private int totalFTRShots = 0, totalFTLShots = 0, totalNTRShots = 0;
    private int totalNTLShots = 0, totalFBRShots = 0, totalFBLShots = 0;
    private int totalNBRShots = 0, totalNBLShots = 0;

    private long totalFTRTime = 0, totalFTLTime = 0, totalNTRTime = 0;
    private long totalNTLTime = 0, totalFBRTime = 0, totalFBLTime = 0;
    private long totalNBRTime = 0, totalNBLTime = 0;

    /**
     * Statistics relating to tracking tests (totals are kept of the
     * total amount of track time vs. on target and on bull time for
     * each difficulty level).
     */
    private int totalTrackms = 0;
    
    private static final int NUM_TRACK_LEVELS = 6;
    private int[] totalTrackmsLevel = new int[NUM_TRACK_LEVELS];
    private int[] totalTrackBullmsLevel = new int[NUM_TRACK_LEVELS];
    private int[] totalTrackTargetmsLevel = new int[NUM_TRACK_LEVELS];

    /**
     * Statistics relating to sniper tests (totals are kept of the
     * total number of shots vs. on target and head shot percentages).
     */
    private int totalSniperShots = 0;

    private static final int NUM_SNIPER_LEVELS = 6;
    
    private int[] totalSniperShotsLevel = new int[NUM_SNIPER_LEVELS];
    private int[] totalHeadShotsLevel = new int[NUM_SNIPER_LEVELS];
    private int[] totalBodyShotsLevel = new int[NUM_SNIPER_LEVELS];


    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new profile instance
     */
    public Profile(String profileName, int screenWidth, int screenHeight) {
        setProfileName(profileName);
        setScreenDimensions(screenWidth, screenHeight);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: get/set methods                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Return the profile name
     */
    public String getProfileName() {
        return profileName;
    }

    /**
     * Set the profile name to that specified
     */
    public void setProfileName(String profileName) {
        this.profileName = profileName;
    }

    /**
     * Set the screen dimensions to those specified
     */    
    public void setScreenDimensions(int screenWidth, int screenHeight) {
        this.screenWidth = screenWidth;
        this.screenHeight = screenHeight;
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Reaction time test statistics                                //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Record details of the reaction time test result
     */
    public void recordReactionTimeTest(int reactionTime) {
        totalReactionTests++;

        if (reactionTime < 150) {
            total_Sub_150++;
        } else if (reactionTime < 200) {
            total_150_200++;
        } else if (reactionTime < 250) {
            total_200_250++;
        } else if (reactionTime < 300) {
            total_250_300++;
        } else if (reactionTime < 350) {
            total_300_350++;
        } else {
            total_Grt_350++;
        }
    }    

    public boolean considerReactionTimeTestForRank(Rank rank, int averageReactionTime) {
        boolean testPassed = false;
        if (averageReactionTime <= getAverageReactionTimeForRank(rank)) {
            testPassed = true;
            if (isHigherRank(reactionTimeRank, rank)) reactionTimeRank = rank;
        }
        return testPassed;
    }    
    
    public int getNumTotalReactionTests() { return totalReactionTests; }
    public int getNumReactionTestsSub150ms() { return total_Sub_150; }
    public int getNumReactionTests150To200ms() { return total_150_200; }
    public int getNumReactionTests200To250ms() { return total_200_250; }
    public int getNumReactionTests250To300ms() { return total_250_300; }
    public int getNumReactionTests300To350ms() { return total_300_350; }
    public int getNumReactionTestsMoreThan350ms() { return total_Grt_350; }

    public double getPercentageTotalReactionTests() { return 100.0 * (double) totalReactionTests / (double) totalReactionTests; }
    public double getPercentageReactionTestsSub150ms() { return 100.0 * (double) total_Sub_150 / (double) totalReactionTests; }
    public double getPercentageReactionTests150To200ms() { return 100.0 * (double) total_150_200 / (double) totalReactionTests; }
    public double getPercentageReactionTests200To250ms() { return 100.0 * (double) total_200_250 / (double) totalReactionTests; }
    public double getPercentageReactionTests250To300ms() { return 100.0 * (double) total_250_300 / (double) totalReactionTests; }
    public double getPercentageReactionTests300To350ms() { return 100.0 * (double) total_300_350 / (double) totalReactionTests; }
    public double getPercentageReactionTestsMoreThan350ms() { return 100.0 * (double) total_Grt_350 / (double) totalReactionTests; }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Snap shot test statistics                                    //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Record details of the snap shot test result
     * 
     * @param targetX mouse x click location
     * @param targetY mouse y click location
     * @param reactionTime reaction time in ms (i.e. time to move mouse)
     * @param shotTime shot time in ms (i.e. time to shoot mouse)
     * @param hitRegion region of the target that got hit
     */
    public void recordSnapShot
            (int targetX, int targetY, int reactionTime, int shotTime, int hitRegion) {
        totalSnapShots++;
        
        totalReactionTime += reactionTime;
        totalShotTime += shotTime;

        if (hitRegion == 1) totalBand1Hits++;
        else if (hitRegion == 2) totalBand2Hits++;
        else if (hitRegion == 3) totalBand3Hits++;
        else if (hitRegion == 4) totalBand4Hits++;
        else totalBandMiss++;

        // Determine the region of the mouse click (i.e. top of screen, bottom
        // of screen, left or right region, near or far from the screen centre
        boolean top = targetY < screenHeight / 2 ? true : false;
        boolean left = targetX < screenWidth / 2 ? true : false;
        boolean near = (Math.abs(targetX - screenWidth / 2) < screenWidth / 4 
                && Math.abs(targetY - screenHeight / 2) < screenHeight / 4) ? true : false;

        // Update the region hit location count and hit time
        if (near) {
            if (top) {
                if (left) {
                    totalNTLShots++;
                    if (hitRegion >= 1) { totalNTLHits++; totalNTLTime += shotTime; }
                } else {
                    totalNTRShots++;
                    if (hitRegion >= 1) { totalNTRHits++; totalNTRTime += shotTime; }
                }
            } else {
                if (left) {
                    totalNBLShots++;
                    if (hitRegion >= 1) { totalNBLHits++; totalNBLTime += shotTime; }
                } else {
                    totalNBRShots++;
                    if (hitRegion >= 1) { totalNBRHits++; totalNBRTime += shotTime; }
                }
            }
        } else {
            if (top) {
                if (left) {
                    totalFTLShots++;
                    if (hitRegion >= 1) { totalFTLHits++; totalFTLTime += shotTime; }
                } else {
                    totalFTRShots++;
                    if (hitRegion >= 1) { totalFTRHits++; totalFTRTime += shotTime; }
                }
            } else {
                if (left) {
                    totalFBLShots++;
                    if (hitRegion >= 1) { totalFBLHits++; totalFBLTime += shotTime; }
                } else {
                    totalFBRShots++;
                    if (hitRegion >= 1) { totalFBRHits++; totalFBRTime += shotTime; }
                }
            }
        }
    }

    public boolean considerSnapShotTestForRank(
            Rank rank, int averageShotTime, double averageShotAccuracy) {
        boolean testPassed = false;
        if (averageShotTime <= getAverageSnapShotTimeForRank(rank) 
                && averageShotAccuracy >= getSnapShotTargetAccuracyForRank(rank) / 100.0) {
            testPassed = true;
            if (isHigherRank(snapShotRank, rank)) snapShotRank = rank;
        }
        return testPassed;
    }
    
    public int getTotalSnapShots() { return totalSnapShots; }

    public double getAverageReactionTime() { return (double) totalReactionTime / (double) totalSnapShots; }
    public double getAverageShotTime() { return (double) totalShotTime / (double) totalSnapShots; }

    public double getBand1HitPercentage() { return 100.0 * (double) totalBand1Hits / (double) totalSnapShots; }
    public double getBand2HitPercentage() { return 100.0 * (double) totalBand2Hits / (double) totalSnapShots; }
    public double getBand3HitPercentage() { return 100.0 * (double) totalBand3Hits / (double) totalSnapShots; }
    public double getBand4HitPercentage() { return 100.0 * (double) totalBand4Hits / (double) totalSnapShots; }
    public double getBandMissPercentage() { return 100.0 * (double) totalBandMiss / (double) totalSnapShots; }
    public double getTargetHitPercentage() { return 100.0 - 100.0 * (double) totalBandMiss / (double) totalSnapShots; }


    public double getFarTopRightShotAccuracy() { return totalFTRShots == 0 ? 0.0 : 100.0 * (double) totalFTRHits / (double) totalFTRShots; }
    public double getFarTopLeftShotAccuracy() { return totalFTLShots == 0 ? 0.0 : 100.0 * (double) totalFTLHits / (double) totalFTLShots; }
    public double getFarBottomRightShotAccuracy() { return totalFBRShots == 0 ? 0.0 : 100.0 * (double) totalFBRHits / (double) totalFBRShots; }
    public double getFarBottomLeftShotAccuracy() { return totalFBLShots == 0 ? 0.0 : 100.0 * (double) totalFBLHits / (double) totalFBLShots; }
    public double getNearTopRightShotAccuracy() { return totalNTRShots == 0 ? 0.0 : 100.0 * (double) totalNTRHits / (double) totalNTRShots; }
    public double getNearTopLeftShotAccuracy() { return totalNTLShots == 0 ? 0.0 : 100.0 * (double) totalNTLHits / (double) totalNTLShots; }
    public double getNearBottomRightShotAccuracy() { return totalNBRShots == 0 ? 0.0 : 100.0 * (double) totalNBRHits / (double) totalNBRShots; }
    public double getNearBottomLeftShotAccuracy() { return totalNBLShots == 0 ? 0.0 : 100.0 * (double) totalNBLHits / (double) totalNBLShots; }

    public double getFarTopRightShotTime() { return totalFTRHits == 0 ? 0.0 : (double) totalFTRTime / (double) totalFTRHits; }
    public double getFarTopLeftShotTime() { return totalFTLHits == 0 ? 0.0 : (double) totalFTLTime / (double) totalFTLHits; }
    public double getFarBottomRightShotTime() { return totalFBRHits == 0 ? 0.0 : (double) totalFBRTime / (double) totalFBRHits; }
    public double getFarBottomLeftShotTime() { return totalFBLHits == 0 ? 0.0 : (double) totalFBLTime / (double) totalFBLHits; }
    public double getNearTopRightShotTime() { return totalNTRHits == 0 ? 0.0 : (double) totalNTRTime / (double) totalNTRHits; }
    public double getNearTopLeftShotTime() { return totalNTLHits == 0 ? 0.0 : (double) totalNTLTime / (double) totalNTLHits; }
    public double getNearBottomRightShotTime() { return totalNBRHits == 0 ? 0.0 : (double) totalNBRTime / (double) totalNBRHits; }
    public double getNearBottomLeftShotTime() { return totalNBLHits == 0 ? 0.0 : (double) totalNBLTime / (double) totalNBLHits; }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Tracking test statistics                                     //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Record details of the tracking test result
     * 
     * @param rank Rank of the recorded test
     * @param trackms number of ms of recorded taget tracking
     * @param trackTargetms number of ms of recorded track time on the target
     * @param trackBullms number of ms of recorded track time on the bull
     */    
    public void recordTrackingTest(
            Rank rank, int trackms, int trackTargetms, int trackBullms) {
        int levelIdx = Integer.parseInt(rank.toString().substring(4, 5)) - 1;

        totalTrackms += trackms;

        totalTrackmsLevel[levelIdx] += trackms;
        totalTrackBullmsLevel[levelIdx] += trackTargetms;
        totalTrackTargetmsLevel[levelIdx] += trackBullms;
    }

    public boolean considerTrackingTestForRank(
            Rank rank, double onTargetPercentage, double onBullPercentage) {
        boolean testPassed = false;
        if (onTargetPercentage >= getTargetTrackingAccuracyForRank(rank) / 100.0 
                && onBullPercentage >= getBullTrackingAccuracyForRank(rank) / 100.0) {
            testPassed = true;
            if (isHigherRank(trackingRank, rank)) trackingRank = rank;
        }
        return testPassed;
    }
    
    public int getTotalTrackSeconds() { return totalTrackms / 1000; }

    public int getTotalTrackSecondsForLevel(int level) {
        if (level < 0 || level >= NUM_TRACK_LEVELS)
            throw new IllegalArgumentException("Profile.getTotalTrackSecondsForLevel: " + 
                    "Invalid level [" + level + "]");
        
        return totalTrackmsLevel[level];
    }

    public double getPercentageBullTrackTimeForLevel(int level) {
        if (level < 0 || level >= NUM_TRACK_LEVELS)
            throw new IllegalArgumentException("Profile.getPercentageBullTrackTimeForLevel: " + 
                    "Invalid level [" + level + "]");
        
        if (totalTrackmsLevel[level] == 0)
            return 0.0;
        else
            return 100.0 * (double) totalTrackBullmsLevel[level] / (double) totalTrackmsLevel[level];
    }

    public double getPercentageTargetTrackTimeForLevel(int level) {
        if (level < 0 || level >= NUM_TRACK_LEVELS) 
            throw new IllegalArgumentException("Profile.getPercentageTargetTrackTimeForLevel: " + 
                    "Invalid level [" + level + "]");
        
        if (totalTrackmsLevel[level] == 0)
            return 0.0;
        else
            return 100.0 * (double) totalTrackTargetmsLevel[level] / (double) totalTrackmsLevel[level];
    }

    public double getPercentageMissTrackTimeForLevel(int level) {
        return 100.0 - getPercentageTargetTrackTimeForLevel(level);
    }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Sniper shot test statistics                                  //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Record details of the sniper test result
     * 
     * @param rank Rank of the recorded test
     * @param hitRegion region that the sniper shot landed
     */        
    public void recordSniperShot(Rank rank, int hitRegion) {
        int levelIdx = Integer.parseInt(rank.toString().substring(4, 5)) - 1;

        totalSniperShots++;

        totalSniperShotsLevel[levelIdx] += 1;
        if (hitRegion > 0) totalBodyShotsLevel[levelIdx] += 1;
        if (hitRegion > 1) totalHeadShotsLevel[levelIdx] += 1;
    }

    public boolean considerSniperShotTestForRank(
            Rank rank, double onBodyPercentage, double onHeadPercentage) {
        boolean testPassed = false;
        if (onBodyPercentage >= getBodyShotsAccuracyForRank(rank) / 100.0 
                && onHeadPercentage >= getHeadShotsAccuracyForRank(rank) / 100.0) {
            testPassed = true;
            if (isHigherRank(sniperShotRank, rank)) sniperShotRank = rank;
        }
        return testPassed;
    }

    public int getTotalSniperShots() { return totalSniperShots; }

    public int getTotalSniperShotsForLevel(int level) {
        if (level < 0 || level >= NUM_SNIPER_LEVELS)
            throw new IllegalArgumentException("Profile.getTotalSniperShotsForLevel: " + 
                    "Invalid level [" + level + "]");
        
        return totalSniperShotsLevel[level];
    }

    public double getPercentageHeadShotsForLevel(int level) {
        if (level < 0 || level >= NUM_SNIPER_LEVELS )
            throw new IllegalArgumentException("Profile.getPercentageHeadShotsForLevel: " + 
                    "Invalid level [" + level + "]");

        if (totalSniperShotsLevel[level] == 0)
            return 0.0;
        else
            return 100.0 * (double) totalHeadShotsLevel[level] / (double) totalSniperShotsLevel[level];
    }

    public double getPercentageBodyShotsForLevel(int level) {
        if (level < 0 || level >= NUM_SNIPER_LEVELS ) 
            throw new IllegalArgumentException("Profile.getPercentageBodyShotsForLevel: " + 
                    "Invalid level [" + level + "]");
        
        if (totalSniperShotsLevel[level] == 0)
            return 0.0;
        else
            return 100.0 * (double) totalBodyShotsLevel[level] / (double) totalSniperShotsLevel[level];
    }

    public double getPercentageMissShotsForLevel(int level) {
        return 100.0 - getPercentageBodyShotsForLevel(level);
    }


    ///////////////////////////////////////////////////////////////////////////
    // Methods: Rank information                                             //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Return information on the current rank and next rank level and 
     * associated requirements
     */
    public Rank getReactionTimeRank() { return reactionTimeRank; }
    public Rank getSnapShotRank() { return snapShotRank; }
    public Rank getTrackingRank() { return trackingRank; }
    public Rank getSniperShotRank() { return sniperShotRank; }

    public Rank getNextReactionTimeRank() { return getNextRank(reactionTimeRank); }
    public Rank getNextSnapShotRank() { return getNextRank(snapShotRank); }
    public Rank getNextTrackingRank() { return getNextRank(trackingRank); }
    public Rank getNextSniperShotRank() { return getNextRank(sniperShotRank); }

    private Rank getNextRank( Rank curentRank ) {
        Rank nextRank = null;
        switch (curentRank) {
            case Unranked: nextRank = Rank.Rank1; break;
            case Rank1: nextRank = Rank.Rank2; break;
            case Rank2: nextRank = Rank.Rank3; break;
            case Rank3: nextRank = Rank.Rank4; break;
            case Rank4: nextRank = Rank.Rank5; break;
            case Rank5: nextRank = Rank.Rank6; break;
            case Rank6: nextRank = null; break;
        }
        return nextRank;        
    }
    
    public static int getAverageReactionTimeForRank(Rank rank) {
        int averageReactionTimeForRank = 0;
        switch (rank) {
            case Rank1: averageReactionTimeForRank = 300; break;
            case Rank2: averageReactionTimeForRank = 270; break;
            case Rank3: averageReactionTimeForRank = 240; break;
            case Rank4: averageReactionTimeForRank = 220; break;
            case Rank5: averageReactionTimeForRank = 200; break;
            case Rank6: averageReactionTimeForRank = 180; break;
        }
        return averageReactionTimeForRank;
    }

    public static int getAverageSnapShotTimeForRank(Rank rank) {
        int averageReactionTimeForRank = 0;
        switch (rank) {
            case Rank1: averageReactionTimeForRank = 1000; break;
            case Rank2: averageReactionTimeForRank = 900; break;
            case Rank3: averageReactionTimeForRank = 800; break;
            case Rank4: averageReactionTimeForRank = 700; break;
            case Rank5: averageReactionTimeForRank = 600; break;
            case Rank6: averageReactionTimeForRank = 500; break;
        }
        return averageReactionTimeForRank;
    }

    public static int getSnapShotTargetAccuracyForRank(Rank rank) {
        int averageReactionTimeForRank = 0;
        switch (rank) {
            case Rank1: averageReactionTimeForRank = 80; break;
            case Rank2: averageReactionTimeForRank = 80; break;
            case Rank3: averageReactionTimeForRank = 80; break;
            case Rank4: averageReactionTimeForRank = 80; break;
            case Rank5: averageReactionTimeForRank = 80; break;
            case Rank6: averageReactionTimeForRank = 80; break;
        }
        return averageReactionTimeForRank;
    }

    public static int getTargetTrackingAccuracyForRank(Rank rank) {
        int averageTargetTrackingAccuracy = 0;
        switch (rank) {
            case Rank1: averageTargetTrackingAccuracy = 80; break;
            case Rank2: averageTargetTrackingAccuracy = 80; break;
            case Rank3: averageTargetTrackingAccuracy = 80; break;
            case Rank4: averageTargetTrackingAccuracy = 70; break;
            case Rank5: averageTargetTrackingAccuracy = 60; break;
            case Rank6: averageTargetTrackingAccuracy = 50; break;
        }
        return averageTargetTrackingAccuracy;
    }

    public static int getBullTrackingAccuracyForRank(Rank rank) {
        int averageBullTrackingAccuracy = 0;
        switch (rank) {
            case Rank1: averageBullTrackingAccuracy = 80; break;
            case Rank2: averageBullTrackingAccuracy = 80; break;
            case Rank3: averageBullTrackingAccuracy = 80; break;
            case Rank4: averageBullTrackingAccuracy = 50; break;
            case Rank5: averageBullTrackingAccuracy = 40; break;
            case Rank6: averageBullTrackingAccuracy = 25; break;
        }
        return averageBullTrackingAccuracy;
    }

    public static int getBodyShotsAccuracyForRank(Rank rank) {
        int averageBodyShotAccuracy = 0;
        switch (rank) {
            case Rank1: averageBodyShotAccuracy = 70; break;
            case Rank2: averageBodyShotAccuracy = 70; break;
            case Rank3: averageBodyShotAccuracy = 70; break;
            case Rank4: averageBodyShotAccuracy = 70; break;
            case Rank5: averageBodyShotAccuracy = 70; break;
            case Rank6: averageBodyShotAccuracy = 70; break;
        }
        return averageBodyShotAccuracy;
    }

    public static int getHeadShotsAccuracyForRank(Rank rank) {
        int averageHeadShotAccuracy = 0;
        switch (rank) {
            case Rank1: averageHeadShotAccuracy = 10; break;
            case Rank2: averageHeadShotAccuracy = 10; break;
            case Rank3: averageHeadShotAccuracy = 10; break;
            case Rank4: averageHeadShotAccuracy = 10; break;
            case Rank5: averageHeadShotAccuracy = 10; break;
            case Rank6: averageHeadShotAccuracy = 10; break;
        }
        return averageHeadShotAccuracy;
    }

    private boolean isHigherRank(Rank currentRank, Rank otherRank) {
        if (currentRank == Rank.Unranked) {
            if (otherRank != Rank.Unranked) {
                return true;
            } else {
                return false;
            }
        } else {
            if (otherRank == Rank.Unranked) {
                return false;
            } else {
                int currentRankInt = Integer.parseInt(currentRank.toString().substring(4, 5));
                int otherRankInt = Integer.parseInt(otherRank.toString().substring(4, 5));
                if (currentRankInt < otherRankInt) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    }
}
