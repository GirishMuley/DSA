#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    
    Node(int d){
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,Node* &tail,int d){
    
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }else{
        Node* temp = new Node(d);
        temp->next = head;
        temp->prev = temp;
        head = temp;
    }
}

void reverse(Node* &head,Node* &tail){
    if(head == NULL || head->next == NULL){
        return;
    }
    Node* prevNode = head;
    Node* tempNode = head;
    Node* curNode = head->next;
    
    
    prevNode->next = NULL;
    prevNode->prev = NULL;

    while(curNode != NULL) {
      tempNode = curNode->next;
      curNode->next = prevNode;
      prevNode->prev = curNode;
      prevNode = curNode;
      curNode = tempNode;
    }
    
    head = prevNode;
  }

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,1);
    print(head);

    insertAtHead(head,tail,2);
    print(head);

    insertAtHead(head,tail,3);
    print(head);

    insertAtHead(head,tail,4);
    print(head);

    insertAtHead(head,tail,5);
    print(head);
    
    reverse(head,tail);
    print(head);
    return 0;
}