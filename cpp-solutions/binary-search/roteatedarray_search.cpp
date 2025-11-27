#include<iostream>
#include<vector>
using namespace std;






int findIndex(  vector<int>&nums, int target){

 // take two pointers low and high normal bs approach

    int low=0,high=nums.size()-1;
    
        // run until low and high both met and the earch is completed 

    while(low<=high){

     // take the mid position 
        int mid=(low+high)/2;


        // if target is found at mid return the index

        if(nums[mid]==target) return mid;

        // check if the left half is sorted if the left half is sorted then left will be smaller than mid

        // nums[low]<=nums[mid]

        if(nums[low]<=nums[mid]){

            // if the target is smaller than or equal to the low  and greater than mid

            // nums[low]<=target <nums[mid]

            // then we will search in the left part only

            if(nums[low]<=target &&target<nums[mid]){
                high=mid-1;
            }

            // or else we will search in the right part

            else{
                low=mid+1;
            }
        }


        // if the left half is not sorted 

        // so nums[mid]<nums[high]

        else{

            // if the target lies inside the sorted right part

            // then nums[mid]<target<=nums[high]

            if(nums[mid]<target && target<=nums[high]){
                low=mid+1;
            }

            else{

                // target doesnt lie in the right sorted half 

                // so search in the left part
                high=mid-1;
            }
        }
    }
            // Target not found in array

    return -1;

}


int main(){
        int n;
    cout<<"Enter the no of elements: ";
    cin>>n;

    // take the input for the rotated sorted array
    vector<int>nums(n);
    cout<<"Enter the rotated sorted array: ";
    for(int i=0;i<n;i++) cin>>nums[i];


    // enter the target
    int target;

    cout<<"Enter the target to search: ";
    cin>>target;


    // logging the answer
    int ans=findIndex(nums,target);

    if(ans==-1) cout<<"No index found for the given target ";

    else{
            cout<<"the index for target value  in the rotated sorted array will be: "<<ans;

    }

}