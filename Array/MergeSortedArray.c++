#include<bits/stdc++.h>
using namespace std;

void mergeSortedArray(vector<int> &nums1,vector<int> &nums2,int n,int m){
      for(int i = 0; i<nums2.size() ; i++){
            nums1.pop_back();
        }
        
        
        for(int i = 0; i<nums2.size() ; i++){
            nums1.push_back(nums2[i]);
        }
        
        sort(nums1.begin() , nums1.end());
}

void printArray(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr.at(i)<<" ";
    }
}

int main(){
    vector<int> vect1;
    vector<int> vect2;
    
    int size_Of_Vect1;
    int size_Of_Vect2;
    
    cout<<"Enter size of first array :"<<endl;
    cin>>size_Of_Vect1;
    cout<<"Enter the element of the array :"<<endl;
    for(int i=0;i<size_Of_Vect1;i++){
        int data;
        cin>>data;
        vect1.push_back(data);
    }
    
    cout<<"Enter size of second array :"<<endl;
    cin>>size_Of_Vect2;
    cout<<"Enter the element of the array :"<<endl;
    for(int i=0;i<size_Of_Vect2;i++){
        int data;
        cin>>data;
        vect2.push_back(data);
    }
 
    mergeSortedArray(vect1,vect2,size_Of_Vect1,size_Of_Vect2);
    
    cout<<"Merged array is :"<<endl;
    
    printArray(vect1);
    
    return 0;
}