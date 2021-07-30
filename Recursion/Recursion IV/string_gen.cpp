#include<iostream>
using namespace std;


void  string_gen(char * ip,char * op,int i ,int j){
    if(ip[i]=='\0'){
        op[j]='\0';   
        cout<<op<<endl;
        return;
    }
    if(ip[i]!='0'){
    int digit =  ip[i] - '0' ;
    op[j] = char(digit + 'A' - 1 );

    string_gen(ip,op,i+1,j+1);

    if(ip[i+1]!='\0'){
        int sd =  ip[i+1] - '0' ;
        int n_digit = digit*10 + sd;
        if(n_digit<=26){
            op[j] = char(n_digit+ 'A'  -1);
            string_gen(ip,op,i+2,j+1);
        }

    }

    }
    return;
}
int main(){
    char in []="123";
    char out[100];

    string_gen(in,out,0,0);
//    cout<<sizeof(out)/sizeof(out[0]);
// cout<<char('1' + 'A'  - '0')<<endl;
// cout<<char(71)<<endl<<in[0] - '0';
    return 0;
}

// g++ string_gen.cpp -o string_gen && .\string_gen