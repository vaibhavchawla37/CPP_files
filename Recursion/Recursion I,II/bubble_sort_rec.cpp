#include<iostream>
#include<algorithm>
using namespace std;

void bubble_sort (int a[],int n){
    if(n==1) return;
    for(int j=0;j<n-1;j++){
        if(a[j]>a[j+1]){
            swap(a[j],a[j+1]);
        }
    }
    bubble_sort(a,n-1);
    
}
//int i=0;
void bubble_sort_rec (int a[],int j,int n){
    if(n==1) return;
    
    if(j!=n-1){
        if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
     //   cout<<" "<<j_1++<<" ";
        bubble_sort_rec(a,j+1,n);
 //    cout<<i++<<endl;
    //;
    }

    bubble_sort_rec(a,0,n-1);
    
}
// 4 5 1 3 2 

int main(){

    int a[]={5,4,1,3,2};
    int n = sizeof(a)/sizeof(a[0]);

    bubble_sort_rec(a,0,n);
 

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }



    return 0;
}//>g++ bubble_sort_rec.cpp  -o bubble_sort_rec  && .\bubble_sort_rec 