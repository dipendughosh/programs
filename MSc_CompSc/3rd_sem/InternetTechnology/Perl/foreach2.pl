#! /usr/bin/perl -w

use strict;

my @a = (2 , 4 , 6 ,  8 );
#my $i;

foreach my $i (@a)
{
  $i = $i * 2;
}

print "@a\n";
