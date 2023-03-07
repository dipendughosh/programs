#! /usr/bin/perl -w

sub pick_restuarent
{
  if($cash > 150)
  {
    return 'chez paul';
  }
  elsif($cash > 50)
  {
    return 'peak maular steak house';
  }
  elsif($cash > 10)
  {
    return 'pancakes r us';
  }
  else
  {
    return 'fast food delite';
  }
}

$cash = 19;

print 'You should eat at : ' , pick_restuarent() , "\n";