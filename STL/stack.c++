#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> str;

    str.push("Full");
    str.push("stack");
    str.push("Developer");

    cout<<"Element at top = "<<str.top()<<endl;
    str.pop();
    cout<<"Element at top = "<<str.top()<<endl;

    cout<<"size of stack ="<<str.size()<<endl;

    cout<<"Empty or not = "<<str.empty()<<endl;

    return 0;
}