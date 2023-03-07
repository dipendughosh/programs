//Write a menu driven program that will perform arithmetic operation on two numbers
import java.util.Scanner;
class menu
{
	public static void main(String argv[])
    {
		Scanner in = new Scanner(System.in);
		int resulti=0,intNumber1=0,intNumber2=0,c=0,cc=0;
		float resultf=0,floatNumber1=0.0f,floatNumber2=0.0f;
		System.out.println("\tMENU");
		System.out.println("1.Integer");
		System.out.println("2.Float");
		System.out.print("Enter Choice :- ");
		c=in.nextInt();;
		switch(c)
		{	
			case 1:	
				System.out.print("Enter Number 1: ");
				intNumber1=in.nextInt();
				System.out.print("Enter Number 2: ");
				intNumber2=in.nextInt();
				System.out.println("\tINTEGER-MENU");
				System.out.println("1.ADDITION");
				System.out.println("2.SUBTRACTION");
				System.out.println("3.MULTIPLICATION");
				System.out.println("4.DIVISION");
				System.out.print("Enter Choice :- ");
				cc=in.nextInt();
				switch(cc)
				{
					case 1:
						resulti=intNumber1+intNumber2;
						System.out.println("ADDITION:----\n"+intNumber1+" + "+intNumber2+" = "+resulti);
						break;
					case 2:
						resulti=intNumber1-intNumber2;
						System.out.println("SUBTRACTION:----\n"+intNumber1+" - "+intNumber2+" = "+resulti);
						break;
					case 3:
						resulti=intNumber1*intNumber2;
						System.out.println("MULTIPLITION:----\n"+intNumber1+" * "+intNumber2+" = "+resulti);
						break;
					case 4:
						resulti=intNumber1/intNumber2;
						System.out.println("DIVISION:----\n"+intNumber1+" / "+intNumber2+" = "+resulti);
						break;
					default:
						System.out.println("Wrong Input Int");
						break;
				}
				break;
			case 2:
				System.out.print("Enter Number 1: ");
				floatNumber1=in.nextFloat();
				System.out.print("Enter Number 2: ");
				floatNumber2=in.nextFloat();
				System.out.println("\tFLOAT-MENU");
				System.out.println("1.ADDITION");
				System.out.println("2.SUBTRACTION");
				System.out.println("3.MULTIPLICATION");
				System.out.println("4.DIVISION");
				System.out.print("Enter Choice :- ");
				cc=in.nextInt();
				switch(cc)
				{
					case 1:
						resultf=floatNumber1+floatNumber2;
						System.out.println("ADDITION:----\n"+floatNumber1+" + "+floatNumber2+" = "+resultf);
						break;
					case 2:
						resultf=floatNumber1-floatNumber2;
						System.out.println("SUBTRACTION:----\n"+floatNumber1+" - "+floatNumber2+" = "+resultf);
						break;
					case 3:
						resultf=floatNumber1*floatNumber2;
						System.out.println("MULTIPLITION:----\n"+floatNumber1+" * "+floatNumber2+" = "+resultf);
						break;
					case 4:
						resultf=floatNumber1/floatNumber2;
						System.out.println("DIVISION:----\n"+floatNumber1+" / "+floatNumber2+" = "+resultf);
						break;
					default:
						System.out.println("Wrong Input Float");
						break;
				}
				break;
			default:
				System.out.println("Wrong Input");
				break;
		}
	}
}
