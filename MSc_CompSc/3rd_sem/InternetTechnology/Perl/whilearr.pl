#! /usr/bin/perl -w

use strict;

my @name = ('joe' , 'charlie' , 'sue' , 'mary');
my $i;

$i = 0;
while($i <= $#name)
{
  print "$i is $name[$i]\n";
  $i++;
}