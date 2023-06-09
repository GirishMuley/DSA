#include<iostream>
using namespace std;

class Hero{
    //properties
    private:
    int health;
    public:
    char level;
    
    Hero(){
        cout<<"Simple Constuctor is called"<<endl;
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

    //copy constructor
    Hero(Hero& temp){
        cout<<"Copy Constuctor is called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    void print(){
        cout<<"Health is :"<<health<<endl;
        cout<<"Level is :"<<level<<endl;
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

    Hero suresh(70,'c');
    suresh.print();
    //copy constructor
    Hero ritesh(suresh);
    ritesh.print();
    // ritesh.health = suresh.health;

    return 0;
}