#include<stdio.h>
#include<conio.h>
#include<alloc.h>
#define UNSEEN 0
#define FRINGE 1
#define INTREE 2
#define MAX 20
typedef struct node_type
{
int vertex;
int weight;
struct node_type *link;
}node;
typedef struct fringe_type
{
int vertex;
struct fringe_type *link;
}fringe_node;
void create_graph(node *adj[],int num)
{
int i;
for(i=1;i<=num;i++)
adj[i]=(node*)NULL;
}
void input_graoh(node *adj[],int num)
{
node *ptr,*last;
char *ss[]={"","First","Second","Third","Fourth","Fifth","Sixth","Seventh","Eighth","Ninth"};
int i,j,m,val,wt;
for(i=1;i<=num;i++)
{
last=(node*)NULL;
clrscr();
printf("\nHow many nodes in the adjacency list of node %d:",i);
scanf("%d",&m);
for(j=1;j<=m;j++)
{
printf("Enter %s node:",ss[j]);
scanf("%d",&val);
printf("Enter weight for edge (%d%d):",i,val);
scanf("%d",&wt);
ptr=(node*)malloc(sizeof(node));
ptr->vertex=val;
ptr->weight=wt;
ptr->link=(node*)NULL;
if(adj[i]==(node*)NULL)
adj[i]=last=ptr;
else
{
last->link=ptr;
last=ptr;
}
}
}
void delete_graph(node *adj[],int n)
{
int i;
node *temp,*ptr;
for(i=1;i<=n;i++)
{
ptr=adj[i];
while(ptr!=(node*)NULL)
{
temp=ptr;
ptr=ptr->link;
free(temp);
}
adj[i]=(node*)NULL;
}
}
void insert(fringe_node **fringe_list,int d)
{
fringe_node *ptr;
ptr=(fringe_node*)malloc(sizeof(fringe_node));
ptr->vertex=d;
ptr->link=*fringe_list;
*fringe_list=ptr;
}
void delete(fringe_node **fringr_list,int d)
{
fringe_node *loc,*ploc;
if(d==(*fringe_list)->vertex)
{
loc=*fringe_list;
*fringe_list=(*fringe_list)->link;
free(loc);
}
else
{
ploc=*fringe_list;
loc=(*fringe_list)->link;
while(loc->vertex!=d)
{
ploc=loc;
loc=loc->link;
}
ploc->link=loc->link;
free(loc);
}
}
int empty(fringe_node *ptr)
{
if(ptr==(fringe_node*)NULL)
return 1;
else
return 0;
}
void print_path(int parent[],int s,int v)
{
if(v==s)
printf("%d",s);
else
{
if(parent[v]==0)
printf("No path from %d to %d\n",s,v);
else
{
print_path(parent,s,parent[v]);
printf("->%d",v);
}
}
}
void shortest_path(node *adj[],int n,int s,int d)
{
fringe_node *fringe_list,*ptr2;
node *ptr1;
int i,x,stuck,w,min_dist,y,wt;
inr parent[MAX],status[MAX],dist[MAX];
fringe_list=(fringe_node*)NULL;
for(i=1;i<=n;i++)
status[i]=UNSEEN;
parent[s]=0;
dist[s]=0;
status[s]=INTREE;
x=s;
stuck=0;
while((x!=d)&&(!stuck))
{
ptr1=adj[x];
while(ptr1!=(node*)NULL)
{
y=ptr1->vertex;
wt=ptr1->weight;
if((status[y]==FRINGE)&&(dist[x]+wt<dist[y]))
{
parent[y]=x;
dist[y]=dist[x]+wt;
}
else
{
if(status[y]==UNSEEN)
{
status[y]=FRINGE;
parent[y]=x;
dist[y]=dist[x]+wt;
insert(&fringe_list,y);
}
}
ptr1=ptr1->link;
}
if(empty(fringe_list))
stuck=1;
else
{
x=fringe_list->vertex;
min_dist=dist[x];
ptr2=fringe_list->link;
while(ptr2!=(fringe_node*)NULL)
{
w=ptr2->vertex;
if(dist[w]<min_dist)
{
x=w;
min_dist=dist[w];
}
ptr2=ptr2->link;
}
delete(&fringe_list,x);
status[x]=INTREE;
}
}
print_path(parent,s,d);
}
void main()
{
node *adj[MAX];
int i,n,s,d;
create_graph(adj,n);
clrscr();
printf("\nEnter number of nodes in the graph:");
scanf("%d",%n);
input_graph(adj,n);
clrscr();
printf("\nEnter source vertex:");
scanf("%d",&s);
printf("\nEnter destination vertex:");
scanf("%d",&d);
printf("\n\nShortest path,if any....\n\n");
shortest_path(adj,n,s,d);
printf("\n\npress any key to continue...");
getch();
delete_graph(adj,n);
}