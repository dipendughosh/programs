<html>
<body>
<p>
<?php
$d=mysql_connect("localhost","root","");
if($d)
 echo(" connected");
mysql_select_db("student");
$sql="create table result(roll integer(3) primary key,name varchar(20),marks integer(4));";
$s=mysql_query($sql);
if($s)
echo(" table created");
?>
</p>
</body>
</html>
