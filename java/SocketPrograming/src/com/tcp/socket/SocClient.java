package com.tcp.socket;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.Socket;

public class SocClient {

	public static void main(String[] args) throws Exception {

		String ip="localhost";
		int port=9999;
		Socket s=new Socket(ip,port);
		
		String str="Dipendu Ghosh";
		
		OutputStreamWriter os=new OutputStreamWriter(s.getOutputStream());
		PrintWriter out=new PrintWriter(os);
		out.println(str);
		out.flush();
		
		BufferedReader br=new BufferedReader(new InputStreamReader(s.getInputStream()));
		String str1=br.readLine();
		
		System.out.println("C : Server Data : "+str1);
		
		br.close();
		out.close();
		os.close();
		s.close();
	}

}
