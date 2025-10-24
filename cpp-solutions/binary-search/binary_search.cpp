#include<iostream>
#include<vector>
using namespace std;



// binary search is a very common algo of searching in which the input is sorted and it search by dividing left and right side with help of middle


// time complexity-> O(log n) 

// space O(1)

// it will return the index of target if it is present
int binarySearch(vector<int>&nums,int target){

    // two pointers low and high one at the left most and other at the right most
    int low=0;
    int high=nums.size()-1;


    while(low<=high){
    
// get the middle index in terms of low and high
    int mid=low+(high-low)/2;

    // checks to be perofomed 
    //1. if value is equal to target

    if(nums[mid]==target) return mid;

    // 2. if value is smaller than target
    // then increase the low to next to mid
   else if(nums[mid]<target) low=mid+1;


    // 3. if value is greater thn target
    // then decrease high to before mid
        else high=mid-1;


    
    }


    // if none of the index is returned 
    return -1;


}

int main(){

    // declaring the vector and target ehich we need to search
    vector<int>nums={-1,0,3,5,9,12};
    int target=9;


    int ans=binarySearch(nums,target);

    // logging the output if -1 it means target is not found else return the exact output
    if(ans==-1){
        cout<<"target is not present inside the input array";
    }

    else{
        cout<<"the index at which target is present is: "<<ans;

    }
    return 0;
}