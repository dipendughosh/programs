//to read and write a structrure into a file
#include<stdio.h>
#include<io.h>
#include<stdlib.h>

struct temp
{
	int i;
	float j;
	char l[10];
};

int main()
{
	struct temp ob[10];
	int a;
	FILE *fp;
	fp=fopen("test.txt","w");
	if(fp == NULL)
	{
		printf("\nCannot open file");
		exit(0);
	}
	for(a=0;a<3;a++)
	{
		printf("Enter integer :- ");
		scanf("%d",&ob[a].i);
		printf("Enter float :- ");
		scanf("%f",&ob[a].j);
		printf("Enter string :- ");
		fflush(stdin);
		gets(ob[a].l);
		fprintf(fp,"%d|%f|%s\n",ob[a].i,ob[a].j,ob[a].l);
	}
	fclose(fp);
	fp=fopen("test.txt","r");
	if(fp == NULL)
	{
		printf("\nCannot open file");
		exit(0);
	}
	a=0;
	do
	{
		fscanf(fp,"%d|%f|%s\n",&ob[a].i,&ob[a].j,&ob[a].l);
		printf("integer = %d | float = %f | string = %s\n\n",ob[a].i,ob[a].j,ob[a].l);
		a++;
	}while(!feof(fp));
	fclose(fp);
	return(0);
}



