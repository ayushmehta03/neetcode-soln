#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// time and space complexity

    // memoization
    // time-> O(n*amount)
    // space->O(n*amount)+O(n) recurssion


    // tabulation
        // time-> O(n*amount)
    // space->O(n*amount)
    // space can be optimized 









// memoization code
int f(int i,vector<int>&nums,int amount,vector<vector<int>>&dp){

    // basecase
    // if the index is last and suppose the amount is 4 and we have 2 at index 0 so we will do a modulo to get no of coins
    if(i==0){
        // let amount =4 and ith value is 2 4%2==0 yes return 4/2 =2 coins
        if(amount%nums[0]==0) return amount/nums[0];
        // if not possible discard the path by adding infinty
        return 1e9;
    }
    // if the same case has been visited before which is that the vaue will not be the initial value -1

    if(dp[i][amount]!=-1) return dp[i][amount];

    // not take -> nothing will change only index will move
    int nTake=0+f(i-1,nums,amount,dp);
    // intilaize take as infinity
    int take=1e9;

    // if the coin is smaller or equal to the amount then we will take it
    // subtract the amount after taking it and add 1 means we are taking it

    if(nums[i]<=amount) take=1+f(i,nums,amount-nums[i],dp);

    // store the values in dp vector for avoiding overlapping sub problem
    return dp[i][amount]=min(take,nTake);

}


// tabulation  code

int tabulation(vector<int>&coins,int amount){

    int n=coins.size();

    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    

    // base case for the 0th index and eacha nd every amount value 
    for(int amt=0;amt<=amount;amt++){
        if(amt%coins[0]==0) dp[0][amt]=amt/coins[0];
    }

    // starting from index 1 as 0 is already defined in base case
    for(int idx=1;idx<n;idx++){

        // the whole appproach is same as recurssion and memoziation here we are just using loops instead for recurssive calls
        // refer to memoization part for better undersating

        // bottom up approach


        for(int amt=0;amt<=amount;amt++){
            int nTake=dp[idx-1][amt];
            int take=1e9;
            if(coins[idx]<=amt){
                take=1+dp[idx][amt-coins[idx]];
            }
              dp[idx][amt]=min(take,nTake);


        }
    }

    // as this is bottom up approach we will return the last n-1 and amount
   int ans=dp[n-1][amount];

   return (ans>=1e9?-1:ans);



}


int coinChange(vector<int>&nums,int amount){
    // grab the no of coins
    int n=nums.size();

    // for memoization 
    vector<vector<int>>dp(n,vector<int>(amount+1,-1));


    int ans=f(n-1,nums,amount,dp);
    return (ans>=1e9 ?-1:ans);


}



int main(){

    // taking input for number of coins
 int n;
  cout<<"Enter the number of coins: ";
  cin>>n;

    // taking input for coins values
    vector<int>nums(n);
    cout<<"Enter the coins amount: "<<endl;
    for(int i=0;i<n;i++) cin>>nums[i];

    // taking input for amount 

    int amount;
    cout<<"Enter the amount: ";
    cin>>amount;

    // this is the otput of memoization code 
    int minCoins=coinChange(nums,amount);
    cout<<"The min no of coins required to reach amount is: "<<minCoins;

    cout<<endl;
    // output for tabulation code
    int tabuCoins=tabulation(nums,amount);
    cout<<"The min no of coins tabulation approach:  "<<tabuCoins;
    return 0;



   
    

}