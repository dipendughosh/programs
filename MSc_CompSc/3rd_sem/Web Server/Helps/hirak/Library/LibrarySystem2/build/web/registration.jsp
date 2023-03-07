<%-- 
    Document   : registration
    Created on : Dec 21, 2010, 11:14:01 AM
    Author     : Hirak
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Member Registration</title>
    </head>
    <body>
        <form name="RegistrationServlet" action="RegistrationServlet" method="POST">
        <center><h1><u>Library Automation System</u></h1></center>
        <center><table border="0">
                <thead>
                    <tr>
                        <th><h2><u>Member Registration</u></h2></th>
                        <th></th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td><h3>Member Id :</h3></td>
                        <td><input type="text" name="memid" value="" id="memid"size="6" /></td>
                    </tr>
                    <tr>
                        <td><h3>Name :</h3></td>
                        <td><input type="text" name="memname" value="" id="memname" /></td>
                    </tr>
                    <tr>
                        <td><h3>Address :</h3></td>
                        <td><input type="text" name="add" value="" id="add"/></td>
                    </tr>
                    <tr>
                        <td><h3>Date of birth :</h3></td>
                        <td><input type="text" name="dob" value="" id="dob"/>(dd-mon-yyyy)</td>
                    </tr>
                    <tr>
                        <td><h3>Sex :</h3></td>
                        <td><select name="sex">
                                <option>M</option>
                                <option>F</option>
                            </select></td>
                    </tr>
                    <tr>
                        <td><h3>Contact No :</h3></td>
                        <td><input type="text" name="contact" value="" id="contact"/></td>
                    </tr>
                     <tr>
                         <td colspan="2"><input type="submit" value="Submit" name="submit" /></td>
                    </tr>
                </tbody>
            </table>
        </center>
        </form>
    </body>
</html>
