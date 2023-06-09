#include<iostream>
using namespace std;

int binarySearch(int array[],int size,int key){
    int start = 0;
    int end = size-1;

    int mid = start + (end - start)/2;

    while(start<=end){
        //check key is equal to mid
        if(array[mid] == key) {
            return mid;
        }

        //go to right
        if(key > array[mid]){
            start = mid + 1;
        }
        else//got to left
        {
            end = mid - 1;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main(){
    int even[] = {1,4,5,7,9,10};
    int odd[] = {2,6,9,12,14};

    int evenindex = binarySearch(even,6,7);

    cout<<"Index of 7 = "<<evenindex<<endl;

    int oddindex = binarySearch(odd,5,6);

    cout<<"Index of 6 = "<<oddindex<<endl;

    evenindex = binarySearch(even,6,20);
    cout<<"Index of 20 = "<<evenindex<<endl;

    oddindex = binarySearch(odd,5,20);
    cout<<"Index of 20 = "<<evenindex<<endl;
    
    return 0;
}