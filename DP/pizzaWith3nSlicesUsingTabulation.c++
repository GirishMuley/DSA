#include<bits/stdc++.h>
using namespace std;

    int solve(vector<int>& slices){
        int k = slices.size();

        vector<vector<int>> dp1(k+2,vector<int> (k+2,0));

        vector<vector<int>> dp2(k+2,vector<int> (k+2,0));

        for(int index = k-2; index >= 0; index--){
            for(int n = 1;n<=k/3;n++){
                int take = slices[index] + dp1[index+2][n-1];
                int notTake = 0 + dp1[index+1][n];

                dp1[index][n] = max(take,notTake);
            }
        }
        int case1 = dp1[0][k/3];

        for(int index = k-1; index >= 1; index--){
            for(int n = 1;n<=k/3;n++){
                int take = slices[index] + dp2[index+2][n-1];
                int notTake = 0 + dp2[index+1][n];

                dp2[index][n] = max(take,notTake);
            }
        }
        int case2 = dp2[1][k/3];

        return max(case1,case2);
    }
    int maxSizeSlices(vector<int>& slices) {
        return solve(slices);
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
    
    cout<<"__________________"<<endl;
    
    cout<<maxSizeSlices(vect)<<endl;
    
    return 0;
}