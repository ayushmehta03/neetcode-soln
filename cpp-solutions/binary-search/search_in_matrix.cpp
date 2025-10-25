#include<iostream>
#include<vector>
using namespace std;

// searching in a 2d matrix with same logic as of the binary search



bool searchMatrix( vector<vector<int>>&matrix,int target){

    // grab the no of rows and column
   int n=matrix.size();
   int m=matrix[0].size();


   // declare both low and high same as the standard binary search problem
   int low=0;
   int high=n*m-1;


   while(low<=high){
    // calculating the mid 

    int mid=low+(high-low)/2;

    // calculating row and col with the help of mid
    int row=mid/m;
    int col=mid%m;


    // 3 checks for samller equal and greater same as binary search


    if(matrix[row][col]==target) return true;
    else if(matrix[row][col]<target) low=mid+1;
    else high=mid-1;

   }
   return false;

}


int main(){

    // input vector and the target
    vector<vector<int>>matrix={
        {1,3,5,7},{10,11,16,20}
    };


    int target=3;

    // logging the output on conditioanl based
    bool ans=searchMatrix(matrix,target);


    if(ans){
        cout<<"Target is present in the matrix ";
    }
    else{
        cout<<"not found in the matrix";
    }

}