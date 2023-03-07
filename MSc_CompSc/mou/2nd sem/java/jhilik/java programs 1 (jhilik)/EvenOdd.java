import java.util.Scanner;
public class EvenOdd
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int number;
		System.out.println("Enter the number");
		number=input.nextInt();
		if(number%2==0)
		System.out.println("The number is even");
		else
		System.out.println("The number is odd");
	}
} 
		