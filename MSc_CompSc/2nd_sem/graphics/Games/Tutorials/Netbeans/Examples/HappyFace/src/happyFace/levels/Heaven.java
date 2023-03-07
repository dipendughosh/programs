package happyFace.levels;

import game.engine.*;
import game.assets.*;

import happyFace.*;

/**
 * The final level - against the biggest happy emoticon there is
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */
public class Heaven extends HappyFaceLevelLayer
{   
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Variables specifying if the various triggers have already been fired
     */
    private boolean trigger2Fired = false;  
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Heaven instance
     */        
    public Heaven( GameEngine gameEngine ) 
    {
        super( gameEngine );                        
        setLevelName( "Heaven" );                
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
        if( trigger.getTriggerNumber() != 12 ) {
            playerSpawnX = trigger.x;
            playerSpawnY = trigger.y;        
        }
        
        if( trigger.getTriggerNumber() == 1 ) {
            addMessage( "TriggerLine1", "The final level, the ultimate challenge, blah,", trigger.x+100.0, trigger.y-300.0 );
            addMessage( "TriggerLine2", "blah... It's the usual make your way", trigger.x+100.0, trigger.y-260.0 );
            addMessage( "TriggerLine3", "to the end, defeat the big, bad, or in", trigger.x+100.0, trigger.y-220.0 );
            addMessage( "TriggerLine4", "this case good, boss emoticon.", trigger.x+100.0, trigger.y-180.0 );
            addMessage( "TriggerLine5", "Untold riches, admiration and fame", trigger.x+100.0, trigger.y-140.0 );
            addMessage( "TriggerLine6", "await - or something like that.", trigger.x+100.0, trigger.y-100.0 );
            addMessage( "TriggerLine7", "", trigger.x+100.0, trigger.y-60.0 );
        }          

        
        else if( trigger.getTriggerNumber() == 2 ) {
            if( !trigger2Fired ) {
                addMessage( "TriggerLine1", "Have some bombs - well, you'll need", trigger.x+50.0, trigger.y-180.0 );
                addMessage( "TriggerLine2", "something to propel you upwards", trigger.x+50.0, trigger.y-140.0 );
                addMessage( "TriggerLine3", "on your journey towards the", trigger.x+50.0, trigger.y-100.0 );
                addMessage( "TriggerLine4", "floating city.", trigger.x+50.0, trigger.y-60.0 );
                
                int numOfBombs = 10;
                for( int idx = 0; idx < numOfBombs; idx++) {
                    CollectableBody bombs = new CollectableBody( this,
                            trigger.x - gameEngine.randomiser.nextInt(200),
                            trigger.y - 50.0 - gameEngine.randomiser.nextInt(100), 4,
                            "SmallBombUnlit", CollectableBody.CollectableType.SmallBomb );                            
                    levelMaximumScore += bombs.getPoints();
                    queueGameObjectToAdd( bombs, "CollectableBodies" );     
                }
            }
        }           
        
        else if( trigger.getTriggerNumber() == 3 ) {
            addMessage( "TriggerLine1", "You will find extra lifes scattered all over", trigger.x+150.0, trigger.y-230.0 );
            addMessage( "TriggerLine2", "this level. Why would this be the case?", trigger.x+150.0, trigger.y-190.0 );
            addMessage( "TriggerLine3", "Oh, some unimportant reason I'm sure,", trigger.x+150.0, trigger.y-150.0 );
            addMessage( "TriggerLine4", "still, do collect them.", trigger.x+150.0, trigger.y-110.0 );
        }             

        else if( trigger.getTriggerNumber() == 4 ) {
            addMessage( "TriggerLine1", "Hint: to gain access to the", trigger.x+0.0, trigger.y-180.0 );
            addMessage( "TriggerLine2", " floating city, bomb jump", trigger.x+0.0, trigger.y-140.0 );
            addMessage( "TriggerLine3", "up and to the right.", trigger.x+0.0, trigger.y-100.0 );
        }          

        else if( trigger.getTriggerNumber() == 5 ) {
            addMessage( "TriggerLine1", "The heavenly city", trigger.x+00.0, trigger.y-60.0 );
            addMessage( "TriggerLine2", "towers before you...", trigger.x+00.0, trigger.y-20.0 );
        }    

        else if( trigger.getTriggerNumber() == 6 ) {
            addMessage( "TriggerLine1", "This tower looks to be", trigger.x-200.0, trigger.y-220.0 );
            addMessage( "TriggerLine2", "the home of the angelic", trigger.x-200.0, trigger.y-180.0 );
            addMessage( "TriggerLine3", "emoticons who have amassed", trigger.x-200.0, trigger.y-140.0 );
            addMessage( "TriggerLine4", "a nice stash of goodies.", trigger.x-200.0, trigger.y-100.0 );
        }     

        else if( trigger.getTriggerNumber() == 7 ) {
            addMessage( "TriggerLine1", "An emoticon jail, in heaven,", trigger.x+340.0, trigger.y-180.0 );
            addMessage( "TriggerLine2", "the cheek and indignity of", trigger.x+340.0, trigger.y-140.0 );
            addMessage( "TriggerLine3", "it all... although, it does", trigger.x+340.0, trigger.y-100.0 );
            addMessage( "TriggerLine4", "offer a juicy means of", trigger.x+340.0, trigger.y-60.0 );
            addMessage( "TriggerLine5", "increasing your score...", trigger.x+340.0, trigger.y-20.0 );
        }          
     
        else if( trigger.getTriggerNumber() == 8 ) {
            addMessage( "TriggerLine1", "A grand palace opens out in front", trigger.x+200.0, trigger.y-80.0 );
            addMessage( "TriggerLine2", "of you, surely of the home of", trigger.x+200.0, trigger.y-40.0 );
            addMessage( "TriggerLine3", "something important.", trigger.x+200.0, trigger.y-00.0 );
        }          
        
        else if( trigger.getTriggerNumber() == 9 ) {
            addMessage( "TriggerLine1", "Do remember, all emoticons can be", trigger.x+200.0, trigger.y-80.0 );
            addMessage( "TriggerLine2", "dispatched by jumping on top of them.", trigger.x+200.0, trigger.y-40.0 );
            addMessage( "TriggerLine3", "Even the big ones!", trigger.x+200.0, trigger.y-00.0 );
        }          
                
        else if( trigger.getTriggerNumber() == 10 ) {
            addMessage( "TriggerLine1", "Just to be clear, should a big emoticon", trigger.x+470.0, trigger.y-240.0 );
            addMessage( "TriggerLine2", "be found herein, you will want to get", trigger.x+470.0, trigger.y-200.0 );
            addMessage( "TriggerLine3", "into a position where you can drop", trigger.x+470.0, trigger.y-160.0 );
            addMessage( "TriggerLine4", "down on top of the emoticon and", trigger.x+470.0, trigger.y-120.0 );
            addMessage( "TriggerLine5", "remain on top for as long as", trigger.x+470.0, trigger.y-80.0 );
            addMessage( "TriggerLine6", "possible. Have you been collecting", trigger.x+470.0, trigger.y-40.0 );
            addMessage( "TriggerLine7", "those extra lifes?", trigger.x+470.0, trigger.y+00.0 );
        }           
        
        else if( trigger.getTriggerNumber() == 11 ) {
            addMessage( "TriggerLine1", "It's nice up here - just the right sort", trigger.x+200.0, trigger.y-180.0 );
            addMessage( "TriggerLine2", "of spot for dropping down onto any", trigger.x+200.0, trigger.y-140.0 );
            addMessage( "TriggerLine3", "large emoticons that happen to", trigger.x+200.0, trigger.y-100.0 );
            addMessage( "TriggerLine4", "be floating about...", trigger.x+200.0, trigger.y-60.0 );
        }          
                 
        else if( trigger.getTriggerNumber() == 12 ) {            
            EmoticonPlayer player = (EmoticonPlayer)getGameObject( "Player" );
            player.triggerEmoticonDeath();        
        }          
        
        else if( trigger.getTriggerNumber() == 0 ) {
            boolean emoticonBossAlive = false;
            GameObjectCollection emoticons = getGameObjectCollection("Emoticons");
            for( int idx = 0; idx < emoticons.size && !emoticonBossAlive; idx++ )
                if( ((Emoticon)emoticons.gameObjects[idx]).emoticonType.equals("EmoticonBoss") )
                    emoticonBossAlive = true;
            
            if( emoticonBossAlive ) {
                addMessage( "TriggerLine1", "You must kill the", trigger.x-230.0, trigger.y-50.0 );
                addMessage( "TriggerLine2", "emoticon boss to", trigger.x-230.0, trigger.y-10.0 );
                addMessage( "TriggerLine3", "complete this level!", trigger.x-230.0, trigger.y+20.0 );                
            } else
                currentNumEmoticonsKilled = 1000;
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
        } else if( trigger.getTriggerNumber() == 2 ) {
            if( !trigger2Fired ) {
                trigger2Fired = true;            
                removeMessages(4);
            }
        } else if( trigger.getTriggerNumber() == 3 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 4 ) {
            removeMessages(3);
        } else if( trigger.getTriggerNumber() == 5 ) {
            removeMessages(2);
        } else if( trigger.getTriggerNumber() == 6 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 7 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 8 ) {
            removeMessages(3);
        } else if( trigger.getTriggerNumber() == 9 ) {
            removeMessages(3);
        } else if( trigger.getTriggerNumber() == 10 ) {
            removeMessages(7);
        } else if( trigger.getTriggerNumber() == 11 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 0 ) {
            boolean emoticonBossAlive = false;
            GameObjectCollection emoticons = getGameObjectCollection("Emoticons");
            for( int idx = 0; idx < emoticons.size && !emoticonBossAlive; idx++ )
                if( ((Emoticon)emoticons.gameObjects[idx]).emoticonType.equals("EmoticonBoss") )
                    emoticonBossAlive = true;
            
            if( emoticonBossAlive )
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
        levelDataFileName = "Heaven.dat";
        backgroundMusicAssetName = "Heaven";
        backgroundMusicVolume = 80;
        targetNumEmoticonsToCollect = 0;
        targetNumEmoticonsToKill = 1000;  
                
        super.setupLevel();
        
        viewPortFocusXOffset = 0;
        viewPortFocusYOffset = -gameEngine.screenHeight/8;
        
        levelExitMessageXOffset = 0.0;
        levelExitMessageYOffset = -200.0;

        trigger2Fired = false;
    }   
    
    /**
     * Perform level exit actions
     */
    @Override      
    protected void quitLevel() { 
        //((MidiAsset)assetManager.retrieveAssetArchetype( "JailBreak" )).stop();
        super.quitLevel();
    }
}
