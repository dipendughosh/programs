<%-- 
    Document   : searchresources
    Created on : Feb 24, 2011, 8:35:20 PM
    Author     : Hirak
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Search Resources</title>
    </head>
    <body>
        <form name="SearchResourceServlet" action="SearchResourceServlet" method="GET">
        <center><h1><u>Library Automation System</u></h1></center>
        <center><table border="0">
                <thead>
                    <tr>
                        <th><h2><u>Search Resources</u></h2></th>
                        <th></th>
                    </tr>
                </thead>
                <tbody>
                    <tr>
                        <td><h3>Type :</h3></td>
                        <td><select name="resourcetype" id="type">
                                <option>Book</option>
                                <option>CD</option>
                                <option>DVD</option>
                            </select></td>
                    </tr>
                    <tr>
                        <td><h3>Name :</h3></td>
                        <td><input type="text" name="name" value="" id="name" /></td>
                    </tr>
                    <tr>
                        <td><h3>Author's Name :</h3></td>
                        <td><input type="text" name="authorname" value="" id="authorname"/></td>
                    </tr>
                    <tr>
                        <td><h3>Category :</h3></td>
                        <td><input type="text" name="category" value="" id="category"/></td>
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
