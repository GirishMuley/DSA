#include<bits/stdc++.h>
using namespace std;
// To hold the prime numbers <= sqrt(n)
vector<int> primes;

//get all the primes <= x
//x = sqrt(n)
void simpleSieve(int x){
    vector<bool> isPrime(x + 1,true);

    /*
    making 0 and 1 as false since they are not prime
    */
    isPrime[0] = false;
    isPrime[1] = false;

    //Sieve for filtering out the primes <= x
    for(int i=2;i*i<=x;i++){
        if(isPrime[i]){
            //cancelling out all the mutilple of i
            for(int m = i*i;m <= x;m+=i){
                isPrime[m] = false;
            }
        }
    }

    //add all the prime into primes[]
    for(int i=2;i<=x;i++){
        if(isPrime[i]){
            primes.push_back(i);
        }
    }
}

void segmentedSieve(int low,int high,vector<int> &ans){
    vector<int> isPrime(high - low + 1,true);
    //looping over all primes
    for(int p:primes){
        //choosing the first multiple of p >= low
        int s = low/p*p;
        if(s < low){
            s+=p;
        }
        //cancalling out the factors of p
        for(int i=s;i<=high;i+=p){
            isPrime[i - low] = false;
        }
    }
    //append all primes in range [low,high] in ans
    for(int i=0;i<isPrime.size();i++){
        if(isPrime[i]){
            ans.push_back(i + low);
        }
    }
}
int main(){
    primes.clear();
    int n;
    cin>>n;
    //get all the primes <= sqrt(n)
    simpleSieve((int)floor(sqrt(n)));
    vector<int> ans;
    /*
  divide the range [2, n-1] into
  smaller segments of size sqrt(n),
  use segmentedSieve to find all the
  primes in the range [l, r] and append
  to ans
  */

  //for every segment ,we call segmentedSieve()
  int updateVal = floor(sqrt(n));
  for(int l = 2;l<n;l+=updateVal){
    int r = min(l + updateVal - 1,n - 1);
    segmentedSieve(l,r,ans);
  }
  //print all the primes < n
  for(int p:ans){
    cout<<p<<" ";
  }
  cout<<endl;
    return 0;
}