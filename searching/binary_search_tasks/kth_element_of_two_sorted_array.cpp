#include<iostream>
using namespace std;
int findKthElement(int arr1[], int arr2[], int n1, int n2, int k)
{
    // Always use binary search on small array to reduce search space which reduces time complexity
    if(n1>n2)
    {
        return findKthElement(arr2, arr1, n2, n1, k);
    }
    // if k=3 and arr1 has 4 elements so low=0 and high= 3 (since we need 3rd element)so  high=min(k, n1)
    // if k=6 and arr2 has only 5 elements then there must be 1 element in minimum from arr1 so low=1 that's why low=max(0, k-n2)
    
    int low=max(0, k-n2), high=min(k, n1);
    while(low<=high)
    {
    //  cut2=k-cut1 ensures there are only k elements on left half
        int cut1=(low+high) /2, cut2=k-cut1;
        int l1=cut1==0?INT_MIN:arr1[cut1-1];
        int l2=cut2==0?INT_MIN:arr2[cut2-1];
        int r1=cut1==n1?INT_MAX:arr1[cut1];
        int r2=cut2==n2?INT_MAX:arr2[cut2];
        cout<<cut1<<" "<<cut2<<" "<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<highl;
        if(l1<=r2 && l2<=r1)
        {
            return max(l1, l2);
        }    
        else if(l1>r2)
        {
            high=cut1-1;
        }
        else
        {
            low=cut1+1;
        }
    }
    return -1;
}
int main()
{
    int arr1[]={1,3,4,7,10,12};
    int arr2[]={2,3,5,6};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    int k;
    cin>>k;
    cout<<findKthElement(arr1, arr2, n1, n2,k);
    return 0;
}