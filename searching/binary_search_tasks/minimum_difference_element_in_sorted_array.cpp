// Given a sorted array, find the element in the array which has minimum difference with the given number. 
#include<iostream>
using namespace std;
int main()
{
    int arr[]={1,3,8,10,15};
    int min_element_of;
    cin>>min_element_of;
    int n=sizeof(arr)/sizeof(arr[0]);
    int start=0, end=n-1, res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(arr[mid]==min_element_of)
        {
            res=mid;
            break;
        }
        else if(arr[mid]>min_element_of)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if(res==-1)
    {
     res =(abs(arr[end]-min_element_of)<abs(arr[start]-min_element_of))?end:start;
    }
    cout<<res;
    return 0;
}