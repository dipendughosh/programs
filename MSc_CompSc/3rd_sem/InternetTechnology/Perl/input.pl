#! /usr/bin/perl -w

use strict;

print "Enter name :- ";
my $name = <STDIN>;
my $name2;
print "Hello $name!!\n";

chomp($name);
print "Hello $name!!\n";

print "Enter name :- ";
chomp($name2 = <STDIN>);
print "Hello $name2!!\n";