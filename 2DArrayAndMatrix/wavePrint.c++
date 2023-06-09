#include<bits/stdc++.h>
using namespace std;

 vector<int> wavePrint(vector<vector<int>> arr,int nRows,int mCols){
    vector<int> ans;

    for(int col=0;col<mCols;col++){
        if(col&1){
            //odd index -> bottom to top
            for(int row = nRows-1;row>=0;row--){
               // ans.push_back(arr[row][col]);
                cout<<arr[row][col]<<" ";
            }
        }else{
            //0 or even index -> top tp bottom
            for(int row=0;row<nRows;row++){
            //    ans.push_back(arr[row][col]);
                cout<<arr[row][col]<<" ";
            }
        }
    }
    return ans;
 }

int main(){
    vector<vector<int>> vect;
    int No_Of_Rows;
    int No_Of_Cols;
    
    cout<<"Enter number of rows : "<<endl;
    cin>>No_Of_Rows;
    cout<<"Enter number of column : "<<endl;
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

    
    cout<<"Wave is given bellow :"<<endl;
    wavePrint(vect,No_Of_Rows,No_Of_Cols);

    return 0;
}