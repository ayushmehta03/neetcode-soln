#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// time compleixty -> O(n)

// space complexity -> O(n)

// the basic approach of this porblem is to calculate the prefix sum and get the suffix minimum calculate the difference and return the max possible 

// prefix sum -> O to i sum
// suffix minimum i+1 -> n-1 minimum element

int maxScoreSpilit(vector<int>&nums){

    int n=nums.size();

    // have a prefix summ array for storing prefix sum

    vector<long long>prefixSum(n);

    // the first elemnt at 0th position will be same beacuse no elent at the left
    prefixSum[0]=nums[0];

    // starting from i=1; 

    // take the previous + current
    for(int i=1;i<n;i++){
        prefixSum[i]=prefixSum[i-1]+nums[i];
    }


    // now suffixMin min from i+1 to n-1 pos

    vector<int>suffixMin(n);

    // for the last pos val will be same so

    suffixMin[n-1]=nums[n-1];


    // and take the min bewteen the right elemnt and te current one
    for(int i=n-2;i>=0;i--){
        suffixMin[i]=min(nums[i],suffixMin[i+1]);
    }


    // calculate the sum

    long long ans=LLONG_MIN;

    for(int i=0;i<n-1;i++){
        ans=max(ans,prefixSum[i]-suffixMin[i+1]);
    }

    return ans;



}

int main(){
    int n;
    cout<<"Enter the no of elements for the array: ";
    cin>>n;

    vector<int>arr;
    cout<<"Enter the array elemnts: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int ans=maxScoreSpilit(arr);

    cout<<"the max score after spilit will be: "<<ans;




}