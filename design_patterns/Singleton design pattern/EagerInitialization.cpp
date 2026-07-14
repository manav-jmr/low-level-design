#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton()
    {
        cout << "Singleton constructor called. New object created." << endl;
    }
public:
    static Singleton* getInstance()
    {
        return instance;
    }
};

Singleton* Singleton::instance = new Singleton(); // Eager initialization

//problem - might lead to memory wastage if the instance is never used

int main()
{
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}