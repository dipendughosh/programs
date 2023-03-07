<?php
$con=mysql_connect("localhost","debraj","12345");
if(!$con)
{
 die('could not connect'.mysql_error());
}
else
{
 echo "CONNECTION ESTABLISHED";
}

$admission="med";
 mysql_query("CREATE DATABASE $admission",$con);
 mysql_select_db($admission,$con);
$sql="
  CREATE TABLE stdetail 
    ( 
      formno varchar(9) NOT NULL,
      category varchar(3) NOT NULL,  
      univ varchar(2) NOT NULL,
      sstatus varchar(7) NOT NULL,  
      fname varchar(30) NOT NULL,  
      mname varchar(30)  NULL,  
      lname varchar(30) NOT NULL,  
      ffname varchar(30) NOT NULL,  
      fmname varchar(30) NULL,  
      flname varchar(30) NOT NULL,  
      phno int(15)  NULL,  
      sex varchar(1) NOT NULL,  
      nationality varchar(20) NOT NULL,  
      dob date NOT NULL,  
      ggroup varchar(20) NOT NULL,     
      PRIMARY KEY (formno)
    )ENGINE = InnoDB"; 


if(!$sql)
{
die('could not make the table'.mysql_error());
} 
else
{
 echo "stdetail table created";
}
mysql_query($sql,$con);




$sql2="
  CREATE TABLE stmarks 
    ( 
    formno varchar(9) NOT NULL,
    bedfm int(4)  NULL, 
    bedm float(7,3)  NULL, 
    mafm int(4)  NULL, 
    mam float(7,3)  NULL, 
    mph int(1)  NULL, 
    phd int(1)  NULL, 
    nnet int(1)  NULL, 
    wwritten float(7,3) NULL,
    ttotal float(7,3) NULL,
    FOREIGN KEY (formno) REFERENCES stdetail(formno) 
    ) ENGINE = InnoDB"; 
 



if(!$sql2)
{
die('could not make the table'.mysql_error());
} 
else
{
 echo "stmarks table created";
}
mysql_query($sql2,$con);

#mysql_close($con);
?>


