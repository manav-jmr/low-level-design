#include<iostream>
using namespace std;

class Burger {
public:
    virtual void prepare() = 0;
    virtual ~Burger() {};
};

class BasicBurger : public Burger {
public:
    void prepare()
    {
        cout << "Preparing basic burger with bun , pattty and ketchup!" << endl;
    }
};

class StandardBurger : public Burger {
public:
    void prepare()
    {
        cout << "Preparing standard burger with bun , patty , cheese and lettuce!" << endl;
    }
};

class PremiumBurger : public Burger {
public:
    void prepare()
    {
        cout << "Preparing premium burger with bun , premium patty , cheese , lettuce and secret sauce!" << endl;
    }
};

class BasicWheatBurger : public Burger {
public:
    void prepare()
    {
        cout << "Preparing basic wheat burger with bun , pattty and ketchup!" << endl;
    }
};

class StandardWheatBurger : public Burger {
public:
    void prepare()
    {
        cout << "Preparing standard wheat burger with bun , patty , cheese and lettuce!" << endl;
    }
};

class PremiumWheatBurger : public Burger {
public:
    void prepare()
    {
        cout << "Preparing premium wheat burger with bun , premium patty , cheese , lettuce and secret sauce!" << endl;
    }
};

class BurgerFactory {
public:
    virtual Burger* createBurger(string &type) = 0;
};

class SinghBurger : public BurgerFactory {
public:
    Burger* createBurger(string &type)
    {
        if(type == "basic")
        {
            return new BasicBurger();
        }
        else if(type == "standard")
        {
            return new StandardBurger();
        }
        else if(type == "premium")
        {
            return new PremiumBurger();
        }
        else 
        {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};

class KingBurger : public BurgerFactory {
public:
    Burger* createBurger(string &type)
    {
        if(type == "basic")
        {
            return new BasicWheatBurger();
        }
        else if(type == "standard")
        {
            return new StandardWheatBurger();
        }
        else if(type == "premium")
        {
            return new PremiumWheatBurger();
        }
        else 
        {
            cout << "Invalid burger type!" << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "basic";

    BurgerFactory* myFactory = new KingBurger();

    Burger* burger = myFactory->createBurger(type);

    burger->prepare();

    return 0;
}

