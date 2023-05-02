// FIND PEAK ELEMENT IN AN ARRAY:

// A peak element is an element that is greater than its neighbors.

// Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.

// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.

// You may imagine that nums[-1] = nums[n] = -∞.

// Example :

// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int start=0, end= n-1, res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        // checking starting and last index
        if(mid-1<0 || mid+1>n-1)
        {
            if(mid-1<0 && arr[mid]>arr[mid+1])
            {
                res=mid;
                break;
            }
            else if(mid+1>n-1 && arr[mid]>arr[mid-1])
            {
                res=mid;
                break;
            }
        }
        // checking other index
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        {
            res=mid;
            break;
        }
        else if(arr[mid]<arr[mid-1])
        {
            end=mid-1;
        }
        else if(arr[mid]<arr[mid+1])
        {
            start=mid+1;
        }
    }
    cout<<res;
    return 0;
}
