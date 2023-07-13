#include<bits/stdc++.h>
using namespace std;


void dfs(int node,int parent,int &timer,vector<int> &disc, vector<int> &low,vector<vector<int>> &result,unordered_map<int,list<int>> &adj, unordered_map<int, bool> &vis){
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for(auto nbr:adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node] = min(low[node],low[nbr]);
            //check edge is bridge
            
            if(low[nbr] > disc[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
           //node already visited and not parent
           //back edge
           low[node] = min(low[node],disc[nbr]); 
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //adj list
    unordered_map<int, list<int>> adj;

    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(v);
    vector<int> low(v);
    int parent = -1;
    unordered_map<int, bool> vis;

    for(int i=0;i<v;i++){
        disc[i] = -1;
        low[i] = -1;
    }

    vector<vector<int>> result;
    //dfs
    for(int i=0;i<v;i++){
        if(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;
}

int main(){
    int v;
    cout<<"Enter no of vertices"<<endl;
    cin>>v;
    
    int e;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    
    int r,c;
    cout<<"Enter row and col for array of edges"<<endl;
    cin>>r>>c;
    cout<<"____________________________________"<<endl;
    vector<vector<int>> vect;
    
    for(int i=0;i<r;i++){
        vector<int> v1;
        for(int j=0;j<c;j++){
            int val;
            cin>>val;
            v1.push_back(val);
        }
        vect.push_back(v1);
    }
    
    vector<vector<int>> output = findBridges(vect,v,e);
    
    reverse(output.begin(),output.end());
    
    cout<<"____________________________________"<<endl;
    
    int cnt = 0;
    for(int i=0;i<output.size();i++){
        cnt++;
        for(int j=0;j<output[i].size();j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"bridge"<<endl;
    cout<<cnt<<endl;
    
    return 0;
}