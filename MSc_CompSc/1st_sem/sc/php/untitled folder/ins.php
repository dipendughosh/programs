<?php
mysql_connect("localhost","root","");
mysql_select_db("student");
$sql="insert into result values('$_POST[roll]','$_POST[name]','$_POST[marks]')";
$q=mysql_query($sql);
if($q)
echo("one row inserted");
else 
echo("error");
?>
