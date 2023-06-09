#include<bits/stdc++.h>
using namespace std;

void soleve(string str,string output,int index,vector<string>& ans){
    //base case
    if(index >= str.length()){
        if(output.length() > 0){
            ans.push_back(output);
        }
        return;
    }
    //exclude
    soleve(str,output,index+1,ans);
    //include
    char element = str[index];
    output.push_back(element);
    soleve(str,output,index+1,ans);
}

vector<string> subsequences(string str){
    vector<string> ans;
    string output = "";
    int index = 0;
    soleve(str,output,index,ans);
    return ans;
}

int main(){
    string str;
    cin>>str;
    

    vector<string> ans = subsequences(str);

    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }


    return 0;
}