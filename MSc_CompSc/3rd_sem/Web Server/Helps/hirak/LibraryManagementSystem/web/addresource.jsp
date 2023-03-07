<%-- 
    Document   : addresource
    Created on : Dec 24, 2010, 8:54:52 PM
    Author     : Hirak
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Add Resources</title>
    </head>
    <body>
        <form name="ResourceServlet" action="ResourceServlet" method="POST">
        <center><h1><u>Library Automation System</u></h1>
        <table border="0">
            <thead>
                <tr>
                    <th><h2><u>Add Book/CD/DVD</u></h2></th>
                    <th></th>
                </tr>
            </thead>
            <tbody>
                <tr>
                    <td><h3>Resource Id :</h3></td>
                    <td><input type="text" name="resourceid" value="" /></td>
                </tr>
                <tr>
                    <td><h3>Name :</h3></td>
                    <td><input type="text" name="name" value="" /></td>
                </tr>
                <tr>
                    <td><h3>Category :</h3></td>
                    <td><input type="text" name="category" value="" /></td>
                </tr>
                <tr>
                    <td><h3>Type :</h3></td>
                    <td><select name="type">
                            <option>Book</option>
                            <option>CD</option>
                            <option>DVD</option>
                        </select></td>
                </tr>
                <tr>
                    <td><h3>Author's Name:</h3></td>
                    <td><input type="text" name="authorname" value="" /></td>
                </tr>
                <tr>
                    <td><h3>No. Of Copies :</h3></td>
                    <td><input type="text" name="no_of_copies" value="" /></td>
                </tr>
                <tr>
                    <td colspan="2"><input type="submit" value="Submit" name="Submit" /></td>
                </tr>
            </tbody>
        </table>
        </center>
        </form>
        </body>
</html>
