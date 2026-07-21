#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H

#include<iostream>
#include "../models/Order.h"
#include<bits/stdc++.h>

using namespace std;

class NotificationService {
public:
    static void notify(Order* order)
    {
        cout << "\n Notification: Your " << order->getType() << " order with ID " << order->getOrderid() 
             << " has been placed successfully!" << endl;
    }
};

#endif //NOTIFICATION_SERVICE_H