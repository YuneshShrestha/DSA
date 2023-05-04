#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int arr[]={2,3,4,4,4,6,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    int element=4;
    if(binary_search(arr,arr+n,element))
    {
        cout<<"Element 3 is present\n";
        cout<<"\n";
        cout<<"Lower Bound:"<<lower_bound(arr,arr+n,element)-arr;
        cout<<"\n";
        cout<<"Upper Bound:"<<upper_bound(arr,arr+n,element)-arr;

    }
    else
    {
        cout<<"not present.\n";
         cout<<"Lower Bound:"<<lower_bound(arr,arr+n,element)-arr;
         cout<<"\n";
         cout<<"Upper Bound:"<<upper_bound(arr,arr+n,element)-arr;

    }
   
    return 0;
}