package java.sks.Basics1;
//Write a program to demonstrate the Mixed mode arithmetic operation performed inJAVA
import java.util.Scanner;
class mixdArth
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int intNumber=0;
		float floatNumber=0.0f;
		System.out.print("Enter Integer Value: ");
		intNumber=in.nextInt();
		System.out.print("Enter Float Value: ");
		floatNumber=in.nextFloat();
		System.out.println("Mixed Mode Arithmetic\n"+intNumber+" * "+floatNumber+" = "+(intNumber*floatNumber)+"\n"+intNumber+" / "+floatNumber+" = "+(intNumber/floatNumber));
	}
}