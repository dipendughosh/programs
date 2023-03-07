var xmlhttp,CONF;

function SignOut()
	{
		xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}
	var Lusrname= document.getElementById('Lusrname').value;
	var url ="logout.asp?LOGIN_usrname="+Lusrname+"&sid="+Math.random();
	alert(url);
	xmlhttp.open('GET',url,true);
	xmlhttp.onreadystatechange=stateChanged;
	xmlhttp.send(null);
	}

function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				document.getElementById('Lusrname').innerHtml=xmlhttp.responseText;
				window.location = "http://www.alumni.cucse.org/index.html";
			}	
		}

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
		
		function noCacheCopy()
		{
			if(document.getElimentById('Lusrname').value="expired")
			{
				window.location = "http://www.alumni.cucse.org/index.html";
			}
		}
		