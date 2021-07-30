#include<iostream>
#include<algorithm>
#include<set>
#include<cstring>
using namespace std;


void  permute_unique(char * ip,int i,set<string> &s){
    if(ip[i]=='\0'){
        string t(ip);
        s.insert(t);
        return;
        }

    for(int j=i;ip[j]!='\0';j++){
        swap(ip[i],ip[j]);
        permute_unique(ip,i+1,s);
        swap(ip[i],ip[j]);
    }

}
int main(){
    char in[] ="133";
    set<string> s;
    permute_unique(in,0,s);
    for(string x : s){
        cout<<x<<" ";
    }
}

// g++ permute_unique.cpp -o permute_unique && .\permute_unique