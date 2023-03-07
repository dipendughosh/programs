<%-- 
    Document   : AddRoom
    Created on : Oct 23, 2010, 2:44:56 PM
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
        <center><h1>ABC Hotel Reservation System</h1></center>
        <center><h2>Add Room Form</h2></center>
        <form id="AddRoomFormId" name="AddRoomForm" action="AddRoomServlet" method="POST">
            <table align="center" border="1" width="500">

                <tr>
                    <td>Room Number</td>
                    <td><input name="RoomNo" id="RoomNoId" /></td>
                </tr>
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
            <td>Availability</td>
            <td><input type="text" name="Avail" id="AvailId" value="0"/></td>
        </tr>
        <tr>
            <td colspan="2"><center><input type="submit" value="submit" /></center></td>
        </tr>

            </table>
        </form>
        <center><h3><a href="index.jsp">Home</a></h3></center>
    </body>
</html>
