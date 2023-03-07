package servlets;
import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.sql.Connection;
import java.sql.DriverManager;

import com.mysql.jdbc.ResultSet;
import com.mysql.jdbc.Statement;


public class bookingServlet1 extends HttpServlet {

	
	
	 protected void performBooking(HttpServletRequest request, HttpServletResponse response)
	    throws ServletException, IOException {
		 
		 PrintWriter out = response.getWriter();
	      
	        int n,reserved=0;

	        String tname =request.getParameter("tname").toString();
	        String date = request.getParameter("date").toString();
	        int  adt = Integer.parseInt(request.getParameter("adt").toString());
	        int  chd= Integer.parseInt(request.getParameter("chd").toString());
	        int totalPerson=adt+chd;
	        String cno = request.getParameter("cno").toString();
	       
	        response.setContentType("text/html;charset=UTF-8");
	        
	        try {
	        	Class.forName("com.mysql.jdbc.Driver");
				Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/tour", "root", "");
				Statement st = (Statement) con.createStatement();
				String s1="select * from tour_schedule where title like '"+tname+"%' and date='"+date+"'";
				ResultSet rs = (ResultSet) st.executeQuery(s1);
				out.println("okk1");
	  			int tid = 0,seats = 0,amnt = 0, b_id = 0, totalAmount=0;
	  			
				while(rs.next()){
				tid=Integer.parseInt(rs.getString(1));
				 seats=Integer.parseInt(rs.getString(4));
				 amnt=Integer.parseInt(rs.getString(5));	
				 String dt=rs.getString(3);
				
				 
					}
				out.println("okk2");
				if(seats > totalPerson)
				{
					
					//retrieve max booking_id
					rs=(ResultSet) st.executeQuery("select * from booking");
					if(rs.next())
					{
						rs=(ResultSet) st.executeQuery("select max(booking_id)  from booking");
						if(rs.next())
							b_id=Integer.parseInt(rs.getString(1))+1;
						
					}
					else
						b_id=1;
					
						
			
					out.println("ang");
					//calculate total amount
					 totalAmount=(adt*amnt)+(chd*(amnt-2000));
					
					// make reservation
					String s2="insert into booking values('"+Integer.toString(b_id)+"','"+ Integer.toString(tid)+"','"+Integer.toString(adt)+"','"+Integer.toString(chd)+"','"+Integer.toString(totalAmount)+"','"+cno+"','"+date+"')";
					n = st.executeUpdate(s2);	
					out.println("ang1");
					//decrease available seats
					int av=seats-totalPerson;
					String s3="update tour_schedule set availability='"+av+"' where tour_id='"+tid+"' and date='"+date+"'";
					n = st.executeUpdate(s3);
					out.println("ang2");
					reserved=1;
					
					}
				
					// close all the connections.
				      rs.close();
				      st.close();
				      con.close();
				      
				      out.println("ang3");
				      
				      // generate the ticket by calling the JSP page
				      
				      javax.servlet.RequestDispatcher dispatcher = getServletContext().getRequestDispatcher("/viewTicket.jsp"); 
				      
				      if(reserved==1)
				      {  request.setAttribute("reserved","true"); 
				      
				      	request.setAttribute("tourName",tname);
				      	request.setAttribute("onDate",date);
				      	request.setAttribute("adults",Integer.toString(adt));
				      	request.setAttribute("children",Integer.toString(chd));
				      	request.setAttribute("amount",Integer.toString(totalAmount));
				      	
				      }	
				      else
				    	  request.setAttribute("reserved","false");
				      dispatcher.forward(request,response); 

				}

	  	      
	  			

	      
	  	catch (Exception ex) {
	      
	      out.println(ex);
	          
	                  
	              }
	  
	  	
	  	
	  			

	        
	   } 


	
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		doPost(req, resp);
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws ServletException, IOException {
		performBooking(req,resp);
	}

}
