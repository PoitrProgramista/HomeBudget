#pragma once
#include <string>
#include <iostream>
#include <Windows.h>

namespace Prompt
{
	void prompt(const std::string& message);
	void promptAndWait(const std::string& message);
	void promptAndGet(const std::string& message, std::string& externalData);
}

