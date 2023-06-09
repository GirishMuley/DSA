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


Node* solve(vector<int> &preorder,int mini,int maxi,int &i){
    if(i >= preorder.size())
        return NULL;

    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    Node* root = new Node(preorder[i++]);
    root->left = solve(preorder,mini,root->data,i);
    root->right = solve(preorder,root->data,maxi,i);
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i=0;
    return solve(preorder,mini,maxi,i);
}


int main(){
    // Node* root = NULL;
    // // cout<<"Enter data "<<endl;
    // buildFromLevelOrder(root);
    int size;
    cin>>size;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }

    Node* result = preorderToBST(vect);

    levelOrderTraversal(result);
    
    return 0;
}