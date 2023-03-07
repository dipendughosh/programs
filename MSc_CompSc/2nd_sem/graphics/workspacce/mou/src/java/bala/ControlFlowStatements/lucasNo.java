//Write a program that will generate Lucas sequence up to certain range specified by user
import java.io.DataInputStream;
class lucasNo
{
	public static void main(String args[])
	{
		DataInputStream in = new DataInputStream(System.in);
		int range=0,a=2,b=1,c=0;
		try
		{
			System.out.print("Enter the range:- ");
			range=Integer.parseInt(in.readLine());
		}
		catch(Exception e)
		{
		}
		System.out.println("The sequence is as follows : ");
		System.out.print(a+"\t"+b);
		for(int i=2;i<=range;i++)
		{
			c=a+b;
			System.out.print("\t"+c);
			a=b;
			b=c;
		}
	}
}			
			
		
		
		
		