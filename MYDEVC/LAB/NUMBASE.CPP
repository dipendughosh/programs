#include <iostream.h>
#include <stdlib.h>
#include <conio.h>

char digit[] = {"0123456789ABCDEF"};
int main()
{
    char num[5];
    int numbase(char*);
    cout<<"Number : "; cin>>num;
    cout<<"\nBase  =  "<<numbase(num);
    cout<<endl;
    system("PAUSE");
    return 0;
}

int numbase(char* n)
{   int intnum[10],i,j,noofdig = 0;
    int len = strlen(n);
    for(i = 0; i < len; i++) intnum[i] = 0;
    for(i = 0; i < len; i++)
    {   for(j = 0; j < 16; j++)
        {   if(n[i] == digit[j])
            {   intnum[i] = j;
                cout<<"\n"<<intnum[i]; getche();
                noofdig++;
            }
        }
    }

    return noofdig;
}


