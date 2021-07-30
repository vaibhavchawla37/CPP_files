#include<iostream>
using namespace std;


bool  rat_maze(char  maze[][10] ,int  sol[][10] ,int i ,int j,int m,int n){
    if(i==m and j==n){
        sol[i][j]=1;
        for(int i=0;i<=m;i++){
            for( int j=0;j<=n;j++){
                cout<<sol[i][j];
            }
            cout<<endl; 
        }
        cout<<endl;
        return true;
    }
    

    if(i>m || j>n)  return false;
    if(maze[i][j]=='X') return false;
    
    
    sol[i][j]=1;
    bool right_path = rat_maze(maze,sol,i,j+1,m,n);
    bool down_path = rat_maze(maze,sol,i+1,j,m,n);
    sol[i][j] = 0;

    if(right_path || down_path){
        return true;
    }
    return false;

}
int main(){
    char maze [10][10]= {
                            "0000",
                            "00X0",
                            "000X",
                            "0X00"
    };
   int sol[10][10] = {0};
   rat_maze(maze,sol,0,0,3,3);
}

// g++ rat_maze.cpp -o rat_maze && .\rat_maze