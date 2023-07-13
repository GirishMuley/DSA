#include<bits/stdc++.h>
using namespace std;


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    vector<int> dist(n+1,1e9);
    dist[src] = 0;

    //n-1 times

    for(int i=0;i<=n;i++){
        //traverse on edge list
        for(int j=0;j<m;j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
                dist[v] = dist[u] + wt;
            }
        }
    }

    //check for negative cycle
    bool flag = 0;
    for(int j=0;j<m;j++){
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if(dist[u] != 1e9 && ((dist[u] + wt) < dist[v])){
            flag = 1;
        }
    }
    if(flag == 0)
    {
        return dist[dest];
    }
    return -1;
}

int main(){
    int v;
    cout<<"Enter no of vertices"<<endl;
    cin>>v;
    
    int e;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    
    int src;
    cout<<"Enter source"<<endl;
    cin>>src;
    
    int dest;
    cout<<"Enter destination"<<endl;
    cin>>dest;
    
    cout<<"______________________"<<endl;
    
    int r,c;    
    cout<<"Enter row and col"<<endl;
    cin>>r>>c;
    
    vector<vector<int>> vect;
    for(int i=0;i<r;i++){
        vector<int> row;
        for(int j=0;j<c;j++){
            int value;
            cin>>value;
            row.push_back(value);
        }
        vect.push_back(row);
    }
    
    int output = bellmonFord(v,e,src,dest,vect);
    
    cout<<"______________________"<<endl;
    
    cout<<output<<endl;
    
    return 0;
}