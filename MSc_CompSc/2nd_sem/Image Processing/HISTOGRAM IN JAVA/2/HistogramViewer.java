import java.awt.*;
import java.awt.image.*;
import javax.swing.*;
import java.io.*;
import javax.imageio.ImageIO;

class HistogramViewer extends javax.swing.JFrame {
    HistogramEqualizer histoEqual = new HistogramEqualizer();

    private File imageFile; // The image selected in the selectFileDialog

    private ImageComponent imageComponent = new ImageComponent();
    private HistogramComponent histogramComponent = new HistogramComponent();
    
    private javax.swing.JButton loadFileButton;
    private javax.swing.JFrame selectFileDialog;
    private javax.swing.JFileChooser selector;

    private java.awt.Container	histogramContainer = new Container();
    private java.awt.Container	imageContainer = new Container();
    private java.awt.Container	buttonContainer = new Container();

    private final int	WINDOW_WIDTH = 590;
    private final int	WINDOW_HEIGHT = 400;

    public static void main(String[] args) {
    	
    	javax.swing.SwingUtilities.invokeLater(new Runnable() {
            public void run() {
                new HistogramViewer().creatAndShowGUI();
            }

        });
       // new HistogramViewer().setVisible(true);
    }

    /** Init the components in the frame */
    public void creatAndShowGUI() {
        Dimension screenSize = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
	Container contentPane = getContentPane();
	Rectangle bounds = new Rectangle((screenSize.width - WINDOW_WIDTH)/2,
					 (screenSize.height - WINDOW_WIDTH)/2,
					 WINDOW_WIDTH, WINDOW_HEIGHT);
	contentPane.setLayout(new java.awt.BorderLayout());
	setBounds(bounds);
		
	// initialize file selection dialog stuff
        selectFileDialog = new javax.swing.JFrame();
        selector = new javax.swing.JFileChooser();
        loadFileButton = new javax.swing.JButton();
        selector.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                selectorActionPerformed(evt);
            }
        });
        selectFileDialog.getContentPane().add(selector, java.awt.BorderLayout.CENTER);
	selectFileDialog.setBounds(bounds);

	// set app to die if main window is closed
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) { System.exit(0); }
        });
	
	// setup histogram graphs container
        histogramContainer.setLayout(new java.awt.FlowLayout(java.awt.FlowLayout.CENTER));
        histogramContainer.add(histogramComponent, null);
        contentPane.add(histogramContainer, java.awt.BorderLayout.NORTH);

	// setup images container
        imageContainer.setLayout(new java.awt.FlowLayout(java.awt.FlowLayout.CENTER));
        imageContainer.add(imageComponent, null);
        contentPane.add(new JScrollPane(imageContainer), java.awt.BorderLayout.CENTER);

	// setup load button
        loadFileButton.setText("Load");
        loadFileButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                selectFileDialog.setVisible(true);
            }
        });
        buttonContainer.setLayout(new java.awt.FlowLayout(java.awt.FlowLayout.CENTER));
        buttonContainer.add(loadFileButton, null);
        contentPane.add(buttonContainer, java.awt.BorderLayout.SOUTH);
        setVisible(true);
    }

    /** 
     * First draw the color image which has been selected, and then make a grey image
     * from the orginal image, and draw the grey image.
     */
    public void loadFile() throws IOException {
        // load image and make greyscale version
        histoEqual.loadRGBArrays(); //get RGB data from original image
        histoEqual.makeGreyImage(); //make out a grey image from original image

        // apply histogram-equalization
        histoEqual.performEqualization();

        // update the imageComponent
        imageComponent.clearImages();
        imageComponent.addImage(histoEqual.getInputImage());
        imageComponent.addImage(histoEqual.getGreyImage());
        imageComponent.addImage(histoEqual.getEqualizedImage());
        imageComponent.repaint();
        
        // update the histogramComponent
        histogramComponent.setHistograms(histoEqual.getNewHistogram(),
					 histoEqual.getOldHistogram());
        histogramComponent.repaint();
    }

    /**
     * Button in file selector is clicked, then load the selected image. 
     */
    private void selectorActionPerformed(java.awt.event.ActionEvent evt) {
        BufferedImage image;
        imageFile = selector.getSelectedFile();
	
        try {
            selectFileDialog.dispose();
            image = ImageIO.read(imageFile);
            histoEqual.setInputImage(image);
            
            javax.swing.SwingUtilities.invokeLater(new Runnable() {
                public void run() {
                	try{
                		loadFile();
                	} catch (IOException e){
                		System.out.println(e.getMessage());
                	}
            
                }
            });
            
        } catch (Exception e) {
	    System.out.println(e.getMessage());
	}
    }
}
