#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight,vector<int> &value,int n,int capacity){
	//step 1
	vector<vector<int>> dp(n,vector<int>(capacity+1,0));

	//step 2: analyse base case
	for(int w = weight[0]; w<=capacity;w++){
		if(weight[0] <= capacity)
			dp[0][w] = value[0];
		else
			dp[0][w] = 0;
	}

	for(int index = 1;index<n;index++){
		for(int  w = 0;w <= capacity;w++){
			int include = 0;
			if(weight[index] <= w)
				include = value[index] + dp[index-1][w - weight[index]];
				int exclude = 0 + dp[index - 1][w];
				dp[index][w] = max(exclude,include);
		}
	}
	return dp[n-1][capacity];
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	
	return solve(weight,value,n,maxWeight);
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