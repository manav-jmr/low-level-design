#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

using namespace std;

class ScheduledOrderFactory : public OrderFactory {
private:
    string scheduledTime;

public:
    ScheduledOrderFactory(const string& scheduledTime)
    {
        this->scheduledTime = scheduledTime;
    }

    Order* createOrder(User* user , Cart* cart , Restaurant* restaurant , const vector<const MenuItem*> menuItems , 
                       PaymentStrategy* paymentStrategy , const string& orderType)
    {
        Order* order = nullptr;

        if(orderType == "Delivery")
        {
            DeliveryOrder* deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else if(orderType == "Pickup")
        {
            PickupOrder* pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        }
        else
        {
            cout << "Invalid order type!" << endl;
            return nullptr;
        }

        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduledTime);
        order->setTotal(cart->getTotalCost());

        return order;
    }
};

#endif //SCHEDULED_ORDER_FACTORY_H