#include<iostream>
using namespace std;

void print_order(int n){
    if (n==1){
        cout<<n;
        return ;
    }
    cout<<n<<" "; 
    print_order(n-1);
    
    
}
int main(){
    int n;
    cin>>n;
    print_order(n);


    return 0;
}//>g++ Print_reverse.cpp -o Print_reverse && .\Print_reverse