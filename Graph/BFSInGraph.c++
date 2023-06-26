#include<bits/stdc++.h>
using namespace std;


void preparedAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node] = 1;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        //store frontNode into ans
        ans.push_back(frontNode);

        //traverse all neighbours of frontNode
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;

    preparedAdjList(adjList,edges);

    //traverse all components of a graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
} 

int main(){
    int vertex;
    cout<<"Enter vertex"<<endl;
    cin>>vertex;
    
    int pairNumber;
    cout<<"How many pair you want to enter"<<endl;
    cin>>pairNumber;
     
    vector<pair<int,int>> vect;
    
    for(int i=0;i<pairNumber;i++){
        int f,s;
        cout<<"Enter pairs";
        cin>>f>>s;
        vect.push_back(make_pair(f,s));
    }
    
    cout<<"Pair You Enter"<<endl;
    
    for(int i=0;i<pairNumber;i++){
        cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }
    
    vector<int> output = BFS(vertex,vect);
    
    cout<<"Yor output is below "<<endl;
    
    for(int i=0;i<output.size();i++){
        cout<<output[i]<< " ";
    }
    
    return 0;
}