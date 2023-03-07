package library_system_pkg;

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


public class ResourceServlet extends HttpServlet 
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
        Statement s1;
        Connection con;
        
        String resourceid= request.getParameter("resourceid").toString();
        String name = request.getParameter("name").toString();
        String category = request.getParameter("category").toString();
        String type= request.getParameter("type").toString();
        String authorname=request.getParameter("authorname").toString();;

        if(authorname.isEmpty())
        {
           authorname="None";
        }
 
        Integer no_of_copies= Integer.parseInt(request.getParameter("no_of_copies").toString());

        try
        {
             Class.forName("com.mysql.jdbc.Driver");
             con = DriverManager.getConnection("jdbc:mysql://localhost:3306/LibrarySystem", "root", "goblin");
             s1 = con.createStatement();

             String s="insert into Resource values('"+ resourceid +"','"+name+"','"+type+"','"+category+"','"+authorname+"',"+no_of_copies+","+no_of_copies+")";
             s1.executeUpdate(s);
             out.println("<html>");
             out.println("<head>");
             out.println("<title>Registration Complete</title>");
             out.println("</head>");
             out.println("<body>");
             out.println("<center><h1><u>Library Automation System</u></h1></center>");
             out.println("<center><br /><h2> Your Record has been added successfully.</h2></center>");
             out.println("<br /><center><h4><a href = 'addresource.html'>Back</a></h4></center>");
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
            out.println("<title>Registration Error</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("<center><h1>Library Automation System</h1></center>");
            out.println("<br><center><h2>Registration Error</h2></center>");
            out.println("<center><textarea rows='5' cols='50'>" + e + "</textarea></center>");
            out.println("<center><h3>Please Try Again</h3></center>");
            out.println("<br><center><h4><a href = 'addresource.html'>Back</a></h4></center>");
            out.println("</body>");
            out.println("</html>");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
    }
}
