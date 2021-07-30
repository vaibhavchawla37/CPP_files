#include<iostream>
#include<stack>
using namespace std;

bool valid_pair(char p1,char p2){
    if(p1 == '(' and p2 == ')') return true;
    if(p1 == '[' and p2 == ']') return true;
    if(p1 == '{' and p2 == '}') return true;

    return false;
}


bool isValid(char* str){
    stack<char> s;
    for(int i=0 ;str[i]!='\0';i++){
        if( str[i] == '[' or str[i] == '{' or str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == '}' || str[i] == ']'){
            if(s.empty() or !valid_pair(s.top(),str[i])){
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}

int main(){
    
    char s[100] = "{a+b + [(2*3)]";

    cout<<boolalpha;
    cout<<isValid(s);
    return 0;
}

// g++ brackets.cpp -o brackets && .\brackets