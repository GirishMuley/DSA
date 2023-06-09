#include<bits/stdc++.h>
using namespace std;

void soleve(string ditits,string output,int index,vector<string>& ans,string mapping[]){
    //base case
    if(index >= ditits.length()){
        ans.push_back(output);
        return;
    }
    int number = ditits[index] - '0';
    string  value = mapping[number];

    for(int i=0;i<value.length();i++){
        output.push_back(value[i]);
        soleve(ditits,output,index+1,ans,mapping);
        output.pop_back();
    }
}

vector<string> letterCombinatos(string ditits){
    vector<string> ans;
    if(ditits.length()==0){
        return ans;
    }
    string output = "";
    int index = 0;
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    soleve(ditits,output,index,ans,mapping);
    return ans;
}

int main(){
    string ditits;
    cin>>ditits;

    vector<string> result =  letterCombinatos(ditits);

    for(int i=0;i<result.size();i++){
        cout<<result.at(i)<<" ";
    }

    return 0;
}