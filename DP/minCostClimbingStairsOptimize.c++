#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &cost,int n){
      int prev2 = cost[0];
      int prev1 = cost[1];

      for(int i=2;i<n;i++){
          int curr = cost[i] + min(prev1,prev2);
          prev2 = prev1;
          prev1 = curr;
      }
      return min(prev1,prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        return solve(cost,n);
    }
    
int main(){
    int size;
    cout<<"Enter total stairs"<<endl;
    cin>>size;
    
    cout<<"__________________"<<endl;
    vector<int> vect;
    
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    cout<<minCostClimbingStairs(vect)<<endl;
    
    return 0;
}