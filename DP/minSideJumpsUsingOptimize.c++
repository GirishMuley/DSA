
#include<bits/stdc++.h>
using namespace std;

     int solve(vector<int>& obstacles){
        int n = obstacles.size()-1;
        
        vector<int> curr(4,INT_MAX);
        vector<int> next(4,INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for(int currpos = n-1;currpos>=0;currpos--){
            for(int currlane = 1;currlane<=3;currlane++){
                if(obstacles[currpos+1] != currlane){
                    curr[currlane] = next[currlane];
                }
                else
                {
                    //sideways jump
                    int ans =INT_MAX;
                    for(int i=1;i<=3;i++){
                        if(currlane != i && obstacles[currpos] != i)
                    ans = min(ans, 1 + next[i]);
                    }
                    curr[currlane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2],min(1+next[1],1+next[3]));
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