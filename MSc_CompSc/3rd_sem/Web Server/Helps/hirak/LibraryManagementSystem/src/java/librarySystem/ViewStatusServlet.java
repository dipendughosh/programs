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
public class ViewStatusServlet extends HttpServlet {
   
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
        Statement s1;
        ResultSet rs1,rs2,rs3,rs4;
        int FINE=0;
        String MEM_ID=request.getParameter("mem").toString();


        try
        {             
             Class.forName("org.apache.derby.jdbc.ClientDriver");
             con = DriverManager.getConnection("jdbc:derby://localhost:1527/LibrarySystem", "ishan", "ishan");
             s1 = con.createStatement();             
             String s="select * from App.checkout where member_id='"+MEM_ID+"'";             

             out.println("<HTML><HEAD><TITLE>View Status</TITLE></HEAD>");
             out.println("<BODY>");
             out.println("<center><h1>Library Management System</h1></center><br>");
             out.println("<center><h2Member Status... Enquiry Results</h2></center><br>");
             out.println("<table align='center' border='1'>");
             out.println("<tr>");
             out.println("<td>C_ID</td><td>MEMBER_ID</td><td>RESOURCE_ID</td><td>BORROW_DATE</td><td>RETURN_DATE</td><td>FINE AS ON TODAY</td>");
             out.println("</tr>");

             rs1=s1.executeQuery(s);
             
                while (rs1.next())
                    {
                       String s2="select type from App.resource where resource_id='"+rs1.getString("RESOURCE_ID")+"'";
                       rs2=s1.executeQuery(s2);
                       String Type=rs2.getString("type");

                       String s3="select datediff(currdate(),'"+rs1.getString("RETURN_DATE")+"') AS days";
                       rs3=s1.executeQuery(s3);
                       int Days=Integer.parseInt(rs3.getString("days"));


                        /*FINE CALCULATIONS */
                       if(Days >0)
                       {
                            if(Type.matches("BOOKS"))
                            {
                                FINE=Days*1;
                            }
                            if(Type.matches("CD"))
                            {
                                FINE=Days*2;
                            }
                            if(Type.matches("DVD"))
                            {
                                FINE=Days*3;
                            }
                       }
                        else
                            FINE=0;                       

                       out.println("<tr>");
                       out.println("<td>"+rs1.getString("C_ID")+"</td><td>"+rs1.getString("MEMBER_ID")+"</td><td>" +rs1.getString("RESOURCE_ID")+"</td><td>"+ rs1.getString("BORROW_DATE")+"</td><td>"+rs1.getString("RETURN_DATE")+"</td><td>"+FINE+"</td>");
                       out.println("</tr>");
                    }
              out.println("</table><br>");


              out.println("<table align='center' border='1'>");
              out.println("<tr>");
              out.println("<td>");
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
