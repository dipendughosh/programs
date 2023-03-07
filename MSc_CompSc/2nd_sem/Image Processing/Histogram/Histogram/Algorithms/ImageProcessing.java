package Algorithms;

/**
 	*************************************************************************************
	* File: ImageProcessing.java           Date: 21/11/2004	      Version: 1.01 		*
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
	*	  ONLY IF the source will not be used 
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
*/

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import Viewer.OpenImage;
import Viewer.Bitmap;
import Viewer.RGBEncoder;

public class ImageProcessing extends JPanel{
	
	HistManager hisMan;
	ContrastFunction conFun;
    int r1=85,c1=85,r2=170,c2=170;
	
	private JTabbedPane srcTabPane, trgTabPane, srcTab, trgTab;
	private JPanel picPane, jpOrginalIm, jpControl, hisPane, hisGreyscale, 
                    hisRed, hisGreen, hisBlue, contrastPane;

	public Insets getInsets(){
		return new Insets(3,3,3,3);
	}
	
	public ImageProcessing(HistManager hisMan){
		
	this.hisMan = hisMan;
		
	try{
		UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
	}catch(Exception e){}
	
    this.setLayout(new BorderLayout());

	picPane = new JPanel();
	picPane.setLayout(new FlowLayout());	
	srcTabPane = SourceType();
	picPane.add(srcTabPane);
	trgTabPane = TargetType();
	picPane.add(trgTabPane);
	this.add(picPane, BorderLayout.CENTER);

  }

	protected JTabbedPane SourceType(){

	    srcTab = new JTabbedPane(SwingConstants.TOP);
		srcTab.setPreferredSize(new Dimension(220, 310));//old 250
		jpOrginalIm = new JPanel();
	    srcTab.addTab("Image", null, jpOrginalIm, "This is an original image");
		return (srcTab);
    }

	protected JTabbedPane TargetType(){

	    trgTab = new JTabbedPane(SwingConstants.TOP);
		trgTab.setPreferredSize(new Dimension(290, 310));

		hisGreyscale = new JPanel();
		hisRed = new JPanel();
		hisGreen = new JPanel();
		hisBlue = new JPanel();
        
    	trgTab.addTab("Grayscale", null, hisGreyscale, "");
    	trgTab.addTab("Red", null, hisRed, "");
    	trgTab.addTab("Green", null, hisGreen, "");
        trgTab.addTab("Blue", null, hisBlue, "");
	 	 
		return (trgTab);

	}
    
   	public  void displayHistogram(){
		
			// Hien Histogram
	        JPanel myPn0 = new JPanel(new GridLayout(1,0));
		    myPn0.setPreferredSize(new Dimension(280, 200));
	 	    myPn0.add(hisMan.dispGreyHist());
			
	        JPanel myPn1 = new JPanel(new GridLayout(1,0));
		    myPn1.setPreferredSize(new Dimension(280, 200));
	 	    myPn1.add(hisMan.dispRedHist());
			
	        JPanel myPn2 = new JPanel(new GridLayout(1,0));
		    myPn2.setPreferredSize(new Dimension(280, 200));
	 	    myPn2.add(hisMan.dispGreenHist());
			
	        JPanel myPn3 = new JPanel(new GridLayout(1,0));
		    myPn3.setPreferredSize(new Dimension(280, 200));
	 	    myPn3.add(hisMan.dispBlueHist());
			
            hisGreyscale.add(myPn0);
			hisGreyscale.setPreferredSize(new Dimension(280, 200));//330 310

			hisRed.add(myPn1);
			hisRed.setPreferredSize(new Dimension(280, 200));//330 310
			
			hisGreen.add(myPn2);
			hisGreen.setPreferredSize(new Dimension(280, 200));//330 310
			
			hisBlue.add(myPn3);
			hisBlue.setPreferredSize(new Dimension(280, 200));//330 310
	}

   	public  void displayImage(){
		
			jpOrginalIm.removeAll();
			hisMan.setPreferredSize(new Dimension(210, 320));
			jpOrginalIm.add(hisMan);
	}
    
    public  void displayConFun(){
        conFun = new ContrastFunction(r1,c1,r2,c2);
        JPanel myPn4 = new JPanel(new GridLayout(1,0));
        myPn4.setPreferredSize(new Dimension(280, 280));
        myPn4.add(conFun);
        contrastPane.add(myPn4);
    }
    
	public void grayscale(){
		int[] D=hisMan.startProcess();
		int X=D[0];
		int Y=D[1];
		int x,y;
		int[] RGB=new int[3];
		int t;
		int op=0;

		for (y=0;y<Y;y++){
			for (x=0;x<X;x++){
				RGB=hisMan.getRGB(x,y);
                // grayscale = maximise of red, green and blue
                t=Math.max(RGB[0],Math.max(RGB[1],RGB[2]));
                
                // grayscale = squareroot of red*red + green*green + blue*blue
                //t=RGB[0]*RGB[0]+RGB[1]*RGB[1]+RGB[2]*RGB[2];
                //t=(int)(Math.sqrt(t/3));
                
                RGB[0]=t;
				RGB[1]=t;
				RGB[2]=t;
				hisMan.writeRGB(x,y,RGB);
				op=op+6;
			}
		}
		hisMan.stopProcess(op);
	}
	
	public void histEqualisation(){
		int[] D=hisMan.startProcess();
		int X=D[0];
		int Y=D[1];
		int XxY=X*Y;
		int x,y;
		int[] RGB=new int[3];
		int op=0;
		float[] T=new float[256];	// Spatial transform function.
		int t,i;


		int[] I=new int[256];	// frequencies.
		
		for (x=0;x<256 ;x++ ){
			I[x]=0;
		}
		op=op+256;

		// Compute T	
		for (y=0;y<Y;y++){
			for (x=0;x<X;x++){
				RGB=hisMan.getRGB(x,y);
				I[RGB[0]]++;
				op=op+1;
			}
		}
		
		T[0]=(float)I[0]/(float)XxY;
		t=I[0];
		for (x=1;x<256 ;x++ ){   
			t=t+I[x];
			T[x]=((float)t/(float)XxY)*255;
		}

		op=op+256;

		// Now apply T on image.
		for (y=0;y<Y;y++){
			for (x=0;x<X;x++){
				RGB=hisMan.getRGB(x,y);
				
				RGB[0]=(int)T[RGB[0]];
				RGB[1]=(int)T[RGB[1]];
				RGB[2]=(int)T[RGB[2]];
				hisMan.writeRGB(x,y,RGB);
				op=op+1;
			}
		}
		hisMan.stopProcess(op);
	}

	public void negative(){
		int[] D=hisMan.startProcess();
		int X=D[0];
		int Y=D[1];
		int x,y;
		int[] RGB=new int[3];
		int op=0;

		for (y=0;y<Y;y++){
			for (x=0;x<X;x++){
				RGB=hisMan.getRGB(x,y);
                
                RGB[0]=255-RGB[0];
				RGB[1]=255-RGB[1];
				RGB[2]=255-RGB[2];
				hisMan.writeRGB(x,y,RGB);
				op=op+3;
			}
		}
		hisMan.stopProcess(op);
	}
	
	public void channelBoost(float rb,float gb,float bb){
		int[] D=hisMan.startProcess();
		int X=D[0];
		int Y=D[1];
		int x,y;
		int[] RGB=new int[3];
		int op=0;
			
		for (y=0;y<Y;y++){
			for (x=0;x<X;x++){
				RGB=hisMan.getRGB(x,y);
				
				RGB[0]=(int)((float)RGB[0]*rb);
				RGB[1]=(int)((float)RGB[1]*gb);
				RGB[2]=(int)((float)RGB[2]*bb);
                
				if (RGB[0]>255) RGB[0]=255;
				if (RGB[1]>255) RGB[1]=255;
				if (RGB[2]>255) RGB[2]=255;
                
				hisMan.writeRGB(x,y,RGB);
				op=op+3;
			}
		}
		hisMan.stopProcess(op);
	}
	
	public void channelBoost(){
		
		String strRed, strGreen, strBlue;
		float rb=1,gb=1,bb=1;

		Object objRed = JOptionPane.showInputDialog(this, "Please enter % of RED color", "RED channel",
			JOptionPane.QUESTION_MESSAGE, null, null, "100");
		Object objGreen = JOptionPane.showInputDialog(this, "Please enter % of GREEN color", "GREEN channel",
			JOptionPane.QUESTION_MESSAGE, null, null, "100");
		Object objBlue = JOptionPane.showInputDialog(this, "Please enter % of BLUE color", "BLUE channel",
			JOptionPane.QUESTION_MESSAGE, null, null, "100");
		
		//Get the result . . .
		if (objRed != null && objGreen != null && objBlue != null){
			strRed = (String)objRed;
			strGreen = (String)objGreen;
			strBlue = (String)objBlue;
			rb=(float)(Integer.parseInt(strRed))/(float)100;
			gb=(float)(Integer.parseInt(strGreen))/(float)100;
			bb=(float)(Integer.parseInt(strBlue))/(float)100;
			if (rb>1) rb=1;
			if (gb>1) gb=1;
			if (bb>1) bb=1;
		}	
		channelBoost(rb,gb,bb);
	}
	
	public void contrast(int r1,int s1,int r2,int s2){
		int[] D=hisMan.startProcess();
		int X=D[0];
		int Y=D[1];
		int x,y;
		int[] RGB=new int[3];
		int op=0;
		int [] T=new int[256];	// Spatial transform function.
		int r;
		float m;

		// check weather parameters are valid.
		if (!((r1<=r2)&(s1<=s2))){
			hisMan.stopProcess(op);
			return;
		}

		// Compute T	
		for (r=0;r<r1;r++){
			m=(float)s1/(float)r1;
			T[r]=(int)((float)r*m);
		}
		for (r=r1;r<r2;r++){
			m=(float)(s2-s1)/(float)(r2-r1);
			T[r]=(int)((float)(r-r1)*m)+s1;
		}
		for (r=r2;r<=255;r++){
			m=(float)(255-s2)/(float)(255-r2);
			T[r]=(int)((float)(r-r2)*m)+s2;
		}
		op=op+256;
		
		// Now apply T on image.
		for (y=0;y<Y;y++){
			for (x=0;x<X;x++){
				RGB=hisMan.getRGB(x,y);
				
				RGB[0]=T[RGB[0]];
				RGB[1]=T[RGB[1]];
				RGB[2]=T[RGB[2]];
				hisMan.writeRGB(x,y,RGB);
				op=op+1;
			}
		}
		hisMan.stopProcess(op);
	}

public void contrast(){
		
        contrastPane = new JPanel();
        trgTab.addTab("Contrast Graph", null, contrastPane, "");

        String strRow1, strRow2, strCol1, strCol2;
        int rw1=85,cl1=85,rw2=170,cl2=170;

		Object objRw1 = JOptionPane.showInputDialog(this, "Please enter X1 value", "X1",
			JOptionPane.QUESTION_MESSAGE, null, null, "85");
		Object objCl1 = JOptionPane.showInputDialog(this, "Please enter Y1 value", "Y1",
			JOptionPane.QUESTION_MESSAGE, null, null, "85");
        Object objRw2 = JOptionPane.showInputDialog(this, "Please enter X2 value", "X2",
            JOptionPane.QUESTION_MESSAGE, null, null, "170");
        Object objCl2 = JOptionPane.showInputDialog(this, "Please enter Y2 value", "Y2",
			JOptionPane.QUESTION_MESSAGE, null, null, "170");
		
		//Get the result . . .
		if (objRw1 != null && objRw2 != null && objCl1 != null && objCl2 != null){
			strRow1 = (String)objRw1;
			strRow2 = (String)objRw2;
			strCol1 = (String)objCl1;
			strCol2 = (String)objCl2;
			rw1=Integer.parseInt(strRow1);
			rw2=Integer.parseInt(strRow2);
			cl1=Integer.parseInt(strCol1);
			cl2=Integer.parseInt(strCol2);
		}
        this.r1=rw1;
        this.c1=cl1;
        this.r2=rw2;
        this.c2=cl2;
        contrast(r1,c1,r2,c2);
	}	
}


