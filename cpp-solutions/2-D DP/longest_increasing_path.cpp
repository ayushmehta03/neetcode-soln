#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


// so basically this queston ask us to return the longest increasing path from 0 to the last cell

// and the next cell which we are chosing must be greater than the previous one 

// we will use memoization technique of dp to solve this 


vector<vector<int>>dp;

// recurssive function along with memoization

int dfs(int i,int j,vector<vector<int>>&mat){

    // if this state value has been already calculated just return it 

    if(dp[i][j]!=-1) return dp[i][j];


    int n=mat.size();
    int m=mat[0].size();


    // min length =1 (the cell it self )

    int best=1;

    // moving in up direction 

    // for moving up i must be greater than 0 otherwise it will be out of indexing 
    // and the next cell value should be greater than the previous one


    if(i>0 &&mat[i-1][j]>mat[i][j]){
        // add 1 to the next call as this condition satisfied 

        best=max(best,1+dfs(i-1,j,mat));
    }

    // moving in down direction 
    
}

int main(){

    // input data of the matrix 
    vector<vector<int>>matrix={{9,9,4},{6,6,8},{2,1,1}};

    // this is the length intially as 1 

    int lipm=1;

    // grab the size of matrix rows and cols
    int n=matrix.size();

    int m=matrix[0].size();


    // dp 2d array for storing repeating subproblems  intially as -1 at all the cells

    dp.assign(n,vector<int>(m,-1));


    // lets run the loop because the path can start from anywhere
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            // compute the best path starting at i,j 
            lipm=max(lipm,dfs(i,j,matrix));
        }
    }



}