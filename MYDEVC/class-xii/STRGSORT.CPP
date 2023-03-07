#include <string>

void main()
{   string arr[2],temp;
    int i,j;
    cout<<"Enter names:\n";
    for(i=0;i<2;i++)
        cin>>arr[i];
    if(arr[0]>arr[1])
    {   cout<<"\ngreater\n";
        temp=arr[0];
        arr[0]=arr[1];
        arr[1]=temp;
    }
    cout<<"Names:\n";
    for(i=0;i<2;i++)
        cout<<arr[i];
    cout<<endl;
    system("PAUSE");
}
