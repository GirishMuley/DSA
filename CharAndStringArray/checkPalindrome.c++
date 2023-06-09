#include<bits/stdc++.h>
using namespace std;

char toLowercase(char ch){
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkSpecial(char ch){
    if(!(ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)){
        return 1;
    }else{
        return 0;  
    }
}

bool isStringPalindrome(vector<char> & vect,int length){
    int start = 0;
    int end = vect.size() - 1;
    while(start<=end){
        if(toLowercase(vect[start]) != toLowercase(vect[end])){
            return 0;
        }else{
            if(checkSpecial(vect[start])){
            start++;
            end--;
            }else{
                return 1;
            }
        }
    }
    return 1;
}

void reverseString(vector<char> &vect,int length){
    int start = 0;
    int end = length - 1;
    
    while(start<end){
        swap(vect[start++],vect[end--]);
    }
}

int getLength(vector<char> &vect){
    int count = 0;
    for(int i=0;vect[i] != '\0';i++){
        count++;
    }
    return count;
}

void print(vector<char> &vect){
    for(int i=0;i<vect.size();i++){
        cout<<vect.at(i);
    }
}

int main(){
    vector<char> vect;
    int size = 15;
    cout<<"Enter your name "<<endl;
    for(int i=0;i<size;i++){
        char data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"Your name is ";
    
    print(vect);
    
    cout<<endl;
    int Length  = getLength(vect);
    cout<<"Length is "<<Length<<endl;
    
    reverseString(vect,Length);
    
    cout<<"Your name is "<<endl;
    print(vect);
    cout<<endl;
    cout<<"string is palindrome or not "<<isStringPalindrome(vect,Length)<<endl;
    
    return 0;
}