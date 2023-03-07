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

public class ReturnResourceServlet extends HttpServlet 
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
	        Statement s1,s4,s5;
	        int a;
	        ResultSet records;

	        String mem= request.getParameter("mem").toString();
	        
	        try
	        {
	             Class.forName("com.mysql.jdbc.Driver");
	             con = DriverManager.getConnection("jdbc:mysql://localhost:3306/LibrarySystem", "root", "goblin");
	             s1 = con.createStatement();
	             s4 = con.createStatement();
	             s5 = con.createStatement();
	             String s="select * from CHECKOUT where C_ID='"+mem+"'";
	             records =s1.executeQuery(s);
	             String resourceid="";
	             while(records.next())
	             {
	            	 resourceid=records.getString("RESOURCEID");
	             }
	             String s2="select available from resource where resourceid='"+resourceid+"'";
	             records=s1.executeQuery(s2);
	            
	             while(records.next())
	             {
	                a= records.getInt("available")+1;
	                String s3="update resource set available="+a+" where resourceid='"+resourceid+"'";
	                s4.executeUpdate(s3);
	             }  
	             String s6="delete from checkout where C_ID='"+mem+"'";
	             s5.executeUpdate(s6);

	             
	             out.println("<HTML><HEAD><TITLE>Resource List</TITLE></HEAD>");
	             out.println("<BODY>");
	             out.println("<center><h1>Library Automation System</h1></center><br>");
	             out.println("<center><h2>Resource Returned</h2></center><br><br>");
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

