#! /usr/bin/perl

use strict;

my($host , $date);

#chomp($host = `/bin/hostname`);
#chomp($date = `/bin/date`);

print "Content-type: text/html";

print <<EOHTML;
<html>
<head>
<title>System Information</title>
</head>
<body>
<h1>Hello from !</h1>
</body>
</html>
EOHTML