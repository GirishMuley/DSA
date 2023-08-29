#include<bits/stdc++.h>
using namespace std;

    int solve(vector<int>& obstacles){
        int n = obstacles.size()-1;
        vector<vector<int>> dp(4,vector<int> (obstacles.size(),INT_MAX));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for(int currpos = n-1;currpos>=0;currpos--){
            for(int currlane = 1;currlane<=3;currlane++){
                if(obstacles[currpos+1] != currlane){
                    dp[currlane][currpos] = dp[currlane][currpos+1];
                }
                else
                {
                    //sideways jump
                    int ans =INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans, 1 + dp[i][currpos + 1]);
                    }
                    dp[currlane][currpos] = ans;
                }
            }
        }
        return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));
    }
    int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles);
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