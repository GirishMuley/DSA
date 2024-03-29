#include<bits/stdc++.h>
using namespace std;


int solve(int n,int x,int y,int z){
	//base case
	if(n == 0)
		return 0;
	
	if(n < 0) 
		return INT_MIN;

	int a = solve(n-x,x,y,z) + 1;
	int b = solve(n-y,x,y,z) + 1;
	int c = solve(n-z,x,y,z) + 1;

	int ans = max(a,max(b,c));
	return ans;
}

int cutSegments(int n, int x, int y, int z) {
	int ans = solve(n,x,y,z);
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