#include<iostream>
#include<vector>
using namespace std;


// jump game 2 we need minimum no of jumps to reach the last index


// note-> we can also use dp approach for this solution

    // time complexity-> O(n)

    // space complexity -> O(1)

int minJumps(vector<int>&nums){

    int n=nums.size();


    // these two var will contain a range from left to right to get the max we can reach

    int left=0,right=0;


    // count each jumps
    int jumps=0;

    // we will count till right doesnt reach n-1 index

    while(right<n-1){

        // this will contain the max we can reach from that index
        int farthest=0;



        // iterate in the range from left to right
        for(int i=left;i<=right;i++){

        // take the max we can reach
        farthest=max(farthest,i+nums[i]);

        }

        // update the new ranges 


        // left will go one place ahead of right
        left=right+1;

        // right will be set to the farthest we can reach

        right=farthest;

        // increase the jumps cnt;

        jumps++;


    }


    return jumps;



}


int main(){


    vector<int>nums={2,3,1,1,4};


    int minJps=minJumps(nums);

    cout<<"The min jump req to reach the last index: "<<minJps;


}

