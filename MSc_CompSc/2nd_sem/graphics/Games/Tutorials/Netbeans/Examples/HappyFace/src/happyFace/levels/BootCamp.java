package happyFace.levels;

import game.engine.*;
import game.assets.*;

import happyFace.*;

/**
 * An open level within which the player will have to dispatch a lot of 
 * happy emoticons.
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */
public class BootCamp extends HappyFaceLevelLayer
{
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a Boot Camp instance
     */           
    public BootCamp( GameEngine gameEngine ) 
    {
        super( gameEngine );                        
        setLevelName( "Boot Camp" );                
    }
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Methods:                                                              //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Perform level specific behaviour whenever the player enters into
     * a trigger region
     */
    @Override
    protected void fireTrigger( Trigger trigger ) {        
        playerSpawnX = trigger.x;
        playerSpawnY = trigger.y;
        
        if( trigger.getTriggerNumber() == 1 ) {
            addMessage( "TriggerLine1", "Boot Camp: Raid the stash of", trigger.x+280.0, trigger.y-290.0 );
            addMessage( "TriggerLine2", "bombs and then use your guile", trigger.x+280.0, trigger.y-250.0);
            addMessage( "TriggerLine3", "and agility to entirely annihilate", trigger.x+280.0, trigger.y-210.0 );
            addMessage( "TriggerLine4", "the emoticon army before returning", trigger.x+280.0, trigger.y-170.0 );
            addMessage( "TriggerLine5", "here to make your escape.", trigger.x+280.0, trigger.y-130.0 );
            addMessage( "TriggerLine6", "Hint: You will need to bomb jump", trigger.x+280.0, trigger.y-70.0 );
            addMessage( "TriggerLine7", "a lot in this level...", trigger.x+280.0, trigger.y-30.0 );                        
        }

        else if( trigger.getTriggerNumber() == 2 ) {
            addMessage( "TriggerLine1", "The slash of bombs is hidden", trigger.x-280.0, trigger.y-150.0 );
            addMessage( "TriggerLine2", "down this ravine. Use the bombs", trigger.x-280.0, trigger.y-110.0);
            addMessage( "TriggerLine3", "from the ruins to the west to", trigger.x-280.0, trigger.y-70.0 );
            addMessage( "TriggerLine4", "blow a hole in the bridge", trigger.x-280.0, trigger.y-30.0 );
        }        
        
        else if( trigger.getTriggerNumber() == 3 ) {            
            addMessage( "TriggerLine1", "There is little other supply", trigger.x-180.0, trigger.y-170.0 );
            addMessage( "TriggerLine2", "on this level, i.e. this stash", trigger.x-180.0, trigger.y-130.0);
            addMessage( "TriggerLine3", "must be used to kill", trigger.x-180.0, trigger.y-90.0 );
            addMessage( "TriggerLine4", "all the happy emoticons", trigger.x-180.0, trigger.y-50.0 );
        }        
        
        else if( trigger.getTriggerNumber() == 4 ) {
            if( currentNumEmoticonsKilled < targetNumEmoticonsToKill ) {            
                addMessage( "TriggerLine1", "The emoticon army lies in the", trigger.x+100.0, trigger.y-150.0 );
                addMessage( "TriggerLine2", "plain below this cliff. Note:", trigger.x+100.0, trigger.y-110.0);
                addMessage( "TriggerLine3", "you will need to climb back up", trigger.x+100.0, trigger.y-70.0 );
                addMessage( "TriggerLine4", "the cliff to make good your escape", trigger.x+100.0, trigger.y-30.0 );
            }
        }
                
        else if( trigger.getTriggerNumber() == 5 ) {
            addMessage( "TriggerLine1", "Engaging a large horde of", trigger.x-100.0, trigger.y-110.0 );
            addMessage( "TriggerLine2", "emoticons in direct combat", trigger.x-100.0, trigger.y-70.0);
            addMessage( "TriggerLine3", "is likely to be difficult...", trigger.x-100.0, trigger.y-30.0 );
        }
        
        else if( trigger.getTriggerNumber() == 6 ) {
            addMessage( "TriggerLine1", "It's nice up here... no happy", trigger.x-0.0, trigger.y-120.0 );
            addMessage( "TriggerLine2", "emoticons can make their way up", trigger.x-0.0, trigger.y-80.0);
            addMessage( "TriggerLine3", "and bombs can rain down...", trigger.x-0.0, trigger.y-40.0 );
        }
                
        else if( trigger.getTriggerNumber() == 7 ) {
            addMessage( "TriggerLine1", "A bridge with water. No emoticon,", trigger.x-0.0, trigger.y-100.0 );
            addMessage( "TriggerLine2", "including yourself, can swim...", trigger.x-0.0, trigger.y-60.0);
        }
        
        else if( trigger.getTriggerNumber() == 8 ) {
            addMessage( "TriggerLine1", "Oh look... a large bomb", trigger.x-130.0, trigger.y-140.0 );
            addMessage( "TriggerLine2", "and it's under a bunch", trigger.x-130.0, trigger.y-100.0);
            addMessage( "TriggerLine3", "of happy emoticons...", trigger.x-130.0, trigger.y-60.0 );
        }
                
        else if( trigger.getTriggerNumber() == 9 ) {
            addMessage( "TriggerLine1", "The fort lies ahead and", trigger.x-70.0, trigger.y-180.0 );
            addMessage( "TriggerLine2", "it's full of overly happy", trigger.x-70.0, trigger.y-140.0);
            addMessage( "TriggerLine3", "emoticons. Direct", trigger.x-70.0, trigger.y-100.0 );
            addMessage( "TriggerLine4", "confrontation is not advisable", trigger.x-70.0, trigger.y-60.0 );
        }
                
        else if( trigger.getTriggerNumber() == 0 ) {
            if( currentNumEmoticonsKilled < targetNumEmoticonsToKill ) {
                addMessage( "TriggerLine1", "You must kill at least " 
                        + targetNumEmoticonsToKill, trigger.x+300.0, trigger.y-200.0 );
                addMessage( "TriggerLine2", "emoticons to exit this level...", trigger.x+300.0, trigger.y-160.0 );
            }            
        }
    }

    /**
     * Perform trigger cancellation actions if the player exists the 
     * bounds of a trigger
     */        
    @Override       
    protected void cancelTrigger( Trigger trigger ) {
        if( trigger.getTriggerNumber() == 1 ) {
            removeMessages(7);            
        }  else if( trigger.getTriggerNumber() == 2 ) {
           removeMessages(4);
        } else if( trigger.getTriggerNumber() == 3 ) {
           removeMessages(4);
        } else if( trigger.getTriggerNumber() == 4 ) {
            if( currentNumEmoticonsKilled < targetNumEmoticonsToKill ) { 
                removeMessages(4);                
            }
        } else if( trigger.getTriggerNumber() == 5 ) {
            removeMessages(3);            
        } else if( trigger.getTriggerNumber() == 6 ) {
           removeMessages(3);
        } else if( trigger.getTriggerNumber() == 7 ) {
           removeMessages(2);            
        } else if( trigger.getTriggerNumber() == 8 ) {
           removeMessages(3);
        } else if( trigger.getTriggerNumber() == 9 ) {
           removeMessages(4);
        } else if( trigger.getTriggerNumber() == 0 ) {
            if( currentNumEmoticonsKilled < targetNumEmoticonsToKill ) {
                removeMessages(2);                
            }            
        }
    }

    /**
     * Remove the specified number of messages
     */
    private void removeMessages( int numMessages ) {
        for( int idx = 1; idx <= numMessages; idx++ )
            queueGameObjectToRemove( getGameObject( "TriggerLine"+idx ) );            
    }          

    /**
     * Setup the game levle
     */
    @Override        
    public void setupLevel()
    {     
        levelDataFileName = "BootCamp.dat";
        backgroundMusicAssetName = "BootCamp";
        backgroundMusicVolume = 80;
        targetNumEmoticonsToCollect = 0;
        targetNumEmoticonsToKill = 45;  
        
        super.setupLevel();
        
        viewPortFocusXOffset = 0;
        viewPortFocusYOffset = 0;
        
        levelExitMessageXOffset = -100.0;
        levelExitMessageYOffset = -200.0;
        
    }   
    
    /**
     * Perform level exit actions
     */
    @Override      
    protected void quitLevel() { 
        ((MidiAsset)assetManager.retrieveAssetArchetype( "BootCamp" )).stop();
        super.quitLevel();
    }
}