#include<stdio.h>
int count=0;
void solve(int s, int d, int h, int n)
{
    count++;
    if(n==1){
        printf("Plate: %d moved from %d to %d.\n", n, s,d);
        return;
    }
    // in this method (n-1) disk is transferred from source to helper using destination as helper 
    solve(s, h, d, n-1);
    printf("Plate: %d moved from %d to %d.\n",n, s,d);
    // in this method (n-1) disk is transferred from helper to destination using source as helper 
    solve(h,d,s,n-1);

}
int main(){
    int n, s=1, h=2, d=3;
    printf("Enter no. of plates: ");
    scanf("%d",&n);
    solve(s,d,h,n);
    printf("Steps taken: %d",count);
    return 0;
}