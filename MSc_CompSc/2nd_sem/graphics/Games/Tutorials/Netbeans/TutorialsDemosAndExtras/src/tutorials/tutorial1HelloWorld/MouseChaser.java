package tutorials.tutorial1HelloWorld;

import game.engine.*;

public class MouseChaser extends GameObject {
    
    public MouseChaser(GameLayer gameLayer) {
        super(gameLayer);
        
        setRealisationAndGeometry("HelloWorldAsset");
    }
    
    public void update() {
        this.x = inputEvent.mouseXCoordinate;
        this.y = inputEvent.mouseYCoordinate;
    }
}
