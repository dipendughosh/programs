#!C:\wamp\bin\perl.exe
#print "Content-type:text/html\n\n";

use strict;
use DBI;  # Here's how to include the DBI module 

print ("Content-Type: text/html\n\n");


my $dbh = DBI->connect('DBI:mysql:test','root','angana')
or print "Err";
print "successfully connected\n";

my $sth=$dbh->prepare('select * from result')
or print "error";
$sth->execute();
while(my @row=$sth->fetchrow()){
print "<br>@row[0]----@row[1]\n";
}

