#! /usr/bin/perl

use CGI ':standard';

print 
  header(),
  start_html('More System Information'),
  h1('Client Information'),
  'Here is some information about the client',
  ul
  (
    li('The remote host :- ' , remote_host()),
    li('The user agent :- ' , user_agent()),
    li('The referer :- ' , referer())
  ),
  h1('Server Information'),
  'Here is some information about the server',
  ul
  (
    li('The server name :- ' , server_name()),
    li('The server software :- ' , server_software()),
    li('The server port :- ' , server_port()),
    li('The script name :- ' , script_name())
  ),
  end_html();