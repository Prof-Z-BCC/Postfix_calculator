#include <iostream>

#include "Stack.h"
#include <string>
#include <sstream>
using namespace std;

int main() {
    Stack stk;
    string str;
    cout << "Enter a postfix expression: ";
    getline(cin, str);
    istringstream iss(str);
    while (iss >> str) {
        if (isdigit(str[0])) {
            stk.push(stoi(str));
        } else {
            try {
                if (str[0] == '=') {
                    cout << "The final result is: ";
                    stk.display();
                    cout << endl;
                } else {
                    switch (str[0]) {
                        case '+': {
                            stk.display();
                            int sum = stk.pop() + stk.pop();
                            stk.push(sum);
                            break;
                        }
                        case '-': {
                            stk.display();
                            int val1 = stk.pop();
                            int val2 = stk.pop();
                            int diff = val2 - val1;
                            stk.push(diff);
                            break;
                        }
                        case '*': {
                            stk.display();
                            int prod = stk.pop() * stk.pop();
                            stk.push(prod);
                            break;
                        }
                        case '/': {
                            stk.display();
                            int val1 = stk.pop();
                            int val2 = stk.pop();
                            int quot = val2 / val1;
                            stk.push(quot);
                            break;
                        }
                        default: {
                            throw runtime_error("Invalid input");
                        }
                    }
                }
            }
            catch (const exception &e) {
                cerr <<"ERROR: " << e.what() << endl;
            }
        }
    }
}
