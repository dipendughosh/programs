/*    */

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>

void main()
{
 FILE *fp1,*fp2;
 char ch;
 clrscr();
 fp1=fopen("c:/file2.txt","r");
 if(fp1==NULL)
 {
 printf("File not found");
 getch();
 exit(0);
 }
 fp2=fopen("d:/file2.txt","w");
 while((ch=fgetc(fp1)) != EOF)
 {
 fputc(ch,fp2);
 }
 fclose(fp1);
 fclose(fp2);
 printf("Coppied successfully");
 getch();
  }