#include<iostream>
using namespace std;

struct node
{   
    int data;
    node *next=NULL;
    /* data */
};
class queue_ll{
    node* head =NULL ;
    node *tail = NULL;
    public:
    bool empty(){
        if( head == NULL){
            return true;
        }
        return false;
    }
    void push(int x){

        node* temp = new node ;
        temp->data = x;
        if(empty()){
            head = tail =temp;

            return;
        }
        tail->next = temp;
        tail = temp;
    }
    void pop(){
        if(empty()){
            cout<<"Empty queue"<<endl;
            return;
        } 
        node * temp = head;
        head = head->next;
        delete temp;
    }
    void print(){
        if(empty()){
            cout<<"Nothing to print"<<endl;
            return;
        }
        node*temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};

int main(){
    queue_ll q;
    for(int i = 1;i<=5;i++){
        q.push(i);
    }
    q.print();
    q.pop();q.pop();q.pop();q.pop();q.pop();q.pop();
    q.print();
    q.push(0);
    q.print();

    return 0;
}

// g++ queue_ll.cpp -o queue_ll && ./queue_ll  