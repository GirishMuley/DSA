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
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* Kreverse(Node* head,int k){
    //base case
    if(head == NULL){
        return NULL;
    }

    //STEP 1 revserse firts k steps
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //STEP 2 Recursion 
    if(next != NULL){
        head->next = Kreverse(next,k);
    }
    //STEP 3 return head of reversed list
    return prev;
}


int main(){
    Node* head = NULL;
    insertAtHead(head,-1);
    insertAtHead(head,6);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    print(head);
    
    Node* result = Kreverse(head,2);
    print(result);

    return 0;
}