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

	var Surname,Name,Sex,Dob,PrAdd,PrPin,PrLandmark,Mobile,Std,Landline,EmailPer,EmailOff,PtAdd,PtPin,PtLandmark,btech,msc,mtech,phd,YearJoin,YearPass,occ,Com,CurProf,CurDesg,CurCom,CCAdd,CCPin,CCLandmark,CCStd,CCLand,CCFaxStd,CCFax,CaFrom,CaTo,CaName,CbFrom,Cbto,CbName,Dec;
			
	Surname=document.getElementByName('Surname').value;
	Name=document.getElementByName('Name').value;
	Sex=document.getElementByName('Sex').value;
	Dob=document.getElementByName('Dob').value;
	PrAdd=document.getElementByName('PrAdd').value;
	PrPin=document.getElementByName('PrPin').value;
	PrLandmark=document.getElementByName('PrLandmark').value;
	Mobile=document.getElementByName('Mobile').value;
	Std=document.getElementByName('Std').value;
	Landline=document.getElementByName('Landline').value;
	EmailPer=document.getElementByName('EmailPer').value;
	EmailOff=document.getElementByName('EmailOff').value;
	PtAdd=document.getElementByName('PtAdd').value;
	PtPin=document.getElementByName('PtPin').value;
	PtLandmark=document.getElementByName('PtLandmark').value;
	btech=document.getElementByName('btech').value;
	msc=document.getElementByName('msc').value;
	mtech=document.getElementByName('mtech').value;
	phd=document.getElementByName('phd').value;
	YearJoin=document.getElementByName('YearJoin').value;
	YearPass=document.getElementByName('YearPass').value;
	occ=document.getElementByName('occ').value;
	Com=document.getElementByName('Com').value;
	CurProf=document.getElementByName('CurProf').value;
	CurDesg=document.getElementByName('CurDesg').value;
	CurCom=document.getElementByName('CurCom').value;
	CCAdd=document.getElementByName('CCAdd').value;
	CCPin=document.getElementByName('CCPin').value;
	CCLandmark=document.getElementByName('CCLandmark').value;
	CCStd=document.getElementByName('CCStd').value;
	CCL=document.getElementByName('CCL').value;
	CCFaxStd=document.getElementByName('CCFaxStd').value;
	CCFax=document.getElementByName('CCFax').value;
	CaFrom=document.getElementByName('CaFrom').value;
	CaTo=document.getElementByName('CaTo').value;
	CaName=document.getElementByName('CaName').value;
	CbFrom=document.getElementByName('CbFrom').value;
	Cbto=document.getElementByName('Cbto').value;
	CbName=document.getElementByName('CbName').value;
	Dec=document.getElementByName('Dec').value;

		var InsertSql="Insert into profile values('"+ Surname +"','"+Name+"','"+Sex+"','"+Dob+"','"+PrAdd+"','"+PrPin+"','"+PrLandmark+"','"+Mobile+"','"+Std+"','"+Landline+"','"+EmailPer+"','"+EmailOff+"','"+PtAdd+"','"+PtPin+"','"+PtLandmark+"','"+btech+"','"+msc+"','"+mtech+"','"+phd+"','"+YearJoin+"','"+YearPass+"','"+occ+"','"+Com+"','"+CurProf+"','"+CurDesg+"','"+CurCom+"','"+CCAdd+"','"+CCPin+"','"+CCLandmark+"','"+CCStd+"','"+CCL+"','"+CCFaxStd+"','"+CCFax+"','"+CaFrom+"','"+CaTo+"','"+CaName+"','"+Cbto+"','"+CbName+"';";
	

	
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