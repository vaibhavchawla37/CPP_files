#include<iostream>
using namespace std;

int Power (int n,int k){
    if (k==0)
        return 1;
    
    int ans=Power(n,k/2);
    ans=ans*ans;
    
    if(k%2!=0) return ans*n;

    return ans;

    
}
int main(){
    int n=5;
    int k=3;
    cout<<Power(n,k);
  
    return 0;
}//>g++ Power.cpp  -o Power  && .\Power 