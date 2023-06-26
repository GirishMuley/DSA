#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
        TrieNode* root;

        Trie(char ch){
            root = new TrieNode(ch);
        }

    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        //present 
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
        {
            //absent 
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }
        //recursion
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }

    void lcp(string str,string &ans){
        for(int i=0;i<str.length();i++){
            char ch = str[i];

            if(root->childCount == 1){
                ans.push_back(ch);
                //move forward
                int index = ch - 'a';
                root = root->children[index];
            }
            else
            {
                break;
            }
            if(root->isTerminal)
            break;
        }
    }
};
string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie *t = new Trie('\0');
    //insert all string into trie
    for(int i=0;i<n;i++){
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";

    t->lcp(first,ans);
    // cout<<ans<<endl;
    return ans;
    
}


int main(){
    
    vector<string> str{"code","coding"};

    int size  = str.size();
    

    // int size;
    // cout<<"Enter size"<<endl;
    // cin>>size;
    // cout<<"Enter strings"<<endl;
    // for(int i=0;i<=size;i++){
        
    //     string data;
    //     getline(cin, data);
    //     str.push_back(data);
    // }
    
    
    string output = longestCommonPrefix(str,size);
    
    // longestCommonPrefix(str,size);
    
    cout<<"Output"<<endl<<output<<endl;
    
    
    return 0;
}