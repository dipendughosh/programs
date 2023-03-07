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

public class SearchResourceServlet extends HttpServlet 
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
    	response.setContentType("text/html;charset=UTF-8");
        PrintWriter out = response.getWriter();
        Connection con;
        Statement s1;
        ResultSet records;

        String authorname= request.getParameter("authorname").toString();
        String name = request.getParameter("name").toString();
        String category = request.getParameter("category").toString();
        String type= request.getParameter("resourcetype").toString();

        try
        {
             Class.forName("com.mysql.jdbc.Driver");
             con = DriverManager.getConnection("jdbc:mysql://localhost:3306/LibrarySystem", "root", "goblin");
             s1 = con.createStatement();
             String s="select * from RESOURCE where type='"+type+"'";

             if (!name.isEmpty())
             {
                  s= s+" and name='"+name+"'";
             }
             if (!authorname.isEmpty())
             {
                  s= s+" and author='"+authorname+"'";
             }
             if (!category.isEmpty())
             {
                  s= s+" and catagory='"+category+"'";
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
                out.println("<td>"+records.getString("RESOURCEID")+"</td><td>" + records.getString("NAME") +"</td><td>"+ records.getString("TYPE") +"</td><td>"+ records.getString("CATAGORY")+"</td><td>"+records.getString("AUTHOR")+ "</td><td>"+records.getInt("NO_OF_COPIES")+"</td><td>" +  records.getInt("AVAILABLE")+"</td>");
                out.println("</tr>");
             }

             out.println("</table><br>");
             out.println("<br>");
             out.println("<center><a href='AllocateResource.html'><h3>Allocate Resource</h3></a></center>");
             out.println("<br /><center><h4><a href = 'index.html'>Home</a></h4></center>");
             out.println("</BODY></HTML>");
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
            out.println("<br><center><h2>Registration Error</h2></center>");
            out.println("<center><textarea rows='5' cols='50'>" + e + "</textarea></center>");
            out.println("<center><h3>Please Try Again</h3></center>");
            out.println("<br><center><h4><a href = 'addresource.html'>Back</a></h4></center>");
            out.println("<br><center><h4><a href = 'index.html'>Home</a></h4></center>");
            out.println("</body>");
            out.println("</html>");
		}
        catch(Exception e)
        {
			System.out.println(e);
		}
    }
}
