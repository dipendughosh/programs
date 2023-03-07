/**
 	*************************************************************************************
	* File: ImageGUI.java                Date: 17/11/2004		      Version: 1.0 		*
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
    * Please send comments, bug reports, improvements to: hoptrandinh@yahoo.com  
    *
    * @Author Tran Dinh Hop, 6 Nov 2004
    * @Please visit http://www.freewebs.com/DigitZone for updated version
*/

import java.awt.*;
import java.awt.event.*;
import java.io.File;

import javax.swing.*;
import javax.swing.event.*;

import Utils.*;
import Viewer.*;
import Algorithms.*;

public class ImageGUI extends JFrame implements ActionListener{

	private JDesktopPane desktopPane;
	private JLabel statusBar;
	private JButton[] buttons;
	private JToolBar toolBar;
	private JInternalFrame inframe;
	private JDialog hDialog;
    private HistManager hisMan;
    private String imageFile = "";

	public ImageGUI(){
		try{
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		}catch(Exception e){}
		
		this.setTitle("IMAGE HISTOGRAM PROJECT");
	  	this.getContentPane().setLayout(new BorderLayout());
		this.getContentPane().add(getToolBar(), BorderLayout.PAGE_START);
        
        JMenuBar menuBar = new JMenuBar();
        JMenu help = new JMenu("Help"); 
        menuBar.add(fileMenu());
        menuBar.add(editMenu());
        menuBar.add(histMenu());
        menuBar.add(help);
		this.setJMenuBar(menuBar) ;

	 	desktopPane = new JDesktopPane();
		desktopPane.setDragMode(JDesktopPane.LIVE_DRAG_MODE);
		desktopPane.setBackground(new Color (0,153,153));
		this.getContentPane().add(desktopPane, BorderLayout.CENTER);
		
		statusBar = new JLabel("Ready");
	 	statusBar.setPreferredSize(new Dimension(800, 17));
		this.getContentPane().add(statusBar, BorderLayout.PAGE_END);
		
		this.pack();
		this.setSize(800,570);
		this.setVisible(true);
		this.setResizable(false);
	}
	
     private JMenu fileMenu(){
     	 JMenu file = new JMenu("File");
         file.setMnemonic(KeyEvent.VK_F);

		 //-----------------
		 JMenuItem open = new JMenuItem("Open Image", KeyEvent.VK_O);
				
         file.add(open);
         open.addActionListener(this);
					
			//-----------------
         JMenuItem save = new JMenuItem("Save Image", KeyEvent.VK_S);
         file.add(save);
         save.addActionListener(this);
         file.addSeparator();

			//-----------------
         JMenuItem quit = new JMenuItem("Quit", KeyEvent.VK_Q);
         file.add(quit);
         quit.addActionListener(this);
         return file;
      }

     private JMenu editMenu(){
         JMenu edit = new JMenu("Edit");
         edit.setMnemonic(KeyEvent.VK_E);

            //-----------------
         JMenuItem undo = new JMenuItem("Undo", KeyEvent.VK_U);
         //undo.disable();   
         edit.add(undo);
         undo.addActionListener(this);

            //-----------------
         JMenuItem revert = new JMenuItem("Revert", KeyEvent.VK_R);
         revert.disable();   
         edit.add(revert);
         revert.addActionListener(this);
         edit.addSeparator();

            //-----------------
         JMenuItem changeBG = new JMenuItem("Background", KeyEvent.VK_B);
         edit.add(changeBG);
         changeBG.addActionListener(this);
            
         return edit;
      }

	 private JMenu histMenu(){
         JMenu mnHist = new JMenu("Histogram");
         mnHist.setMnemonic(KeyEvent.VK_H);

        JMenuItem histOrg = new JMenuItem("Original Histogram", KeyEvent.VK_O);
         mnHist.add(histOrg);
         histOrg.addActionListener(this);
			
        JMenuItem histEqual = new JMenuItem("Histogram Equalisation", KeyEvent.VK_E);
         mnHist.add(histEqual);
         histEqual.addActionListener(this);

        JMenuItem histCons = new JMenuItem("Contrast Stretch", KeyEvent.VK_C);
         mnHist.add(histCons);
         histCons.addActionListener(this);
			
         mnHist.addSeparator(); // add ------
			
        JMenuItem histGray = new JMenuItem("Grayscale Model", KeyEvent.VK_G);
         mnHist.add(histGray);
         histGray.addActionListener(this);
            
        JMenuItem histNeg = new JMenuItem("Negative Model", KeyEvent.VK_N);
         mnHist.add(histNeg);
         histNeg.addActionListener(this);

			
	    JMenuItem histBoost = new JMenuItem("Channel Boost Model", KeyEvent.VK_B);
         mnHist.add(histBoost);
         histBoost.addActionListener(this);
	
         return mnHist;
      }

      public JToolBar getToolBar(){
         toolBar = new JToolBar();
			toolBar.setFloatable(false);
				 JLabel lb = new JLabel(" ");
				 String[] iconFiles = {"icons\\open.gif","icons\\undo.gif","icons\\revert.gif","icons\\histo.gif",
				                       "icons\\histo.gif","icons\\histo.gif","icons\\histo.gif",
                                       "icons\\histo.gif","icons\\histo.gif"};
				 String[] buttonLabels = {"Open","Undo","Revert","Original Histogram","Histogram Equalisation","Contrast Stretch",
                                          "Grayscale Model","Negative Model","Channel Boost Model"};
                                          
				
				 ImageIcon[] icons = new ImageIcon[iconFiles.length];
				 buttons = new JButton[buttonLabels.length];
				
			   for(int i=0;i<buttonLabels.length;++i) {
				   icons[i] = new ImageIcon(iconFiles[i]);
				   buttons[i] = new JButton(icons[i]);
                   buttons[i].setToolTipText(buttonLabels[i]);
			       buttons[i].addActionListener(this);
				   if(i==1||i==3) toolBar.addSeparator();
				   toolBar.add(buttons[i]);
				}
         return toolBar;
      }

      public void actionPerformed(ActionEvent e){
         String pressed = e.getActionCommand();
            
         if(pressed.equals("Quit")){
            System.exit(1);
         }
        else if(pressed.equals("Background")){
             Color newBg = JColorChooser.showDialog(this,
                               "Choose Background Colour", getBackground());
             if(newBg != null){
                desktopPane.setBackground(newBg);
                }         
        }
         else if(pressed.equals("Open Image")||e.getSource()==(Object)buttons[0]){
			
				FileChooser fc = new FileChooser("image", "Open");
				String orgImage = fc.getFileName();
				OpenImage oi = new OpenImage(orgImage);
				
				RGBEncoder je = new RGBEncoder(orgImage);
				String intensityImage = je.getOutFileName();
				hisMan = new HistManager(intensityImage);

				inframe=new JInternalFrame("Open Image",true,true,true,true);
				inframe.setTitle(oi.getImageName());	
				inframe.getContentPane().add(oi);
				inframe.setSize(new Dimension(240,360));
				inframe.setLocation(550,33);
				inframe.setVisible(true);
				desktopPane.add(inframe);
         }
			
        else if(pressed.equals("Undo")||e.getSource()==(Object)buttons[1]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.undo();
            }
			}	
        else if(pressed.equals("Revert")||e.getSource()==(Object)buttons[2]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.revert();
            }
      }
        else if(pressed.equals("Original Histogram")||e.getSource()==(Object)buttons[3]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.revert();
                ImageProcessing _hJDialog = new ImageProcessing(hisMan);
                _hJDialog.displayImage();
                _hJDialog.displayHistogram();
        
					 hDialog = new JDialog(this, "Original Histogram", true);
					 hDialog.getContentPane().add(_hJDialog);
					 hDialog.setSize(new Dimension(550,360));
					 hDialog.setLocation(4,111);
					 hDialog.setVisible(true); 
            }
      }
        else if(pressed.equals("Histogram Equalisation")||e.getSource()==(Object)buttons[4]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.revert();
                ImageProcessing _hJDialog = new ImageProcessing(hisMan);
                _hJDialog.histEqualisation();
                _hJDialog.displayImage();
                _hJDialog.displayHistogram();
       
 					 hDialog = new JDialog(this, "Histogram Equalisation", true);
					 hDialog.getContentPane().add(_hJDialog);
					 hDialog.setSize(new Dimension(550,360));
					 hDialog.setLocation(4,111);
					 hDialog.setVisible(true); 
            }
      }
        else if(pressed.equals("Contrast Stretch")||e.getSource()==(Object)buttons[5]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.revert();
                
                ImageProcessing _hJDialog = new ImageProcessing(hisMan);
                _hJDialog.contrast();
                _hJDialog.displayImage();
                _hJDialog.displayHistogram();
                _hJDialog.displayConFun();
       
                     hDialog = new JDialog(this, "Contrast Stretch", true);
					 hDialog.getContentPane().add(_hJDialog);
					 hDialog.setSize(new Dimension(550,360));
					 hDialog.setLocation(4,111);
					 hDialog.setVisible(true); 
            }
      }
        else if(pressed.equals("Grayscale Model")||e.getSource()==(Object)buttons[6]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.revert();
                ImageProcessing _hJDialog = new ImageProcessing(hisMan);
                _hJDialog.grayscale();
                _hJDialog.displayImage();
                _hJDialog.displayHistogram();
        
					 hDialog = new JDialog(this, "Grayscale Model", true);
					 hDialog.getContentPane().add(_hJDialog);
					 hDialog.setSize(new Dimension(550,360));
					 hDialog.setLocation(4,111);
					 hDialog.setVisible(true); 
            }
      }
        else if(pressed.equals("Negative Model")||e.getSource()==(Object)buttons[7]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.revert();
                ImageProcessing _hJDialog = new ImageProcessing(hisMan);
                _hJDialog.negative();
                _hJDialog.displayImage();
                _hJDialog.displayHistogram();
       
 					 hDialog = new JDialog(this, "Negative Model", true);
					 hDialog.getContentPane().add(_hJDialog);
					 hDialog.setSize(new Dimension(550,360));
					 hDialog.setLocation(4,111);
					 hDialog.setVisible(true); 
            }
      }
        else if(pressed.equals("Channel Boost Model")||e.getSource()==(Object)buttons[8]){
            if (hisMan==null){
                String title = "Warning";
                String message ="\nYou must open an image for processing\n\n";
                JOptionPane.showMessageDialog(this,message, title,
                                         JOptionPane.INFORMATION_MESSAGE);
            }
            else{
                hisMan.revert();
                ImageProcessing _hJDialog = new ImageProcessing(hisMan);
                _hJDialog.channelBoost();
                _hJDialog.displayImage();
                _hJDialog.displayHistogram();
       
 					 hDialog = new JDialog(this, "Channel Boost Model", true);
					 hDialog.getContentPane().add(_hJDialog);
					 hDialog.setSize(new Dimension(550,360));
					 hDialog.setLocation(4,111);
					 hDialog.setVisible(true); 
            }
      }

   }

	public static void main(String[] args){
		new ImageGUI();
	}

}

