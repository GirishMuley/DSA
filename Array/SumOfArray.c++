#include<iostream>
using namespace std;

int getSum(int array[], int size){
    int sum = 0;
    for(int i=0;i<size;i++){
        sum = sum + array[i];
    }
    return sum;
}

int main(){
    int size;
    cout<<"How many element you want to enter"<<endl;
    cin>>size;

    int num[100];
    cout<<"Enter values:"<<endl;
    for(int i=0;i<size;i++){
        cin>>num[i];
    }

    cout<<"Sum of the  array is = "<<getSum(num,size)<<endl;

    return 0;
}