#include "Prompt.h"


void Prompt::prompt(const std::string & message)
{
	std::cout << message << std::endl;
}

void Prompt::promptAndWait(const std::string & message)
{
	system("cls");
	std::cout << message << std::endl;
	Sleep(1500);
}

void Prompt::promptAndGet(const std::string & message, std::string & externalData)
{
	std::cout << message;
	std::cin >> externalData;
}
