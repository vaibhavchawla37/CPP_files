#include<iostream>
using namespace std;


class queue{
    int cs;
    int front ;
    int rear ;
    int ms ;
    int *a;
    public:
    queue(int ds =5){
        a = new int(ds);
        cs = 0 ;
        ms =ds;
        front = 0;
        rear = ds -1;
    }
    bool empty(){
        if (cs==0) return true;
        return false;
    }
    bool full(){
        return cs==ms;
    }
    void push(int x){
        if (full()){
            cout<< "Full queue";
            return;
        }
        
        rear = (rear + 1) % ms; 
        a[rear] = x;
        cs++;
    }
    void pop(){
        if (!empty()){
            front = (front +1 ) % ms;
            cs--;
        }
    }
    void print(){
        if (empty()){
            cout<<"Empty queue"<<endl;
            return;
        } 
        int f = front ; 
        int r = rear ;
        while(f!=r){
            cout<<a[f]<<" ";
            f=(f+1)%ms;
        }
        cout<<a[f]<<" ";
        cout<<endl;
    }

    ~queue(){
        if(a!=NULL){
            delete [] a;
            a=NULL;
        }
    }


    
};


int main (){
    int n = 5;
        queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.print();
    q.pop();
    q.pop();
    q.print();
   
    q.push(7);
    q.print();


    return 0;
}

// g++ queue_vec.cpp -o queue_vec && .\ queue_vec