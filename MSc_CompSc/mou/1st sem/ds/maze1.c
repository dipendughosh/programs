#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int maze[15][15],mark[15][15],stack[15][3];
	int move[4][2]={-1,0,
					0,1,
					1,0,
					0,-1,
					};
	int i,j,m,n,top,mov,g,h,x1,y1,x2,y2,c=0;
	printf("Enter Size:-");
	printf("\nEnter Row:- ");
	scanf("%d",&m);
	printf("Enter Column:- ");
	scanf("%d",&n);
	printf("Enter the matrix:-\n");
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			printf("[%d][%d] = ",i,j);
			scanf("%d",&maze[i][j]);
		}
	for(i=0;i<=n+1;i++)
		maze[0][i]=0;
	for(i=0;i<=n+1;i++)
		maze[m+1][i]=0;
	for(i=0;i<=m+1;i++)
		maze[i][0]=0;
	for(i=0;i<=m+1;i++)
		maze[i][n+1]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
			mark[i][j]=0;
	printf("\nEnter source locations:- ");
	printf("\nEnter Row :- ");
	scanf("%d",&x1);
	printf("Enter column :- ");
	scanf("%d",&y1);
	mark[x1][y1]=1;
	stack[0][0]=x1;
	stack[0][1]=y1;
	stack[0][2]=1;
	printf("\nEnter Destination locations:- ");
	printf("\nEnter Row :- ");
	scanf("%d",&x2);
	printf("Enter column :- ");
	scanf("%d",&y2);
	top=1;
	while(top!=0)
	{
		i=stack[0][0];
		j=stack[0][1];
		mov=stack[0][2];
		top=top-1;
		while(mov<=3)
		{
			g=i+move[mov][0];
			h=j+move[mov][1];
			if(mark[g][h]==0&&maze[g][h]==1)
			{
				mark[g][h]=1;
				top++;
				stack[top][0]=i;
				stack[top][1]=j;
				mov=-1;
				i=g;j=h;	
			}
			mov=mov+1;
			if(g==x2&&h==y2)
			{
				printf("\nPath made by the rat is:--\n");
				for(i=1;i<=m;i++)
					for(j=1;j<=n;j++)
						mark[i][j]=0;
				for(i=1;i<=top;i++)
					mark[stack[i][0]][stack[i][1]]=1;
				for(i=1;i<=top;i++)
					printf("%d %d\n",stack[i][0],stack[i][1]);
				printf("%d %d\n",x2,y2);
				stack[0][0]=x1;
				stack[0][1]=y1;
				stack[0][2]=2;
				top=1;
				getch();
				c++;
				if(c==10)
					exit(0);
				break;
			}
		}
	}
	if(c == 10)
		printf("\nNo path exists between the source and the location");
}