/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package LirarySystem;

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
 * @author Hirak
 */
public class RegistrationServlet extends HttpServlet {
   
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
            out.println("<title>Servlet RegistrationServlet</title>");  
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet RegistrationServlet at " + request.getContextPath () + "</h1>");
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
    throws ServletException, IOException {
        PrintWriter out = response.getWriter();
        Statement s1;
        ResultSet records;
        Connection con;
        int n;

        String memid= request.getParameter("memid").toString();
        String name = request.getParameter("memname").toString();
        String address = request.getParameter("add").toString();
        String dob= request.getParameter("dob").toString();
        String sex= request.getParameter("sex").toString();
        String contact= request.getParameter("contact").toString();


        try
        {
             Class.forName("org.apache.derby.jdbc.ClientDriver");
             con = DriverManager.getConnection("jdbc:derby://localhost:1527/Library", "hirak", "hirak");
             s1 = con.createStatement();

             String s="insert into App.Member values('"+ memid +"','"+name+"','"+address+"','"+dob+"','"+sex+"','"+contact+"')";
             n=s1.executeUpdate(s);
             out.println("<html>");
             out.println("<head>");
             out.println("<title>Registration Complete</title>");
             out.println("</head>");
             out.println("<body>");
             out.println("<center><h1><u>Library Automation System</u></h1></center>");
             out.println("<center><br /><h2> Your Record has been added successfully.</h2></center>");
             out.println("<br /><center><h4><a href = 'index.jsp'>Back</a></h4></center>");
             out.println("</body>");
             out.println("</html>");
             processRequest(request, response);
        }
        catch(ClassNotFoundException e){
			System.out.println(e);
		}
		catch(SQLException e){
			System.out.println(e);
                        out.println("<html>");
                        out.println("<head>");
                        out.println("<title>Registration Error</title>");
                        out.println("</head>");
                        out.println("<body>");
                        out.println("<center><h1>Library Automation System</h1></center>");
                        out.println("<br><center><h2>Registration Error</h2></center>");
                        out.println("<center><textarea rows='5' cols='50'>" + e + "</textarea></center>");
                        out.println("<center><h3>Please Try Again</h3></center>");
                        out.println("<br><center><h4><a href = 'registration.jsp'>Back</a></h4></center>");
                        out.println("</body>");
                        out.println("</html>");
		}
		catch(Exception e){
			System.out.println(e);
		}
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
