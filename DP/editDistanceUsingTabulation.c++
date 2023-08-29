#include<bits/stdc++.h>
using namespace std;

int solve(string a, string b){
    vector<vector<int>> dp(a.length()+1,vector<int>(b.length()+1,0));
    
    for(int j=0;j<b.length();j++){
        dp[a.length()][j] = b.length() - j;
    }
    
    for(int i=0;i<a.length();i++){
        dp[i][b.length()] = a.length() - i;
    }
    
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
         int ans = 0;
    if(a[i] == b[j]){
        ans = dp[i+1][j+1];
    }
    else
    {
        //insert
        int insertAns = 1 + dp[i][j+1];
        //delete
        int deleteAns = 1 + dp[i+1][j];
        //replace
        int replaceAns = 1 + dp[i+1][j+1];

        ans = min(insertAns,min(deleteAns,replaceAns));
    }
    dp[i][j] = ans;   
        }
    }
    return dp[0][0];
}
int minDistance(string word1, string word2) {
    return solve(word1,word2);
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