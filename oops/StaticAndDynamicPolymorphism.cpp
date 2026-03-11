#include<iostream>
using namespace std;

class car{
    protected:
        string model;
        string brand;
        bool isEngineOn;
        int currSpeed;
    
    public:
        car(string brand , string model)
        {
            this->brand = brand;
            this->model = model;
            this->isEngineOn = false;
            this->currSpeed = 0;
        }

        void startEngine()
        {
            if(isEngineOn)
            {
                cout << "Engine is already on" << endl;
            }
            else 
            {
                isEngineOn = true;
                cout << "Engine started" << endl;
            }
        }

        void stopEngine()
        {
            if(!isEngineOn)
            {
                cout << "Engine is already off" << endl;
            }
            else 
            {
                isEngineOn = false;
                currSpeed = 0;
                cout << "Engine has been switched off" << endl;
            }
        }

        virtual void accelerate() = 0;
        
        virtual void accelerate(int speed) = 0;

        virtual void brake() = 0;

        virtual ~car() {};
};

class manualCar : public car{
    private : 
        int currGear;

    public:

        manualCar(string brand , string model) : car(brand , model)
        {   
            this->currGear = 0;
        }

        void changeGear(int gear)
        {
            currGear = gear;
            cout << brand << " " << model << " " << "gear changed to " << currGear << endl;
        }

        void accelerate()
        {
            if(!isEngineOn)
            {
                cout << brand << " " << model << " " << "Engine is switched off" << endl;
                return;
            }
            currSpeed += 20;
            cout << brand << " " << model << " " << "speed is increased by 20 to " << currSpeed << endl;
        }

        void accelerate(int speed)
        {
            if(!isEngineOn)
            {
                cout << brand << " " << model << " " << "Engine is already off" << endl;
                return;
            }
            currSpeed += speed;
            cout << brand << " " << model << " " << "speed is increased by " << speed << " to " << currSpeed << endl;
        }

        void brake()
        {
            if(!isEngineOn)
            {
                cout << brand << " " << model << " " << "Engine is switched off" << endl;
                return;
            }
            if(currSpeed < 0)
            {
                currSpeed = 0;
            }
            currSpeed -= 20;
            cout << brand << " " << model << " " << "speed is decreased by 20 to " << currSpeed << endl;
        }
};

class electricCar : public car{
    private : 
        int currBattery;

    public:

        electricCar(string brand , string model) : car(brand , model)
        {   
            this->currBattery = 100;
        }

        void chargeBattery()
        {
            if(currBattery == 100)
            {
                cout << brand << " " << model << " " << "already full charged" << endl;
            }
            currBattery = 100;
            cout << brand << " " << model << " " << "battery charged to 100 " << endl;
        }

        void accelerate()
        {
            if(!isEngineOn)
            {
                cout << brand << " " << model << " " << "Engine is switched off" << endl;
                return;
            }
            if(currBattery <= 0)
            {
                cout << brand << " " << model << " " << "has 0% battery. Please charge immediately !" << endl;
                return;
            }
            currSpeed += 20;
            currBattery -= 10;
            cout << brand << " " << model << " " << "speed is increased by 20 to " << currSpeed << endl;
        }

        void accelerate(int speed)
        {
            if(!isEngineOn)
            {
                cout << brand << " " << model << " " << "Engine is already off" << endl;
                return;
            }
             if(currBattery <= 0)
            {
                cout << brand << " " << model << " " << "has 0% battery. Please charge immediately !" << endl;
                return;
            }
            currSpeed += speed;
            currBattery -= 10;
            cout << brand << " " << model << " " << "speed is increased by" << speed << " to " << currSpeed << endl;
        }

        void brake()
        {
            if(!isEngineOn)
            {
                cout << brand << " " << model << " " << "Engine is switched off" << endl;
                return;
            }
            currSpeed -= 20;
            if(currSpeed < 0)
            {
                currSpeed = 0;
            }
            cout << brand << " " << model << " " << "speed is decreased by 20" << endl;
        }
};

int main()
{
    manualCar* manualCar1 = new manualCar("Audi" , "Q7");
    manualCar1 -> startEngine();
    manualCar1 -> accelerate();
    manualCar1 -> changeGear(3);
    manualCar1 -> accelerate(40);
    manualCar1 -> brake();
    manualCar1 -> stopEngine();

    cout << "------------------------------" << endl;

    electricCar* electricCar1 = new electricCar("Tesla" , "Model S");
    electricCar1 -> startEngine();
    electricCar1 -> accelerate();
    electricCar1 -> accelerate(40);
    electricCar1 -> brake();
    electricCar1 -> chargeBattery();
    electricCar1 -> stopEngine();
}