#include "my_class.h"
#include "my_money.h"
#include <iostream>

#define A 5


template<typename T>
void testProgram(LimitedStack<T, A>& stack) {
    for (int i = 0; i <= A; ++i) {
       try {
            std::cin >> stack;
        } catch (std::overflow_error& e) {
           std::cerr << "We caught an error. " << e.what() << std::endl;
        }
    }
    std::cout << stack;
    std::cout << "Deleted element: " << stack.pop() << std::endl;
    std::cout << "Queue size is: " << stack.size() << std::endl;
    std::cout << "Top element is: " << stack.topElement() << std::endl;
    if (stack.empty()) std::cout << "The stack is empty." << std::endl;
    else std::cout << "The stack is not empty." << std::endl;
    for (int i = 0; i < A; ++i) {
        try {
            stack.pop();
        } catch (std::underflow_error& e) {
            std::cout << "We caught an error. " << e.what() << std::endl;
        }
    }
    if (stack.empty()) std::cout << "The stack is empty." << std::endl;
    else std::cout << "The stack is not empty." << std::endl;
}

int main() {
    
    return 0;
}

