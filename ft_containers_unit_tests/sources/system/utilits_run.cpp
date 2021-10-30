#include "lib.hpp"

int main(int argc, char* argv[], char* env[]) {
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "|                                      UTILS                                      |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	printElement("Function"); printElement("Result"); printElement("ft time       std time      leaks"); cout << endl;

	runFunctionTest("../map_tests/NAME.cpp", argv, env);

	return (0);
}