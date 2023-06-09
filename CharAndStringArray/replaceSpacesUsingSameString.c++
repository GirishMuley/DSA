#include<bits/stdc++.h>
using namespace std;

string replaceSpacesUsingSameString(string &str){
    int n = str.length();
    int count = 0;
    for(int i=0;i<n;i++){
        if(str[i] == ' '){
            count++;
        }
    }
    n = str.length()+(count*2);
    for(int i=0;i<n;i++){
        if(str[i] == ' '){
        str.erase(i,1);
        str.insert(i,"@40");
        }
    }
    return str;
}

int main(){
    string str;
    cout<<"Enter string"<<endl;
    getline(cin,str);
    cout<<"Output"<<endl;
    cout<<replaceSpacesUsingSameString(str)<<endl;
    
    return 0;
}