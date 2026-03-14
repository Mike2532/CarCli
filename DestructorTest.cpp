#include <iostream>

class ICar {
public:
    ~ICar()
    {
        std::cout << "ICar destroyed\n";
    }
};

class Car : public ICar {
public:
    ~Car()
    {
        std::cout << "Car destroyed\n";
    }
};

class ICarTwo {
public:
    virtual ~ICarTwo()
    {
        std::cout << "ICarTwo destroyed\n";
    }
};

class CarTwo : public ICarTwo {
public:
    ~CarTwo()
    {
        std::cout << "CarTwo destroyed\n";
    }
};

int main() {
    std::cout << "no virtual destructor\n";
    ICar* car = new Car();
    delete car;

    std::cout << "\nhas virtual destructor\n";
    ICarTwo* carTwo = new CarTwo();
    delete carTwo;
}