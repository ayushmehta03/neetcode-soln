#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// approach->hashmaps

// time complexity->O(n)

// space complexity -> O(n)


bool check(vector<int>&nums){
    // declare unordered map for keeping track of frequencies
    unordered_map<int,int>mp;

    for(auto num:nums) mp[num]++;

    // if the freq is greater or equal to 2 it means there exists a duplicate
    for(auto it:mp){
        if(it.second>=2) return true;
    }
    return false;

}

int main(){

    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];

    if(check(nums)) cout<<"Yes there exists a dupliate";
    else cout<<"No duplicate in the array";
    return 0;
}