// Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

// Example:

// Input : arr[] = {0, 0, 1, 1, 1, 1} 
// Output : 2

#include<iostream>
using namespace std;
int main()
{
    int arr[] = {0, 0, 1, 1, 1, 1};
    int start=0, end=1, res=-1;
    while(arr[end]!=1)
    {
        start=end;
        end=end*2;
    }
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==1)
        {
            res=mid;
            end=mid-1;
        }
        else if(arr[mid]==0)
        {
            start=mid+1;
        }
    }
    cout<<"Ans: "<<res;
    return 0;
}