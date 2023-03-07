<%-- 
    Document   : CheckOutCust
    Created on : Oct 31, 2010, 11:27:17 AM
    Author     : Ishan Mukherjee
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Check Out Customer</title>
    </head>
    <body>
        <center><h1>ABC Hotel Reservation System</h1></center>
        <br>
        <form name="CheckOut" id="CkeckOutId" action="CheckOutServlet" method="POST">
            <table align="center" border="1">
                <tr>
                    <td>Customer Id</td><td><input type="text" name="CustId" /></td>
                </tr>
                <tr>
                    <td colspan="2"><center><input type="submit" /></center></td>
                </tr>
            </table>
        </form>
        <center><h3><a href="index.jsp">Home</a></h3></center>
    </body>
</html>
