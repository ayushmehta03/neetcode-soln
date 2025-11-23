#include<iostream>
#include<vector>
#include<queue>
using namespace std;



// time complexity-> O(n logn)

// space complexity -> O(n)

bool handsofSt(vector<int>&hand,int grp){


    // take the no of elements in total

    int n=hand.size();


    // if the total number of element is not multiple of grp size it can nnot be arranged
    if(n%grp!=0) return false;


    // declaring the priority queue to get the smallest card at the top

    priority_queue<int,vector<int>,greater<int>>pq;


    // pushing all the card into queue

    for(int card:hand){
        pq.push(card);
    }

    // track the frequency with the help of map

    unordered_map<int,int>freq;

    for(int card: hand) freq[card]++;


    // run the loop untill the pq becomes empty



    while(!pq.empty()){
        // get the smallest avilable card
        int start=pq.top();
        pq.pop();


        // if this card is used up skip it
        if(freq[start]==0) continue;


        // form the group

        for(int i=0;i<grp;i++){
            int curr=start+i;

            // if the required card is missing we cant form the group
            if(freq[curr]==0) return false;

            freq[curr]--;
        }
    }

    return true; // all groups are formed after loop completes without any error
}   




int main(){


    // hand vector number of cards 

    vector<int>hand={1,2,3,6,2,3,4,7,8};


    // group size declaration

    int grpSize=3;


    if(handsofSt(hand,grpSize)){
        cout<<"yes alice's hand can be rearragened";
    }
    else{
        cout<<"not possible to arrange alice's hand";
    }
}