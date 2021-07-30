#include<iostream>
#include<stack>
using namespace std;

int main(){
    int a[] =  {2,6,1,7};
    int n = sizeof(a)/sizeof(a[0]);
    stack<int> s;
    s.push(a[n-1]);
    int o[n]={0};
    o[n-1] = -1;

    for (int i=n-2;i>=0;i--){
        if(a[i]>=s.top() ){
            if(a[i]==s.top()){
                o[i] =-1;
            }else
            o[i] = s.top();
          //  cout<<o[i];
            s.push(a[i]);
        }
        else{
            while(!s.empty() and a[i]<s.top()){
               // cout<<s.top()<<" ";
                s.pop();
            }
            if(s.empty()){
                o[i] = -1;
                s.push(a[i]);
                continue;
            }
            o[i] = s.top();
           // cout<<o[i];
            s.push(a[i]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<o[i]<<" ";
    }
}