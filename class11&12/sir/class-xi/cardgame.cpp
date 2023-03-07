#include <iostream.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
struct card
{
    char name[5];
    char no;
};
int main()
{
    card game[4],temp;
    int x,y,number;
    gets(game[0].name);//="c";
    game[1].name[]="club";
    /*game[2].name="diamond";
    game[3].name="heart";
    game[0].no="A";
    game[1].no="J";
    game[2].no="9";
    game[3].no="2";  */
    for(int i=0;i<3;i++)
    {
        cout<<"\nPlease enter position's to be swaped  -->";
        cin>>x>>y;
        temp=game[x];
        game[x]=game[y];
        game[y]=temp;
    }
    cout<<"\nEnter the position whose content's are to be seen  -->";
    cin>>number;
    cout<<"\nThe com\ntents are  :\n";
    puts(game[number].name);
    cout<<game[number].no;
    cout<<endl;
    system("PAUSE");
    return 0;
}
