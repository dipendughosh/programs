/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ABC_hotel_pkg;

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

/**
 *
 * @author Ishan Mukherjee
 */
public class ViewRESERVElistServlet extends HttpServlet {
   
    /** 
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        try {
            /* TODO output your page here
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet ViewRESERVElistServlet</title>");  
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet ViewRESERVElistServlet at " + request.getContextPath () + "</h1>");
            out.println("</body>");
            out.println("</html>");
            */
        } finally { 
            out.close();
        }
    } 

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /** 
     * Handles the HTTP <code>GET</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException
    {
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        Connection con;
        Statement s1;
        ResultSet records;
        int n;

        try
        {
             Class.forName("org.apache.derby.jdbc.ClientDriver");
             con = DriverManager.getConnection("jdbc:derby://localhost:1527/ABChotel", "ishan", "ishan");
             s1 = con.createStatement();
             String s="Select CUST_ID,NAME,ADDRESS,App.RESERVATION.RS_ID as RSV_ID,DT_OF_CHECKIN,DT_OF_CHECKOUT,ROOM_NO from App.CUSTOMER,App.RESERVATION where App.CUSTOMER.RS_ID=App.RESERVATION.RS_ID";
             records =s1.executeQuery(s);

             out.println("<HTML><HEAD><TITLE>Products</TITLE></HEAD>");
             out.println("<BODY>");
             out.println("<center><h1>ABC Hotel Reservation System</h1></center><br>");
             out.println("<center><h2>Reservation List</h2></center><br><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>CUST_ID</td><td>NAME</td><td>ADDRESS</td><td>RESERVATION ID</td><td>DT_OF_CHECKIN</td><td>DT_OF_CHECKOUT</td><td>ROOM_NO</td>");
             out.println("</tr>");



      while (records.next())
      {

        out.println("<tr>");        
        out.println("<td>"+records.getString("CUST_ID")+"</td><td>" + records.getString("NAME") +"</td><td>"+ records.getString("ADDRESS") +"</td><td>"+ records.getString("RSV_ID")+"</td><td>"+records.getString("DT_OF_CHECKIN")+ "</td><td>"+records.getString("DT_OF_CHECKOUT")+"</td><td>" +  records.getString("ROOM_NO")+"</td>");
        out.println("</tr>");
      }

      out.println("</table><br>");
      out.println("<br>");
      out.println("<center><a href='index.jsp'><h3>Home</h3></a></center>");
      out.println("</BODY></HTML>");


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
    //    processRequest(request, response);
    } 

    /** 
     * Handles the HTTP <code>POST</code> method.
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
    throws ServletException, IOException {
        processRequest(request, response);
    }

    /** 
     * Returns a short description of the servlet.
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
