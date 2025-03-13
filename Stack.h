//
// Created by Rich Zwolinski on 3/11/25.
//

#ifndef STACK_H
#define STACK_H

#include "Node.h"

class Stack {

public:
    Node * head;
    Stack();
    ~Stack();
    bool isEmpty() const;
    void push(int);
    int pop();
    void display() const;

};



#endif //STACK_H
