#! /usr/bin/perl -w

use strict;

my $i = 10;
my $j;

$j = $i++;
print "\$i++ post increment :- $j\n";

$j = ++$i;
print "++\$i pre increment :- $j\n";

$j = $i--;
print "\$i-- post decrement :- $j\n";

$j = --$i;
print "--\$i pre decrement :- $j\n";
