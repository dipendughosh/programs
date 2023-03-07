#! /usr/bin/perl -w

use strict;

my $a = 'hello';
my $b = 'world';
my $msg = $a . ' ' . $b;

print "$msg\n";

$a = 'hi';
$b = $a x 2;
my $c = $a x 5;

print "$b\n$c\n";