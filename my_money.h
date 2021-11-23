#include <iostream>
#include <ostream>

#ifndef MY_MONEY_H
#define MY_MONEY_H

class Money {
private:
    long m_rubles;
    int m_penny;
public:
    Money (const long& rubles, const int& penny);
    Money();
    ~Money() = default;

    friend std::ostream& operator<<(std::ostream& os, const Money& money);
    friend std::istream& operator>>(std::istream& is, Money& money);


    Money& operator=(const Money& money);
    Money& operator=(const int& zero);
};

Money::Money (const long& rubles, const int& penny): 
              m_rubles(rubles + static_cast<long> (penny / 100)), m_penny(penny % 100) {}

Money::Money() : m_rubles(0), m_penny(0) {}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << money.m_rubles << "," << money.m_penny << " ";
    return os; 
}

std::istream& operator>>(std::istream& is, Money& money) {
    std::cout << "Enter the amount of rubles and pennies: " << std::endl;
    is >> money.m_rubles;
    is >> money.m_penny;
    if (money.m_penny >= 100) {
        money.m_rubles += static_cast<long> (money.m_penny / 100);
        money.m_penny %= 100;
    }
    return is;
}

Money& Money::operator=(const Money& money) {
    m_rubles = money.m_rubles;
    m_penny = money.m_penny;
    return *this;
}

Money& Money::operator=(const int& zero) {
    m_rubles = zero;
    m_penny = zero;
    return *this;
}

#endif