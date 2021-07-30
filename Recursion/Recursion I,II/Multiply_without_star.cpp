#include<iostream>
using namespace std;

int multiply (int n,int k){
    if (k==1)
        return n;
    if (n==0 or k==0) return 0;
    return n+multiply(n,k-1);
    
}
int main(){
    int n=2;
    int k=3;
    cout<<multiply(n,k);
  
    return 0;
}//>g++ Multiply_without_star.cpp  -o Multiply_without_star  && .\Multiply_without_star 