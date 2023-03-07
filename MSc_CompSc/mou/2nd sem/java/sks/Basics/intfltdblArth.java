//Write a program that will demonstrate arithmetic operations performed with int,float and double values given by user
import java.util.Scanner;
class intfltdblArth
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int resulti=0,intNumber1=0,intNumber2=0;
		float resultf=0.0f,floatNumber1=0.0f,floatNumber2=0.0f;
		double resultd=0.0,doubleNumber1=0.0,doubleNumber2=0.0;
		System.out.print("Integer\nEnter Number 1: ");
		intNumber1=in.nextInt();
		System.out.print("Enter Number 2: ");
		intNumber2=in.nextInt();
		System.out.print("Float\nEnter Number 1: ");
		floatNumber1=in.nextFloat();
		System.out.print("Enter Number 2: ");
		floatNumber2=in.nextFloat();
		System.out.print("Double\nEnter Number 1: ");
		doubleNumber1=in.nextDouble();
		System.out.print("Enter Number 2: ");
		doubleNumber2=in.nextDouble();
		
		resulti=intNumber1+intNumber2;
		System.out.println("Integer-------\n"+intNumber1+" + "+intNumber2+" = "+resulti);
		resulti=intNumber1-intNumber2;
		System.out.println(intNumber1+" - "+intNumber2+" = "+resulti);
		resulti=intNumber1*intNumber2;
		System.out.println(intNumber1+" * "+intNumber2+" = "+resulti);
		resulti=intNumber1/intNumber2;
		System.out.println(intNumber1+" / "+intNumber2+" = "+resulti);
		
		resultf=floatNumber1+floatNumber2;
		System.out.println("Float-------\n"+floatNumber1+" + "+floatNumber2+" = "+resultf);
		resultf=floatNumber1-floatNumber2;
		System.out.println(floatNumber1+" - "+floatNumber2+" = "+resultf);
		resultf=floatNumber1*floatNumber2;
		System.out.println(floatNumber1+" * "+floatNumber2+" = "+resultf);
		resultf=floatNumber1/floatNumber2;
		System.out.println(floatNumber1+" / "+floatNumber2+" = "+resultf);
		
		resultd=doubleNumber1+doubleNumber2;
		System.out.println("Double-------\n"+doubleNumber1+" + "+doubleNumber2+" = "+resultd);
		resultd=doubleNumber1-doubleNumber2;
		System.out.println(doubleNumber1+" - "+doubleNumber2+" = "+resultd);
		resultd=doubleNumber1*doubleNumber2;
		System.out.println(doubleNumber1+" * "+doubleNumber2+" = "+resultd);
		resultd=doubleNumber1/doubleNumber2;
		System.out.println(doubleNumber1+" / "+doubleNumber2+" = "+resultd);
	}
}
