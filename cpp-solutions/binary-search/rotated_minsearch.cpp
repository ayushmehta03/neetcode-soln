#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMin(vector<int>&nums){

    // get the no of elements
    int n=nums.size();

    // intially start with max value cause we need the minimu value
    int ans=INT_MAX;


    // take two pointers low and high normal bs approach

    int low=0;
    int high=n-1;


    // run until low and high both met and the earch is completed 
    while(low<=high){

        // take the mid position 
        int mid=(low+high)/2;

        // if the first element is smaller than the last one it means there is no rotation so the array is already sorted 
        if(nums[low]<=nums[high]){
            ans=min(ans,nums[low]);
            break;
        }

        // if the low is smaller than the mid it means the left half is sorted so we will search in the right part low=mid+1

        if(nums[low]<=nums[mid]){
            ans=min(ans,nums[low]);
            low=mid+1;
        }
        //  Left half is NOT sorted → then right half must be sorted
            // So rotation/minimum is in the left half (before mid)
            // nums[mid] is a candidate for minimum



        else{
            high=mid-1;
            ans=min(ans,nums[mid]);
        }
    }

    return ans;

}



int main(){

    // taking the input for the problem no of elements 
    int n;
    cout<<"Enter the no of elements: ";
    cin>>n;

    // take the input for the rotated sorted array
    vector<int>nums(n);
    cout<<"Enter the rotated sorted array: ";
    for(int i=0;i<n;i++) cin>>nums[i];


    // logging the answer
    int ans=findMin(nums);

    cout<<"the minimum element in the rotated sorted array will be: "<<ans;
    return 0;

}