#! /usr/bin/perl -w

sub test1
{
  $a = 10;
  $b = 11;

  $a + $b;
}

sub test2
{
  @a = ('testing' , 'one' , 'two' , 'three');

  sort(@a);
}

$c = test1();
print "test1 = $c\n";

@b = test2();
print "test2 = @b\n";