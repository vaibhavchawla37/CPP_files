
#include<iostream>
#include<algorithm>
using namespace std;

int partition(int *a,int s,int l){
  
    int i=s;
    int j=s+1;
    int pivot=a[s];
    while(j<=l){
        if(a[j]<=pivot){
            i=i+1;
            swap(a[i],a[j]);
        }
        j++;
    }
    swap(a[s],a[i]);
    return i;

    
}

void quick_sort (int a[],int s,int l){
    if(s>=l) return;

    int p=partition(a,s,l);

    
    quick_sort(a,s,p-1);
    quick_sort(a,p+1,l);

    

    
}


int main(){

    int a[]={5,4,1,3,2,7,8};
    int n = sizeof(a)/sizeof(a[0]);

    quick_sort(a,0,n-1);
 

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }



    return 0;
}//g++ quick_sort.cpp  -o quick_sort  && .\quick_sort 