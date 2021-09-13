// 3-1 Clock Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <iomanip>

void ClearConsole() {
    for (int i = 0; i < 40; ++i) {
        std::cout << std::endl;
    }
}

void PrintClock(int hr, int min, int sec)
{
    std::string amPm = (hr > 11) ? "PM" : "AM";
    int hr12 = (hr > 12) ? hr - 12 : hr;
    hr12 = (hr12 == 0) ? 12 : hr12;

    std::cout << "***************************\t***************************" << std::endl;
    std::cout << "*      12-Hour Clock      *\t*      24-Hour Clock      *" << std::endl;
    std::cout << "*       " << std::setfill('0') << std::setw(2) << hr12 << ":" << std::setfill('0') << std::setw(2) << min << ":" << std::setfill('0') << std::setw(2) << sec << " " << amPm << "       *";
    std::cout << "\t";
    std::cout << "*        " << std::setfill('0') << std::setw(2) << hr << ":" << std::setfill('0') << std::setw(2) << min << ":" << std::setfill('0') << std::setw(2) << sec << "         *" << std::endl;
    std::cout << "***************************\t***************************" << std::endl;
}

void PrintMenu()
{
    std::cout << "\n\n**************************" << std::endl;
    std::cout << "* 1 - Add One Hour       *" << std::endl;
    std::cout << "* 2 - Add One Minute     *" << std::endl;
    std::cout << "* 3 - Add One Second     *" << std::endl;
    std::cout << "* 4 - Exit Program       *" << std::endl;
    std::cout << "**************************" << std::endl;

}

int GetUserInput()
{
    int userChoice;
    std::cin >> userChoice;
    return userChoice;
}

int main()
{
    int hr = 12;
    int min = 30;
    int sec = 30;
    while (true)
    {
        if (sec > 59)
        {
            sec = 0;
            min++;
        }
        if (min > 59)
        {
            min = 0;
            hr++;
        }
        if (hr > 23)
        {
            hr = 0;
        }
        PrintClock(hr, min, sec);

        PrintMenu();

        switch (GetUserInput())
        {
        case 1:
            hr++;
            break;
        case 2:
            min++;
            break;
        case 3:
            sec++;
            break;
        case 4:
            exit(0);
        default:
            break;
        }

        ClearConsole();
    }

    return 0;

}

