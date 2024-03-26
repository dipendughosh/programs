#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    string a;
    int count = 0;
    int *arr;
    int i = 0;
    string filePath = "/home/dipendu/mtech/dsa/ass1/data.text";
    ifstream file(filePath);
    string line;
    while (getline(file, line))
    {
        cout << line << "\t";
        count++;
    }
    file.close();
    cout << endl
         << "count : " << count << endl;
    fstream myfile(filePath, std::ios_base::in);
    arr = new int(count);
    while (myfile >> arr[i])
    {
        i++;
    }
    myfile.close();
    int sum = 0;
    for (i = 0; i < count; i++)
    {
        sum = sum + arr[i];
        cout << arr[i] << "\t";
    }
    cout << endl
         << "sum : " << sum << endl;

    return 0;
}