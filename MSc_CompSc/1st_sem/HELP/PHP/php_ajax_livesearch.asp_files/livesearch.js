var xmlhttp;

function showResult(str)
{
if (str.length==0)
  {
  document.getElementById("livesearch").
  innerHTML="";
  document.getElementById("livesearch").
  style.border="0px";
  return;
  }
xmlhttp=GetXmlHttpObject()

if (xmlhttp==null)
  {
  alert ("Browser does not support HTTP Request");
  return;
  }
var url="livesearch.php";
url=url+"?q="+str;
url=url+"&sid="+Math.random();
xmlhttp.onreadystatechange=stateChanged ;
xmlhttp.open("GET",url,true);
xmlhttp.send(null);
}

function stateChanged()
{
if (xmlhttp.readyState==4)
  {
  document.getElementById("livesearch").
  innerHTML=xmlhttp.responseText;
  document.getElementById("livesearch").
  style.border="1px solid #A5ACB2";
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