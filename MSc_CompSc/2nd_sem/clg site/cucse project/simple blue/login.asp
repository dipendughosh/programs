<%@ LANGUAGE="VBSCRIPT" %>
<%
'declare the variables
Dim Connection
Dim ConnString
Dim Recordset
Dim conn1
Dim sql
Dim sql1

'define the connection string, specify database driver
ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'declare the SQL statement that will query the database

'Response.Write (request.querystring("LOGIN_usrname"))
'Response.Write (request.querystring("LOGIN_password"))

sql="SELECT password FROM login where alumni_id='" & request.querystring("LOGIN_usrname") & "' and password='" & request.querystring("LOGIN_password")  & "'"

sql1="UPDATE login set LIO_StatusId='" & request.querystring("LIO_StatusId") & "' WHERE alumni_id='" & request.querystring("LOGIN_usrname") & "'"
Response.Write sql1
	
'create an instance of the ADO connection and recordset objects
Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")
'Set conn1 = Server.CreateObject("ADODB.Connection")

'Open the connection to the database
Connection.Open ConnString
'conn1.Open ConnString

'Open the recordset object executing the SQL statement and return records
Recordset.Open sql,Connection
'first of all determine whether there are any records

If Recordset.EOF Then
	Response.Write("NO")
Else
	Connection.Execute sql1
	Response.Write("YES")
End If
	
'close the connection and recordset objects to free up resources
Recordset.Close
Set Recordset=nothing
Connection.Close
Set Connection=nothing
'conn1.close
'Set conn=nothing
%>