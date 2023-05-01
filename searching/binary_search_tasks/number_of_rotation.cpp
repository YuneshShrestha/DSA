// Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. Given such an array, find the value of k.

// Examples:

// Input : arr[] = {15, 18, 2, 3, 6, 12}
// Output: 2
// Explanation : Initial array must be {2, 3,
// 6, 12, 15, 18}. We get the given array after 
// rotating the initial array twice.

// Input : arr[] = {7, 9, 11, 12, 5}
// Output: 4

// Input: arr[] = {7, 9, 11, 12, 15};
// Output: 0

#include<iostream>
using namespace std;
int main()
{
    int arr[]={15, 18, 2, 3, 6, 12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int start = 0, end= n-1;
    while(start<=end){
        int mid=(start+end)/2;
        int prev=(mid+n-1)%n;
        int next=(mid+1)%n;
        if(arr[prev]>=arr[mid] && arr[next]>=arr[mid])
        {
            cout<<"Rotation: "<<mid;
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
    
    return 0;
}