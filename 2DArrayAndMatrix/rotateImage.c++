#include<bits/stdc++.h>
using namespace std;

vector<int> rotateImage(vector<vector<int>>& matrix){
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int endingRow = row - 1;
    int endingCol = col - 1;
    
    
    for(int col=0;col<=endingCol;col++){
        for(int row=endingRow;row>=0;row--){
            cout<<matrix[row][col];
        }
        cout<<endl;
        
    }
    return ans;    
}



int main(){
    vector<vector<int>> vect;
    int No_Of_Rows;
    int No_Of_Cols;
    cout<<"Enter number of rows : "<<endl;
    cin>>No_Of_Rows;
    cout<<"Enter number of cols : "<<endl;
    cin>>No_Of_Cols;
    cout<<"Enter elements : "<<endl;
    for(int row=0;row<No_Of_Rows;row++){
        vector<int> rows;
        for(int col=0;col<No_Of_Cols;col++){
            int data;
            cin>>data;
            rows.push_back(data);
        }
        vect.push_back(rows);
    }
    
    rotateImage(vect);

    return 0;
}