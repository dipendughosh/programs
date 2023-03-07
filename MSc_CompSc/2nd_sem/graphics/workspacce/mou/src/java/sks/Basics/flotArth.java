//Write a program to to demonstrate the Float arithmetic operations performed in JAVA
import java.util.Scanner;
class flotArth
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		float r=0.0f;
		double pi=3.142857142857,cir=0.0f,area=0.0f;
		System.out.print("Enter Radius of circle in float: ");
		r=in.nextFloat();
		cir=2*pi*r;
		area=pi*r*r;
		System.out.println("Circumference of circle = "+cir+"\nArea of circle = "+area);	
	}
}
