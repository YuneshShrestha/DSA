// CEILING OF AN ELEMENT IN A SORTED ARRAY:

// Given a sorted array and a value x, the ceiling of x is the smallest element in array greater than or equal to x, and the floor is the greatest element smaller than or equal to x. Assume than the array is sorted in non-decreasing order. Write efficient functions to find floor and ceiling of x.

// Examples :

// For example, let the input array be {1, 2, 8, 10, 10, 12, 19}
// For x = 0:    floor doesn't exist in array,  ceil  = 1
// For x = 1:    floor  = 1,  ceil  = 1
// For x = 5:    floor  = 2,  ceil  = 8
// For x = 20:   floor  = 19,  ceil doesn't exist in array

#include<iostream>
using namespace std;
int main(){
    int arr[]= {1, 2, 8, 10, 10, 12, 19};
    int target;
    cout<<"Which elements ceil do you want to search?: ";
    cin>>target;
    int start=0, end= (sizeof(arr)/sizeof(arr[0]))-1;
    int res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==target)
        {
            res=arr[mid];
            break;
        }
        else if(arr[mid]>target)
        {
            res=arr[mid];
            end=mid-1;
        }
        else if (arr[mid]<target)
        {
            start=mid+1;
        }
    }
    cout<<res;
    return 0;
}