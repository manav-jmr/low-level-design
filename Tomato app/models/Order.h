#ifndef ORDER_H
#define ORDER_H

#include<iostream>
#include<bits/stdc++.h>
#include "User.h"
#include "Restaurant.h"
#include "MenuItem.h"
#include "../strategies/PaymentStrategy.h"
#include "../utils/TimeUtils.h"

using namespace std;

class Order {
protected:
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurant* restaurant;
    vector<const MenuItem*> items;
    PaymentStrategy* paymentStrategy;
    double total;
    string scheduled;

public:
    Order()
    {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        total = 0.0;
        scheduled = "";
        orderId = ++nextOrderId;
    }

    virtual ~Order()
    {
        delete paymentStrategy;
    }

    bool processPayment()
    {
        if(paymentStrategy)
        {
            paymentStrategy->pay(total);
            return true;
        }
        else
        {
            cout << "Please choose a payment mode first !" << endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    int getOrderid() const
    {
        return orderId;
    }

    void setUser(User* u)
    {
        this->user = u;
    }

    User* getUser() const
    {
        return user;
    }

    void setRestaurant(Restaurant* r)
    {
        this->restaurant = r;
    }

    Restaurant* getRestaurant() const
    {
        return restaurant;
    }

    void setItems(const vector<const MenuItem*> its)
    {
        this->items = its;
        total = 0;
        for(auto &it : items)
        {
            total += it->getPrice();
        }
    }

    const vector<const MenuItem*> getItems() const
    {
        return items;
    }

    void setPaymentStrategy(PaymentStrategy* p)
    {
        this->paymentStrategy = p;
    }

    void setScheduled(const string &s)
    {
        this->scheduled = s;
    }

    string getScheduled() const
    {
        return scheduled;
    }

    double getTotal() const
    {
        return total;
    }

    void setTotal(int total)
    {
        this->total = total;
    }
};

int Order::nextOrderId = 0;

#endif //ORDER_H