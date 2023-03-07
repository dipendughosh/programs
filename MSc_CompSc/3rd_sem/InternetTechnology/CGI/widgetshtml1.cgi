#! /usr/bin/perl

use strict;
use CGI ':standard';

if(param)
{
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
}
else
{
  print
    header(),
    start_html('An example of widgets',"#ffeeff"),
    h1('An example of widgets'),
    start_form(),
    'Programming Language: ' ,
    textfield(-name => 'language' , -value => 'Perl'),
    br(),
    'Comments: ',
    br(),
    textarea(-name => 'comments' , -cols => 20 , -rows => 5),
    br(),
    'Rate the coolness: ',
    radio_group(-name => 'coolness' , -values => ['cool' , 'very cool' , 'ice cold'] , -default => 'ice cold'),
    br(),
    'I will learn more about CGI and PERL: ',
    checkbox(-name => 'learnmore' , -value => 'yes' , -label => 'Yes' , -checked => 1),
    br(),
    'I will use this operating system: ',
    popup_menu(-name => 'operating_system' , -values => ['Linux' , 'Solaris' , 'Windows'] , -size => 1),
    br(),
    'My favourite animal(s): ',
    scrolling_list(-name => 'animal' , -values => ['Penguin' , 'Camel' , 'Lama' , 'Horse' , 'Cat' , 'Dog'] , -size => 3 , -multiple => 1),
    br(),
    submit(-value => 'Submit Form'),
    ' ',
    reset(-value => 'Reset Form'),
    end_form(),
    end_html();
}