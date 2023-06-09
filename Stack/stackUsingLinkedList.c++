#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  
  Node(int data){
      this->data = data;
      this->next = NULL;
  }
  
  ~Node(){
      int value = this->data;
      if(this->next != NULL){
          delete next;
          this->next = NULL;
      }
      cout<<"Memory is free for node with data"<<value<<endl;
  }
};

void push(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}



bool isEmpty(Node* &head){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

void pop(Node* &head){
    Node* temp;
    if(isEmpty(head)){
        cout<<"Stack is empty"<<endl;
    }
    else{
        temp = head;
        head = head->next;
        free(temp);
    }
}

int peek(Node* &head){
    if(head == NULL){
        cout<<"Stack is empty"<<endl;
    }else{
        head->data;
    }
    return head->data;
}



void print(Node* &head){
    Node* curr = head;
    if(isEmpty(curr)){
        cout<<"Stack is empty "<<endl;
    }else{
     while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;   
    }
}


int main(){
    Node* head = NULL;
    push(head,5);
    push(head,3);
    push(head,6);
    print(head);
    
    int ans = peek(head);
    cout<<"Top: "<<ans<<endl;
    
    pop(head);
    print(head);
    
    int ans2 = peek(head);
    cout<<"Top: "<<ans2<<endl;
    
    
    
    return 0;
}