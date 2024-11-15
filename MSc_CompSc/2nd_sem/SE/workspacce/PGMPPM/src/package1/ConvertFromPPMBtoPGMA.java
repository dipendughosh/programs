package package1;

	import java.io.BufferedReader;
	import java.io.BufferedWriter;
	import java.io.FileReader;
	import java.io.FileWriter;
	import java.io.IOException;

public class ConvertFromPPMBtoPGMA {

	private static final long serialVersionUID = 1L;
		
	private BufferedReader bin;
	private BufferedWriter bout;
	
	public ConvertFromPPMBtoPGMA()
	{
	}
	
	public static void main(String[] args) 
	{
		ConvertFromPPMBtoPGMA ob = new ConvertFromPPMBtoPGMA ();
		ob.openFiles();
		ob.readwrite();
		ob.closeFile();
	}

	private void closeFile()
	{
		try
		{
			bin.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		try 
		{
			bout.close();
		}
		catch (IOException e)
		{
		e.printStackTrace();
		}
	}
		
	private void readwrite()
	{
		int i = 0;
		int len = 0;
		int lineCntr = 0;
		int charCntr = 0;
		int flag = 0;
		int x = 159;
		int y = 27;
		char s = 0;
		String strLine;
		String temp = null;
		System.out.println("START");
	
		try 
		{
			while (true)  
			{
				strLine = bin.readLine();
				if(strLine == null)
					break;
				
				if(flag == 0)
				{
					if(strLine.equals("p6") || strLine.equals("P6"))
					{
						strLine="P3";
					}
					
					bout.write(strLine);
					bout.newLine();
					if(strLine.equals("255"))
					{
						flag = 1;
					}
				}
				else if(flag == 1)
				{
					temp = null;
					len=strLine.length();
					for(i=0;i<len;i++)
					{
						charCntr++;
						s=strLine.charAt(i);
						if(temp == null)
							temp=""+(int)s;
						else
							/*if((int)s > 255)
								temp=temp+" "+(int)chck((int)s);
							else*/
								temp=temp+" "+(int)s;
						if(lineCntr == x)
						{
							if(charCntr == 49)
							{
								bout.write(temp);
								bout.newLine();
								charCntr = 0;
								lineCntr = 0;
								x=158;
								temp=null;
							}
						}
						else if(lineCntr < x)
						{
							if(charCntr == y)
							{
								bout.write(temp);
								bout.newLine();
								charCntr = 0;
								lineCntr++;
								y=24;
								temp=null;
							}
						}
					}
					
				}
			}	
		}
		catch (IOException e2) 
		{
			e2.printStackTrace();
		}	
		System.out.println("Finish");
	}

	private char chck(int s) 
	{
		switch(s)
		{
			case 732:
				return 152;
			case 8255:
				return 132;
			case 8364:
				return 128;
			case 8230:
				return 133;
			case 8221:
				return 148;
			case 8216:
				return 145;
			case 710:
				return 136;
			case 8211:
				return 150;
			case 8250:
				return 155;
			case 65533:
				return 129;
			case 8212:
				return 151;
			case 376:
				return 159;
			case 353:
				return 154;
			case 402:
				return 131;
			case 8220:
				return 147;
			case 339:
				return 156;
			case 8240:
				return 137;
			case 8217:
				return 146;
		}
		return 0;
	}

	private void openFiles()
	{
		try 
		{
			bin = new BufferedReader(new FileReader("C:\\images\\MATLAB Screenshot(b).ppm"));
		}
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		try 
		{
			bout = new BufferedWriter(new FileWriter("C:\\images\\MATLAB Screenshot(ba).ppm"));
		}
		catch (IOException e) 
		{
			e.printStackTrace();
		}
		
	}
}


