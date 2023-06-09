// #include<iostream>
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
      char data;
      TrieNode* children[26];
      bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        //base case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assumption , word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
        {
            //absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        //recursion
        insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }


    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else
        {
            //absent
            return false;
        }
        //recursion
        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word) ;
    }
    
    bool trieEmpty(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i]){
                return false;
            }
        }
        return true;
    }
    
    
    TrieNode* deleteWordUtil(TrieNode* root,string word,int height=0){
        
        //empty or Not
        if(!root){
            return NULL;
        }
        // cout<<"Inside deleteWord"<<endl;
        
        if(height == word.size()){
            cout<<word.size()<<endl;
            if(root->isTerminal){
                root->isTerminal = false;
            }
            if(trieEmpty(root)){
                delete(root);
                root = NULL;
            }
            return root;
        }
        
        int index = word[height] - 'A';
        root->children[index] = deleteWordUtil(root->children[index],word,height + 1);
        
        if(trieEmpty(root) && root->isTerminal ==false){
            delete(root);
            root = NULL;
        }
        return root;
    }
    
    void deleteWord(string word){
        deleteWordUtil(root,word);
    }
};

int main(){
    TrieNode* root;
    Trie *t = new Trie();

    t->insertWord("abcd");
    
    
    cout<<"Present or Not "<<t->searchWord("abcd")<<endl;
    
    t->deleteWord("abcd");
    
    cout<<"Present or Not "<<t->searchWord("abcd")<<endl;
    
     
    return 0;
}