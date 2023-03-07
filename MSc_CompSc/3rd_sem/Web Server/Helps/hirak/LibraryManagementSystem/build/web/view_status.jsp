<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>View Status Page</title>
    </head>
    <body>
        <h1>Library Automation System</h1>
        <form action="ViewStatusServlet" method="get">
        Enter the member Id whose Status is to be viewed : <input type="text" name="mem" />
        <input type="submit" value="submit"/>
        </form>
    </body>
</html>
