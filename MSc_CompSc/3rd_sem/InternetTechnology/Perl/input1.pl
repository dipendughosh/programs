#! /usr/bin/perl -w

use strict;

print "Enter text :-\n ";
my @name;
@name = <STDIN>;
my $i = 0;

print "Entered text:-\n";

while($i <= $#name)
{
  print "line $i :- $name[$i] ";
  $i++;
}

#chomp(@name);
#chomp(@name = <STDIN>);
