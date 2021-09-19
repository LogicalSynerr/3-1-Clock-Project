// 3-1 Clock Project.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <iomanip>
#include "DigitalClock.h"



int main()
{

    DigitalClock clock;

    /*
    * Inifnite loop to keep the clock running until user exits.
    */
    while (true)
    {

        /*
        * function call to print the clocks
        */
        clock.PrintClock();

        /*
        * function call to print the user menu under the clocks
        */
        clock.PrintMenu();


        clock.GetUserInput();


        /*
        * Function call to clear screen to display updated data.
        */
        clock.ClearConsole();
    }

    return 0;

}

