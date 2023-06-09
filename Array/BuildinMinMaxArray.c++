#include<iostream>
#include<climits>
using namespace std;

int getMax(int num[],int n){
    int maxi = INT_MIN;

    for(int i=0;i<n;i++){
        maxi = max(maxi,num[i]);
    }
    return maxi;
}

int getMin(int num[],int n){
    int mini = INT_MAX;

    for(int i=0;i<n;i++){
        mini = min(mini,num[i]);
    }
    return mini;
}

int main(){
    int size;
    cout<<"How many values you want to enter"<<endl;
    cin>>size;

    int num[100];

    for(int i = 0;i<size;i++){
        cin>>num[i];
    }

    cout<<"The maximum value is = "<<getMax(num, size)<<endl;
    cout<<"The manimum value is = "<<getMin(num, size)<<endl;
}