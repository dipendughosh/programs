//Write a program that will take an integer from the user amd check whether it is perfect number or not
import java.io.DataInputStream;
class perfectNo
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int intNumber=0,n=0,s=0;
		try
		{
			System.out.print("Enter Number: ");
			intNumber=Integer.parseInt(in.readLine());
		}
		catch(Exception E)
		{
		}
		n=intNumber;
		for(int i=1;i<=n/2;i++)
		{		
			if(n % i == 0)
				s=s+i;
		}
		if(s == intNumber)
			System.out.println(intNumber+" is a Perfect Number");
		else
			System.out.println(intNumber+" is Not a Perfect Number");
	}
}
