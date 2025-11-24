#include<iostream>
#include<vector>
#include<stack>
using namespace std;



// in this problem we have to find the next greater temperature difference with current one in terms of indexes

// time complexity ->  O(N)

// space complexity -> O(N)


vector<int>dailyTemp(vector<int>&temp){


    // calculate the total no of temperature given

    int n=temp.size();


    // declare vector for storing the days difference intially filled with o's

    vector<int>nge(n,0);

    // declare stack to store indicez which represent warmer days
    stack<int>st;

    //  will iterate from rifht to left

    for(int i=n-1;i>=0;i--){

        // if the stack is not empty and the top indices is olding vakue which is smaller or equal to the temp[i] will discard it because it can not be greater 
        while(!st.empty() &&temp[st.top()]<=temp[i]){
            st.pop();
        }
        // if stack is not empty then the top elemnt will be greater 

        // so we will set the difference to the index 
        if(!st.empty()){
        nge[i]=st.top()-i;

        }

        // push the indices
        st.push(i);
    }

    // return the answer vector

    return nge;


}

int main(){
    vector<int>temp={73,74,75,71,69,72,76,73};

    vector<int>ans=dailyTemp(temp);

    for(auto it: ans) cout<<" "<<it;
}