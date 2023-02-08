// Using Extra Space
#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;
class Answer{
    stack<int> s, ss;
    public:
    void push(int n){
        s.push(n);
        if(ss.empty() || ss.top()>=n){
            ss.push(n);
        }
    }
    int pop(){
        if(s.empty()){
            return -1;
        }
        int val=s.top();
        s.pop();
        if(ss.top()==val){
            ss.pop();
        }
        return val;
    }
    int getMin(){
        if(ss.empty()){
            return -1;
        }
        return ss.top();
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
