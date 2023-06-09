#include<bits/stdc++.h>
using namespace std;

void soleve(vector<int> nums,vector<int> output,int index,vector<vector<int>>& ans){
    //base case
    if(index >= nums.size()){
        ans.push_back(output);
        return;
    }
    //exclude
    soleve(nums,output,index+1,ans);
    //include
    int element = nums[index];
    output.push_back(element);
    soleve(nums,output,index+1,ans);
}


vector<vector<int>> subsets(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    soleve(nums,output,index,ans);
    return ans;
}

void print(vector<vector<int>> ans){
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    vector<int> vect;
    cout<<"Enter size"<<endl;
    int size;
    cin>>size;
    cout<<"Enter elements"<<endl;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }

    vector<vector<int>> ans =  subsets(vect);
    print(ans);

    return 0;
}