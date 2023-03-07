import java.util.Scanner;
public class ArithOp
{
	public static void main(String args[])
	{
		Scanner input = new Scanner(System.in);
		int number1,number2,choice,result;
		System.out.println("Enter the number1");
		System.out.println("Enter the number2");
		number1=input.nextInt();
		number2=input.nextInt();
		System.out.println("Press 1:Adition Press2: Subtraction Press 3: Multiplication Press 4: Division");
		System.out.println("Enter proper choice");
		choice=input.nextInt();
		switch(choice)
		{
		case 1: 
		{
		result=number1+number2;
		System.out.println("The result is:"+result);
		break;
		}
		case 2:
		{
		result=number1-number2;
		System.out.println("The result is:"+result);
		break; 
		}
		case 3:
		{
		result=number1*number2;
		System.out.println("The result is:"+result);
		break;
		}
		case 4:
		{
		result=number1/number2;
		System.out.println("The result is:"+result);
		break;
		}
		default:
		System.out.println("Enter proper choice");
		}
	}
}
		