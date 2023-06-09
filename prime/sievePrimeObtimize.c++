#include<bits/stdc++.h>
using namespace std;

int N = 1000000;
bool sieve[1000001];
void createSieve(){
    for(int i=2;i<=N;i++){
        sieve[i] = true;
    }
    for(int i=2;i*i<=N;i++){
        if(sieve[i] == true){
            for(int j=i*i;j<=N;j+=i){
                sieve[j] = false;
            }
        }
    }
}

int main(){
    //o(n log(log n))
    createSieve();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(sieve[n] == true){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }
    return 0;
}