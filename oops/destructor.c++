#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    //properties
    private:
    int health;
    public:
    char level;
    char *name;
    
    Hero(){
        cout<<"Simple Constuctor is called"<<endl;
        name = new char[100];
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

    //deep copy constructor
    Hero(Hero& temp){
        char *ch = new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name = ch;
        cout<<"Copy Constuctor is called"<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }
    void print(){
        cout<<endl;
        cout<<"Name : "<<this->name<<", ";
        cout<<"Health is :"<<health<<", ";
        cout<<"Level is :"<<level<<", ";
        cout<<endl;
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

    void setName(char name[]){
        strcpy(this->name,name);
    }

    ~Hero(){
        cout<<"Destructor is called"<<endl;
    }
};

int main(){
    //static
    Hero a;
    //Dynamic
    Hero *b = new Hero();
    //Manually destructor call
    delete b;
    
    return 0;
}