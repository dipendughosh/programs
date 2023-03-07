/*
 * Copyright 2009 Dmitry Brant. All Rights Reserved.
 * me@dmitrybrant.com
 * http://dmitrybrant.com
 *
 * This program is free for personal use.
 * If you would like to use it in a commercial application, please
 * e-mail me at the address above.
 * This software comes as-is, with no warranty.
 *
 */
package dmitrybrant.mandelbrot;

import javax.microedition.lcdui.Canvas;
import javax.microedition.lcdui.Graphics;


class MandelbrotCanvas extends Canvas {
    MandelbrotApp myApp;

    MandelbrotCanvas (MandelbrotApp mandelTestlet) {
        myApp = mandelTestlet;
    }

    void init () {
    }

    void destroy () {
    }


    protected void paint (Graphics g) {
        myApp.paint (g);
    }

    protected void keyPressed (int key) {
        int action = getGameAction (key);

        float xScale = (myApp.rangex2 - myApp.rangex1);
        float yScale = (myApp.rangey2 - myApp.rangey1);

        boolean gotAction = true, gotKey = true;
        switch (action) {
        case LEFT:
            myApp.rangex1 += (xScale / 16.0F);
            myApp.rangex2 += (xScale / 16.0F);
            break;
        case RIGHT:
            myApp.rangex1 -= (xScale / 16.0F);
            myApp.rangex2 -= (xScale / 16.0F);
            break;
        case UP:
            myApp.rangey1 -= (yScale / 16.0F);
            myApp.rangey2 -= (yScale / 16.0F);
            break;
        case DOWN:
            myApp.rangey1 += (yScale / 16.0F);
            myApp.rangey2 += (yScale / 16.0F);
            break;
        case FIRE:
        default:
            gotAction = false;
        }

        if(!gotAction){
            switch (key){
            case KEY_NUM1:
                myApp.rangex1 -= (xScale / 4.0F);
                myApp.rangex2 += (xScale / 4.0F);
                myApp.rangey1 -= (yScale / 4.0F);
                myApp.rangey2 += (yScale / 4.0F);
                break;
            case KEY_NUM3:
                myApp.rangex1 += (xScale / 4.0F);
                myApp.rangex2 -= (xScale / 4.0F);
                myApp.rangey1 += (yScale / 4.0F);
                myApp.rangey2 -= (yScale / 4.0F);
                break;
            case KEY_NUM7:
                myApp.numIterations-=4; if(myApp.numIterations < 2) myApp.numIterations = 2;
                break;
            case KEY_NUM9:
                myApp.numIterations+=4;
                break;
            default:
                gotKey = false;
            }
        }

        if(gotAction || gotKey)
            myApp.RenderMandelbrot();
    }

}
