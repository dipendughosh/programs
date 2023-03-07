import java.util.Scanner;

public class BoolDemo
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int number1,number2;
		System.out.println("Enter number1");
		System.out.println("Enter number2");
		number1 = input.nextInt();
		number2 = input.nextInt();
		boolean b;
		b=true;
		System.out.println("b is now:" +b);
		if(b)
		System.out.println("Execute this");
		b=false;
		System.out.println("b is now: "+b);
		if(b)
		System.out.println("Do not Execute this");
		if(number1>number2)
		System.out.println("number1>number2 is " +(number1>number2));
		if(number1<number2)
		System.out.println("number1<number2 is "+(number1<number2));
	}
}		
		
