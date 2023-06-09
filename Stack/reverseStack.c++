#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>& stack){
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
}

void insertAtBottom(stack<int>& s,int element){
    //base case
    if(s.empty()){
        s.push(element);
        return;
    }

    int num = s.top();
    s.pop();
    //recursive call

    insertAtBottom(s,element);
    s.push(num);

}

void revserseStack(stack<int>& stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    revserseStack(stack);

    insertAtBottom(stack,num);
    
}

int main(){
    stack<int> myStack;
    myStack.push(2);
    myStack.push(1);
    myStack.push(3);

    revserseStack(myStack);

    print(myStack);

    return 0;
}