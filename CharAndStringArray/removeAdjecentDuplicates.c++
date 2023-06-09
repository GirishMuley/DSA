#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){
    string temp = "";
    for(int i=0;i<s.length();i++){
        temp.push_back(s[i]);
        if(temp.size()>=2 && temp[temp.length()-1] == temp[temp.length()-2]){
            temp.pop_back();
            temp.pop_back();
        }
    }
    return temp;
}

int main(){
    string s = "abbaca";
    
    cout<<removeDuplicates(s);
    
    return 0;
}