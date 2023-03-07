<%@ LANGUAGE="VBSCRIPT" %>
<%
'declare the variables
Dim Connection
Dim ConnString
Dim sql
Dim serial
Dim userId
Dim Recordset

'define the connection string, specify database driver
ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'create an instance of the ADO connection and recordset objects
Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")

'declare the SQL statement that will query the database
sql=request.querystring("InsertSql")
sql1="SELECT count(*) 'count' from profile"
sql2="INSERT into login values('"

'Open the connection to the database
Connection.Open ConnString

Recordset.Open sql1,Connection

serial= Recordset.Fields("count").value
Response.Write serial

userId="ALCUCSE" & Request.querystring("YearJoin") & (serial+1)

sql=sql & "'" & userId & "');"
'sql2=sql2 & userId & "','" & Request.querystring("password") & "','0');"
sql2=sql2 & userId & "','" & userId & "','0');"

Response.Write sql
Response.Write sql2

Connection.Execute sql
Connection.Execute sql2

'close the connection and recordset objects to free up resources
Recordset.Close
Set Recordset=nothing
Connection.Close
Set Connection=nothing
%>