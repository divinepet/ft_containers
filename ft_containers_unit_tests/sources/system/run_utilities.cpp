#include "lib.hpp"

int main(int argc, char* argv[], char* env[]) {
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "|                                     UTILITIES                                   |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	printElement("Function"); printElement("Result"); printElement("ft time       std time      leaks"); cout << endl;

	runFunctionTest("../utilities_tests/is_integral.cpp", argv, env);
	runFunctionTest("../utilities_tests/enable_if.cpp", argv, env);
	runFunctionTest("../utilities_tests/equal.cpp", argv, env);
	runFunctionTest("../utilities_tests/lexicographical.cpp", argv, env);

	return (0);
}