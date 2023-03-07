//Write a program that will demonstrate initialization of string by user input
import java.io.DataInputStream;
class strUserIn
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		String str="";
		try
		{
			System.out.println("Enter a string: ");
			str=in.readLine();
		}
		catch(Exception E)
		{
		}
		System.out.println("Read string = "+str);
	}
}