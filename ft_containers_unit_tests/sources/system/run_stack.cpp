#include "lib.hpp"

int main(int argc, char* argv[], char* env[]) {
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "|                                       STACK                                     |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	printElement("Function"); printElement("Result"); printElement("ft time       std time      leaks"); cout << endl;

	runFunctionTest("../stack_tests/constructor.cpp", argv, env);
	runFunctionTest("../stack_tests/push().cpp", argv, env);
	runFunctionTest("../stack_tests/top().cpp", argv, env);
	runFunctionTest("../stack_tests/pop().cpp", argv, env);
	runFunctionTest("../stack_tests/size().cpp", argv, env);
	runFunctionTest("../stack_tests/empty().cpp", argv, env);
	return 0;
}