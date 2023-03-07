#! /usr/bin/perl

use strict;

my($host , $date);

chomp($host = `/bin/hostname`);
chomp($date = `/bin/date`);

print "Content-type: text/html\n";
print <<EOHTML;


<head>
<title>System Information</title>
</head>
<body bgcolor="#520063" text="#ffffff">
<h1>Hello from $host!</h1>
The current time is now : $date
</body>
EOHTML;