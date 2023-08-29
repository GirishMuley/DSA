#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& obstacles,int currlane,int currpos){
        //base case
        int n = obstacles.size()-1;
        if(currpos == n){
            return 0;
        }

        if(obstacles[currpos+1] != currlane){
            return solve(obstacles,currlane,currpos+1);
        }
        else
        {
            //sideways jump
            int ans = INT_MAX;
            for(int i=1;i<=3;i++){
                if(currlane != i && obstacles[currpos] != i)
                ans = min(ans,1 + solve(obstacles,i,currpos));
            }
            return ans;
        }
    }
int minSideJumps(vector<int>& obstacles) {
        return solve(obstacles,2,0);
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