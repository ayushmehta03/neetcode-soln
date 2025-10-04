#include<iostream>
#include<vector>
using namespace std;


// product of array except itself

    // approach -> prefix sum
    // time complexity-> O(N)
    // space complexity -> O(1)

vector<int>product(vector<int>&nums){
    int n=nums.size();
    // answer vector for stroing prodyuct from both left and right side
    vector<int>ans(n);

    // prefix for the left part intially as 1 
    int prefix=1;

    for(int i=0;i<n;i++){
        // storing the left part in the answer vector
        ans[i]=prefix;
        // prefi changing wrt to the left part
        prefix*=nums[i];
    }
    // postfix for right part initally as 1 
    int postfix=1;

    for(int i=n-1;i>=0;i--){
        // postfix*prefix in the answer vector
        ans[i]*=postfix;
        // postfix changin wrt to the right part
        postfix*=nums[i];
    }
    // return the answer vector
    return ans;


}



int main(){

    // declaring the size for the array
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;

    // intiliaze vector with n size and take the input
    vector<int>nums(n);
    cout<<"Enter the elements fo the array: ";
    for(int i=0;i<n;i++) cin>>nums[i];


    // store the result of function product in ans vector
    vector<int>ans=product(nums);

    // print the vector ans
    cout<<"The resulatant array with product except itself:";
    cout<<endl;
    for(auto it:ans) cout<<" "<<it;

    

}