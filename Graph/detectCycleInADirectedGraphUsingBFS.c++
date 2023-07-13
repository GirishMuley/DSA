#include<bits/stdc++.h>
using namespace std;


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
   //create adj list
    unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first  -1;
        int v = edges[i].second -1;

        adj[u].push_back(v);
    }

    //find all indegrees
    vector<int> indegrees(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegrees[j]++;
        }
    }

    //0 indegrees value push 
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indegrees[i] == 0)
        q.push(i);
    }

    //do bfs
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //int count
        cnt++;

        //neighbour indegree update
        for(auto neighbour:adj[front])
        {
            indegrees[neighbour]--;
            if(indegrees[neighbour] == 0)
            q.push(neighbour);
        }
    }
    if(cnt == n)
    return false;
    else
    return true;
}

int main(){
    int n;
    cout<<"Enter no of vertex"<<endl;
    cin>>n;
    
    int e;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    
    vector<pair<int,int>> vect;
    cout<<"Enter pairs"<<endl;
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        vect.push_back(make_pair(f,s));
    }
    
    if(detectCycleInDirectedGraph(n,vect)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    
    return 0;
}