#include<iostream>
#include<vector>
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


Node *insert(Node*root,int val){
    if(root==NULL) return new Node(val);

    if(val<root->data) root->left= insert(root->left,val);

    else{
        root->right=insert(root->right,val);
    }
    return root;
}

void inOrder(Node*root,int k,int res){
    if(root==NULL) return;
    inOrder(root->left,k,res);
    if(--k==0) res=root->data;
    inOrder(root->right,k,res);


}


int kthSmallest(Node*root,int k){
    int res=-1;
    inOrder(root,k,res);
    return res;


}


int main(){

    Node*root=NULL;
    vector<int>values={3,9,20,5,15,7};
    for(int val:values){
     root= insert(root,val);
    }
    // k value to get the smallest number
    int k=2;

    int ans=kthSmallest(root,k);
    cout<<ans;

}