package library_system_pkg;

import java.io.IOException;
import java.io.PrintWriter;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class CheckRecordsServlet extends HttpServlet 
{
	private static final long serialVersionUID = 1L;

    /** 
     * Handles the HTTP <code>GET</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
    {
		doPost(request, response);
    } 

    /** 
     * Handles the HTTP <code>POST</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
    {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        Connection con;
        Statement stmnt1;
        ResultSet rs1,rs2;

        String dt= request.getParameter("Edate").toString();
        String s1="select * from checkout where borrow_date='"+dt+"'";
        String s2="select * from checkout where return_date='"+dt+"'";

        try
        {
             Class.forName("com.mysql.jdbc.Driver");
             con = DriverManager.getConnection("jdbc:mysql://localhost:3306/LibrarySystem", "root", "goblin");
             stmnt1 = con.createStatement();
             rs1=stmnt1.executeQuery(s1);

             out.println("<HTML><HEAD><TITLE>View Status</TITLE></HEAD>");
             out.println("<BODY>");
             out.println("<center><h1>Library Management System</h1></center><br>");
             out.println("<center><h2>Resources Borrowed Results</h2></center><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>C_ID</td><td>MEMBER_ID</td><td>RESOURCE_ID</td><td>BORROW_DATE</td><td>RETURN_DATE</td>");
             out.println("</tr>");

             while(rs1.next())
             {
                out.println("<tr>");
                out.println("<td>"+rs1.getString("C_ID")+"</td><td>"+rs1.getString("MEMBER_ID")+"</td><td>" +rs1.getString("RESOURCEID")+"</td><td>"+ rs1.getString("BORROW_DATE")+"</td><td>"+rs1.getString("RETURN_DATE")+"</td>");
                out.println("</tr>");
             }
             out.println("</table><br><hr><br>");              

             rs2=stmnt1.executeQuery(s2);
             out.println("<center><h2>Resources Returned Results</h2></center><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>C_ID</td><td>MEMBER_ID</td><td>RESOURCE_ID</td><td>BORROW_DATE</td><td>RETURN_DATE</td>");
             out.println("</tr>");

             while(rs2.next())
             {
                out.println("<tr>");
                out.println("<td>"+rs2.getString("C_ID")+"</td><td>"+rs2.getString("MEMBER_ID")+"</td><td>" +rs2.getString("RESOURCEID")+"</td><td>"+ rs2.getString("BORROW_DATE")+"</td><td>"+rs2.getString("RETURN_DATE")+"</td>");
                out.println("</tr>");
             }
             out.println("</table><br><hr><br>");              
             out.println("<br /><center><h4><a href = 'index.html'>Home</a></h4></center>");
             out.println("</BODY></HTML>");

        }
        catch(ClassNotFoundException e)
        {
			System.out.println(e);
		}
		catch(SQLException e)
		{
			System.out.println(e);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}        
    }
}
