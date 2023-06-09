#include<iostream>
#include<deque>
using namespace std;

int main(){

    deque<int> de;
    deque<int> de2;

    de.push_back(1);
    de.push_back(3);
    de.push_front(2);

    de2.push_back(1);
    de2.push_back(3);
    de2.push_front(2);


    for(int i:de){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"After pop_back"<<endl;
    de.pop_back();
    for(int i:de){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"After pop_front"<<endl;
    de.pop_front();
    for(int i:de){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"element at 2nd index = "<<de2.at(2)<<endl;

    cout<<"front ="<<de2.front()<<endl;
    cout<<"back = "<<de2.back()<<endl;

    cout<<"empty or not"<<de2.empty()<<endl;

    cout<<"before erase"<<de2.size()<<endl;
    de2.erase(de2.begin(),de2.begin()+1);
    cout<<"after erase"<<de2.size()<<endl;
    for(int i:de2){
        cout<<i<<" ";
    }
    return 0;
}