#! /usr/bin/perl -w

use strict;

my @a = (2,4,6,8,10);

print "Before :- @a \n";

push(@a , 10 , 12);
print "After push :- @a \n";

my $element = pop(@a);
print "After pop :- @a \n";
print "Element poped :- $element \n";