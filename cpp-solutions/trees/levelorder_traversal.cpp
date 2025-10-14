#include<iostream>
#include<vector>
#include<queue>
using namespace std;




// time complexity-> O(N)

// space complexity -> O(N)









// constructing the binary search tree 

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
    }
    return root;
}



// level order traversal in a binary search tree 

vector<vector<int>>levelOrder(Node*root){

    // declaring 2d vector for returning answer
    vector<vector<int>>ans;

    // return empty vector if root is null
    if(root==NULL) return ans;

    // declare a queue of same type as struct so that it holds value left and right
    queue<Node*>q;

    // push the root at first
    q.push(root);

    // run untill the q becomes empty

    while(!q.empty()){

    // grab the size of queue
     int size=q.size();

     // declare vector so that it stores value of each value
     vector<int>level;

    // run the operation fwrt to the size
     for(int i=0;i<size;i++){
     Node*node=q.front();

     // pop the value from the top
     q.pop();

     // check for both left and right if it is not null push to the queue theses are the other levels
     if(node->left!=NULL) q.push(node->left);
     if(node->right!=NULL) q.push(node->right);

     // push the value to the leevel vector
     level.push_back(node->data);

     }
     // once the loop is completed for each level push it to the 2d vector ans 

     ans.push_back(level);

    }

    return ans;


}

int main(){
    Node*root=NULL;
    vector<int>values={3,9,20,15,7};

 for(int val:values){
    root=insert(root,val);
 }

 vector<vector<int>>ans=levelOrder(root);
 
 for(int i=0;i<ans.size();i++){
    for(auto it: ans[i]){
     cout << it << " ";
    }
    cout<<endl;
 }



}
