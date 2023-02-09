#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
void swap(int *d1, int *d2){
    int temp;
    temp= *d1;
    *d1=*d2;
    *d2=temp;
}
void selectionSort(int arr[SIZE]){
    // Ya track garda sano element agadi aaudai janxa

    for(int i=0; i<=SIZE-2; i++){
       int min_idx=i;
       for (int j = i+1; j <= SIZE-1; j++)
       {
         if(arr[j]<arr[min_idx]){
            min_idx=j;
         }
       }
       swap(&arr[min_idx],&arr[i]);   
    }
}
int main(){
    int arr[SIZE]={5,2,4,6,1,3};
    selectionSort(arr);
    printf("Sorted List:");
    for(int i=0; i<SIZE; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}