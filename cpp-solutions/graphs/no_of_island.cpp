#include<iostream>
#include<vector>
using namespace std;


// time complexity-> O(nxm)
// space complexity-> O(n*m)



// func for checking all the neccesary conidtions 
bool check(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&visited){

    int n=grid.size();
    int m=grid[0].size();

    // it will cehck for row should be either equal or greater than 0 and less than its value n same for column 
    // and it should not be visited and we need to take only the landpart not the water 

    return (row>=0&&row<n&&col>=0&&col<m&&!visited[row][col]&&grid[row][col]=='1');

}

// using recurssive dfs approach to solve this problem

void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&grid){
    // once it is called mark the repsective row and col as visited 
    vis[row][col]=1;

    // take the delta row and column for checking all the boundaries for row and column up down left and right 

    // if the row goes up it will be -1 right no change down +1 and left no change
    int delRow[4]={-1,0,1,0};

    // if the col goes up no change right +1 down no change and left -1
    int delCol[4]={0,1,0,-1};

    // use a loop run it for 4 times for checking all conditions
    for(int i=0;i<4;i++){
     int nRow=row+delRow[i];
     int nCol=delCol[i]+col;
     if(check(nRow,nCol,grid,vis)){
        // if it atisfies the condition call the dfs again
        dfs(nRow,nCol,vis,grid);
     }

    }
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
    return cnt;
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