#include <iostream.h>
#include <conio.h>

class card
{   private :
        int number;
        int suit;
    public :
        void change(int n)
        {   if ( n = 1 ) cout<<"Ace"; }
};
/*card cards[4] = { 11, 3, 1, 4, 6, 2, 13, 1 };  also correct */

void shuffle(card&,card&);     // Can be made local also
void display(card cards[],int,int); //   Note that the objects
                                   //   cards[] have been created after the
                                  //   declaration of function
void main()
{   card result;
    ////card cards[4] = { 11, 3, 1, 4, 6, 2, 13, 1 };
    card cards[4] = { 11, 3, 1, 4, 6, 2, 13, 1 };
    /*void display(card cards[],int,int);
      void shuffle(card&,card&);
      int times = 1,num1,num2 ; */

    display(cards,0,4);
    shuffle(cards[0],cards[2]);
    shuffle(cards[1],cards[3]);
    shuffle(cards[1],cards[2]);
    shuffle(cards[0],cards[1]);
    cout<<"\n The Fourth Card is : ";
    display(cards,3,4);
    getche();
    return 0;
}

void display(card tash[],int first,int last )
{   for (int i=first; i<last; i++)
    {  cout<<"\ncard"<<i+1<<"--> Colour :";
       cout<<tash[i].suit;
       cout<<" Number : ";
       cout<<change(tash[i].number);
    }
    cout<<endl;
}

void shuffle(card& tas1,card& tas2)
{   card temp = tas1; tas1 = tas2;
    tas2 = temp;
}


