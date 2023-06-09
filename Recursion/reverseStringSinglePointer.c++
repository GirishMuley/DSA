#include<iostream>
using namespace std;

void reverse(string& str,int i,int n){
    //base case
    if(i>n/2){
        return;
    }
    swap(str[i],str[n-i-1]);
    i++;
    //recursive call
    reverse(str,i,n);
}

int main(){
    string name = "abcde";
    reverse(name,0,name.length());
    cout<<name<<endl;
    return 0;
}