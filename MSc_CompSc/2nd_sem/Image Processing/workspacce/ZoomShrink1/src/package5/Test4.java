package package5;

import javax.imageio.ImageIO;
import javax.imageio.ImageWriter;
import javax.imageio.ImageWriteParam;
import javax.imageio.IIOImage;
import javax.imageio.stream.FileImageOutputStream;
import java.awt.image.BufferedImage;
import java.awt.*;
import java.awt.geom.AffineTransform;
import java.io.IOException;
import java.io.File;
import java.util.Iterator;

/**
 * Java2D Bicubic image resize example
 */
public class Test4 {

    public static void main(String[] args) {
    	BufferedImage source = null;
    	 int destWidth = 0;
    	 BufferedImage resized = null;
        try
        {
        	try
        	{
        		source = ImageIO.read(new File(args[0]));
        	}
        	catch(IOException e)
        	{
        		throw e;
        	}
        	try
        	{
        		destWidth = Integer.parseInt(args[1]);
        	}
        	catch(Exception e)
        	{
        		
        	}
            int destHeight = 0;
            if (args.length == 3)
                destHeight = Integer.parseInt(args[2]);
            try
            {
            	resized = resize(source,destWidth,destHeight,RenderingHints.VALUE_INTERPOLATION_BICUBIC);
            }
            catch(Exception e)
            {
            	
            }
            try
            {
            	writeJPEG(resized,"C:\\1.jpg");
            }
            catch(Exception e)
            {
            	
            }
        } 
        catch (IOException e)
        {
            e.printStackTrace();
        }
    }

    public static BufferedImage resize(BufferedImage source, int destWidth, int destHeight, Object interpolation) {
        if (source == null)
            throw new NullPointerException("source image is NULL!");
        if (destWidth <= 0 && destHeight <= 0)
            throw new IllegalArgumentException("destination width & height are both <=0!");
        int sourceWidth = source.getWidth();
        int sourceHeight = source.getHeight();
        double xScale = ((double) destWidth) / (double) sourceWidth;
        double yScale = ((double) destHeight) / (double) sourceHeight;
        if (destWidth <= 0) {
            xScale = yScale;
            destWidth = (int) Math.rint(xScale * sourceWidth);
        }
        if (destHeight <= 0) {
            yScale = xScale;
            destHeight = (int) Math.rint(yScale * sourceHeight);
        }
        GraphicsConfiguration gc = getDefaultConfiguration();
        BufferedImage result = gc.createCompatibleImage(destWidth, destHeight, source.getColorModel().getTransparency());
        Graphics2D g2d = null;
        try {
            g2d = result.createGraphics();
            g2d.setRenderingHint(RenderingHints.KEY_INTERPOLATION, interpolation);
            AffineTransform at =
                    AffineTransform.getScaleInstance(xScale, yScale);
            g2d.drawRenderedImage(source, at);
        } finally {
            if (g2d != null)
                g2d.dispose();
        }
        return result;
    }

    public static GraphicsConfiguration getDefaultConfiguration() {
        GraphicsEnvironment ge = GraphicsEnvironment.getLocalGraphicsEnvironment();
        GraphicsDevice gd = ge.getDefaultScreenDevice();
        return gd.getDefaultConfiguration();
    }


    public static void writeJPEG(BufferedImage input, String name) throws IOException {
        Iterator iter =
                ImageIO.getImageWritersByFormatName("JPG");
        if (iter.hasNext()) {
            ImageWriter writer = (ImageWriter) iter.next();
            ImageWriteParam iwp =
                    writer.getDefaultWriteParam();
            iwp.setCompressionMode(
                    ImageWriteParam.MODE_EXPLICIT);
            iwp.setCompressionQuality(0.95f);
            File outFile = new File(name);
            FileImageOutputStream output =
                    new FileImageOutputStream(outFile);
            writer.setOutput(output);
            IIOImage image =
                    new IIOImage(input, null, null);
            writer.write(null, image, iwp);
            output.close();
        }
    }

}