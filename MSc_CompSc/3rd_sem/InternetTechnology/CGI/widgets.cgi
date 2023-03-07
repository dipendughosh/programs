#! /usr/bin/perl

use strict;
use CGI ':standard';

my $language = param('language') || 'Perl';
my $comments = param('comments') || ' ';
my $coolness = param('coolness') || 'Ice Cold ';
my $learnmore = param('learnmore') || 'no';
my $operating_system = param('operating_system') || 'Linux';
my @animal = param('animal');
my @params = param();

print
  header(),
  start_html('Process Widgets'),
  h1('Process Widgets'),
  'You entered the following information in the form: ',
  br(),
  'Language: ',b($language),
  br(),
  'Comments: ',b($comments),
  br(),
  'Coolness Level: ',b($coolness),
   br(),
  'You want to learn more about PERL and CGI: ',b($learnmore),
  br(),
  'Your Operating System choice: ',b($operating_system),
  br(),
  'Your favourite animals are: ',b("@animal"),
  br(),br(),
  i("@params"),
  end_html();