#include<iostream>
using namespace std;

int  knapsack(int *wt ,int *pro,int n,int c){
    if(n==0 || c== 0 )  return 0;
    int inc = 0;
    int exc = 0;
    if(c>=wt[n-1]){
        inc = pro[n-1] + knapsack(wt,pro,n-1,c-wt[n-1]);
    }
    exc = knapsack(wt,pro,n-1,c);
    return max(inc,exc);
}
int main(){
    int wt[] ={1,2,3,5};
    int pro[]={50,60,30,60};
    int c = 7;
    int n = sizeof(wt)/sizeof(wt[0]);

    cout<<knapsack(wt,pro,n,c);
    return 0;
}

// g++ knapsack.cpp -o knapsack && .\knapsack