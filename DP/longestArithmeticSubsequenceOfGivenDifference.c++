#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            int temp = arr[i] - difference;
            int tempAns = 0;

            //check answer exisit for temp already or not
            if(dp.count(temp))
             tempAns = dp[temp];

            //current answer update
            dp[arr[i]] = 1 + tempAns;

            //ans update
            ans = max(ans,dp[arr[i]]);
        }
        return ans;
    }

int main(){
    int size;
    cout<<"Enter size"<<endl;
    cin>>size;
    
    cout<<"Enter elements"<<endl;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    int diff;
    cout<<"Enter difference"<<endl;
    cin>>diff;
    
    cout<<"____________________"<<endl;
    
    cout<<longestSubsequence(vect,diff)<<endl;
    
    return 0;
}