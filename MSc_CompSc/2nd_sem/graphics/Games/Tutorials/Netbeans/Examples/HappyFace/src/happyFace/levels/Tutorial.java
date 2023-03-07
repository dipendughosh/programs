package happyFace.levels;

import game.engine.*;
import game.assets.*;
import java.awt.event.*;
import happyFace.*;

/**
 * Tutorial game level
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */
public class Tutorial extends HappyFaceLevelLayer
{

    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new tutorial instance
     */
    public Tutorial( GameEngine gameEngine ) 
    {
        super( gameEngine );                        
        setLevelName( "Tutorial" );                
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
            addMessage( "TriggerLine1", "Welcome to the HappyFace tutorial", trigger.x+200.0, trigger.y-240.0 );
            addMessage( "TriggerLine2", "where you can learn the gameplay", trigger.x+200.0, trigger.y-200.0);
            addMessage( "TriggerLine3", "basics needed to find success.", trigger.x+200.0, trigger.y-160.0 );
            addMessage( "TriggerLine4", "To get started, use the ", trigger.x+200.0, trigger.y-120.0 );
            addMessage( "TriggerLine5", KeyEvent.getKeyText( EmoticonPlayer.MOVE_LEFT_KEY )
                    + " and " + KeyEvent.getKeyText( EmoticonPlayer.MOVE_RIGHT_KEY )
                    + " keys to roll", trigger.x+200.0, trigger.y-80.0 );
            addMessage( "TriggerLine6", "left and right.", trigger.x+200.0, trigger.y-40.0 );
            
            // As this is the tutorial, given the player lots of lifes
            EmoticonPlayer player = (EmoticonPlayer)getGameObject("Player");
            player.setLife( 99 );
        }

        else if( trigger.getTriggerNumber() == 2 ) {
            addMessage( "TriggerLine1", "You can bounce using the " +
                    KeyEvent.getKeyText( EmoticonPlayer.JUMP_UP_KEY ) + " key", trigger.x+0.0, trigger.y-290.0 );
            addMessage( "TriggerLine2", "and quickly stop bouncing using", trigger.x+0.0, trigger.y-250.0);
            addMessage( "TriggerLine3", "the " + KeyEvent.getKeyText( EmoticonPlayer.STOP_BOUNCE_KEY ) +
                    " key. ", trigger.x+0.0, trigger.y-210.0 );
            addMessage( "TriggerLine4", "Repeatedly bouncing will increase", trigger.x+0.0, trigger.y-150.0 );
            addMessage( "TriggerLine5", "the height of the bounce.", trigger.x+0.0, trigger.y-110.0 );
        }

        else if( trigger.getTriggerNumber() == 3 ) {
            addMessage( "TriggerLine1", "This room contains spikes", trigger.x+300.0, trigger.y-130.0);
            addMessage( "TriggerLine2", "that will reduce your", trigger.x+300.0, trigger.y-90.0);
            addMessage( "TriggerLine3", "health (lower left screen).", trigger.x+300.0, trigger.y-50.0);
            addMessage( "TriggerLine4", "Pick up the hearts to", trigger.x+300.0, trigger.y-10.0 );
            addMessage( "TriggerLine5", "increase health. Escape", trigger.x+300.0, trigger.y+30.0 );
            addMessage( "TriggerLine6", "the room by jumping", trigger.x+300.0, trigger.y+70.0 );
            addMessage( "TriggerLine7", "over the spikes.", trigger.x+300.0, trigger.y+110.0 );
        }
         
        else if( trigger.getTriggerNumber() == 4 ) {
            addMessage( "TriggerLine1", "Jump as high as", trigger.x+320.0, trigger.y-170.0);
            addMessage( "TriggerLine2", "you can to get", trigger.x+320.0, trigger.y-130.0);
            addMessage( "TriggerLine3", "on top of the", trigger.x+320.0, trigger.y-90.0);
            addMessage( "TriggerLine4", "large spike, then", trigger.x+320.0, trigger.y-50.0 );
            addMessage( "TriggerLine5", "roll off quickly.", trigger.x+320.0, trigger.y-10.0 );
        }

        else if( trigger.getTriggerNumber() == 5 ) {
            addMessage( "TriggerLine1", "Avoid pools of water, acid and fire", trigger.x+240.0, trigger.y-240.0);
            addMessage( "TriggerLine2", "by jumping over them (or jumping", trigger.x+240.0, trigger.y-200.0);
            addMessage( "TriggerLine3", "out if you fall in!)", trigger.x+240.0, trigger.y-160.0);

            addMessage( "TriggerLine4", "Oh, if not already tried, used the", trigger.x+240.0, trigger.y-100.0);
            addMessage( "TriggerLine5", KeyEvent.getKeyText( HappyFaceLevelLayer.ZOOM_IN_KEY  )
                    + " and " + KeyEvent.getKeyText( HappyFaceLevelLayer.ZOOM_OUT_KEY  )
                    + " keys to zoom in and out,", trigger.x+240.0, trigger.y-60.0);
            addMessage( "TriggerLine6", "or, scroll and zoom using the mouse.", trigger.x+240.0, trigger.y-20.0);
        }

        else if( trigger.getTriggerNumber() == 6 ) {
            addMessage( "TriggerLine1", "Most levels have destroyable platforms and walls.", trigger.x+170.0, trigger.y-100.0);
            addMessage( "TriggerLine2", "Use the "
                    + KeyEvent.getKeyText( EmoticonPlayer.SMALL_BOMB_KEY ) + ", "
                    + KeyEvent.getKeyText( EmoticonPlayer.MEDIUM_BOMB_KEY ) + " and "
                    + KeyEvent.getKeyText( EmoticonPlayer.LARGE_BOMB_KEY ) + " keys to throw small,", trigger.x+170.0, trigger.y-60.0);
            addMessage( "TriggerLine3", "medium and large bombs. Bombs differ in", trigger.x+170.0, trigger.y-20.0);
            addMessage( "TriggerLine4", "their destructive ability - use small and", trigger.x+170.0, trigger.y+20.0);
            addMessage( "TriggerLine5", "medium bombs to destroy the two platforms.", trigger.x+170.0, trigger.y+60.0);
        }        

        else if( trigger.getTriggerNumber() == 7 ) {
            addMessage( "TriggerLine1", "Bombs appear on top of your head and", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine2", "take on your travel velocity. Bombs", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine3", "can be thrown up by jumping after", trigger.x+50.0, trigger.y-70.0);
            addMessage( "TriggerLine4", "throwing the bomb.", trigger.x+50.0, trigger.y-30.0);
        }        
        
        else if( trigger.getTriggerNumber() == 8 ) {
            addMessage( "TriggerLine1", "Some levels have jump pads that", trigger.x+50.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "magnify your bounce. Jump up", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "using the pads. The height of", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "the jump can be controlled", trigger.x+50.0, trigger.y-70.0);
            addMessage( "TriggerLine5", "by pressing jump or crouch.", trigger.x+50.0, trigger.y-30.0);
        }        

        else if( trigger.getTriggerNumber() == 9 ) {
            addMessage( "TriggerLine1", "Now the hard bit... bomb jumping.", trigger.x+50.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "Drop a bomb, let it roll off you", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "and then jump on it just before", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "it explodes to jump up... easy, eh?", trigger.x+50.0, trigger.y-70.0);
            addMessage( "TriggerLine5", "Mastering this will be very useful.", trigger.x+50.0, trigger.y-30.0);
        }        

        else if( trigger.getTriggerNumber() == 10 ) {
            addMessage( "TriggerLine1", "Something more challenging? Bomb long jumping.", trigger.x+50.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "Drop a bomb to your left, wait by its side", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "and jump just before it explodes to propel", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "yourself across the chasm. Zoom out", trigger.x+50.0, trigger.y-70.0);
            addMessage( "TriggerLine5", "for a better view.", trigger.x+50.0, trigger.y-30.0);
        }        
        
        else if( trigger.getTriggerNumber() == 11 ) {
            addMessage( "TriggerLine1", "One of the goals within the game is to rescue", trigger.x+50.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "unhappy emoticons from the oh-so-tiresome", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "happy emoticons. An unhappy wee fellow", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "is trapped in the pit - release", trigger.x+50.0, trigger.y-70.0);
            addMessage( "TriggerLine5", "him by walking into him.", trigger.x+50.0, trigger.y-30.0);
        }        

        else if( trigger.getTriggerNumber() == 12 ) {
            addMessage( "TriggerLine1", "A happy emoticon - aimlessly wandering with", trigger.x+50.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "a grin. You will be hurt if he bumps into", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "you or jumps on you. You can squish him by", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "jumping on top. This weak little fellow", trigger.x+50.0, trigger.y-70.0);
            addMessage( "TriggerLine5", "only requires one jump to be dispatched...", trigger.x+50.0, trigger.y-30.0);
            addMessage( "TriggerLine6", "         Go on...", trigger.x+50.0, trigger.y+10.0);
        }        

        else if( trigger.getTriggerNumber() == 13 ) {
            addMessage( "TriggerLine1", "You can use bombs to dispatch happy emoticons.", trigger.x+50.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "If it's a small bomb, then it needs to explode", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "close to the emoticon. Oh look, some small", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "bombs and a trapped emoticon.", trigger.x+50.0, trigger.y-70.0);
            addMessage( "TriggerLine5", "How convenient.", trigger.x+50.0, trigger.y-30.0);
        }        
        
        else if( trigger.getTriggerNumber() == 14 ) {
            addMessage( "TriggerLine1", "As happy emoticons cannot swim it would surely", trigger.x+50.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "be a tragic accident if someone were to", trigger.x+50.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "bump into the emoticon merrily gazing", trigger.x+50.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "into that pool of acid...", trigger.x+50.0, trigger.y-70.0);
        }        
   
        else if( trigger.getTriggerNumber() == 15 ) {
            addMessage( "TriggerLine1", "Two somewhat more challenging", trigger.x-150.0, trigger.y-190.0);
            addMessage( "TriggerLine2", "emoticons await. You could toss", trigger.x-150.0, trigger.y-150.0);
            addMessage( "TriggerLine3", "in bombs, or jump into the pit", trigger.x-150.0, trigger.y-110.0);
            addMessage( "TriggerLine4", "like the angry ball of fury", trigger.x-150.0, trigger.y-70.0);
            addMessage( "TriggerLine5", "which you undoubtedly are.", trigger.x-150.0, trigger.y-30.0);
        }        

        else if( trigger.getTriggerNumber() == 16 ) {
            addMessage( "TriggerLine1", "What about a challenge to tie", trigger.x+150.0, trigger.y-340.0);
            addMessage( "TriggerLine2", "everything together? The happy", trigger.x+150.0, trigger.y-300.0);
            addMessage( "TriggerLine3", "emoticons have barricaded the", trigger.x+150.0, trigger.y-260.0);
            addMessage( "TriggerLine4", "bridge to the exit. Make your", trigger.x+150.0, trigger.y-220.0);
            addMessage( "TriggerLine5", "way to the other side in whatever", trigger.x+150.0, trigger.y-180.0);
            addMessage( "TriggerLine6", "manner you want - spam bombs,", trigger.x+150.0, trigger.y-140.0);
            addMessage( "TriggerLine7", "jump off bombs, skilfully squish", trigger.x+150.0, trigger.y-100.0);
            addMessage( "TriggerLine8", "the happy emoticons - whatever", trigger.x+150.0, trigger.y-60.0);
            addMessage( "TriggerLine9", "tickles your fancy.", trigger.x+150.0, trigger.y-20.0);
        }        
        
        else if( trigger.getTriggerNumber() == 17 ) {
            addMessage( "TriggerLine1", "You are awarded a score and possibly a medal", trigger.x+50.0, trigger.y-100.0);
            addMessage( "TriggerLine2", "whenever you finished a level. Increase", trigger.x+50.0, trigger.y-60.0);
            addMessage( "TriggerLine3", "your score by collecting items, squishing,", trigger.x+50.0, trigger.y-20.0);
            addMessage( "TriggerLine4", "happy emoticon and freeing unhappy emoticons.", trigger.x+50.0, trigger.y+20.0);
        }        
        
        else if( trigger.getTriggerNumber() == 0 ) {
            addMessage( "TriggerLine1", "Well done!", trigger.x+50.0, trigger.y-90.0);
            addMessage( "TriggerLine2", "Jump up to the exit sign", trigger.x+50.0, trigger.y-50.0);
            addMessage( "TriggerLine3", "to, well, exit.", trigger.x+50.0, trigger.y-10.0);
        }                
    }

    /**
     * Perform trigger cancellation actions if the player exists the 
     * bounds of a trigger
     */        
    @Override
    protected void cancelTrigger( Trigger trigger ) {
        if( trigger.getTriggerNumber() == 1 ) {
            removeMessages(6);
        } else if( trigger.getTriggerNumber() == 2 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 3 ) {
            removeMessages(7);
        } else if( trigger.getTriggerNumber() == 4 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 5 ) {
            removeMessages(6);
        } else if( trigger.getTriggerNumber() == 6 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 7 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 8 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 9 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 10 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 11 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 12 ) {
            removeMessages(6);
        } else if( trigger.getTriggerNumber() == 13 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 14 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 15 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 16 ) {
            removeMessages(9);
        } else if( trigger.getTriggerNumber() == 17 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 0 ) {
            removeMessages(3);
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
        levelDataFileName = "Tutorial.dat";
        backgroundMusicAssetName = "Tutorial";
        backgroundMusicVolume = 100;
        targetNumEmoticonsToCollect = 0;
        targetNumEmoticonsToKill = 0;  
        
        super.setupLevel();

        viewPortFocusXOffset = 0;
        viewPortFocusYOffset = +gameEngine.screenHeight/16;        
        
        levelExitMessageXOffset = 0.0;
        levelExitMessageYOffset = -200.0;
    }   
    
    /**
     * Perform level exit actions
     */
    @Override
    protected void quitLevel() { 
        ((MidiAsset)assetManager.retrieveAssetArchetype( "Tutorial" )).stop();
        super.quitLevel();
    }
}