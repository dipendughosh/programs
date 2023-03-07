#include<stdio.h>
#include<conio.h>

FILE *fp1;

void main()
{

	char name[50];
	int ch;
       //FILE *fp1;
	void create(char name[]);
	void read(char[]);
	void write(char[]);
	void append(char[]);
	void delete1(char[]);
	clrscr();
	printf("\nEnter the name of the new file which is to be created or handled: ");
	scanf("%s",name);
	do
	{
		printf("\nEnter the choice: ");
		printf("\nPress 1 to create a file.");
		printf("\nPress 2 to write into a file.");
		printf("\nPress 3 to read a file.");
		printf("\nPress 4 to append a file.");
		printf("\nPress 5 to delete a file.");
		printf("\nPress 6 to exit.");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			 {	create(name);
				break;
			 }

			case 2:
				write(name);
				break;

			case 3:
				read(name);
				break;

			case 4:
				append(name);
				break;

			case 5:
				delete1(name);
				break;

			case 6:
				printf("\nExiting..");
				exit();

			default:
				printf("\Wrong choice!");
				break;
		}

	}while(1);
	getch();
}


void create(char name[])
{
	/*printf("\nEnter the name of the new file which is to be created or handled: ");
	scanf("%s",name);*/
	//FILE *fp1;
	fp1 = fopen(name, "w");
	if(fp1==NULL)
		printf("\nfile is not created!\n");
	else
		printf("\nfile has created successfully.\n");
	fclose(fp1);
}

void read(char name[])
{
	//FILE *fp1;
	char c;
	fp1=fopen(name, "r");
	while((c=getc(fp1))!= EOF)
	{
	       printf("%c", c);
	}
	fclose(fp1);
}

void write(char name[])
{
	//FILE *fp1;
	char c,input[100];
	fp1=fopen(name, "w");
	printf("\nEnter the text you want to write: ");
	//scanf("%s", input);
	while((c=getchar())!="\n")
	       fputc(c,fp1);
	printf("\Wwriting is completed.");
	fclose(fp1);
}

void append(char name[])
{
       //	FILE *fp1;
	char c;
	fp1=fopen(name,"a");
	printf("\nEnter the text: ");
	while(c=getchar()!="\n")
		putc(c,fp1);
	fclose(fp1);
}


void delete1(char name[])
{
	int status;
	status=remove(name);
	if(status==0)
		printf("\nFile detele successfully!\n");
	else
		printf("\nUnable to delete!\n");
}