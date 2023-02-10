#include<stdio.h>
#include<stdlib.h>
int sequential_search(int arr[], int key, int n){
    for (int i = 0; i < n; i++)
    {
       if(arr[i]==key){
        return i;
       }
    }
    return -1;
    
}
int main(){
    int arr[] = {12, 2,7,3,6,8,1}, element;
    int n= sizeof(arr)/sizeof(arr[0]);
    printf("Which element index do you want to know? Element:");
    scanf("%d", &element);
    int index = sequential_search(arr, element, n);
    printf("Index of %d : %d", element ,index);
    return 0;
}