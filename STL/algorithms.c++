#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;

    vec.push_back(1);
    vec.push_back(3);
    vec.push_back(6);
    vec.push_back(7);

    cout<<"finding 6 = "<<binary_search(vec.begin(),vec.end(),6)<<endl;
    
    cout<<"lower bound = "<<lower_bound(vec.begin(),vec.end(),6)-vec.begin()<<endl;
    cout<<"upper bound = "<<upper_bound(vec.begin(),vec.end(),4)-vec.begin()<<endl;

    int a = 3;
    int b = 5;

    cout<<"max = "<<max(a,b)<<endl;
    cout<<"min = "<<min(a,b)<<endl;

    swap(a,b);
    cout<<a<<b<<endl;

    string str = "abcd";
    reverse(str.begin(),str.end());
    cout<<"string = "<<str<<endl;
    
    for(int i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
    rotate(vec.begin(),vec.begin()+1,vec.end());
    cout<<"after rotate = "<<endl;
    for(int i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
    
    sort(vec.begin(),vec.end());
    for(int i: vec){
        cout<<i<<" ";
    }
    cout<<endl;
    
    return 0;
}