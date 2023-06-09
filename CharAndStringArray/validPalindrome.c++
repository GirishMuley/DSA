#include<bits/stdc++.h>
using namespace std;

bool valid(char ch){
    if((ch>='a' && ch<='z')||(ch>='A'&& ch<='Z')||(ch>='0' && ch<='9')){
        return 1;
    }
    return 0;
}

char toLowerCase(char ch){
    if((ch>='a' && ch<='z')||(ch>='0' && ch<='9')){
        return ch;
    }else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(string vect){
    int start = 0;
    int end = vect.length() - 1;
    while(start<=end){
        if(vect[start] != vect[end]){
            return 0;
        }else{
            start++;
            end--;
        }
    }
    return 1;
}

bool isPalindrome(string vect){
    string temp = "";
    for(int i=0;vect.length();i++){
        if(valid(vect[i])){
            temp.push_back(vect[i]);
        }
    }
    
    for(int i=0;i<temp.length();i++){
        temp[i] = toLowerCase(temp[i]);
    }
    return checkPalindrome(temp);
}

void printString(string vect){
        cout<<vect;
}

int main(){
    // vector<string> vect;
    string str;
    cout<<"Enter your string :"<<endl;
    getline(cin,str);
    // vect.push_back(str);
    
    printString(str);
     
    int result = isPalindrome(str);
    
    if(result){
        cout<<"true";
    }else{
        cout<<"false";
    }
    

    return 0;
}