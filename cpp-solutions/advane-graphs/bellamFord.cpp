#include<iostream>
#include<vector>
using namespace std;

// this algorithm works when the dijikstra fails because of negative edges
// altough dijiksra is faster than this 

// time complexity -> O(E*V)
// space complexity -> O(E+V)







    vector<int> bellamnFord(vector<vector<int>>edges,int src,int V){

        // distance vector for stroing 
        vector<int>distance(V,1e8);

        // mark the soruce as 0
        distance[src]=0;

        // the intution behind bellman ford algo is to try relaxation for v-1 times so that each vertex gets a minimum distance 

        // even after running for v-1 if there is still relaxation it means there is negative cycle so will return accordingly

        // running loop for v-1 times
        for(int i=0;i<V-1;i++){
        // tarverse through the edges
        for(auto it:edges){

            // grab the starting point(u),destination(v),and weight(w)
            int u=it[0];
            int v=it[1];
            int w=it[2];

            // check for starting poing should not be infinity and the reaching node distance is greater tahn the starting and weight to reach it
           
            if(distance[u]!=1e8 &&distance[u]+w<distance[v]){

            // replace the existiing value 
             distance[v]=distance[u]+w;


            }
        }


        }

        // last check for negative cycle return {-1} if there is negative cycle again

        for(auto it:edges){
           int u=it[0];
            int v=it[1];
            int w=it[2];

            // this means still relaxation is possible and we have to return {-1}
            if(distance[u]!=1e8 &&distance[u]+w<distance[v]){
            return {-1};


            } 
        }

        // return the distance vector if there is no negative cycle
        return distance;

    }

int main(){

    // edges vector with negative value
    vector<vector<int>>edges={
        {1,3,2},
        {4,3,-1},
        {2,4,1},
        {1,2,1},
        {0,1,5}
    };

    // soruce node

    int src=0;

    // no of vertices / nodes
    int V=5;

    // call the function passing edges source node and no of vertices

    vector<int>ans=bellamnFord(edges,src,V);

    
    if(ans[0]==-1){
        cout<<"not possible there is negative cycle";
    }

    else{
        for(auto it:ans){
            cout<<" "<<it;
        }
    }
    return 0;

}