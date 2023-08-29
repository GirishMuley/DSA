#include<bits/stdc++.h>
using namespace std;

int solve(string a,string b){
    vector<int> curr(b.length()+1,0);
    vector<int> next(b.length()+1,0);
    
    for(int i=a.length()-1;i>=0;i--){
        for(int j = b.length()-1;j>=0;j--){
            int ans = 0;
            if(a[i] == b[j]){
                ans = 1 + next[j+1];
            }
            else
            {
                ans = max(next[j],curr[j+1]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
    int longestCommonSubsequence(string text1, string text2) {
        return solve(text1,text2);
    }

int main(){
    string str1;
    cout<<"Enter string one"<<endl;
    getline(cin,str1);
    
    string str2;
    cout<<"Enter string two"<<endl;
    getline(cin,str2);
    
    cout<<"________________"<<endl;
    
    cout<<longestCommonSubsequence(str1,str2)<<endl;
    
    return 0;
}