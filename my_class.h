#include <iostream>

#ifndef MY_CLASS_H
#define MY_CLASS_H

template <typename T, const int n>
class LimitedStack {
private:
    T m_stack[n];
    int m_top;
    int m_length;
public:
    LimitedStack();
    ~LimitedStack() = default;
    LimitedStack operator= (const LimitedStack& arr) {
        m_length = arr.m_length;
        for (int i = 0; i < m_length; ++i)
            m_stack[i] = arr.m_stack[i];
        return *this;
    }

    void push(const T& element);
    void displayStack();

    T pop();
    T topElement();
    T size();

    bool empty();
};

template <typename T, const int n>
LimitedStack<T, n>::LimitedStack() : m_top(-1), m_length(0) {}

template <typename T, const int n>
void LimitedStack<T, n>::push(const T& element) {
    if (m_top == (n - 1))
        throw std::overflow_error("Can't push onto a full stack");
    m_top++;
    m_length++;
    m_stack[m_top] = element;
}

template <typename T, const int n>
T LimitedStack<T, n>::pop() {
    if (m_top == -1)
        throw std::underflow_error("Can't pop from an empty stack");
    T data = m_stack[m_top];
    m_stack[m_top] = 0;
    m_top--;
    m_length--;
    return data;
}

template <typename T, const int n>
void LimitedStack<T, n>::displayStack() {
    std::cout << "Stack: ";
    for (int i = 0; i < m_length; ++i) {
        std::cout << m_stack[i] << " "; 
    }
    std::cout << std::endl;
}

template <typename T, const int n>
T LimitedStack<T, n>::topElement() {
    return m_stack[m_top];
}

template <typename T, const int n>
T LimitedStack<T, n>::size() {
    return m_length;
}

template <typename T, const int n>
bool LimitedStack<T, n>::empty() {
    if (m_length == 0)
        return true;
    else
        return false;
}

#endif