package package5;

import java.awt.*;
import java.awt.geom.AffineTransform;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.ImageIO;
import javax.swing.*;

public class Test6 extends JPanel implements Runnable {
    BufferedImage image;
    double scale = 1.0;
    Thread thread;
    boolean animating = false;
    boolean increasing = true;

    Test6(BufferedImage image) {
        this.image = image;
    }

    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2 = (Graphics2D)g;
        g2.setRenderingHint(RenderingHints.KEY_INTERPOLATION,
                            RenderingHints.VALUE_INTERPOLATION_BICUBIC);
        int w = getWidth();
        int h = getHeight();
        int iw = image.getWidth();
        int ih = image.getHeight();
        double x = (w - scale*iw)/2;
        double y = (h - scale*ih)/2;
        AffineTransform at = AffineTransform.getTranslateInstance(x, y);
        at.scale(scale, scale);
        g2.drawRenderedImage(image, at);
    }

    public void run() {
        while(animating) {
            try {
                Thread.sleep(50);
            } catch(InterruptedException e) {
                stop();
            }
            scale = scale + (increasing ? 0.05 : -0.05);
            if(increasing && scale > 2) {
                increasing = false;
            } else if(!increasing && scale < 1.0) {
                increasing = true;
            }
            repaint();
        }
    }

    private void start() {
        if(!animating) {
            animating = true;
            thread = new Thread(this);
            thread.setPriority(Thread.NORM_PRIORITY);
            thread.start();
        }
    }

    private void stop() {
        animating = false;
        if(thread != null)
            thread.interrupt();
        thread = null;
    }

    public static void main(String[] args) throws IOException {
        String path = "1.jpg";
        BufferedImage image = null;
        try
        {
        	image = ImageIO.read(new File(path));
        }
        catch(Exception e)
        {
        	
        }
        Test6 test = new Test6(image);
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.getContentPane().add(test);
        f.setSize(500,500);
        f.setLocation(200,200);
        f.setVisible(true);
        test.start();
    }
}