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
public class AddRoomServlet extends HttpServlet {
   
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
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Add Room</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<center><h2>Room Added Successfully</h2><br><a href ='index.jsp'>Home</a></center>");
            out.println("<center><h3><a href ='index.jsp'>Home</a></h3></center>");
            out.println("</body>");
            out.println("</html>");
            
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
    throws ServletException, IOException {
        processRequest(request, response);
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
    throws ServletException, IOException
    {
        PrintWriter out = response.getWriter();
        Connection con;
	Statement s1;
        ResultSet records;
        int n;

        String RoomNo= request.getParameter("RoomNo").toString();
        String BedType = request.getParameter("bed").toString();
        String Facility = request.getParameter("facility").toString();
        String Avail= request.getParameter("Avail").toString();
        RoomNo = RoomNo + BedType + Facility ;
        

        try
        {
             Class.forName("org.apache.derby.jdbc.ClientDriver");
             con = DriverManager.getConnection("jdbc:derby://localhost:1527/ABChotel", "ishan", "ishan");
             s1 = con.createStatement();

             String s="insert into App.Rooms values('" + RoomNo + "'," + Facility + "," + BedType + "," + Avail + ")";
             n=s1.executeUpdate(s);
             processRequest(request, response);
        }
        catch(ClassNotFoundException e){
			System.out.println(e);
		}
		catch(SQLException e){
			System.out.println(e);
                        out.println("<html>");
                        out.println("<head>");
                        out.println("<title>Add Room Error</title>");
                        out.println("</head>");
                        out.println("<body>");
                        out.println("<center><h1>ABC Hotel Reservation System</h1></center>");
                        out.println("<br><center><h2>Add Rooms Error</h2></center>");
                        out.println("<center><textarea rows='5' cols='50'>" + e + "</textarea></center>");
                        out.println("<center><h3>Please Try Again</h3></center>");
                        out.println("<br><center><h4><a href = 'AddRoom.jsp'>Back</a></h4></center>");
                        out.println("</body>");
                        out.println("</html>");
		}
		catch(Exception e){
			System.out.println(e);
		}        

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
