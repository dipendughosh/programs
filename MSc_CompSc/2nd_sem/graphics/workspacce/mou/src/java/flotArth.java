//Write a program to to demonstrate the Float arithmetic operations performed in JAVA
package java;
import java.io.DataInputStream;
class flotArth
{
	public static void main(String args[])
    {
		DataInputStream in = new DataInputStream(System.in);
		float resultf=0.0f,floatNumber1=0.0f,floatNumber2=0.0f;
		try
		{
			System.out.print("Float\nEnter Number 1: ");
			String x = in.readLine();
			floatNumber1=Float.parseFloat(x);
			
			System.out.print("Enter Number 2: ");
			floatNumber2=Float.parseFloat(x);
		}
		catch(Exception e)
		{
		}
		resultf=floatNumber1+floatNumber2;
		System.out.println("Float-------\n"+floatNumber1+" + "+floatNumber2+" = "+resultf);
		resultf=floatNumber1-floatNumber2;
		System.out.println(floatNumber1+" - "+floatNumber2+" = "+resultf);
		resultf=floatNumber1*floatNumber2;
		System.out.println(floatNumber1+" * "+floatNumber2+" = "+resultf);
		resultf=floatNumber1/floatNumber2;
		System.out.println(floatNumber1+" / "+floatNumber2+" = "+resultf);
	}
}
