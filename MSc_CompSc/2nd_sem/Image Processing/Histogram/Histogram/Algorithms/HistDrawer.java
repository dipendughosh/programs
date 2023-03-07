package Algorithms;

/**
    *************************************************************************************
    * File: RGBEncoder.java                Date: 21/11/2004           Version: 1.01         *
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
import java.awt.Color;
import java.awt.Graphics;

class HistDrawer{

	Color C;		// Color to draw with.
	int n;			// No. of data points - 1. |points|=(n+1)
	int X[],Y[];	// |X|=|Y|=n+1 .. coordinates..

	// Constructor
	// data : Data as unnormalized nonnegative float.
	// n : |data|-1
	// ymax : upper limit of HistDrawer >= max{data[i]}  for all  0=<i=<n
	// C : color to plot the line HistDrawer in.
	// X0,Y0 : top left coordinates for the HistDrawer.
	// W,H : width and height of area to use for plotting.
	
	public HistDrawer(float[] data,int n,float ymax,
		Color C,int X0,int Y0,int W, int H){
			
		this.n=n;
		this.C=C;

		X=new int[n+1];
		Y=new int[n+1];
		int i=0;
        float xd=W/n;
		float yd=H/ymax;
            
		for (i=0;i<=n;i++){
			Y[i]=Y0+(H-((int)(data[i]*yd)));
			X[i]=X0+(int)(i*xd);
		}
	}

	public void draw(Graphics g){
		
		int i=0;
		Color temp=g.getColor();
		g.setColor(C);
		
		for (i=0;i<n;i=i+2){
			//g.drawLine(X[i],Y[i],X[i+1],Y[i+1]);// line graph
			g.drawLine(X[i],Y[i],X[i],176); // Column graph
		}
		g.setColor(temp);
	}
}

