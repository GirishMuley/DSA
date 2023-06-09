#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& vect,int m,int mid){
   long long int chop = 0;
    for(int i=0;i<vect.size();i++){
        if(vect[i]>mid){
            chop += (vect[i]-mid);
        }
    }
    if(chop >= m)
    return true;
    else
    return false;
}

int allocateWoods(vector<int>& vect,int m){
   long long int start = 0;
   int maxi = -1;
    for(long long int i=0;i<vect.size();i++){
        maxi = max(maxi,vect[i]);
    }

   long long int end = maxi;
   long long int mid = start + (end - start)/2;
   long long int ans = -1;
    while(start<=end){
        if(isPossible(vect,m,mid)){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int32_t main(){
    vector<int> vect;
    int n,m;
    cout<<"Number of elements : "<<endl;
    cin>>n;
    cout<<"Enter wood cutting range : "<<endl;
    cin>>m;
    cout<<"Enter all trees heights : "<<endl;
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"chopping lenght ="<<allocateWoods(vect,m)<<endl;
    return 0;
}