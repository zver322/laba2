#include "my_class.h"
#include <iostream>


template<typename T>
void testProgram(LimitedStack<T, 5>& stack) {
    for (int i = 0; i < 6; ++i) {
       try {
           int number;
            std::cin >> number;
            stack.push(number);
       } catch (std::overflow_error& e) {
           std::cerr << "We caught an error. " << e.what() << std::endl;
       }
    }
    stack.displayStack();
    std::cout << "Deleted element: " << stack.pop() << std::endl;
    std::cout << "Queue size is: " << stack.size() << std::endl;
    std::cout << "Top element is: " << stack.topElement() << std::endl;
    if (stack.empty()) std::cout << "The stack is empty." << std::endl;
    else std::cout << "The stack is not empty." << std::endl;
    for (int i = 0; i < 5; ++i) {
        try {
            stack.pop();
        } catch (std::underflow_error& e) {
            std::cout << "We caought an error. " << e.what() << std::endl;
        }
    }
    if (stack.empty()) std::cout << "The stack is empty." << std::endl;
    else std::cout << "The stack is not empty." << std::endl;
    stack.displayStack();
}

int main() {
    LimitedStack<int, 5> a;
    LimitedStack<int, 5> b;
    LimitedStack<float, 5> c;
    //testProgram(a);
    return 0;
}

