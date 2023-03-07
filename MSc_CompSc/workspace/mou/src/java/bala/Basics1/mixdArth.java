package java.bala.Basics1;
//Write a program to demonstrate the Mixed mode arithmetic operation performed inJAVA
import java.io.DataInputStream;
class mixdArth
{
	public static void main(String argv[])
    {
		DataInputStream in = new DataInputStream(System.in);
		int intNumber=0;
		float floatNumber=0.0f;
		try
		{
			System.out.print("Enter Integer Value: ");
			intNumber=Integer.parseInt(in.readLine());
			System.out.print("Enter Float Value: ");
			floatNumber=Float.valueOf(in.readLine()).floatValue();
			
        }
		catch(Exception E)
		{
		}
		System.out.println("Mixed Mode Arithmetic\n"+intNumber+" * "+floatNumber+" = "+(intNumber*floatNumber)+"\n"+intNumber+" / "+floatNumber+" = "+(intNumber/floatNumber));
	}
}