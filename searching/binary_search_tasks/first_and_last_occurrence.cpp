#include<iostream>
using namespace std;

int firstOccurence(int data[], int start, int end, int element){
    int res=-1;
    while (start<=end)
    {
        int mid=(start+end)/2;
        if(data[mid]==element)
        {
            res=mid;
            end=res-1;
        }   
        else if (data[mid]>element)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        
    }
    return res;
}

int lastOccurence(int data[], int start, int end, int element){
     int res=-1;
    while (start<=end)
    {
        int mid=(start+end)/2;
        if(data[mid]==element)
        {
            res=mid;
            start=res+1;
        }   
        else if (data[mid]>element)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        
    }
    return res;
}

int main(){
    int data[] = {7,7,7,8,9}, element, reqdIndex=-1;
    int start=0, end=(sizeof(data)/sizeof(data[0]))-1;
    cout<<"What do you want to search?: ";
    cin>>element;
    int firstIndex=firstOccurence(data, start, end, element), lastIndex=lastOccurence(data, start, end, element);
    cout<<"First Occurence: "<<firstIndex<<"\n";
    cout<<"Last Occurence: "<<lastIndex<<"\n";
    cout<<"Number of Occurence: "<<lastIndex-firstIndex+1;

      
    return 0;
}