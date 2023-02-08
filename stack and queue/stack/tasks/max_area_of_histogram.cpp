#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
int main(){
    vector<int> arr={6,2,5,4,5,1,6};
    // nsl index
    vector<int> v;
    stack<pair<int, int>> s;
    int pseudoIndex=-1;
    for(int i=0; i<arr.size();i++){
        if(s.empty()){
            v.push_back(pseudoIndex);
        }
        else if (s.size() >0 && s.top().second < arr[i])
        {
            v.push_back(s.top().first);
        }
        else if (s.size() >0 && s.top().second >= arr[i])
        {
           while(s.size() >0 && s.top().second >= arr[i]){
                s.pop();
           }
           if(s.size() == 0){
            v.push_back(pseudoIndex);
           }
           else{
            v.push_back(s.top().first);
           }
        }
        s.push({i,arr[i]});        
    }
    // nsr index
    vector<int> v1;
    stack<pair<int, int>> s1;
    int pseudoIndex1 = 7;
    for(int i=arr.size() -1; i>=0;i--){
        if(s1.empty()){
            v1.push_back(pseudoIndex1);
        }
        else if (s1.size() >0 && s1.top().second < arr[i])
        {
            v1.push_back(s1.top().first);
        }
        else if (s1.size() >0 && s1.top().second >= arr[i])
        {
           while(s1.size() >0 && s1.top().second >= arr[i]){
                s1.pop();
           }
           if(s1.size() == 0){
            v1.push_back(pseudoIndex1);
           }
           else{
            v1.push_back(s1.top().first);
           }
        }
        s1.push({i,arr[i]});        
    }
    reverse(v1.begin(), v1.end());
    vector<int> answer;
    for(int i=0; i<v1.size(); i++){
        answer.push_back((v1[i]-v[i]-1)*arr[i]);
    }
    
    cout<< *max_element(answer.begin(), answer.end());
    return 0;
}