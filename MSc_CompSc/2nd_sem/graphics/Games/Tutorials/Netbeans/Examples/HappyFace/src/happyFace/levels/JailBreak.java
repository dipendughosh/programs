package happyFace.levels;

import game.engine.*;
import game.assets.*;

import happyFace.*;

/**
 * First of the proper game levels - involving the breakout of emoticons
 * from a prison
 * 
 * @author <A HREF="mailto:P.Hanna@qub.ac.uk">Philip Hanna</A>
 * @version $Revision: 1.0 $ $Date: 2007/08 $
 */
public class JailBreak extends HappyFaceLevelLayer
{
    ///////////////////////////////////////////////////////////////////////////
    // Class data                                                            //
    ///////////////////////////////////////////////////////////////////////////

    /**
     * Variables specifying if the various triggers have already been fired
     */
    private boolean trigger2Fired = false;   
    private boolean trigger3Fired = false;
    private int trigger3MessageDisplayPeriod = 240;

    
    ///////////////////////////////////////////////////////////////////////////
    // Constructors                                                          //
    ///////////////////////////////////////////////////////////////////////////
    
    /**
     * Create a new Jail Break instance
     */      
    public JailBreak( GameEngine gameEngine ) 
    {
        super( gameEngine );                        
        setLevelName( "Jail Break" );                
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
            addMessage( "TriggerLine1", "Jail Break!", trigger.x+250.0, trigger.y-310.0 );
            addMessage( "TriggerLine2", "Break into the underground jail", trigger.x+250.0, trigger.y-250.0);
            addMessage( "TriggerLine3", "and rescue the oppressed and", trigger.x+250.0, trigger.y-210.0 );
            addMessage( "TriggerLine4", "trapped emoticons. At least " + targetNumEmoticonsToCollect, trigger.x+250.0, trigger.y-170.0 );
            addMessage( "TriggerLine5", "emoticons must be rescued.", trigger.x+250.0, trigger.y-130.0 );
            addMessage( "TriggerLine6", "Hint: A direct approach may not", trigger.x+250.0, trigger.y-70.0 );
            addMessage( "TriggerLine7", "be the best approach...", trigger.x+250.0, trigger.y-30.0 );            
        }
           
        else if( trigger.getTriggerNumber() == 2 ) {
            playerSpawnX = trigger.x;
            playerSpawnY = trigger.y;

            // If the player has rescued the emoticons and is leaving the prison
            // then set a small bomb to blow the two spike balls on the way in.
            // If not already released they will roll down the passage.
            if( !trigger2Fired 
                    && currentNumEmoticonsCollected >= targetNumEmoticonsToCollect ) {
                ExplodingBody explosion = new ExplodingBody( this, 4656, 1551, 1,
                    ExplodingBody.ExplosionBody.SmallBomb, ExplodingBody.ExplosionType.Small, 0, 0);
                explosion.setFuseDuration( 100 );
                explosion.igniteFuse();
                this.queueGameObjectToAdd( explosion, "Explosions" );
                
                trigger2Fired = true;
            }            
        }        

        else if( trigger.getTriggerNumber() == 3 ) {            
            playerSpawnX = trigger.x;
            playerSpawnY = trigger.y;

            // If the player has rescued the emoticons and is leaving the 
            // prison then set off a number of charges to destroy most of
            // the inner section. This will likely force the player to escape
            // up the main passage.
            if( !trigger3Fired 
                    && currentNumEmoticonsCollected >= targetNumEmoticonsToCollect ) {

                viewPortLayerX = trigger.x; viewPortLayerY = trigger.y;      
                validateViewPort();
                
                addMessage( "Trigger3Line1", "Alert!", trigger.x, trigger.y-200.0 );                
                addMessage( "Trigger3Line2", "Alarm triggered!", trigger.x, trigger.y-150.0 );                
                
                ExplodingBody explosion = new ExplodingBody( this, 7400, 1950, 4,
                    ExplodingBody.ExplosionBody.LargeBomb, ExplodingBody.ExplosionType.Large, 0, 0);
                explosion.setFuseDuration( 20000 ); explosion.igniteFuse();
                this.queueGameObjectToAdd( explosion, "Explosions" );

                explosion = new ExplodingBody( this, 7450, 1570, 4,
                    ExplodingBody.ExplosionBody.LargeBomb, ExplodingBody.ExplosionType.Large, 0, 0);
                explosion.setFuseDuration( 20000 ); explosion.igniteFuse();
                this.queueGameObjectToAdd( explosion, "Explosions" );

                
                explosion = new ExplodingBody( this, 6980, 1570, 4,
                    ExplodingBody.ExplosionBody.LargeBomb, ExplodingBody.ExplosionType.Large, 0, 0);
                explosion.setFuseDuration( 25000 ); explosion.igniteFuse();
                this.queueGameObjectToAdd( explosion, "Explosions" );
                
                explosion = new ExplodingBody( this, 6770, 1840, 4,
                    ExplodingBody.ExplosionBody.LargeBomb, ExplodingBody.ExplosionType.Large, 0, 0);
                explosion.setFuseDuration( 25250 ); explosion.igniteFuse();
                this.queueGameObjectToAdd( explosion, "Explosions" );
                
                explosion = new ExplodingBody( this, 6450, 1570, 4,
                    ExplodingBody.ExplosionBody.LargeBomb, ExplodingBody.ExplosionType.Large, 0, 0);
                explosion.setFuseDuration( 25500 ); explosion.igniteFuse();
                this.queueGameObjectToAdd( explosion, "Explosions" );


                explosion = new ExplodingBody( this, 5910, 1700, 4,
                    ExplodingBody.ExplosionBody.LargeBomb, ExplodingBody.ExplosionType.Large, 0, 0);
                explosion.setFuseDuration( 30000 ); explosion.igniteFuse();
                this.queueGameObjectToAdd( explosion, "Explosions" );
                
                trigger3Fired = true;
            }            
        }        
        
        else if( trigger.getTriggerNumber() == 4 ) {
            if( currentNumEmoticonsCollected < targetNumEmoticonsToCollect ) {
                addMessage( "TriggerLine1", "You must release at least " 
                        + targetNumEmoticonsToCollect, trigger.x+360.0, trigger.y-50.0 );
                addMessage( "TriggerLine2", "emoticons to exit this level...", trigger.x+360.0, trigger.y );
            }
        }
        
        else if( trigger.getTriggerNumber() == 5 ) {
            addMessage( "TriggerLine1", "One has to question the wisdom", trigger.x+200.0, trigger.y-180.0 );
            addMessage( "TriggerLine2", "of building a 'secure',", trigger.x+200.0, trigger.y-140.0 );
            addMessage( "TriggerLine3", "underground prison just below ", trigger.x+200.0, trigger.y-100.0 );
            addMessage( "TriggerLine4", "a deep hollow in the ground...", trigger.x+200.0, trigger.y-60.0 );
        }         

        else if( trigger.getTriggerNumber() == 6 ) {
            addMessage( "TriggerLine1", "A supply stash -  lets hope", trigger.x-10.0, trigger.y-170.0 );
            addMessage( "TriggerLine2", "your timing and bomb throwing", trigger.x-10.0, trigger.y-130.0 );
            addMessage( "TriggerLine3", "skills are good...", trigger.x-10.0, trigger.y-90.0 );
        }         
  
        else if( trigger.getTriggerNumber() == 7 ) {
            addMessage( "TriggerLine1", "The prison cells - it will be", trigger.x-130.0, trigger.y-70.0 );
            addMessage( "TriggerLine2", "necessary to bomb jump up", trigger.x-130.0, trigger.y-30.0 );
            addMessage( "TriggerLine3", "to escape the prision", trigger.x-130.0, trigger.y+10.0 );
        }         
    }

    /**
     * Perform trigger continuational actions if the player remains within 
     * the bounds of a trigger
     */    
    @Override       
    protected void continueTrigger( Trigger trigger ) {
        if( trigger.getTriggerNumber() == 3 ) {
            if( trigger3Fired && trigger3MessageDisplayPeriod > 0 ) {
                trigger3MessageDisplayPeriod--;
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
        } else if( trigger.getTriggerNumber() == 3 ) {
            if( trigger3Fired && trigger3MessageDisplayPeriod == 0 ) {
                queueGameObjectToRemove( getGameObject( "Trigger3Line1" ) );    
                queueGameObjectToRemove( getGameObject( "Trigger3Line2" ) );                
                trigger3MessageDisplayPeriod = -1;
            }
        } else if( trigger.getTriggerNumber() == 4 ) {
            if( currentNumEmoticonsCollected < targetNumEmoticonsToCollect ) {
                removeMessages(2);
            }
        } else if( trigger.getTriggerNumber() == 5 ) {
            removeMessages(4);
        } else if( trigger.getTriggerNumber() == 6 ) {
            removeMessages(3);
        } else if( trigger.getTriggerNumber() == 7 ) {
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
        levelDataFileName = "JailBreak.dat";
        backgroundMusicAssetName = "JailBreak";
        backgroundMusicVolume = 80;
        targetNumEmoticonsToCollect = 6;
        targetNumEmoticonsToKill = 0;  
                
        super.setupLevel();
        
        viewPortFocusXOffset = 0;
        viewPortFocusYOffset = -gameEngine.screenHeight/8;
        
        levelExitMessageXOffset = 0.0;
        levelExitMessageYOffset = -200.0;
        
        trigger2Fired = false;   
        trigger3Fired = false;
        trigger3MessageDisplayPeriod = 240;
    }   
    
    /**
     * Perform level exit actions
     */
    @Override        
    protected void quitLevel() { 
        ((MidiAsset)assetManager.retrieveAssetArchetype( "JailBreak" )).stop();
        super.quitLevel();
    }
}
