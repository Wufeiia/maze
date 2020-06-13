#ifndef _stack_h_
#define _stack_h_
#include <iostream>

using namespace std;
const int Max = 20;

class Stack{
    //protected:
    public:
        float userArray[Max];
        int top;
    //public:
        Stack();
        void push(float n); //insert data in stack
        float pop(); //return data
        bool isEmpty();
        float getArray(){return userArray[top];};


};
#endif

