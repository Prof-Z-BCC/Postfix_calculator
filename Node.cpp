//
// Created by Rich Zwolinski on 3/11/25.
//

#include "Node.h"

Node::Node() {
    data = 0;
    this->next = nullptr;
}
Node::Node(const int data) {
    this->data = data;
    this->next = nullptr;
}

