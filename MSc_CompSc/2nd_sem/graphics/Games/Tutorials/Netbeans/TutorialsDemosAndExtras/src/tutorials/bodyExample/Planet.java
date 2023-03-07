/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package tutorials.bodyExample;

import game.engine.*;
import game.physics.*;
import game.geometry.*;
/**
 *
 * @author DG
 */

public class Planet extends Body
{
    public Planet(GameLayer gameLayer)
    {
        super(gameLayer);
        setRealisation("Planet");
        setGeometry(new Circle(0, 0, 25));
        setMass(Double.MAX_VALUE);
        restitution = 1.0;
    }
}