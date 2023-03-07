   /* BINARY FILE FOR RECORD INSERTION AND DELETION OK*/

#include<stdio.h>
#include<conio.h>
#define NULL 0
typedef struct record
	    {
	     char username[50];
	     char password[10];
	    }rcrd;
rcrd protect,str;
void main(void)
{
 FILE *fp,*ft;
 int sz;
 char ch,name[30];
 fp=fopen("psw.dat","rb+");
 if(fp==NULL)
   fp=fopen("psw.dat","wb+");
 sz=(-1)*sizeof(protect);
 while(1)
  {
   clrscr();
	printf("\n\n\n\n                       ****----    MENU    ----****");
	printf("\n\nTo add a new user --> Press 1..");
	printf("\n\nTo list the users -->Press 2..");
	printf("\n\nTo modify a single record -->Press 3..");
	printf("\n\nTo delete a single user -->Press 4..");
	printf("\n\nTo insert a single record -->Press 5..");
	printf("\n\nTo exit -->Press 6..");
	printf("\n\n\nNow enter your choice: ");
	fflush(stdin);
	ch=getche();
	switch(ch)
	 {
	  case '1':
	   printf("\n\nEnter the user-name: ");
	   gets(protect.username);
	   printf("\n\nEnter the password: ");
	   gets(protect.password);
	   fseek(fp,0,SEEK_END);
	   fwrite(&protect,sizeof(protect),1,fp);
	   break;
	  case '2':
	   printf("\n\n  *$* THE CONTENT OF THE FILE ARE *$*\n\n");
	   rewind(fp);
	   while(fread(&protect,sizeof(protect),1,fp)==1)
	       printf("\n %s\t->\t%s",protect.username,protect.password);
	   break;
	  case '3':
	   printf("\n\nEnter a valid user-name: ");
	   gets(name);
	   rewind(fp);
	   while(fread(&protect,sizeof(protect),1,fp)==1)
	    {
	     if(strcmp(name,protect.username)==0)
	       {
		printf("\n %s\t->\t%s",protect.username,protect.password);
		printf("\n\nEnter the new username: ");
		gets(protect.username);
		printf("\n\nEnter the new password: ");
		gets(protect.password);
		fseek(fp,sz,SEEK_CUR);
		fwrite(&protect,sizeof(protect),1,fp);
	       }
	    }
	   break;
	  case '4':
	   printf("\n\nEnter the user-name: ");
	   gets(name);
	   ft=fopen("temp.dat","wb");
	   rewind(fp);
	   while(fread(&protect,sizeof(protect),1,fp)==1)
	    {
	     if(strcmp(name,protect.username)!=0)
	       fwrite(&protect,sizeof(protect),1,ft);
	    }
	   fclose(ft);
	   fclose(fp);
	   remove("psw.dat");
	   rename("temp.dat","psw.dat");
	   fp=fopen("psw.dat","rb+");
	   break;
	  case '5':
	   printf("\n\nEnter a username before which you want to insert: ");
	   gets(name);
	   ft=fopen("temp.dat","wb");
	   rewind(fp);
	   while((fread(&protect,sizeof(protect),1,fp))==1)
	    {
	     if((strcmp(name,protect.username))==0)
	      {
	       printf("\n\nEnter the new username: ");
	       gets(str.username);
	       printf("\n\nEnter the password: ");
	       gets(str.password);
	       fwrite(&str,sizeof(str),1,ft);
	      }
	     fwrite(&protect,sizeof(protect),1,ft);
	    }
	   fclose(ft);
	   fclose(fp);
	   remove("psw.dat");
	   rename("temp.dat","psw.dat");
	   fp=fopen("psw.dat","rb+");
	   break;
	  default:
	   fclose(fp);
	   exit(0);
	 }
       printf("\n\nPress any key to continue...");
       fflush(stdin);
       getch();
  }
}



