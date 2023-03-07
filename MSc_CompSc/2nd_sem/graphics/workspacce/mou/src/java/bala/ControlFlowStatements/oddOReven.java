//Write a program to check whether a number is even or odd.Put proper restrictions on the values given by the user
import java.io.DataInputStream;
class oddOReven
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int intNumber=0,f=1;
		try
		{
			do
			{
				if(f == 0)
					System.out.println("Wrong Entry:-ReEnter ");
				System.out.print("Enter a Positive Number: ");
				intNumber=Integer.parseInt(in.readLine());
				f=0;
			}while(intNumber <= 0);
		}
		catch(Exception E)
		{
		}
		if(intNumber % 2 == 0)
			System.out.println(intNumber+" is Even");
		else
			System.out.println(intNumber+" is Odd");
	}
}
