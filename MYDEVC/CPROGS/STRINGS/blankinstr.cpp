#include <iostream.h>
#include <conio.h>

void main()
{   char strng[20];
    cin.getline(strng,20);
    for(int i=0; i<strlen(strng); i++)
       if(strng[i]==' ') cout<<i+1<<endl;
    getche();
}
