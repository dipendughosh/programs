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
import java.awt.*;
import javax.swing.JPanel;

// Draws the intended transform function for contrast strettching.

class ContrastFunction extends JPanel{
	int r1,s1,r2,s2;

	public ContrastFunction(int rw1,int cl1,int rw2,int cl2){
		setForeground(Color.blue);
		this.resize(257,257);
		if ((rw1<=rw2)&&(cl1<=cl2)&&(rw1<256)&&(cl1<256)&&(rw2<256)&&(cl2<256)){
			this.r1=rw1;
			this.r2=rw2;
			this.s1=cl1;
			this.s2=cl2;
		}
	}
    
	public void paint(Graphics g){
        
        g.drawRect(10,10,255,255);
        g.drawString("0,0",17,275);
        g.drawString("255",245,275);
        g.drawString("255",15,8);

        g.drawOval(10-3,265-3,6,6);
        g.drawLine(0+10,255+10,r1+10,255-s1+10);
        
        g.drawOval(r1-3+10,255-s1-3+10,6,6);
        g.drawLine(r1+10,255-s1+10,r2+10,255-s2+10);
        
        g.drawOval(r2-3+10,255-s2-3+10,6,6);
        g.drawLine(r2+10,255-s2+10,255+10,0+10);
        
        g.drawOval(255+10-3,0+10-3,6,6);
        return;
	}
}

