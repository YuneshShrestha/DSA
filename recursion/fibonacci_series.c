#include<stdio.h>
int fibonacciSeries(int n){
    if(n<=1){
        return n;
    }
    return fibonacciSeries(n-1) + fibonacciSeries(n-2);
}
int main(){
    int n,i=0;
    printf("How Long Fibonacci Series you want? : ");
    scanf("%d",&n);
    while(i!=n)
    {
        printf("%d ",fibonacciSeries(i));
        i++;
    }
    return 0;
}