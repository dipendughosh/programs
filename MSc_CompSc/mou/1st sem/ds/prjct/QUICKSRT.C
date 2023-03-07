#include<stdio.h>
#include<conio.h>
#include<string.h>

struct train
{
	int id,dist,noc;
	char dest[10];
};

int quick1(struct train input[],int beginning, int end)
{
	int pos,left,right;
	struct train temp;
	left=beginning;
	right=end;
	pos=beginning;
	/* scan from right to left	*/
	do
	{
		while(input[pos].dist<=input[right].dist && pos!=right)
		{
			right--;
		}
		if(pos==right)
			return(pos);
		else
		{
			temp=input[pos];
			input[pos]=input[right];
			input[right]=temp;
			pos=right;
		}
		/*	scan from left to right		*/
		while(input[pos].dist>=input[left].dist && pos!=left)
		{
			left++;
		}
		if(pos==left)
			return(pos);
		else
		{
			temp=input[pos];
			input[pos]=input[left];
			input[left]=temp;
			pos=left;
		}
	}while(left<=right);
}

int quick2(struct train input[],int beginning, int end)
{
	int pos,left,right;
	struct train temp;
	left=beginning;
	right=end;
	pos=beginning;
	/* scan from right to left	*/
	do
	{
		while(input[pos].dest[0]<=input[right].dest[0] && pos!=right)
		{
			right--;
		}
		if(pos==right)
			return(pos);
		else
		{
			temp=input[pos];
			input[pos]=input[right];
			input[right]=temp;
			pos=right;
		}
		/*	scan from left to right		*/
		while(input[pos].dest[0]>=input[left].dest[0] && pos!=left)
		{
			left++;
		}
		if(pos==left)
			return(pos);
		else
		{
			temp=input[pos];
			input[pos]=input[left];
			input[left]=temp;
			pos=left;
		}
	}while(left<=right);
}

void main()
{
	struct train ob[10];
	int n=0,lower[100],upper[100],i,ch;
	int beginning,end,pos,top;
	FILE *fp;
	fp=fopen("train.txt","r");
	if(fp==NULL)
	{
		printf("file not found");
		exit(0);
	}
	do
	{
		fscanf(fp,"%d|%d|%d|%s\n",&ob[n].id,&ob[n].dist,&ob[n].noc,&ob[n].dest);
		//printf("%d %d %d %s\n\n",ob[n].id,ob[n].dist,ob[n].noc,ob[n].dest);
		n++;
	}while(!feof(fp));
	do
	{
		printf("\n\t1.distanc sort");
		printf("\n\t2.destination sort");
		printf("\n\t3.Exit");
		printf("\n\n\tEnter Choice : - ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				top=-1;
				if(n>=1)
				{
					top=top+1;
					lower[top]=0;
					upper[top]=n-1;
				}
				while(top!=-1)
				{
					beginning=lower[top];
					end=upper[top];
					top=top-1;
					pos=quick1(ob,beginning,end);
					if(beginning+1<pos)
					{
						top=top+1;
						lower[top]=beginning;
						upper[top]=pos-1;
					}
					if(end-1>pos)
					{
						top=top+1;
						lower[top]=pos+1;
						upper[top]=end;
					}
				}
				fp=fopen("test5.txt","w");
				if(fp == NULL)
				{
					printf("\nCannot open file");
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					fprintf(fp,"%d %d %d %s\n",ob[i].id,ob[i].dist,ob[i].noc,ob[i].dest);
				}
				fclose(fp);
				break;
			case 2:
				top=-1;
				if(n>=1)
				{
					top=top+1;
					lower[top]=0;
					upper[top]=n-1;
				}
				while(top!=-1)
				{
					beginning=lower[top];
					end=upper[top];
					top=top-1;
					pos=quick2(ob,beginning,end);
					if(beginning+1<pos)
					{
						top=top+1;
						lower[top]=beginning;
						upper[top]=pos-1;
					}
					if(end-1>pos)
					{
						top=top+1;
						lower[top]=pos+1;
						upper[top]=end;
					}
				}
				fp=fopen("test6.txt","w");
				if(fp == NULL)
				{
					printf("\nCannot open file");
					exit(0);
				}
				for(i=0;i<n;i++)
				{
					fprintf(fp,"%d %d %d %s\n",ob[i].id,ob[i].dist,ob[i].noc,ob[i].dest);
				}
				fclose(fp);
				break;
			case 3:
				exit(0);
			default:
				printf("\nWrong Input: Re Enter");
				break;	
		}
	}while(1);
}