#include<iostream>
using namespace std;
char keypad[][10]={"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void  dial_pad(char * ip,char * op,int i ,int j){
    if(ip[i]=='\0'){
        op[j]='\0';
        cout<<op<<endl;
        return ;
    }
    int idx = ip[i]-'0';
    for (int k=0 ; keypad[idx][k]!='\0' ; k++){
        op[j] = keypad[idx][k];
        dial_pad(ip,op,i+1,j+1);
    }
    return;

}
int main(){
    char in []="666";
    char out[100];

    dial_pad(in,out,0,0);
//    cout<<sizeof(out)/sizeof(out[0]);
    return 0;
}

// g++ dial_pad.cpp -o dial_pad && .\dial_pad