#include<iostream>
#include<queue>
using namespace std;

int main(){
    int freq[26] = {0};
    char ch ;
    cin>>ch;
    queue<char> q;
    while(ch!='.'){
        freq[ch - 'a']++;
        q.push(ch);
        while(!q.empty()){
            int  idx = q.front() - 'a';
            if(freq[idx]>1){
                q.pop();
            }
            else{
                cout<<q.front()<<" ";
                break;
            }
        }
        if(q.empty()){
            cout<<-1<<" ";
        }
        cin>>ch;
    }


    return 0;
}
// 