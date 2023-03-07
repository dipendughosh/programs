package com;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;



public class Test {

	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "test", "test123");
		System.out.println("Connected.....");
		
		Statement st = con.createStatement();
		ResultSet rs = st.executeQuery("select * from marks");
		System.out.println("queried.....");
		
		while(rs.next()){
			System.out.println(rs.getObject("Name"));
		}
		
		con.close();
	}

}
