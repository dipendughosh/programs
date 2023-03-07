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
  print "Content-type: text/html\n";
  print "\n";

    print "<html>\n";
      print "<head>\n";
	print "<title>An example of widgets</title>\n";
      print "</head>\n";
      print "<body bgcolor = \"#ffeeff\">\n";
	print "<form action = \"/cgi-bin/widgetshtml.cgi\" method = \"post\">\n";
	  print "Programming Language: <input type = \"text\" name = \"language\" value = \"Perl\">\n";
	  print "<br>\n";
	  print "<textarea name = \"comments\" cols = \"20\" rows = \"5\"></textarea>\n";
	  print "Rate the coolness: \n"; 
	  print "<input type = \"radio\" name = \"coolness\" value = \"cool\"> cool\n";
	  print "<input type = \"radio\" name = \"coolness\" value = \"very cool\"> very cool\n";
	  print "<input type = \"radio\" name = \"coolness\" value = \"ice cold\" checked> ice cold\n";
	  print "I will learn more about CGI and PERL:\n"; 
	  print "<input type = \"checkbox\" name = \"learnmore\" value = \"yes\" checked> yes\n";
	  print "I will use this operating system: \n";
	  print "<select name = \"operating_system\" size = \"1\">\n";
	    print "<option>Linux</option>\n";
	    print "<option>Solaris</option>\n";
	    print "<option>Windows</option>\n";
	  print "</select>\n";
	  print "<br>\n";
	  print "My favourite animal(s): \n";
	  print "<select name = \"animal\" size = \"3\" multiple>\n";
	    print "<option>Penguin</option>\n";
	    print "<option>Camel</option>\n";
	    print "<option>Lama</option>\n";
	    print "<option>Horse</option>\n";
	    print "<option>Cat</option>\n";
	    print "<option>Dog</option>\n";
	  print "</select>\n";
	  print "<br>\n";
	  print "<input type = \"submit\" value = \"Submit Form\">\n";
	  print "<input type = \"reset\" value = \"Reset Form\">\n";
      print "</form>\n";
    print "</body>\n";
  print "</html>\n";
}