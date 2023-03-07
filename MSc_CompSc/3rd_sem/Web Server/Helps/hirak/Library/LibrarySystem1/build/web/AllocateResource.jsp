<%-- 
    Document   : AllocateResource
    Created on : Feb 26, 2011, 10:29:41 AM
    Author     : Hirak
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Allocate Resource</title>
    </head>
    <body>
        <form name="AllocateResourceServlet" action="AllocateResourceServlet" method="POST">
            <center><h1><u>Library Automation System</u></h1></center>
            <center>
        <table border="0">
            <thead>
                <tr>
                    <th><h2><u>Allocate Resource</u></h2></th>
                    <th></th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><h3>Checkout Id :</h3></td>
                    <td><input type="text" name="checkoutid" value="" /></td>
                </tr>
                <tr>
                    <td><h3>Member Id :</h3></td>
                    <td><input type="text" name="memberid" value="" /></td>
                </tr>
                <tr>
                    <td><h3>?Resource Id :</h3></td>
                    <td><input type="text" name="resourceid" value="" /></td>
                </tr>
                <tr>
                    <td><h3>Borrow Date :</h3></td>
                    <td><input type="text" name="borrow" value="" />(yyyy-mm-dd)</td>
                </tr>
                <tr>
                    <td><h3>Return Date :</h3></td>
                    <td><input type="text" name="return" value="" />(yyyy-mm-dd</td>
                </tr>
                <tr>
                    <td colspan="2"><input type="submit" value="Check Out" name="checkout" /></td>
                </tr>
            </tbody>
        </table>
            </center>
        </form>
    </body>
</html>
