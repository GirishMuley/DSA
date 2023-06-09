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


void inorder(Node* root,vector<int> &in){
    if(root == NULL)
        return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node* inorderToBST(int s,int e,vector<int> &in){
    //base case
    if(s>e)
    return NULL;

    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = inorderToBST(s, mid-1,in);
    root->right = inorderToBST(mid+1,e,in);
    return root;
}

Node* balancedBst(Node* root) {
    vector<int> inorderVal;
    inorder(root,inorderVal);
    return inorderToBST(0,inorderVal.size()-1,inorderVal);
}



int main(){
    Node* root = NULL;
    // cout<<"Enter data "<<endl;
    buildFromLevelOrder(root);

    Node* result = balancedBst(root);

    levelOrderTraversal(result);
    
    return 0;
}