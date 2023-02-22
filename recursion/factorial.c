#include<stdio.h>
int factorial(int n){
    if(n==0){
        return 1;
    }
    return n*factorial(n-1);
}
int main(){
    int n;
    printf("Enter a number to know its factorial: ");
    scanf("%d",&n);
    printf("%d",factorial(n));
    return 0;
}