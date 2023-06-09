#include<iostream>
#include<stack>
using namespace std;

void print(stack<int>& stack){
    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
}

void sortInsert(stack<int>& stack,int num){
    //base case
    if(stack.empty() || (!stack.empty() && stack.top() < num)){
        stack.push(num);
        return;
    }

    int n = stack.top();
    stack.pop();

    //recursive call
    sortInsert(stack,num);
    stack.push(n);
}

void sortStack(stack<int>& stack){
    //base case
    if(stack.empty()){
        return;
    }

    int num = stack.top();
    stack.pop();

    //recursive call
    sortStack(stack);
    sortInsert(stack,num);
}

int main(){
    stack<int> myStack;
    myStack.push(5);
    myStack.push(-2);
    myStack.push(9);
    myStack.push(-7);
    myStack.push(3);

    sortStack(myStack);

    print(myStack);

    return 0;
}