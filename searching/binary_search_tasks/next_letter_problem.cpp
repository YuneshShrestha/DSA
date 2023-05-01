// Given an array of letters sorted in ascending order, 
// find the smallest letter in the the array which is greater than a given key letter. 

#include<iostream>
using namespace std;
int main(){
    char arr[]= {'a','c','f','h'};
    char target;
    cout<<"Enter the Element: ";
    cin>>target;
    int start=0, end= (sizeof(arr)/sizeof(arr[0]))-1;
    char res='#';
    while(start<=end)
    {
        int mid=(start+end)/2;
        if(arr[mid]>target)
        {
            res=arr[mid];
            end=mid-1;
        }
        else if (arr[mid]<=target)
        {
            start=mid+1;
        }
    }
    cout<<"Next Letter: "<<res;
    return 0;
}