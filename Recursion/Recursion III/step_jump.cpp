#include<iostream>
using namespace std;

int step_jump(int n,int k){
    if(n<0) return 0;

    if(n==0) return 1;
    int ans = 0 ;
    for(int i=1;i<=k;i++)
        ans += step_jump(n-i,k);  
    
    return ans;

}

int main(){
   int n=4;
   int k=3;
    cout<<step_jump(n,k);

   return 0;

}
//  g++ step_jump.cpp -o step_jump && ./step_jump