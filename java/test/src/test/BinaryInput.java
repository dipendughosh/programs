package test;

import java.io.DataInputStream;
import java.io.EOFException;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class BinaryInput {

	static String fileName = "stu.txt" ;
	
	public static void main(String[] args) {
		
		boolean EOF = false ;
	
		try {
			FileInputStream fr = new FileInputStream(fileName) ;
			DataInputStream dr = new DataInputStream(fr) ;
			
			while ( !EOF ) {
			
				try {
					int rno ;
					float marks ;
					rno = dr.readInt() ;
					System.out.println("Rollno : " + rno) ;
					marks = dr.readFloat() ;
					System.out.println("Marks : " + marks) ;
				}
				catch ( EOFException e ) {
					System.out.println("end of file") ;
					EOF = true ;
				}
				catch ( IOException e ) {
					System.err.println(e) ;
				}
			}
		}
		catch ( FileNotFoundException e ) {
			System.out.println("File not found") ;
		}
	}
}
