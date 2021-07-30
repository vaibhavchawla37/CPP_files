#include<iostream>
using namespace std;

int tower_of_hanoi(int  n ,char src,char help,char dest){
   if(n==0){
       return 0 ;
   }
   int x =tower_of_hanoi(n-1,src,dest,help);
   cout<<"Shift "<<n<<" form "<<src<<" to "<<dest<<endl;
   int y=tower_of_hanoi(n-1,help,src,dest);

   return x+y+1;

}

int main(){
    int n;
    cin>>n;
    cout<<tower_of_hanoi(n,'A','B','C') ;
    

   return 0;

}
//  g++ tower_of_hanoi.cpp -o tower_of_hanoi && .\tower_of_hanoi