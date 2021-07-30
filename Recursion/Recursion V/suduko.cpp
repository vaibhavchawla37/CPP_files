#include<iostream>
#include<algorithm>
#include<math.h>
int c=0;
using namespace std;
bool can_placed(int  ip[][9],int i,int j,int number,int n){
    for(int k = 0 ;  k < n ; k++){
        if( ip[k][j] == number or ip[i][k] == number){
            return false;
        }
    }
    int  rn = sqrt(n);
    int x = (i/rn) * rn ;
    int y = (j/rn) * rn;

    for(int k = x; k < x + rn ; k++ ){
        for(int l = y; l < y + rn; l++){
            if(ip[k][l] == number ){
                return false ; 
            }
        }
    }
    return true;

}


bool  suduko(int  ip[][9],int i,int j,int n){
    if(i==n){
        for(int i = 0 ;i<n ;i++){
        for(int j=0;j<n;j++){
                cout<<ip[i][j]<<" ";
        }
        cout<<endl;
    }
        cout<<endl;
        c++;
        return true;;
    }
    if(j==n){
        return suduko(ip,i+1,0,n);
    }
    if(ip[i][j]!=0){
        return suduko(ip,i,j+1,n);
    }

    for(int number = 1;number<=n;number++){
        if(can_placed(ip,i,j,number,n)){
            ip[i][j] = number;
            bool solved =  suduko(ip,i,j+1,n);
            if(solved==true){
                return true;
            }
             
        }
      
    }
   ip [i][j] = 0;
    return false ; 
    
}
int main(){
    int in[9][9] ={
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 0, 0, 0, 0, 3, 0, 0}
    };
    suduko(in,0,0,9) ;
    int n=4;
    
cout<<c;
}

// g++ suduko.cpp -o suduko && .\suduko