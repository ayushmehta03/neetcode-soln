#include<iostream>
#include<vector>
#include<queue>
using namespace std;



// in this question we have to find the kth largest element
// it means suppose if have data like this 1 2 3 4 5 6 7

// k value=2 kth largest will be 1 for 7 and 2 for 6 so the value matches we get 6 as kth largest


int kthLargest(vector<int>&nums,int k){


    // declaring a min heap so that smallest value goes at the top 
    priority_queue<int,vector<int>,greater<int>>minHeap;



    // pushing the value into the pq

    for(int num:nums){

        // this will start pushing the minimu at the top
        minHeap.push(num);

        // and if the size goes beyond k we will start removing the top element which is the smaller ones


        if(minHeap.size()>k) minHeap.pop();
    }


    // and intially at the end we will get the kth largest at the top

    // so return the top

    return minHeap.top();



}



int main(){

    // this is the given data
    vector<int>nums={3,2,1,5,6,4};

    // value of k

    int k=2;

    int ans=kthLargest(nums,k);

    cout<<"the kth largest element will be: "<<ans;

    


}