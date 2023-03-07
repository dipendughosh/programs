#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

void main()
{   char line[80];
    do
    {   //cin.getline(line,80); /* To repeat the line */
        cin.getline(line,80,';'); /* To delimit the string with ';' */
        if (*line) cout<<line<<"\n";  //This inserts a line-feed
    } while (*line);
    cout<<line;
    getche();
}
