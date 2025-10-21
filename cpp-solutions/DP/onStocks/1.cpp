#include<iostream>
#include<vector>
#include<climits>
using namespace std;


// you should buy the day before you sell this is the basic rule behind the solution




// thie function calculates the maxProfit
int maxProfit(vector<int>&prices){

    // this is for stroing the minimum cost price
    int minP=INT_MAX;

    // this is for storing the maximum porfit
    int maxP=0;


    for(int i=0;i<prices.size();i++){

        // will alwyas take the minimum for buying
        minP=min(minP,prices[i]);


        // alwyas take the maximum for the maxProfit
        maxP=max(maxP,prices[i]-minP);
    }


    return maxP;


}






int main(){


    // pirces for buying and selling
    vector<int>prices={7,1,5,3,6,4};

    // logging the answer
    int ans=maxProfit(prices);


    cout<<"The max profit that can be obtained is: "<<ans;

    return 0;

}