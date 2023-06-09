#include<iostream>
#include<map>
using namespace std;
int main(){
    map<int,string> m;

    m[1]="Girish";
    m[13]="Muley";
    m[5]="Developer";

    m.insert({3,"jack"});

    cout<<"Before erase "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    cout<<"finding 13 = "<<m.count(13)<<endl;

    m.erase(3);

    cout<<"after erase "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    cout<<endl;

    auto it = m.find(5);
    for(auto i=it;it!=m.end();it++){
        cout<<(*i).first<<endl;
    }
    return 0;
}