#include<iostream>
using namespace std;

int main(){
    
    int rows;
    cout<<"Enter no of rows of array"<<endl;
    cin>>rows;

    int *number = new int[rows]; //array to store no of column
    int **array = new int*[rows];//jagged array

    for(int i=0;i<rows;i++){
        cout<<"Enter no of col in row "<<i<<": ";
        cin>>number[i];
        array[i] = new int[number[i]];
    }

    for(int i=0;i<rows;i++){
        for(int j=0;j<number[i];j++){
            cout<<"Rows "<<i<<": Enter value"<<i*number[i]+j<<": ";
            cin>>array[i][j];
        }
    }
    cout<<"Showing all the Inputed data in a matrix form"<<endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<number[i];j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Dellocating the array..."<<endl;
    for(int i=0;i<rows;i++){
        delete [] array[i];
    }
    delete [] array;
    cout<<"Done!";
    return 0;
}