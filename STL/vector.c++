#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    vector<int> vec2(5,1);
    for(int i:vec2){
        cout<<i<<" ";
    }
    cout<<endl;
    vector<int> last(vec2);
    for(int i:last){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"capacity = "<<vec.capacity()<<endl;

    vec.push_back(1);
    cout<<"capacity = "<<vec.capacity()<<endl;

    vec.push_back(2);
    cout<<"capacity = "<<vec.capacity()<<endl;

    vec.push_back(3);
    cout<<"capacity = "<<vec.capacity()<<endl;
    cout<<"size = "<<vec.size()<<endl;

    cout<<"Element at 2nd index = "<<vec.at(2)<<endl;
    cout<<"front = "<<vec.front()<<endl;
    cout<<"back = "<<vec.back()<<endl;

    cout<<"Before pop "<<endl;
    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    
    vec.pop_back();

    cout<<"After pop"<<endl;
    for(int i:vec){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"before clear size = "<<vec.size()<<endl;
    vec.clear();
    cout<<"After clear size = "<<vec.size()<<endl;
    return 0;
}