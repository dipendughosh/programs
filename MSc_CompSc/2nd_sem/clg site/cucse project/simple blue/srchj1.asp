<%@ LANGUAGE="VBSCRIPT" %>
<%
'declare the variables
Dim Connection
Dim ConnString
Dim Recordset
Dim SQL
Dim result

'define the connection string, specify database driver
ConnString="DRIVER={SQL Server};SERVER=cucse.org;UID=admincucse;" & _
"PWD=cucse123;DATABASE=cucse"

'SQL = "SELECT * FROM prof WHERE "
'	IF C_alumniId.checked = 1 THEN
'		SQL=SQL + "alumni_id='"+ document.getElementById('T_alumniId').value + "'"
'	ELSE
'		IF C_name.checked = 1 THEN
'			SQL=SQL + "name='" + document.getElementById('T_name').value + "'"
'			IF C_yoj.checked = 1 THEN
'				SQL=SQL + " AND yoj='" + document.getElementById('T_yoj').value + "'"
'			END IF
'			IF C_yop.checked = 1 THEN
'				SQL=SQL + " AND yop='" + document.getElementById('T_yop').value + "'"
'			END IF
'		ELSEIF C_yoj.checked = 1 THEN
'			SQL=SQL + "yoj='" + document.getElementById('T_yoj').value + "'"
'			IF C_yop.checked = 1 THEN
'				SQL=SQL + " AND yop='" + document.getElementById('T_yop').value "'"
'			END IF
'		ELSEIF C_yop.checked = 1 THEN
'			SQL=SQL + "yoj='" + document.getElementById('T_yoj').value + "'"
'		END IF
'	END IF
'	alert(SQL)
SQL= request.querystring("SQL")

'create an instance of the ADO connection and recordset objects
Set Connection = Server.CreateObject("ADODB.Connection")
Set Recordset = Server.CreateObject("ADODB.Recordset")

'Open the connection to the database
Connection.Open ConnString

'Open the recordset object executing the SQL statement and return records
Recordset.Open SQL,Connection

'first of all determine whether there are any records
If Recordset.EOF Then
	Response.Write("No")
Else
'if there are records then loop through the fields
result="<table>"
result=result & "<tr>"
result=result & "<th>ID</th>"
result=result & "<th>Name</th>"
result=result & "</tr>"

	Do While NOT Recordset.EOF  
		result=result & "<tr>"
		result=result & "<td>"
		result=result & Recordset.Fields("name").value
		result=result & "</td>"			
		result=result & "<td>"			
		result=result & Recordset.Fields("surname").value
		result=result & "</td>"
		result=result & "<td>"
		result=result & Recordset.Fields("date_of_birth").value
		result=result & "</td>"			
		result=result & "<td>"			
		result=result & Recordset.Fields("yoj").value
		result=result & "</td>"
		result=result & "<td>"			
		result=result & Recordset.Fields("yop").value
		result=result & "</td>"
		Dim msc
		Dim mtech
		Dim btech
		Dim phd
		msc=Recordset.fields("course_msc").value
		btech=Recordset.fields("course_btech").value
		mtech=Recordset.fields("course_mtech").value
		phd=Recordset.fields("course_phd").value
		if msc=1 then
			result=result & "M.Sc "
		end if
		if btech=1 then
			result=result & "B.Tech "
		end if
		if mtech=1 then
			result=result & "M.Tech "
		end if
		if phd=1 then
			result=result & "Phd."
		end if	
		result=result & "</tr>"
		recordset.MoveNext    
	Loop
	result=result & "</table>"
End If

Response.write result

'close the connection and recordset objects to free up resources
Recordset.Close
Set Recordset=nothing
Connection.Close
Set Connection=nothing
%>