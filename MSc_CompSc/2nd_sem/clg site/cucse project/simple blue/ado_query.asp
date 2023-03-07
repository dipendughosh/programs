<!DOCTYPE HTML PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en-US" lang="en-US"><head>



<title>ADO Queries</title>
 
<link rel="shortcut icon" href="http://w3schools.com/favicon.ico" 
type="image/x-icon">
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<meta name="Keywords" 
content="xml,tutorial,html,dhtml,css,xsl,xhtml,javascript,asp,ado,vbscript,dom,sql,colors,soap,php,authoring,programming,training,learning,beginner's
 guide,primer,lessons,school,howto,reference,examples,samples,source 
code,tags,demos,tips,links,FAQ,tag list,forms,frames,color 
table,w3c,cascading style sheets,active server pages,dynamic 
html,internet,database,development,Web building,Webmaster,html guide">

<meta name="Description" content="Free HTML XHTML CSS JavaScript DHTML 
XML DOM XSL XSLT RSS AJAX ASP ADO PHP SQL tutorials, references, 
examples for web building.">

<meta http-equiv="pragma" content="no-cache">
<meta http-equiv="cache-control" content="no-cache">
<meta http-equiv="expires" content="-1">

<link rel="stylesheet" type="text/css" 
href="ado_query_files/stdtheme.css">

<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? "https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + "google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script><script src="ado_query_files/ga.js" type="text/javascript"></script>
<script type="text/javascript">
function searchfield_focus(obj)
{
obj.style.color=""
obj.style.fontStyle=""
if (obj.value=="Search W3Schools")
	{
	obj.value=""
	}
}

var pageTracker = _gat._getTracker("UA-3855518-1");
pageTracker._initData();
pageTracker._trackPageview();
</script>
<!--[if gt IE 7]>
<style>
body
{
overflow-y:scroll;
}
</style>
<![endif]-->


<script src="ado_query_files/osd.js" type="text/javascript"></script></head><body>

<center>
<table style="width: 902px; margin-top: 0px; margin-bottom: 0px; 
background-color: rgb(255, 255, 255);" border="0" cellpadding="0" 
cellspacing="0">
<tbody><tr><td align="center"><a name="top"></a>

<table style="margin-top: 1px; background-color: rgb(96, 96, 96); 
border-bottom: 1px solid black;" width="890" border="0" cellpadding="0" 
cellspacing="0">
<tbody><tr style="height: 47px;">
<td width="15">&nbsp;</td>
<td style="text-align: left;" valign="middle" width="500">
<a href="http://www.w3schools.com/">
<img style="margin-top: 6px;" src="ado_query_files/h_logo.gif" 
alt="w3schools" title="w3schools" height="20" width="203" border="0"></a>
</td>
<td valign="bottom" align="right">
<form style="font-size: 10px; margin-bottom: 10px;" method="get" 
name="searchform" action="http://www.google.com/search" target="_blank">
<table border="0" cellpadding="0" cellspacing="0"><tbody><tr>
<td><input name="sitesearch" value="www.w3schools.com" type="hidden"></td>
<td><input onfocus="searchfield_focus(this)" style="width: 128px; color:
 rgb(128, 128, 128); font-style: italic;" alt="search" name="as_q" 
size="20" value="Search W3Schools" type="text"></td>
<td><input value="Search" title="Search W3Schools" type="submit"></td>
</tr></tbody></table>
</form>
</td>
<td>&nbsp;&nbsp;</td>
</tr>
</tbody></table>

<table style="margin: 0px 0px 2px; padding: 0px; background-color: 
rgb(96, 96, 96);" width="890" border="0" cellpadding="0" cellspacing="0">
<tbody><tr style="height: 20px;">
<td class="blacknav" style="border-left: medium none;" width="50"><a 
class="m_item" href="http://w3schools.com/default.asp" target="_top">HOME</a></td>
<td class="blacknav" width="50"><a class="m_item" 
href="http://w3schools.com/html/default.asp" target="_top">HTML</a></td>
<td class="blacknav" width="40"><a class="m_item" 
href="http://w3schools.com/css/default.asp" target="_top">CSS</a></td>
<td class="blacknav" width="40"><a class="m_item" 
href="http://w3schools.com/xml/default.asp" target="_top">XML</a></td>
<td class="blacknav" width="90"><a class="m_item" 
href="http://w3schools.com/js/default.asp" target="_top">JAVASCRIPT</a></td>
<td class="blacknav" width="40"><a class="m_item" 
href="http://w3schools.com/asp/default.asp" target="_top">ASP</a></td>
<td class="blacknav" width="40"><a class="m_item" 
href="http://w3schools.com/php/default.asp" target="_top">PHP</a></td>
<td class="blacknav" width="40"><a class="m_item" 
href="http://w3schools.com/sql/default.asp" target="_top">SQL</a></td>
<td class="blacknav" width="60"><a class="m_item" 
href="http://w3schools.com/sitemap/sitemap_tutorials.asp" target="_top">MORE...</a></td>
<td class="blacknav">&nbsp;</td>
<td class="blacknav" width="80"><a class="m_item" 
href="http://w3schools.com/sitemap/sitemap_references.asp" target="_top">References</a></td>
<td class="blacknav" width="70"><a class="m_item" 
href="http://w3schools.com/sitemap/sitemap_examples.asp" target="_top">Examples</a></td>
<td class="blacknav" width="50"><a class="m_item" 
href="http://w3schools.com/forum/default.asp" target="_blank">Forum</a></td>
<td class="blacknav" style="border-right: medium none;" width="50"><a 
class="m_item" href="http://w3schools.com/about/default.asp" 
target="_top">About</a></td>
</tr>
</tbody></table>

<div style="width: 890px; height: 94px; position: relative; margin: 0px;
 padding: 0px; overflow: hidden;">

<div class="toprect_img">
<b>BEST WEB HOSTING</b>
<a target="_blank" rel="nofollow" 
href="http://stats.justhost.com/track?cb9f3a2d1dcf0bf26abe2da7b079bcbdf"><img
 style="position: absolute; left: 0px; bottom: 0px;" 
src="ado_query_files/justhost_155x75.gif" alt="JustHosts" border="0"></a><br>

</div><div style="width: 728px; height: 90px; position: absolute; right:
 0px; top: 0px;">
<iframe id="leaderframe" style="background-color: rgb(255, 255, 255); 
height: 90px; width: 728px;" src="ado_query_files/leaderframe.asp" 
marginwidth="0" marginheight="0" frameborder="0" height="90" 
scrolling="no" width="728">
Your browser does not support inline frames or is currently configured 
not to display inline frames.
</iframe>
</div></div>

<table style="padding: 0pt;" width="890" border="0" cellpadding="0" 
cellspacing="0">
<tbody><tr><td id="leftcolumn" valign="top" width="161" align="left">
<div style="margin-left: 1px; margin-top: 5px;"><h2 class="left"><span 
class="left_h2">ADO</span> Tutorial</h2>
<a target="_top" href="http://w3schools.com/ado/default.asp">ADO HOME</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_intro.asp">ADO Intro</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_connect.asp">ADO 
Connect</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_recordset.asp">ADO 
Recordset</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_display.asp">ADO 
Display</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_query.asp" 
style="font-weight: bold;">ADO Query</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_sort.asp">ADO Sort</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_add.asp">ADO Add</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_update.asp">ADO 
Update</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_delete.asp">ADO 
Delete</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_demo.asp">ADO Demo</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_getstring.asp">ADO 
Speed Up</a><br>
<br>
<h2 class="left"><span class="left_h2">ADO</span> Objects</h2>
<a target="_top" href="http://w3schools.com/ado/ado_ref_command.asp">ADO
 Command</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_connection.asp">ADO
 Connection</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_error.asp">ADO 
Error</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_field.asp">ADO 
Field</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_parameter.asp">ADO
 Parameter</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_property.asp">ADO
 Property</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_record.asp">ADO 
Record</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_recordset.asp">ADO
 Recordset</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_ref_stream.asp">ADO 
Stream</a><br>
<a target="_top" href="http://w3schools.com/ado/ado_datatypes.asp">ADO 
DataTypes</a><br>
<br>
<a target="_top" href="http://w3schools.com/ado/ado_summary.asp">ADO 
Summary</a><br>
<br>
<h2 class="left"><span class="left_h2">ADO</span> Examples</h2>
<a target="_top" href="http://w3schools.com/ado/ado_examples.asp">ADO 
Examples</a><br>
<br>
<h2 class="left"><span class="left_h2">ADO</span> Exam</h2>
<a target="_top" href="http://w3schools.com/cert/default.asp">ADO Exam</a><br>


</div>
</td>
<td valign="top" align="left">
<table style="background-color: rgb(255, 255, 255); color: rgb(0, 0, 0);
 padding-bottom: 8px; padding-right: 5px;" width="574" border="0" 
cellpadding="0" cellspacing="0">
<tbody><tr>
<td style="padding-top: 4px;">

<h1>ADO <span class="color_h1">Queries</span></h1>
<table class="chapter" width="100%" border="0" cellpadding="0" 
cellspacing="0"><tbody><tr>
<td class="prev"><a class="chapter" 
href="http://w3schools.com/ado/ado_display.asp">« Previous</a></td>
<td class="next"><a class="chapter" 
href="http://w3schools.com/ado/ado_sort.asp">Next Chapter »</a></td>
</tr></tbody></table>
<hr>
<p class="intro">We may use SQL to create queries to specify 
only a selected set of records and fields to view.</p>
<hr>
<h2>Display Selected Data</h2>
<p>We want to display only the records from the "Customers" table that 
have a "Companyname" 
that starts with an A (remember to save the file with an .asp 
extension):</p>
<table class="example" width="100%" border="0" cellpadding="0" 
cellspacing="0"><tbody><tr><td>
<h2 class="example">Example</h2>
<table class="example_code" width="100%" border="0" cellpadding="0" 
cellspacing="0"><tbody><tr><td>
&lt;html&gt;<br>
&lt;body&gt;<br>
<br>
&lt;%<br>
set conn=Server.CreateObject("ADODB.Connection")<br>
conn.Provider="Microsoft.Jet.OLEDB.4.0"<br>
conn.Open "c:/webdata/northwind.mdb"<br>
<br>
set rs=Server.CreateObject("ADODB.recordset")<br>
sql="SELECT Companyname, Contactname FROM Customers<br>
WHERE CompanyName LIKE 'A%'"<br>
rs.Open sql, conn<br>
%&gt;<br>
<br>
&lt;table border="1" width="100%"&gt;<br>
&nbsp;&nbsp;&lt;tr&gt;<br>
&nbsp;&nbsp;&lt;%for each x in rs.Fields<br>
&nbsp;&nbsp;&nbsp;&nbsp;response.write("&lt;th&gt;" &amp; x.name &amp; 
"&lt;/th&gt;")<br>
&nbsp;&nbsp;next%&gt;<br>
&nbsp;&nbsp;&lt;/tr&gt;<br>
&nbsp;&nbsp;&lt;%do until rs.EOF%&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&lt;tr&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&lt;%for each x in rs.Fields%&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;td&gt;&lt;%Response.Write(x.value)%&gt;&lt;/td&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&lt;%next<br>
&nbsp;&nbsp;&nbsp;&nbsp;rs.MoveNext%&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&lt;/tr&gt;<br>
&nbsp;&nbsp;&lt;%loop<br>
&nbsp;&nbsp;rs.close<br>
&nbsp;&nbsp;conn.close%&gt;<br>
&lt;/table&gt;<br>
<br>
&lt;/body&gt;<br>
&lt;/html&gt;
</td></tr></tbody></table>
<br><a target="_blank" 
href="http://w3schools.com/ado/showasp.asp?filename=demo_query_1" 
class="showbtn">Show example »</a>
</td></tr></tbody></table>
<br>
<hr>
<br>
<table width="100%" border="0" cellpadding="0" cellspacing="0">
<tbody><tr>
<td width="48" align="left"><img src="ado_query_files/tryitimg.gif" 
alt="Examples" height="46" width="40" border="0"></td>
<td valign="middle" align="left"><h2>More Examples</h2></td>
</tr>
</tbody></table>
<p>
<a target="_blank" 
href="http://w3schools.com/ado/showasp.asp?filename=demo_query_2">Display
 records 
where "Companyname" is &gt; E</a><br>
How to display only the records from the "Customers" table that have a 
"Companyname" 
that is larger than E.</p>
<p>
<a target="_blank" 
href="http://w3schools.com/ado/showasp.asp?filename=demo_query_3">Display
 only Spanish 
customers</a><br>
How to display only the Spanish customers from the "Customers" table.</p>
<p>
<a target="_blank" 
href="http://w3schools.com/ado/showasp.asp?filename=demo_query_4">Let 
the user choose 
filter</a><br>
Let the user choose which country to show customers from.</p>
<br>
<table class="chapter" width="100%" border="0" cellpadding="0" 
cellspacing="0"><tbody><tr>
<td class="prev"><a class="chapter" 
href="http://w3schools.com/ado/ado_display.asp">« Previous</a></td>
<td class="next"><a class="chapter" 
href="http://w3schools.com/ado/ado_sort.asp">Next Chapter »</a></td>
</tr></tbody></table>

<hr>

<!-- **** SPOTLIGHTS 1 **** -->

<iframe id="w3schools_spot1" name="w3schools_spot1" 
src="ado_query_files/aspallframe.asp" marginwidth="0" marginheight="0" 
frameborder="0" height="100" scrolling="no" width="100%">
Your browser does not support inline frames or is currently configured 
not to display inline frames.
</iframe>
<hr>

<!-- **** SPOTLIGHTS 2 **** -->

<h2><a target="_blank" rel="nofollow" 
href="http://www.stylusstudio.com/">
Stylus Studio® XML Development Environment</a></h2>
<a rel="nofollow" target="_blank" href="http://www.stylusstudio.com/">
<img src="ado_query_files/styluslogo1.gif" alt="stylus" height="48" 
hspace="10" width="200" border="0"></a>
<p>Stylus Studio® 2010 XML Enterprise Suite raises the bar for 
productivity in XML development tools.
Millions of XML developers and data integration specialists turn to 
Stylus Studio's comprehensive and intuitive
XML toolset to tackle today's advanced XML data transformation and 
aggregation challenges.</p>
<table border="0" cellpadding="0" cellspacing="0"><tbody><tr>
<td>
<a rel="nofollow" target="_blank" 
href="http://www.stylusstudio.com/xml_download.html">
<img src="ado_query_files/stylusstudio_pipeline.gif" alt="stylus" 
height="173" width="230" border="0"></a>
</td>
<td valign="top">
<ul style="margin: 0px;">
<li>XML Pipeline Editor, Debugger and Code Generator</li>
<li>DataDirect XML Converters</li>
<li>XQuery Mapper, Editor, Debugger, and Profiler</li>
<li>XSLT Mapper, Editor, Debugger, Designer, and Profiler</li>
<li>Java and C# for .Net Code Generation</li>
<li>XML Schema Designer With Documentation Generator</li>
<li>XML Editor With Full XPath Integration</li>
</ul>
<br>
<p style="margin-left: 27px;"><a rel="nofollow" target="_blank" 
href="http://www.stylusstudio.com/xml_download.html">Download a free 
trial now</a> </p>
</td>
</tr></tbody></table>
<br>
<hr>


<!-- **** SPOTLIGHTS 3 **** -->
<script type="text/javascript"><!--
document.write('<table cellpadding="0" cellspacing="0"><tr><td width="108">&nbsp;</td><td>');
google_ad_client = "pub-3440800076797949";
/*txt*/
google_ad_slot = "1699448869";
google_ad_width = 336;
google_ad_height = 280;
//-->
</script><table cellpadding="0" cellspacing="0"><tbody><tr><td 
width="108">&nbsp;</td><td>
<script type="text/javascript" src="ado_query_files/show_ads.js">
</script><script src="ado_query_files/expansion_embed.js"></script><script src="ado_query_files/test_domain.js"></script><script>google_protectAndRun("ads_core.google_render_ad", google_handleError, google_render_ad);</script><ins
 style="display: inline-table; border: medium none; height: 280px; 
margin: 0pt; padding: 0pt; position: relative; visibility: visible; 
width: 336px;"><ins style="display: block; border: medium none; height: 
280px; margin: 0pt; padding: 0pt; position: relative; visibility: 
visible; width: 336px;"><iframe allowtransparency="true" hspace="0" 
id="google_ads_frame1" marginheight="0" marginwidth="0" 
name="google_ads_frame" src="ado_query_files/ads." style="left: 0pt; 
position: absolute; top: 0pt;" vspace="0" frameborder="0" height="280" 
scrolling="no" width="336"></iframe></ins></ins>
<script type="text/javascript">
<!--
document.write("</td></tr></table>");
//-->
</script></td></tr></tbody></table>

</td></tr>
</tbody></table>
</td>

<td id="rightcolumn" valign="top" width="155" align="center">
<table cellspacing="0">
<tbody><tr><th>WEB HOSTING</th></tr>
<tr><td>
<a target="_blank" rel="nofollow" href="http://www.lunarpages.com/">Best
 Web Hosting</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" href="http://www.eukhost.com/">PHP 
MySQL Hosting</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" href="http://www.web-hosting-top.com/">Top
 10 Web Hosting</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" 
href="http://www.heartinternet.co.uk/index.shtml">UK Reseller Hosting</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" href="http://www.webhosting.uk.com/">Web
 Hosting</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" href="http://www.imhosted.com/">FREE 
Web Hosting</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" 
href="http://stats.justhost.com/track?c878c3580275f4db3720fbc777a282233">Top
 Web Hosting</a>
</td></tr>
<!--
<tr><td>
<a target="_blank" rel="nofollow" href="http://eb908380-829d-44a9-a23f-d234163d3e80.statcamp.net/turl/?id=34f063afc2704104ac4b5d88e7227c3a">Unmetered Servers</a>
</td></tr>
-->
</tbody></table>

<table cellspacing="0">
<tbody><tr><th>WEB BUILDING</th></tr>
<tr><td>

<a target="_blank" rel="nofollow" 
href="http://www.altova.com/ref/?s=w3s_text2&amp;q=xmlspy">XML Editor &#8211; 
Free Trial!</a>

</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" 
href="http://www.wix.com/start/wfree?utm_campaign=w3&amp;experiment_id=w300">FREE
 Flash Website</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" 
href="http://www.dreamtemplate.com/?ref=w3txt">FREE Web Templates</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" href="http://www.seoconsult.co.uk/">SEO
 Company</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" 
href="http://www.templateworld.com/go.php?t=26">Free Web 2.0 Templates</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" href="http://www.yola.com/?cid=600101">Free
 Website Builder</a>
</td></tr>
<tr><td>
<a target="_blank" rel="nofollow" 
href="http://www.all-computer-schools.com/featured/web-design-development-programs?src=asd_acom_062007_00000001">US
 Web Design Schools</a>
</td></tr>
</tbody></table>

<table cellspacing="0">
<tbody><tr><th>W3SCHOOLS EXAMS</th></tr>
<tr><td>
<a target="_blank" href="http://w3schools.com/cert/default.asp">Get 
Certified in:<br>HTML, CSS, JavaScript, XML, PHP, and ASP</a>
</td></tr>
</tbody></table>

<table cellspacing="0">
<tbody><tr><th>W3SCHOOLS BOOKS</th></tr>
<tr><td>
<a target="_blank" href="http://w3schools.com/books/default.asp">
New Paperbacks:<br>HTML, CSS<br>
JavaScript, and Ajax</a>
</td></tr>
</tbody></table>

<table cellspacing="0">
<tbody><tr><th>STATISTICS</th></tr>
<tr><td>
<a target="_top" href="http://w3schools.com/browsers/browsers_stats.asp">Browser
 Statistics</a><br>
<a target="_top" href="http://w3schools.com/browsers/browsers_os.asp">Browser
 OS</a><br>
<a target="_top" 
href="http://w3schools.com/browsers/browsers_display.asp">Browser 
Display</a>
</td></tr></tbody></table>

<script type="text/javascript">
<!--
function sharethis()
{
txt='<a href="http://www.facebook.com/sharer.php?u='+document.URL+'" target="_blank" title="Facebook">'
txt=txt+'<img src="/images/share_facebook.gif" border="0" width="16px" height="16px" style="margin-right:4px" /></a>';
txt=txt+'<a href="http://twitter.com/home?status=Currently reading '+document.URL+'" target="_blank" title="Twitter">';
txt=txt+'<img src="/images/share_twitter.gif" border="0" width="16px" height="16px" style="margin-right:4px" /></a>';
txt=txt+'<a href="mailto:?&amp;subject='+document.title+'&amp;body=Take%20a%20look%20at%20this%20page%20at%20W3Schools.com:%20'+document.URL+'" target="_blank" title="E-mail">';
txt=txt+'<img src="/images/share_email.gif" border="0" width="16px" height="16px" style="margin-right:4px" /></a>';
txt=txt+'<a href="http://delicious.com/save?v=5&noui&jump=close&url='+document.URL+'&title='+document.title+'" target="_blank" title="Delicious">';
txt=txt+'<img src="/images/share_delicious.gif" border="0" width="16px" height="16px" style="margin-right:4px" /></a>';
txt=txt+'<a href="http://www.reddit.com/submit?url='+document.URL+'" target="_blank" title="Reddit">';
txt=txt+'<img src="/images/share_reddit.gif" border="0" width="16px" height="16px" style="margin-right:4px" /></a>';
txt=txt+'<a href="http://digg.com/submit?url='+document.URL+'&amp;title='+document.title+'" target="_blank" title="Digg">';
txt=txt+'<img src="/images/share_digg.gif" border="0" width="16px" height="16px" style="margin-right:4px" /></a>';
txt=txt+'<a href="http://www.stumbleupon.com/submit?url='+document.URL+'%26title%3D'+document.title+'" target="_blank" title="Stumbleupon">';
txt=txt+'<img src="/images/share_stumbleupon.gif" border="0" width="16px" height="16px" /></a>';
document.getElementById("sharethis").innerHTML=txt;
}
//--></script>
<table cellspacing="0">
<tbody><tr><th>SHARE THIS PAGE</th></tr>
<tr>
<td id="sharethis">
<div style="height: 16px;">
<a href="#" onclick="sharethis();return false;">Share with »</a>
</div>
</td>
</tr>
</tbody></table>


<table cellspacing="0">
<tbody><tr><td><br>
<iframe id="w3schools_lqsky" name="w3schools_lqsky" 
style="background-color: rgb(255, 255, 255);" 
src="ado_query_files/aspallsky.asp" marginwidth="0" marginheight="0" 
frameborder="0" height="755" scrolling="no" width="142">
</iframe>
</td></tr></tbody></table>

</td></tr></tbody></table>

<table id="footer" width="890" align="center" border="0">
<tbody><tr>
<td width="200" align="left">
<a href="http://www.w3schools.com/"><img 
src="ado_query_files/w3schoolscom_gray.gif" alt="W3Schools.com" 
border="0"></a>
</td>
<td style="word-spacing: 6px; font-size: 90%; padding-right: 10px;" 
align="right">
<a href="http://w3schools.com/default.asp" target="_top">HOME</a> |
<a href="#top" target="_top">TOP</a> |
<a href="http://w3schools.com/ado/ado_query.asp?output=print" 
target="_blank">PRINT</a> |
<a href="http://w3schools.com/forum/default.asp" target="_blank">FORUM</a>
 |
<a href="http://w3schools.com/about/default.asp" target="_top">ABOUT</a>
</td>
</tr>
<tr>
<td colspan="2" style="padding-top: 10px;" valign="top" align="center">
W3Schools is for training only. We do not warrant the correctness of its
 content.
The risk from using it lies entirely with the user.
<br>
While using this site, you agree to have read and accepted our
<a href="http://w3schools.com/about/about_copyright.asp">terms of use</a>
 and
<a href="http://w3schools.com/about/about_privacy.asp">privacy policy</a>.<br>
<a href="http://w3schools.com/about/about_copyright.asp">Copyright 
1999-2010</a> by Refsnes Data. All Rights Reserved.
</td>
</tr>
</tbody></table>

</td>
</tr></tbody></table>
</center>

</body></html>