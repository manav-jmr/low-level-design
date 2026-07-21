#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../models/Order.h"
#include "../models/Cart.h"
#include "../models/Restaurant.h"
#include "../strategies/PaymentStrategy.h"

using namespace std;

class OrderFactory {
public:
    virtual Order* createOrder(User* user , Cart* cart , Restaurant* restaurant , const vector<const MenuItem*> menuItems , 
                                PaymentStrategy* paymentStrategy , const string& orderType) = 0;

    virtual ~OrderFactory() {}
};

#endif //ORDER_FACTORY_H