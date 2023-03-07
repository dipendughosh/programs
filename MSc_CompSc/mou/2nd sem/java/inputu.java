import java.io.DataInputStream;
class inputu
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
		System.out.println("intNumber = "+intNumber);
		System.out.println("floatNumber = "+floatNumber);	
	}
}
