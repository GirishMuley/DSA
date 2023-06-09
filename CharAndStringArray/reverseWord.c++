#include<bits/stdc++.h>
using namespace std;

void reverseWord(char* s){
    //reverse entire string
    int start = 0;
    int end = strlen(s) - 1;
    while(start<end){
        swap(s[start++],s[end--]);
    }
    //reverse each word in the string
    start = 0;
    for(int current = 0;current<strlen(s);current++){
        if(current == ' '){
            continue;
        }
        start = current;
        while(s[current] != ' ' && current<strlen(s)){
            current++;
        }
        end = current-1;
        while(start<end){
            swap(s[start++],s[end--]);
        }
    }
    
}

int main(){
    char s[] = "my name is jack";
    
    reverseWord(s);
    
    cout<<s;
    return 0;
}