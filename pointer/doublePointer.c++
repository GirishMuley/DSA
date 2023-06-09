#include<iostream>
using namespace std;
void update(int **p2){
    //it will change value? -NO 
    // p2 = p2 + 1;
    //it will change value? -YES
    // *p2 = *p2 + 1;//p address change
    //it will change value? -YES
    **p2 = **p2 + 1;
    
}
int main(){
    int i = 5;
    int* p = &i;
    int** p2 = &p;

    // //following will print the what value i hold
    // cout<<i<<endl;
    // cout<<*p<<endl;
    // cout<<**p2<<endl;

    // //following will print the address of i
    // cout<<&i<<endl;
    // cout<<p<<endl;
    // cout<<*p2<<endl;

    // //pirnt address of p
    // cout<<&p<<endl;
    // cout<<p2<<endl;

    cout<<endl<<endl;
    cout<<"before"<<i<<endl;
    cout<<"before"<<p<<endl;
    cout<<"before"<<p2<<endl;
    update(p2);
    cout<<"after"<<i<<endl;
    cout<<"after"<<p<<endl;
    cout<<"after"<<p2<<endl;
    cout<<endl<<endl;
    return 0;
}