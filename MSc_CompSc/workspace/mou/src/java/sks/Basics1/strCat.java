package java.sks.Basics1;
//Write a program that will perform concatenation of two strings
import java.io.DataInputStream;
class strCat
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		String str1="",str2="";
		try
		{
			System.out.print("Enter a string1 : ");
			str1=in.readLine();
			System.out.print("Enter a string2 : ");
			str2=in.readLine();
		}
		catch(Exception E)
		{
		}
		System.out.println("After concatenation:-\n"+str1+" "+str2);
	}
}
