#include<iostream>
using namespace std;
int main(){
    int data[] = {9,8,7,6,4}, element, reqdIndex=-1;
    int start=0, end=(sizeof(data)/sizeof(data[0]))-1;
    cout<<"What do you want to search?: ";
    cin>>element;
    while (start<=end)
    {
        int mid=start+(end-start)/2;
        if(data[mid]==element)
        {
            reqdIndex=mid;
            break;        
        }   
        else if (data[mid]>element)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        
    }
    if(reqdIndex==-1){
        cout<<"Element Not Found.";
    }
    else{
        cout<<"Required Index is "<<reqdIndex;
    }
    
    return 0;
}