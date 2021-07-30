#include<iostream>
#include <string>
using namespace std;

void subset(char * in,char * out,int i ,int j){
    
    if(in[i]=='\0'){
        out[j]='\0';
        cout<<out<<endl;
        return;
    }

    
    subset(in,out,i+1,j);
    out[j]=in[i];
    subset(in,out,i+1,j+1);
    
    
    

}

int main(){
    char input[] ="abc";
    char output[10];
    subset(input,output,0,0);
}
//  g++ subsequence_subset.cpp -o subsequence_subset && .\subsequence_subset