#include <iostream>
#include <ostream>

#ifndef MY_CLASS_H
#define MY_CLASS_H

template <typename T, const int n>
class LimitedStack {
private:
    T m_stack[n];
    int m_top;
public:
    LimitedStack();
    explicit LimitedStack(T element);
    ~LimitedStack();

    LimitedStack<T, n>& operator= (const LimitedStack<T, n>& stack) {
        if (this == &stack)
            return *this;
        m_top = stack.m_top;
        for (int i = 0; i < n; ++i) {
            m_stack[i] = stack.m_stack[i];
        }
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, LimitedStack<T, n>& stack) {
        if (stack.empty())
            os << "Stack is empty." << std::endl;
        else {
            os << "Stack: ";
            for (int i = 0; i < stack.size(); ++i)
                os << stack.m_stack[i] << " ";
            os << std::endl;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, LimitedStack<T, n>& stack) {
        T element;
        is >> element;
        stack.push(element);
        return is;
    }

    void push(const T& element);

    T pop();
    T topElement();
    int size();

    bool empty();
    bool full();
};

template <typename T, const int n>
LimitedStack<T, n>::LimitedStack() : m_top(-1) {}

template <typename T, const int n>
LimitedStack<T, n>::LimitedStack(T element) {
    push(element);
}

template <typename T, const int n>
LimitedStack<T, n>::~LimitedStack() {
    while (!empty())
        this -> pop();
}

template <typename T, const int n>
void LimitedStack<T, n>::push(const T& element) {
    if (full())
        throw std::overflow_error("Can't push onto a full stack.");
    m_stack[++m_top] = element;
}

template <typename T, const int n>
int LimitedStack<T, n>::size() {
    return m_top + 1;
}

template <typename T, const int n>
T LimitedStack<T, n>::pop() {
    if (empty())
        throw std::underflow_error("Can't pop from an empty stack.");
    T element = m_stack[m_top];
    m_stack[m_top--] = 0;
    return element;
}

template <typename T, const int n>
T LimitedStack<T, n>::topElement() {
    return m_stack[m_top];
}

template <typename T, const int n>
bool LimitedStack<T, n>::empty() {
    if (m_top == -1)
        return true;
    else
        return false;
}

template <typename T, const int n>
bool LimitedStack<T, n>::full() {
    if (m_top == n - 1)
        return true;
    else
        return false;
}

#endif