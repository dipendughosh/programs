<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<%@ page import="java.sql.Connection" %>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="com.mysql.jdbc.ResultSet" %> 
<%@ page import="com.mysql.jdbc.Statement" %>

<html>
<head>
<title>Paradise Tour And Travels:: Tour Schedule</title>

<style type="text/css">
/*----------Text Styles----------*/
.ws6 {font-size: 8px;}
.ws7 {font-size: 9.3px;}
.ws8 {font-size: 11px;}
.ws9 {font-size: 12px;}
.ws10 {font-size: 13px;}
.ws11 {font-size: 15px;}
.ws12 {font-size: 16px;}
.ws14 {font-size: 19px;}
.ws16 {font-size: 21px;}
.ws18 {font-size: 24px;}
.ws20 {font-size: 27px;}
.ws22 {font-size: 29px;}
.ws24 {font-size: 32px;}
.ws26 {font-size: 35px;}
.ws28 {font-size: 37px;}
.ws36 {font-size: 48px;}
.ws48 {font-size: 64px;}
.ws72 {font-size: 96px;}
.wpmd {font-size: 13px;font-family: Arial,Helvetica,Sans-Serif;font-style: normal;font-weight: normal;}
/*----------Para Styles----------*/
DIV,UL,OL /* Left */
{
 margin-top: 0px;
 margin-bottom: 0px;
}
</style>

<style type="text/css">
a.style2:link{color:#FF6600;text-decoration: none;}
a.style2:visited{color:#FF6600;text-decoration: none;}
a.style2:hover{color:#99CC00;background:#ECFFEC;text-decoration: none;}
a.style2:active{text-decoration: none;}
a.style1:link{color:#333399;text-decoration: none;}
a.style1:visited{color:#333399;text-decoration: none;}
a.style1:hover{color:#333399;text-decoration: none;}
a.style1:active{color:#333399;text-decoration: none;}
a.style3:link{color:#FF6600;text-decoration: none;}
a.style3:visited{color:#FF6600;text-decoration: none;}
a.style3:hover{color:#99CC00;background:#ECFFEC;text-decoration: none;}
a.style3:active{text-decoration: none;}
 a:hover { text-decoration:none;} /*BG color is a must for IE6*/
  
      a.tooltip span {display:none; padding:2px 3px; margin-left:8px; width:400px; height:40px;}
  
      a.tooltip:hover span{display:inline; position:absolute; background:#ffffff; border:2px solid #cccccc; color:#6c6c6c;}

</style>

<script src="ac_activex.js" type="text/javascript"></script>

<style type="text/css">
div#container
{
	position:relative;
	width: 783px;
	margin-top: 0px;
	margin-left: auto;
	margin-right: auto;
	text-align:left; 
}
body {text-align:center;margin:0}
</style>
<style type="text/css">
<!--

a {
	border-bottom: 1px dashed brown;
	text-decoration: none;
}

a:hover {
	position: relative;
}

a span {
	display: none;
}

a:hover span {
	display: block;
   	position: absolute; top: 10px; left: 0;
	/* formatting only styles */
   	padding: 5px; margin: 10px; z-index: 100;
   	background:black; border: 1px dotted #c0c0c0;
	opacity: 0.9;
        color:white
        height:40px;
        width:200px
	/* end formatting */
}

-->
</style>
</head>
<body>
<div id="container">
<div id="g_image3" style="position:absolute; overflow:hidden; left:204px; top:143px; width:28px; height:47px; z-index:0"><img src="images/topmenu_img1.gif" alt="" title="" border=0 width=28 height=47></div>

<div id="g_image5" style="position:absolute; overflow:hidden; left:18px; top:190px; width:187px; height:250px; z-index:1"><img src="images/users_feedback_bg.gif" alt="" title="" border=0 width=187 height=85></div>

<div id="g_image2" style="position:absolute; overflow:hidden; left:18px; top:143px; width:187px; height:47px; z-index:2"><img src="images/users_feedback_s.gif" alt="" title="" border=0 width=187 height=47></div>

<div id="g_image9" style="position:absolute; overflow:hidden; left:229px; top:829px; width:536px; height:47px; z-index:3"><img src="images/botmenu_bg.gif" alt="" title="" border=0 width=536 height=47></div>

<div id="g_image10" style="position:absolute; overflow:hidden; left:16px; top:829px; width:187px; height:47px; z-index:4"><img src="images/bot1.gif" alt="" title="" border=0 width=187 height=47></div>

<div id="g_image8" style="position:absolute; overflow:hidden; left:203px; top:829px; width:28px; height:47px; z-index:5"><img src="images/bot2.gif" alt="" title="" border=0 width=28 height=47></div>

<div id="g_image4" style="position:absolute; overflow:hidden; left:231px; top:143px; width:534px; height:47px; z-index:6"><img src="images/products_b.gif" alt="" title="" border=0 width=534 height=47></div>

<div id="g_shape1" style="position:absolute; overflow:hidden; left:16px; top:879px; width:751px; height:15px; z-index:7"><img border=0 width="100%" height="100%" alt="" src="images/shape483515.gif"></div>

<div id="marquee1" style="position:absolute; overflow:hidden; left:30px; top:201px; width:157px; height:250px; z-index:8">
<marquee width="157" height="250" direction="Up" scrolldelay="250">
<div class="wpmd">

<%
      try {
    	  Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/tour", "root", "");
			Statement st = (Statement) con.createStatement();
			ResultSet rs = (ResultSet) st.executeQuery("select distinct title from tour_schedule");
			int i=0;
    while (rs.next()) { i++;
    %>
    
        <div><font class="ws12" color="#666699\"> <a  href="tour<%= i %>.jsp"> <%=rs.getString(1)%> </a><br/><br/></font></div>
        
    <%   }    %>
    <%
    // close all the connections.
    rs.close();
    st.close();
    con.close();
} catch (Exception ex) {
    %>
    <font size="+3" color="red">unable to connect database</font>
        <%
                
            }
        %>
   

<div><font class="ws9" color="#66699"><center>*****</center></font></div>
</div></marquee>
</div>

<div id="g_text4" style="position:absolute; overflow:hidden; left:35px; top:159px; width:159px; height:162px; z-index:9">
<div class="wpmd">
<div><font color="#666699" class="ws9"><B>SELECT A TOUR</B></font></div>
<div><font color="#666699" class="ws9"><B><BR></B></font></div>
<div><font color="#666699" class="ws9"><BR></font></div>
</div></div>

<div id="g_image1" style="position:absolute; overflow:hidden; left:424px; top:1px; width:340px; height:141px; z-index:10"><img src="images/b001main_right.jpg" alt="" title="" border=0 width=340 height=141></div>

<div id="g_flash1" style="position:absolute; overflow:hidden; left:18px; top:0px; width:407px; height:142px; z-index:11">
<script type="text/javascript">
AC_RunFlashContent("id","g_flash1","width","407","height","142","quality","high","autoplay","false","loop","true","wmode","transparent","codebase","http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab","pluginspage","http://www.macromedia.com/go/getflashplayer","src","images/arrowhead.swf");
</script>
<noscript>
<object classid="clsid:D27CDB6E-AE6D-11CF-96B8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab" width=407 height=142>
<param name="movie" value="images/arrowhead.swf">
<param name="quality" value="high">
<param name="loop" value="true">
<param name="wmode" value="transparent">
<param name="autoplay" value="false">
<!--[if !IE]>-->
<object data="images/arrowhead.swf" width="407" height="142" type="application/x-shockwave-flash">
<param name="pluginurl" value="http://www.macromedia.com/go/getflashplayer">
<param name="quality" value="high">
<param name="loop" value="true">
<param name="wmode" value="transparent">
<param name="autoplay" value="false">
</object>
<!--<![endif]-->
</object>
</noscript>
</div>

<div id="slideshow1" style="position:absolute; overflow:hidden; left:221px; top:225px; width:540px; height:600px; z-index:12">
<object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://fpdownload.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,0,0" width="540" height="600" id="tech" align="middle" quality="high" allowFullScreen="true" wmode="transparent" allowScriptAccess="always">
    <param name="movie" value="images/andaman.swf" />
    <param name="quality" value="high" />
    <param name="allowFullScreen" value="true" />
    <param name="wmode" value="transparent" />
    <param name="allowScriptAccess" value="always" />
    <param name="_flashcreator" value="http://www.photo-flash-maker.com" />
    <param name="_flashhost" value="http://www.go2album.com" />
    <embed src="images/andaman.swf" width="382" height="286" quality="high" allowFullScreen="true" wmode="transparent" allowScriptAccess="always" name="tech" align="middle" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer" />
  </object>

</div>



<div id="text2" style="position:absolute; overflow:hidden; left:420px; top:154px; width:458px; height:20px; z-index:14">
<div class="wpmd">
<div><font face="Tahoma"><B><a href="index.jsp" title="" class="style1">HOME</a></B></font><font color="#333333" face="Tahoma"><B>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </B></font><font face="Tahoma"><B><a href="schedule.jsp" title="" class="style1">CHECK TOUR SCHEDULE</a></B></font><font color="#333333" face="Tahoma"><B>&nbsp;&nbsp;&nbsp; </B></font><font face="Tahoma"><B><a href="help.jsp" title="" class="style1">HELP</a></B></font><font color="#333333" face="Tahoma"><B>&nbsp;&nbsp;&nbsp; </B></font><font face="Tahoma"><B><a href="contact.jsp" title="" class="style1">CONTACTS</a></B></font></div>
</div></div>





<div><font color="#000080"><BR></font></div>
</div>

<div id="text4" style="position:absolute; overflow:hidden; left:472px; top:836px; width:495px; height:90px; z-index:16">
<div class="wpmd">
<a  href="#" class="tip"><font face="Tahoma">Designed And Developed </font><span><font color="yellow">Angana Chakraborty,Priyanka Das</font></span></a>By dept. of Computer Science And Engineering 2011-2012




<div></div>
</div></div>


<div id="text5" style="position:absolute; overflow:hidden; left:450px; top:20px; width:700px; height:41px; z-index:19">
<div class="wpmd">
<div align=center><font color="#FFFFFF" face="Times New Roman" class="ws18"><B>TRAVELERS' PARADISE</B></font></div>
</div></div>

</body>
</html>
