#include<bits/stdc++.h>
using namespace std;


vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adjacency list
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //create of distnce array with infinite value intially
    vector<int> dist(vertices);
    for(int i=0;i<vertices;i++)
       dist[i] = INT_MAX;

    //creation of set on basis (distance,node)
    set<pair<int,int>> st;

    //intialse distance and set with source node
    dist[source] = 0;
    st.insert(make_pair(0,source));

    while(!st.empty()){
        //fetch top record
        auto top = *(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        //remove top record now
        st.erase(st.begin());

        //traverse on neighbour
        for(auto neighbour: adj[topNode]){
            if(nodeDistance + neighbour.second < dist[neighbour.first]){
                auto record = st.find(make_pair(dist[neighbour.first],neighbour.first));

                //if record found , then erase it
                if(record != st.end()){
                    st.erase(record);
                }

                //distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                //record push in set
                st.insert(make_pair(dist[neighbour.first],neighbour.first));
            }
        }
    }
    return dist;
}


int main(){
    int v;
    cout<<"Enter no of vertices"<<endl;
    cin>>v;
    
    int e;
    cout<<"Enter no of edges"<<endl;
    cin>>e;
    
    cout<<"________________________"<<endl;
    
    // vector<vector<int>> vect(v,vector<int>(e,0));
    
    // for(int i=0;i<e;i++){
    //     int u,v,w;
    //     cin>>u>>v>>w;
    //     vect[u][v] = 0;
    //     vect[u][w] = 0;
    // }
    cout<<"Enter row and col"<<endl;
    
    int r,c;
    cin>>r>>c;
    vector<vector<int>> vect;
    for(int i=0;i<r;i++){
        vector<int> v1;
        for(int j=0;j<c;j++){
            int num;
            cin>>num;
            v1.push_back(num);
        }
        vect.push_back(v1);
    }
    
    int source = 0;
    
    vector<int> output = dijkstra(vect,v,e,source);
    
    cout<<"________________________"<<endl;
    
    for(int i=0;i<output.size();i++){
        cout<<output[i]<<" ";
    }
    
    return 0;
}