#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

main ()
{
 int p=fork();
 printf("Parent %d",p);
 printf ("Hello\n");
}
