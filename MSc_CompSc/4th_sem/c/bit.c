#include<stdio.h>
#include<conio.h>

main()
{
	unsigned int i = 0xffffffff,j,k;

   printf("hexadecimal values : i = %x\t~i = %x\n",i,~i);
	printf("decimal values : i = %u\t~i = %u\n",i,~i);
   printf("size of i = %d\n",sizeof(i));

   j=i;

   while(j)
   {
      printf("%d\n",j%10);
      j=j/10;
   }

   getch();
}
