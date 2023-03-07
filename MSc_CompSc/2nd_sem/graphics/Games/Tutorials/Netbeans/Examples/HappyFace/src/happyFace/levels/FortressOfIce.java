package happyFace.levels;

import game.engine.*;
import game.assets.*;

import happyFace.*;

/**
 * The player must make use of an unstoppable emoticon to break through
 * a defences of a castle
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */
public class FortressOfIce extends HappyFaceLevelLayer
{
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Variables specifying if the destroyer has been released
     */    
    private boolean destroyerReleased;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Fortress of Ice instance
     */       
    public FortressOfIce( GameEngine gameEngine ) 
    {
        super( gameEngine );                        
        setLevelName( "Fortress of Ice" );                
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
        if( trigger.getTriggerNumber() == 1 ) {
            playerSpawnX = trigger.x; playerSpawnY = trigger.y;
            
            addMessage( "TriggerLine1", "The Fortress of Ice lies to the west.", trigger.x+50.0, trigger.y-290.0 );
            addMessage( "TriggerLine2", "Without bombs you have little hope of", trigger.x+50.0, trigger.y-250.0);
            addMessage( "TriggerLine3", "breaching the walls and must rely on", trigger.x+50.0, trigger.y-210.0 );
            addMessage( "TriggerLine4", "directing the ominously named Destroyer", trigger.x+50.0, trigger.y-170.0 );
            addMessage( "TriggerLine5", "(large gnashing teeth, dislikes kittens,", trigger.x+50.0, trigger.y-130.0 );
            addMessage( "TriggerLine6", "has anger management issues, etc.),", trigger.x+50.0, trigger.y-90.0 );
            addMessage( "TriggerLine7", "to clear the path onwards.", trigger.x+50.0, trigger.y-50.0 );                        
        }

        else if( trigger.getTriggerNumber() == 2 ) {
            playerSpawnX = trigger.x; playerSpawnY = trigger.y;
                             
            addMessage( "TriggerLine1", "This air hole has been blocked.", trigger.x+20.0, trigger.y-290.0 );
            addMessage( "TriggerLine2", "There is a rumour that a small stash", trigger.x+20.0, trigger.y-250.0);
            addMessage( "TriggerLine3", "of bombs has fallen into the moat before", trigger.x+20.0, trigger.y-210.0 );
            addMessage( "TriggerLine4", "the outer walls of the fortress.", trigger.x+20.0, trigger.y-170.0 );
            addMessage( "TriggerLine5", "Perhaps, these bombs could used", trigger.x+20.0, trigger.y-130.0 );
            addMessage( "TriggerLine6", "to open the air hole.", trigger.x+20.0, trigger.y-90.0 );
        }

        else if( trigger.getTriggerNumber() == 3 ) {            
            EmoticonPlayer player = (EmoticonPlayer)getGameObject( "Player" );
            player.triggerEmoticonDeath();        
        }        
        
        else if( trigger.getTriggerNumber() == 4 ) {
            playerSpawnX = trigger.x; playerSpawnY = trigger.y;

            if( !destroyerReleased ) {
                addMessage( "TriggerLine1", "The abhorrence that is the Destroyer", trigger.x+50.0, trigger.y-190.0 );
                addMessage( "TriggerLine2", "remains imprisoned in its flimsy brick", trigger.x+50.0, trigger.y-150.0);
                addMessage( "TriggerLine3", "prison with nothing better to do than", trigger.x+50.0, trigger.y-110.0 );
                addMessage( "TriggerLine4", "to ensure no one dares to steal its", trigger.x+50.0, trigger.y-70.0 );            
                addMessage( "TriggerLine5", "precious gemstone...", trigger.x+50.0, trigger.y-30.0 );
            }
        }        

        else if( trigger.getTriggerNumber() == 5 ) {
            if( !destroyerReleased ) {
                destroyerReleased = true;
            
                GameObjectCollection emoticons = getGameObjectCollection( "Emoticons" );
                for( int idx = 0; idx < emoticons.size; idx++ )
                    if( ((Emoticon)emoticons.gameObjects[idx]).emoticonType.equals( "EmoticonDestroyer" ) )
                        ((EmoticonAI)emoticons.gameObjects[idx]).setChaseAI( EmoticonAI.ChaseAI.Chase );
            }
        }        
        
        else if( trigger.getTriggerNumber() == 6 ) {
            playerSpawnX = trigger.x; playerSpawnY = trigger.y;
    
            addMessage( "TriggerLine1", "The somewhat immense", trigger.x-170.0, trigger.y-260.0 );
            addMessage( "TriggerLine2", "walls of the Fortress", trigger.x-170.0, trigger.y-220.0);
            addMessage( "TriggerLine3", "of Ice rise before you.", trigger.x-170.0, trigger.y-180.0 );
            addMessage( "TriggerLine4", "If only there was an", trigger.x-170.0, trigger.y-140.0 );                        
            addMessage( "TriggerLine5", "angry Destroyer that", trigger.x-170.0, trigger.y-100.0 );
            addMessage( "TriggerLine6", "could be persuaded to", trigger.x-170.0, trigger.y-60.0 );                        
            addMessage( "TriggerLine7", "crash into the wall...", trigger.x-170.0, trigger.y-20.0 );
        }
     
        else if( trigger.getTriggerNumber() == 7 ) {
            playerSpawnX = trigger.x; playerSpawnY = trigger.y;
    
            addMessage( "TriggerLine1", "The innards of the", trigger.x-170.0, trigger.y-260.0 );
            addMessage( "TriggerLine2", "fortress await plunder -", trigger.x-170.0, trigger.y-220.0);
            addMessage( "TriggerLine3", "although this is likely", trigger.x-170.0, trigger.y-180.0 );
            addMessage( "TriggerLine4", "to be a smash and grab", trigger.x-170.0, trigger.y-140.0 );                        
            addMessage( "TriggerLine5", "unless you can frustrate", trigger.x-170.0, trigger.y-100.0 );
            addMessage( "TriggerLine6", "the rather dumb ", trigger.x-170.0, trigger.y-60.0 );                        
            addMessage( "TriggerLine7", "Destroyer...", trigger.x-170.0, trigger.y-20.0 );
        }        
        
        else if( trigger.getTriggerNumber() == 8 ) {
            playerSpawnX = trigger.x; playerSpawnY = trigger.y;
    
            addMessage( "TriggerLine1", "The treasury - surely it would be crime", trigger.x+200.0, trigger.y-210.0 );
            addMessage( "TriggerLine2", "if you didn't 'set free' all of those", trigger.x+200.0, trigger.y-170.0);
            addMessage( "TriggerLine3", "lovely, shiny diamonds", trigger.x+200.0, trigger.y-130.0 );
        }        
        
        else if( trigger.getTriggerNumber() == 9 ) {
            playerSpawnX = trigger.x; playerSpawnY = trigger.y;
    
            addMessage( "TriggerLine1", "This imposing and seemingly indestructible", trigger.x-270.0, trigger.y-100.0 );
            addMessage( "TriggerLine2", "tower leads upwards towards the", trigger.x-270.0, trigger.y-60.0);
            addMessage( "TriggerLine3", "emoticon heaven and the last stage", trigger.x-270.0, trigger.y-20.0 );
            addMessage( "TriggerLine4", "of your journey...", trigger.x-270.0, trigger.y+20.0 );
        }        
        
        else if( trigger.getTriggerNumber() == 0 ) {
    
            addMessage( "TriggerLine1", "Oh, aren't you a curious one.", trigger.x+30.0, trigger.y-170.0 );
            addMessage( "TriggerLine2", "Still, have an extra life, and enjoy", trigger.x+30.0, trigger.y-130.0);
            addMessage( "TriggerLine3", "the pool of acid. I do hope you were", trigger.x+30.0, trigger.y-90.0 );
            addMessage( "TriggerLine4", "not intended to trap a dumb", trigger.x+30.0, trigger.y-50.0 );
            addMessage( "TriggerLine5", "Destroyer over here...", trigger.x+30.0, trigger.y-10.0 );
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
            removeMessages(6);            
        } else if( trigger.getTriggerNumber() == 4 ) {
            if( !destroyerReleased ) {
                removeMessages(5);                
            }
        } else if( trigger.getTriggerNumber() == 6 ) {
            removeMessages(7);
        } else if( trigger.getTriggerNumber() == 7 ) {
            removeMessages(7);            
        } else if( trigger.getTriggerNumber() == 8 ) {
            removeMessages(3);
        } else if( trigger.getTriggerNumber() == 9 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 0 ) {
            removeMessages(5);
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
        levelDataFileName = "FortressOfIce.dat";
        backgroundMusicAssetName = "FortressOfIce";
        backgroundMusicVolume = 100;
        targetNumEmoticonsToCollect = 0;
        targetNumEmoticonsToKill = 0;  
                
        super.setupLevel();
        
        viewPortFocusXOffset = 0;
        viewPortFocusYOffset = gameEngine.screenHeight/8;
        
        levelExitMessageXOffset = 0.0;
        levelExitMessageYOffset = -150.0;
        
        destroyerReleased = false;        
    }   
    
    /**
     * Perform level exit actions
     */
    @Override       
    protected void quitLevel() { 
        ((MidiAsset)assetManager.retrieveAssetArchetype( "FortressOfIce" )).stop();
        super.quitLevel();
    }
}
