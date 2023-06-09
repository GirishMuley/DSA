#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    
//constructor
Node(int data){
    this->data = data;
    this->next = NULL;
}
 
//destructor
~Node(){
    int value =this->data;
    //memory free
    if(this->next != NULL){
        delete next;
        this->next = NULL;
    }
    cout<<"Memory is free for node with data"<<value<<endl;
}
};

void insertAtHead(Node* &head,int d){
    //new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail,int d){
    //new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = temp;
}

void insertAtPosition(Node* &tail,Node* &head,int position,int d){
     if(position == 1){
        insertAtHead(head,d);
        return;
     }
   
    Node* temp = head;
    int cnt = 1;

    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(tail,d);
        return;
    }
    //creating n node for d
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position,Node* &head,Node* &tail){
      //deleting first or start node
      if(position == 1){
        Node* temp = head;
        head = head -> next;
        temp->next = NULL;
        //memory free start node
        delete temp;
      }else{
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        curr -> next = NULL;
        if(prev->next == NULL){
            tail = prev;
        }
        delete curr;
      }
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* removeDuplicates(Node* head){
   if(head == NULL){
        return NULL;
    }
    Node* curr = head;
    while(curr != NULL){
        Node* temp = curr->next;
        Node* prev = curr;
        while(temp != NULL){
            if(curr->data == temp->data){
            prev->next = temp->next;
            delete(temp);
            temp = prev->next;
           }else{
               prev = temp;
               temp = temp->next;
           }
        }
        curr = curr->next;
    }
    return head;
}

int main(){
    Node* head = NULL;
    insertAtHead(head,-1);
    insertAtHead(head,2);
    insertAtHead(head,2);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,2);
    insertAtHead(head,4);
    print(head);

    Node* result = removeDuplicates(head);
    print(result);
    return 0;
}