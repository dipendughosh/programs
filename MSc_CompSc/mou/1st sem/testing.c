#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct train
{
	int train_id;
	char dest[20];
	int dist;
	int no_of_comp;
};

main()
{
	struct train t[20];
	int i,n=0;
	FILE *fp;
	//FILE *fpp;
	fp=fopen("a.txt","r");
	if(fp==NULL)
	{
		printf("file cannot be opened");

		exit(1);
	}
	do
	 {
		 fscanf(fp,"%d|%s|%d|%d",&t[n].train_id,&t[n].dest,&t[n].dist,&t[n].no_of_comp);
		 printf("%d %s %d %d\n",t[n].train_id,t[n].dest,t[n].dist,t[n].no_of_comp);
		 n=n+1;
	 }
	 while(!feof(fp)) ;
	fclose(fp);
	/*for(i=0;i<n;i++)
	     printf("%d %s %d %d\n",t[i].train_id,t[i].dest,t[i].dist,t[i].no_of_comp);*/
}