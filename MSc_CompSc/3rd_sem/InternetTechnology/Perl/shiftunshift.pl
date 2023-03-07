#! /usr/bin/perl -w

use strict;

my @a = (2,4,6,8,10);

print "Before :- @a \n";

unshift(@a , 11 , 12);
print "After unshift :- @a \n";

my $element = shift(@a);
print "After shift :- @a \n";
print "Element shifted :- $element \n";