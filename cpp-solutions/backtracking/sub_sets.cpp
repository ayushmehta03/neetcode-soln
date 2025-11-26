#include<iostream>
#include<vector>
using namespace std;






// this function will perform the core back tracking and set the subsets to the answer vector

void backtrack(vector<int>&nums,int start,vector<int>&path,vector<vector<int>>&result){

    // verytime we reach here it means path is valid subset

    result.push_back(path);


    // include each elent from the start

    for(int i=start;i<nums.size();i++){

        // pushing the value to the path 
        path.push_back(nums[i]);

        // exploring the further subset

        backtrack(nums,i+1,path,result);

        // discard the last element shich is indeed backtracking
        path.pop_back();


    }
}

 
// function which will return all the possible subset wrt nums array

vector<vector<int>>subSet(vector<int>&nums){

    // create a 2d vector to store subset which we will return

    vector<vector<int>>result;

    // path vector for picking current subset

    vector<int>path;

    // calling the void function backtrack to set all subset to the resulttant vector which we will return


    // start is passed as 0 because we will start from index 0 of array

    backtrack(nums,0,path,result);


    return result;


}


int main(){

    // taking the input for no of elements
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;

    // declaring the array of n size
    vector<int>nums(n);


    // taking the  elements entry for array

    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];


    // calling the subset function and storing the data in ans 2d vector
    vector<vector<int>>ans=subSet(nums);

    // log the answer 
    for(int i=0;i<ans.size();i++){
        for(auto it:ans[i]) cout<<" "<<it;
        cout<<endl;
    }



}