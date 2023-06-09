#include<iostream>
using namespace std;

int findUnique(int array[],int size){
    int ans = 0;
    for(int i=0;i<size;i++){
        ans = ans^array[i];
    }
    return ans;
}

int main(){
    int array[]={2,3,1,6,3,6,2};
    int size = sizeof(array)/sizeof(array[0]);
    int value;

    value = findUnique(array,size);

    cout<<value<<endl;

    return 0;    

}