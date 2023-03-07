#! /usr/bin/perl -w

use strict;

sub print_args
{
  my ($a,$b,$c) = @_;

  print "\$a : $a\n";
  print "\$b : $b\n";
  print "\$c : $c\n";
  
  print "full string as passed " , @_ , "\n";
}

my $num = 10;
my $name = 'john deo';

print_args($num , $name , 3.1234);