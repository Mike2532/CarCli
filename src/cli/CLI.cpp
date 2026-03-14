#include "CLI.h"
#include <sstream>
#include <iostream>
#include <string>

void CLI::ServeApp()
{
    SayGreeting();
    ParseCommands();
}

void CLI::ParseCommands()
{
    std::string line;

    while (getline(std::cin, line) && HandleLine(line))
    {}
}

bool CLI::HandleLine(const std::string& line)
{
    if (line.empty())
    {
        return true;
    }

    std::stringstream stringstream(line);
    std::string firstArc;
    stringstream >> firstArc;

    if (firstArc == "exit")
    {
        return false;
    }
    if (firstArc == "--help")
    {
        ShowCarInfo();
        return true;
    }
    if (firstArc == "EngineOn")
    {
        ExecuteWithErrorsHandling([this](){
            car->TurnOnEngine();
        });
        return true;
    }
    if (firstArc == "EngineOff")
    {
        ExecuteWithErrorsHandling([this](){
            car->TurnOffEngine();
        });
        return true;
    }
    if (firstArc == "Info")
    {
        ExecuteWithErrorsHandling([this](){
            car->PrintState();
        });
        return true;
    }
    if (firstArc == "SetGear" || firstArc == "SetSpeed")
    {
        std::string secondArc;
        stringstream >> secondArc;
        int val = 0;
        try
        {
            val = stoi(secondArc);
        } catch (const std::exception& e)
        {
            std::cout << "invalid second argument\n";
            return true;
        }
        ExecuteWithErrorsHandling([this, firstArc, val](){
            if (firstArc == "SetGear")
            {
                car->SetGear(val);
                return;
            }
            car->SetSpeed(val);
        });
        return true;
    }
    std::cout << "unknown command\n";
    return true;
}

void CLI::SayGreeting()
{
    std::cout << "wecome to car CLI app. To get clue write \"--help\"\n";
}

void CLI::ExecuteWithErrorsHandling(std::function<void()> func)
{
    try
    {
        func();
    } catch (std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
}

void CLI::ShowCarInfo()
{
    std::cout <<
            "exit – exit from app\n"
            "EngineOn – turn on car engine\n"
            "EngineOff – turn off car engine\n"
            "Info – show car status\n"
            "SetGear X – change gear to X (x ∈ [-1;5])\n"
            "SetSpeed X – change speed to X (x depends from cur gear)\n"
            "speeds limist from gear:\n"
            "\t-1: 0-20\n"
            "\t0: no limits but you can not rase your speed\n"
            "\t1: 0-30\n"
            "\t2: 20-50\n"
            "\t3: 30-60\n"
            "\t4: 40-90\n"
            "\t5: 50-150\n";
}