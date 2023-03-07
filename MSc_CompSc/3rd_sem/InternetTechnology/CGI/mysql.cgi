#! /usr/bin/perl -w

sub handle_error {
  my ($msg,$dbh, $sth) = @_;
 print <<EOHTML;
Content-type: text/html


<head></head>
<body>
There is an error : <b> $msg </b>

<a href = "/cgi-bin/newage.cgi"> Click here to go back to form </a>
</body>
</html>
EOHTML

$sth->finish() if $sth;
$dbh->disconnect() if $dbh;
exit 0;
}

sub process_form
{
 my ($dbh)=@_;
 my $fn=param('fname');
 my $ag = param ('age');

my $sth=$dbh->prepare('insert into newage (firstname,age)
                   values(?,?)') or
            handle_error("cannot prepare SQL ".$dbh->errstr(),$dbh);
$sth->execute($fn,$ag) or
           handle_error("cannot execute ".$dbh->errstr(), $dbh,$sth);
}
# main program ;
use strict;
use CGI':standard';
use DBI;

my $dbh = DBI->connect('DBI:mysql:people', 'apache', 'lamp')
    or handle_error("cannot connect to mysql ".DBI->errstr());
if (param()) {process_form($dbh);}
my $sth = $dbh->prepare('select  firstname, age from newage order by age') or
       handle_error("cannot prepare ".$dbh->errstr(), $dbh);
$sth->execute() or handle_error("cannot execute".$sth->errstr(), $dbh, $sth);

print header,
      start_html("database age information");
print
      <<EOHT;
      <h2> Current name age information </h2>
      <table border="1">
      <tr> <th> First name </th> <th> Age </th> </tr>
EOHT

my ($fn,$ag);

while (($fn,$ag) = $sth->fetchrow())
     { 
       print "<tr> <td> $fn </td> <td> $ag </td></tr> \n";
     }
print "</table>";

print <<EOHT;
<hr>
<h3> Enter name and age information </h3>
<form action="/cgi-bin/newage.cgi/" method=post>
<table border="0">
<tr> <td> First name: </td>
     <td> <input type=text name = fname value=""> </td>
     </tr>
<tr> <td> Age : </td>
     <td> <input type=text name=age value=""></td>
     <tr>
</table>
<hr>
<input type=submit value="submit data">
</form>
<hr>
<p>
<p>

EOHT
print end_html();
$sth->finish();
$dbh->disconnect();

