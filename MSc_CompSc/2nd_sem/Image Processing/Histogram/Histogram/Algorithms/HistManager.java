package Algorithms;

/**
    *************************************************************************************
    * File: HistManager.java                Date: 21/11/2004           Version: 1.01         *
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
import javax.swing.JPanel;
import java.awt.*;
import java.awt.image.MemoryImageSource;
import java.awt.image.PixelGrabber;

import Algorithms.HistCalculator;

public class HistManager extends JPanel{
	
	Image disp;					// Image currently in display.
	private Image Undo;			// Image before last enhancement.
	int W,H;					// Width and height of the image. 
	private String filename;	// Filename of original image. 
	private int ipixels[];		// Array dump of image during enhancement.(read)
	private int opixels[];		// Array dump of image during enhancement.(write)
	private int reads,writes;	// No. of reads and writes on the image.
	HistCalculator hist, hist1, hist2, hist3;

	public HistManager(String filename){
		this.filename=filename;
		try{
			Toolkit toolkit=Toolkit.getDefaultToolkit();
			this.disp=toolkit.getImage(filename);
			this.Undo=toolkit.getImage(filename);
		
			MediaTracker t=new MediaTracker(this);
			t.addImage(this.disp,0);
			t.addImage(this.Undo,1);
			t.waitForID(0);
			t.waitForID(1);
			this.W=this.disp.getWidth(null);
			this.H=this.disp.getHeight(null);
		} catch (InterruptedException e) { };
		
		ipixels=new int[this.W*this.H];
		opixels=new int[this.W*this.H];
		//this.enhancementInProgress=false;
		//this.setLocation(200,300);
		hist = new HistCalculator(this,0);
		hist1 = new HistCalculator(this,1);
		hist2 = new HistCalculator(this,2);
		hist3 = new HistCalculator(this,3);
	}

	public void paint(Graphics g){
		update(g);
	}

	public void update(Graphics g){
		g.drawImage(this.disp,0,0,this);
	}

	public boolean handleEvent(Event e){
    	if (e.id == Event.WINDOW_DESTROY){
    		System.exit(0);
    		return true;
    	}
    	return false;
	}

	public void undo(){
		// swap disp and Undo;
		Image t=Undo;
		Undo=disp;
		disp=t;
		repaint();
		hist.calc();
	}

	// Swaps disp and Undo and then loads original image in disp
	public void revert(){
		// swap disp and Undo;
		Image te=Undo;
		Undo=disp;
		disp=te;

		try{
			Toolkit toolkit=Toolkit.getDefaultToolkit();
			this.disp=toolkit.getImage(filename);
			MediaTracker t=new MediaTracker(this);
			t.addImage(this.disp,0);
			t.waitForID(0);
		} catch (InterruptedException e) { };
		repaint();
		hist.calc();
	}

	// Methods to be used by any image enhancement routines
	
	// This method is to be called before starting any enhancement routine
	// returns an int array [ImageWidth,ImageHeight]
	public int[] startProcess(){
		// swap disp and Undo;
		Image t=Undo;
		Undo=disp;
		disp=t;

		// now the enhancement has to happen from 
		// Undo->disp
		try{
			PixelGrabber pg = new PixelGrabber(this.Undo,0,0,this.W,this.H,ipixels,0,this.W);
			pg.grabPixels();
		} catch (InterruptedException e) { };
		opixels=(int[])ipixels.clone();
		//this.enhancementInProgress=true;
		this.reads=0;
		this.writes=0;
		int[] ret={this.W,this.H};
		return ret;
	}

	// Computes the index from coordinate values.
	private int index(int x,int y){
		return (y*this.W)+x;
	}
	
	// Returns the RGB values of the pixel at x,y
	// x and y assumed to be in proper range.
	// returns an integer array of the form [R,G,B]
	// R,G,B in the range [0..255]
	// [0,0,0] : Black
	// [255,255,255] : White
	public int[] getRGB(int x,int y){
		int rgb=ipixels[index(x,y)];
		int r=((rgb>>16) & 0xff);
		int g=((rgb>>8) & 0xff);
		int b=((rgb) & 0xff);
		this.reads++;
		int[] ret={r,g,b};
		return ret;
	}

	// Writes an RGB value of the pixel at x,y
	// x and y assumed to be in proper range.
	// requires a byte array of the form [R,G,B]
	// R,G,B in the range [0..255]
	// [0,0,0] : Black
	// [255,255,255] : White
	public void writeRGB(int x,int y,int[] rgb){
		opixels[index(x,y)]=(0xff000000 | (rgb[0]<<16) | (rgb[1]<<8) | (rgb[2]));
		this.writes++;
	}
	
	// This method is to be called after completion of 
	// the enhancement routine to commit all changes.
	// accepts one int value (no. of operations performed on the image)
	public void stopProcess(int op){
		MemoryImageSource mi=new MemoryImageSource (this.W,this.H,opixels,0,this.W);
		this.disp = createImage(mi);
		repaint();
		hist.calc();
		hist = new HistCalculator(this,0);
		hist1 = new HistCalculator(this,1);
		hist2 = new HistCalculator(this,2);
		hist3 = new HistCalculator(this,3);
	}
	
	public HistCalculator dispGreyHist(){
		return hist;
	}
	
	public HistCalculator dispRedHist(){
		return hist1;
	}

	public HistCalculator dispGreenHist(){
		return hist2;
	}
	
	public HistCalculator dispBlueHist(){
		return hist3;
	}
}

