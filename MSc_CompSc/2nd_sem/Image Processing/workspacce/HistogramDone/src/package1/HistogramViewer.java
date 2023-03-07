package package1;

import java.awt.*;
import java.awt.image.*;

import javax.swing.*;

import java.io.*;
import java.awt.event.*;
import javax.imageio.ImageIO;

import java.util.LinkedList;
import java.awt.image.BufferedImage;

class HistogramViewer extends JFrame
{
    HistogramEqualizer histoEqual = new HistogramEqualizer();

    private File imageFile; // The image selected in the selectFileDialog

    private ImageComponent imageComponent = new ImageComponent();
    private HistogramComponent histogramComponent = new HistogramComponent();
    
    //Components
    private JButton loadFileButton;
    private JFrame selectFileDialog;
    private JFileChooser selector;

    //Containers
    private Container histogramContainer = new Container();
    private Container imageContainer = new Container();
    private Container buttonContainer = new Container();

    private int WINDOW_WIDTH = 800;
    private int WINDOW_HEIGHT = 600;

    public static void main(String[] args)
    {
    	
    	SwingUtilities.invokeLater(new Runnable()
    	{
            public void run()
            {
                new HistogramViewer().creatAndShowGUI();
            }

        });
       // new HistogramViewer().setVisible(true);
    }

    /** Init the components in the frame */
    public void creatAndShowGUI() 
    {
        Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
        Container contentPane = getContentPane();
        Rectangle bounds = new Rectangle((screenSize.width - WINDOW_WIDTH)/2,(screenSize.height - WINDOW_WIDTH)/2, WINDOW_WIDTH, WINDOW_HEIGHT);
        contentPane.setLayout(new BorderLayout());
        setBounds(bounds);
		//System.out.println(bounds);
	// initialize file selection dialog stuff
        selectFileDialog = new JFrame();
        selector = new JFileChooser();
        loadFileButton = new JButton();
        selector.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent evt) 
            {
                selectorActionPerformed(evt);
            }
        });
        selectFileDialog.getContentPane().add(selector, BorderLayout.CENTER);
        selectFileDialog.setBounds(bounds);

	// set app to die if main window is closed
        addWindowListener(new WindowAdapter() 
        {
            public void windowClosing(WindowEvent evt) 
            {
            	System.exit(0); 
           	}
        });
	
	// setup histogram graphs container
        histogramContainer.setLayout(new FlowLayout(FlowLayout.CENTER));
        histogramContainer.add(histogramComponent, null);
        contentPane.add(histogramContainer, BorderLayout.NORTH);

	// setup images container
        imageContainer.setLayout(new FlowLayout(FlowLayout.CENTER));
        imageContainer.add(imageComponent, null);
        contentPane.add(new JScrollPane(imageContainer), BorderLayout.CENTER);

	// setup load button
        loadFileButton.setText("Load");
        loadFileButton.addActionListener(new ActionListener() 
        {
            public void actionPerformed(ActionEvent evt) 
            {
                selectFileDialog.setVisible(true);
            }
        });
        buttonContainer.setLayout(new FlowLayout(FlowLayout.CENTER));
        buttonContainer.add(loadFileButton, null);
        contentPane.add(buttonContainer, BorderLayout.SOUTH);
        setVisible(true);
    }

    /** 
     * First draw the color image which has been selected, and then make a grey image
     * from the orginal image, and draw the grey image.
     */
    public void loadFile() throws IOException 
    {
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
        histogramComponent.setHistograms(histoEqual.getNewHistogram(), histoEqual.getOldHistogram());
        histogramComponent.repaint();
    }

    /**
     * Button in file selector is clicked, then load the selected image. 
     */
    private void selectorActionPerformed(ActionEvent evt) 
    {
        BufferedImage image;
        imageFile = selector.getSelectedFile();
	
        try
        {
            selectFileDialog.dispose();
            image = ImageIO.read(imageFile);
            histoEqual.setInputImage(image);
            
            SwingUtilities.invokeLater(new Runnable() 
            {
                public void run() 
                {
                	try
                	{
                		loadFile();
                	} 
                	catch (IOException e)
                	{
                		System.out.println(e.getMessage());
                	}
            
                }
            });
            
        } 
        catch (Exception e) 
        {
        	System.out.println(e.getMessage());
        }
    }
    
/*------------------------------------------------------------------------------------*/    
    /**
     * Component to show the original histogram and resulting histogram.
     */
    class HistogramComponent extends JComponent
    {
        private double[] oldHistogram; // Histogram of image before histogram-equalization
        private double[] newHistogram; // Histogram of image after histogram-equalization

        public HistogramComponent()
        {
            setPreferredSize(new Dimension(590, 150));
            revalidate();
        }

        public void setHistograms(double[] newHistogram, double[] oldHistogram)
        {
            this.oldHistogram = oldHistogram;
            this.newHistogram = newHistogram;
        }

        /**
         * Paint the histogram-equalized image and two histograms
         */
        public void paint(Graphics g) 
        {
            drawHistogram(g, "Old Histogram", 15, 5, 125, 1, oldHistogram);
            drawHistogram(g, "New Histogram", 320, 5, 125, 1, newHistogram);
        }

        /**
        * Draw the histogram picture of input histogram
        *
        *@param g  graphics object of current frame
        *       x  the x coordinate of histogram image to be showed
        *       y  the x coordinate of histogram image to be showed
        *       height the height of the histogram image
        *       space  the space between two lines in the histogram.
        */
        public void drawHistogram(Graphics g, String title, int x, int y, int height, int space, double[] inputHistogram) 
        {
            double max = 0;
            if (inputHistogram != null)
            {
                for (int j = 0; j < 256; j++)
                {
                    if (inputHistogram[j] > max)
                        max = inputHistogram[j];
                }
            }

            // set up font
            g.setFont(new Font("Arial", Font.PLAIN, 11));
            FontMetrics	fm = g.getFontMetrics();
            int	ascent = fm.getAscent();
            int	lineHeight = fm.getHeight();

            // draw title
            int titleWidth = fm.stringWidth(title);
            g.setColor(Color.black);
            g.drawString(title, x + (256*space - titleWidth)/2, y + ascent);
            y += lineHeight;
            height -= lineHeight;

            // draw background
            Rectangle	histRect = new Rectangle(x, y, 256*space, height);
            g.setColor(Color.WHITE);
            g.fillRect(histRect.x, histRect.y, histRect.width, histRect.height);

            // draw bars
            g.setColor(Color.darkGray);
            if (inputHistogram != null)
            {
                for (int i = 0; i < 256; i++)
                    g.drawLine(x + ((i + 1) * space), y + height, x + ((i + 1) * space), y + height - (int) (height * inputHistogram[i] / max));
            }

            // draw vertical label
            String	vLabel = "" + ((double) (int) (max * 1000) / 10) + "%";
            g.setColor(Color.red);
            g.drawString(vLabel, x + 2, y + ascent);

            // draw horizontal labels
            g.setColor(Color.black);
            g.drawString("256", (x + (space * 256)) - 8, y + height + ascent + 2);
            g.drawString("128", (x + (space * 128)) - 8, y + height + ascent + 2);
            g.drawString("  0", (x + (space *   0)) - 8, y + height + ascent + 2);
        }
    }
    
/*------------------------------------------------------------------------------------*/  
    public class HistogramEqualizer 
    {
        private BufferedImage inputImage; //image object of input image
        private BufferedImage newImage; //image after histogram equalization
        private BufferedImage greyImage; //grey image of input image

        private short[][] red; // array of red which is extracted from the image data
        private short[][] green; // array of green which is extracted from the image data
        private short[][] blue; // array of blue which is extracted from the image data

        private int[] inputImageData; // data array of input image
        private short[][] greyImageData; // data array of the image after being greyed
        private short[][] equalizedImageData; // data array after histogram equalization
        
        private double[] oldHistogram = new double[256]; // normalized histogram of grey image
        private double[] newHistogram = new double[256]; // normalized histogram of equalized image
        private double[] equalizedHistogram = new double[256]; // equalized histogram of equalized image

        private int rows; // image height
        private int cols; // image width

        /** 
         * Get RGB inputImageData from image and change them into
         * three color arrays, red, green, and blue.
         */
        public void loadRGBArrays() 
        {
            // check if we need to resize the component arrays, i.e.,
            // has the size of the image changed?
            if (inputImage.getHeight() != rows || inputImage.getWidth() != cols)
            {
                rows = inputImage.getHeight();
                cols = inputImage.getWidth();
                
                red   = new short[rows][cols];
                green = new short[rows][cols];
                blue  = new short[rows][cols];
            }

            // get pixels as ints of the form 0xRRGGBB
            inputImageData = inputImage.getRGB(0, 0, inputImage.getWidth(), inputImage.getHeight(), null, 0, inputImage.getWidth());
            
            // extract red, green, and blue components from each pixel
            int index;
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    index = (row * cols) + col;
                    unpackPixel(inputImageData[index], red, green, blue, row, col);
                }
            }
        }

        /** Make out a grey image "greyImageData" from original image. */
        public void makeGreyImage()
        {
            greyImageData = new short[rows][cols];

            for (int row = 0; row < rows; row++) 
            {
                for (int col = 0; col < cols; col++) 
                {
                    // grey value is average of red, green, and blue components, i.e.,
                    // grey = (red + green + blue) / 3
                    greyImageData[row][col] = (short)((  red[row][col]+ green[row][col] + blue[row][col]) / 3);
                }
            }
    	
            greyImage = greyToBufferedImage(greyImageData);
        }

        /** 
         * This method can convert array of short inputImageDatatype into a BufferedImage.
         * After being converted into type of BufferedImage, the image can be showed on
         * GUI.
         * @return a object of BufferedImage which is coverted from the input grey image data array
         * @param inputGreyImageData The short[][] of grey image data
         */
        public BufferedImage greyToBufferedImage(short[][] inputGreyImageData) 
        {
            int[] greyBufferedImageData = new int[rows * cols];
            int index;
            for (int row = 0; row < rows; row++)
            {
                for (int col = 0; col < cols; col++)
                {
                    index = (row * cols) + col;
                    greyBufferedImageData[index] = packPixel(inputGreyImageData[row][col],inputGreyImageData[row][col], inputGreyImageData[row][col]);
                }
            }

            BufferedImage greyImage = new BufferedImage(cols, rows, BufferedImage.TYPE_INT_RGB);
            greyImage.setRGB(0, 0, cols, rows, greyBufferedImageData, 0, cols);

            return greyImage;
        }

        // performEqualization takes the greyImageData and creates
        // the old and new histograms and the new image
        public void performEqualization() 
        {
        	createHistograms(greyImageData, oldHistogram, equalizedHistogram);
            equalizedImageData = equalizeImage(greyImageData, equalizedHistogram);
            createHistograms(equalizedImageData, newHistogram, null);
            newImage = greyToBufferedImage(equalizedImageData);
        }

        /** 
         * Return the image data after histogram-equalization.
         * This method applies the algorithm of histogram-equalization
         * on the input image data.
         * @return the image data histogram-equalized
         * @param inputGreyImageData input grey image data need to be histogram-equalized
         * @param equalizedHistogram equalized histogram of inputGreyImageData
         */
        public short[][] equalizeImage(short[][] inputGreyImageData, double[] equalizedHistogram)
        {
            short[][] data = new short[rows][cols];

            double	s = 0;
            for (int y = 0; y < rows; y++)
            {
                for (int x = 0; x < cols; x++)
                {
                    //s += normalizedHistogram[inputGreyImageData[y][x]];
                    data[y][x] = (short) (equalizedHistogram[inputGreyImageData[y][x]] * 255);
                }
            }
            
            return data;
        }

        /* 
         * Create normalized and equalized histograms of inputGreyImageData
         * @param inputGreyImageData a grey image data
         * @param normalizedHistogram used to return normalized histogram
         * @param equalizedHistogram used to return equalized histogram
         */
        public void createHistograms(short[][] inputGreyImageData,double[] normalizedHistogram, double[] equalizedHistogram) 
        {
            int[] histogram = new int[256];

            // count the number of occurences of each color
            for (int y = 0; y < rows; y++) 
            {
                for (int x = 0; x < cols; x++) 
                {
                    ++histogram[inputGreyImageData[y][x]];
                }
            }

            // normalize and equalize the histogram array
            double sum = 0;
            for (int v = 0; v < 256; v++)
            {
                if (normalizedHistogram != null)
                {
                    normalizedHistogram[v] = (double) histogram[v] / (cols * rows);
                }
                if (equalizedHistogram != null)
                {
                    sum += histogram[v];
                    equalizedHistogram[v] = sum / (cols * rows);
                }
            }
        }

        // packPixel takes the red, green, and blue components
        // of a color and returns a 24-bit representation of the
        // the color, i.e., 0xRRGGBB
        // red, green, and blue are assumed to be in the range 0 - 255
        private int packPixel(int red, int green, int blue)
        {
            return (red << 16) | (green << 8) | blue;
        }
        
        // unpackPixel does the opposite of packPixel;
        // it takes a 24-bit pixel in the form 0xRRGGBB
        // and pulls out the three components, storing
        // them position (row, col) or the red, green,
        // and blue arrays
        private void unpackPixel(int pixel, short [][] red, short [][] green, short [][] blue, int row, int col) 
        {
            red[row][col]   = (short)((pixel >> 16) & 0xFF);
            green[row][col] = (short)((pixel >>  8) & 0xFF);
            blue[row][col]  = (short)((pixel >>  0) & 0xFF);
        }

        //****************************//
        // Various Accessor Functions //
        //****************************//

        public BufferedImage getInputImage() 
        {
        	return inputImage; 
        }
        public BufferedImage getGreyImage() 
        {
        	return greyImage; 
        }
        public BufferedImage getEqualizedImage() 
        {
        	return newImage; 
        }
        public double [] getOldHistogram()
        {
        	return oldHistogram; 
        }
        public double [] getNewHistogram() 
        {
        	return newHistogram; 
        }

        public void setInputImage(BufferedImage image)
        {
        	inputImage = image; 
        }
    }

/*------------------------------------------------------------------------------------*/
    /**
     * Component to show images
     */
    class ImageComponent extends JComponent
    {
        private LinkedList imageList = new LinkedList();
        private LinkedList rectList = new LinkedList();

        private static final int PADDING = 5;

        public ImageComponent()
        {
        	
        }

        public void addImage(BufferedImage image) 
        {
            if (image == null)
                return;
            
            // add image to list
            imageList.add(image);
            rectList.add(new Rectangle(0, 0, image.getWidth(), image.getHeight()));

            // update scroll bar
            resizeScroller();
        }

        public void clearImages() 
        {
            // clear lists
            imageList.clear();
            rectList.clear();

            // update scroll bar
            resizeScroller();
        }
        
        // assuming we're inside a scrollbar view,
        // resizeScroller updates our preferred size
        // and tells the view to revalidate its bars
        private void resizeScroller() 
        {
            Rectangle	bounds = new Rectangle(0, 0, 0, 0);

            // calculate bounds of images
            for (int i = 0; i < imageList.size(); ++i) 
            {
                Rectangle	rect = (Rectangle)rectList.get(i);
                bounds.height = Math.max(bounds.height, rect.height);
                bounds.width += rect.width;
            }
            bounds.width += PADDING * (imageList.size() + 1);
            bounds.height += 2*PADDING;

            setPreferredSize(bounds.getSize());
            revalidate();
        }

        // paint the images
        public void paint(Graphics g) 
        {
            int offset = PADDING;
            for (int i = 0; i < imageList.size(); ++i) 
            {
                g.drawImage((BufferedImage)imageList.get(i), offset, PADDING, null);
                offset += PADDING + ((Rectangle)rectList.get(i)).width;
            }
        }
    }

}