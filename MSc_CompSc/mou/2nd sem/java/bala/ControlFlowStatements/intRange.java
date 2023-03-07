//Write a program that will find sum of all the positive integers upto a specified range
import java.io.DataInputStream;
class intRange
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int i=0,n=0,s=0;
		float floatNumber=0.0f;
		try
		{
			do
			{
				System.out.print("Enter Range(Positive Integer): ");
				n=Integer.parseInt(in.readLine());
			}while(n <= 0);
		}
		catch(Exception E)
		{
		}
		System.out.println("Intergers upto "+n+" are:-");
		for(i=1;i<=n;i++)
			s=s+i;
		System.out.print("sum till "+i+" = "+s);
	}
}
