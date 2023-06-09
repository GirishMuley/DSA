#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    
//constructor
Node(int data){
    this->data = data;
    this->next = NULL;
    this->child = NULL;
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
        n = n->child;
    }
    cout<< endl;
}

Node* push(Node* &head_ref, int data)
{

	// Allocate the Node & Put in the data
	Node* new_node = new Node(data);

	new_node->data = data;
	new_node->next = NULL;

	// Make next of new Node as head
	new_node->child = head_ref;

	// Move the head to point to new Node
	head_ref = new_node;

	return head_ref;
}



Node* merge(Node* down,Node* right){
	if(down == NULL)
	return right;

	if(right == NULL)
	return down;

	Node* ans = new Node(-1);
	Node* temp = ans;

	while(down != NULL && right != NULL){
		if(down->data < right->data){
			temp->child = down;
			temp = down;
			down = down->child; 
		}else{
			temp->child = right;
			temp = right;
			right= right->child;
		}
	}

	if(down != NULL){
		temp->child = down;
		temp = down;
		down = down->child; 
	}
	if(right != NULL){
		temp->child = right;
		temp = right;
		right= right->child;
	}
	return ans->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL){
		return head;
	}
	Node* down = head;
	Node* right = head->next;
	down->next = NULL;
	right = flattenLinkedList(right);
	
	Node* ans = merge(down,right);
	return ans;
}

int main(){
    Node* head = NULL;
    
    push(head, 30);
	push(head, 8);
	push(head, 7);
	push(head, 5);

	push(head->next, 20);
	push(head->next, 10);

	push(head->next->next, 50);
	push(head->next->next, 22);
	push(head->next->next, 19);

	
	push(head->next->next->next, 45);
	push(head->next->next->next, 40);
	push(head->next->next->next, 35);
	push(head->next->next->next, 20);

	// Function call
	Node* answer = flattenLinkedList(head);

	printList(answer);
	return 0;

}