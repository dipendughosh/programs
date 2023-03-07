var xmlhttp;
var CONF;	
var LOGIN_usrname,LOGIN_password,LIO_StatusId;

function start()
{	
	alert("llll");
	insert_AJAX();
}
function insert_AJAX()
{
		alert("llll");
		xmlhttp=GetXmlHttpObject();
				if (xmlhttp==null)
				{
					alert ("Browser does not support HTTP Request");
					return;
				}

	var Surname;
	var Name;
	var Sex,Dob,PrAdd,PrPin,PrLandmark,Mobile,Std,Landline,EmailPer,EmailOff,PtAdd,PtPin,PtLandmark,btech,msc,mtech,phd,YearJoin,YearPass,occ,Com,CurProf,CurDesg,CurCom,CCAdd,CCPin,CCLandmark,CCStd,CCLand,CCFaxStd,CCFax,CaFrom,CaTo,CaName,CbFrom,Cbto,CbName,Dec;
	
	Surname=document.getElementById("surname").value;
	Name=document.getElementById("Name").value;
	Sex=document.getElementById("Sex").value;
	Dob=document.getElementById("Dob").value;
	PrAdd=document.getElementById("PrAdd").value;
	PrPin=document.getElementById("PrPin").value;
	PrLandmark=document.getElementById("PrLandmark").value;
	Mobile=document.getElementById("Mobile").value;
	Std=document.getElementById("Std").value;
	Landline=document.getElementById("Landline").value;
	EmailPer=document.getElementById("EmailPer").value;
	EmailOff=document.getElementById("EmailOff").value;
	PtAdd=document.getElementById("PtAdd").value;
	PtPin=document.getElementById("PtPin").value;
	PtLandmark=document.getElementById("PtLandmark").value;
	btech=document.getElementById("btech").value;
	msc=document.getElementById("msc").value;
	mtech=document.getElementById("mtech").value;
	phd=document.getElementById("phd").value;
	YearJoin=document.getElementById("YearJoin").value;
	YearPass=document.getElementById("YearPass").value;
	occ=document.getElementById("occ").value;
	Com=document.getElementById("Com").value;
	CurProf=document.getElementById("CurProf").value;
	CurDesg=document.getElementById("CurDesg").value;
	CurCom=document.getElementById("CurCom").value;
	CCAdd=document.getElementById("CCAdd").value;
	CCPin=document.getElementById("CCPin").value;
	CCLandmark=document.getElementById("CCLandmark").value;
	CCStd=document.getElementById("CCStd").value;
	CCLand=document.getElementById("CCLand").value;
	CCFaxStd=document.getElementById("CCFaxStd").value;
	CCFax=document.getElementById("CCFax").value;
	CaFrom=document.getElementById("CaFrom").value;
	CaTo=document.getElementById("CaTo").value;
	CaName=document.getElementById("CaName").value;
	CbFrom=document.getElementById("CbFrom").value;
	Cbto=document.getElementById("Cbto").value;
	CbName=document.getElementById("CbName").value;
	Dec=document.getElementById("Dec").value;
		
	var InsertSql="Insert into profile values('"+ Surname +"','"+Name+"','"+Sex+"','"+Dob+"','"+PrAdd+"','"+PrPin+"','"+PrLandmark+"','"+Mobile+"','"+Std+"','"+Landline+"','"+EmailPer+"','"+EmailOff+"','"+PtAdd+"','"+PtPin+"','"+PtLandmark+"','"+btech+"','"+msc+"','"+mtech+"','"+phd+"','"+YearJoin+"','"+YearPass+"','"+occ+"','"+Com+"','"+CurProf+"','"+CurDesg+"','"+CurCom+"','"+CCAdd+"','"+CCPin+"','"+CCLandmark+"','"+CCStd+"','"+CCLand+"','"+CCFaxStd+"','"+CCFax+"','"+CaFrom+"','"+CaTo+"','"+CaName+"','"+Cbto+"','"+CbName+"');";
	

	var url="InsertIntoProfile.asp";
	url=url+"?InsertSql="+InsertSql+"&Std="+Math.random();	 
	alert(url);
	xmlhttp.open('GET',url,true);
	xmlhttp.onreadystatechange=stateChanged;
	xmlhttp.send(null);
}

function stateChanged()
		{
			if (xmlhttp.readyState==4)
			{
				alert(xmlhttp.responseText);
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