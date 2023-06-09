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
    Hero ramesh;

    // ramesh.health = 70;
    ramesh.setHealth(70);
    ramesh.level = 'A';
    cout<<"Size of ramesh is "<<sizeof(ramesh)<<endl;
    cout<<"Health is : "<<ramesh.getHealth()<<endl;
    cout<<"Level is : "<<ramesh.level<<endl;
      
    return 0;
}