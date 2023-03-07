#! /usr/bin/perl

use CGI ':standard';

print 
  header(),
  start_html
  (
    -title => 'System Information' ,
    -bgcolor => "#520063" ,
    -text => "#ffffff"
  ),
  h1('Hello world'),
  hr(),
  'Time to go now....',
  end_html();