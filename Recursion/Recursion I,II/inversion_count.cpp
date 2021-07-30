#include<iostream>
#include<algorithm>
using namespace std;

int merge(int *a,int s,int l){
    int mid = (s+l)/2;
    int i=s;
    int j=mid+1;
    int temp[100];
    int k=s;
    int cnt=0;
    
    while(i<=mid && j<=l){

        if (a[i]<=a[j]){
            temp[k++] = a[i++];
        }

        else {
            temp[k++]=a[j++];
            cnt =cnt+ mid-i+1;
        }
    }

    while(i<=mid){
        temp[k++]=a[i++];
    }

    while(j<=l)
        temp[k++]=a[j++];
    

    for(int p=s;p<=l;p++)    
        a[p]=temp[p];

    return cnt;
}

int inversion_count (int a[],int s,int l){
    if(s>=l) return 0;

    int m = (s+l)/2;
    int x=inversion_count(a,s,m);
    int y=inversion_count(a,m+1,l);
    int z=merge(a,s,l);
    return x+y+z;

}


int main(){

    int a[]={1,5,2,6,3,0};
    int n = sizeof(a)/sizeof(a[0]);

    cout<<inversion_count(a,0,n-1)<<endl;
 

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }



    return 0;
}//g++ inversion_count.cpp  -o inversion_count  && .\inversion_count 