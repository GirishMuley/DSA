#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> ms;

    ms.insert(1);
    ms.insert(1);
    ms.insert(1);
    ms.insert(2);
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<endl;

    
    cout<<"count = "<<ms.count(1)<<endl;
    
    ms.erase(ms.find(1),ms.find(1)+2);
    cout<<"After erase"<<endl;
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<endl;

    ms.erase(ms.find(1));
    cout<<"After erase"<<endl;
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<endl;

    ms.erase(1);
    cout<<"After erase"<<endl;
    for(auto i:ms){
        cout<<i<<" ";
    }
    cout<<endl;


    return 0;
}