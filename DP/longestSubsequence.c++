//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int solve(int n,int a[],int curr,int prev){
        //base case
        if(curr == n){
            return 0;
        }
        
        //include
        int take = 0;
        if(prev == -1 || a[curr] > a[prev])
            take = 1 + solve(n,a,curr+1,curr);
            
        //exclude
        int notTake = 0 + solve(n,a,curr+1,prev);
        return max(take,notTake);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       return solve(n,a,0,-1);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends