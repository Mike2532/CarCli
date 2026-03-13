#ifndef OOP_3_2_CLI_H
#define OOP_3_2_CLI_H

#include "../car/ICar.h"

class CLI
{
public:
    CLI(std::unique_ptr<ICar> car)
    {
        this->car = std::move(car);
    }

    void ServeApp();
private:
    void SayGreeting();
    void ShowCarInfo();
    void ExecuteWithErrorsHandling(std::function<void()>);

    std::unique_ptr<ICar> car;
};


#endif//OOP_3_2_CLI_H
