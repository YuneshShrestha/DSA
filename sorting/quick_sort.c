#include<stdio.h>
#include<stdlib.h>
#define SIZE 6
void swap(int *d1, int *d2){
    int temp;
    temp= *d1;
    *d1=*d2;
    *d2=temp;
}
int partition(int arr[], int p, int r) {
    int x = arr[r];
    int i = p-1;
   
    for (int j = p; j <= r-1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i],&arr[j]);
        }
       
    }
     swap(&arr[i+1],&arr[r]);
  
    return i+1;
}

void quickSort(int arr[], int p, int r) {
    if (p < r) {
        int q = partition(arr, p, r); //O(N)
        quickSort(arr, p, q-1);
        quickSort(arr, q+1, r);
    }
}
int main(){
    int arr[]={50,23,9,18,61,32};
    quickSort(arr,0,SIZE-1);
    printf("Sorted List: ");
    for(int i=0; i<SIZE; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}