/*
    Description: 
    1) sorting according to key  
    2) counting the elements having distnct key values
    Drawbacks:
    1) Not for negative number but it can be possible if you add highest negative number to all the digit and subtract it after being sorted
    2) Not for values on different range for this radix sort is good
    3) Counting sort is only effective when the range of input values is not too large. If the range of input values is too large, counting sort requires a lot of memory to store the frequency count array, making it impractical to use. So k must be of O(N)
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 17
void countingSort(int arr[],int k, int leastNumber){
     if(leastNumber<0){
        k-=leastNumber;
     }
   int b[SIZE], count[k+1];
//    If least number is negative
   if(leastNumber<0){
     for (int i = 0; i <SIZE; i++) {
        arr[i]-=leastNumber;
     }
   }
// Setting all the elements of count to zero
   for (int i = 0; i <= k; i++) {
    count[i] = 0;
  }
// Counting the number of occurence of digit
  for (int i = 0; i <SIZE; i++) {
    ++count[arr[i]];
  }
// By this we we get a array where we can tell from which index-1 to which index-1 the value will occur 
   for (int i = 1; i <= k; i++)
   {
     count[i] += count[i-1];
   }
// Now we are creating a array of sorted list
   for (int i = SIZE-1; i >= 0; i--)
   {
        b[--count[arr[i]]]=arr[i];
   }
//    Copying the sorted list to actual list
   for (int i = 0; i < SIZE; i++)
   {
        arr[i]=b[i];
   }
   
    if(leastNumber<0){
     for (int i = 0; i <SIZE; i++) {
        arr[i]+=leastNumber;
     }
   }
   
}
int main(){
    int arr[SIZE]={2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
    // 9 is passed as argument for k since it is highest element, 0 as least element
    countingSort(arr,9,0);
    printf("Sorted List:");
    for(int i=0; i<SIZE; i++){
        printf("%d ",arr[i]);
    }

    return 0;
}

