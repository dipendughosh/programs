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

public class AllocateResourceServlet extends HttpServlet 
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
        PrintWriter out = response.getWriter();
        Statement s1,s4;
        ResultSet records=null;
        Connection con;
        int a;

        String checkoutid= request.getParameter("checkoutid").toString();
        String memberid = request.getParameter("memberid").toString();
        String resourceid = request.getParameter("resourceid").toString();
        String borrow_dt= request.getParameter("borrow").toString();
        String return_dt=request.getParameter("return").toString();

        try
        {
             Class.forName("com.mysql.jdbc.Driver");
             con = DriverManager.getConnection("jdbc:mysql://localhost:3306/LibrarySystem", "root", "goblin");
             s1 = con.createStatement();
             s4 = con.createStatement();

             String s="insert into Checkout values('"+ checkoutid +"','"+memberid+"','"+resourceid+"','"+borrow_dt+"','"+return_dt+"')";
             s1.executeUpdate(s);

             String s2="select available from resource where resourceid='"+resourceid+"'";
             records=s1.executeQuery(s2);
            
             while(records.next())
             {
                a= records.getInt("available")-1;
                String s3="update resource set available="+a+" where resourceid='"+resourceid+"'";
                s4.executeUpdate(s3);
             }  
             
             out.println("<html>");
             out.println("<head>");
             out.println("<title>Registration Complete</title>");
             out.println("</head>");
             out.println("<body>");
             out.println("<center><h1><u>Library Automation System</u></h1></center>");
             out.println("<center><br /><h2> Your Record has been added successfully.</h2></center>");
             out.println("<br /><center><h4><a href = 'AllocateResource.html'>Back</a></h4></center>");
             out.println("<br /><center><h4><a href = 'index.html'>Home</a></h4></center>");
             out.println("</body>");
             out.println("</html>");
        }
        catch(ClassNotFoundException e)
        {
			System.out.println(e);
		}

        catch(SQLException e)
        {
			System.out.println(e);
			out.println("<html>");
            out.println("<head>");
            out.println("<title>Error</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<center><h1>Library Automation System</h1></center>");
            out.println("<br><center><h2>Error</h2></center>");
            out.println("<center><textarea rows='5' cols='50'>" + e + "</textarea></center>");
            out.println("<center><h3>Please Try Again</h3></center>");
            out.println("<br><center><h4><a href = 'AllocateResource.html'>Back</a></h4></center>");
            out.println("</body>");
            out.println("</html>");
		}
        
        catch(Exception e)
        {
			System.out.println(e);
		}
    }
}
