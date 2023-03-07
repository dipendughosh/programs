//to check if transpose matrix & symmetrical
#include<iostream.h>
#include<conio.h>
void main()
{ clrscr();
  int matrix[20][20];
  int r,c;
  cout<<"enter the no of rows ";
  cin>>r;
  do
  { cout<<" enter the column ";
   cin>>c;
  }while(r!=c);
  for(int i=0;i<r;i++)
   { for(int j=0;j<c;j++)
	{cout<<" enter the elements ";
	  cin>>matrix[i][j];
	}
   }
   cout<<"original matrix\n";
   for(i=0;i<r;i++)
	{ for(int j=0;j<r;j++)
	   {cout<<"\t"<<matrix[i][j];}
	  cout<<endl;
	}
  // function declaration
  int tran(int [20][20],int);
  int g=tran(matrix,r);
  if(g==1)
   cout<<" symmetrical";
  else
   cout<<" not symmetrical";

   getche();
}
  // function definition()
  int tran(int matrix[20][20],int r)
  { int mat[20][20],s=0;
   for(int i=0;i<r;i++)
	{for(int j=0;j<r;j++)
	 {mat[i][j]=matrix[j][i];}
	}
	// printing the transpose matrix
	 cout<<" transpose matrix\n";
	for(i=0;i<r;i++)
	 {for(int j=0;j<r;j++)
	  {cout<<"\t"<<mat[i][j];}
	   cout<<endl;
	 }
	 for(i=0;i<r;i++)
	  {for(int j=0;j<r;j++)
	   { if(mat[i][j]==matrix[i][j])
		  s++;
	   }
	  }
	  if(s==r*r)
		return 1;
	  else
		return 0;
  }