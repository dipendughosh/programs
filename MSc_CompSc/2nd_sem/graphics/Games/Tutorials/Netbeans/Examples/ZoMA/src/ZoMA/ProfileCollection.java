package ZoMA;

import java.io.Serializable;
import java.util.*;

/**
 * ProfileCollecion provides a serializable collection of Profile
 * instance, i.e. it holds all the statistics of players who
 * have created a profile on the system.
 *
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1 $ $Date: 2007/08 $
 */

public class ProfileCollection implements Serializable {

    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Maximum number of profiles that can be held within the collection,
     * alongside an arraylist of stored profiles.
     */ 
    private static final int MAX_PROFILES = 6;
    private ArrayList<Profile> profiles = new ArrayList<Profile>();

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a ProfileCollection instance.
     */
    public ProfileCollection() { }

    
    ///////////////////////////////////////////////////////////////////////////
    // Methods: Get/set methods                                              //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Return the number of profiles that can be stored within this collection
     */
    public int getMaxProfiles() {
        return MAX_PROFILES;
    }
    
    /**
     * Return the number of profiles stored within this collection
     */
    public int getNumProfiles() {
        return profiles.size();
    }

    /**
     * Create and add a new empty profile to the collection using the specified
     * profile name and screen dimensions.
     * <P>
     * The screen dimension is needed to track the location (i.e. top, bottom, left
     * right, etc.) of screen clicks within the profile.
     */
    public boolean addNewProfile(String profileName, int screenWidth, int screenHeight) {
        if (getNumProfiles() == getMaxProfiles())
            return false;
        
        Profile profile = new Profile(profileName, screenWidth, screenHeight);
        profiles.add(profile);
        return true;
    }

    /**
     * Return the specified profile, or null if the profile cannot be found
     */
    public Profile getProfile(String profileName) {
        Profile requestedProfile = null;

        for (Profile profile : profiles) {
            if (profile.getProfileName().equals(profileName)) {
                requestedProfile = profile;
            }
        }
        return requestedProfile;
    }

    /**
     * Return the specified profile, or null if the index is invalid
     */
    public Profile getProfile(int profileIdx) {
        if (profileIdx < 0 || profileIdx >= profiles.size()) {
            return null;
        } else {
            return profiles.get(profileIdx);
        }
    }

    /**
     * Delete the specified profile, returning false if the profile cannot be found
     */
    public boolean deleteProfile(String profileName) {
        boolean profileDeleted = false;

        for (int idx = 0; !profileDeleted && idx < profiles.size(); idx++) {
            if (profiles.get(idx).getProfileName().equals(profileName)) {
                profiles.remove(idx);
                profileDeleted = true;
            }
        }
        return profileDeleted;
    }
}