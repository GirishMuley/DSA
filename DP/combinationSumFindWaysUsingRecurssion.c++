#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &num,int tar){
    //base case
    if(tar < 0)
        return 0;
    
    if(tar == 0)
        return 1;
    
    int ans = 0;

    for(int i=0;i<num.size();i++){
        ans += solve(num,tar - num[i]);
    }
    return ans;
}
int findWays(vector<int> &num, int tar)
{
    return solve(num,tar);
}

int main(){
    int size;
    cout<<"Enter size of array"<<endl;
    cin>>size;
    
    cout<<"Enter elements"<<endl;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    int tar;
    cout<<"Enter target value"<<endl;
    cin>>tar;
    
    cout<<"___________________"<<endl;
    
    cout<<findWays(vect,tar)<<endl;
    
    return 0;
}