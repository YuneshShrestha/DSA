// You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

// Return the single element that appears only once.

// Your solution must run in O(log n) time and O(1) space.
#include<iostream>
using namespace std;
int main()
{
    int arr[]={2,2,4,4,5,5,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    // end=n-2 is used because for single last element we  let high not to shrink
    int start=0, end=n-2;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        // For left half:  1st number comes with even index and 2nd number with odd index
        if(arr[mid]==arr[mid^1])
        {
            start=mid+1;
        }
        // For left half:  1st number comes with odd index and 2nd number with even index
        else
        {
            end=mid-1;
        }
    }
    cout<<arr[start];

    return 0;
}