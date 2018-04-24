package test;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;

public class BinaryOutput {

	static String fileName = "stu.txt" ;
	static InputStreamReader isr = new InputStreamReader(System.in) ;
	static BufferedReader stdin = new BufferedReader(isr) ;
	
	public static void main(String[] args) {
	
		try {
			int rno ;
			float marks ;
			FileOutputStream fw = new FileOutputStream(fileName) ;
			DataOutputStream dw = new DataOutputStream(fw) ;
			
			for ( int i = 0 ; i < 5 ; i++ ) {
				System.out.print("Enter Rollno : ") ;
				rno = Integer.parseInt(stdin.readLine()) ;
				System.out.print("Enter Marks : ") ;
				marks = Float.parseFloat(stdin.readLine()) ;
				dw.writeInt(rno) ;
				dw.writeFloat(marks) ;
			}
			dw.close() ;
			fw.close() ;
		}
		catch ( IOException e ) {
			System.err.println(e) ;
		}
	}
}
