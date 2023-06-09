#include<iostream>
using namespace std;
#define AREA(l,b) (l * b)
int main(){
    int length = 10;
    int breath = 5;
    int area = AREA(length,breath);
    cout<<"Area of reactangle is "<<area<<endl;
    return 0;
}