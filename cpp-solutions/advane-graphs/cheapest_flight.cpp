#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int cheapestFlight(int n,vector<vector<int>>&flights,int src,int dst,int k){

    // creating vector with pair contains dst and price
    vector<pair<int,int>>adj[n];


    // pushing the data wrt the requirment above
    for(auto &it:flights){
        int u=it[0];
        int v=it[1];
        int w=it[2];
        adj[u].push_back({v,w});
    }
     // creating a queue
        queue<pair<int, pair<int, int>>> q;

    // distance vector for stroing the shortest distance
        vector<int>distance(n,1e9);

        // pushing the source to the queue with stops as 0
    q.push({0,{src,dst}});

    // source distance should be 0
    distance[src]=0;

    while(!q.empty()){

        // grab the queue element and pop it right after it
          auto it = q.front();
            q.pop();

            // take all 3 params stops node and cost 
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // stops greater than k we will continue 
            if (stops > k) continue;


            // traverse inside the vector adjacent
            for (auto &itr : adj[node]) {

                // take the adj node and weight 
                int adjNode = itr.first;
                int wt = itr.second;
                // if we get a smaller distance then will replace it
                if (cost + wt < distance[adjNode]) {

                    // replace the current distance
                    distance[adjNode] = cost + wt;
                    // push the elemnt into queue
                    q.push({stops + 1, {adjNode, cost + wt}});
                }
            }
    }

    // if the last dst in distance vector value is 1e9 will return -1 which is not possible
    return (distance[dst] == (int)1e9) ? -1 : distance[dst];





    


}


int main(){

    // NO OF NODES
    int n=4;

    // 2d vector contating start end and weight 
    vector<vector<int>>flights={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    // surce node
    int src=0;

    // destination node
    int dst=3;

    // no of stops
    int k=1;

    int cheapestDistance=cheapestFlight(n,flights,src,dst,k);



    // logging the data with theses conditions
    if(cheapestDistance==-1){
        cout<<"no route possible for the given data set";
    }
    else{
        cout<<"The cheapest price from src to dst is: "<<cheapestDistance;

    }

    return 0;

}