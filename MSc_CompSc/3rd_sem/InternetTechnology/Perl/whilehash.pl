#! /usr/bin/perl -w

use strict;

my %capitals =
(
a => 'hi',
b => 'this',
c => 'is',
d => 'me',
e => 'bye'
);
my @sk = sort(keys(%capitals));
my $i;

$i=0;
while($i <= $#sk)
{
  print "$sk[$i]\t::-\t$capitals{$sk[$i]}\n";
  $i++;
}