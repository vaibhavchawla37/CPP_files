#include<iostream>
#include<queue>
//int max_level = -1;
using namespace std;
class node{
    int data = 0;
    node* left =NULL ;
    node* right  =NULL;
    public:

    node * build_bst(node* root,int d){
      //  cout<<root->data;
      1+2;
        if(root == NULL){
            node * temp = new node ;
            temp->data = d; 
            return  temp;
        }
        if(root->data<d){
            root->right = build_bst(root->right,d);
        }
        else 
            root->left = build_bst(root->left,d);
        return root ;
    }
    void bfs(node* root){
        queue<node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            node* ele = q.front();
            if(ele == NULL){
                cout<<endl;
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
            cout<<ele->data<<" ";
            q.pop();
            if(ele->left){
                q.push(ele->left);
            }
            if(ele->right){
                q.push(ele->right);
            }
        }
        }

    }
        void print(node* root){
        if(root == NULL){
            return;
        }
        print(root->left);
        cout<<root->data<<" ";
        print(root->right);
    }
    node* delete_node (node* root ,int k){
        if(root == NULL ){
            return NULL;
        }
        else if(root->data>k){
           root->left =  delete_node(root->left, k);
        }
            
        else if(root->data == k){
 
            if (root->left == NULL){
               node* temp = root->right;
               delete (root);
               return temp;
           }
           else if(root->right ==NULL){
               node* temp = root->left;
               delete (root);
               return temp;
           }
           else{
               node* temp = root->right;
               while(temp->left != NULL){
                   temp=temp->left;
               }
                root->data = temp->data;

                root->right = delete_node(root->right,temp->data);

           }
        }
        else {
            root->right =  delete_node(root->left, k);
        }
    return root;
    }
    

};
int main(){
   // int a[] = {15,10,20,12,5,3,6,11,13,2,4,14,22,1};
   int a[] = {5,3,7,1,6,8};
    int n = sizeof(a)/sizeof(a[0]);
    node t;
    
    node*  root = NULL;
    node * e;
    e = t.build_bst(root,a[0]);
    for(int i = 1 ;i <n; i++){
        t.build_bst(e,a[i]);
    }
    t.print(e);
    t.delete_node(e,5);
    cout<<endl;
    t.print(e);
}

 // g++ binary_tree.cpp -o binary_tree && .\binary_tree