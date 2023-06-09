#include<iostream>
using namespace std;

int main(){
    // int num = 5;
    // cout<<num<<endl;
    // //address of Operator - &
    // cout<<"adddress of num is "<<&num<<endl;

    // int *ptr = &num;
    // cout<<"Address is :"<<ptr<<endl;
    // cout<<"Value is :"<<*ptr<<endl;

    // double d = 4.3;
    // double *p2 = &d;

    // cout<<"Address is :"<<p2<<endl;
    // cout<<"Value is :"<<*p2<<endl;

    // cout<<"size of integer is "<<sizeof(num)<<endl;
    // cout<<"size of pointer is "<<sizeof(ptr)<<endl;
    // cout<<"size of pointer is "<<sizeof(p2)<<endl;

    //pointer to int is created, and  pointing to some garbage address
    // int *p;
    // cout<<"p"<<*p<<endl;

    // //how to avoid above problem
    // int *p1 = 0;
    // cout<<"p1"<<*p1<<endl;

    // int i = 5;
    // int *p3 = &i;
    // cout<<"p3 "<<p3<<endl;
    // cout<<"*p3 "<<*p3<<endl;

    // int *q3 = 0;
    // q3 = &i;
    // cout<<"q3 "<<q3<<endl;
    // cout<<"*q3 "<<*q3<<endl;

    // int number = 5;
    // int a = number;
    // cout<<"a before "<<number<<endl;
    // a++;
    // cout<<"a after "<<number<<endl;

    // int *p4 = &number;
    // cout<<"Before "<<number<<endl;
    // (*p4)++;
    // cout<<"After "<<number<<endl;

    // //copying pointer
    // int *q = p4;
    // cout<<"1 : "<<p4<<" - "<<q<<endl;
    // cout<<"2 : "<<*p4<<" - "<<*q<<endl;

    //important concept
    int i = 3;
    int *t = &i;
    cout<<"before :"<<*t<<endl;
    *t = *t + 1;
    cout<<"After :"<<*t<<endl;
    cout<<"Program end here!!!!!!"<<endl;
    return 0;
}