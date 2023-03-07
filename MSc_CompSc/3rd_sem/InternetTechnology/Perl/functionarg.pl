#! /usr/bin/perl -w

use strict;

sub print_args
{
  my $i = 0;

  while($i <= $#_)
  {
    print "arg $i : $_[$i]\n";
    $i++;
  }

  print "full string as passed " , @_ , "\n";
}

my $num = 10;
my $name = 'john deo';

print_args($num , $name , 3.1234 , 'Hello world!!!');