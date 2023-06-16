#include<bits/stdc++.h>
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

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

class compare{
    public:
    bool operator()(Node<int>* a,Node<int>* b){
        return a->data > b->data;
    }
};

Node<int>* mergeKLists(vector<Node<int>*> &listArray)
{
    priority_queue<Node<int>*,vector<Node<int>*>,compare> minHeap;
    int k = listArray.size();
    
    if(k == 0)
    return NULL;
    //step1:
    for(int i=0;i<k;i++){
        if(listArray[i] != NULL)
        {
            minHeap.push(listArray[i]);
        }
    }

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while(minHeap.size() > 0){
        Node<int>* top = minHeap.top();
        minHeap.pop();

        if(top->next != NULL)
        {
            minHeap.push(top->next);
        }

        //LL is empty
        if(head == NULL)
        {
            head = top;
            tail = top;
        }
        else //inset at LL
        {
            tail->next = top;
            tail = top;
        }
    }
    return head;
}


int main(){
    Node* head = NULL;

    int t;
    cin>>t;
    while(t--){
        int value;
        cin>>value;
        if(!value > -1){
            insertAtHead(head,value);
        }else{
            cout<<"Next"<<endl;
        }
    }

    return 0;
}