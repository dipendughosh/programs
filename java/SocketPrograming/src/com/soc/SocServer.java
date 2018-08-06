package com.soc;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class SocServer {

	public static void main(String[] args) throws Exception {
		
		System.out.println("S : Server Started");
		ServerSocket ss=new ServerSocket(9999);
		
		System.out.println("S : Server is waiting for Client");
		Socket s=ss.accept();
		
		System.out.println("S : Client Connected");
		
		BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
		String str=br.readLine();
		
		System.out.println("S : Client Data : "+str);	

		String str1=str.substring(0, 3);
		
		OutputStreamWriter os=new OutputStreamWriter(s.getOutputStream());
		PrintWriter out=new PrintWriter(os);
		out.println(str1);
		out.flush();
		
		System.out.println("S : Data Sent");	
		
		out.close();
		os.close();
		br.close();
		s.close();
		ss.close();
	}

}
