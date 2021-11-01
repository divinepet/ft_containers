#pragma once
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;

const std::string GREEN = "\x1B[1;32m";
const std::string REDD = "\x1B[1;31m";
const std::string YELLOW = "\x1B[1;33m";
const std::string WHITE = "\x1B[1;39m";
const std::string RESET = "\033[0m";

void printElement(std::string t) {
	if (t == "OK") t = GREEN + t + RESET;
	else if (t == "FAILED") t = REDD + t + RESET;
	cout << std::left << std::setw(30) << std::setfill(' ') << t;
}