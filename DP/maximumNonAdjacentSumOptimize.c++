#include<bits/stdc++.h>
using namespace std;

int solveTab(vector<int> &nums){
    int n = nums.size();
    
    int prev2 = 0;
    int prev1 = nums[0];    

    for(int i=1;i<n;i++){
        int incl = prev2 + nums[i];
        int excl = prev1 + 0;
        int ans = max(incl,excl);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    return solveTab(nums);
}


int main(){
    int size;
    cout<<"Enter the size"<<endl;
    cin>>size;
    
    cout<<"Enter elements"<<endl;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    
    cout<<maximumNonAdjacentSum(vect)<<endl;
    
    return 0;
}