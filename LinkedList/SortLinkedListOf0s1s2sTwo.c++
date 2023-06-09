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

// void insertAtTail(Node* &tail,<int> d){
//     //new node create
//     Node* temp = new Node(d);
//     tail -> next = temp;
//     tail = temp;
// }

void insertAtTail(Node* &tail, Node* curr ) {
    tail -> next = curr;
    tail = curr;
}

// void insertAtPosition(Node* &tail,Node* &head,int position,Node* d){
//      if(position == 1){
//         insertAtHead(head,d);
//         return;
//      }
   
//     Node* temp = head;
//     int cnt = 1;

//     while(cnt < position - 1){
//         temp = temp->next;
//         cnt++;
//     }

//     if(temp->next == NULL){
//         insertAtTail(tail,d);
//         return;
//     }
//     //creating n node for d
//     Node* nodeToInsert = new Node(d);
//     nodeToInsert->next = temp->next;
//     temp->next = nodeToInsert;
// }

// void deleteNode(int position,Node* &head,Node* &tail){
//       //deleting first or start node
//       if(position == 1){
//         Node* temp = head;
//         head = head -> next;
//         temp->next = NULL;
//         //memory free start node
//         delete temp;
//       }else{
//         //deleting any middle node or last node
//         Node* curr = head;
//         Node* prev = NULL;

//         int cnt = 1;
//         while(cnt < position){
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }
//         prev -> next = curr -> next;
//         curr -> next = NULL;
//         if(prev->next == NULL){
//             tail = prev;
//         }
//         delete curr;
//       }
// }

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* sortList(Node* head){
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    //create separate list 0s,1s & 2s
    while(curr != NULL){
        int value = curr->data;
        if(value == 0){
            insertAtTail(zeroTail,curr);
        }
        else if(value == 1){
            insertAtTail(oneTail,curr);
        }
        else if(value == 2){
            insertAtTail(twoTail,curr);
        }
        curr = curr->next;
    }

    //merge 3 sublist
    if(oneHead->next != NULL){
        zeroTail->next = oneHead->next;
    }else{
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    //setup head
    head = zeroHead->next;
    return head;
    //delete dummy node
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    
}

int main(){
    
    Node* head = NULL;

    insertAtHead(head,-1);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,2);
    insertAtHead(head,0);
    insertAtHead(head,1);
    print(head);

    Node* res = sortList(head);
    print(res);

    return 0;
}