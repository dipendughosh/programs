<%
'declare the variables
Dim Connection
Dim ConnString
Dim Recordset
Dim SQL
Dim sql2

'define the connection string, specify database driver
ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'declare the SQL statement that will query the database
SQL = "SELECT * FROM login where alumni_id='ALCUCSE20032' and password='" & Request.querystring("change_old_pwd") &"'"

'create an instance of the ADO connection and recordset objects
Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")

'Open the connection to the database
Connection.Open ConnString

'Open the recordset object executing the SQL statement and return records
Recordset.Open SQL,Connection

'first of all determine whether there are any records
If Recordset.EOF Then
Response.Write("NO")
Else
sql2="update login set password='" & Request.querystring("change_new_pwd") & "' where alumni_id='ALCUCSE20032'"
Connection.Execute sql2
End If

'close the connection and recordset objects to free up resources
Recordset.Close
Set Recordset=nothing
Connection.Close
Set Connection=nothing
%>