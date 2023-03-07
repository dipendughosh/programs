#! /usr/bin/perl -w

use strict;

my $line;

open (FH , '<test.txt') or die "Can't Open Test.txt :- $!";

while($line = <FH>)
{
  print "Line is :- $line\n";
}

close(FH);

print "___________________________________________\n";

if(! open (FH , '<test.txt'))
{
  die "Can't Open Test.txt :- $!";
}

my @all_lines = <FH>;

my $i = 0;
while($i <= $#all_lines)
{
  print "Line is $i :- $all_lines[$i]\n";
  $i++;
}

close(FH);