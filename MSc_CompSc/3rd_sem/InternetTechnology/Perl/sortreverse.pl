#! /usr/bin/perl -w

use strict;

my @a = ('hello' , 'world' , 'good' , 'riddance');

print "Before :- @a \n";

my @b = sort(@a);
print "After sort :- @b \n";

my $c = reverse(@a);
print "After reverse :- @a \n";
  