#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

// This function is to merge subarray in sorted order
void merge(int arr[], int lb, int mid, int ub){
    // i = to track beginning sub-array elements, j = to track ending sub-array elements, k=for tracking new array b
    int i=lb, j=mid+1, k=lb;
    int b[SIZE];
    while (i<=mid && j<=ub)
    {
        // In this loop if beginning array contains less value element than ending array then keep the less value element 
        // in new array b and increase the value of i else vice versa
       if(arr[i]<=arr[j])
       {
            b[k]=arr[i];
            i++;
       }
       else
       {
            b[k] = arr[j];
            j++;
       }
       k++;
    }
    // if some elements are remained
    if(i>mid){
        while (j<=ub)
        {
            b[k]=arr[j];
            j++;
            k++;
        }
    }
    else{
       while (i<=mid)
        {
            b[k]=arr[i];
            i++;
            k++;
        } 
    }
    for(int k=lb; k<=ub; k++)
    {
        arr[k]=b[k];
    }
}
// mergeSort divides the all the subarray till single elements appear in each sub-array in recurrsive manner
void mergeSort(int arr[], int lb, int ub){
    // This if condition is checking whether subarray contains 2 or more elements.
    if(lb<ub){
        int mid=(lb + ub)/2;
        // For beginning part
        mergeSort(arr, lb, mid);
        // For ending part
        mergeSort(arr, mid+1, ub);
        merge(arr, lb, mid, ub);
    }
}
int main(){
    int arr[]={-2,45,0,11,-9};
    mergeSort(arr,0,SIZE-1);
    printf("Sorted List:");
    for(int i=0; i<SIZE; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}