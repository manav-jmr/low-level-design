#include<iostream>
#include<stdexcept>
#include<bits/stdc++.h>
using namespace std;

class twoDimensionalShape {
    public:
        virtual double area() = 0;
};

class threeDimensionalSHape {
    public:
        virtual double area() = 0;
        virtual double volume() = 0;
};

class square : public twoDimensionalShape {
    private:
        double side;
    public:
        square(double side)
        {
            this->side = side;
        }

        double area() 
        {
            return side * side;
        }
};

class cube : public threeDimensionalSHape {
    private:
        double side;
    public:
        cube(double side)
        {
            this->side = side;
        }

        double area()
        {
            return 6 * side * side;
        }

        double volume()
        {
            return side * side * side;
        }
};

int main()
{
    twoDimensionalShape* sq = new square(5);
    threeDimensionalSHape* cb = new cube(7.5);

    cout << "The area of square is " << sq->area() << endl;
    cout << "The area of cube is " << cb->area() << endl;
    cout << "The volume of cube is " << cb->volume() << endl;
}