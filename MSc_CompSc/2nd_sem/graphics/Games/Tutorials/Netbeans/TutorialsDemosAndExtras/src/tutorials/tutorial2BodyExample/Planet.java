package tutorials.tutorial2BodyExample;

import game.engine.*;
import game.physics.*;
import game.geometry.*;

public class Planet extends Body {
    
    public Planet(GameLayer gameLayer) {
        super(gameLayer);
        
        setRealisation("Planet");
        setGeometry(new Circle(0, 0, 25));
        
        setMass(Double.MAX_VALUE);
        restitution = 1.0;
    }
}
