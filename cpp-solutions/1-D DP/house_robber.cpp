// house robber problem
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// approach-> dynamic programming
// time complexity->O(n)
// space complexity -> O(1)

int rob(vector<int>&nums){

    // this variable is for i-1 means the just before the current 
    int prev=nums[0];

    // this  variable is for i-2  means the before the previous one
    int prev2=0;


    for(int i=1;i<nums.size();i++){

        // now we have two options either we can rob the current one leave it 
        // we will be executing both cases in terms of take and nTake

        // if we take 
        int take=nums[i];
        // if the i value is greater than 1 than only we can take previous 2 otherwise it will be out of bound
        if(i>1) take+=prev2;

        // if we are not taking which means we have taken the previous one so nTake=previous
        int nTake=prev;

        // take the maximum from both of the cases
        int best=max(take,nTake);

        // now change the value of previous and previous 2

        // prev 2 will become the last previous 
            prev2=prev;


        // so previous will become what we have taken just before that is
          prev=best;




    }
    // return the previous
    return prev;

}

int main(){

    // taking input for number of houses
    int n;
    cout<<"Enter the no of houses: ";
    cin>>n;

    // declaring vector for carrying money value for each house
    vector<int>nums(n);

    // taking input of money value
    cout<<"Enter the money amount for each houses: ";
    for(int i=0;i<n;i++) cin>>nums[i];

    // calling the rob function to get the max money that can be robbed
    int robbedMoney=rob(nums);

    cout<<"The mamximum amount of money that can be robbed is: "<<robbedMoney;
    return 0;

}

