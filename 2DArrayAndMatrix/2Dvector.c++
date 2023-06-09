#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int>> vect;
    cout<<"Enter element :"<<endl;
    for(int row=0;row<3;row++){
        vector<int> rows;
        for(int col=0;col<3;col++){
            int data;
            cin>>data;
            rows.push_back(data);
        }
        vect.push_back(rows);
    }

    cout<<"Vector contains :"<<endl;

    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<vect[row][col]<<" ";
        }
        cout<<endl;
    }
    return 0;
}