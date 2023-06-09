#include<bits/stdc++.h>
using namespace std;

class Deque{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    Deque(int n){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    bool pushFront(int x){
        if(isFull()){
            return false;
        }else if(isEmpty()){
            front = rear = 0;
        }else if(front == 0 && rear != size-1){
            front = size-1;
        }else{
            front--;   
        }
        arr[front] = x;
        return true;
    }

    bool pushRear(int x){
        if(isFull()){
            return false;
        }else if(isEmpty()){
            front = rear = 0;
        }else if(rear == size-1 && front != 0){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    int popFront(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        }else if(front == rear - 1){
            front = 0;
        }else{
            front++;
        }
        return ans;
    }

    int popRear(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;

        if(front == rear){
            front = rear = -1;
        }else if(rear == 0){
            rear = size-1;
        }else{
            rear--;
        }
        return ans;
    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    int getRear(){
        if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(front == -1)
        return true;
    else
        return false;
    }

    bool isFull(){
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            return true;
        }
        else
        {
            return false;
        }
    }
};

    
int main(){
    Deque q(7);
    cout<<q.isEmpty()<<endl;
    cout<<q.pushFront(10)<<endl;
    cout<<q.pushFront(20)<<endl;
    cout<<q.pushRear(30)<<endl;
    cout<<q.getFront()<<endl;
    cout<<q.popRear()<<endl;
    cout<<q.popRear()<<endl;
    return 0;
}