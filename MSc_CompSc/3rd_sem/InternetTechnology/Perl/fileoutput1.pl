#! /usr/bin/perl -w

use strict;

my $line;

open (FH , '>test1.txt') or die "Can't open Test1.txt : $!\n";

while($line = <STDIN>)
{
  print FH "You Entered :- $line";
}

close(FH);