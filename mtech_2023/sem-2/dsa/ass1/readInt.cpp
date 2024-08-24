#include <iostream>
#include <climits>
using namespace std;

int main()
{
    string x;
    int i = 0;
    int arraySize = INT_MAX;
    cout << "arraySize : " << arraySize << endl;
    while (cin >> x)
    {
        try
        {
            cout << ++i << ": " << stoi(x) << endl;
        }
        catch (exception e)
        {
            break;
        }
    }
}