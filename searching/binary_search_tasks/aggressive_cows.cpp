#include<iostream>
using namespace std;
bool isValid(int stalls[], int n,int k, int distance)
{
    // assuming that 1 cow takes the 1st position
    int countAggressiveCows=1;
    int lastCowPostion=stalls[0];
    for(int i=1; i<n; i++)
    {
        int calcDistance=stalls[i]-lastCowPostion;

        if(calcDistance>=distance)
        {
            // calculating distance from previous placed cow
            lastCowPostion=stalls[i];
            countAggressiveCows++;
        }
        if(countAggressiveCows==k)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int stalls[]={1,2,4,8,9};
    int k;
    int n=sizeof(stalls)/sizeof(stalls[0]);
    cin>>k;
    int start=stalls[0], end=stalls[n-1];
    int res=-1;
    while(start<end)
    {
        int mid=start+(end-start)/2;
        if(isValid(stalls,n, k, mid))
        {
            res=mid;
            // since laragest min distance so shift right to find high distance
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    cout<<res;
    return 0;
}