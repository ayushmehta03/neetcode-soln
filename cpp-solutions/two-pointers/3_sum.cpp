#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



// in this problem we need to select three elemnts whose sum is equal to 0 

// and there can be multiple triplte pairs in the input

// and there should not be any duplicate in the triplet



vector<vector<int>>threeSum(vector<int>&nums){
    // take the size of nums
    int n=nums.size();

    // 2d vector ans for storing triplet pair who sume is equal to 0

    vector<vector<int>>ans;

    // sorting the nums vector to make a range small from left and large towards right
    sort(nums.begin(),nums.end());


    for(int i=0;i<n;i++){

        // if the consecutive elemnt are equal will skip this
        if(i>0 &&nums[i]==nums[i-1]) continue;

        int j=i+1;
        int k=n-1;


        // j should be less than k
        while(j<k){

            // calculate the sum with 3 pointers
            int sum=nums[i]+nums[j]+nums[k];

            // sum is ngeative will push j to the right side for greater sum value
            if(sum<0) j++;

            // sum is greater than 0 so will move the k to the left side
            else if(sum>0) k--;

            // if the sum is exactly equal to 0
            else{

                // push the triplet into answwer vector and move j and k 

             ans.push_back({nums[i],nums[j],nums[k]});
             j++;
             k--;
            }


          // avoiding duplicates for j and k too 
          
          while(j<k &&nums[j]==nums[j-1]) j++;
          while(j<k &&nums[k]==nums[k+1]) k--;



    }

 

}
 return ans;
}

int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    // storing the 2d vector into answer vector
    vector<vector<int>>ans=threeSum(nums);



    if(ans.size()==0){
        cout<<"no triplet sum is equal to 0";
    }

    cout<<"The triplet whose sum is equal to :"<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<endl;
        for(auto it:ans[i]){
            cout<<" "<<it;
        }
    }
    return 0;




}