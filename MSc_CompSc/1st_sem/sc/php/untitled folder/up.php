<?php
mysql_connect("localhost","root","");
mysql_select_db("student");
$sql="update result set name='$_POST[name]' where roll='$_POST[roll]';";
$d=mysql_query($sql);
if($d)
 echo("one row updated");
?>