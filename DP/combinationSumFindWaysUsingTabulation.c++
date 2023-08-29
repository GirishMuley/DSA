#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &num,int tar){
   vector<int> dp(tar+1,0);
   dp[0] = 1;

   //traversing from target 1 to tar
   for(int i=1;i<=tar;i++){
       //traversing on num vector
       for(int j=0;j<num.size();j++){
           if(i-num[j] >= 0)
                dp[i] += dp[i - num[j]];
       }
   }
   return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    return solve(num,tar);
}

int main(){
    int size;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    
    cout<<"Enter elements"<<endl;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    int tar;
    cout<<"Enter target value"<<endl;
    cin>>tar;
    
    cout<<"___________________"<<endl;
    
    cout<<findWays(vect,tar)<<endl;
    
    return 0;
}