#! /usr/bin/perl -w

use strict;

sub manage_phone
{
  my ($phone) = @_;

  if($phone =~/(\d{3})\s(\d{3})\s(\d{4})/)
  {
    return "($1) $2 - $3";
  }
  else
  {
    return "phone number improper\n";
  }
}

sub matches
{
  my ($str , $char_class) = @_;
  
  if($str =~/^[$char_class]+$/)
  {
    print "[$str] matches /[$char_class]/\n";
  }
  else
  {
    print "[$str] does not matches /[$char_class]/\n";
  }
}


my $p1 = 'phone number : 847 555 1212';
my $p2 = manage_phone($p1);

print "Before :- $p1\nAfter :- $p2\n";

my $p3 = 'phone number : 847 555-1212';
my $p4 = manage_phone($p3);

print "Before :- $p3\nAfter :- $p4\n";

my $s1 = 'A string of only alphas and strings';
my $s2 = 'A string of 1 digit';
my $c = 'a-zA-Z ';

matches($s1 , $c);
matches($s2 , $c);