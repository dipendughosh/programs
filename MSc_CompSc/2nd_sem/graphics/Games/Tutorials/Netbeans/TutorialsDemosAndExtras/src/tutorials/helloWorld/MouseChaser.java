/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package tutorials.helloWorld;

import game.engine.*;
/**
 *
 * @author DG
 */
public class MouseChaser extends GameObject
{
    public MouseChaser(GameLayer gameLayer)
    {
        super(gameLayer);
        setRealisationAndGeometry("HelloWorldAsset");
    }

    public void update()
    {
        this.x = inputEvent.mouseXCoordinate;
        this.y = inputEvent.mouseYCoordinate;
    }
}
