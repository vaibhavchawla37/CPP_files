#include<iostream>
#include<stack>

using namespace std;
void span(int * stk,int n){
    stack<int> s;
    int span [100] = {0};
   
    // s.push(make_pair(0,stk[0]));
    for(int i=0;i<n;) {
        if(s.empty()){
            s.push(i);
            span[i] =i+1;
            i++;
            continue;
        }
        auto x =s.top();
        if(stk[i]<stk[x]){
            s.push(i);
            span[i] = i - x;
            i++;
        }
        if(stk[i]>=stk[x]){
            s.pop();
        }
    }
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }   
    cout<<endl;
    // while(!s.empty()){
    //     auto x = s.top();
    //     cout<<x<<" ";
    //     s.pop();
    // }
    


}

int main(){
    int stk[] = {100,80,60,70,60,75,185};
    int n = sizeof(stk)/sizeof(stk[0]);
 //   stack<pair<int,int>> s = span(stk,n);
 span(stk,n);
    // while(!s.empty()){
    //     auto x = s.top();
    //     cout<<x.first<<" "<<x.second;
    //     s.pop();
    // }
}

//  g++ stock_span.cpp -o stock_span && .\stock_span