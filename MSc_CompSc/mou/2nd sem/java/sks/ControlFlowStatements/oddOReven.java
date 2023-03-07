//Write a program to check whether a number is even or odd.Put proper restrictions on the values given by the user
import java.util.Scanner;
class oddOReven
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int intNumber=0,f=1;
		do
		{
			if(f == 0)
				System.out.println("Wrong Entry:-ReEnter ");
			System.out.print("Enter a Positive Number: ");
			intNumber=in.nextInt();
			f=0;
		}while(intNumber <= 0);
		if(intNumber % 2 == 0)
			System.out.println(intNumber+" is Even");
		else
			System.out.println(intNumber+" is Odd");
	}
}
