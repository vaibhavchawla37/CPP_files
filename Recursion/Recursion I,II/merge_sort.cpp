#include<iostream>
#include<algorithm>
using namespace std;

void merge(int *a,int s,int l){
    int mid = (s+l)/2;
    int i=s;
    int j=mid+1;
    int temp[100];
    int k=s;
    
    while(i<=mid && j<=l){

        if (a[i]<=a[j])
            temp[k++] = a[i++];

        else 
            temp[k++]=a[j++];
    }

    while(i<=mid)
        temp[k++]=a[i++];

    while(j<=l)
        temp[k++]=a[j++];
    

    for(int p=s;p<=l;p++)    
        a[p]=temp[p];

    
}

void merge_sort (int a[],int s,int l){
    if(s>=l) return;

    int m = (s+l)/2;
    
    merge_sort(a,s,m);
    merge_sort(a,m+1,l);

    merge(a,s,l);


    
}


int main(){

    int a[]={5,4,1,3,2};
    int n = sizeof(a)/sizeof(a[0]);

    merge_sort(a,0,n-1);
 

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }



    return 0;
}//g++ merge_sort.cpp  -o merge_sort  && .\merge_sort 