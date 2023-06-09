#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix){
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();

    int count = 0;
    int total = row*col;

    //indexs initialization
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row-1;
    int endingCol = col-1;

    while(count < total){
        //printing starting row
        for(int index = startingCol;count < total && index<=endingCol;index++){
            // ans.push_back(matrix[startingRow][index]);
            cout<<matrix[startingRow][index]<<" ";
            count++;
        }
        startingRow++;
        //printing ending column
        for(int index = startingRow;count < total && index<=endingRow;index++){
            cout<<matrix[index][endingCol]<<" ";
            count++;
        }
        endingCol--;
        //printing ending row
        for(int index = endingCol;count < total && index>=startingCol;index--){
            cout<<matrix[endingRow][index]<<" ";
            count++;
        }
        endingRow--;
        //printing starting column
        for(int index = endingRow;count < total && index>=startingRow;index--){
            cout<<matrix[index][startingCol]<<" ";
            count++;
        }
        startingCol++;
    }
    return ans;
}

int main(){
    vector<vector<int>> vect;
    int No_Of_Rows;
    int No_Of_Cols;
    cout<<"Enter number of rows :"<<endl;
    cin>>No_Of_Rows;
    cout<<"Enter number of colum :"<<endl;
    cin>>No_Of_Cols;
    cout<<"Enter elements :"<<endl;

    for(int row=0;row<No_Of_Rows;row++){
        vector<int> rows;
        for(int col=0;col<No_Of_Cols;col++){
            int data;
            cin>>data;
            rows.push_back(data);
        }
        vect.push_back(rows);
    }

    cout<<"Spiral is given bellow :"<<endl;

    spiralOrder(vect);
    return 0;
}