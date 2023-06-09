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

vector<int> mergeArrays(vector<int> &a,vector<int> &b){
    vector<int> ans(a.size() + b.size());
    int i=0,j=0;
    int k=0;
    while(i<a.size() && j<b.size()){
        if(a[i] < b[j]){
            ans[k++] = a[i];
            i++;
        }else{
            ans[k++] = b[j];
            j++;
        }
    }

    while(i<a.size()){
        ans[k++] = a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++] = b[j];
        j++;
    }
    return ans;
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

Node* mergeBST(Node *root1,Node *root2){
    //step 1: store inorder
    vector<int> bst1,bst2;
    inorder(root1,bst1);
    inorder(root2,bst2);
    //step 2:merge both sorted arrays
    vector<int> mergeArray = mergeArrays(bst1,bst2);
    //step 3: use merged inorder array to build BST
    int s = 0,e = mergeArray.size() - 1;
    return inorderToBST(s,e,mergeArray);
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