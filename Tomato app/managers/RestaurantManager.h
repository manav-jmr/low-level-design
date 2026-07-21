#ifndef RESTAURANT_MANAGER_H
#define RESTAURANT_MANAGER_H

#include <iostream>
#include <string>   
#include<bits/stdc++.h>
#include "../models/Restaurant.h"
using namespace std;

class RestaurantManager {
private:
    vector<Restaurant*> restaurants;
    static RestaurantManager* instance;

    RestaurantManager() {
        //private constructor to prevent instantiation
    }

public:
    static RestaurantManager* getInstance()
    {
        if(!instance)
        {
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* r)
    {
        restaurants.push_back(r);
    }

    vector<Restaurant*> searchByLocation(string loc)
    {
        vector<Restaurant*> ans;
        transform(loc.begin() , loc.end(), loc.begin() , ::tolower);

        for(auto it : restaurants)
        {
            string rl = it->getLocation();
            transform(rl.begin() , rl.end() , rl.begin() , ::tolower);
            if(rl == loc)
            {
                ans.push_back(it);
            }
        }

        return ans;
    }
};

RestaurantManager* RestaurantManager::instance = nullptr;

#endif // RESTAURANT_MANAGER_H