#ifndef CART_H
#define CART_H

#include<iostream>
#include<bits/stdc++.h>
#include "MenuItem.h"
#include "Restaurant.h"

using namespace std;

class Cart {
private:
    Restaurant* restaurant;
    vector<const MenuItem*> items;
public:
    Cart() {
        restaurant = nullptr;
    }

    void addItem(const MenuItem* item)
    {
        if(!restaurant)
        {
            cout << "Cart: set a restaurant before adding items!";
            return;
        }
        items.push_back(item);
    }

    double getTotalCost() const
    {
        double sum = 0;
        for(const auto& it : items)
        {
            sum += it->getPrice();
        }

        return sum;
    }

    bool isEmpty()
    {
        return (!restaurant || items.empty());
    }

    void clear()
    {
        items.clear();
    }

    void setRestaurant(Restaurant* r)
    {
        this->restaurant = r;
    }

    Restaurant* getRestaurant() const
    {
        return restaurant;
    }

    const vector<const MenuItem*> &getItems() const
    {
        return items;
    }
};

#endif //CART_H