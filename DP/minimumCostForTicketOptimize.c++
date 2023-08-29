#include<bits/stdc++.h>
using namespace std;

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;
    
    queue<pair<int,int>> month;
    queue<pair<int,int>> week;
    
    for(int day:days){
        //step1 : remove expired days
        while(!month.empty() && month.front().first + 30 <= day)
        month.pop();

        while(!week.empty() && week.front().first + 7 <= day)
        week.pop();

        //step 2 add cost for current day
        week.push(make_pair(day,ans+cost[1]));
        month.push(make_pair(day,ans+cost[2]));
        
        //step3 ans update
        ans = min(ans+cost[0],min(week.front().second,month.front().second));
    }
    return ans;
}

int main(){
    int days;
    cout<<"Enter no of days"<<endl;
    cin>>days;
    
    cout<<"Enter days"<<endl;
    vector<int> vectDays;
    for(int i=0;i<days;i++){
        int data;
        cin>>data;
        vectDays.push_back(data);
    }
    
    cout<<"Enter cost"<<endl;
    vector<int> vectCost;
    for(int i=0;i<3;i++){
        int data;
        cin>>data;
        vectCost.push_back(data);
    }
    
    cout<<minimumCoins(days,vectDays,vectCost)<<endl;
    
    return  0;
}