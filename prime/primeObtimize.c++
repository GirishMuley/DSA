#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;
    int count = 0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i == 0){
            count++;
            if((n/i) != i){
                count++;
            }
        }
    }
    
    if(count == 2){
        cout<<"Prime number"<<endl;
    }else{
        cout<<"Not prime number"<<endl;
    }
    return 0;
}