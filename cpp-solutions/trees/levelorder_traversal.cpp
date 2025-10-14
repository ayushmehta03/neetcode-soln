#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
int data;
Node*left;
Node*right;

Node(int val){
    data=val;
    left=right=NULL;
}
};

Node*insert(Node*root,int val){
    if(root==NULL) return new Node(val);
    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
        return root;
    }
}


int main(){
    Node*root=NULL;
    vector<int>values={3,9,20,NULL,NULL,15,7};

 for(int val:values){
    root=insert(root,val);
 }
}
