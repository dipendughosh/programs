package servelets;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.ServletResponse;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;


public class serveletCls extends HttpServlet
{
	private static final long serialVersionUID = 1L;

	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)throws ServletException, IOException 
	{
		doPost(req, resp);
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)throws ServletException, IOException 
	{
		
    try
    {
    	Class.forName("com.mysql.jdbc.Driver");
		Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/test", "root", "goblin");
		System.out.println("Connected.....");
		
		Statement s1 = con.createStatement();
		String s="insert into marks values(98,'oiuy')";
        s1.executeUpdate(s);
        s1.close();
		Statement st = con.createStatement();
		ResultSet rs = st.executeQuery("select * from marks");
		System.out.println("queried.....");
		
		
		PrintWriter writer = resp.getWriter();
		writer.println("<html><body>");
		while(rs.next())
		{
			
			writer.println("<table><tr><td>"+rs.getObject("a")+"</td><td>"+rs.getObject("b")+"</td></tr></table>");
		}
		writer.println("</body></html>");
		st.close();
		rs.close();
		con.close();
    }
    catch(ClassNotFoundException e){
		System.out.println(e);
	}
	catch(SQLException e){
		System.out.println(e);
                   
	}
	catch(Exception e){
		System.out.println(e);
	}   
		//PrintWriter writer = resp.getWriter();
		//writer.println("<html><body>");
		//writer.println("<table><tr><td>tttt</td><td>tttt2</td></tr><tr><td>tttt</td><td>tttt2</td></tr></table></body></html>");
	}
}

