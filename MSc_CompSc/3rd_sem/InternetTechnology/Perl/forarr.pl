#! /usr/bin/perl -w

use strict;

my @name = ('joe' , 'charlie' , 'sue' , 'mary');
my $i;

for($i = 0 ; $i <= $#name ; $i++)
{
  print "$i is $name[$i]\n";
}