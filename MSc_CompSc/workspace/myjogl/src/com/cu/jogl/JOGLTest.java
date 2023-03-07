package com.cu.jogl;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.media.opengl.GL;
import javax.media.opengl.GLAutoDrawable;
import javax.media.opengl.GLCanvas;
import javax.media.opengl.GLEventListener;
import javax.swing.JFrame;
import javax.swing.JLabel;

import com.sun.opengl.util.Animator;

public class JOGLTest extends JFrame implements KeyListener, MouseListener, GLEventListener{

	double sx = 1;
	double tx = 0;
	double rx = 0;
	double ty = 0;
	
	public static void main(String[] args) {
		JOGLTest frame = new JOGLTest();
		
		frame.setTitle("My JOGL...");
		frame.setSize(450,450);
		frame.setDefaultCloseOperation(EXIT_ON_CLOSE);
		
		GLCanvas canvas = new GLCanvas();
		frame.add(canvas);
		
		canvas.addGLEventListener(frame);

		frame.addKeyListener(frame);
		
		Animator animator = new Animator(canvas);
		animator.start();
		
		frame.setVisible(true);
		
		

	}

	@Override
	public void keyPressed(KeyEvent ke) {
		if(ke.getKeyCode() == KeyEvent.VK_LEFT){
			tx -= .02;
		}else if(ke.getKeyCode() == KeyEvent.VK_RIGHT){
			tx += .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_UP){
			ty += .02;
		}
		else if(ke.getKeyCode() == KeyEvent.VK_DOWN){
			ty -= .02;
		}
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent ke) {
		System.out.println("Key Typed : "+ke.getKeyChar());
		
	}

	@Override
	public void display(GLAutoDrawable drawable) {
		GL gl = drawable.getGL();
		gl.glClear(GL.GL_COLOR_BUFFER_BIT);
		gl.glLoadIdentity();
		gl.glTranslated(tx, 0, 0);
		gl.glTranslated(0, ty, 0);
		gl.glRotated(rx, .3, .3, .3);
		rx += .01;
		gl.glScaled(sx, sx, 1);
		/*
		if(sx > .5)
			sx -= .002;
		*/
		drawTriangle(gl);
	
		
		
	}

	private void drawTriangle(GL gl) {
		gl.glBegin(GL.GL_TRIANGLES);
		    gl.glColor3d(1, 0, 0);
			gl.glVertex3d(0, .3, 0);
			gl.glColor3d(0, 1, 0);
			gl.glVertex3d(-.3, -.3,0);
			gl.glColor3d(0, 0, 1);
			gl.glVertex3d(.3, -.3,0);
		gl.glEnd();
		
	}

	@Override
	public void displayChanged(GLAutoDrawable drawable, boolean modeChanged,
			boolean deviceChanged) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void init(GLAutoDrawable drawable) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void reshape(GLAutoDrawable drawable, int x, int y, int width,
			int height) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseClicked(MouseEvent mo) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mousePressed(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	

}
