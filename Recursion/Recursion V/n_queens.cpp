#include<iostream>
using namespace std;

bool can_placed(int board[][10],int n,int i,int j){
    for(int k=i;k>=0;k--){
        if(board[k][j]==1){
            return false;
        }
    }
    int x=i;
    int y=j;
    while(x>=0 and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;y--;
    }

    x=i;
    y=j;
    while(x>=0 and y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;y++;  
    }

    return true;
    
}
int n_queens(int board[][10],int n,int i  ){
    if(i==n){
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++)
        //         cout<<board[i][j]<<" ";
        //     cout<<endl;
        // }
        // cout<<endl;
        return 1;
    }
    int cnt = 0;
    for(int k=0; k<n;k++){
        if(can_placed(board,n,i,k)){
            board[i][k] = 1;
            cnt += n_queens(board,n,i+1);
            board[i][k] = 0 ;
        }
    }
    return cnt;
    
}

int main(){
    int n;
    cin >>n;
    int board [10][10]={0};
    cout<<n_queens(board,n,0);

    return 0;
}

// g++ n_queens.cpp -o n_queens && .\n_queens