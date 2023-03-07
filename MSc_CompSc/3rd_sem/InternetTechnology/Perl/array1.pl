#! /usr/bin/perl -w

use strict;

my @data = ('joe',39,"test data",49.3);

print "Within double quotes: @data\n";
print "Outside any quotes: " , @data , "\n";
print 'Within single quotes: @data' , "\n";
