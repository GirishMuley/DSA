#include<bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int> &q){
    // To check the even number of elements
    if (q.size() % 2 != 0)
        cout << "Input even number of integers." << endl;
        
    // Initialize an empty stack of int type
    stack<int> s;
    int halfSize = q.size()/2;
    
    // Push first half elements into the stack
    for(int i = 0;i < halfSize;i++){
        s.push(q.front());
        q.pop();
    }
    
    // enqueue back the stack elements
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    
    // dequeue the first half elements of queue
    // and enqueue them back
    for(int i=0;i<halfSize;i++){
        q.push(q.front());
        q.pop();
    }
    
    // Again push the first half elements into the stack
    for(int i=0;i<halfSize;i++){
        s.push(q.front());
        q.pop();
    }
    
    // interleave the elements of queue and stack
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
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