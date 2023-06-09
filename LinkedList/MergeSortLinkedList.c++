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

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left,Node* right){
    if(left == NULL)
    return right;

    if(right == NULL)
    return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    //merge 2 sorted linked list
    while(left != NULL && right != NULL){
        if(left->data < right->data){
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL){
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL){
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans = ans->next;
    return ans;
}

Node* mergeSort(Node* head){
    //base case
    if(head == NULL || head->next == NULL){
        return head;
    }
    //break linked list into 2 halves, after finding mid
    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    //recursive call to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    //merge both left and right halves
    Node* result = merge(left,right);

    return result;
}

int main(){
    
    Node* head = NULL;

    insertAtHead(head,-1);
    insertAtHead(head,2);
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,1);
    print(head);
    
    Node* answer = mergeSort(head);
    printList(answer);

    return 0;
}