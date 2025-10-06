#include<iostream>
#include<vector>
using namespace std;







int uniqueWays(){

}











// function for calculating the total no of ways  through memoization 

int f(int i,int j,vector<vector<int>>&dp){


// return 1 if they have reached the starting point because we are going from last to top
        if(i==0 &&j==0) return 1;

    // either row or col has reached out of bound then return 0 ways
      if(i<0 ||j<0) return 0;


      // if this part has been visited earlier
      if(dp[i][j]!=-1) return dp[i][j];

        // as we are going from last to first so reverse the down to up and right to left
      int up=f(i-1,j,dp);
      int left=f(i,j-1,dp);

    // tkae the sum of both up and down to get total no of ways
      return dp[i][j]=up+left;



}

int main(){
    // take the input for no of rows
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    // take the input for no of columns
    int m;
    cout<<"Enter the number of columns: ";
    cin>>m;

    // dp vector for storing the overlapping sub problems
    vector<vector<int>>dp(n,vector<int>(m,-1));


    // memoization technique 
    int ans=f(n-1,m-1,dp);
    cout<<"The total no of ways through which we can reach the end point: "<<ans;
    

}