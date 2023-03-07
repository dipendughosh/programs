#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#define MAX 50
void main()
{   char arr[MAX], stack[MAX], inverse[MAX], flag = 1;
    int index = 0, num, full = 0, top = -1, bot = 0;
    cout << "Enter a word : "; gets(arr);
    while (arr[index]!= '\0') stack[++top] = arr[index++];
    stack[++top] = '\0';
    while(--top >= 0) inverse[bot++] = stack[top];
    index = 0;
    while(arr[index]!= '\0')
    {   if(arr[index] != inverse[index])
        {   flag = 0;
            break;
        }
        index++;
    }
    if(flag == 1) cout<<"\nPALINDROME";
    else cout<<"\nSORRY";
    cout<<endl;
    system("PAUSE");
}

