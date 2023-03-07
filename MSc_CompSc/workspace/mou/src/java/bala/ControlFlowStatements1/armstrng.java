package java.bala.ControlFlowStatements1;
//Write a program that will check whether a number is Armstrong number or not
import java.io.DataInputStream;
class armstrng
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int s=0,intNumber=0,n,b=0,x=0,a=1;
		try
		{
			System.out.print("Enter Integer Value: ");
			intNumber=Integer.parseInt(in.readLine());
		}
		catch(Exception e)
		{
		}
		n=intNumber;
		while(n >= 1)
		{
			n=n/10;
			x++;
		}
		n=intNumber;
		while(n >= 1)
		{
			b=n%10;
			n=n/10;
			a=1;
			for(int i=1;i<=x;i++)
				a=a*b;
			s=s+a;
		}
		if(s == intNumber)
			System.out.println(intNumber+" is an Armstromg Number");
		else
			System.out.println(intNumber+" is Not an Armstromg Number");
	}
}
