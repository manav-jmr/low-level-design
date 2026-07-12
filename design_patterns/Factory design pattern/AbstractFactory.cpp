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

class GarlicBread {
public:
    virtual void prepare() = 0;
};

class BasicGarlicBread : public GarlicBread {
public:
    void prepare()
    {
        cout << "Preparing basic garlic bread with butter and garlic!" << endl;
    }
};

class CheeseGarlicBread : public GarlicBread {
public:
    void prepare()
    {
        cout << "Preparing cheesy garlic bread with extra cheese and butter !" << endl;
    }
};

class BasicWheatGarlicBread : public GarlicBread {
public:
    void prepare()
    {
        cout << "Preparing basic wheat garlic bread with butter and garlic!!" << endl;
    }
};

class CheeseWheatGarlicBread : public GarlicBread {
public:
    void prepare()
    {
        cout << "Preparing cheesy wheat garlic bread with extra cheese and butter !" << endl;
    }
};

class MealFactory {
public:
    virtual Burger* createBurger(string &type) = 0;
    virtual GarlicBread* createGarlicBread(string &type) = 0;
};

class SinghBurger : public MealFactory {
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

    GarlicBread* createGarlicBread(string &type)
    {
        if(type == "basic")
        {
            return new BasicGarlicBread();
        }
        else if(type == "cheesy")
        {
            return new CheeseGarlicBread();
        }
        else 
        {
            cout << "Invalid garlic bread type!" << endl;
            return nullptr;
        }
    }
};

class KingBurger : public MealFactory {
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

    GarlicBread* createGarlicBread(string &type)
    {
        if(type == "basic")
        {
            return new BasicWheatGarlicBread();
        }
        else if(type == "cheese")
        {
            return new CheeseWheatGarlicBread();
        }
        else 
        {
            cout << "Invalid garlic bread type!" << endl;
            return nullptr;
        }
    }
};

int main()
{
    string burgerType = "basic";
    string garlicBreadType = "cheese";

    MealFactory* myFactory = new KingBurger();

    Burger* burger = myFactory->createBurger(burgerType);
    GarlicBread* garlicBread = myFactory->createGarlicBread(garlicBreadType);

    burger->prepare();
    garlicBread->prepare();

    return 0;
}
