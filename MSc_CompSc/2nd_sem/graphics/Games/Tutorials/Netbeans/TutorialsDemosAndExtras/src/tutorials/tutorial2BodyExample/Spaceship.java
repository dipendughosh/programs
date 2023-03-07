package tutorials.tutorial2BodyExample;

import game.engine.*;
import game.physics.*;
import java.awt.event.*;

public class Spaceship extends Body {
    
    private double shipMovementAcceleration = 10.0;
    private double shipRotationalAcceleration = 0.15;
    private double shipRotationalDampening = 0.1;
    
    public Spaceship(GameLayer gameLayer) {
        super(gameLayer);
        
        x = gameLayer.width / 2;
        y = gameLayer.height / 2;
        
        rotation = Math.PI / 2.0;
        
        setMass(100.0);
        
        setRealisationAndGeometry("Spaceship");
    }
    
    public void update() {
        if (inputEvent.keyPressed[KeyEvent.VK_UP]) {
            velocityx += Math.sin(rotation) * shipMovementAcceleration;
            velocityy -= Math.cos(rotation) * shipMovementAcceleration;
        } else if (inputEvent.keyPressed[KeyEvent.VK_DOWN]) {
            velocityx -= Math.sin(rotation) * shipMovementAcceleration;
            velocityy += Math.cos(rotation) * shipMovementAcceleration;
        }
        
        if (inputEvent.keyPressed[KeyEvent.VK_RIGHT]) {
            angularVelocity += shipRotationalAcceleration;
        } else if (inputEvent.keyPressed[KeyEvent.VK_LEFT]) {
            angularVelocity -= shipRotationalAcceleration;
        }
        
        if (Math.abs(angularVelocity) < shipRotationalDampening) {
            angularVelocity = 0.0;
        } else {
            angularVelocity -=
                    shipRotationalDampening * Math.signum(angularVelocity);
        }
    }
}
