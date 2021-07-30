#include<iostream>
#include<queue>
//int max_level = -1;
using namespace std;

struct Pair{
    int height ;
    int diameter ; 
};
struct BPair{
    int height ;
    bool bal ; 
};
struct Sum_pair{
    int max_sum = 0 ;
    int branch_sum = 0;
};
class node {
    int data ;
  
    node* left =NULL;
    node* right=NULL;
    

    public:    
    node* build_tree(){
        int d ;
        cin>>d;
        if(d==-1 ){
            
            return NULL;
        }
        node * root =  new node;
        root->data = d;
        root->left = build_tree();
        root -> right= build_tree();
        return root;
    }
    void print(node* root){
        if(root == NULL){
            return;
        }
        cout<<root->data<<" ";
        print(root->left);
        print(root->right);
    }
    int count_nodes(node* root){
        if(root == NULL){
            return 0;
        }
        int c1 = count_nodes(root->left);
        int c2 = count_nodes(root->right);
        return 1 + c1 + c2;

    }
    int height(node* root){
        if(root == NULL ){
            return 0;
        }
        int h1 = height(root->left);
        int h2 =  height(root->right);
        return max(h1,h2) + 1;
    }
    void kth_level(node* root ,int k){
        if(root == NULL){
            return;
        }
        if(k==0){
            cout<< root->data<<" ";
            return;
        }
        kth_level(root->left,k-1);
        kth_level(root->right,k-1);
        return;
    }
    void level_all(node* root){
        int H = height(root);
        for(int i = 0; i<H;i++  ){
            kth_level(root,i);
            cout<<endl;
        }
    }
    void bfs_queue(node * root){
        queue<node *> Q;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            node* element = Q.front();
            if(element==NULL){
                cout<<endl;
                Q.pop();
                if(!Q.empty()){
                    Q.push(NULL);
                }
            }

            else{
            cout<<element->data<<" ";
            Q.pop();
            if(element->left){
                Q.push(element->left);
            }
            if(element->right){
                Q.push(element->right);
            }
        }
        }
    }
    int diameter(node *root){
        if(root ==  NULL){
            return 0;
        }
        int h1 = height(root->left);
        int h2 = height(root->right);
        int op1 = h1 + h2;
        int op2 = diameter(root->left);
        int op3 = diameter(root->right);
        return max(op1,max(op2,op3));
    }
    Pair fast_diameter(node * root){
        Pair p ;
        if(root == NULL){
            p.height = 0;
            p.diameter= 0;
            return p;
        }
        Pair left  =fast_diameter(root->left); 
        Pair right =fast_diameter(root->right);

        p.height = max(left.height,right.height) + 1;
        p.diameter = max( left.height+right.height ,max(left.diameter,right.diameter));
        return p;
    }
    int sum_of_nodes(node* root){
        if(root == NULL){
            return 0;
        }
        if(root->left==NULL && root->right== NULL){
            return root->data;
        }
       
        int rs = sum_of_nodes(root->right);
        int ls = sum_of_nodes(root->left);

        // int temp = root->data; 
        root->data = ls+rs; 
        return root->data ;
    }
    BPair balanced_height(node* root){
        BPair p;
        if(root == NULL){
            p.height = 0 ;
            p.bal == true;
            return p;
        }
        BPair left = balanced_height(root->left);
        BPair right = balanced_height(root->right);

        p.height = max(left.height,right.height) + 1;
        if(abs(left.height-right.height)<=1 and left.bal and right.bal){
            p.bal = true;
        }
        else
            p.bal = false;
        
        return p;
    }
    node * build_balanced(int * a , int s,int e){
        if(s>e){
            return NULL;
        }
        int m = (s+e)/2;
        node* root= new node;
        root->data = a[m];
        root->left = build_balanced(a,s,m-1);
        root->right = build_balanced(a,m+1,e);
        return root;
    }
    node* build_pre_in(int * pre,int * in,int s,int e){
        static int i = 0;
        if(s>e){
            return NULL;
        }
        int idx = -1;
        node * root = new node ;
        root->data = pre[i];
        for(int j =s;j<=e;j++){
            if(pre[i]==in[j]){
                idx = j;
                break;
            }
        }
        i++;
        root->left = build_pre_in(pre,in,s,idx-1);
        root->right = build_pre_in(pre,in,idx+1,e);
        return root;
    }
    void right_view(node* root,int level,int &max_level){
        // static int max_level = -1;
        if(root == NULL ){
            return ;
        }
        if(max_level<level){
            cout<<root->data<<" ";
            max_level = level ;
        }
        right_view(root->right,level+1,max_level);
        right_view(root->left,level +1 , max_level);
    }
    int distance_from_kth_node(node* root,node* target,int k){
        if(root == NULL){
            return  -1;
        }
        if(root == target){
            kth_level(root,k);
            return 0;
        }

        int DL = distance_from_kth_node(root->left,target,k); 
        if(DL!= -1){
            if(DL+1 == k){
                cout<<root->data<<" ";
            }
            else{
                kth_level(root->right,k-DL-2);
            }
            return 1+DL;
        }
        int DR = distance_from_kth_node(root->right,target,k); 
        if(DR != -1){
            if(DR+1 == k){
                cout<<root->data<<" ";
            }
            else{
                kth_level(root->left,k-2-DR);
            }
            return DR+1;
        }
        return -1;
    }
    void print_data(node* root){
        cout<<root->data<<endl;
    }
    node * lca(node *root,int a,int b){
        if(root == NULL) return NULL;
        
        if(root->data == a or root->data == b){
            return root;
        }

        node * lans = lca(root->left,a,b);
        node * rans = lca(root->right,a,b);

        if(lans and rans){
            return root;
        }
        if(rans) return rans;
        return lans;
    }
    Sum_pair node_path_sum(node* root){
        Sum_pair p;
        if(root == NULL) return p;
        
        Sum_pair left = node_path_sum(root->left);
        Sum_pair right = node_path_sum(root->right);
        
        int op1 = root->data;
        int op2 = left.branch_sum + root->data;
        int op3 = right.branch_sum + root->data;
        int op4 = left.branch_sum + right.branch_sum  + root->data;

        int cur_max_sum_node = max(op1,max(op2,max(op3,op4)));
        
        p.branch_sum = max(left.branch_sum,max(right.branch_sum,0)) + root->data;
        p.max_sum = max(left.max_sum,max(right.max_sum,cur_max_sum_node));

        return p;
    }
};

int main(){
    // int a[] = {3,4,-1,6,-1,-1,5,-1,-1,-1,-1};
    // int n = sizeof(a)/sizeof(a[0]);
    
    //node t;
    //node* root=t.build_tree();
    //t.print(root);
   // cout<<endl;
   // cout<<"height: "<<t.height(root)<<endl;
   // t.level_all(root);
    //t.bfs_queue(root);
    //cout<<t.count_nodes(root);
    //cout<<t.diameter(root);
    //t.kth_level(root,1);
    //Pair p= t.fast_diameter(root);
    // cout<<"Height:   "<<p.height<<endl;
    // cout<<"Diameter: "<<p.diameter<<endl;
    // cout<<t.sum_of_nodes(root)<<endl;
    // t.bfs_queue(root);
    //BPair p= t.balanced_height(root);
    //cout<<boolalpha;
    //cout<<p.bal;
    //node t1;
    //int a[] = {1,2,3,4,5,6,7};
    //int n = sizeof(a)/sizeof(a[0]);
    //node* root = t1.build_balanced(a,0,n-1);

    // int in[] = {3,2,8,4,1,6,7,5};
    // int pre[] = {1,2,3,4,8,5,6,7};
    // int n = sizeof(in)/sizeof(in[0]);
    
    // node t2;
    // node * root = t2.build_pre_in(pre,in,0,n-1);
    // t2.bfs_queue(root);
    // cout<<t2.height(root);

    node t ;
    node* root = t.build_tree();
    t.bfs_queue(root);
   // int max_level = -1;
    //t.right_view(root,0,max_level);
    // t.distance_from_kth_node(root,root->left->left,1);
    // cout<<endl;
    // t.kth_level(root->left->left,3);
    // t.print_data(t.lca(root,6,5));
    Sum_pair p = t.node_path_sum(root);
    cout<<p.branch_sum<<endl<<p.max_sum;

    
    

}
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1  14 13 -1 -1 -1
// 1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1

// g++ tree_rec.cpp -o tree_rec && .\tree_rec