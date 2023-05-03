// SEARCH IN A ROW WISE AND COLUMN WISE SORTED MATRIX:

// Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.
// Example :

// Input : mat[4][4] = { {10, 20, 30, 40},
//                       {15, 25, 35, 45},
//                       {27, 29, 37, 48},
//                       {32, 33, 39, 50}};
//               x = 29
// Output : Found at (2, 1)

#include<iostream>
using namespace std;
pair<int,int> search(int arr[][4], int element)
{
    int i=0, j=3;
    pair<int,int> ans;
    while(i>=0 && j>=0)
    {
        if(arr[i][j]==element)
        {
            ans.first=i;
            ans.second=j;
            return ans;
        }
        else if(arr[i][j]>element)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    ans.first=-1;
    ans.second=-1;
    return ans;
}
int main()
{
    int mat[4][4]={ {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50}
                  };
    int element;
    cout<<"Element: ";
    cin>>element;
    pair<int,int> ans=search(mat, element);
    cout<<"("<<ans.first<<","<<ans.second<<")";
    
    return 0;
}