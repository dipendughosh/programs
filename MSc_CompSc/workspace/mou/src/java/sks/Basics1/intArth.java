package java.sks.Basics1;
//Write a program to to demonstrate the Integer arithmetic operations performed in JAVA
import java.util.Scanner;
class intArth
{
	public static void main(String args[])
    {
		Scanner in = new Scanner(System.in);
		int lengthr=0,breadthr=0,lengths=0,areas,arear,peris,perir;
		System.out.print("Enter length of square in integer: ");
		lengths=in.nextInt();
		System.out.print("Enter length of rectangle in integer: ");
		lengthr=in.nextInt();
		System.out.print("Enter breadth of rectangle in integer: ");
		breadthr=in.nextInt();
		areas=lengths*lengths;
		arear=lengthr*breadthr;
		peris=4*lengths;
		perir=2*(lengthr+breadthr);
		System.out.println("Square\nPerimeter = "+peris+"\nArea = "+areas);
		System.out.println("Rectangle\nPerimeter = "+perir+"\nArea = "+arear);
	}
}
