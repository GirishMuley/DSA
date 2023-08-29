#include<bits/stdc++.h>
using namespace std;

int solveTab(vector<int> &num,int x){

    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=x;i++){
        //trying to solve for every amount fingure from 1 to x
        for(int j=0;j<num.size();j++){
            if(i-num[j] >=0 && dp[i-num[j]] != INT_MAX){
                dp[i] = min(dp[i],1 + dp[i-num[j]]);
            }
        }
    }

    if(dp[x] == INT_MAX)
        return -1;

    return dp[x];
}


int minimumCoinsElements(vector<int> &num, int x)
{
    return solveTab(num,x);
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