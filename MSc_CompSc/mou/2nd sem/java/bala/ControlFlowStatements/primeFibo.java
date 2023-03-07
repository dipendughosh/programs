//Write a program that will generate all prime numbers with in Fibonacci series up to certain range
import java.io.DataInputStream;
class primeFibo
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int a=0,b=1,c=0,n=0,x=0;
		try
		{
			System.out.print("Enter Range: ");
			n=Integer.parseInt(in.readLine());		
        }
		catch(Exception E)
		{
		}
		System.out.print("All prime numbers that are also fibonacci numbers:\n1\t");
		for(int i=2;i<n;i++)
		{
			x=0;
			c=a+b;
			a=b;
			b=c;
			for(int j=1;j <= c/2;j++)
			{
				if(c % j == 0)
					x++;
			}
			if(x == 1)
				System.out.print(c+"\t");
		}
	}
}
