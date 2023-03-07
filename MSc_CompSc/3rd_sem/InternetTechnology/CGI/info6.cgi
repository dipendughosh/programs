#! /usr/bin/perl

use strict;
use CGI ':standard';

my $env_path = $ENV{PATH_INFO} || '';
my $method_path = path_info() || '';

print
  header,
    start_html('Path Information'),
    'From %ENV: ',
  b($env_path),
  br(),
  'From path_info(): ',
  b($method_path),
  end_html();