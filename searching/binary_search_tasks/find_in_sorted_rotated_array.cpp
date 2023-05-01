// FIND AN ELEMENT IN A ROTATED SORTED ARRAY:

// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.

// Your algorithm's runtime complexity must be in the order of O(log n).

// Example:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4

#include<iostream>
using namespace std;
int bs(int arr[], int start, int end, int element){
    int mid=-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==element)
        {
            break;
        }
        else if (arr[mid]>element)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    
    return mid;
}
int main()
{
    int target;
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int start = 0, end= n-1, min_index=-1;
    cout<<"Find Element: ";
    cin>>target;
    while(start<=end){
        int mid=(start+end)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(arr[prev]>=arr[mid] && arr[next]>=arr[mid])
        {
            min_index=mid;
            break;
        }
        else
        {
            if(arr[mid]<=arr[n-1])
            {
                end=mid-1;
            }
            else if(arr[mid]>=arr[0])
            {
                start=mid+1;
            }
        }
    }
    if(arr[min_index]==target)
    {
        cout<<"Required Index is: "<<min_index;
    }
    else
    {
        if(arr[n-1]>=target)
        {
            cout<<"Required Index is: "<<bs(arr, min_index+1, n-1, target);    
        }
        else if (arr[0]<=target)
        {
            cout<<"Required Index is: "<<bs(arr, 0, min_index-1, target);       
        }
        
    }
    return 0;
}