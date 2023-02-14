#include<stdio.h>
#include<stdlib.h>
int binary_search(int arr[], int start, int end, int key)
{
   if(start<=end){
     int midValue= (start+end)/2;
    if(arr[midValue] == key)
    {
        return midValue;
    }
    if(arr[midValue]>key)
    {
        return binary_search(arr, start, midValue-1, key);
    }
    else
    {
        return binary_search(arr, midValue+1, end, key);   
    }
   }
    
    return -1;
    
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8}, element;
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("Which element index do you want to know? Element:");
    scanf("%d", &element);
    int index = binary_search(arr, 0, n-1 ,element);
    printf("Index of %d : %d", element ,index);
    return 0;
}