#include<bits/stdc++.h>
using namespace std;

class node{
  public:
  int data;
  int i;
  int j;

  node(int data,int row,int col){
      this->data = data;
      i = row;
      j = col;
  }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    priority_queue<node*,vector<node*>, compare> minHeap;

    //step1: insert all K first element 
    for(int i=0;i<k;i++){
        node* tmp = new node(kArrays[i][0],i,0);
        minHeap.push(tmp);
    }

    vector<int> ans;

    //step2:
    while(minHeap.size() > 0){
        node* tmp = minHeap.top();
        ans.push_back(tmp->data);
        minHeap.pop();

        int i = tmp->i;
        int j = tmp->j;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            minHeap.push(next);
        }
    }
    return ans;
}

void print(vector<int>arr,int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        vector<vector<int>> arr(k,vector<int>(k,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                cin>>arr[i][j];
            }
        }
        
        vector<int> output = mergeKSortedArrays(arr,k);
        print(output,k*k);
        cout<<endl;
    }
    return 0;
}