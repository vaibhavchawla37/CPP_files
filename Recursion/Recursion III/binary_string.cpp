#include<iostream>
using namespace std;

int binary_string(int  n ,int last_digit){
   
    if (n==0) return 0;
    
    if (n==1){
        if(last_digit==1) return 1;
        if(last_digit==0) return 2;
    }
    
    
    if(last_digit==0)
        return binary_string(n-1,0) + binary_string(n-1,1);
    
    if(last_digit==1)
        return binary_string(n-1,0);



}

int main(){
    int n;

    cout<<binary_string(3,0) ;
    

   return 0;

}
//  g++ binary_string.cpp -o binary_string && ./binary_string