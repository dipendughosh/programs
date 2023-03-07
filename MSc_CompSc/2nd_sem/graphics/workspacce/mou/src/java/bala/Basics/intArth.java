//Write a program to to demonstrate the Integer arithmetic operations performed in JAVA
import java.io.DataInputStream;
class intArth
{
	public static void main(String args[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int lengthr=0,breadthr=0,lengths=0,areas,arear,peris,perir;
		try
		{
			System.out.print("Enter length of square in integer: ");
			lengths=Integer.parseInt(in.readLine());
			System.out.print("Enter length of rectangle in integer: ");
			lengthr=Integer.parseInt(in.readLine());
			System.out.print("Enter breadth of rectangle in integer: ");
			breadthr=Integer.parseInt(in.readLine());
		}
		catch(Exception E)
		{
		}
		areas=lengths*lengths;
		arear=lengthr*breadthr;
		peris=4*lengths;
		perir=2*(lengthr+breadthr);
		System.out.println("Square\nPerimeter = "+peris+"\nArea = "+areas);
		System.out.println("Rectangle\nPerimeter = "+perir+"\nArea = "+arear);
	}
}
