#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// this problem is similar to house robber i have explained all details in house robber problem

    // the only thing which is different is that in this problem is that all houses are arranged in circular way 

    // u can not theif from first and last one house 

    // time complexity=O(N)
    // space complexity =O(N)
    // approach -> dynamic programming


    // yes u can optimise this by not using additional datastrcure temp1 and temp2 
    // just call the function once with 1,n-1  and 0,n-2

    




    int findMaxRob(vector<int>&nums){
        // this part is fully explained in house robber 1 problem

        int n=nums.size();
        int prev=nums[0];
        int prev2=0;

        for(int i=1;i<n;i++){
            int take=nums[i];

            if(i>1) take+=prev2;
            int nTake=prev;

            int best=max(take,nTake);
            prev2=prev;
            prev=best;
        }
        return prev;

    }

int rob(vector<int>&nums){

    int n=nums.size();



    // declare first vector for leaving first house mentioned in the question
        vector<int>temp1;

        // declare the second vector skipping the last house
        vector<int>temp2;

        for(int i=0;i<n;i++){
            // skip the first house
            if(i!=0) temp1.push_back(nums[i]);

            // skip the last house
            if(i!=n-1) temp2.push_back(nums[i]);

        }

        // return the max from both of the two vector temp1 and temp2

        return max(findMaxRob(temp1),findMaxRob(temp2));


}


int main(){
    int n;
    cout<<"Enter the number of houses: ";
    cin>>n;


    vector<int>houses(n);
    cout<<"Enter the money amount for each houses: ";
    cout<<endl;
    for(int i=0;i<n;i++) cin>>houses[i];

    int maxAmount=rob(houses);
    cout<<"the max amount of money will be: "<<maxAmount;
    return 0;



}