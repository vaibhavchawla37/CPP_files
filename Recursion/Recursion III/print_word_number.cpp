#include<iostream>
#include<algorithm>
using namespace std;

char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void print_word (int n){
    
    if(n==0) return ;  
    print_word(n/10);
    cout<<words[n%10]<<" ";
}

int main(){
    int n;
    cin>>n;
    print_word(n);
    return 0;
}//g++ print_word_number.cpp  -o print_word_number  && .\print_word_number 