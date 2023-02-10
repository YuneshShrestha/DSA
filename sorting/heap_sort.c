#include<stdio.h>
#include<stdlib.h>
void swap(int *d1, int *d2){
    int temp;
    temp= *d1;
    *d1=*d2;
    *d2=temp;
}
void maxHeapify(int arr[], int n,int i){
    int largest=i;
    int l=2*i + 1 , r= 2* i+2;
    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }
    if(largest!=i){
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, n,largest);
    }

}
void heapSort(int arr[], int n){
    // Build a max heapify
   for (int i = n/2 -1; i >= 0; i--)
   {
    maxHeapify(arr,n,i);
   }
//    Delete and sort
   for(int i=n-1; i>=0; i--){
    swap(&arr[0],&arr[i]);
    maxHeapify(arr,i,0);
   }
   
}
int main(){
    int arr[]={12, 11, 13, 5, 6, 7};
    int n= sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    printf("Sorted List: ");
    for(int i=0; i<n; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}