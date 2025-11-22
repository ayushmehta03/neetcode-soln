#include<iostream>
#include<vector>
using namespace std;


bool maxJump(vector<int>&nums){


    int n=nums.size();

    // this will store till now maximum where can we reach
    int mxIndex=0;


    for(int i=0;i<n;i++){


        // if the current i is not possible 
        // it means mxIndex is behind

        if(i>mxIndex) return false;


        // nums[i] tells that how much we can jump from i 
        // so we need to take the max reachable point in linearity

        mxIndex=max(mxIndex,nums[i]+i);


        // if we can reach the last index we need to return true
        if(mxIndex>=nums.size()) return true;

    }

    // if loop completes wtht any error return true
    return true;
}


int main(){

    vector<int>nums={2,3,1,1,4};

    if(maxJump(nums)){
        cout<<"yes it is possible to reach the last index";
    }

    else{
        cout<<"not possible to reach the last index";
    }

}