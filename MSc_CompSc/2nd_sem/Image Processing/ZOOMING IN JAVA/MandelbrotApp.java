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

import javax.microedition.lcdui.*;
import javax.microedition.midlet.MIDlet;
import javax.microedition.midlet.MIDletStateChangeException;


public class MandelbrotApp extends MIDlet implements CommandListener {
    private Display myDisplay;
    private MandelbrotCanvas myCanvas;
    private Command exit = new Command ("Exit", Command.EXIT, 1);
    private Command about = new Command ("About", Command.ITEM, 2);

    private int[] colorPalette;
    private int[] scanlineBuffer;
    private int screenWidth = 0, screenHeight = 0;

    public float rangex1 = -2F, rangex2 = 0.5F, rangey1 = -1.4F, rangey2 = 1.4F;
    public int numIterations = 24;


    public MandelbrotApp () {
        super ();

        myDisplay = Display.getDisplay (this);
        myCanvas = new MandelbrotCanvas (this);
        myCanvas.setCommandListener (this);
        myCanvas.addCommand (exit);
        myCanvas.addCommand(about);

        scanlineBuffer = null;
        colorPalette = new int[256];

        for(int i=0; i<64; i++)
            colorPalette[i] = (((i * 4) << 8) | ((63 - i) * 4));
        for(int i=64; i<128; i++)
            colorPalette[i] = ((((i - 64) * 4) << 16) | (((127 - i) * 4) << 8));
        for(int i=128; i<192; i++)
            colorPalette[i] = (((255) << 16) | ((i - 128) * 4));
        for(int i=192; i<256; i++)
            colorPalette[i] = ((((255 - i) * 4) << 16) | (255));

    }


    public void init () throws MIDletStateChangeException {
    }

    public void startApp () throws MIDletStateChangeException {
        myDisplay.setCurrent (myCanvas);
        RenderMandelbrot();
    }

    public void pauseApp () {
    }

    /**
     * destroyApp()
     * <p/>
     * This is important.  It closes the app's RecordStore
     *
     * @param cond true if this is an unconditional destroy
     *             false if it is not
     *             currently ignored and treated as true
     */
    public void destroyApp (boolean cond) {
        myDisplay.setCurrent ((Displayable) null);
        myCanvas.destroy ();
        notifyDestroyed ();
    }


    public void RenderMandelbrot(){
        if((myCanvas.getWidth() != screenWidth) || (myCanvas.getHeight() != screenHeight)){
            screenWidth = myCanvas.getWidth();
            screenHeight = myCanvas.getHeight();
            scanlineBuffer = new int[screenWidth * screenHeight];
        }

        float bmpWidth = (float)screenWidth;
        float bmpHeight = (float)screenHeight;

        float x, y, xsquare, ysquare, dx, dy, bail = 4, j, p;
        int i, mul, col;
        int xpos, ypos;

        //float rangex1 = -0.1795247F, rangex2 = -0.1404622F, rangey1 = 1.013583F, rangey2 = 1.053083F, p;
        float[] q = null;

        if(screenWidth > screenHeight) q = new float[screenWidth + 1];
        else q = new float[screenHeight + 1];

        mul = 255 / numIterations;
        dx = (rangex2 - rangex1) / bmpWidth;
        dy = (rangey2 - rangey1) / bmpHeight;

        q[0] = rangey2;
        for(i=1; i < q.length; i++) q[i] = q[i - 1] - dy;


        xpos = 0; ypos = 0;

        for(p = rangex1; p <= rangex2; p += dx){
            i = 0;

            for(j = rangey1; j <= rangey2; j += dy){
                x = 0; y = 0; xsquare = 0; ysquare = 0; col = 1;

                while(true){
                    if(col > numIterations){
                        scanlineBuffer[ypos*screenWidth + xpos] = 0;
                        break;
                    }
                    if((xsquare + ysquare) > bail){
                        scanlineBuffer[ypos*screenWidth + xpos] = colorPalette[(col*mul)%255];
                        break;
                    }
                    xsquare = x * x;
                    ysquare = y * y;
                    y *= x;

                    y += (y + q[i]);
                    x = xsquare - ysquare + p;
                    col++;
                }
                i++;
                ypos++;
                if(ypos >= screenHeight) break;
            }

            myCanvas.repaint();
            myCanvas.serviceRepaints();

            xpos++;
            if(xpos >= screenWidth) break;
            ypos = 0;
        }
    }



    public void paint (Graphics g) {

        g.drawRGB(scanlineBuffer, 0, screenWidth, 0, 0, screenWidth, screenHeight, false);

        g.setColor(0xFFFFFF);
        int fontHeight = g.getFont().getHeight();
        int strY = 4;
        g.drawString("(C) Dmitry Brant", 4, strY, 0); strY += fontHeight;
        g.drawString("Iterations: " + Integer.toString(numIterations), 4, strY, 0); strY += fontHeight;
    }

    public void commandAction (Command cmd, Displayable disp) {
        if (cmd == exit) {
            destroyApp (true);
        }
        else if(cmd == about){
            Alert alert = new Alert ("About...");
            alert.setType (AlertType.INFO);
            alert.setTimeout (Alert.FOREVER);
            alert.setString ("Copyright 2009 Dmitry Brant.\nhttp://dmitrybrant.com");
            myDisplay.setCurrent (alert);
        }
    }
}
