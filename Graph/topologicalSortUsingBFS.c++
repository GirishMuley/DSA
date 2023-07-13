#include<bits/stdc++.h>
using namespace std;

 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<e;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegrees(v);
    for(auto i:adj){
        for(auto j:i.second){
            indegrees[j]++;
        }
    }

    //0 indegrees value push 
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indegrees[i] == 0)
        q.push(i);
    }

    //so bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //ans store
        ans.push_back(front);

        //neighbour indegree update
        for(auto neighbour:adj[front])
        {
            indegrees[neighbour]--;
            if(indegrees[neighbour] == 0)
            q.push(neighbour);
        }
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
    
    // for(int i=0;i<output.size();i++){
    //     cout<<output[i]<<" ";
    // }
    
    for (auto it = output.begin(); it != output.end(); it++)
        cout << *it << " ";
 
    
    return 0;
}