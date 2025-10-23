#include<iostream>
#include<vector>
using namespace std;

// input is sorted in the vector for this problem



// function for twoSum
vector<int> twoSum(vector<int>&nums,int target){

    // take two pinters left and right one at the begging and other at the last
 int left=0;
 int right=nums.size()-1;


    // run the loop until both of them meets
    while(left<=right){

        // calcukate the sum from both the pointers
        int sum=nums[left]+nums[right];

        // if it is equal to the target we need to return the index but in the guven problem the index is starting from 1 so will return +1 WITH the matching pointers
        if(sum==target) return {left+1,right+1};

        else if(sum<target) left++;

        else right--;
 }

    return {-1,-1};

}

int main(){

    vector<int>nums={2,7,11,15};
    int target=9;


    vector<int>ans=twoSum(nums,target);


    if(ans[0]==-1 &&ans[1]==-1){
        cout<<"no elents can make the sum to the target";
    }
    else{

    cout<<"The matching indexes which makes target sum are : ";
    cout<<ans[0]<<" "<<ans[1];
    }
    return 0;





}