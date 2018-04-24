package helloworldjava;

import java.io.*;

class parent {
	int x=10; 
        {
		x++;
		System.out.println("x="+x);
	}
	public void disp() {
		System.out.println("I am in parent"); 
	}
}

interface printable {
	void print();
}

interface showable extends printable {
	void show();
}

class child extends parent implements showable {
	final int y;
	child(int x) {
		x=x*x;
		y=20;
		System.out.println("x="+x);
	}
	public void print() {
		System.out.println("y="+y);
		System.out.println("Hello");
	}
	public void disp() {
		System.out.println("I am in child"); 
	}
	public void show() {
		System.out.println("I am in show"); 
	}
}

class AbstractTest {
	public static void main(String args[]) {
		child obj=new child(20);
		obj.print();
		obj.disp();
		obj.show();
		{
			System.out.println("I am in main block");
		}
	}
}