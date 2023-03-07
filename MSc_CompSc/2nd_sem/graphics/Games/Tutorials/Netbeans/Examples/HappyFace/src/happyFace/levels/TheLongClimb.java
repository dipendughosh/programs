package happyFace.levels;

import game.engine.*;
import game.assets.*;

import happyFace.*;

/**
 * Advanced tutorial game level where the player has to escape upwards
 * (involves a good amount of precise jumping)
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */
public class TheLongClimb extends HappyFaceLevelLayer
{
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Variables used to control the fall of spiky balls in one section of
     * the level. 
     */
    private final int MAX_SPIKES_TO_DROP = 25;
    private final int SPIKE_DROP_FREQUENCY = 600;
    private boolean spikeFallTriggered;
    private int numSpikesFallen;
    
    /**
     * Variables used to signify if the waves of happy emoticons have
     * been spawned
     */    
    private boolean firstWaveSpawned;
    private boolean secondWaveSpawned;
    
    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new The Long Climb instance
     */    
    public TheLongClimb( GameEngine gameEngine ) 
    {
        super( gameEngine );                        
        setLevelName( "The Long Climb" );
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
            addMessage( "TriggerLine1", "The Long Climb...", trigger.x+250.0, trigger.y-310.0 );
            addMessage( "TriggerLine2", "Escape from your hellish home", trigger.x+250.0, trigger.y-250.0);
            addMessage( "TriggerLine3", "by gathering resources and", trigger.x+250.0, trigger.y-210.0 );
            addMessage( "TriggerLine4", "climbing up. Once free your", trigger.x+250.0, trigger.y-170.0 );
            addMessage( "TriggerLine5", "reign of terror can begin!", trigger.x+250.0, trigger.y-130.0 );
            addMessage( "TriggerLine6", "Hint: A devil to the east holds", trigger.x+250.0, trigger.y-70.0 );
            addMessage( "TriggerLine7", "a stash of bombs...", trigger.x+250.0, trigger.y-30.0 );
        } 
        
        else if( trigger.getTriggerNumber() == 2 ) { 
            addMessage( "TriggerLine1", "Hint: Apart from", trigger.x-110.0, trigger.y-370.0 );
            addMessage( "TriggerLine2", "exploding barriers,", trigger.x-110.0, trigger.y-330.0);
            addMessage( "TriggerLine3", "bombs are not really", trigger.x-110.0, trigger.y-290.0 );            
            addMessage( "TriggerLine4", "needed on this level", trigger.x-110.0, trigger.y-250.0 );            
            addMessage( "TriggerLine5", "although they can really", trigger.x-110.0, trigger.y-210.0 );            
            addMessage( "TriggerLine6", "help in jumping up...", trigger.x-110.0, trigger.y-170.0 );            
        }
            
        else if( trigger.getTriggerNumber() == 3 ) { 
            addMessage( "TriggerLine1", "Hint: Destroy the barrier", trigger.x, trigger.y+200.0 );
            addMessage( "TriggerLine2", "with a bomb. You may then", trigger.x, trigger.y+240.0);
            addMessage( "TriggerLine3", "need to clear the debris", trigger.x, trigger.y+280.0 );            
            addMessage( "TriggerLine4", "off the ledge to enable", trigger.x, trigger.y+320.0 );            
            addMessage( "TriggerLine5", "you to jump up.", trigger.x, trigger.y+360.0 );            
        }

        else if( trigger.getTriggerNumber() == 4 ) {
            addMessage( "TriggerLine1", "It sounds like heavy things", trigger.x-70.0, trigger.y-200.0 );            
            addMessage( "TriggerLine2", "are falling up ahead. Climb up", trigger.x-70.0, trigger.y-160.0 );            
            addMessage( "TriggerLine3", "without delay and be extra", trigger.x-70.0, trigger.y-120.0 );            
            addMessage( "TriggerLine4", "cautious...", trigger.x-70.0, trigger.y-80.0 );            
            
            spikeFallTriggered = true;
        }   
        
        else if( trigger.getTriggerNumber() == 5 ) {
            spikeFallTriggered = false;
        }            
            
        else if( trigger.getTriggerNumber() == 6 ) {
            if( firstWaveSpawned == false ) {            
                addMessage( "TriggerLine1", "Oh, dear... Your escape", trigger.x, trigger.y-50.0 );                
                addMessage( "TriggerLine2", "attempt been noticed...", trigger.x, trigger.y );                
                addMessage( "TriggerLine3", "Incoming!", trigger.x, trigger.y+50.0 );                
            
                createChasingEmoticon( "EmoticonSetCHappy3", 11215.0, 2940.0 );
                createChasingEmoticon( "EmoticonSetCHappy3", 11309.0, 2940.0 );
            }
        }                        

        else if( trigger.getTriggerNumber() == 7 ) {
            addMessage( "TriggerLine1", "Bouncers... cleanly", trigger.x, trigger.y-200.0 );            
            addMessage( "TriggerLine2", "jump on top to be", trigger.x, trigger.y-160.0 );            
            addMessage( "TriggerLine3", "propelled upwards...", trigger.x, trigger.y-120.0 );            
            
            spikeFallTriggered = true;
        }   
            
        else if( trigger.getTriggerNumber() == 8 ) {
            if( secondWaveSpawned == false ) {                        
                createChasingEmoticon( "EmoticonSetCHappy3", 8860.0, 1050.0 );
                createChasingEmoticon( "EmoticonSetCHappy1", 9164.0, 1050.0 );
                createChasingEmoticon( "EmoticonSetCHappy2", 9341.0, 1050.0 );
                createChasingEmoticon( "EmoticonSetCHappy1", 9643.0, 1050.0 );
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
        } else if( trigger.getTriggerNumber() == 2 ) {
            removeMessages(6);
        } else if( trigger.getTriggerNumber() == 3 ) {
            removeMessages(5);
        } else if( trigger.getTriggerNumber() == 4 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 6 ) {
            if( firstWaveSpawned == false ) {
                removeMessages(3);            
                firstWaveSpawned = true;
            }
        } else if( trigger.getTriggerNumber() == 7 ) {
            removeMessages(3);
        } else if( trigger.getTriggerNumber() == 8 ) {     
            secondWaveSpawned = true;
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
     * Create an emoticon of the specified type that will chase the player
     */
    private void createChasingEmoticon( String emoticonName, double spawnX, double spawnY ) {        
        EmoticonAI emoticon = new EmoticonAI(  this, emoticonName, 
            spawnX, spawnY, HappyFaceLevelLayer.EMOTICON_DRAW_ORDER  );      
        emoticon.setChaseAI( EmoticonAI.ChaseAI.Chase );
        emoticon.setChaseRange( EmoticonAI.CHASE_RANGE_XL );
        emoticon.setVisibleRange( EmoticonAI.VISIBLE_RANGE_XL );
        
        emoticon.setJumpFrequency( 
                gameEngine.randomiser.nextDouble() < 0.5 ?
                    EmoticonAI.JUMP_FREQUENCY_S : EmoticonAI.JUMP_FREQUENCY_XS );
        emoticon.setJumpProbability( 
                gameEngine.randomiser.nextDouble() < 0.5 ?
                    EmoticonAI.JUMP_PROBABILITY_L : EmoticonAI.JUMP_PROBABILITY_XL );

        levelMaximumScore += emoticon.getPoints();
        queueGameObjectToAdd( emoticon, "Emoticons" );
    }
    
    /**
     * Update the level - spawning spike balls if needed
     */
    @Override        
    public void update() {
        super.update();
        
        if( spikeFallTriggered && numSpikesFallen < MAX_SPIKES_TO_DROP ) {
            if( gameEngine.updateCounter % SPIKE_DROP_FREQUENCY == 0 ) {
                InteractingBody spikeBall = new InteractingBody(  this, 0.0, 0.0, 
                        HappyFaceLevelLayer.ITEM_DRAW_ORDER, "SpikyBall2",
                        InteractingBody.InteractionType.Spiky,
                        InteractingBody.InteractionStrength.Mild, true  );
                
                switch( gameEngine.randomiser.nextInt(4) ) {
                    case 0: spikeBall.setPosition( 7143.0, 3086.0 ); break;
                    case 1: spikeBall.setPosition( 7496.0, 3086.0 ); break;
                    case 2: spikeBall.setPosition( 7720.0, 3086.0 ); break;
                    case 3: spikeBall.setPosition( 8079.0, 3086.0 ); break;
                }

                queueGameObjectToAdd( spikeBall, "InteractingBodies" );                
                numSpikesFallen++;
            }            
        }        
    }
        
    /**
     * Setup the game levle
     */
    @Override    
    public void setupLevel()
    {     
        levelDataFileName = "TheLongClimb.dat";
        backgroundMusicAssetName = "TheLongClimb";
        backgroundMusicVolume = 80;
        targetNumEmoticonsToCollect = 0;
        targetNumEmoticonsToKill = 0;  
        
        super.setupLevel();

        viewPortFocusXOffset = 0;
        viewPortFocusYOffset = +gameEngine.screenHeight/8;        
        
        levelExitMessageXOffset = 0.0;
        levelExitMessageYOffset = -200.0;
        
        spikeFallTriggered = false; 
        numSpikesFallen = 0;
        firstWaveSpawned = false;        
        secondWaveSpawned = false;        
    }   

    /**
     * Perform level exit actions
     */
    @Override    
    protected void quitLevel() { 
        ((MidiAsset)assetManager.retrieveAssetArchetype( "TheLongClimb" )).stop();
        super.quitLevel();
    }
}