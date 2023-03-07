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
public class SearchResourceServlet extends HttpServlet {
   
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
            out.println("<title>Servlet SearchResourceServlet</title>");  
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Servlet SearchResourceServlet at " + request.getContextPath () + "</h1>");
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
        response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        Connection con;
        Statement s1;
        ResultSet records;

        String authorname= request.getParameter("authorname").toString();
        String name = request.getParameter("name").toString();
        String category = request.getParameter("category").toString();
        String type= request.getParameter("type").toString();

        try
        {
             Class.forName("org.apache.derby.jdbc.ClientDriver");
             con = DriverManager.getConnection("jdbc:derby://localhost:1527/Library", "hirak", "hirak");
             s1 = con.createStatement();
             String s="select * from APP.RESOURCE where ";

             s= s+"type='"+type+"'";

             if (!name.isEmpty())
             {
                  s= s+" and name='"+name+"'";
             }
             if (!category.isEmpty())
             {
                  s= s+" and category='"+category+"'";
             }
             if (!authorname.isEmpty())
             {
                  s= s+" and authorname='"+authorname+"'";
             }
             records =s1.executeQuery(s);

             out.println("<HTML><HEAD><TITLE>Resource List</TITLE></HEAD>");
             out.println("<BODY>");
             out.println("<center><h1>Library Automation System</h1></center><br>");
             out.println("<center><h2>Resource List</h2></center><br><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>Resource ID</td><td>Name</td><td>Type</td><td>Category</td><td>Author's Name</td><td>No. of Copies</td><td>Available</td>");
             out.println("</tr>");

             while (records.next())
             {

                out.println("<tr>");
                out.println("<td>"+records.getString("RESOURCEID")+"</td><td>" + records.getString("NAME") +"</td><td>"+ records.getString("TYPE") +"</td><td>"+ records.getString("CATEGORY")+"</td><td>"+records.getString("AUTHORNAME")+ "</td><td>"+records.getString("NO_OF_COPIES")+"</td><td>" +  records.getString("AVAILABLE")+"</td>");
                out.println("</tr>");
             }

             out.println("</table><br>");
             out.println("<br>");
             out.println("<center><a href='AllocateResource.jsp'><h3>Allocate Resource</h3></a></center>");
             out.println("</BODY></HTML>");
        }
         catch(ClassNotFoundException e){
			System.out.println(e);
		}
	catch(SQLException e){
			System.out.println(e);
                         out.println("<html>");
                        out.println("<head>");
                        out.println("<title>Error</title>");
                        out.println("</head>");
                        out.println("<body>");
                        out.println("<center><h1>Library Automation System</h1></center>");
                        out.println("<br><center><h2>Registration Error</h2></center>");
                        out.println("<center><textarea rows='5' cols='50'>" + e + "</textarea></center>");
                        out.println("<center><h3>Please Try Again</h3></center>");
                        out.println("<br><center><h4><a href = 'addresource.jsp'>Back</a></h4></center>");
                        out.println("</body>");
                        out.println("</html>");
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
