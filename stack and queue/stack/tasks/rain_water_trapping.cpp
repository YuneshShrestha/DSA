#include <bits/stdc++.h>
#include <vector>
using namespace std;
int min(int a, int b){
    if(a<b){
        return a;
    }
    else {
        return b;
    }
}
int main(){
    int sum=0;
    vector<int> arr={3,0,0,2,0,4};
    vector<int> maxl,maxr;
    
    // MAX LEFT
    maxl.push_back(arr[0]);
    for(int i=1; i<arr.size();i++){
        if(maxl[i-1]<arr[i]){
            maxl.push_back(arr[i]);
        }
        else{
            maxl.push_back(maxl[i-1]);
        }
    }

    // MAX RIGHT
     maxr.push_back(arr[arr.size() - 1]);
     for(int i=arr.size() - 2; i>=0;i--){
        if(maxr[i+1]<arr[i]){
            maxr.push_back(arr[i]);
        }
        else{
            maxr.push_back(maxr[i+1]);
        }
    }
    // min from maxl and maxr and subtraction with array
    for(int i=0; i<arr.size();i++){
        arr[i] = min(maxl[i],maxr[i])-arr[i];
    }
     for(int i=0; i<arr.size();i++){
        sum+=arr[i];
     }
     cout<<"ANS: "<<sum;

    return 0;
}
