#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
int main(){
    // Like nearest greater left (ngl)
    
    vector<int> arr;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int value;
        cin>>value;
        arr.push_back(value);
    }
    vector<int> v;
    stack<pair<int,int>> s;
    // left to right
    for(int i=0; i<arr.size();i++){
        if(s.empty()){
            v.push_back(-1);
        }
        else if(s.size() >0 && s.top().second > arr[i]){
            v.push_back(s.top().first);
        }
        else if(s.size() >0 && s.top().second <= arr[i]){
            while(s.size() >0 && s.top().second <= arr[i]){
                s.pop();
            }
            if(s.empty()){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().first);
            }
        }
        s.push({i,arr[i]});
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout<<i-v[i]<<" ";
    }
    
    return 0;
}