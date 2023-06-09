#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>& rank,int m,int mid){
    int NoOfDishes = 0;
    for(int i=0;i<rank.size();i++){
        int sum = 0;
        for(int j=1;sum<=mid;j++){
            sum += rank[i]*j;
            NoOfDishes++;
            if(sum>mid){
                NoOfDishes--;
            }
            if(NoOfDishes>=m){
                return true;
            }
        }
    }
    return false;
}

int minCockTime(vector<int>& rank,int m){
    int start = 0;
    int maxi = -1;
    for(int i=0;i<rank.size();i++){
        maxi = max(maxi,rank[i]);
    }
    int end = maxi * m * (m+1)/2;
    int mid = start + (end - start)/2;
    int ans = -1;
    while(start<=end){
        if(isPossible(rank,m,mid)){
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
    vector<int> rank;
    int cock;
    int dish;
    cout<<"Enter number of cocks "<<endl;
    cin>>cock;
    cout<<"Enter number of dishes "<<endl;
    cin>>dish;
    cout<<"Enter the ranks of cocks "<<endl;
    for(int i=0;i<cock;i++){
        int data;
        cin>>data;
        rank.push_back(data);
    }
    cout<<"Time taken = "<<minCockTime(rank,dish)<<endl;
    return 0;
}