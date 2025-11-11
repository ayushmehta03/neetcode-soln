/*
    
Time complexity : O(m*n) where m is the number of rows and n is the number of columns in the grid.
Space complexity : O(m*n) for the 2D array used to store the number of unique paths to each cell.


Dry Run : m = 2 , n = 3

    sol array initialization:
    0 0 0
    0 0 0

    after setting rows and column 
    1 1 1
    1 0 0 


    now for i =1 and j =1

    sol[1][1] = sol[1][0] + sol[0][1] = 1+1 = 2

    thus 
    1 1 1
    1 2 0

    for i =1 and j =2

    sol[1][2] = sol[1][1] + sol[0][2] = 2+1 = 3 
    thus
    1 1 1
    1 2 3

    thus the output will be 3



 */



class Solution {
    public int uniquePaths(int m, int n) {

        //creating a 2d array to store the number of unique paths to each cell
        int[][] sol = new int[m][n];



        //Number of ways to reach any cell in first row is 1
        for(int i =0;i<m;i++){
            sol[i][0]=1;
        }


        //Number of ways to reach any cell in first column is 1
        for(int i =0;i<n;i++){
            sol[0][i]=1;
        }


        //filling the dp array
        //Number of ways to reach cell (i,j) is the sum of ways to reach cell (i-1,j) and cell (i,j-1)
        for(int i =1;i<m;i++){
            for(int j= 1;j<n;j++){
                sol[i][j]= sol[i-1][j]+sol[i][j-1];
            }
        }


        return sol[m-1][n-1];

    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int m = 3;
        int n = 7;
        int result = solution.uniquePaths(m, n);
        System.out.println("Number of unique paths from top-left to bottom-right in a " + m + "x" + n + " grid: " + result);
    }
}