#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//create adjaceny list
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++){
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	//do bfs
	unordered_map<int,bool> visited;
	unordered_map<int,int> parent;
	queue<int> q;
	parent[s] = -1;
	q.push(s);
	visited[s] = true;

	while(!q.empty()){
		int front = q.front();
		q.pop();

		for(auto i:adj[front]){
			if(!visited[i]){
				visited[i] = true;
				parent[i] = front;
				q.push(i);
			}
		}
	}

	//prepare shortest path
	vector<int> ans;
	int currentNode = t;
	ans.push_back(t);

	while(currentNode != s){
		currentNode = parent[currentNode];
		ans.push_back(currentNode);
	}

	reverse(ans.begin(),ans.end());
	return ans;
}


int main(){
    int n;
    cout<<"Enter no of houses"<<endl;
    cin>>n;
    
    int e;
    cout<<"Enter no of roads"<<endl;
    cin>>e;
    
    int s;
    cout<<"Enter starting house"<<endl;
    cin>>s;
    
    int t;
    cout<<"Enter ending house"<<endl;
    cin>>t;
    
    
    vector<pair<int,int>> vect;
    cout<<"Enter pairs"<<endl;
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        vect.push_back(make_pair(f,s));
    }
    
    vector<int> output = shortestPath(vect,n,e,s,t);
    
    cout<<"___________________________"<<endl;
    
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    
    return 0;
}