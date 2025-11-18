
#include<iostream>
#include<vector>
using namespace std;


// time complexity = O(2^n)

// approach -> backtracking and recurssion

void findCombination(int idx,vector<int>&arr,int target,vector<vector<int>>&ans,vector<int>&ds){


    // base case


    // starting from index 0 if we have covered all elemnts upto n-1 and our value of idx is n we will check for two cases:

    // if the target has became 0 we will add that group to the answer

    // or else simply return

    if(idx==arr.size()){
      if(target==0){
        ans.push_back(ds);
      }  

      return;
    }



    // if our target is greater than the element than we will execute backtracking

    if(arr[idx]<=target){
        ds.push_back(arr[idx]);


        // recurssive call within that index

        findCombination(idx,arr,target-arr[idx],ans,ds);

        ds.pop_back();
    }

    // if that case fails will move ahead by increasing index

    findCombination(idx+1,arr,target,ans,ds);

}


// returing function with the 2d vector containg all the possible combinations whose sum is equal to target
vector<vector<int>>combinationSum(
    vector<int>candidates,int target){


    // temp vector
    vector<int>ds;

    vector<vector<int>>ans;


    findCombination(0,candidates,target,ans,ds);


        return ans;



}



int main(){



    // these all are the input data 

    vector<int>candidates={2,3,6,7};

    int target=7;

    vector<vector<int>>result=combinationSum(candidates,target);

    for(int i=0;i<result.size();i++){
        for(auto it:result[i]){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}