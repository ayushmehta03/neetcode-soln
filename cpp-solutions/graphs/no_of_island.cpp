#include<iostream>
#include<vector>
using namespace std;



// using recurssive dfs approach to solve this problem

void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&gird){
    // once it is called mark the repsective row and col as visited 
    vis[row][col]=1;
}


int numIsland(vector<vector<char>>&grid){

    // take the size of row and col
    int n=grid.size();
    int m=grid[0].size();


    // take a 2d vector for storing the row and col visiting action
    vector<vector<int>>visited(n,vector<int>(m,0));

    // take a count variable for stroing no of islands
    int cnt=0;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            // if this part is not viisted and the position we are standing on is island which is 1 
            if(!visited[i][j]&& grid[i][j]=='1'){
                // increase the no of count
                cnt++;
                // call the function dfs 
                dfs(i,j,visited,grid);
            }
        }
    }
}


int main(){


    // this is the grid we need to counts the no of island 
    // ans island is defined if the stsnding part is '1' and all its surrounding up down ledt and right are '0'
    vector<vector<char>>grid={
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // logging the result

    int ans=numIsland(grid);
    if(ans>0){
        cout<<"The number of island in the gird will be : "<<ans;
    }
    else cout<<"No island can be formed ";
    return 0;


}