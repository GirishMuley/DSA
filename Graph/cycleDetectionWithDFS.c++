#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>


bool isCyclicDFS(int node,int parent,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj){
    visited[node] = true;
    for(auto neihbour:adj[node]){
        if(!visited[neihbour]){
            bool cycleDetection = isCyclicDFS(neihbour,node,visited,adj);
            if(cycleDetection){
                return true;
            }else if(neihbour != parent){
                //cycle parent
                return true;
            }
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //create adjacency list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //to handle disconnected components
    unordered_map<int,bool> visited;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,-1,visited,adj);
            if(ans == 1)
                return "Yes";
        }
    }
    return "No";
}


int main(){
    int n;
    cout<<"Enter no of vertex(nodes)"<<endl;
    cin>>n;
    
    int e;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    
    vector<vector<int>> vect(n,vector<int>(e,0));
    
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        vect[u][v] = 1;
    }
    
    string result = cycleDetection(vect,n,e);
    
    cout<<result<<endl;
    
    return 0;
}