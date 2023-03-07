package package4;

import java.awt.*;
import java.awt.event.*;

import java.util.*;

import javax.swing.*;


public class ImageLoad extends JFrame implements KeyListener,MouseListener,EventListener
{
	private static final long serialVersionUID = 1L;

	public Image img;
	Dimension size;
	
	ImageLoad()
	{
		JFrame frame = new JFrame();
		frame.setSize(800, 600);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setBounds(0, 0, 800, 600);
		Canvas canvas = new Canvas();
		frame.add(canvas);
		try
		{
			frame.addKeyListener((KeyListener) frame);
			frame.addMouseListener((MouseListener) frame);
		}
		catch(Exception e)
		{
			
		}
		frame.setVisible(true);	
		
	}
	
	public static void main(String[] args)
	{
		ImageLoad imageload = new ImageLoad();
			
		
	}
	
	public void init()
	{
		img = new ImageIcon(this.getClass().getResource("1.jpg")).getImage();
		size.width = img.getWidth(this)+100;
        size.height = img.getHeight(this)+100;
	}
	
	public void paint(Graphics g)
    {

        Graphics2D g2d = (Graphics2D) g;

        g2d.drawImage(img, 10, 10, this);
    }

	@Override
	public void keyPressed(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyReleased(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void keyTyped(KeyEvent arg0) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseClicked(MouseEvent arg0) {
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
