#include<iostream>
#include "TomatoApp.h"
using namespace std;

int main()
{
    // create tomato app instance
    TomatoApp* app = new TomatoApp();

    //simulate a user coming in(Happy flow)
    User* user = new User(101 , "Manav" , "Delhi");
    cout << "\n User: " << user->getName() << " is Active. " << endl;

    //User searches for restaurants in their location
    vector<Restaurant*> restaurants = app->searchRestaurantsByLocation(user->getAddress());

    if(restaurants.empty())
    {
        cout << "No restaurants found in your location!" << endl;
        return 0;
    }

    cout << "\n Restaurants found in your location: " << endl;
    for(auto &it : restaurants)
    {
        cout << " -  " << it->getName() << endl;
    }

    //User selects a restaurant
    app->selectRestaurant(user , restaurants[0]);

    cout << "\n User: " << user->getName() << " has selected restaurant: " << restaurants[0]->getName() << endl;

    //user adds items to cart
    app->addToCart(user , "P1");
    app->addToCart(user , "P2");

    app->printUserCart(user);

    //user checkout the cart
    Order* order = app->checkOutNow(user , "Delivery" , new UpiPaymentStrategy("1234567890"));

    //User pay for the cart. If payment is success, notification is sent.
    app->payForOrder(user, order);

    //cleanup code
    delete app;
    delete user;
    delete order;

    return 0;
}