#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<ctype.h>
#include<string.h>
#define MAXBD 500

int i;
long int phone[MAXDB+1];
int room[MAXDB+1];
long int phone_tmp[MAXDB+1];
int room_tmp[MAXDB+1];
void AddEntry(int,long int);
int add_count=0;
int current_e_add;
int DeleteEntry(int,long int);
int FindPhone(long int);
int FindRoom(int);
int phone_found,room_found;
int del_entry;
int tot_del_entry=0;
int ListAll(void);
int SoryAllEntries(char);
int GeTotalEntries(void);
int chkstrdig(char str[],int range);
char menu(void);
void loadDB(void);
void exitmenu(void);
void drawscreen(void);
void refreshscreen(void);
vhar dbload[80];

void main(void)
{
     char iroom[80],iphone[80],add_quit;
     char option,sortopt,exit_opt;
     int phone_check,room_check,delete_check,sort_check,list_check;
     int iroom_search,iroom_del;
     int int_iroom,total_entries;
     int error_iphone,total_entries;
     int error_iphone,error_iroom;
     long int longint_iphone;
     long int iphone_search;
     long int iphone_del;
     strcpy(dbload,"No database file loaded (RAM MODE!).");
     do
     {
           do
           {
                  option=menu();
                  if(option=='1')
                  {
                         current_e_add=0;
                         for(i=add_count;i<MAXDB;i++)
                         {
                                clrscr();
                                refreshscreen();
                                drawscreen();
                                gotoxy(1,4);
                                printf(">>Add Entry<<");
                                gotoxy(1,25);
                                cprintf("Please Add Your Entry,leave blank to quit to Main Menu");
                                gotoxy(1,6);
                                printf("Enter Room Number[%3d]",i+1);
                                gets(iroom);
                                if(iroom[0]=='\0')
                                {
                                       gotoxy(1,25);
                                       crintf("you chose to quit : Entry %d was not added to the database.",i+1);
                                       getch();
                                       break;
                                }
                                printf("Enter Phone Number[%3d]:",i+1);
                                gets(iphone);
                                if(iphone[0]=='\0')
                                {
                                       gotoxy(1,25);
                                       cprintf("You chose to quit : Entry %d was not added to the database.",i+1);
                                       getch();
                                       break;
                                }
                                error_iroom=chkstrdig(iroom,4);
                                error_iphone=chkstrdig(iphone,8);
                                while(error_iroom!=0)
                                {
                                       if(error_iroom==-1)
                                       {
                                              clrscr();
                                              refreshscreen();
                                              drawscreen();
                                              gotoxy(1,4);
                                              printf(">>Add Entry<<");
                                              gotoxy(1,25);
                                              cprintf("Error: Room Number-out of Range,Your entry was greater than 4 digits.");
                                              gotoxy(1,6);
                                              printf("Render Room Number[%3d]:",i+1);
                                              gets(iroom);
                                       }
                                       if(error_iroom==-2)
                                       {
                                              clrscr();
                                              refreshscreen();
                                              drawscreen();
                                              gotoxy(1,4);
                                              printf("***Add Entry***");
                                              gotoxy(1,25);
                                              cprintf("Error: Room Number-Character(s) detected,character(s)are not allowed.");
                                              gotoxy(1,6);
                                              printf("REnter Room Number[%3d]:",i+1);
                                              gets(iroom);
                                       }
                                       error_iroom=chkstrdig(iroom,4);
                                }
                                