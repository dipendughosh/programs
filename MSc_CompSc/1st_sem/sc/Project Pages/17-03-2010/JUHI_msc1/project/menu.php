<html>
<head>
<style type="text/css">
body{font-family:calibri bold italic;}
table{font-size:80%;background:black}
a{color:white;text-decoration:underline;font:bold}
a:hover{color:"#060606"}
td.menu{background:"#00a3cc"}
table.menu
{
font-size:100%;
position:absolute;
visibility:hidden;
}

#navlist{position:relative;}
#navlist li{margin:0;padding:0;list-style:none;position:absolute;top:0;}
#navlist li, #navlist a{height:92px;display:block;}

#home{left:0px;width:77px;}
#home{background:url('C:\icons\h3.jpg') 0 0;}
#home a:hover{background: url('C:\icons\h3.jpg') 0 -90px;}


</style>
<script type="text/javascript">
function showmenu(elmnt)
{
document.getElementById(elmnt).style.visibility="visible";
}
function hidemenu(elmnt)
{
document.getElementById(elmnt).style.visibility="hidden";
}
</script>
</head>

<body>
<ul id="navlist">
  <li id="home"><a href="http://localhost/pub.php"></a></li>
</ul>
<h3 align=center>FACULTY DETAILS DATABASE</h3>

</br>
</br>
<table width="100%">
 <tr bgcolor="#003f55">
  <td onmouseover="showmenu('personal_details')" onmouseout="hidemenu('personal_details')">
   <a href="/default.asp">PERSONAL DETAILS</a><br />
   <table class="menu" id="personal_details" width="120">
   <tr><td class="menu"><a href="/html/default.asp">Enter New Details</a></td></tr>
   <tr><td class="menu"><a href="/xhtml/default.asp">View Details</a></td></tr>
   <tr><td class="menu"><a href="/css/default.asp">Modify Details</a></td></tr>
   </table>
  </td>
  <td onmouseover="showmenu('conference')" onmouseout="hidemenu('conference')">
   <a href="/default.asp">CONFERENCE</a><br />
   <table class="menu" id="conference" width="120">
   <tr><td class="menu"><a href="/js/default.asp">Enter New Details</a></td></tr>
   <tr><td class="menu"><a href="/vbscript/default.asp">View Conferences</a></td></tr>
   </table>
  </td>
  <td onmouseover="showmenu('projects')" onmouseout="hidemenu('projects')">
   <a href="/site/site_validate.asp">PROJECTS</a><br />
   <table class="menu" id="projects" width="120">
   <tr><td class="menu"><a href="/site/site_validate.asp">Enter New Details</a></td></tr>
   <tr><td class="menu"><a href="/site/site_validate.asp">View Projects</a></td></tr>
   <tr><td class="menu"><a href="/site/site_validate.asp">Modify projects</a></td></tr>
   </table>
  </td>
  <td onmouseover="showmenu('publications')" onmouseout="hidemenu('publications')">
   <a href="/default.asp">PUBLICATIONS</a><br />
   <table class="menu" id="publications" width="120">
   <tr><td class="menu"><a href="/js/default.asp">Enter New Details</a></td></tr>
   <tr><td class="menu"><a href="/vbscript/default.asp">View Publications</a></td></tr>
   </table>
  </td>
  <td onmouseover="showmenu('patents')" onmouseout="hidemenu('patents')">
   <a href="/default.asp">PATENTS</a><br />
   <table class="menu" id="patents" width="120">
   <tr><td class="menu"><a href="/js/default.asp">Enter New Details</a></td></tr>
   <tr><td class="menu"><a href="/vbscript/default.asp">View Patents</a></td></tr>
   </table>
  </td>
 </tr>
</table>
<p>Mouse over these options to see the drop down menus</p>
</body>

</html>

