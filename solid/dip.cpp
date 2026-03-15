#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Database {
    public:
        virtual void save(string data) = 0;
};

class MySQLDatabase : public Database {
    public:
        void save(string data)
        {
            cout << "Saving to MySQLDatabase : " << data << endl;
        }
};

class MongoDBDatabase : public Database {
    public:
        void save(string data)
        {
            cout << "Saving to MongoDBDatabase : " << data << endl;
        }
};

class UserService {
    private : 
        Database* db;
    public:
        UserService(Database* db)
        {
            this->db = db;
        }

        void storeUser(string data)
        {
            db->save(data);
        }
};

int main()
{
    Database* Mysql = new MySQLDatabase();
    Database* mongodb = new MongoDBDatabase();

    UserService* service1 = new UserService(Mysql);
    service1->storeUser("Manav");

    UserService* service2 = new UserService(mongodb);
    service2->storeUser("DJ");
}