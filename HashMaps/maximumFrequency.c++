#include<bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr)
{
    unordered_map<int,int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
        maxFreq = max(maxFreq,count[arr[i]]);
    }

    for(int i=0;i<arr.size();i++){
        if(maxFreq == count[arr[i]]){
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}

int main(){
    int size;
    cin>>size;
    vector<int> vect;
    for(int i=0;i<size;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    int output = maximumFrequency(vect);
    cout<<output<<endl;
    
    return 0;
}