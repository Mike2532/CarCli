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
    std::unique_ptr<ICar> car;

    void SayGreeting();
    void ShowCarInfo();
    void ExecuteWithErrorsHandling(std::function<void()>);
    void ParseCommands();
    bool HandleLine(const std::string& line);
};


#endif//OOP_3_2_CLI_H
