#include<bits/stdc++.h>
using namespace std;

bool solve(string str,string pattern,int i,int j){
    //base case
    if(i<0 && j<0)
        return true;
    
    if(i>=0 && j<0)
        return false;
    
    if(i<0 && j>=0){
        for(int k=0;k<=j;k++){
            if(pattern[k] != '*'){
                return false;
            }
        }
        return true;
    }
    //match
    if(str[i] == pattern[j] || pattern[j] == '?')
    return solve(str,pattern,i-1,j-1);
    else if(pattern[j] == '*')
        return (solve(str,pattern,i-1,j) || solve(str,pattern,i,j-1));
        else
        return false;
}
    bool isMatch(string s, string p) {
        return solve(s,p,s.length()-1,p.length()-1);
    }

int main(){
    string str;
    cout<<"Enter string "<<endl;
    getline(cin,str);
    
    string pattern;
    cout<<"Enter pattern"<<endl;
    getline(cin,pattern);
    
    cout<<"______________"<<endl;
    
    if(isMatch(str,pattern)){
        cout<<"True";
    }else{
        cout<<"False";
    }
    
    return 0;
}