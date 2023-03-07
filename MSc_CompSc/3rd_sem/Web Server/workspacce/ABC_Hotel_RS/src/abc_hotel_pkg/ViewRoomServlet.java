package abc_hotel_pkg;

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


public class ViewRoomServlet extends HttpServlet
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
        Statement s1;
        ResultSet records;
        String s3,s4;

        try
        {
        	 Class.forName("com.mysql.jdbc.Driver");
             con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ABCHotel", "root", "goblin");
             s1 = con.createStatement();
             String s="select * from rooms";
             records =s1.executeQuery(s);

             out.println("<HTML><HEAD><TITLE>Room List</TITLE></HEAD>");
             out.println("<BODY>");
             out.println("<center><h1>ABC Hotel Reservation System</h1></center><br>");
             out.println("<center><h2>Room List</h2></center><br><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>ROOM NO</td><td>AC/NON-AC</td><td>NUMBER OF BEDS</td><td>RESERVED</td>");
             out.println("</tr>");

             while (records.next())
             {
            	 s3=records.getString("AC_NONAC");
            	 s4=records.getString("RESERVED");

            	 if(s3.equals("4"))
            	 {
            		 s3="AC";
            	 }
            	 else
            	 {
            		 s3="NON-AC";
            	 }

            	 if(s4.equals("0"))
            	 {
            		 s4="NO";
            	 }
            	 else
            	 {
            		 s4="YES";
            	 }

            	 out.println("<tr>");
            	 out.println("<td>"+records.getString("ROOM_NO")+"</td><td>" + s3 +"</td><td>"+records.getString("NO_OF_BEDS")+"</td><td>"+ s4 + "</td>");
            	 out.println("</tr>");
             }

             out.println("</table><br>");
             out.println("<center><a href='index.html'><h3>Home</h3></a></center>");
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
