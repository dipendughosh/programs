# include <stdio.h>
# include <conio.h>
void main()
	{
		int e=0,m=0,y=0,f=0,n=0,x=0,i,k;
		printf("enter day month year");
		scanf("%d%d%d",&e,&m,&y);
		printf("enter day month year");
		scanf("%d%d%d",&f,&n,&x);
			if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
				k=31;
			else
				{
					if(m==2)
					k=28;
					else
					k=30;
				}
				if((y==x)&&(m==n))
				switch(1)
					{
						case 1:
						for(i=1; ;i++)
							{
								if(e==f)
								break;
								else
								e=e+1;
							}
						printf("%d",i-1);
						break;
					}
				if((y==x)&&(m!=n))
				switch(2)
					{
						case 2:
						for(i=1; ;i++)
							{
								if((e==f)&&(m==n))
								break;
								else
									{
										e=e+1;
										if(e>k)
											{
												m=m+1;
												e=1;
											}
									}
							}
							printf("%d",i-1);
							break;
					}
				else
				switch(3)
					{
						case 3:
						for(i=1; ;i++)
							{
								if((e==f)&&(m==n)&&(y==x))
								break;
								else
									{
										e=e+1;
										if(e>k)
											{
												m=m+1;
												e=1;
													if(m>12)
														{
															y=y+1;
															m=1;
															e=1;
														}
											}
									}
							}
						printf("%d",i-1);
						break;
					}
	getch();
	}