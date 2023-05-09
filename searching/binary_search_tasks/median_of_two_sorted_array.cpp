#include<iostream>
using namespace std;
double median(int arr1[], int arr2[], int n1, int n2)
{
    
    if(n1<n2){
       return median(arr2,arr1,n2,n1);
    }
    int start=0, end=n1;
    while(start<end)
    {
        int cut1=start+(end-start)/2;
        // cut = n2-cut1 works only if n1 and n2 both are even but cut2=(n1+n2+1)/2-cut1 works for all
        int cut2=(n1+n2+1)/2-cut1;

        int l1=cut1==0?INT_MIN:arr1[cut1-1];
        int l2=cut2==0?INT_MIN:arr2[cut2-1];

        int r1=cut1==n1?INT_MAX:arr1[cut1];
        int r2=cut2==n2?INT_MAX:arr2[cut2];
        cout<<n1<<" "<<n2<<" "<<cut1<<" "<<cut2<<" "<<l1<<" "<<l2<<" "<<r1<<" "<<r2<<endl;
        if(l1<=r2 && l2<=r1)
        {
            if((n1+n2)%2==0)
            {
                return (max(l1, l2) + min(r1, r2))/2.0;
            }
            else
            {
                return max(l1,l2);
            }
        }
        else if(l1>r2)
        {
            end=cut1-1;
        }
        else
        {
            start=cut1+1;
        }
    }
    return 0.0;
}
int main()
{
    int arr1[]={1,3,5};
    int arr2[]={4};
    int n1= sizeof(arr1)/sizeof(arr1[0]);
    int n2=sizeof(arr2)/sizeof(arr2[0]);   
    cout<<median(arr1,arr2, n1, n2);
    return 0;
}