#include<iostream>
using namespace std;

class Hero{
    //properties
    int health;
};

int main(){
    //creating object
    Hero h1;

    cout<<"Size : "<<sizeof(h1)<<endl;

    return 0;
}