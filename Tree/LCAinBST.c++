#include<bits/stdc++.h>
#include<climits>
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

Node* LCAinBST(Node* root,int P,int Q){
    while(root != NULL){
        if(root->data < P && root->data < Q){
            root = root->right;
        }else if(root->data > P && root->data > Q){
            root = root->left;
        }else{
            return root;
        }
    }
}

int main(){
    Node* root = NULL;
    // cout<<"Enter data "<<endl;
    buildFromLevelOrder(root);

    Node* ans  = LCAinBST(root,3,5);
    
    cout<<ans->data<<endl;

    return 0;
}