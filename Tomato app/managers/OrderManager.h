#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include "../models/Order.h"
using namespace std;

class OrderManager {
private:
    vector<Order*> orders;
    static OrderManager* instance;

    OrderManager()
    {
        //private constructor
    }

public:
    static OrderManager* getInstance()
    {
        if(!instance)
        {
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrder(Order* order)
    {
        orders.push_back(order);
    }

    void listOrders()
    {
        cout << "\n------- All orders ------" << endl;
        for(auto &it : orders)
        {
            cout << it->getType() << "order for " << it->getUser()->getName()
                    << " | Total: Rs" << it->getTotal()
                    << "| At : " << it->getScheduled() << endl;
        }
    }
};

OrderManager* OrderManager::instance = nullptr;

#endif //ORDER_MANAGER_H