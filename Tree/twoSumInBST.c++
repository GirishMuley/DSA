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

void inorder(Node* root,vector<int> &in){
    if(root == NULL)
        return;
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

bool twoSumInBST(Node* root, int target) {
	vector<int> inorderVal;
    inorder(root,inorderVal);
    int i=0,j=inorderVal.size()-1;

    while(i<j){
        int sum = inorderVal[i] + inorderVal[j];
        if(sum == target)
            return true;
        else if(sum > target)
            j--;
        else
            i++;
    }
    return false;
}


int main(){
    Node* root = NULL;
    // cout<<"Enter data "<<endl;
    buildFromLevelOrder(root);

    if(twoSumInBST(root,20)){
        cout<<"True";
    }else{
        cout<<"False";
    }

    return 0;
}