#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
using namespace std;

class CreditCardPaymentStrategy : public PaymentStrategy {
private:
    string cardNumber;

public:
    CreditCardPaymentStrategy(const string &cardNumber)
    {
        this->cardNumber = cardNumber;
    }

    void pay(double amount)
    {
        cout << "\n Paid Rs" << amount << " using Credit Card with card number: " << cardNumber << endl;
    }
};

#endif //CREDIT_CARD_PAYMENT_STRATEGY_H