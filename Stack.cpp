//
// Created by Rich Zwolinski on 3/11/25.
//

#include "Stack.h"
#include <iostream>

using std::cout, std::endl;

Stack::Stack() {this->head = nullptr;}
Stack::~Stack() {
    if (!isEmpty()) {
        Node* current = head;
        while( current != nullptr ) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }
}
bool Stack::isEmpty() const {

    // If head is nullptr, the stack is empty
    return head == nullptr;
}

// Function to push an element onto the stack
void Stack::push(const int new_data) {

    // Create a new node with given data
    Node* new_node = new Node(new_data);

    // Link the new node to the current top node
    new_node->next = head;

    // Update the top to the new node
    head = new_node;
}

// Function to remove the top element from the stack
int Stack::pop() {

    // Check for stack underflow
    if (this->isEmpty()) {
        cout << "\nStack Underflow" << endl;
    }
    else {
        // Assign the current top to a temporary
        // variable
        Node* temp = head;
        int value = head->data;
        // Update the top to the next node
        head = head->next;

        // Deallocate the memory of the old top node
        delete temp;
        return value;

    }
}

void Stack::display() const {
    if (this->isEmpty()) {
        cout << "\nStack is Empty";
    }
    else {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}



