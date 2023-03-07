import java.util.Scanner;

public class Mod
	{
		public static void main(String args[])
		{
			Scanner input = new Scanner(System.in);
			int number,x;
			System.out.println("Enter the number");
			number=input.nextInt();
			if(number<0)
			{
			x=number*-1;
			System.out.println("The absolute value of the number is:"+x);
			}
			else
			{
			System.out.println("The absolute value of the number is:"+number);
			}
		}
	}