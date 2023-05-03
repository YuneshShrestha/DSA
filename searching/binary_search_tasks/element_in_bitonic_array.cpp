// FIND AN ELEMENT IN BITONIC ARRAY:

// Given a bitonic sequence of n distinct elements, write a program to find a given element x in the bitonic sequence in O(log n) time. A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

// Examples:

// Input :  arr[] = {-3, 9, 18, 20, 17, 5, 1};
//          key = 20
// Output : Found at index 3

#include<iostream>
using namespace std;
int binarySearch(int arr[], int start, int end, int element)
{
    int mid=-1, isAscending=0;
    if(arr[start]<arr[end])
    {
        isAscending=1;
    }
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==element)
        {
            break;
        }
        else if (isAscending && arr[mid]<element)
        {
           start=mid+1;
        }
        else if (isAscending && arr[mid]>element)
        {
            end=mid-1;
        }
        else if(!isAscending && arr[mid]<element)
        {
            end=mid-1;
        }
        else if(!isAscending && arr[mid]>element)
        {
            start=mid+1;
        }
    }
    return mid;
}
int main()
{
    int arr[]={-3, 9, 18, 20, 17, 5, 1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int start=0, end=n-1, res=-1, element;
    cout<<"Enter the element you want to search: ";
    cin>>element;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        {
            res=mid;
            break;
        }
        else if(arr[mid+1]>arr[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    // cout<< binarySearch(arr,0, res-1, element)<<"\n"<<binarySearch(arr, res, n-1,element);
    int ans1= binarySearch(arr,0, res-1, element);
    if(arr[ans1]!=element)
    {
        int ans2=binarySearch(arr,res, n-1, element);
        if(arr[ans2]!=element)
        {
            cout<<"Element not found.";
        }
        else
        {
            cout<<ans2;
        }
    }
    else{
        cout<<ans1;
    }
  
    return 0;
}