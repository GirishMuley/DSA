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

Node* solve(Node* first,Node* second){
    //if only one element is present in first list
    if(first ->next == NULL){
        first->next = second;
        return first;
    }
    
    Node* curr1 = first;
    Node* next1 = curr1->next;

    Node* curr2 = second;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL){
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)){
            //add node in between the first list
            curr1->next = curr2;
            curr2->next= next1;
            //update pointers
            curr1 = curr2;
            curr2 = next2;
        }else{
            //curr 1 and next1 update
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL){
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

Node* sortTwoList(Node* first,Node* second){
    if(first == NULL)
    return second;

    if(second == NULL)
    return first;

    if(first->data <= second->data){
       return solve(first,second);
    }else{
       return solve(second,first);
    }
}

int main(){
    
    Node* head = NULL;
    Node* head2 = NULL;
    insertAtHead(head,-1);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,1);
    print(head);

    insertAtHead(head2,-1);
    insertAtHead(head2,5);
    insertAtHead(head2,3);
    insertAtHead(head2,2);
    print(head2);

    Node* res = sortTwoList(head,head2);
    print(res);

    return 0;
}