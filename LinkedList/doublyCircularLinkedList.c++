#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    //constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    
    //destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"Memory is free for node with data "<<value<<endl;
    }
};

void print(Node* head){
    Node* temp = head;

    if(head == NULL){
        cout<<"List is empty"<<endl;
    }

    do{
        cout<<head->data<<" ";
        head = head->next;
    }while(head != temp);
    cout<<endl;
}

void insertAtHead(Node* &head,Node* &tail,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = tail = temp;
        temp->prev = tail;
        temp->next = head;
    }else{
        Node * temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        temp->prev = tail;
        tail->next = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head,Node* &tail,int d){
    if(head == NULL){
        Node* temp = new Node(d);
        temp->prev = tail;
        temp->next = head;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        temp->next = head;
        head->prev = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
    //insert at start
    if(position == 1){
        insertAtHead(head,tail,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;
    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }
    //insert at end
    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->prev = temp;
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail,int position){
    
    if(position == 1){
        Node* temp = head;
        temp->next->prev = NULL;
        temp->next->prev = temp->prev;
        head = temp->next;
        tail->next = head;        
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        // Node* prev = NULL;
        int cnt = 1;
        while(cnt < position){
            curr=curr->next;
            cnt++;
        }
        curr->prev->next =curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head,tail,1);
    print(head);
    
    insertAtHead(head,tail,2);
    print(head);

    insertAtTail(head,tail,5);
    print(head);

    insertAtPosition(head,tail,3,4);
    print(head);

    deleteNode(head,tail,1);
    print(head);
    
    deleteNode(head,tail,2);
    print(head);

    deleteNode(head,tail,2);
    print(head);
    return 0;
}