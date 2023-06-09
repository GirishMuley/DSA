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

int solve(Node* root,int& i,int k){
    //base case
    if(root == NULL){
        return -1;
    }
    //L
    int left = solve(root->left,i,k);

    if(left != -1){
        return left;
    }
    //N
    i++;
    if(i==k)
        return root->data;

    //R 
    return solve(root->right,i,k);
}

int kthSmallest(Node* root, int k) {
    int i=0;
    int ans = solve(root,i,k);
    return ans;
}

int main(){
    Node* root = NULL;
    // cout<<"Enter data "<<endl;
    buildFromLevelOrder(root);

    int result = kthSmallest(root,4);

    cout<<result<<endl;

    return 0;
}