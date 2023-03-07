package java.sks.ControlFlowStatements1;
//Write a program that will take two numbers from the user and check whether they are Amicable numbers or not
import java.util.Scanner;
class amicablNo
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int intNumber1=0,intNumber2=0,div1=0,div2=0,n=0;
		System.out.print("Enter Number 1: ");
		intNumber1=in.nextInt();
		System.out.print("Enter Number 2: ");
		intNumber2=in.nextInt();
		n=intNumber1;
		for(int i=1;i<=n/2;i++)
		{		
			if(n % i == 0)
				div1=div1+i;
		}
		n=intNumber2;
		for(int i=1;i<=n/2;i++)
		{		
			if(n % i == 0)
				div2=div2+i;
		}
		if(intNumber1 == div2 && intNumber2 == div1)
			System.out.println(intNumber1+" and "+intNumber2+" are Amicable Numbers");
		else
			System.out.println(intNumber1+" and "+intNumber2+" are Not Amicable Numbers");
	}
}
