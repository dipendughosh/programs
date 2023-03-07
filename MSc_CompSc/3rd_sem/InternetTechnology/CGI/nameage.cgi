#! /usr/bin/perl

use strict;
use CGI ':standard';

my $name = param('yourname') || 'john deo';
my $age = param('age') || 0;
my @params = param();

print
  header(),
  start_html('Your name and age'),
  "Hello $name , your are $age years old.",
  hr(),
  'The parameters entered are: ',
  b("@params"),
  end_html();