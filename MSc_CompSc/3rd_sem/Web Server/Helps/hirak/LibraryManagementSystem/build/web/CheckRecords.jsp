<%-- 
    Document   : CheckRecords
    Created on : Feb 23, 2011, 7:27:10 AM
    Author     : Ishan Mukherjee
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Check Records</title>
    </head>
    <body>
        <h1>Enter Date on which Records Borrowed or Records Returned are to be viewed</h1>
        <form action="CheckRecordsServlet" method="get">
        <input type="text" name="Edate" />
        <input type="submit" value="submit" />
        </form>
    </body>
</html>
