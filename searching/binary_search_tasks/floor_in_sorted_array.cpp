// FIND FLOOR OF AN ELEMENT IN A SORTED ARRAY:

// Given a sorted array and a value x, the floor of x is the largest element in array smaller than or equal to x. Write efficient functions to find floor of x.

// Example:

// Input : arr[] = {1, 2, 8, 10, 10, 12, 19}, x = 5
// Output : 2
// 2 is the largest element in arr[] smaller than 5.

#include<iostream>
using namespace std;
int main(){
    int arr[]= {1, 2, 8, 10, 10, 12, 19};
    int target;
    cout<<"Which elements floor do you want to search?: ";
    cin>>target;
    int start=0, end= (sizeof(arr)/sizeof(arr[0]))-1;
    int res=-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]==target)
        {
            res=arr[mid];
            break;
        }
        else if(arr[mid]<target)
        {
            res=arr[mid];
            start=mid+1;
        }
        else if (arr[mid]>target)
        {
            end=mid-1;
        }
    }
    cout<<res;
    return 0;
}