#include<iostream>
using namespace std;

class Hero{
    //properties
    private:
    int health;
    public:
    char level;
    
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
    //static allocation
    Hero a;
    a.setHealth(80);
    a.setLevel('B');
    cout<<"Level is :"<<a.level<<endl;
    cout<<"Health is :"<<a.getHealth()<<endl;

    Hero *b = new Hero;
    b->setLevel('A');
    b->setHealth(70);
    cout<<"Health is : "<<(*b).getHealth()<<endl;
    cout<<"Level is : "<<(*b).level<<endl;
      
    return 0;
}