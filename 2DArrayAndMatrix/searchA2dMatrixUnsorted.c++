#include<bits/stdc++.h>
using namespace std;

bool searchA2dMatrix(vector<vector<int>>& matrix,int target){
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col -1;

    while(rowIndex < row && colIndex>=0){
        int element = matrix[rowIndex][colIndex];
        if(element == target){
            return 1;
        }
        if(element < target){
            rowIndex++;
        }else{
            colIndex--;
        }
    }
    return 0;
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

    int target;
    cout<<"Enter a element you want to search : "<<endl;
    cin>>target;

    if(searchA2dMatrix(vect,target)){
        cout<<"Target found "<<endl;
    }else{
        cout<<"Target not found "<<endl;
    }

    return 0;
}