#include<iostream>
using namespace std;

class Vehicle{
    public:
    Vehicle(){
        cout<<"this is a Vehicle"<<endl;
    }
};

class Fare{
    public:
    Fare(){
        cout<<"Fare of Vehice"<<endl;
    }
};

class Car:public Vehicle{

};

class Bus:public Vehicle,public Fare{

};

int main(){
    Bus obj;  
    return 0;
}