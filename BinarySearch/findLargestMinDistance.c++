#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& vect,int m,int mid){
    int paintersCount = 1;
    int boards = 0;
    for(int i=0;i<vect.size();i++){
        if(boards + vect[i] <= mid){
            boards += vect[i];
        }else{
            paintersCount++;
            if(paintersCount > m || vect[i] > mid){
                return false;
            }
            boards = vect[i];
        }
    }
    return true;
}

int findLargestMinDistance(vector<int>& vect,int m){
    int start = 0;
    int sum  = 0;
    for(int i=0;i<vect.size();i++){
        sum += vect[i];
    }
    int end = sum;
    int ans = -1;
    int mid = start + (end - start)/2;

    while(start<=end){
        if(isPossible(vect,m,mid)){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

int main(){
    vector<int> vect{10,20,30,40};
    int painters = 2;
    cout<<"Answer = "<<findLargestMinDistance(vect,painters)<<endl;
    return 0;
}