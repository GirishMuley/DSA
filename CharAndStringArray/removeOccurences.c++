#include<bits/stdc++.h>
using namespace std;

string removeOccurences(string s,string part){
    while(s.length() != 0 && s.find(part) < s.length()){
        s.erase(s.find(part),part.length());
    }
    return s;
}

int main(){
    string str = "daabcbaabcbc";
    string part = "abc";
    
    cout<<removeOccurences(str,part)<<endl;
    
    return 0;
}