#include <iostream.h>
#include <stdlib.h>
#include <conio.h>
int main()
{   char* ptr = "Vande Mataram"; // String initialised with a pointer
    int len = strlen(ptr);       // This is necessary to allocate space
    char* str;                   // Another pointer to char declared
    str = new char[len+1];       // Allocates space(+1 for NULL)
    strcpy(str, ptr);            // copying string to new address
    cout << "ptr = " << ptr << endl;
    cout << "str = " << str << endl;
    delete str;                  // DEALLOCATES str's memory
    cout<<endl;
    system("PAUSE");
    return 0;
}

//int *p = new int;
