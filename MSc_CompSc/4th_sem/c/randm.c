#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

main()
{
	int i;
   i = random(100);
	printf("Random(100) = %d\n",i);
   i = rand();
	printf("Rand(100) = %d\n",i);
   getch();

}
