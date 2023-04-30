#include<iostream>
using namespace std;
int main(){
    int data[] = {1,2,3,4}, element, reqdIndex=-1, isAscending=0;
    int start=0, end=(sizeof(data)/sizeof(data[0]))-1;
    cout<<"What do you want to search?: ";
    cin>>element;
    // Checking is elements are more than 1
    if(start!=end){
        if(data[start]<data[end]){
            isAscending=1;
        }
    }
    while (start<=end)
    {
        int mid=(start+end)/2;
        if(data[mid]==element)
        {
            reqdIndex=mid;
            break;        
        }   
        else if (data[mid]>element)
        {
            if(isAscending)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
           
        }
        else
        {
            if(isAscending)
            {
                start=mid+1;
            }
            else
            {
                end=mid-1;
            }
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