#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{
    char sen[1000],vowels[5]="aeiou",alpbet;
    int  i,j,length,vowel=0,k=1;
    cout<<"\nInput a sentence \n";
    gets(sen);
    cout<<"\nThe original sentence is \n";
    puts(sen);
    length = strlen(sen);
    for(i = 0;i<length;i++)
    {
        alpbet = sen[i];
        if(alpbet == ' ')
        {
            cout<<"in word number "<<k<<"there are "
                <<vowel<<" number of vowels ";
        }
        for(j = 0;j<5;j++)
        {
            if(alpbet = vowels[j];
                    vowel++;
        }
    }
    getche();
}





    cout<<endl;
    system("PAUSE");
    return 0;
}
