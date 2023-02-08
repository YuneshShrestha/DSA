// Using Extra Space
#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
class Answer{
    stack<int> s;
    int minValue;
    public:
    void push(int n){
        if(s.empty()){
            s.push(n);
            minValue=n;
        }
        else if(n>=minValue){
            s.push(n);
        }
        else{
            s.push((2*n) - minValue);
            minValue = n;
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        else if(s.top()>=minValue){
            int curr=s.top();
            s.pop();
            return curr;
        }
        else{
            int curr=s.top();
            minValue = (2*minValue) - curr;
            s.pop();
            return (curr+minValue)/2;
        }
    }
    int getMin(){
       if(s.empty()){
        return -1;
       }
       return minValue;
    }
};
int main(){    
    Answer ans;
    int n,p;
    while(cin.peek() != '\n'){
        cin>>n;
        ans.push(n);   
    }
    cout<<"How many times do you want to pop?";
    cin>>p;
    for(int i=0;i<p;i++){
        cout<<ans.pop()<<" has been popped."<<"\n";
    }
    cout<<"Min: "<<ans.getMin();
    
    return 0;
}
