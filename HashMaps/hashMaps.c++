#include<bits/stdc++.h>
using namespace  std;

int main(){
    //creattion
    unordered_map<string,int> m;
    
    //insertion
    // 1
    pair<string,int> p = make_pair("Girish",3);
    m.insert(p);

    // 2
    pair<string,int> pair("Muley",2);
    m.insert(pair);

    //3
    m["mera"] = 1;
    m["mera"] = 2;

    //search
    cout<<m["mera"]<<endl;
    cout<<m.at("Girish")<<endl;

    // cout<<m.at("unknow")<<endl; check this out
    cout<<m["unknow"]<<endl;
    cout<<m.at("unknow")<<endl;

    //size
    cout<<m.size()<<endl;

    //check presence
    cout<<m.count("bro")<<endl;
    cout<<m.count("Girish")<<endl;

    //erase
    m.erase("mera");
    cout<<m.size()<<endl;

    //iterator
    unordered_map<string,int> :: iterator it = m.begin();

    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    
    return 0;
}