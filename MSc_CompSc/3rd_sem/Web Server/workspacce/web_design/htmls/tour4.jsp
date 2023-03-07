<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">

<%@ page import="java.sql.Connection" %>
<%@ page import="java.sql.DriverManager" %>
<%@ page import="com.mysql.jdbc.ResultSet" %> 
<%@ page import="com.mysql.jdbc.Statement" %>
<html>
<head>

<title>Paradise Tour And Travels:: </title>
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

</head>
<body onload="x();">
<div id="container">
<div id="g_image3" style="position:absolute; overflow:hidden; left:204px; top:143px; width:28px; height:47px; z-index:0"><img src="images/topmenu_img1.gif" alt="" title="" border=0 width=28 height=47></div>

<div id="g_image5" style="position:absolute; overflow:hidden; left:18px; top:190px; width:187px; height:250px; z-index:1"><img src="images/users_feedback_bg.gif" alt="" title="" border=0 width=187 height=85></div>

<div id="g_image2" style="position:absolute; overflow:hidden; left:18px; top:143px; width:187px; height:47px; z-index:2"><img src="images/users_feedback_s.gif" alt="" title="" border=0 width=187 height=47></div>

<div id="g_image9" style="position:absolute; overflow:hidden; left:229px; top:690px; width:536px; height:47px; z-index:3"><img src="images/botmenu_bg.gif" alt="" title="" border=0 width=536 height=47></div>

<div id="g_image10" style="position:absolute; overflow:hidden; left:16px; top:690px; width:187px; height:47px; z-index:4"><img src="images/bot1.gif" alt="" title="" border=0 width=187 height=47></div>

<div id="g_image8" style="position:absolute; overflow:hidden; left:203px; top:690px; width:28px; height:47px; z-index:5"><img src="images/bot2.gif" alt="" title="" border=0 width=28 height=47></div>

<div id="g_image4" style="position:absolute; overflow:hidden; left:231px; top:143px; width:534px; height:47px; z-index:6"><img src="images/products_b.gif" alt="" title="" border=0 width=534 height=47></div>

<div id="g_shape1" style="position:absolute; overflow:hidden; left:16px; top:740px; width:751px; height:15px; z-index:7"><img border=0 width="100%" height="100%" alt="" src="images/shape483515.gif"></div>

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




<div id="text2" style="position:absolute; overflow:hidden; left:420px; top:154px; width:458px; height:20px; z-index:14">
<div class="wpmd">
<div><font face="Tahoma"><B><a href="index.jsp" title="" class="style1">HOME</a></B></font><font color="#333333" face="Tahoma"><B>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </B></font><font face="Tahoma"><B><a href="schedule.jsp" title="" class="style1">CHECK TOUR SCHEDULE</a></B></font><font color="#333333" face="Tahoma"><B>&nbsp;&nbsp;&nbsp; </B></font><font face="Tahoma"><B><a href="help.jsp" title="" class="style1">HELP</a></B></font><font color="#333333" face="Tahoma"><B>&nbsp;&nbsp;&nbsp; </B></font><font face="Tahoma"><B><a href="contact.jsp" title="" class="style1">CONTACTS</a></B></font></div>
</div></div>



<div id="text4" style="position:absolute; overflow:hidden; left:272px; top:700px; width:495px; height:30px; z-index:16">
<div class="wpmd">
<div><font face="Tahoma">Designed And Developed By dept. of Computer Science And Engineering 2011-2012</font></div>
</div></div>

<div id="text5" style="position:absolute; overflow:hidden; left:250px; top:20px; width:700px; height:41px; z-index:19">
<div class="wpmd">
<div align=center><font color="#FFFFFF" face="Times New Roman" class="ws18"><B>TRAVELLERS' PARADISE</B></font></div>
</div></div>
<div id="image2" style="position:absolute; overflow:hidden; left:217px; top:196px; width:550px; height:450px; z-index:11"><img src="images/new_releases_s.gif" alt="" title="" border=0 width=532 height=430 style="border:#CCFFFF 9px ridge"></div>

<div id="text1" style="position:absolute; overflow:hidden; left:225px; top:238px; width:532px; height:90px; z-index:12">
<div class="wpmd">
<div align=center><font color="#000080" face="Algerian" class="ws24"><B><U>MUMBAI & GOA TOUR SCHEDULE</U></B></font></div>
</div></div>

<div id="html1" style="position:absolute; overflow:hidden; left:270px; top:320px; width:550px; height:550px; z-index:13">
<pre>
MUMBAI & GOA ( 10 DAYS PROGRAMME ) Rs. 20000/- per head
1st Day 	Howrah Station	: 	 
2nd Day 	Train Journey : 	
3rd Day 	Arrive Mimbai 	: 	
4th Day 	Mumbai Site Scene : 	
5th Day 	Way to Goa  : 	
6th Day 	North Goa Tour	: 	
7th Day 	South Goa & river Cruise  	: 	
8th Day 	Site Scene 	: 	
9th Day		Goa Station :
10th Day	Howrah Station :
</pre>
<div id="nav10d" style="position:absolute; left:10px; top:230px; z-index:0"><a onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('nav10','','images/nav412959060a.gif',1)" href="photo4.jsp"><img name="nav10" onLoad="MM_preloadImages('images/nav412959060a.gif')" alt="" border=0 src="images/nav412959060i.gif"></a></div>
<div id="nav10d" style="position:absolute; left:185px; top:230px; z-index:0"><a onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('nav10','','images/nav412572960a.gif',1)" href="avail4.jsp"><img name="nav10" onLoad="MM_preloadImages('images/nav412572960a.gif')" alt="" border=0 src="images/nav412572960i.gif"></a></div>
<div id="nav10d" style="position:absolute; left:350px; top:230px; z-index:0"><a onMouseOut="MM_swapImgRestore()" onMouseOver="MM_swapImage('nav10','','images/nav411604840a.gif',1)" href="book4.jsp"><img name="nav10" onLoad="MM_preloadImages('images/nav411604840a.gif')" alt="" border=0 src="images/nav411604840i.gif"></a></div>

</div>

</body>
</html>
