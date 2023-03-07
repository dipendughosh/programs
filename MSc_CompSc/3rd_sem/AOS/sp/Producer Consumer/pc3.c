#include
#include
#include
#include
#define N 10
long smutex,sempty,sfull,qid,mut,emp,full;
int wait(int);
int signal(int);
void producer(void);
void consumer(void)
void print();
struct sembuf sop;
main()
{
int ch;
smutex=semget((key_t)*123,1,IPC_CREAT|0666);
sempty=semget((key_t)*124,1,IPC_CREAT|0666);
sfull=semget((key_t)*125,1,IPC_CREAT|0666);
semctl(smutex,0,STEVAL,1);
semctl(sfull,0,STEVAL,N);
printf(“\n\tsmutex id is:%d”,smutex);
printf(“\n\tsempty id is:%d”,sempty);
printf(“\n\tsfull id is:%d”,sfull);
qid=msgget((key_t)999,IPC_CREAT|0666);
do
{
printf(“\n\t1:producer”);
printf(“\n\t2:consumer”);
printf(“\n\t3:exit”);
printf(“\nenter your choice:”);
scanf(“\n%d”,&ch);
if(ch= =1)
producer();
if(ch= =2)
consumer();
}
while(ch!=3)
}
int wait(int id)
{
if(id<0)
{
exit(0);
}
id=id-1;
return(id);
}
int signal(int);
{
id=id+1;
return(id);
}
void producer(void)
{
char item[20];
emp=wait(sempty);
mut=wait(smutex);
printf(“\n\tDuring wait operation”);
printf(“\n\tMutex value is%d\n”,mut);
printf(“\n\tEmpty value is%d\n”,emp);
printf(“\n\tproducer in critical section\n\tEnter item:”);
scanf(“%d”,&item):
if(msgnd(qid,&item,20,IPC_NOWAIT)==-1)
printf(“\n\tMessage could not be sent buffer full”);
mut=signal(smutex);
full=signal(sfull);
printf(“\nDuring signal operation”);
printf(“\n\tMutex value is:%d\n”,mut);
printf(“\n\t full value is:%d\n”,full);
}
void consumer(void)
{
char item[20];
full=wait(sfull);
mut=wait(smutex);
printf(“\n\tDuring wait operation”);
Printf(“\n\tMutex value is%d\n”,mut);
Printf(“\n\tfull value is%d\n”,full);
printf(“\n\tconsumer in critical section\n”);
if(msgrcv(qid,&item,20,IPC_NOWAIT)==-1)
{
printf(“\n\tMessage could not be received buffer empty”);
exit(1);
}
printf(“\n\tMessage received:%s\n”,item);
mut=signal(smutex);
emp=signal(sempty);
printf(“\nDuring signal operation”);
printf(“\n\tMutex value is:%d\n”,mut);
printf(“\n\t Empty value is:%d\n”,emp);
} 