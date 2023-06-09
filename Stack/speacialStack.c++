#include<bits/stdc++.h>
using namespace std;

class SpecialStack{
    // Define the data members.
    stack<int> s;
    int mini = INT_MAX;

    public:
    void push(int data){
        //for first element
        if(s.empty()){
            s.push(data);
            mini = data;
        }
        else
        {
            if(data < mini){
                s.push(2*data - mini);
                mini = data;
            }
            else
            {
                s.push(data);
            }
        }
    }

    int pop(){
        if(s.empty()){
            return -1;
        }

        int curr = s.top();
        s.pop();
        if(curr > mini){
            return curr;
        }
        else
        {
            int prevMin = mini;
            int val = 2*mini -curr;
            mini = val;
            return prevMin;
        }
    }

    int top(){
        if(s.empty())
        return -1;

        int curr = s.top();
        if(curr < mini){
            return mini;
        }
        else
        {
            return curr;
        }
    }

    bool isEmpty(){
        return s.empty();
    }

    int getMin(){
        if(s.empty()){
            return -1;
        }
        return mini;
    }
};

int main(){
     SpecialStack s;
    
    s.push(3);
    s.push(5);
    cout<<"Minimum Element in the stack is"<<s.getMin()<<endl;
    s.push(2);
    s.push(1);
    cout<<"Minimum Element in the stack is"<<s.getMin()<<endl;
    cout<<"Top Most Element Removed:"<<s.pop()<<endl;
    cout<<"Minimum Element in the stack is"<<s.getMin()<<endl;
    cout<<"Top Most Element Removed:"<<s.pop()<<endl;
    cout<<"Top Most Element is:"<<s.top()<<endl;
  
    return 0;
}