#include<iostream>
#include<vector>
#include<queue>
using namespace std;



bool topoSort( vector<vector<int>>&adj,int V){

    // vector for storing the indegree 
    vector<int>inDegree(V);

    // storing all the incoming nodes

    for(int i=0;i<V;i++){
        for(auto it:adj[i]){
            inDegree[it]++;
        }
    }

    queue<int>q;

    for(int i=0;i<V;i++){
        if(inDegree[i]==0) q.push(i);
    }
    vector<int>topo;

    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it:adj[node]){
            inDegree[it]--;
            if(inDegree[it]==0) q.push(it);

        }


    }
    if(topo.size()==V) return true;

    return false;



}

bool canFinish(vector<vector<int>>&preRequists,int numCourses){

    // storinng the numCourse into simple variable
    int V=numCourses;

    // adjacenecy vector creation wrt prerequists
    vector<vector<int>>adj(V);


    // pushing the edges into the adjacency list
    for(auto it:preRequists){
        adj[it[0]].push_back(it[1]);
    }

    if(topoSort(adj,V)) return true;
    return false;

}

// main function

int main(){

    // this the course prerequists
    vector<vector<int>>preRequists={
        {1,0}
    };

    // these are the number of courses 
    int numCourses=2;


    // if we can finish it means we will be able to finish the course
    if(canFinish(preRequists,numCourses)){
        cout<<"Yes we can finish the course ";
    }

    // otherwise not possible to complete

    else{
        cout<<"Not possible to finish the course ";
    }


}