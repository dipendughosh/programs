package demos2;


import com.sun.opengl.util.BufferUtil;
import com.sun.opengl.util.FPSAnimator;
import com.sun.opengl.util.GLUT;

import javax.swing.*;
import javax.media.opengl.*;
import javax.media.opengl.glu.GLU;

import java.awt.*;
import java.awt.event.*;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.nio.IntBuffer;
import java.util.ArrayList;
import java.util.List;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLEventListener;
import java.io.IOException;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.awt.image.PixelGrabber;
import java.io.FileInputStream;
import java.io.InputStream;
import java.nio.ByteBuffer;

public class Loader 
{
    public static void main(String[] args) 
    {
    	GLDisplay myGLDisplay = new GLDisplay("Texture mapping");
        myGLDisplay.addGLEventListener(new Renderer());
        myGLDisplay.start();
    }
    
    public static class GLDisplay 
    {
        private static final int DEFAULT_WIDTH = 640;
        private static final int DEFAULT_HEIGHT = 480;
		private static final int EXIT_ON_CLOSE = 0;

        private JFrame frame;
        private GLCanvas glCanvas;
        private FPSAnimator animator;
        private int width;
        private int height;
        
        private MyHelpOverlayGLEventListener helpOverlayGLEventListener = new MyHelpOverlayGLEventListener();
        private MyExceptionHandler exceptionHandler = new MyExceptionHandler();

        public GLDisplay( String title ) 
        {
        	GLCapabilities caps = new GLCapabilities();
            int width = DEFAULT_WIDTH;
            int height = DEFAULT_HEIGHT;

            glCanvas = new GLCanvas(caps);
            glCanvas.setSize( width, height );
            glCanvas.setIgnoreRepaint( true );
            //glCanvas.addGLEventListener( helpOverlayGLEventListener );

            frame = new JFrame( title );
            frame.getContentPane().setLayout( new BorderLayout() );
            frame.getContentPane().add( glCanvas, BorderLayout.CENTER );
           
            //addKeyListener( new MyKeyAdapter() );

            this.width = width;
            this.height = height;

            animator = new FPSAnimator( glCanvas, 60 );
            animator.setRunAsFastAsPossible(false);
        }

        public void start() 
        {
            try
            {
                frame.addWindowListener( new MyWindowAdapter() );

                frame.setSize( frame.getContentPane().getPreferredSize() );
                frame.setVisible( true );
                
                glCanvas.requestFocus();

                animator.start();
            } 
            catch ( Exception e ) 
            {
                exceptionHandler.handleException( e );
            }
        }

        public void stop() 
        {
            try 
            {
                animator.stop();
                frame.dispose();
            } 
            catch ( Exception e ) 
            {
                exceptionHandler.handleException( e );
            }
            finally 
            {
                System.exit( 0 );
            }
        }

        public void addGLEventListener( GLEventListener glEventListener ) 
        {
            this.helpOverlayGLEventListener.addGLEventListener( glEventListener );
        }

        public void removeGLEventListener( GLEventListener glEventListener ) 
        {
            this.helpOverlayGLEventListener.removeGLEventListener( glEventListener );
        }

        public void addKeyListener( KeyListener l )
        {
            glCanvas.addKeyListener( l );
        }

        public void removeKeyListener( KeyListener l ) 
        {
            glCanvas.removeKeyListener( l );
        }

        public void registerKeyStrokeForHelp( KeyStroke keyStroke, String description ) 
        {
            helpOverlayGLEventListener.registerKeyStroke( keyStroke, description );
        }

        private class MyWindowAdapter extends WindowAdapter 
        {
            public void windowClosing( WindowEvent e ) 
            {
                stop();
            }
        }

        private class MyExceptionHandler 
        {
            public void handleException( final Exception e ) 
            {
                SwingUtilities.invokeLater( new Runnable() 
                {
                    public void run() 
                    {
                        StringWriter stringWriter = new StringWriter();
                        PrintWriter printWriter = new PrintWriter( stringWriter );
                        e.printStackTrace( printWriter );
                        JOptionPane.showMessageDialog( frame, stringWriter.toString(), "Exception occurred", JOptionPane.ERROR_MESSAGE );
                        stop();
                    }
                }
                );
            }
        }

        private class MyHelpOverlayGLEventListener implements GLEventListener 
        {
            private java.util.List eventListeners = new ArrayList();
            private boolean showHelp = false;
            
            private List keyboardEntries = new ArrayList();
            private GLUT glut = new GLUT();
            private GLU glu = new GLU();
            private static final int CHAR_HEIGHT = 12;
            private static final int OFFSET = 15;
            private static final int INDENT = 3;
            private static final String KEYBOARD_CONTROLS = "Keyboard controls";
            

            public void toggleHelp() 
            {
                showHelp = !showHelp;
            }

            public void registerKeyStroke( KeyStroke keyStroke, String description ) 
            {
            	String modifiersText = KeyEvent.getKeyModifiersText(keyStroke.getModifiers());
                String keyText = KeyEvent.getKeyText(keyStroke.getKeyCode());
                keyboardEntries.add((modifiersText.length() != 0 ? modifiersText + " " : "") +keyText + ": " +description);
            
            }

            public void addGLEventListener( GLEventListener glEventListener ) 
            {
                eventListeners.add( glEventListener );
            }

            public void removeGLEventListener( GLEventListener glEventListener ) {
                eventListeners.remove( glEventListener );
            }

            public void display( GLAutoDrawable glDrawable ) 
            {
                for ( int i = 0; i < eventListeners.size(); i++ ) 
                {
                    ( (GLEventListener) eventListeners.get( i ) ).display( glDrawable );
                }
                if ( showHelp )
                {
                	GL gl = glDrawable.getGL();
                	gl.glMatrixMode(GL.GL_MODELVIEW);
                	gl.glPushMatrix();
                	gl.glLoadIdentity();
                	gl.glMatrixMode(GL.GL_PROJECTION);
                	gl.glPushMatrix();
                	gl.glLoadIdentity();
                	
                	gl.glViewport(0, 0, glDrawable.getWidth(), glDrawable.getHeight());

                	
                	gl.glPushAttrib(GL.GL_ENABLE_BIT);
                	gl.glDisable(GL.GL_BLEND);
                	gl.glDisable(GL.GL_LIGHTING);
                	gl.glDisable(GL.GL_TEXTURE_2D);
                	gl.glDisable(GL.GL_DEPTH_TEST);
                	
                	IntBuffer viewPort = BufferUtil.newIntBuffer(4);
                	gl.glGetIntegerv(GL.GL_VIEWPORT, viewPort);
                	glu.gluOrtho2D(0, viewPort.get(2), viewPort.get(3), 0);

                	gl.glColor3f(1, 1, 1);

                	int x = OFFSET;
                	int maxx = 0;
                	int y = OFFSET + CHAR_HEIGHT;

                	if (keyboardEntries.size() > 0) 
                	{
                		gl.glRasterPos2i(x, y);
                		glut.glutBitmapString(GLUT.BITMAP_HELVETICA_12, KEYBOARD_CONTROLS);
                		maxx = Math.max(maxx, OFFSET + glut.glutBitmapLength(GLUT.BITMAP_HELVETICA_12, KEYBOARD_CONTROLS));
                		
                		y += OFFSET;
                		x += INDENT;
                		for (int i = 0; i < keyboardEntries.size(); i++) 
                		{
                			gl.glRasterPos2f(x, y);
                			String text = (String) keyboardEntries.get(i);
                			glut.glutBitmapString(GLUT.BITMAP_HELVETICA_12, text);
                			maxx = Math.max(maxx, OFFSET + glut.glutBitmapLength(GLUT.BITMAP_HELVETICA_12, text));
                			y += OFFSET;
                		}
                	}
                	
                	gl.glPopAttrib();

                	gl.glPopMatrix();
                	gl.glMatrixMode(GL.GL_MODELVIEW);
                	gl.glPopMatrix();
                }

            }

            public void displayChanged( GLAutoDrawable glDrawable, boolean b, boolean b1 ) 
            {
                for ( int i = 0; i < eventListeners.size(); i++ ) 
                {
                    ( (GLEventListener) eventListeners.get( i ) ).displayChanged( glDrawable, b, b1 );
                }
            }

            public void init( GLAutoDrawable glDrawable ) 
            {
                for ( int i = 0; i < eventListeners.size(); i++ ) 
                {
                    ( (GLEventListener) eventListeners.get( i ) ).init( glDrawable );
                }
            }

            public void reshape( GLAutoDrawable glDrawable, int i0, int i1, int i2, int i3 ) 
            {
                for ( int i = 0; i < eventListeners.size(); i++ ) 
                {
                    ( (GLEventListener) eventListeners.get( i ) ).reshape( glDrawable, i0, i1, i2, i3 );
                }
            }

    		
    		
        }
    }
}

class Renderer implements GLEventListener 
{
	private int texture1;
    private int texture2;
    private GLU glu = new GLU();

    /** Called by the drawable to initiate OpenGL rendering by the client.
    * After all GLEventListeners have been notified of a display event, the
    * drawable will swap its buffers if necessary.
    * @param gLDrawable The GLAutoDrawable object.
    */
    public void display(GLAutoDrawable gLDrawable) 
    {
    	final GL gl = gLDrawable.getGL();
        gl.glClear(GL.GL_COLOR_BUFFER_BIT | GL.GL_DEPTH_BUFFER_BIT);
        gl.glLoadIdentity();  // Reset The View
        gl.glTranslatef(0.0f, 0.0f, -5.0f);

        gl.glBindTexture(GL.GL_TEXTURE_2D, texture1);

        gl.glBegin(GL.GL_QUADS);
        	gl.glTexCoord2f(0.0f, 0.0f);
            gl.glVertex2f(-1.0f, -1.0f);
            gl.glTexCoord2f(1.0f, 0.0f);
            gl.glVertex2f(0.0f, -1.0f);
            gl.glTexCoord2f(1.0f, 1.0f);
            gl.glVertex2f(0.0f, 1.0f);
            gl.glTexCoord2f(0.0f, 1.0f);
            gl.glVertex2f(-1.0f, 1.0f);
        gl.glEnd();

        /*gl.glBindTexture(GL.GL_TEXTURE_2D, texture2);

        gl.glBegin(GL.GL_QUADS);
           	gl.glTexCoord2f(0.0f, 0.0f);
           	gl.glVertex2f(-1.0f, -1.0f);
           	gl.glTexCoord2f(1.0f, 0.0f);
           	gl.glVertex2f(1.0f, -1.0f);
           	gl.glTexCoord2f(1.0f, 1.0f);
           	gl.glVertex2f(1.0f, 1.0f);
           	gl.glTexCoord2f(0.0f, 1.0f);
           	gl.glVertex2f(-1.0f, 1.0f);
        gl.glEnd();*/
    }


    /** Called when the display mode has been changed.  <B>
     * !! CURRENTLY UNIMPLEMENTED IN JOGL !!</B>
     * @param gLDrawable The GLAutoDrawable object.
     * @param modeChanged Indicates if the video mode has changed.
     * @param deviceChanged Indicates if the video device has changed.
     */
    public void displayChanged(GLAutoDrawable gLDrawable,boolean modeChanged, boolean deviceChanged) 
    {
    }

    /** Called by the drawable immediately after the OpenGL context is
     * initialized for the first time. Can be used to perform one-time OpenGL
     * initialization such as setup of lights and display lists.
     * @param gLDrawable The GLAutoDrawable object.
     */
    public void init(GLAutoDrawable gLDrawable) 
    {
    	final GL gl = gLDrawable.getGL();
        gl.glShadeModel(GL.GL_SMOOTH);              // Enable Smooth Shading
        gl.glClearColor(0.0f, 0.0f, 0.0f, 0.5f);    // Black Background
        gl.glClearDepth(1.0f);                      // Depth Buffer Setup
        gl.glEnable(GL.GL_DEPTH_TEST);              // Enables Depth Testing
        gl.glDepthFunc(GL.GL_LEQUAL);               // The Type Of Depth Testing To Do
        // Really Nice Perspective Calculations
        gl.glHint(GL.GL_PERSPECTIVE_CORRECTION_HINT, GL.GL_NICEST);  
        gl.glEnable(GL.GL_TEXTURE_2D);
        
        texture1 = genTexture(gl);
        gl.glBindTexture(GL.GL_TEXTURE_2D, texture1);
        TextureReader.Texture texture3 = null;
        try 
        {
        	texture3 = TextureReader.readTexture("demos/images/ship.png");
        }
        catch (IOException e) 
        {
        	e.printStackTrace();
            throw new RuntimeException(e);
        }
        makeRGBTexture(gl, glu, texture3, GL.GL_TEXTURE_2D, false);
          
        /*texture2 = genTexture(gl);
        gl.glBindTexture(GL.GL_TEXTURE_2D, texture2);
        TextureReader.Texture texture4 = null;
        try
        {
        	texture4 = TextureReader.readTexture("demos/images/alien.png");
        }
        catch (IOException e)
        {
            e.printStackTrace();
            throw new RuntimeException(e);
        }
        makeRGBTexture(gl, glu, texture4, GL.GL_TEXTURE_2D, false);*/
            
        gl.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MIN_FILTER, GL.GL_LINEAR);
        gl.glTexParameteri(GL.GL_TEXTURE_2D, GL.GL_TEXTURE_MAG_FILTER, GL.GL_LINEAR);
    }

    /** Called by the drawable during the first repaint after the component has
     * been resized. The client can update the viewport and view volume of the
     * window appropriately, for example by a call to
     * GL.glViewport(int, int, int, int); note that for convenience the component
     * has already called GL.glViewport(int, int, int, int)(x, y, width, height)
     * when this method is called, so the client may not have to do anything in
     * this method.
     * @param gLDrawable The GLAutoDrawable object.
     * @param x The X Coordinate of the viewport rectangle.
     * @param y The Y coordinate of the viewport rectanble.
     * @param width The new width of the window.
     * @param height The new height of the window.
    */
    public void reshape(GLAutoDrawable gLDrawable, int x, int y, int width,int height) 
    {
    	final GL gl = gLDrawable.getGL();
        if (height <= 0) // avoid a divide by zero error!
        	height = 1;
        final float h = (float) width / (float) height;
        gl.glViewport(0, 0, width, height);
        gl.glMatrixMode(GL.GL_PROJECTION);
        gl.glLoadIdentity();
        glu.gluPerspective(45.0f, h, 1.0, 20.0);
        gl.glMatrixMode(GL.GL_MODELVIEW);
        gl.glLoadIdentity();
    }
    
    private void makeRGBTexture(GL gl, GLU glu, TextureReader.Texture img, int target, boolean mipmapped) 
    {
    	if (mipmapped) 
        {
    		glu.gluBuild2DMipmaps(target, GL.GL_RGB8, img.getWidth(),img.getHeight(), GL.GL_RGB, GL.GL_UNSIGNED_BYTE, img.getPixels());
        } 
        else 
        {
        	gl.glTexImage2D(target, 0, GL.GL_RGB, img.getWidth(),img.getHeight(), 0, GL.GL_RGB, GL.GL_UNSIGNED_BYTE, img.getPixels());
        }
    }

    private int genTexture(GL gl) 
    {
    	final int[] tmp = new int[1];
        gl.glGenTextures(1, tmp, 0);
        return tmp[0];
    }
    
    public static class TextureReader 
    {
    	public static Texture readTexture(String filename) throws IOException
        {
    		boolean storeAlphaChannel = false;
            BufferedImage bufferedImage;
            bufferedImage = readImage(filename);
            return readPixels(bufferedImage, storeAlphaChannel);
        }

        private static BufferedImage readImage(String resourceName) throws IOException 
        {
        	return ImageIO.read(ResourceRetriever.getResourceAsStream(resourceName));
        }

        private static Texture readPixels(BufferedImage img, boolean storeAlphaChannel) 
        {
        	int[] packedPixels = new int[img.getWidth() * img.getHeight()];

            PixelGrabber pixelgrabber = new PixelGrabber(img, 0, 0, img.getWidth(), img.getHeight(), packedPixels, 0, img.getWidth());
            try
            {
            	pixelgrabber.grabPixels();
            }
            catch (InterruptedException e) 
            {
                throw new RuntimeException();
            }

            int bytesPerPixel = storeAlphaChannel ? 4 : 3;
            ByteBuffer unpackedPixels = BufferUtil.newByteBuffer(packedPixels.length * bytesPerPixel);
            for (int row = img.getHeight() - 1; row >= 0; row--)
            {
            	for (int col = 0; col < img.getWidth(); col++) 
                {
            		int packedPixel = packedPixels[row * img.getWidth() + col];
                    unpackedPixels.put((byte) ((packedPixel >> 16) & 0xFF));
                    unpackedPixels.put((byte) ((packedPixel >> 8) & 0xFF));
                    unpackedPixels.put((byte) ((packedPixel >> 0) & 0xFF));
                    if (storeAlphaChannel) 
                    {
                    	unpackedPixels.put((byte) ((packedPixel >> 24) & 0xFF));
                    }
                }
            }

            unpackedPixels.flip();

            return new Texture(unpackedPixels, img.getWidth(), img.getHeight());
        }

        public static class Texture 
        {
            private ByteBuffer pixels;
            private int width;
            private int height;
            public Texture(ByteBuffer pixels, int width, int height) 
            {
                this.height = height;
                this.pixels = pixels;
                this.width = width;
            }
            public int getHeight() 
            {
            	return height;
            }
            public ByteBuffer getPixels() 
            {
            	return pixels;
            }
            public int getWidth() 
            {
             	return width;
            }
        }
            
        public static class ResourceRetriever 
        {
        	public static InputStream getResourceAsStream(final String filename) throws IOException 
            {
        		// Try to load resource from jar
                String convertedFileName = filename.replace('\\', '/');
                InputStream stream = ResourceRetriever.class.getClassLoader().getResourceAsStream(convertedFileName);
                // If not found in jar, then load from disk
                if (stream == null)
                {
                	return new FileInputStream(convertedFileName);
                }
                else 
                {
                	return stream;
                }
            }
       }
    }
}
