package java.sks.ControlFlowStatements1;
//Write a program that will display modulo value (|x|) of a number taken from the user
import java.util.Scanner;
class modulo
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int intNumber=0;
		System.out.print("Enter a Number: ");
		intNumber=in.nextInt();
		System.out.print("| "+intNumber+" | = ");
		if(intNumber < 0)
			intNumber*=(-1);
		System.out.println(intNumber);	
	}
}