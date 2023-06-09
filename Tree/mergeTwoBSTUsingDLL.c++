#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void buildFromLevelOrder(Node* &root) {
    queue<Node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new Node(data);
    
    q.push(root);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
 }

 void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //odd or last level completely traverse
            cout<<endl;
            if(!q.empty()){
                //queue still have some child nodes
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


TreeNode<int> convertIntoSortedDLL(TreeNode<int> *root,TreeNode<int> &head){
    //base case
    if(root == NULL)
    return NULL;

    convertIntoSortedDLL(root->right,head);
    root->right = head;
    if(head != NULL)
        head->left = root;

    head = root;

    convertIntoSortedDLL(root->left,head);
}

TreeNode<int> mergeLinkedList(TreeNode<int> *head1,TreeNode<int> *head2){
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data)
        {
            if(head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }else
        {
            if(head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            } else {
              tail->right = head2;
              head2->left = tail;
              tail = head2;
              head2 = head2->right;
            }
        }
    }
    while(head1 != NULL){
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;        
    }
    while(head2 != NULL){
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}

int countNodes(TreeNode<int> *head){
    int cnt = 0;
    TreeNode<int> *temp = head;
    while(temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head,int n){
    //base case
    if(n <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode<int> *left = sortedLLToBST(head,n/2);
    TreeNode<int> *root = head;
    root->left = left;
    head = head->next;
    root->right = sortedLLToBST(head,n-n/2-1);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    
    //step1: convert BST into sorted DLL in-place
    TreeNode<int> *head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head1->left = NULL;

    //step2: merge sorted linked list
    TreeNode<int> *head = mergeLinkedList(head1, head2);

    //step3: convert SLL into BST
    return sortedLLToBST(head,countNodes(head));
}

int main(){
    Node* root1 = NULL;
    Node* root2 = NULL;
    // cout<<"Enter data "<<endl;
    buildFromLevelOrder(root1);
    buildFromLevelOrder(root2);

    Node* result = mergeBST(root1,root2);

    levelOrderTraversal(result);
    
    return 0;
}