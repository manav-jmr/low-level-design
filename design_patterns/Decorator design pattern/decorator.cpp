#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//Component interface : defines a common interface for mario and all power up decorators
class Character {
public:
    virtual string getAbilities() const = 0;
    virtual ~Character() {}
};

//Concrete component : basic mario character with no powerups
class Mario : public Character {
public:
    string getAbilities() const 
    {
        return "Mario ";
    }
};

//Abstract decorator : CharacterDecorator "is-a" character and "has-a" character
class CharacterDecorator : public Character {
protected:
    Character* character; //Wrapped component

public:
    CharacterDecorator(Character* c)
    {
        this->character = c;
    }
};

//Concrete decorator: Height - Increasing power up
class HeightUp : public CharacterDecorator {
public:
    HeightUp(Character* c) : CharacterDecorator(c) { }

    string getAbilities() const 
    {
        return character->getAbilities() + "with HeightUp ";
    }
};

//Concrete decorator: Gun - Shooting power up
class GunPowerUp : public CharacterDecorator {
public:
    GunPowerUp(Character* c) : CharacterDecorator(c) { }

    string getAbilities() const 
    {
        return character->getAbilities() + "with Gun ";
    }
};

//Concrete decorator: Star - power up(temporary ability)
class StarPowerUp : public CharacterDecorator {
public:
    StarPowerUp(Character* c) : CharacterDecorator(c) { }

    string getAbilities() const 
    {
        return character->getAbilities() + "with Star Power (limited time)";
    }

    ~StarPowerUp() {
        cout << "Destroying StarPowerUp decorator" << endl;
    }
};

int main()
{
    //Create a basic mario character
    Character* mario = new Mario();
    cout << "Basic Character: " << mario->getAbilities() << endl;

    //Decorate mario with HeightUp power up
    Character* heightUpMario = new HeightUp(mario);
    cout << "After HeightUp: " << heightUpMario->getAbilities() << endl;

    //Decorate mario with Gun power up
    Character* gunMario = new GunPowerUp(heightUpMario);
    cout << "After Gun Power Up: " << gunMario->getAbilities() << endl;

    //Decorate mario with Star power up
    Character* starMario = new StarPowerUp(gunMario);
    cout << "After Star Power Up: " << starMario->getAbilities() << endl;

    delete mario; // Clean up the basic mario character
    delete heightUpMario; // Clean up the height-up decorated character
    delete gunMario; // Clean up the gun decorated character
    delete starMario; // Clean up the star decorated character

    return  0;
}

