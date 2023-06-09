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


Node* insertIntoBST(Node* &root,int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }
    if(d > root->data){
        //insert into right part
        root->right = insertIntoBST(root->right,d);
    }
    else
    {
        //insert into left part
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        insertIntoBST(root,data);
        cin>>data;
    }
}

bool searchInBST(Node* &root,int x){
    Node* temp = root;

    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        if(temp->data > x){
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }
    return false;
}

int main(){
    Node* root = NULL;

    cout<<"Enter data to create BST"<<endl;
    takeInput(root);

    cout<<"Printng the BST"<<endl;
    levelOrderTraversal(root);

    if(searchInBST(root,99)){
        cout<<"Present"<<endl;
    }else{
        cout<<"Absent"<<endl;
    }
    return 0;
}