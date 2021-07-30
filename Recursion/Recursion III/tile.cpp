#include<iostream>
using namespace std;

int tile(int n){
    if(n<=3){
        return 1;
    }
    else return tile(n-1)+tile(n-4);
}

int main(){
   int n=4;
    cout<<tile(n);

   return 0;

}