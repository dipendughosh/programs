//Write a program that will display modulo value (|x|) of a number taken from the user
import java.io.DataInputStream;
class modulo
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int intNumber=0;
		try
		{
			System.out.print("Enter a Number: ");
			intNumber=Integer.parseInt(in.readLine());
		}
		catch(Exception E)
		{
		}
		System.out.print("| "+intNumber+" | = ");
		if(intNumber < 0)
			intNumber*=(-1);
		System.out.println(intNumber);	
	}
}