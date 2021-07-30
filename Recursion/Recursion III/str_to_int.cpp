#include<iostream>
#include<cstring>
#include<typeinfo>
#include<algorithm>
using namespace std;

char words[][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int str_to_int (string s){
    if(s.length()==0)
        return 0;

    int n = s.length();
    int dig = s[n-1] -'0';
    s.pop_back();

    return str_to_int(s)*10 +dig;

   
}

int main(){
    string s;
    cin>>s;

   // cout<<s;
   int n=str_to_int(s);;
   cout<<n;
 //  cout << typeid(n).name() << endl;
    return 0;
}//g++ str_to_int.cpp  -o str_to_int  && .\str_to_int 