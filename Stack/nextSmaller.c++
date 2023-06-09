#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> &vect){
    for(int i=0;i<vect.size();i++){
        cout<<vect.at(i)<<" ";
    }
}

vector<int> nextSmallerElement(vector<int>& arr,int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for(int i = n-1;i >= 0;i--){
        int curr = arr[i];
        while(s.top() >= curr){
            s.pop();
        }
        //ans is stack top
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;
}

int main(){
    int size;
    cout<<"Enter size"<<endl;
    cin>>size;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    vector<int> result = nextSmallerElement(vect,size);
    
    printArray(result);

    return 0;
}