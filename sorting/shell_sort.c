#include<stdio.h>
#include<stdlib.h>
#define SIZE 9
void swap(int *d1, int *d2){
    int temp;
    temp= *d1;
    *d1=*d2;
    *d2=temp;
}
void shellSort(int arr[]){
    int gap= SIZE/2;
    while(gap>=1){
        for(int i=0; i<SIZE; i++){
            if(i+gap < SIZE){
                if(arr[i+gap]<arr[i]){
                     swap(&arr[i],&arr[i+gap]);
                }
                if(i-gap>=0 && arr[i-gap]>arr[i]){
                   
                     swap(&arr[i-gap],&arr[i]);
                }
            }
            else{
                    gap/=2;
                    break;
                }
            for(int i=0; i<SIZE; i++){
                printf("%d\t",arr[i]);
            }
            printf("\n");
        }
        printf("\n");
       
    }


}
int main(){
    int arr[SIZE]={23, 29, 15, 19, 31, 7, 9, 5, 2};
    shellSort(arr);
    printf("Sorted List: ");
    for(int i=0; i<SIZE; i++){
        printf("%d\t",arr[i]);
    }

    return 0;
}