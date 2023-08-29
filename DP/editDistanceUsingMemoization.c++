#include<bits/stdc++.h>
using namespace std;

int solve(string& a,string& b,int i,int j,vector<vector<int>>& dp){
    //base case
    if(i == a.length()){
        return b.length() - j;
    }
    if(j == b.length()){
        return a.length() - i;
    }
    
    if(dp[i][j] != -1)
        return dp[i][j];
        
    int ans = 0;
    if(a[i] == b[j]){
        return solve(a,b,i+1,j+1,dp);
    }
    else
    {
        //insert
        int insertAns = 1 + solve(a,b,i,j+1,dp);
        //delete
        int deleteAns = 1 + solve(a,b,i+1,j,dp);
        //replace
        int replaceAns = 1 + solve(a,b,i+1,j+1,dp);

        ans = min(insertAns,min(deleteAns,replaceAns));
    }
    return dp[i][j] = ans;
}
   
int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(),vector<int>(word2.length(),-1));
        return solve(word1,word2,0,0,dp);
}

int main(){
    string str1;
    cout<<"Enter word1"<<endl;
    getline(cin,str1);
    
    string str2;
    cout<<"Enter word2"<<endl;
    getline(cin,str2);
    
    cout<<"____________"<<endl;
    
    cout<<minDistance(str1,str2)<<endl;
    
    return 0;
}