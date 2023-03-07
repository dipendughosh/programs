function start(theForm)
{
	checkEmpty(theForm);
}

function chekEmpty(theForm)
{
	var alId;
	alId=document.getElementById('C_alumniId').value;
	if(alId == True)
	{
		alert("Alumni ID is missing");
		return;
	}
	else
	{
		var a1,a2,a3;
		a1=document.getElementById('C_name').value;
		a2=document.getElementById('C_yoj').value;
		a3=document.getElementById('C_yoj').value;
		if(a1 == True)
		{
			alert("Alumni Name is missing");
		}
		else if(a2 == True)
		{
			alert("Year of Joining is missing");
		}
		else if(a3 == True)
		{
			alert("Year of Passing is missing");
		}
	}
}