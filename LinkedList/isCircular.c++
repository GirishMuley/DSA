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
};

void insertAtHead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* head){
    if(head == NULL){
        cout<<"List is empty"<<endl;
    }
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertNode(Node* &tail,int element,int d){
    //empty list
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }else{
        //non-empty
        //assuming that the element is present in the list
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }
        //element found -> curr is representing element node
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

bool  isCircularList(Node* head){
    //empty list
    if(head == NULL){
        return true;
    }

    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }
    return false;
}

int main(){
    // Node* head = NULL;
    Node* tail = NULL;
   // insertAtHead(head,1);
   insertNode(tail,1,1);
    print(tail);
    
    if(isCircularList(tail)){
        cout<<"Linked List is Circular in nature "<<endl;
    }else{
        cout<<"Linked List is not circular"<<endl;
    }
    return 0;
}