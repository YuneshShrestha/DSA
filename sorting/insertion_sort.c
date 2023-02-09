#include<stdio.h>
#include<stdlib.h>
#define SIZE 8
void insertionSort(int arr[SIZE]){
    int key, j;
    for(int i=1; i<SIZE; i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}
int main(){
    int arr[SIZE]={4,3,2,10,12,1,5,6};
    insertionSort(arr);
    printf("Sorted List:");
    for(int i=0; i<SIZE; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}