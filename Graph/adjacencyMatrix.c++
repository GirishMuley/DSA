#include<bits/stdc++.h>
using namespace std;

int main(){
    //n represent no of nodes
    //m represent no of edges
    int n,m;
    cin>>n>>m;
    vector<vector<int>> ans(n,vector<int>(m,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        ans[u][v] = 1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<< " ";
        }
        cout<<endl;
    }
    return 0;
}