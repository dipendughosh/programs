function start(theForm)
{
	clean();
}

function clean()
{
	document.getElementById('C_alumniId').checked="";	
	document.getElementById('T_alumniId').value="";			
	document.getElementById('C_name').checked="";
	document.getElementById('C_name').disabled="";
	document.getElementById('T_name').value="";
	document.getElementById('T_name').disabled="";
	document.getElementById('C_yoj').checked="";
	document.getElementById('C_yoj').disabled="";
	document.getElementById('T_yoj').value="";
	document.getElementById('T_yoj').disabled="";
	document.getElementById('C_yop').checked="";
	document.getElementById('C_yop').disabled="";
	document.getElementById('T_yop').value="";
	document.getElementById('T_yop').disabled="";
	document.getElementById('Search2').disabled="";
	
}
function chekEmpty1()
{
	if(C_alumniId.checked== 1)
	{
		var alname;
		alname=document.getElementById('T_alumniId').value;
		if(alname.length == '0')
			alert("Alumni ID is missing");
	}
}
function chekEmpty2()
{
	var a1,a2,a3;
	a1=document.getElementById('T_name').value;
	a2=document.getElementById('T_yoj').value;
	a3=document.getElementById('T_yop').value;
	if(C_name.checked == 1 && a1.length=='0')
			alert("Alumni Name is missing");
	else if(C_yoj.checked == 1 && a2.length=='0')
			alert("Year of Joining is missing");
	else if(C_yop.checked == 1 && a3.length=='0')
			alert("Year of Passing is missing");
}
function unchkId()
{
	if(C_alumniId.checked == 0)
		clean();
}
function unchkName()
{
	if(C_name.checked == 0)
		document.getElementById('T_name').value="";
}
function unchkYoj()
{
	if(C_name.checked == 0)
		document.getElementById('T_yoj').value="";
}
function unchkYop()
{
	if(C_name.checked == 0)
		document.getElementById('T_yop').value="";
}

function buildQuery()
{
	SQL = "SELECT * FROM prof WHERE "
	IF C_alumniId.checked = 1 THEN
		SQL=SQL + "alumni_id='"+ document.getElementById('T_alumniId').value + "'"
	ELSE
		IF C_name.checked = 1 THEN
			SQL=SQL + "name='" + document.getElementById('T_name').value + "'"
			IF C_yoj.checked = 1 THEN
				SQL=SQL + " AND yoj='" + document.getElementById('T_yoj').value + "'"
			END IF
			IF C_yop.checked = 1 THEN
				SQL=SQL + " AND yop='" + document.getElementById('T_yop').value + "'"
			END IF
		ELSEIF C_yoj.checked = 1 THEN
			SQL=SQL + "yoj='" + document.getElementById('T_yoj').value + "'"
			IF C_yop.checked = 1 THEN
				SQL=SQL + " AND yop='" + document.getElementById('T_yop').value "'"
			END IF
		ELSEIF C_yop.checked = 1 THEN
			SQL=SQL + "yoj='" + document.getElementById('T_yoj').value + "'"
		END IF
	END IF
	
	var url1="srchj1.asp?SQL=" + SQL + "&sid=" + Math.random();
	alert(url);
	xmlhttp.open('GET',url,true);
	xmlhttp.onreadystatechange=stateChanged;
	xmlhttp.send(null);
}