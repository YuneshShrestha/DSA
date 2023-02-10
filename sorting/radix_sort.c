#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int getMax(int arr[]){
    int max=arr[0];
    for(int i=1; i<SIZE; i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}
void countingSort(int arr[],int k, int pos){
   int b[SIZE], count[k+1];
   
// Setting all the elements of count to zero
   for (int i = 0; i <= k; i++) {
    count[i] = 0;
  }
// Counting the number of occurence of digit
  for (int i = 0; i <SIZE; i++) {
    ++count[(arr[i]/pos)%10];
  }
// By this we we get a array where we can tell from which index-1 to which index-1 the value will occur 
   for (int i = 1; i <= k; i++)
   {
     count[i] += count[i-1];
   }
// Now we are creating a array of sorted list
   for (int i = SIZE-1; i >= 0; i--)
   {
        b[--count[(arr[i]/pos)%10]]=arr[i];
   }
//    Copying the sorted list to actual list
   for (int i = 0; i < SIZE; i++)
   {
        arr[i]=b[i];
   }
   
} 
void radixSort(int arr[]){
    int max = getMax(arr);
    for (int pos = 1; max/pos > 0; pos*=10)
    {
       countingSort(arr, 9 , pos);
    }
}

int main(){
    int arr[SIZE]={432, 8, 530, 90, 88, 231, 11, 45, 677, 199};
    radixSort(arr);
    printf("Sorted List:");
    for(int i=0; i<SIZE; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

