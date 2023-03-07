<%-- 
    Document   : CustEnquiry
    Created on : Oct 23, 2010, 2:43:30 PM
    Author     : Ishan Mukherjee
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>CustEnquiry</h1>

       <form name="RoomSel" id="RoomSel_id" action="SearchRoomServlet" method="post">
        <table align="center" border="1" width="500" height="200">
        <tr>
            <td>Type of Room</td>
            <td>
                <input type="radio" name="bed" value="2">2 BedRoom<br>
                <input type="radio" name="bed" value="3">3 BedRoom <br>
            </td>
        </tr>
        <tr>
            <td>Facility</td>
            <td>
                <input type="radio" name="facility" value="4">AC<br>
                <input type="radio" name="facility" value="5">NON-AC<br>
            </td>
        </tr>
        <tr>
            <td colspan="2"><center><input type="submit" value="submit" /></center></td>
        </tr>
    </table>
    </form>

    </body>
</html>
