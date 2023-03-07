<%
	Dim Connection
	Dim ConnString
	Dim Recordset
	Dim sql

ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'sql="SELECT * FROM login where alumni_id='" & Request.querystring("LOGIN_usrname") & "' and LIO_StatusId='" & Request.querystring("LIO_StatusId") & "'"
sql="SELECT * FROM login where alumni_id='" & Request.querystring("H_user") & "' and LIO_StatusId <> '0'"

Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")
Connection.Open ConnString
Recordset.Open sql,Connection

If Recordset.EOF Then
	Recordset.Close
	Set Recordset=nothing
	Connection.Close
	Set Connection=nothing
	Response.Write ("NO")	
	'Response.redirect "index.html"
ELSE
	Response.Write ("OK")	
	Recordset.Close
	Set Recordset=nothing
	Connection.Close
	Set Connection=nothing
End If

%>