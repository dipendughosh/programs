package test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class jdbc_con 
{

	public static void main(String[] args) throws Exception
	{
		Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "goblin");
		System.out.println("Connected.....");
		
		Statement st = con.createStatement();
		ResultSet rs = st.executeQuery("select * from marks");
		System.out.println("queried.....");
		
		while(rs.next())
		{
			System.out.println(rs.getObject("a")+" "+rs.getObject("b"));
		}

		st.close();
		rs.close();
		con.close();
	}

}
