//Write a program to to demonstrate the Integer arithmetic operations performed in JAVA
import java.io.DataInputStream;
class intArth
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int resulti=0,intNumber1=0,intNumber2=0;
		try
		{
			System.out.print("Integer\nEnter Number 1: ");
			//intNumber1=Integer.valueOf(in.readLine()).intValue();
			intNumber1=Integer.parseInt(in.readLine());
			System.out.print("Enter Number 2: ");
			intNumber2=Integer.parseInt(in.readLine());
		}
		catch(Exception e)
		{
		}
		resulti=intNumber1+intNumber2;
		System.out.println("Integer-------\n"+intNumber1+" + "+intNumber2+" = "+resulti);
		resulti=intNumber1-intNumber2;
		System.out.println(intNumber1+" - "+intNumber2+" = "+resulti);
		resulti=intNumber1*intNumber2;
		System.out.println(intNumber1+" * "+intNumber2+" = "+resulti);
		resulti=intNumber1/intNumber2;
		System.out.println(intNumber1+" / "+intNumber2+" = "+resulti);
	}
}
