#include<stdlib.h>
#include<stack>
#include<vector>
int main()
{
     stack<<char,vector<char>> st;
     char cont='y',ch;
     do
     {
          cout<<"\nEnter data...";cin>>ch;
          st.push(ch);
          cout<<"\nPress (Y/y) to continue...";cin>>cont;
     }
     while(cont!='n');
     return 0;
}