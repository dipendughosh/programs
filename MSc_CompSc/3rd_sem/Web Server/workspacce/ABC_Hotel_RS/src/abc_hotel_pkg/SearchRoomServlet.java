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

public class SearchRoomServlet extends HttpServlet 
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
    	doPost(request,response);
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
        String AC_NONAC=request.getParameter("facility");
        String NO_OF_BEDS=request.getParameter("bed");
        String s3,s4;
     
        try
        {
        	 Class.forName("com.mysql.jdbc.Driver");
        	 con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ABCHotel", "root", "goblin");
             s1 = con.createStatement();
             String s="select * from rooms where AC_NONAC='" + AC_NONAC + "' and NO_OF_BEDS='" + NO_OF_BEDS + "' and RESERVED='0'";
             records =s1.executeQuery(s);

             out.println("<HTML><HEAD><TITLE>Products</TITLE></HEAD>");
             out.println("<BODY>");
             out.println("<center><h1>ABC Hotel Reservation System</h1></center><br>");
             out.println("<center><h2>Customer Enquiry Results</h2></center><br>");
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
             out.println("<center><h2>Customer Registration Form</h2></center><br>");
             out.println("<form name='ReservationFrm' id='ReservationFrmId' action='ReservationServlet' method='POST' ");
             out.println("<table align='center' border='1'>");
             out.println("<tr><td>Name</td><td><input type='text' name='Cname' /></td></tr>");
             out.println("<tr><td>Address</td><td><input type='text' name='Add' /></td></tr>");
             out.println("<tr><td>Date Of Check In(YYYY-MM-DD)</td><td><input type='text' name='CINDate' /></td></tr>");
             out.println("<tr><td>Date Of Check Out(YYYY-MM-DD)</td><td><input type='text' name='COUTDate' /></td></tr>");
             out.println("<tr><td>Room No</td><td><input type='text' name='RoomNo' /></td></tr>");
             out.println("<tr><td colspan='2'><center><input type='submit' value='register' /><center></td></tr>");
             out.println("</table>");
             out.println("<br>");
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
