// Longest Substring Without Repeating Characters   \


#include<iostream>
#include<string>
using namespace std;



// approach-> sliding window

// time complexity-> O(N)

// space complexity -> O(1)

int getLongestSubstr(string s ){

    // hash array for storing last seen indexes of  character
       int hash[256];

    // intially fill it with -1(unvisited)
       for(int i=0;i<256;i++) hash[i]=-1;

        // take two pointers ledt and right to create a window 

        // max Len will hold the maximum length of the window
       int left=0,right=0,maxLen=0;


        int n=s.size();
       // core logic

       // move the right pointer till the last position of the string

       while(right<n){

        // if it is visited before and it comes under the window of left and right then will move the left 

        if(hash[s[right]]!=-1&& hash[s[right]]>=left){

            // move left to the next position of the dupilcate
            left=hash[s[right]]+1;
        }

        // store the latest index of the character
        hash[s[right]]=right;


        // calculating the window size
        int length=right-left+1;

        // getting the max length

        maxLen=max(maxLen,length);


        right++;
       }

       // return the maxLength

       return maxLen;



}


int main(){

    string s;
    cout<<"Enter the string to check: ";
    cin>>s;

    int maxLen=getLongestSubstr(s);


    cout<<"The longest substring without repeation is: "<<maxLen;

}