#ifndef USER_H
#define USER_H

#include<bits/stdc++.h>
#include "Cart.h"
using namespace std;

class User {
private:
    int userId;
    string name;
    string address;
    Cart* cart;

public:
    User(int userId , const string &name , const string &address)
    {
        this->userId = userId;
        this->name = name;
        this->address = address;
        this->cart = new Cart();
    }

    ~User()
    {
        delete cart;
    }

    string getName() const
    {
        return name;
    }

    void setName(const string &n)
    {
        name = n;
    }

    string getAddress() const
    {
        return address;
    }

    void setAddress(const string &add)
    {
        address = add;
    }

    Cart* getCart()
    {
        return cart;
    }
};

#endif //USER_H