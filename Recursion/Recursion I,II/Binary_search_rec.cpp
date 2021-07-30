#include<iostream>
using namespace std;

void binary_search_rec (int a[],int s,int l,int key){
    int m = (s+l)/2 ;
    if(a[m]==key) {
        cout<<key <<" : "<<m;
        return ;
    }

    if(s>=l) {
        cout<<key<<" Not present";
        return ;
    } ;
    
    if(key<a[m]){
        l=m-1;
    }

    if(key>a[m]){
        s=m+1;
    }

    binary_search_rec(a,s,l,key);



    
}
int main(){
    int a[]={1,2,3,4,5,6};
    int n=sizeof(a)/sizeof(a[0]);
    int s=0;
    int l=n-1;
    int key=7;
    
    binary_search_rec(a,s,l,key);
    return 0;
}//>g++ binary_search_rec.cpp  -o binary_search_rec  && .\binary_search_rec 