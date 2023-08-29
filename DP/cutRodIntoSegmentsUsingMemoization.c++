#include<bits/stdc++.h>
using namespace std;


int solveMem(int n,int x,int y,int z,vector<int> &dp){
	//base case
	if(n == 0)
		return 0;
	
	if(n < 0) 
		return INT_MIN;

	if(dp[n] != -1)
		return dp[n];

	int a = solveMem(n-x,x,y,z,dp) + 1;
	int b = solveMem(n-y,x,y,z,dp) + 1;
	int c = solveMem(n-z,x,y,z,dp) + 1;

	dp[n] = max(a,max(b,c));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1,-1);
	int ans = solveMem(n,x,y,z,dp);
	if(ans < 0)
		return 0;
	else
		return ans;
}

int main(){
    
    int lengthOfRode;
    cout<<"Enter length of rod"<<endl;
    cin>>lengthOfRode;
    
    int x,y,z;
    cout<<"Enter the segment of rod"<<endl;
    cin>>x>>y>>z;
    
    
    int ans = cutSegments(lengthOfRode,x,y,z);
    cout<<"Output ";
    cout<<ans;
    
    return 0;
}