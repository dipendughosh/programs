#! /usr/bin/perl -w

use strict;

my @a = (2 , 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20);
my $i;

foreach $i (@a)
{
  print $i , " ** " , $i , " = " , $i ** $i , "\n";
}