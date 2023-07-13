#include<bits/stdc++.h>
using namespace std;


void topoSort(int node,vector<bool> &visited,stack<int> &s,unordered_map<int,list<int>> &adj){
    visited[node] = 1;

    for(auto neighbour:adj[node]){
        if(!visited[neighbour])
            topoSort(neighbour,visited,s,adj);
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // call dfs toplogical sort util function all component
    vector<bool> visited(v);
    stack<int> s;
    for(int i=0;i<v;i++){
        if(!visited[i])
            topoSort(i,visited,s,adj);
    }

    vector<int> ans;

    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

int main(){
    
    int n;
    cout<<"Enter no of vertex"<<endl;
    cin>>n;
    
    int e;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    
    cout<<"_________________________________"<<endl;
    
    vector<vector<int>> vect(n,vector<int>(e,0));
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        vect[u][v] = 1;
    }
    
    vector<int> output = topologicalSort(vect,n,e);
    
    cout<<"_________________________________"<<endl;
    
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    
    // for (auto it = output.begin(); it != output.end(); it++)
    //     cout << *it << " ";
 
    
    return 0;
}