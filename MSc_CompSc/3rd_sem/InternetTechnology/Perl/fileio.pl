#! /usr/bin/perl -w

use strict;

my $line;

open (FH1 , '<test.txt') or die "Can't Open Test.txt :- $!";
open (FH2 , '>test1.txt') or die "Can't open Test1.txt : $!\n";

while($line = <FH1>)
{
  print "Line is :- $line\n";
  print FH2 "Read :- $line";
}

close(FH1);
close(FH2);