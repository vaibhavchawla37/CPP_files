#include<iostream>
#include<bitset>
using namespace std;


void n_queens(bitset<100> col,bitset<100> ld,bitset<100> rd,int n,int i,int &ans){
    if(i==n){
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<board[i][j];
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        ans++;
        return ;
    }
 
    for(int j=0;j<n;j++){
        if(!col[j] and !ld[n-1 + i -j] and !rd[i+j]  ){
            col[j]=  ld[n-1 + i -j]=   rd[i+j] = 1/*board[i][j]*/ ;
            n_queens(col,ld,rd,n,i+1,ans);
            col[j]=  ld[n-1 + i -j]=   rd[i+j] = 0/*board[i][j]*/ ;

        }
    }
   
    
}

int main(){
    int board[10][10]={0};
    int n=8;
bitset<100> col,ld,rd;
    int ans=0;
    n_queens(col,ld,rd,n,0,ans);
    cout<<ans;
    return 0;
}

// g++ nqueens_new.cpp -o nqueens_new && .\nqueens_new