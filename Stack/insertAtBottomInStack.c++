#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>& s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

void solve(stack<int>& s,int x){
    //base case
    if(s.empty()){
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    //recursive call
    solve(s,x);
    s.push(num);

}

void pushAtBottom(stack<int>& myStack,int x){
    solve(myStack,x);
    print(myStack);
}

int main(){
    int value;
    stack<int> myStack;
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    
    cout<<"Enter Value"<<endl;
    cin>>value;
    cout<<endl;

    // stack<int> result = pushAtBottom(myStack,value);
    pushAtBottom(myStack,value);

    // while(!result.empty()){
    //     cout<<result.top()<<" ";
    //     result.pop();
    // }
    // print(result);
    return 0;
}