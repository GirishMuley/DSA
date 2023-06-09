#include<bits/stdc++.h>
using namespace std;

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
    int size = 6;
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
    
    return 0;
}