<html>
<body>
The result is:<br />
<?php
mysql_connect("localhost","root","");
mysql_select_db("student");
$sql="select * from result where roll='$_POST[roll]';";
$val=mysql_query($sql);
$row=mysql_fetch_array($val);
echo("<p>ROLL:  ". $row[roll]."</p><p>       NAME:      ".$row[name]."</p><p>       MARKS:      ".$row[marks]."</p>");
?>
</body>
</html>
