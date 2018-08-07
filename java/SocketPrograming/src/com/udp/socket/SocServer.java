package com.udp.socket;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class SocServer {

	public static void main(String[] args) throws Exception {
		
		DatagramSocket ds=new DatagramSocket(9999);
		
		byte[] b1=new byte[1023];
		
		DatagramPacket dp=new DatagramPacket(b1, b1.length);
		ds.receive(dp);
		String str=new String(dp.getData());
		int num=Integer.parseInt(str.trim());
		int result=num*num;
		byte[] b2=String.valueOf(result).getBytes();
		InetAddress ia=InetAddress.getLocalHost();
		DatagramPacket dp1=new DatagramPacket(b2, b2.length,ia,dp.getPort());
		ds.send(dp1);
		
	}

}
