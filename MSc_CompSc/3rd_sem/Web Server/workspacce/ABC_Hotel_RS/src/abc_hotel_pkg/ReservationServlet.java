package abc_hotel_pkg;

import java.io.IOException;
import java.io.PrintWriter;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class ReservationServlet extends HttpServlet 
{
	private static final long serialVersionUID = 1L;

	/** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException 
    {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try
        {
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Customer Reservation</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<center><h1>ABC Hotel System</h1></center>");
            out.println("<br><h3>Records Inserted Successfully</h3>");
            out.println("<br><center><h3><a href='index.html'>Home</a></h3></center>");
            out.println("</body>");
            out.println("</html>");
            
        }
        finally
        { 
            out.close();
        }
    } 

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
    protected void doPost(HttpServletRequest request, HttpServletResponse response)throws ServletException, IOException
    {
        Connection con;
        Statement s1;

        String Cname = request.getParameter("Cname").toString();
        String CINDate = request.getParameter("CINDate").toString();
        String COUTDate = request.getParameter("COUTDate").toString();
        String RoomNo =  request.getParameter("RoomNo").toString();
        String Add = request.getParameter("Add").toString();
        String RS_ID = Cname + RoomNo ;
        String CUST_ID = Cname + RoomNo ;

        try
        {
        	Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/ABCHotel", "root", "goblin");
            s1 = con.createStatement();

            String s="insert into RESERVATION values('" + RS_ID + "','" + CINDate + "','" + COUTDate + "','" + RoomNo + "')";
            String S1=" insert into CUSTOMER values ('" + CUST_ID + "','" + Cname + "','" + Add + "','" + RS_ID + "')";
            String S2="Update Rooms SET RESERVED=1 where ROOM_NO='" + RoomNo +"'";

            s1.executeUpdate(s);
            s1.executeUpdate(S1);
            s1.executeUpdate(S2);
        }
        catch(ClassNotFoundException e)
        {
			System.out.println(e);
		}
		catch(SQLException e){
			System.out.println(e);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
        processRequest(request, response);
    }
}
