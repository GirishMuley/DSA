#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& satisfaction){
        int n = satisfaction.size();
        vector<int> curr(n+1,0);
        vector<int> next(n+1,0);


        for(int index = n-1;index>=0;index--){
            for(int time = index;time>=0;time--){
                int include = satisfaction[index] * (time+1) + next[time+1];
                int exclude = 0 + next[time];
                curr[time] = max(include,exclude);
            }
            next = curr;
        }
        return next[0];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction);
    }
    
int main(){
    int dishes;
    cout<<"Enter no of dishes"<<endl;
    cin>>dishes;
    
    cout<<"Enter dishes"<<endl;
    vector<int> vect;
    for(int i=0;i<dishes;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"__________________"<<endl;
    
    cout<<maxSatisfaction(vect)<<endl;
    
    return 0;
}