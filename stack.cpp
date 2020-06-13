#include "stack.h"

Stack::Stack(){
    top = -1;//initialize the stack
}

float Stack::pop(){
    top --;
    return userArray[top+1];
}

void Stack::push(float n){
    top ++;
    userArray[top] = n;
}

bool Stack::isEmpty(){
    if(top > -1){
        return false;
    }
    else{
        return true;
    }
}

