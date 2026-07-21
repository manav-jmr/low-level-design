#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/DeliveryOrder.h"
#include "../models/PickupOrder.h"
#include "../utils/TimeUtils.h"

using namespace std;

class NowOrderFactory : public OrderFactory {
public:
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
        order->setScheduled(TimeUtils::getCurrentTime());
        order->setTotal(cart->getTotalCost());

        return order;
    }
};

#endif //NOW_ORDER_FACTORY_H