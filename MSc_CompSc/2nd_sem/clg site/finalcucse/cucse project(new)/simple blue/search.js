var xmlhttp;
var CONF;	
var LOGIN_usrname,LOGIN_password,LIO_StatusId;

function start()
{

		xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}
			
	if(document.IDform.getElementById('C_alumniId').checked== true)
	 {
		var T_alumniId=document.IDform.getElementById('C_alumniId').value;
		if(T_alumniId=="")
		  {
			alert("ID Field Is Selected but Empty !!!");
			return;
		  }	
	 }

	if(document.Detailsform.getElementById('C_name').checked== true)
	 {
		var T_name=document.Detailsform.getElementById('T_name').value;
		if(T_name=="")
		  {
			alert("Name Field Is Selected but Empty !!!");
			return;
		  }	
	 }

	if(document.Detailsform.getElementById('C_yoj').checked== true)
	 {
		var T_yoj=document.Detailsform.getElementById('T_yoj').value;
		if(T_yoj=="")
		  {
			alert("Year Of Joining Field Is Selected but Empty !!!");
			return;
		  }	
	 }
	if(document.Detailsform.getElementById('C_yop').checked== true)
	 {
		var T_yop=document.Detailsform.getElementById('T_yop').value;
		if(T_yop=="")
		  {
			alert("Year Of Passing Field Is Selected but Empty !!!");
			return;
		  }	
	 }
	
	/*var url="login.asp";
	LIO_StatusId=Math.random();
	LIO_StatusId=LIO_StatusId*1000;
	LIO_StatusId=Math.floor(LIO_StatusId);

	url=url+"?LOGIN_usrname="+LOGIN_usrname+"&LOGIN_password="+LOGIN_password+"&LIO_StatusId="+LIO_StatusId;	 
	alert(url);
	xmlhttp.open('GET',url,true);
	xmlhttp.onreadystatechange=stateChanged;
	xmlhttp.send(null);*/
}

/*function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				alert(xmlhttp.responseText);
				
				if(xmlhttp.responseText=="NO")
					alert("Wrong User Name/Password");
				else 
					{							
						var url1="defaultP_1.asp?LIO_StatusId="+LIO_StatusId+"&LOGIN_usrname="+LOGIN_usrname;	
						alert(url1);
						window.location = "defaultP_1.asp?LIO_StatusId="+LIO_StatusId+"&LOGIN_usrname="+LOGIN_usrname;
					}
			}	
		}*/

		function GetXmlHttpObject()
		{
			if (window.XMLHttpRequest)
			{
				// code for IE7+, Firefox, Chrome, Opera, Safari
				return new XMLHttpRequest();
			}
			if (window.ActiveXObject)
			{
				// code for IE6, IE5
				return new ActiveXObject("Microsoft.XMLHTTP");
			}
		return null;
		}			