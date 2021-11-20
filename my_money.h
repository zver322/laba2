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
    ~Money() = default;
    friend std::ostream& operator<<(std::ostream& os, const Money& money);
    Money operator = (const Money& cm) {
        m_rubles = cm.m_rubles;
        m_penny = cm.m_penny;
        return *this;
    }
    
    
};

Money::Money (const long& rubles, const int& penny) : m_rubles(rubles), m_penny(penny) {}

std::ostream& operator<<(std::ostream& os, const Money& money) {
    os << "Money: " << money.m_rubles + static_cast<long> (money.m_penny / 100) << "," << money.m_penny % 100 << std::endl;
    return os; 
}


#endif