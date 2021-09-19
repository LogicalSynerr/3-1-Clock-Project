#pragma once
class DigitalClock
{
public:
	DigitalClock();
	void ClearConsole();
	void PrintMenu();
	void PrintClock();
	void GetUserInput();

private:
	int hr;
	int min;
	int sec;

};

