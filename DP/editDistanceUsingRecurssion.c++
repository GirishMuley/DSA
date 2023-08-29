#include<bits/stdc++.h>
using namespace std;

int solve(string& a,string& b,int i,int j){
    //base case
    if(i == a.length()){
        return b.length() - j;
    }
    if(j == b.length()){
        return a.length() - i;
    }

    int ans = 0;
    if(a[i] == b[j]){
        return solve(a,b,i+1,j+1);
    }
    else
    {
        //insert
        int insertAns = 1 + solve(a,b,i,j+1);
        //delete
        int deleteAns = 1 + solve(a,b,i+1,j);
        //replace
        int replaceAns = 1 + solve(a,b,i+1,j+1);

        ans = min(insertAns,min(deleteAns,replaceAns));
    }
    return ans;
}
   
int minDistance(string word1, string word2) {
        return solve(word1,word2,0,0);
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