#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// int his porblem we need to find the longest common subsequence of two text which will be given in the input 

// i have written both soln one is of the recurssive offcourse it will give tle and dynamic programming also using tabulation it can be done using memoization also



// recurssive solution


int f(int i,int j,string&s,string&t){

    // if any of the index goes below base case we will instantly return 0
    if(i<0 || j<0) return 0;


    // important check 

    // if the words at both of index are same we gonna sum up 1 and check the other possible once

    if(s[i]==t[j]) return 1+f(i-1,j-1,s,t);


    // if the above case doesnt satisfy we will check for both of them skipping the char the one which we will return the max we will take it 
    return max(f(i-1,j,s,t),f(i,j-1,s,t));

}




int main(){

    // these are the two input string 
    string s="abcde";
    string t="ace";

    // calculating the size of both 

    int n=s.size();
    int m=t.size();

    // calling the recurssive function starting with the last index of both of the string

    int recurssiveAns=f(n-1,m-1,s,t);

    cout<<recurssiveAns;


}