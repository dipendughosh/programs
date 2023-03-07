//Write a program that will find sum of all the positive integers upto a specified range
import java.util.Scanner;
class intRange
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int i=0,n=0,s=0;
		do
		{
			System.out.print("Enter Range(Positive Integer): ");
			n=in.nextInt();
		}while(n <= 0);
		System.out.println("Intergers upto "+n+" are:-");
		for(i=1;i<=n;i++)
			s=s+i;
		System.out.print("sum till "+i+" = "+s);
	}
}
