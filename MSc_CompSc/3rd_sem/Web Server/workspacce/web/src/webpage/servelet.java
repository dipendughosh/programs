package webpage;

import java.io.*;
import java.sql.*;

import javax.servlet.*;
import javax.servlet.http.*;

public class servelet extends HttpServlet
{
  
	private static final long serialVersionUID = 1L;

  /**Process the HTTP Get request*/
  public void doPost(HttpServletRequest req, HttpServletResponse res) throws ServletException, IOException
  {
	String connectionURL = "jdbc:mysql://localhost:3306/students";
    Connection connection=null;
    ResultSet rs;
    String exam_v=null, exam_t=null, exam_d=null; 
    Statement st;
    res.setContentType("text/html");
    PrintWriter out = res.getWriter();
    //get the variables entered in the form
    String fname = req.getParameter("fname").toString();
    String lname = req.getParameter("lname").toString();
    String dob=req.getParameter("dob").toString();
    String add = req.getParameter("addr").toString();
    String con = req.getParameter("con").toString();
    String sub=req.getParameter("sub").toString();
    String name=fname + lname;
    String Reg_id=fname+dob;
    
    try
    {
     // Load the database driver
     Class.forName("com.mysql.jdbc.Driver");
     // Get a Connection to the database
     connection = DriverManager.getConnection(connectionURL, "root", "goblin"); 
     //Add the data into the database
     String sql = "insert into student values(?,?,?,?,?,?)";
     PreparedStatement pst = connection.prepareStatement(sql);
     pst.setString(1,fname);
     pst.setString(2,lname);
     pst.setString(3,dob);
     pst.setString(4,add);
     pst.setString(5,con);
     pst.setString(6,sub);
     
     int numRowsChanged = pst.executeUpdate();
     pst.close();
     // show that the new account has been created
     out.println("<html>");
      
 	 out.println("<head>");
 	           
 	 out.println("<title>Students Registration</title>");
 	           
 	 out.println("</head>");
 	 out.println("<body>");
 	 st=connection.createStatement();
     rs = st.executeQuery("select * from subject where sub= '"+sub+"'");
     while(rs.next()) 
     {
       exam_v= rs.getObject(2).toString();
       exam_d= rs.getObject(3).toString();
       exam_t= rs.getObject(4).toString();
     }
     rs.close();
     st.close(); 
     String sql1 = "insert into student_allocated values (?,?)";
     pst = connection.prepareStatement(sql1);
     pst.setString(1, Reg_id);
     pst.setString(2, sub);
     numRowsChanged = pst.executeUpdate();
     pst.close();
	 out.println("<br>");
	 out.println("<center>");
     out.println("<table border='2'><tr><td>NAME</td><td>"+name+"</td></tr> ");
     out.println("<tr><td>Registration_id</td><td>"+Reg_id+"</td></tr> ");
     out.println("<tr><td>Subject</td><td>"+sub+"</td></tr> ");
     out.println("<tr><td>Examination_Date</td><td>"+exam_d+"</td></tr> ");
     out.println("<tr><td>Examination_Venue</td><td>"+exam_v+"</td></tr> ");
     out.println("<tr><td>Examination_Time</td><td>"+exam_t+"</td></tr></table> ");
     out.println("</center>");
     out.println("<br><center><h1><a href='index.html'>Home</a></h1></center>");
      
 	 out.println("</body>");
 	            
 	 out.println("</html>");
 	}
    catch(ClassNotFoundException e)
    {
      out.println("Couldn't load database driver: " + e.getMessage());
    }
    catch(SQLException e)
    {
      out.println("SQLException caught: " + e.getMessage());
    }
    catch (Exception e)
    {
      out.println(e);
    }
    finally 
    {
      // Always close the database connection.
      try 
      {
        if (connection != null) connection.close();
      }
      catch (SQLException ignored)
      {
        out.println(ignored);
      }
    }
  }
} 