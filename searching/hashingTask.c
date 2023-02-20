// You are given an array of  psitive and -ve numbers from -SIZE to +SIZE
// Task is to search whether element is present or not in O(1) time
#include<stdio.h>
#include<stdlib.h>
#define SIZE 1000
int hashTable[SIZE+1][2];
int searchData(int n)
{
    if(n>=0){
        if(hashTable[n][0]==1){
            return 1;
        }
        else
        {
            return 0;
        }
        
    }
    else
    {
        if(hashTable[abs(n)][1]==1){
            return 1;
        }
        else{
            return 0;
        }
    }
}
void insertData(int arr[], int n){
    for (int i = 0; i <n; i++)
    {
        if(arr[i]>=0)
        {
            hashTable[i][0]=1;
        }
        else
        {
            hashTable[abs(arr[i])][1]=1;
        }
    }
    
}

int main(){
    int arr[]={-1,0,1,2,3,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertData(arr,size);
    int isDataAvailable = searchData(9);
    if (isDataAvailable)
    {
        printf("Available");
    }
    else{
        printf("Not Avilable");
    }
    
    return 0;
}