#! /usr/bin/perl -w

use strict;

my $n = 'John Deo';
print $n , "\n";
if($n =~/^(..)/)
{
  print "^(..) :- $1\n";
}

if($n =~/^(\w+)/)
{
  print "^(\\w+) :- $1\n";
}

if($n =~/(\w+)$/)
{
  print "(\\w+)\$ :- $1\n";
}
