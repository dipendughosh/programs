/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package tutorials.bodyExample;

import game.engine.*;
import game.physics.*;
import java.awt.*;
/**
 *
 * @author DG
 */
public class BodyExampleLayer extends CollisionSpace
{
    public BodyExampleLayer(GameEngine gameEngine)
    {
        super("BodyExampleLayer", gameEngine);
        width = gameEngine.screenWidth;
        height = gameEngine.screenHeight;
        MAXIMUM_TRAVEL_VELOCITYX = 500.0;
        MAXIMUM_TRAVEL_VELOCITYY = 500.0;
        MAXIMUM_ANGULAR_VELOCITY = 5.0;
        createGameObjects(); // We’ll add this shortly
    }
    public void draw(Graphics2D graphics2D)
    {
        Color originalColour = graphics2D.getColor();
        graphics2D.setColor(Color.black);
        graphics2D.fillRect(0, 0, gameEngine.screenWidth, gameEngine.screenHeight);
        graphics2D.setColor(originalColour);
        super.draw(graphics2D);
    }
    public void createGameObjects()
    {
        addGameObjectCollection("Planets");
        Spaceship spaceship = new Spaceship(this);
        spaceship.setName("Spaceship");
        addGameObject(spaceship);
        int numPlanets = 5;
        for (int planetIdx = 0; planetIdx < numPlanets; planetIdx++)
        {
            Planet planet = new Planet(this);
            planet.x = gameEngine.randomiser.nextInt((int) width);
            planet.y = gameEngine.randomiser.nextInt((int) height);
            addGameObject(planet, "Planets");
        }
    }
    public void update()
    {
        Spaceship spaceship = (Spaceship) this.getGameObject( "Spaceship" );
        spaceship.update();
        double gravityStrength = 5.0;
        if (spaceship.x < this.width / 2)
        {
            spaceship.velocityx += gravityStrength;
        }
        else
        {
            spaceship.velocityx -= gravityStrength;
        }
        if (spaceship.y < this.height / 2)
        {
            spaceship.velocityy += gravityStrength;
        }
        else
        {
            spaceship.velocityy -= gravityStrength;
        }
        super.update();
        GameObjectUtilities.reboundIfGameLayerExited(spaceship);
    }

}