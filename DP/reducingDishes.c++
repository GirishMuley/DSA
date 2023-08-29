#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& satisfaction,int index,int time){
        //base case
        if(index == satisfaction.size())
            return 0;

        int include = satisfaction[index] * (time + 1) + solve(satisfaction,index + 1,time + 1);
        int exclude = 0 + solve(satisfaction,index + 1,time);
        return max(include,exclude);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        return solve(satisfaction,0,0);
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