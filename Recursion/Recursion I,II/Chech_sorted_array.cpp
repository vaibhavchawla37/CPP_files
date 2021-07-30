#include<iostream>
using namespace std;

bool Chech_sorted_array (int a[],int n){

   if (n==0 or n==1) return true; 

   if(a[0]<a[1] and Chech_sorted_array(a+1,n-1) ){
       return true;
   }

   return false;
    
}
int main(){
    int n=5;
    int a[]={1,2,3,4,5};
    cout<<boolalpha;
    

    
    cout<<Chech_sorted_array(a,n);
    return 0;
}//>g++ Chech_sorted_array.cpp  -o Chech_sorted_array  && .\Chech_sorted_array 