#include<bits/stdc++.h>
using namespace std;

vector<int> findArraySum(vector<int> &vect1,int n,vector<int> &vect2,int m){
    int i = n-1;
    int j = m-1;
    vector<int> ans;
    int carry = 0;
    
    while(i>=0 && j>=0){
        int value1 = vect1[i];
        int value2 = vect2[j];
        
        int sum =  value1 + value2 + carry;
        
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }
    
    //first case
    while(i>=0){
        int sum = vect1[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    
    //second case
    while(j>=0){
        int sum = vect2[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }
    
    //third case
    while(carry != 0){
        int sum = carry;
        carry = sum/10;
        sum = sum/10;
        ans.push_back(sum);
    }
    
    //revrse ans
    reverse(ans.begin(),ans.end());
    return ans;
    
}

void printArray(vector<int> &ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans.at(i)<<" ";
    }
}

int main(){
    vector<int> vect1;
    vector<int> vect2;
    int size_Of_vect1;
    int size_Of_vect2;
    cout<<"Enter the size of first array : "<<endl;
    cin>>size_Of_vect1;
    cout<<"Enter element of array : "<<endl;
    for(int i=0;i<size_Of_vect1;i++){
        int data;
        cin>>data;
        vect1.push_back(data);
    }
    cout<<"Enter the size of second array : "<<endl;
    cin>>size_Of_vect2;
    cout<<"Enter element of array : "<<endl;
    for(int i=0;i<size_Of_vect2;i++){
        int data;
        cin>>data;
        vect2.push_back(data);
    }
    
    cout<<"Sum of array is :"<<endl;
    vector<int> result = findArraySum(vect1,size_Of_vect1,vect2,size_Of_vect2);
    printArray(result);
    return 0;
}