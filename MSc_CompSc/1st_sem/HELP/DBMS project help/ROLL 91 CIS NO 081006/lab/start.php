<?php
$con=mysql_connect("localhost","avishek","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
else
{
 echo "CONNECTION ESTABLISHED";
}

$admission="lab";
 mysql_query("CREATE DATABASE $admission",$con);
 mysql_select_db($admission,$con);
$sql="
  CREATE TABLE employee 
    ( 
    eid varchar(10) NOT NULL,
    fname varchar(30) NULL,
    lname varchar(30) NULL,
    desig varchar(10) NULL,  
    PRIMARY KEY (eid)
    )ENGINE = InnoDB"; 


if(!$sql)
{
die('could not make the table'.mysql_error());
} 
else
{
 echo "employee table created";
}
mysql_query($sql,$con);

$sql1="
  CREATE TABLE labdetail 
    ( 
    labid varchar(10) NOT NULL,
    labname varchar(30) NULL,
    inchargeid varchar(10) NOT NULL,  
    no_machine integer NULL,
    PRIMARY KEY (labid),
    FOREIGN KEY (inchargeid) REFERENCES employee(eid) 
    )ENGINE = InnoDB"; 


if(!$sql1)
{
die('could not make the table'.mysql_error());
} 
else
{
 echo "labdetail table created";
}
mysql_query($sql1,$con);


$sql2="
  CREATE TABLE machine 
    ( 
    mid varchar(10) NOT NULL,
    apos varchar(10) NOT NULL,
    cpos varchar(10) NOT NULL,
    status varchar(20) NULL,
    company varchar(20) NULL,
    model varchar(20) NULL, 
    FOREIGN KEY (apos) REFERENCES labdetail(labid), 
    FOREIGN KEY (cpos) REFERENCES labdetail(labid), 
    PRIMARY KEY (mid) 
    ) ENGINE = InnoDB"; 
 



if(!$sql2)
{
die('could not make the table'.mysql_error());
} 
else
{
 echo "machine table created";
}
mysql_query($sql2,$con);

$sql3="
  CREATE TABLE labass 
    ( 
    labid varchar(10) NOT NULL,
    class varchar(20) NULL, 
    sirid varchar(10) NOT NULL,
    asstime varchar(10) NULL,
    assday varchar(10) NULL,
    subject varchar(10) NOT NULL,
    FOREIGN KEY (labid) REFERENCES labdetail(labid), 
    FOREIGN KEY (sirid) REFERENCES employee(eid) 
    ) ENGINE = InnoDB"; 
 



if(!$sql3)
{
die('could not make the table'.mysql_error());
} 
else
{
 echo "labass table created";
}
mysql_query($sql3,$con);
    


?>

<html>
<body>
<a href="starting.html">Log in</a>
</body>
</html>
