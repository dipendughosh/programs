//DFS of graph
#include<conio.h>
#include<stdio.h>

void main()
{	int i,j,k,ad[10][10],n,q[10],flgbt[10],frnt=0,rear=0,x,y,z,flag,flag2=0;
	clrscr();
	printf("\nEnter number of vertices-");
	scanf("%d",&n);
	printf("Enter \n'1' for an edge bertween the vertices \n'0' for no edge between the vertices\n");
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
		{	if(i==j)
				ad[i][j]=999;
			else
			{	printf("%d - %d = ",i,j);
				scanf("%d",&ad[i][j]);
				if(ad[i][j] != 0 && ad[i][j] != 1)
				{	printf("Wrong input\nOnly '0' and '1'\n");
					--j;
				}
			}
		}
	}
	for(i=1;i<=n;i++)
		flgbt[i]=0;
	for(i=1;i<=n;i++)
	{	for(j=1;j<=n;j++)
			printf("%d\t",ad[i][j]);
		printf("\n");
	}
	printf("Enter vertex to start from-");
	scanf("%d",&x);
	printf("Enter vertex to reach-");
	scanf("%d",&y);
	q[rear++]=x;
	flgbt[x]=1;
	while(frnt!=rear)
	{  z=q[frnt++];
		printf("%d\t",z);
		for(i=1;i<=n;i++)
		{	if(ad[z][i]==1)
			{	q[rear++]=i;
				flgbt[i]=1;
			}
		}
		for(i=frnt;i<rear;i++)
		{	if(q[i]==y)
			{  printf("%d\t",q[i]);
				flag2=1;
				break;
			}
		}
		if(flag2==1)
			break;
	}
	if(flag2!=1)
		printf("\nUnsuccessful search\n");
	else
		printf("\nSuccessful search\n");
	getch();
}


