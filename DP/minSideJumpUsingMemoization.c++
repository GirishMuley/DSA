#include<bits/stdc++.h>
using namespace std;

 int solve(vector<int>& obstacles,int currlane,int currpos,vector<vector<int>>& dp){
        //base case
        int n = obstacles.size()-1;
        if(currpos == n){
            return 0;
        }

        if(dp[currlane][currpos] != -1)
            return dp[currlane][currpos];

        if(obstacles[currpos+1] != currlane){
            return solve(obstacles,currlane,currpos+1,dp);
        }
        else
        {
            //sideways jump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(currlane != i && obstacles[currpos] != i)
                ans = min(ans,1 + solve(obstacles,i,currpos,dp));
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4,vector<int> (obstacles.size(),-1));
        return solve(obstacles,2,0,dp);
    }

int main(){
 
     int size;
     cout<<"Enter size"<<endl;
     cin>>size;
     
     cout<<"Enter obstacles"<<endl;
     vector<int> vect;
     for(int i=0;i<size;i++){
         int data;
         cin>>data;
         vect.push_back(data);
     }
     
     cout<<"___________________"<<endl;
     
     cout<<minSideJumps(vect)<<endl;
     
      return 0;
}