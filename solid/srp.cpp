#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Product{
    public :
        string name;
        double price;

        Product(string name , double price)
        {
            this->name = name;
            this->price = price;
        }
};

class shoppingCart {
    private:
        vector<Product*> products;
    public:
        void addProduct(Product* p)
        {
            products.push_back(p);
        }

        const vector<Product*>& getProduct()
        {
            return products;
        }

        double calcuLateTotal()
        {
            double tot = 0;
            for(auto &it : products)
            {
                tot += it->price;
            }

            return tot;
        }
};

class shopingCartPrinter {
    private:
        shoppingCart* cart;
    public:
        shopingCartPrinter(shoppingCart* cart)
        {
            this->cart = cart;
        }

        void printInvoice()
        {
            cout << "Your invoice is : " << endl;

            for(auto &it : cart->getProduct())
            {
                cout << it->name << "-Rs " << it->price << endl; 
            }
            cout << "The total price is " << cart->calcuLateTotal() << endl;
        }
};

class shoippingCartStorage {
    private : 
        shoppingCart* cart;
    public:
        shoippingCartStorage(shoppingCart* cart)
        {
            this->cart = cart;
        }

        void saveToDatabase()
        {
            cout << "Saving cart to database ...." << endl;
        }
};

int main()
{
    Product* prod1 = new Product("laptop" , 65000);
    Product* prod2 = new Product("Mouse" , 2000);
    Product* prod3 = new Product("keyboard" , 10000);

    shoppingCart* myCart = new shoppingCart();

    myCart->addProduct(prod1);
    myCart->addProduct(prod2);
    myCart->addProduct(prod3);

    shopingCartPrinter* printer = new shopingCartPrinter(myCart);
    printer->printInvoice();

    shoippingCartStorage* db = new shoippingCartStorage(myCart);
    db->saveToDatabase();
}

