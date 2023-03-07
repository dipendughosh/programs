/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package tutorials.helloWorld;

import java.awt.*;
import game.engine.*;

/**
 *
 * @author DG
 */
public class HelloWorldLayer extends GameLayer
{
    public HelloWorldLayer(GameEngine gameEngine)
    {
        super("HelloWorldLayer", gameEngine);
        addGameObjectCollection("Chasers");
        MouseChaser mouseChaser = new MouseChaser(this);
        addGameObject(mouseChaser, "Chasers");
    }

    public void update()
    {
        GameObjectCollection chasers = getGameObjectCollection("Chasers");
        for (int idx = 0; idx < chasers.size; idx++)
        {
            GameObject chaser = chasers.gameObjects[idx];
            chaser.update();
        }
    }
    public void draw(Graphics2D graphics2D)
    {
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(Color.black);
        graphics2D.fillRect(0, 0, gameEngine.screenWidth, gameEngine.screenHeight);
        graphics2D.setColor(originalColour);
        super.draw(graphics2D);
    }
}
