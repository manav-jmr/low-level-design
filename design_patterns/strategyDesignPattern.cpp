#include<iostream>
#include <bits/stdc++.h>
using namespace std;

class walkableRobot {
public:
    virtual void walk() = 0;
    virtual ~walkableRobot() {}    
};

class normalWalk : public walkableRobot {
public:
    void walk()
    {
        cout << "Walking normally ... " << endl;
    }
};

class noWalk : public walkableRobot {
public:
    void walk()
    {
        cout << "Cannot walk ... " << endl;
    }
};

class talkableRobot {
public:
    virtual void talk() = 0;
    virtual ~talkableRobot () {}
};

class normalTalk : public talkableRobot {
public:
    void talk () 
    {
        cout << "Talking normally ... " << endl;
    }
};

class noTalk : public talkableRobot {
public:
    void talk()
    {
        cout << "Cannot talk ..." << endl;
    }
};

class flyableRobot {
public: 
    virtual void fly() = 0;
    virtual ~flyableRobot () {}
};

class normalFly : public flyableRobot {
public:
    void fly()
    {
        cout << "Flying normally .... " << endl;
    }
};

class noFly : public flyableRobot {
public:
    void fly()
    {
        cout << "Cannot fly ...." << endl;
    }
};

class Robot {
protected:
    walkableRobot* walkBehaviour;
    talkableRobot* talkBehaviour;
    flyableRobot* flyBehaviour;

public:
    Robot(walkableRobot* w , talkableRobot* t , flyableRobot* f)
    {
        this->walkBehaviour = w;
        this->talkBehaviour = t;
        this->flyBehaviour = f;
    }

    void walk()
    {
        walkBehaviour->walk();
    }

    void talk()
    {
        talkBehaviour->talk();
    }

    void fly()
    {
        flyBehaviour->fly();
    }

    virtual void projection() = 0;
};

class companionRobot : public Robot{
public:
    companionRobot(walkableRobot* w , talkableRobot* t , flyableRobot* f) : Robot(w , t , f) {}

    void projection()
    {
        cout << "Displaying friendly companion features .... " << endl;
    }
};

class workerRobot : public Robot {
public:
    workerRobot(walkableRobot* w , talkableRobot* t , flyableRobot* f) : Robot(w , t , f) {}

    void projection()
    {
        cout << "Displaying worker efficiency stats .... " << endl;
    }
};

int main()
{
    Robot* robot1 = new companionRobot(new normalWalk() , new normalTalk() , new noFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();

    cout << "................................" << endl;

    Robot* robot2 = new workerRobot(new noWalk() , new noTalk() , new normalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
}
