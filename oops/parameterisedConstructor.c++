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

    //parameterised constructor
    Hero(int health){
        cout<<"this -> "<<this<<endl;
        this->health = health;
    }

    Hero(int health,char level){
        this->health = health;
        this->level = level;
    }

    void print(){
        cout<<health<<"  "<<level<<endl;
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
    
    Hero ramesh(10);
    // cout<<"Address of ramesh "<<&ramesh<<endl;
    ramesh.print();   
    ramesh.getHealth();
    //dynamic
    Hero *h = new Hero;
    h->print();

    Hero temp(22,'B');
    temp.print();
      
    return 0;
}