#ifndef MENUITEM_H
#define MENUITEM_H

#include <iostream>
#include <string>
using namespace std;

class MenuItem {
private:
    string code;
    string name;
    int price;
public:
    MenuItem(const string &code , const string &name , int price)
    {
        this->code = code;
        this->name = name;
        this->price = price;
    }

    string getCode() const 
    {
        return code;
    }

    void setCode(const string &code) 
    {
        this->code = code;
    }

    string getName() const 
    {
        return name;
    }

    void setName(const string &name) 
    {
        this->name = name;
    }

    int getPrice() const 
    {
        return price;
    }

    void setPrice(int price) 
    {
        this->price = price;
    }
};
#endif // MENUITEM_H