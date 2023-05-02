// FIND MAXIMUM ELEMENT IN AN BITONIC ARRAY:

// Problem statement:
// Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.

// Example:

// Input:
// 1 4 8 3 2

// Output:
// 8

#include<iostream>
using namespace std;
int main()
{
    int arr[]={1, 4, 8, 3, 2};
     int n=sizeof(arr)/sizeof(arr[0]);
    int start=0, end= n-1, res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            res=mid;
            break;
        }
        else if (arr[mid+1]>arr[mid])
        {
            start=mid+1;
        }
        else if(arr[mid-1]>arr[mid])
        {
            end=mid-1;
        }
        
    }
    cout<<arr[res];
    return 0;
}