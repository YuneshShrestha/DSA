// Suppose you have a sorted array of infinite numbers, how would you search an element in the array?

// Since array is sorted, the first thing clicks into mind is binary search, but the problem here is that we don’t know size of array.
// If the array is infinite, that means we don’t have proper bounds to apply binary search. So in order to find position of key, first we find bounds and then apply binary search algorithm.

// Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element,
// -if it is greater than high index element then copy high index in low index and double(not necessarily double but you get quite small range to do binary search after you find start and end) 
//  the high index.
// -if it is smaller, then apply binary search on high and low indices found.

#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int start=0, end=1, element,res;
    cout<<"Enter element you want to search: ";
    cin>>element;
    while(element>arr[end])
    {
        start=end;
        end=end*2;
    }
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==element)
        {
         res=mid;
         break;   
        }
        else if(arr[mid]<element)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        
    }
    cout<<"Index: "<<res;
    return 0;
}