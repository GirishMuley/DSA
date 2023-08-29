#include<bits/stdc++.h>
using namespace std;


int solveMemo(vector<int> &num,int x,vector<int> &dp){
    //base case
    if(x == 0)
        return 0;

    if(x < 0)
        return INT_MAX;

    if(dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for(int i=0;i<num.size();i++){
        int ans = solveMemo(num, x-num[i],dp);
        if(ans != INT_MAX)
            mini = min(mini,1+ans);
    }
    dp[x] = mini;
    return mini;
}

int minimumCoinsElements(vector<int> &num, int x)
{
    vector<int> dp(x+1,-1);
    int ans = solveMemo(num,x,dp);
    if(ans == INT_MAX)
        return -1;
    else
        return ans;

}

int main(){
    
    int size;
    cout<<"No of coins"<<endl;
    cin>>size;
    
    int amount;
    cout<<"Enter amount"<<endl;
    cin>>amount;
    
    cout<<"____________"<<endl;
    
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"____________"<<endl;
    
    cout<<minimumCoinsElements(vect,amount)<<endl;
    
    return 0;
}