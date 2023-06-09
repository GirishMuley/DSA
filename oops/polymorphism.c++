#include<iostream>
using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello Love Babber"<<endl;
    }
    void sayHello(char name){
        cout<<"Hello Love Babber"<<endl;
    }
    void sayHello(string name){
        cout<<"Hello Love Babber"<<endl;
    }
};

class B{
    public:
    int a;
    int b;

    public:
    int add(){
        return a+b;
    }

    void operator+ (B &obj){
        int Value1 = this->a;
        int Value2 = obj.a;
        cout<<"Output "<<Value1 - Value2<<endl;
    }
};

class Animal{
    public:
    void speak(){
        cout<<"Speaking"<<endl;
    }
};

class Dog:public Animal {
    public:
    void speak(){
        cout<<"Barking"<<endl;
    }
};

int main(){
  
    Dog obj;
    obj.speak();

    // A obj;
    // obj.sayHello();
    // B obj1,obj2;
    // obj1.a = 4;
    // obj2.b = 7;
    // obj1 + obj2;
    
    return 0;
}