#include<iostream>
#include<algorithm>
using namespace std;


void  permute(char * ip,int i=0){
    if(ip[i]=='\0'){
        cout<<ip<<endl;
        return;
    }

    for(int j=i;ip[j]!='\0';j++){
        swap(ip[i],ip[j]);
        permute(ip,i+1);
        swap(ip[i],ip[j]);
    }

}
int main(){
    char in[] ="133";
    permute(in) ;
}

// g++ permute.cpp -o permute && .\permute