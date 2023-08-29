#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight,vector<int> &value,int index,int capacity,vector<vector<int>> &dp){
	//base case
	//if only 1 item to steal, then just compare its weight with knapsack capacity
	if(index == 0){
		if(weight[0] <= capacity)
			return value[0];
		else
			return 0;
	}

	if(dp[index][capacity] != -1)
		return dp[index][capacity];

	int include = 0;
	if(weight[index] <= capacity)
		include = value[index] + solve(weight,value,index-1,capacity - weight[index],dp);
		int exclude = 0 + solve(weight,value,index-1,capacity,dp);
		dp[index][capacity] = max(exclude,include);
		return dp[index][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}

int main(){
    int size;
    cout<<"How many values you want to enter"<<endl;
    cin>>size;
    
    cout<<"Enter value associate with weight"<<endl;
    vector<int> weight;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        weight.push_back(data);
    }
    
    cout<<"Enter value of weight"<<endl;
    vector<int> value;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        value.push_back(data);
    }
    
    
    int maxWeight;
    cout<<"Enter maxWeight capacity"<<endl;
    cin>>maxWeight;
    
    cout<<"__________________________"<<endl;
    
    cout<<knapsack(weight,value,size,maxWeight)<<endl;
    
    return 0;
}