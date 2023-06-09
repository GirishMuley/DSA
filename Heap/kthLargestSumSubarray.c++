#include<bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>> mini;

	int n = arr.size();
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum += arr[j];
			if(mini.size() < k){
				mini.push(sum);
			}
			else
			{
				if(sum > mini.top()){
					mini.pop();
					mini.push(sum);
				}
			}
		}
	}
	return mini.top();
}

int main(){
    vector<int> vect;
    cout<<"Size of array"<<endl;
    int sizeofvect;
    cin>>sizeofvect;
    cout<<"Enter element"<<endl;
    for(int i=0;i<sizeofvect;i++){
        int data;
        cin>>data;
        vect.push_back(data);
    }
    
    cout<<"Enter k value"<<endl;
    int k;
    cin>>k;
    
    int result = getKthLargest(vect,k);
    
    cout<<"Output "<<endl;
    cout<<result<<endl;
    
    return 0;
}