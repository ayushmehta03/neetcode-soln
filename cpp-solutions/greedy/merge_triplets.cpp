#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

// merge triplets to form target triplet which is given

// this question says that we are given 2d vector triplets from which at 3 unqiue positions we need to form triplets which is equal to the given target array

// we will use unordered set to store the 3 different position 



// time complexity -> O(N)

// space complexity -> O(1)

bool mergeTriplets(vector<vector<int>>&triplets,vector<int>target){


    // declaring the set
    unordered_set<int>st;


    // loop no 1 to traverse inside the triplets array
    for(int i=0;i<triplets.size();i++){

        // if the value is greater than the target array we will skip it

        if(triplets[i][0]>target[0]|| triplets[i][1]>target[1] || triplets[i][2] > target[2]) continue;

        // lets match the elemnt with the given target array

        for(int j=0;j<3;j++){

            // if the value is matched we will insert the position value into unordered set as all the positions are unique det will store all 3 if it is possible

            // no duplicates value will be inserted

            if(triplets[i][j]== target[j]) st.insert(j);
        }


    }

    // lets return the boolean value with respect to the size of set 

   return  st.size()==3;


}



int main(){

    vector<vector<int>>triplets={{2,5,3},{1,8,4},{1,7,5}};

    vector<int>target={2,7,5};


    if(mergeTriplets(triplets,target)){
        cout<<"Yes forming triplet is possible";
    }

    else{
        cout<<"Not possible to form the target array from triplets array";
    }


}