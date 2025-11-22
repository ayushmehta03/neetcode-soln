#include<iostream>
#include<vector>
using namespace std;

// using kadane algorithm solve max sub array sum problem


// time complexity -> O(n)
// SPACE COMPLEXITY -> O(1)


int maxSum(vector<int>&nums){


    // get the size of array
    int n=nums.size();


    // one var for storing linear addition and other for max value

    int ans=0;

    int maxS=INT_MIN;


    for(int i=0;i<n;i++){

        // adding the sum to the ans var
        ans+=nums[i];


        // if ans goes beyond maxS var change the value

        if(maxS<ans) maxS=ans;

        // if the value goes beyond 0 start with 0



        if(ans<0) ans=0;
    }

    return maxS;



}


int main(){

    vector<int>nums={-2,1,-3,4,-1,2,1,-5,4};


    int mxSum=maxSum(nums);

    cout<<"the max sum can be obtained from sub array: "<<mxSum;





}