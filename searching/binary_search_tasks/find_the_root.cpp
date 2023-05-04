// Given two number x and n, find n-th root of x. 

// Examples: 

// Input : 5 2
// Output : 2.2360679768025875

// Input :  x = 5, n = 3
// Output : 1.70997594668

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    double start=0, end=n;
    double mid;

    while((end-start)>0.000001)
    {

        mid=start+(end-start)/2;
        if(pow(mid,m)>n)
        {
            end=mid;
        }
        else
        {
            start=mid;
        }
        
    }
    cout<<mid;
    return 0;
}