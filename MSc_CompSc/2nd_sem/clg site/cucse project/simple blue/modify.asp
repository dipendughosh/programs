<%@ LANGUAGE="VBSCRIPT" %>
<%
'declare the variables
Dim Connection
Dim ConnString
Dim sql
Dim userId

'define the connection string, specify database driver
ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'create an instance of the ADO connection and recordset objects
Set Connection = Server.CreateObject("ADODB.Connection")

'declare the SQL statement that will query the database
sql=request.querystring("ModifySql")

'Open the connection to the database
Connection.Open ConnString

sql=sql & " where alumni_id='ALCUCSE10';"

Connection.Execute sql

Response.write("Record Updated Successfully!")
'close the connection to free up resources
Connection.Close
Set Connection=nothing
%>