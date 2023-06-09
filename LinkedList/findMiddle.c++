#include<iostream>
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
        while(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtHead(Node* &head,int d){
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

void insertAtPosition(Node* &head,Node* &tail,int position,int d){
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
    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position,Node* &head,Node* &tail){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }else{
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

int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head -> next;
    }
    return len;
}

Node* findMiddle(Node *head){
    int len = getLength(head);
    int ans = (len/2);
    
    Node* temp = head;
    int cnt = 0;
    while(cnt <  ans){
        temp = temp -> next;
        cnt++;
    }
    return temp;
}

int main(){
    Node* node = new Node(5);
    Node* head = node;
    Node* tail = node;
    
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    
    Node* res = findMiddle(head);
    cout<<"Middle is = "<<res->data<<endl;
    
    return 0;
}