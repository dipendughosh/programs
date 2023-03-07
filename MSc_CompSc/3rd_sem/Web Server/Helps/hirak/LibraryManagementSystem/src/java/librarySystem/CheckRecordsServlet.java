/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package librarySystem;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author Ishan Mukherjee
 */
public class CheckRecordsServlet extends HttpServlet {
   
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

        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        Connection con;
        Statement stmnt1;
        ResultSet rs1,rs2;

        String dt= request.getParameter("Edate").toString();
        String s1="select * from App.checkout where borrow_date='"+dt+"'";
        String s2="select * from App.checkout where return_date='"+dt+"'";

         try
        {
             Class.forName("org.apache.derby.jdbc.ClientDriver");
             con = DriverManager.getConnection("jdbc:derby://localhost:1527/LibrarySystem", "ishan", "ishan");
             stmnt1 = con.createStatement();
             rs1=stmnt1.executeQuery(s1);

             out.println("<HTML><HEAD><TITLE>View Status</TITLE></HEAD>");
             out.println("<BODY>");
             out.println("<center><h1>Library Management System</h1></center><br>");
             out.println("<center><h2Books Borrowed Results</h2></center><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>C_ID</td><td>MEMBER_ID</td><td>RESOURCE_ID</td><td>BORROW_DATE</td><td>RETURN_DATE</td>");
             out.println("</tr>");

             while(rs1.next())
             {
                out.println("<tr>");
                out.println("<td>"+rs1.getString("C_ID")+"</td><td>"+rs1.getString("MEMBER_ID")+"</td><td>" +rs1.getString("RESOURCE_ID")+"</td><td>"+ rs1.getString("BORROW_DATE")+"</td><td>"+rs1.getString("RETURN_DATE")+"</td>");
                out.println("</tr>");
             }
              out.println("</table><br><hr><br>");              

             rs2=stmnt1.executeQuery(s2);
             out.println("<center><h2Books Returned Results</h2></center><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>C_ID</td><td>MEMBER_ID</td><td>RESOURCE_ID</td><td>BORROW_DATE</td><td>RETURN_DATE</td>");
             out.println("</tr>");

             while(rs2.next())
             {
                out.println("<tr>");
                out.println("<td>"+rs2.getString("C_ID")+"</td><td>"+rs2.getString("MEMBER_ID")+"</td><td>" +rs2.getString("RESOURCE_ID")+"</td><td>"+ rs2.getString("BORROW_DATE")+"</td><td>"+rs2.getString("RETURN_DATE")+"</td>");
                out.println("</tr>");
             }
             
             out.println("</table><br><hr><br>");              
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

        //processRequest(request, response);
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
