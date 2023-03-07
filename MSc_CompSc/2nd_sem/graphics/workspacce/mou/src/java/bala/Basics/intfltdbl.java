//Write a program that will take int,float and double values given by user and display them
import java.io.DataInputStream;
class intfltdbl
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int intNumber=0;
		float floatNumber=0.0f;
		double doubleNumber=0.0;
		try
		{
			System.out.print("Enter Integer Value: ");
			//intNumber=Integer.parseInt(in.readLine());
			intNumber=Integer.valueOf(in.readLine()).intValue();
			System.out.print("Enter Float Value: ");
			floatNumber=Float.valueOf(in.readLine()).floatValue();
			System.out.print("Enter Double Value: ");
			doubleNumber=Double.valueOf(in.readLine()).doubleValue();			
        }
		catch(Exception E)
		{
		}
		System.out.println("intNumber = "+intNumber);
		System.out.println("floatNumber = "+floatNumber);	
		System.out.println("doubleNumber = "+doubleNumber);	
	}
}