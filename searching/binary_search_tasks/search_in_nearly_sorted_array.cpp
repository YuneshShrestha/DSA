// SEARCH IN A NEARLY SORTED ARRAY:

// Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions, i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array. Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].

// For example consider the array {2, 3, 10, 4, 40}, 4 is moved to next position and 10 is moved to previous position.

// Example :
// Input: arr[] =  {10, 3, 40, 20, 50, 80, 70}, key = 40
// Output: 2 
// Output is index of 40 in given array
#include<iostream>
using namespace std;
int main()
{
    int arr[]={10, 3, 40, 20, 50, 80, 70};
    int n=sizeof(arr)/sizeof(arr[0]);
    int start=0, end=n-1;
    int target;
    int mid=-1, res=-1;
    cout<<"Enter number you want to search: ";
    cin>>target;
    while(start<=end){
        mid=start+(end-start)/2;
        if(arr[mid]==target){
            res=mid;
            break;
        }
        else if(mid-1>=start && arr[mid-1]==target)
        {
            res=mid-1;
            break;
        }
        else if(mid+1<=end && arr[mid+1]==target)
        {
            res= mid+1;
            break;
        }


        if(arr[mid]>target)
        {
            end=mid-1;
        }
        else if(arr[mid]<target)
        {
            start=mid+1;
        }
        
    }
    cout<<"Index is: "<<res;
    return 0;
}