package jogl;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.color.ColorSpace;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;
import java.awt.image.ComponentColorModel;
import java.awt.image.DataBuffer;
import java.awt.image.DataBufferByte;
import java.awt.image.Raster;
import java.awt.image.WritableRaster;
import java.io.BufferedInputStream;
import java.io.IOException;
import java.net.URL;
import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.util.HashMap;
import java.util.Hashtable;

import javax.imageio.ImageIO;

import javax.media.opengl.GL;

import package1.Sprite;

public class TextureLoader 
{
    private HashMap table = new HashMap();
    private GL gl;
    private ColorModel glAlphaColorModel;
    private ColorModel glColorModel;
    
    public TextureLoader(GL gl) 
    {
    	this.gl = gl;
    	
        glAlphaColorModel = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_sRGB), new int[] {8,8,8,8}, true,false,ComponentColorModel.TRANSLUCENT,DataBuffer.TYPE_BYTE);                                            
        glColorModel = new ComponentColorModel(ColorSpace.getInstance(ColorSpace.CS_sRGB),new int[] {8,8,8,0},false,false,ComponentColorModel.OPAQUE,DataBuffer.TYPE_BYTE);
    }
    
    private int createTextureID() 
    { 
       int[] tmp = new int[1]; 
       gl.glGenTextures(1, tmp,0); 
	   //gl.glGenTextures(1, tmp); 
       return tmp[0]; 
    } 
    
    public Texture getTexture(String resourceName) throws IOException 
    {
        Texture tex = (Texture) table.get(resourceName);
        
        if (tex != null) 
        {
            return tex;
        }
        
        tex = getTexture(resourceName,GL.GL_TEXTURE_2D,GL.GL_RGBA,GL.GL_LINEAR,GL.GL_LINEAR);
        
        table.put(resourceName,tex);
        
        return tex;
    }
    
    public Texture getTexture(String resourceName,int target,int dstPixelFormat,int minFilter,int magFilter) throws IOException 
    { 
        int srcPixelFormat = 0;
        
        int textureID = createTextureID(); 
        Texture texture = new Texture(target,textureID); 
        
        gl.glBindTexture(target, textureID); 
 
        BufferedImage bufferedImage = loadImage(resourceName); 
        texture.setWidth(bufferedImage.getWidth());
        texture.setHeight(bufferedImage.getHeight());
        
        if (bufferedImage.getColorModel().hasAlpha()) 
        {
            srcPixelFormat = GL.GL_RGBA;
        }
        else 
        {
            srcPixelFormat = GL.GL_RGB;
        }

        ByteBuffer textureBuffer = convertImageData(bufferedImage,texture); 
        
        if (target == GL.GL_TEXTURE_2D) 
        { 
        	gl.glTexParameteri(target, GL.GL_TEXTURE_MIN_FILTER, minFilter); 
            gl.glTexParameteri(target, GL.GL_TEXTURE_MAG_FILTER, magFilter); 
        } 
 
        gl.glTexImage2D(target,0,dstPixelFormat,get2Fold(bufferedImage.getWidth()),get2Fold(bufferedImage.getHeight()),0,srcPixelFormat,GL.GL_UNSIGNED_BYTE,textureBuffer ); 
        
        return texture; 
    } 
    
    private int get2Fold(int fold) 
    {
        int ret = 2;
        while (ret < fold) 
        {
            ret *= 2;
        }
        return ret;
    } 
    
    private ByteBuffer convertImageData(BufferedImage bufferedImage,Texture texture) 
    { 
        ByteBuffer imageBuffer = null; 
        WritableRaster raster;
        BufferedImage texImage;
        
        int texWidth = 2;
        int texHeight = 2;
        
        while (texWidth < bufferedImage.getWidth()) 
        {
            texWidth *= 2;
        }
        while (texHeight < bufferedImage.getHeight()) 
        {
            texHeight *= 2;
        }
        
        texture.setTextureHeight(texHeight);
        texture.setTextureWidth(texWidth);
        
        if (bufferedImage.getColorModel().hasAlpha()) 
        {
            raster = Raster.createInterleavedRaster(DataBuffer.TYPE_BYTE,texWidth,texHeight,4,null);
            texImage = new BufferedImage(glAlphaColorModel,raster,false,new Hashtable());
        }
        else
        {
            raster = Raster.createInterleavedRaster(DataBuffer.TYPE_BYTE,texWidth,texHeight,3,null);
            texImage = new BufferedImage(glColorModel,raster,false,new Hashtable());
        }
            
        Graphics g = texImage.getGraphics();
        g.setColor(new Color(0f,0f,0f,0f));
        g.fillRect(0,0,texWidth,texHeight);
        g.drawImage(bufferedImage,0,0,null);
        
        byte[] data = ((DataBufferByte) texImage.getRaster().getDataBuffer()).getData(); 

        imageBuffer = ByteBuffer.allocateDirect(data.length); 
        imageBuffer.order(ByteOrder.nativeOrder()); 
        imageBuffer.put(data, 0, data.length); 
        
        return imageBuffer; 
    } 
    
    private BufferedImage loadImage(String ref) throws IOException 
    { 
        URL url = TextureLoader.class.getClassLoader().getResource(ref);
        
        if (url == null) 
        {
            throw new IOException("Cannot find: "+ref);
        }
        
        BufferedImage bufferedImage = ImageIO.read(new BufferedInputStream(getClass().getClassLoader().getResourceAsStream(ref))); 
 
        return bufferedImage;
    } 
    
    //Texture Class
    public static class Texture 
    {
        private int target; 
        private int textureID;
        private int height;
        private int width;
        private int texWidth;
        private int texHeight;
        private float widthRatio;
        private float heightRatio;
        
        public Texture(int target,int textureID) 
        {
            this.target = target;
            this.textureID = textureID;
        }
        
        public void bind(GL gl) 
        {
            gl.glBindTexture(target, textureID); 
        }
        
        public void setHeight(int height) 
        {
            this.height = height;
            setHeight();
        }
        
        public void setWidth(int width) 
        {
            this.width = width;
            setWidth();
        }
        
        public int getImageHeight() 
        {
            return height;
        }
        
        public int getImageWidth() 
        {
            return width;
        }
        
        public float getHeight() 
        {
            return heightRatio;
        }
        
        public float getWidth() 
        {
            return widthRatio;
        }
        
        public void setTextureHeight(int texHeight) 
        {
            this.texHeight = texHeight;
            setHeight();
        }
        
        public void setTextureWidth(int texWidth) 
        {
            this.texWidth = texWidth;
            setWidth();
        }
        
        private void setHeight() 
        {
            if (texHeight != 0) 
            {
                heightRatio = ((float) height)/texHeight;
            }
        }
        
        private void setWidth() 
        {
            if (texWidth != 0) 
            {
                widthRatio = ((float) width)/texWidth;
            }
        }
    }
    
    //Sprite Loader
    public static class JoglSprite implements Sprite 
    {
    	private TextureLoader.Texture texture;
    	private JoglGameWindow window;
    	private int width;
    	private int height;
    	
    	public JoglSprite(JoglGameWindow window,String ref) 
    	{
    		try 
    		{
    			this.window = window;
    			texture = window.getTextureLoader().getTexture(ref);
    			
    			width = texture.getImageWidth();
    			height = texture.getImageHeight();
    		}
    		catch (IOException e) 
    		{
    			System.err.println("Unable to load texture: "+ref);
    			System.exit(0);
    		}
    	}
    	
    	public int getWidth() 
    	{
    		return texture.getImageWidth();
    	}

    	public int getHeight() 
    	{
    		return texture.getImageHeight();
    	}

    	public void draw(int x, int y) 
    	{
    	
    		GL gl = window.getGL();
    	
    		gl.glPushMatrix();
    		
    		texture.bind(gl);		
    		gl.glTranslatef(x, y, 0);		
    		gl.glColor3f(1,1,1);
    		
    		gl.glBegin(GL.GL_QUADS);
    		{
    			gl.glTexCoord2f(0, 0);
    			gl.glVertex2f(0, 0);
    			gl.glTexCoord2f(0, texture.getHeight());
    			gl.glVertex2f(0, height);
    			gl.glTexCoord2f(texture.getWidth(), texture.getHeight());
    			gl.glVertex2f(width,height);
    			gl.glTexCoord2f(texture.getWidth(), 0);
    			gl.glVertex2f(width,0);
    		}
    		gl.glEnd();
    		
    		gl.glPopMatrix();
    	}
    }
}