#include<bits/stdc++.h>
using namespace std;

int numTrees(int n) {
        if(n <= 1)
            return 1;
        
        int ans = 0;
        //think i as root node
        for(int i=1;i <= n;i++){
            ans += numTrees(i-1) * numTrees(n-i);
        }
        return ans;
    }

int main(){
    int n;
    cout<<"Emter num"<<endl;
    std::cin >> n;
    
    cout<<"____________"<<endl;
    
    cout<<numTrees(n)<<endl;
    
    return 0;
}