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
    int longestPalindromeSubseq(string s) {
        string revStr = s;
        reverse(revStr.begin(),revStr.end());
        int ans = solve(s,revStr);
        return ans;
    }
int main(){
    string str1;
    cout<<"Enter string one"<<endl;
    getline(cin,str1);
    
    cout<<"________________"<<endl;
    
    cout<<longestPalindromeSubseq(str1)<<endl;
    
    return 0;
}