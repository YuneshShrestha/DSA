// We are given a row-wise sorted matrix of size r*c, we need to find the median of the matrix given. It is assumed that r*c is always odd.

// Examples: 

// Input: 1 3 5
//         2 6 9
//         3 6 9
// Output: Median is 5
// If we put all the values in a sorted 
// array A[] = 1 2 3 3 5 6 6 9 9)

// Input: 1 3 4
//        2 5 6
//        7 8 9
// Output: Median is 5

#include<iostream>
#include<algorithm>
using namespace std;

int rows=3, columns=3;
int binary_search(int arr[][3], int start, int end){
    int requiredElements=(rows*columns+1)/2;
    int mid;
    while(start!=end)
    {
        mid=start+(end-start)/2;
        int count=0;
        for(int i=0; i<3; i++)
        {
            // counting mininmum and extact element to mid
            count+=upper_bound(arr[i], arr[i]+3, mid)-arr[i];
        }
        if(count>=requiredElements)
        {
            end=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    return end;
}
int main()
{
    int a[][3]={{1 ,3 ,10},{2, 12, 18}, { 3, 12, 18}};
    int min_element, max_element;
    max_element = a[0][2];
    min_element= a[0][0];
    for(int i=1; i<3; i++)
    {
      
       if(a[i][2]>max_element)
       {
        max_element=a[i][2];
       }
    
       if(a[i][0]<min_element)
       {
        min_element=a[i][0];
       }
    }
    cout<<binary_search(a, min_element, max_element);   
    
    return 0;
}