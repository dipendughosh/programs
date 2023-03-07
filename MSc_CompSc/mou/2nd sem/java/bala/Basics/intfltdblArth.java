//Write a program that will demonstrate arithmetic operations performed with int,float and double values given by user
import java.io.DataInputStream;
class intfltdblArth
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int resulti=0,intNumber1=0,intNumber2=0;
		float resultf=0.0f,floatNumber1=0.0f,floatNumber2=0.0f;
		double resultd=0.0,doubleNumber1=0.0,doubleNumber2=0.0;
		try
		{
			System.out.print("Integer\nEnter Number 1: ");
			intNumber1=Integer.valueOf(in.readLine()).intValue();
			System.out.print("Enter Number 2: ");
			intNumber2=Integer.valueOf(in.readLine()).intValue();
			System.out.print("Float\nEnter Number 1: ");
			floatNumber1=Float.valueOf(in.readLine()).floatValue();
			System.out.print("Enter Number 2: ");
			floatNumber2=Float.valueOf(in.readLine()).floatValue();
			System.out.print("Double\nEnter Number 1: ");
			doubleNumber1=Double.valueOf(in.readLine()).doubleValue();
			System.out.print("Enter Number 2: ");
			doubleNumber2=Double.valueOf(in.readLine()).doubleValue();
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
