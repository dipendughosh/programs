#! /usr/bin/perl -w

use strict;

my %person1 = 
(
'name','joe',
'age',39,
'phone','555-2121',
'address','123 main st',
'city','chicago',
'state','IL',
'zip','09878'
);

my %person2 = 
(
name => 'joe',
age => 39,
phone => '555-2121',
address => '123 main st',
city => 'chicago',
state => 'IL',
zip => '09878'
);

print "$person1{name} lives in $person1{state} of age $person1{age} has phone no $person1{phone}\n\n";
print "$person2{name} lives in $person2{state} of age $person2{age} has phone no $person2{phone}\n";

my @key1 = keys(%person1);
my @key2 = keys(%person2);

print "keys of person1 are \n@key1\n\n";
print "keys of person2 are \n@key2\n\n";

my @sk1 = sort(@key1);
my @sk2 = sort(keys(%person2));

print "sorted keys of person1 are \n@sk1\n\n";
print "sorted keys of person2 are \n@sk2\n\n";
