<%@ LANGUAGE="VBSCRIPT" %>
<%
'declare the variables
Dim Connection
Dim ConnString
Dim sql
'define the connection string, specify database driver
ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

sql="UPDATE login set LIO_StatusId='0' WHERE alumni_id='" & request.querystring("LOGIN_usrname") & "'"
	
'create an instance of the ADO connection and recordset objects
Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")

'Open the connection to the database
Connection.Open ConnString
Connection.Execute sql
Response.redirect "index.html"

'close the connection and recordset objects to free up resources
Connection.Close
Set Connection=nothing
%>

<html>
<head>