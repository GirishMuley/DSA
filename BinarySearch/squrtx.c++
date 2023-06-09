#include<iostream>
using namespace std;

long long int binarySearch(int n){
    int start = 0;
    long long int end = n;
    long long int mid = start + (end - start)/2;
    long long int ans = -1;
    while(start<=end){
        long long int square = mid*mid;
        if(square == n){
            return mid;
        }
        if(square<n){
            ans = mid;
            start = mid + 1;
        }else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

double morePrecision(int n,int precision,int tempSql){
    double factor = 1;
    double ans = tempSql;

    for(int i=0;i<precision;i++){
        factor /= 10;
        for(double j=ans;j*j<n;j=j+factor){
            ans = j;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter a number"<<endl;
    cin>>n;

    int tempSql = binarySearch(n);

    cout<<"Answer = "<<morePrecision(n,3,tempSql)<<endl;

    return 0;
}