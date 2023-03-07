package package1;

import java.awt.*;
import java.io.*;

import javax.swing.*;

import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import javax.imageio.ImageIO;
import javax.swing.event.*;

public class MapScale extends JPanel 
{
    BufferedImage image;
    double scale = 1.0;

    public MapScale(BufferedImage image) 
    {
        this.image = image;
    }

    protected void paintComponent(Graphics g) 
    {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION,RenderingHints.VALUE_INTERPOLATION_BICUBIC);
        double x = 0;
        double y = 0;
        try
        {
        	x=(getWidth() - scale*image.getWidth())/2;
        }
        catch(Exception e)
        {
        	
        }
        try
        {
        	y=(getHeight() - scale*image.getHeight())/2;
        }
        catch(Exception e)
        {
        	
        }
        AffineTransform at = AffineTransform.getTranslateInstance(x,y);
        at.scale(scale, scale);
        g2.drawRenderedImage(image, at);
    }

    public Dimension getPreferredSize() 
    {
        int w = 0;
        int h = 0;
        try
        {
        	w=(int)(scale*image.getWidth());
        }
        catch(Exception e)
        {
        	
        }
        try
        {
        	h=(int)(scale*image.getHeight());
        }
        catch(Exception e)
        {
        	
        }
        return new Dimension(w, h);
    }

    private JSlider getSlider() 
    {
        int min = 1, max = 36;
        final JSlider slider = new JSlider(min, max, 16);
        
        slider.setMajorTickSpacing(5);
        slider.setMinorTickSpacing(1);
        slider.setPaintTicks(true);
        slider.setSnapToTicks(true);
        slider.addChangeListener(new ChangeListener() 
        {
            public void stateChanged(ChangeEvent e) {
                int value = slider.getValue();
                scale = (value+4)/20.0;
                revalidate();
                repaint();
            }
        });
        return slider;
    }

    public static void main(String[] args)
    {
        String path = "E:\\Program\\Programs\\MSc_CompSc\\2nd sem\\Image Processing\\workspacce\\ZoomShrinkDone\\src\\package1\\5.png";
        BufferedImage image = null;
        try
        {
        	image= ImageIO.read(new File(path));
        }
        catch(IOException e)
        {
        }
        MapScale test = new MapScale(image);
        JFrame frame = new JFrame("Zooming & Shrinking");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.getContentPane().add(new JScrollPane(test));
        //frame.getContentPane().add(test.getSlider(), "Last");
        frame.setSize(400,400);
        frame.setLocation(200,200);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}