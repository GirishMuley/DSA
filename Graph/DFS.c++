#include<bits/stdc++.h>
using namespace std;

void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj, vector<int> &component){
    //ans store
    component.push_back(node);
    //mark visited 
    visited[node] = true;

    //hr connected node k liye recursive call
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(i,visited,adj,component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    //prepare adjList
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int,bool> visited;

    //for all node call dfs ,if not visitd
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adj,component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main(){
    int v;
    cout<<"Enter no of vertices(node)"<<endl;
    cin>>v;
    int e;
    cout<<"Enter no of edges "<<endl;
    cin>>e;
    
    vector<vector<int>> ans(v,vector<int>(e,0));
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        ans[u][v] = 0;
    }
    
    cout<<"_________________"<<endl;
    
    vector<vector<int>> output = depthFirstSearch(v,e,ans);
    
    for(int i=0;i<output.size();i++){
        for(int j=0;j<output.size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}