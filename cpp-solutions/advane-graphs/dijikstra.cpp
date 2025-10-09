#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;



vector<int>dijkistraAlgo(vector<pair<int,int>>adj[],int src,vector<int>&distance){

    // the soruce to source will be 0
    distance[src]=0;

    // declaring priority queue with mean heap 

    // smallest value of weight will be at the top
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    //pushing the  weight source node and
    pq.push({0,src});

    // execute until the priority queue<min heap> becomes empty
    while(!pq.empty()){
        // take the top element
        auto it=pq.top();

        // remove it after taking
        pq.pop();

        //  take the node and cost
        int node=it.second;
        int  cost=it.first;

        // check for its adjacent nodes
        for(auto it:adj[node]){
            int adjNode=it.first;
            int adjCost=it.second;

            // if the current cost+adjCost is smaller than the value of distance vector value
            // then will rep;ace it and push the element into the priority queue
            if(cost+adjCost<distance[adjNode]){
                distance[adjNode]=cost+adjCost;
                pq.push({distance[adjNode],adjNode});
            }

        }

    }

    // return the vector
    return distance;

}


int main(){

    // edges vector with start,destination and weight
    vector<vector<int>> edges = {
        {0, 2, 4},
        {0, 1, 3},
        {1, 3, 2},
        {2, 3, 1},
        {3, 4, 3},
        {3, 5, 6},
        {4, 5, 5}
    };

    // no of edges
    int n=6;

    // creating adjacency list of n size

    vector<pair<int,int>>adj[n];

    // pushing the value to the adjacency list 


    // start->{end,weight/cost}
    // because dijikstra works for both directed and undirected graph
    for(auto it:edges){
        adj[it[0]].push_back({it[1],it[2]});
      adj[it[1]].push_back({it[0],it[2]});

    }

    // distance vector for storing the shortest distance from source

    // intially the value will be infinity
    vector<int>distance(n,1e9);



    // p[assing the adjacency list source node and distance vector
    vector<int>ans=dijkistraAlgo(adj,0,distance);

    // print the shortest distance 
     cout << "Shortest distances from node 0:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "0 -> " << i << " = " << ans[i] << endl;
    }

    return 0;


}