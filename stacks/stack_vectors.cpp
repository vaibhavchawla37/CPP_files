#include<iostream>
#include<vector>
using namespace std;
template<typename T>
class Stack{
    private :

        vector<T> v;
    public:
    void push(T x){
        v.push_back(x) ;
    }
    bool empty(){
        if(v.size()==0) return true;
    }
    void pop(){
        if(empty()){
            cout<<"empty"<<endl;
            return;
        }
        //cout<<"popped: "<<v[v.size()-1]<<endl;;
        v.pop_back();
    }
    T top(){
        return v[v.size() -1];
    }
    void print(){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    int size(){
        return v.size();
    }
    
};

template<typename U>
void transfer(Stack<U> &src,Stack<U> &dst,int n){
    for(int i = 0 ; i < n ; i++ ){
        int x = src.top();
        src.pop();
        dst.push(x);
    }
}
template<typename U>
void reverse(Stack<U> &s1){
    Stack<U> s2;
    int n=s1.size();
    for(int i=0;i<n;i++){
        int x = s1.top();
        s1.pop();
        transfer(s1,s2,n-i-1);
        s1.push(x);
        transfer(s2,s1,n-i-1);
    }
}
template<typename U>
void insert_at_bottom(Stack<U> &s,int x){
    if(s.empty()){
        s.push(x);
        return ;
    }
    int d = s.top(); s.pop();
    insert_at_bottom(s,x);
    s.push(d); 
}

template<typename U>
void rev_rec(Stack<U> &s){
    if(s.empty()) return;

    int x = s.top();s.pop();
    rev_rec(s);
    insert_at_bottom(s,x);
}


int main(){
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.print();
    // reverse(s);
    rev_rec(s);
    s.print();

    Stack<char> c;
    c.push('a');
    c.push('b');
    c.push('c');
    c.push('d');
    c.print();
    //reverse(c);
    rev_rec(s);
    c.print();
    return 0;
}

// g++ stack_vectors.cpp -o stack_vectors && .\stack_vectors