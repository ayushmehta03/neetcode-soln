#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// top k frequncy elemnts using bucket sort 

// time complexity->O(n)

// space complexity->O(n) for bucket


vector<int>bucketSort(vector<int>&nums, int k){
    // unordered map for storing frequency
    unordered_map<int,int>mp;

    for(auto it:nums) mp[it]++;

    int n=nums.size();

    // creating bucket with size n+1
    vector<vector<int>>bucket(n+1);
    
    // if one has 3 frequencies the bucket[3]->{1}

    for(auto &it:mp){
        bucket[it.second].push_back(it.first);
    }
    // answer vector for storing most frequent
    vector<int>ans;

    for(int freq=n;freq>=1 &&ans.size()<k;freq--){
        for(auto num:bucket[freq]){
            // store the top frequent first
            ans.push_back(num);

            // if the no of elements psuehd to answer are equal to k break and return
            if(ans.size()==k) break;
        }
    }
    return ans;

}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>nums(n);

    cout<<"Enter the array elements: ";
    for(int i=0;i<n;i++) cin>>nums[i];

        int k;
    cout<<"Enter k value: ";
    cin>>k;

    vector<int>ans=bucketSort(nums,k);
    cout<<"The k most frequent elements are: ";

    for(auto it:ans) cout<<" "<<it;


}