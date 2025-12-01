#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// int his porblem we need to find the longest common subsequence of two text which will be given in the input 

// i have written both soln one is of the recurssive offcourse it will give tle and dynamic programming also using tabulation it can be done using memoization also



// recurssive solution

// time complexity -> O(2^(n+m))

// space complexity ->  O(n+m)

int f(int i,int j,string&s,string&t){

    // if any of the index goes below base case we will instantly return 0
    if(i<0 || j<0) return 0;


    // important check 

    // if the words at both of index are same we gonna sum up 1 and check the other possible once

    if(s[i]==t[j]) return 1+f(i-1,j-1,s,t);


    // if the above case doesnt satisfy we will check for both of them skipping the char the one which we will return the max we will take it 
    return max(f(i-1,j,s,t),f(i,j-1,s,t));

}


// dp solution below:


// time complexity -> O(n*m)

// space complexity -> O(n*m)

 int longestCommonSubsequence(string &s,string &t){


    // calculate the size of both of the text
    int n=s.size();
    int m=t.size();


    // contsruct the dp vector for tabulation

    vector<vector<int>>dp(n+1,vector<int>(m,0));

    // storing the rule for the dp in case the string is empty

    for(int i=0;i<=n;i++) dp[i][0]=0;

    for(int i=0;i<=m;i++)dp[0][i]=0;

    // finding the longest common subequence

    for(int idx1=1;idx1<=n;idx1++){
        for(int idx2=1;idx2<=m;idx2++){


            // if the match is found we will add 1 and take the previous value till now and store it in the current index positions
            if(s[idx1-1]==t[idx2-1]){
                dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
            }

            // if the characters doesnt match take the max from top and left
             
            else{  
                dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);


            }
        }
    }

    // return the result

    return dp[n][m];



 }



int main(){

    // these are the two input string 
    string s="abcde";
    string t="ace";

    // calculating the size of both 

    int n=s.size();
    int m=t.size();

    // calling the recurssive function starting with the last index of both of the string

  /* int recurssiveAns=f(n-1,m-1,s,t);

    cout<<recurssiveAns; */

    int dpSoln=longestCommonSubsequence(s,t);
    cout<<dpSoln;


}