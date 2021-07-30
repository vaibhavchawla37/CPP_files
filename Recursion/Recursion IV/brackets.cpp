#include<iostream>
#include <string>
using namespace std;
void brackets(char* op,int idx,int n ,int cnt_o,int cnt_c){
    if(idx == 2*n){
       op[idx]='\0';
       cout<<op<<endl;
        return ;
    }

    if(cnt_o<n){
        op[idx]='(';
        brackets( op,idx+1,n,cnt_o+1,cnt_c);
    }

    if(cnt_c<cnt_o){
        op[idx]=')';
        brackets( op,idx+1,n,cnt_o,cnt_c+1);
    }
    
    return;
}

int main(){
    int n ;
   // cin>>n;
    char op[100];
    brackets(op,0,2,0,0);
    
    return 0;
}
//  g++ brackets.cpp -o brackets && .\brackets