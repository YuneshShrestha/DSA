// ALLOCATE MINIMUM NUMBER OF PAGES:

// Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

// Example :

// Input : pages[] = {12, 34, 67, 90}
//         m = 2
// Output : 113
// Explanation:
// There are 2 number of students. Books can be distributed 
// in following fashion : 
//   1) [12] and [34, 67, 90]
//       Max number of pages is allocated to student 
//       2 with 34 + 67 + 90 = 191 pages
//   2) [12, 34] and [67, 90]
//       Max number of pages is allocated to student
//       2 with 67 + 90 = 157 pages 
//   3) [12, 34, 67] and [90]
//       Max number of pages is allocated to student 
//       1 with 12 + 34 + 67 = 113 pages

// Of the 3 cases, Option 3 has the minimum pages = 113. 

#include<iostream>
using namespace std;
pair<int,int> maxAndSum(int arr[], int n)
{
   int max=arr[0], sum=arr[0];
   pair<int, int> ans;
   for (int i = 1; i < n; i++)
   {
     sum+=arr[i];
     if(max<arr[i])
     {
        max=arr[i];
     }
   }
   ans.first=max;
   ans.second=sum;
   
    return ans;
}
bool isValid(int arr[], int minPages, int n, int totalStudent)
{
    bool valid=false;
    int student=1, pages=0, i=0;
    while(i<n)
    {
        pages+=arr[i];
        if(pages>minPages)
        {
           student++;
        }
        if(student>totalStudent)
        {
            return false;
        }
        i++;
    }
    return true;
}
int main()
{
    int arr[]= {12, 34, 67, 90};
    int m=2;
    int n=(sizeof(arr)/sizeof(arr[0]));
    pair<int,int> ans=maxAndSum(arr,n);
    int max=ans.first;
    int sum=ans.second;
    int start=max, end=sum, res=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isValid(arr, mid, n, m))
        {
            res=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }  
    cout<<res;
    return 0;
}
