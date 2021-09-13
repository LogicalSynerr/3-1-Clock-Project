// 3-1 Clock Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <iomanip>

/*
* Function to clear console so new data can be displayed
*/
void ClearConsole() {
    for (int i = 0; i < 40; ++i) {
        std::cout << std::endl;
    }
}

/*
* Outputs the digital clocks to the console.
*/
void PrintClock(int hr, int min, int sec)
{

    /*
    * Single line conditional statements to set the 12 hour clock correctly.
    */
    std::string amPm = (hr > 11) ? "PM" : "AM";
    int hr12 = (hr > 12) ? hr - 12 : hr;
    hr12 = (hr12 == 0) ? 12 : hr12;

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
void PrintMenu()
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
int GetUserInput()
{
    int userChoice;
    std::cin >> userChoice;
    return userChoice;
}

int main()
{

    /*
    * Declare and initialize hour, minute, and seconds.
    */
    int hr = 12;
    int min = 30;
    int sec = 30;

    /*
    * Inifnite loop to keep the clock running until user exits.
    */
    while (true)
    {
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
        * function call to print the clocks
        */
        PrintClock(hr, min, sec);

        /*
        * function call to print the user menu under the clocks
        */
        PrintMenu();

        /*
        * switch statment calls funtion to get user input and then process the input according to the options stated in the user menu.
        */
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

        /*
        * Function call to clear screen to display updated data.
        */
        ClearConsole();
    }

    return 0;

}

