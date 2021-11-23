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
    if (stack.full()) std::cout << "Stack is full." << std::endl;

    std::cout << stack;
    std::cout << "Deleted element: " << stack.pop() << std::endl;
    std::cout << "Queue size is: " << stack.size() << std::endl;
    std::cout << "Top element is: " << stack.topElement() << std::endl;
    std::cout << stack;

    if (stack.empty()) std::cout << "The stack is empty." << std::endl;
    else std::cout << "The stack is not empty." << std::endl;

    LimitedStack<T, A> stack2(stack);
    LimitedStack<T, A> stack3 = stack2;

    for (int i = 0; i < A; ++i) {
        try {
            stack.pop();
        } catch (std::underflow_error& e) {
            std::cout << "We caught an error. " << e.what() << std::endl;
        }
    }
    if (stack.empty()) std::cout << "The stack is empty." << std::endl;
    else std::cout << "The stack is not empty." << std::endl;
    std::cout << "Example of working copy constructor: " << stack2;
    std::cout << "Example of working operator =: " << stack3;
}

int main() {
    while (true) {
        std::cout << "Enter 1 - if you want to see, how container work with int.\n"
              << "Enter 2 - if you want to see, how container work with float.\n"
              << "Enter 3 - if you want to see, how container work with double.\n"
              << "Enter 4 - if you want to see, how container work with class Money.\n";
    int number;
    std::cin >> number;
    if (number == 1) {
        LimitedStack<int, A> stack;
        testProgram(stack);
    } if (number == 2) {
        LimitedStack<float, A> stack;
        testProgram(stack);
    } if (number == 3) {
        LimitedStack <double, A> stack;
        testProgram(stack);
    } if (number == 4) {
        LimitedStack<Money, A> stack;
        testProgram(stack);
    } else {
        std::cout << "Do you want to continue or just exit the program exicution?\n"
                  << "Enter 1 for the first variant.\n" << "Enter 2 for the second variant.\n";
        int decision;
        std::cin >> decision;
        if (decision == 1)
            continue;
        else
            break;
    }
    }
    
    return 0;
}

