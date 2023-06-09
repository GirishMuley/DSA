#include<iostream>

int main(){
    int num;
    std::cout<<"enter a number";
    std::cin>>num;

    bool isPrime = 1;

    for(int i = 2;i<num;i++){
        if(num%i == 0){
            
            isPrime = 0;
            break;
        }
    }

    if(isPrime == 0){
        std::cout<<"number is not a prime";
    }else{
        std::cout<<"number is a prime";
    }
}