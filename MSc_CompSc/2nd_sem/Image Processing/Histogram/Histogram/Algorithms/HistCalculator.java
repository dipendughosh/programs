package Algorithms;

/**
    *************************************************************************************
    * File: HistCaculator.java          Date: 21/11/2004             Version: 1.01      *
    *-----------------------------------------------------------------------------------*
    * This program is released under the GNU General Public License 2.00.                 
    * Details of GNU GPL at http://www.opensource.org/licenses/gpl-license.php              
    * You must agree to this license before using, copying or modifying this code.                                  
    *
    * Redistribution and use in source and binary forms, with or without
    * modification, are permitted provided that the following conditions
    * are met:
    *
    * 1. Redistributions of source code must retain the above copyright
    *    notice, this list of conditions and the following disclaimer.
    * 2. The source can be used and modified by individual/organizations, 
    *     ONLY IF the source will not be used 
    *    for commercial purposes or incorporated into commercial applications.
    *
    * --------------------------------- WARRANTY --------------------------------- 
    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR "AS IS" AND ANY EXPRESS OR IMPLIED 
    * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
    * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  
    * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
    * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
    * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; 
    * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
    * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR 
    * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
    * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
    *
    * --------------------------------- CONTACT --------------------------------- 
    * This project was written in a burning hurry, so it is not a model of efficient
    * nor even good code.
    * Please send comments, bug reports, improvements to: hoptrandinh@yahoo.com  

    * @Author: this source come from http://java.sun.com/
    * @Edited by Tran Dinh Hop, 6 Nov 2004
    * @Please visit http://www.freewebs.com/DigitZone for updated version
*/
import javax.swing.*;
import java.awt.*;
import java.awt.image.PixelGrabber;

class HistCalculator extends JPanel{
	HistManager hisMan;
	HistDrawer grR,grG,grB,grGS;
	int W,H;
	int MAX;
	int type;

	public HistCalculator(HistManager hisMan, int type){
		this.hisMan=hisMan;
		this.type=type;
		W=hisMan.W;
		H=hisMan.H;
		this.resize(324,202);
		calc();
	}

	// Recalculates the HistCalculator.
	public void calc(){
		int WxH=W*H;
		int[] pixels=new int[WxH];
		int i;
		try{
			PixelGrabber pg = new PixelGrabber(hisMan.disp,0,0,W,H,pixels,0,W);
			pg.grabPixels();
		} catch (InterruptedException e) { };

		float[] R=new float[256];
		float[] B=new float[256];
		float[] G=new float[256];
		float[] GS=new float[256];
		float MAX=0;

		for (i=0;i<255;i++){
			R[i]=0;
			G[i]=0;
			B[i]=0;
			GS[i]=0;
		}

		for (i=0;i<WxH;i++){
			int rgb=pixels[i];
			R[((rgb>>16) & 0xff)]++;     //Red   Channel
			G[((rgb>>8) & 0xff)]++;      //Green   Channel
            B[((rgb) & 0xff)]++;         //Blue   Channel
			int rgbValue = (rgb) & 0xFFFFFF; //Greyscale   Channel
			float pec,pos;
			pec = ((float)rgbValue*100)/16777215;	 //Get x% of 24 bit colour, 16 mils color .
			pos = (256 * pec)/100;			         //Get value of x% of 256.
			
			int tmp = (int)Math.round(pos);          //Greyscale   Channel
			if(tmp > 255 )
				tmp = (int)255;
			else if(tmp < 0) 
				tmp = (int)0;
			GS[Math.round(tmp)]++;
		}
		for (i=0;i<255;i++){
			if (R[i]>MAX) MAX=R[i];
			if (G[i]>MAX) MAX=G[i];
			if (B[i]>MAX) MAX=B[i];					
			if (GS[i]>MAX) MAX=GS[i];					
		}

		grR = new HistDrawer(R,255,MAX,Color.red,10,26,256,150);
		grG = new HistDrawer(G,255,MAX,Color.green,10,26,256,150);
		grB = new HistDrawer(B,255,MAX,Color.blue,10,26,256,150);
		grGS = new HistDrawer(GS,255,MAX,Color.black,10,26,256,150);
		
		this.MAX=(int)MAX;

		repaint();
	}

	public void paint(Graphics g){
		if (type == 0){
			grGS.draw(g); //draw greyscale histogram
		}
		else if (type == 1){
			grR.draw(g);//draw red histogram
		}
		else if (type == 2){
			grG.draw(g);//draw green histogram
		}
		else if (type == 3){
			grB.draw(g);//draw blue histogram
		}
		
		g.drawRect(9,25,258,152);
		g.drawString("0",9,189);
		g.drawString("255",246,189);
		g.drawString("0",269,177);
		g.drawString((new Integer(MAX)).toString(),235,23);//269 37
	}
}

