#include "DigitalClock.h"

#include <iostream>
#include <string>
#include <iomanip>


/*
* initialize variables in constructor.
*/
DigitalClock::DigitalClock()
{
    hr = 12;
    min = 30;
    sec = 30;
}

/*
* Function to clear console so new data can be displayed
*/
void DigitalClock::ClearConsole() {
    for (int i = 0; i < 40; ++i) {
        std::cout << std::endl;
    }
}

/*
* Outputs the digital clocks to the console.
*/
void DigitalClock::PrintClock()
{

    /*
    * Single line conditional statements to set the 12 hour clock correctly.
    */
    std::string amPm = (hr > 11) ? "PM" : "AM";
    int hr12 = (hr > 12) ? hr - 12 : hr;
    hr12 = (hr12 == 0) ? 12 : hr12;

    /*
    * If statments to keep sec and min under 60 and hr under 23.
    */
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

    /*
    * Outputs to console, use setfill and setw funtions to format the numbers to always have 2 digits.
    */
    std::cout << "***************************\t***************************" << std::endl;
    std::cout << "*      12-Hour Clock      *\t*      24-Hour Clock      *" << std::endl;
    std::cout << "*       " << std::setfill('0') << std::setw(2) << hr12 << ":" << std::setfill('0') << std::setw(2) << min << ":" << std::setfill('0') << std::setw(2) << sec << " " << amPm << "       *";
    std::cout << "\t";
    std::cout << "*        " << std::setfill('0') << std::setw(2) << hr << ":" << std::setfill('0') << std::setw(2) << min << ":" << std::setfill('0') << std::setw(2) << sec << "         *" << std::endl;
    std::cout << "***************************\t***************************" << std::endl;
}

/*
* Outputs user menu to the console.
*/
void DigitalClock::PrintMenu()
{
    std::cout << "\n\n**************************" << std::endl;
    std::cout << "* 1 - Add One Hour       *" << std::endl;
    std::cout << "* 2 - Add One Minute     *" << std::endl;
    std::cout << "* 3 - Add One Second     *" << std::endl;
    std::cout << "* 4 - Exit Program       *" << std::endl;
    std::cout << "**************************" << std::endl;

}

/*
* Fuction that stores user input into a fuction and returns the function.
*/
void DigitalClock::GetUserInput()
{
    int userChoice;
    std::cin >> userChoice;

    /*
    * switch statment calls funtion to get user input and then process the input according to the options stated in the user menu.
    */
    switch (userChoice)
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
}

