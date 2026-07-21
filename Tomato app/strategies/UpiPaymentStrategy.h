#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include "PaymentStrategy.h"
using namespace std;

class UpiPaymentStrategy : public PaymentStrategy {
private:
    string mobileNumber;

public:
    UpiPaymentStrategy(const string &mobileNumber)
    {
        this->mobileNumber = mobileNumber;
    }

    void pay(double amount)
    {
        cout << "Paid Rs" << amount << " using UPI with mobile number: " << mobileNumber << endl;
    }
};

#endif //UPI_PAYMENT_STRATEGY_H