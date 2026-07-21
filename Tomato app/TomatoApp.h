#ifndef TOMATO_APP_H
#define TOMATO_APP_H

#include "models/User.h"
#include "models/Restaurant.h"
#include "models/Cart.h"
#include "managers/OrderManager.h"
#include "managers/RestaurantManager.h"
#include "strategies/PaymentStrategy.h"
#include "strategies/CreditCardPaymentStrategy.h"
#include "strategies/UpiPaymentStrategy.h"
#include "factories/OrderFactory.h"
#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "services/NotificationService.h"
#include "utils/TimeUtils.h"

using namespace std;

class TomatoApp {
public:
    TomatoApp()
    {
        initializeRestaurants();
    }

    void initializeRestaurants()
    {
        Restaurant* r1 = new Restaurant("Bikaner" , "Delhi");
        r1->addMenuItem(MenuItem("P1" , "Paneer Butter Masala" , 250));
        r1->addMenuItem(MenuItem("P2" , "Dal Makhani" , 200));

        Restaurant* r2 = new Restaurant("Haldiram" , "Kolkata");
        r2->addMenuItem(MenuItem("P1" , "Raj Kachori" , 80));
        r2->addMenuItem(MenuItem("P2" , "Pav Bhaji" , 100));
        r2->addMenuItem(MenuItem("P3" , "Chole Bhature" , 120));

        Restaurant* r3 = new Restaurant("Sagar Ratna" , "Bangalore");
        r3->addMenuItem(MenuItem("P1" , "Idli Sambar" , 50));
        r3->addMenuItem(MenuItem("P2" , "Dosa" , 70));
        r3->addMenuItem(MenuItem("P3" , "Vada Pav" , 40));

        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        restaurantManager->addRestaurant(r1);
        restaurantManager->addRestaurant(r2);
        restaurantManager->addRestaurant(r3);
    }

    vector<Restaurant*> searchRestaurantsByLocation(const string& location)
    {
        RestaurantManager* restaurantManager = RestaurantManager::getInstance();
        return restaurantManager->searchByLocation(location);
    }

    void selectRestaurant(User* user , Restaurant* restaurant)
    {
        Cart* cart = user->getCart();
        cart->setRestaurant(restaurant);
    }

    void addToCart(User* user , const string& itemCode)
    {
        Restaurant* restaurant = user->getCart()->getRestaurant();
        if(!restaurant)
        {
            cout << "Please select a restaurant first!" << endl;
            return;
        }

        for(const auto &item : restaurant->getMenu())
        {
            if(item.getCode() == itemCode)
            {
                user->getCart()->addItem(&item);
                break;
            }
        }
    }

    Order* checkOutNow(User* user , const string &orderType , PaymentStrategy* paymentStrategy)
    {
        return checkout(user , orderType , paymentStrategy , new NowOrderFactory());
    }

    Order* scheduleOrder(User* user , const string &orderType , PaymentStrategy* paymentStrategy , const string& scheduledTime)
    {
        return checkout(user , orderType , paymentStrategy , new ScheduledOrderFactory(scheduledTime));
    }

    Order* checkout(User* user , const string &orderType , PaymentStrategy* paymentStrategy , OrderFactory* orderFactory)
    {
        if(user->getCart()->isEmpty())
        {
            cout << "Cart is empty! Please add items to cart before checkout." << endl;
            return nullptr;
        }

        Cart* userCart = user->getCart();
        Restaurant* orderRestaurant = userCart->getRestaurant();
        vector<const MenuItem*> orderItems = userCart->getItems();
        double totalCost = userCart->getTotalCost(); 

        Order* order = orderFactory->createOrder(user , userCart , orderRestaurant , orderItems , paymentStrategy , orderType);
        OrderManager* orderManager = OrderManager::getInstance();
        orderManager->addOrder(order);
        return order;
    }

    void payForOrder(User* user , Order* order)
    {
        bool isPaymentSuccessful = order->processPayment();

        if(isPaymentSuccessful)
        {
            NotificationService* notification = new NotificationService();
            notification->notify(order);
            user->getCart()->clear();
        }
    }

    void printUserCart(User* user)
    {
        cout << "\n------- User Cart ------" << endl;
        cout << "--------------------------------------" << endl;
        for(const auto &item : user->getCart()->getItems())
        {
            cout << "Item: " << item->getName() << " | Price: Rs" << item->getPrice() << endl;
        }
        cout << "--------------------------------------" << endl;
        cout << "Total Cost: Rs" << user->getCart()->getTotalCost() << endl;
    }
};

#endif //TOMATO_APP_H