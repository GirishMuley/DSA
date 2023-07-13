//kosaraju algorithm
#include<bits/stdc++.h>
using namespace std;


#include<bits/stdc++.h>

void dfs(int node,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj){
	vis[node] = true;
	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			dfs(nbr,vis,st,adj);
		}
	}
	st.push(node);
}

void reDfs(int node,unordered_map<int,bool> &vis, unordered_map<int,list<int>> &adj){
	vis[node] = true;
	for(auto nbr:adj[node]){
		if(!vis[nbr]){
			reDfs(nbr,vis,adj);
		}
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	//adj list
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];

		adj[u].push_back(v);
	}

	//topo sort
	stack<int> st;
	unordered_map<int,bool> vis;
	for(int i=0;i<v;i++){
		if(!vis[i]){
			dfs(i,vis,st,adj);
		}
	}

	//create a transpose graph
	unordered_map<int,list<int>> transpose;
	for(int i=0;i<v;i++){
		vis[i] = 0;
		for(auto nbr:adj[i]){
			transpose[nbr].push_back(i);
		}
	}

	//dfs call using above ordering
	int count = 0;
	while(!st.empty()){
		int top= st.top();
		st.pop();
		if(!vis[top]){
			count++;
			reDfs(top,vis,transpose);
		}
	}
	return count;
}

int main(){
    
    int v;
    cout<<"Enter no of vertices"<<endl;
    cin>>v;
    
    int e;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    
    cout<<"_______________________"<<endl;
    
    int r,c;
    cout<<"Enter row and col"<<endl;
    cin>>r>>c;
    
    vector<vector<int>> vect;
    
    for(int i=0;i<r;i++){
        vector<int> v1;
        for(int j=0;j<c;j++){
            int value;
            cin>>value;
            v1.push_back(value);
        }
        vect.push_back(v1);
    }
    
    cout<<"_______________________"<<endl;
    
    int output = stronglyConnectedComponents(v,vect);
    
    cout<<output;
    return 0;
}