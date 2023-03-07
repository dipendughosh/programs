#! /usr/bin/perl -w

use strict;

my $record = '32451:john deo:789 978 656';

if($record =~/^(.*):(.*):(.*)$/)
{
  print "The record is :- \n";
  print "account number :- $1\n";
  print "name :- $2\n";
  print "phone number :- $3\n";
}
