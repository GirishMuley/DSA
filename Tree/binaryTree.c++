#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree(node* root){
    cout<<"Enter the data:"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //old or last  level completely traverse
            cout<<endl;
            if(!q.empty()){
                //queue still have some child nodes
                q.push(NULL);
            }
        }
        else{
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

void reverseOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    //q.push(NULL);
    stack<node*> s;
    while(!q.empty()){
        node* temp=q.front();
        s.push(temp);
        q.pop();
        if(temp==NULL){
            if(!q.empty()){
                q.push(NULL);
            }
        }
    else{
     if(temp->left){
            q.push(temp->left);
        }
        
         if(temp->right){
            q.push(temp->right);
        }
}
        
        
    }
    
    while(!s.empty()){
        
        node* temp=s.top();
        s.pop();
        if(temp==NULL){
            cout<<endl;
            
        }
        else{
            cout<<temp->data<<" ";
        }
        
        
    }
}

//or second code

// vector<int> reverseLevelOrder(Node *root)
// { queue<Node*> q;  q.push(root); 
//   vector<int> ans; 
//   while(!q.empty())
//   {   Node *temp = q.front(); q.pop();
//       ans.push_back(temp->data);
//       if(temp->right) q.push(temp->right);
//       if(temp->left) q.push(temp->left);  }
//   reverse(ans.begin(),ans.end());
//   return ans; }

void inorderItration(node* root){
    stack<node*> s;
    node* curr = root;

    while(curr != NULL || s.empty() == false){
        //reach the left most node of the curr ndoe
        while(curr != NULL){
            //place pointer to a tree node on the stack before traversing the node left subtree
            s.push(curr);
            curr = curr->left;
        }
        //curr must be null at this point
        curr = s.top();
        s.pop();
        cout<<curr->data<<" ";

        //we have visited the node and its left subtree. now its right subtree turn
        curr = curr->right;
    }
}

void inorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


void preorderItrative(node* root){
    if(root == NULL) return;
    stack<node*> s;

    //start from root node (set curr node to root node)
    node* curr = root;

    //run till the stack is not empty
    while(!s.empty() || curr != NULL){
        //print left children while exist
        //and keep pushing right into the stack
        while(curr != NULL) {
            cout<<curr->data<<" ";

            if(curr->right) s.push(curr->right);
            curr = curr->left;
        }
        //when curr is NULL
        //so we take out right child from stack
        if(!s.empty()){
            curr = s.top();
            s.pop();
        }
    }
}

void preorder(node* root){
    //base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

// vector<int> postorderItrative(node* root){
//     vector<int> postOrderList;
//     stack<node*> s;
//     while(true){
//         while(root){
//             s.push(root);
//             s.push(root);
//             root = root->left;
//         }
//         if(s.empty()) return postOrderList;
//         root = s.top();
//         s.pop();
//         if(!s.empty() && s.top() == root){
//             root = root->right;
//         }else{
//             postOrderList.push_back(root->data);
//             root = NULL;
//         }
//     }
//     return postOrderList;
// }

void postorderItrative(node* root){
    stack<node*> s;
    while(true){
        while(root){
            s.push(root);
            s.push(root);
            root = root->left;
        }
        if(s.empty()) return;
        root = s.top();
        s.pop();
        if(!s.empty() && s.top() == root){
            root = root->right;
        }else{
            cout<<root->data<<" ";
            root = NULL;
        }
    }
}

void postorder(node* root){
    //base case
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }
int main(){
    node* root = NULL;

    // buildFromLevelOrder(root);
    // levelOrderTraversal(root);
    // reverseOrderTraversal(root);
    // // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    // //creating a tree
    root = buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    // //level order
    // cout << "Printing the level order tracersal output " << endl;
    // levelOrderTraversal(root);

    // cout<<"inorder traversal is: "<<endl;
    // inorder(root);
    // cout<<endl;
    // cout<<"inorder traversal using itrative"<<endl;
    // inorderItration(root);

    // cout << endl << "preorder traversal is:  ";
    // preorder(root);
    // cout<<endl;
    // cout<<"preorder itrative traversal is: ";
    // preorderItrative(root);
    cout << endl << "postorder traversal is:  ";
    postorder(root); 

    // cout << endl << "postorder itrative traversal is:  ";
    // vector<int> result = postorderItrative(root);
    // for(int i=0;i<result.size();i++){
    //     cout<<result.at(i)<<" ";
    // }

    cout << endl << "postorder itrative traversal is:  ";
    postorderItrative(root);
    
    return 0;
}