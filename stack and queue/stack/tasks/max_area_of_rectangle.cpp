#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
int findMAH(vector<int> temp){
        // vector<int> temp={6,2,5,4,5,1,6};
    // nsl index
    vector<int> v;
    stack<pair<int, int>> s;
    int pseudoIndex=-1;
    for(int i=0; i<temp.size();i++){
        if(s.empty()){
            v.push_back(pseudoIndex);
        }
        else if (s.size() >0 && s.top().second < temp[i])
        {
            v.push_back(s.top().first);
        }
        else if (s.size() >0 && s.top().second >= temp[i])
        {
           while(s.size() >0 && s.top().second >= temp[i]){
                s.pop();
           }
           if(s.size() == 0){
            v.push_back(pseudoIndex);
           }
           else{
            v.push_back(s.top().first);
           }
        }
        s.push({i,temp[i]});        
    }
    // nsr index
    vector<int> v1;
    stack<pair<int, int>> s1;
    int pseudoIndex1 = temp.size();
    for(int i=temp.size() -1; i>=0;i--){
        if(s1.empty()){
            v1.push_back(pseudoIndex1);
        }
        else if (s1.size() >0 && s1.top().second < temp[i])
        {
            v1.push_back(s1.top().first);
        }
        else if (s1.size() >0 && s1.top().second >= temp[i])
        {
           while(s1.size() >0 && s1.top().second >= temp[i]){
                s1.pop();
           }
           if(s1.size() == 0){
            v1.push_back(pseudoIndex1);
           }
           else{
            v1.push_back(s1.top().first);
           }
        }
        s1.push({i,temp[i]});        
    }
    reverse(v1.begin(), v1.end());
    vector<int> answer;
    for(int i=0; i<v1.size(); i++){
        answer.push_back((v1[i]-v[i]-1)*temp[i]);
    }
    
    return *max_element(answer.begin(), answer.end());
}
int max(int a, int b){
    if(a>b){
        return a;
    }
    else {
        return b;
    }
}
int main(){
    int n,m;
    // n x m
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>arr[i][j];
        }
    }
    // here we turn 2D array to 1D
    vector<int> v;
    for(int j=0;j<m;j++)
    {
        v.push_back(arr[0][j]);
    } 
    int mx=findMAH(v);
    
    for(int i=1;i<n;i++)
    {
        for(int j=0; j<m;j++){
            if(arr[i][j]==0){
                v[j] = 0;
            }
            else {
                v[j] += arr[i][j];
            }
        }
        mx = max(findMAH(v),mx);
    } 
    cout<<"ANS: "<<mx;
    
    return 0;
}