#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
void swap(int *d1, int *d2){
    int temp;
    temp= *d1;
    *d1=*d2;
    *d2=temp;
}
void bubbleSort(int arr[SIZE]){
    // BEST CASE: O(N) complexity
    // Worst Case: O(N^2) complexity
    for(int j=1; j<=SIZE-1; j++){
    // Ya track garda thulo element paxadi sardai janxa
        int issort=1;
        for(int i=0;i<=SIZE-j-1;i++){
            if(arr[i]>arr[i+1]){
                swap(&arr[i], &arr[i+1]);
                issort=0;
            }
        }
        if(issort==1)
            break;
    }
}
int main(){
    int arr[SIZE]={-2,45,0,11,-9};
    bubbleSort(arr);
    printf("Sorted List:");
    for(int i=0; i<SIZE; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}