#include<iostream>
using namespace std;

class Hero{
    //properties
    private:
    int health;
    public:
    char level;
    
    Hero(){
        cout<<"Constuctor is called"<<endl;
    }
    int getHealth(){
        return health;
    }

    char setHealth(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    } 
};

int main(){
    //Object created statically
    cout<<"Hi"<<endl;
    Hero ramesh;
    cout<<"Hello"<<endl;
    //dynamic
    Hero *h = new Hero;
      
    return 0;
}