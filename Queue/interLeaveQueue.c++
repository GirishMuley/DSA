#include<bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q){
    queue<int> newQ;
    
    //divide into two parts
    int n = q.size()/2;
    
    //step : 1 fetch first half element from input queue and push int newQ
    for(int i=0;i<n;i++){
        int val = q.front();
        q.pop();
        newQ.push(val);
    }
    
    //step : 2 push alternate element in input queue itself
    while(!newQ.empty()){
        int val = newQ.front();
        newQ.pop();
        q.push(val);
        
        val = q.front();
        q.pop();
        q.push(val);
    }
}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);
    interLeaveQueue(q);
    
    //print
    int length = q.size();
    for(int i=0;i<length;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}