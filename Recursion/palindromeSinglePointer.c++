#include<iostream>
using namespace std;

bool checkPalindrome(string str,int i,int n){
    //base case
    if(i>n/2){
    return true;
}
    if(str[i] != str[n-i-1]){
        return false;
    }else{
        return checkPalindrome(str,i+1,n);
    }
}

int main(){
    string name = "abba";
    bool isPalindrome = checkPalindrome(name,0,name.length());
    if(isPalindrome){
        cout<<"It's a Palindrome"<<endl;
    }else{
        cout<<"It's not a Palindrome"<<endl;
    }

    return 0;
}