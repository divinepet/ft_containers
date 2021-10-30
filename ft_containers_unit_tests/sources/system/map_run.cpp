#include "lib.hpp"

int main(int argc, char* argv[], char* env[]) {
//	cout << "-----------------------------------------------------------------------------------" << endl;
//	cout << "|                                     ALGORITHMS                                  |" << endl;
//	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "|                                         MAP                                      |" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	printElement("Function"); printElement("Result"); printElement("ft time       std time      leaks"); cout << endl;

	runFunctionTest("../map_tests/constructor.cpp", argv, env);
	runFunctionTest("../map_tests/assign_overload.cpp", argv, env);
	runFunctionTest("../map_tests/iterators.cpp", argv, env);
	runFunctionTest("../map_tests/reverse_iterators.cpp", argv, env);
	runFunctionTest("../map_tests/comparator.cpp", argv, env);
	runFunctionTest("../map_tests/insert_value.cpp", argv, env);
	runFunctionTest("../map_tests/insert_iterators.cpp", argv, env);
	runFunctionTest("../map_tests/insert_hint.cpp", argv, env);
	runFunctionTest("../map_tests/at.cpp", argv, env);
	runFunctionTest("../map_tests/operator[].cpp", argv, env);
	runFunctionTest("../map_tests/empty.cpp", argv, env);
	runFunctionTest("../map_tests/size.cpp", argv, env);
	runFunctionTest("../map_tests/max_size.cpp", argv, env);
	runFunctionTest("../map_tests/clear.cpp", argv, env);
	runFunctionTest("../map_tests/erase_key.cpp", argv, env);
	runFunctionTest("../map_tests/erase_pos.cpp", argv, env);
	runFunctionTest("../map_tests/erase_iterators.cpp", argv, env);
	runFunctionTest("../map_tests/swap.cpp", argv, env);
	runFunctionTest("../map_tests/count.cpp", argv, env);
	runFunctionTest("../map_tests/find.cpp", argv, env);
	runFunctionTest("../map_tests/lower_bound.cpp", argv, env);
	runFunctionTest("../map_tests/upper_bound.cpp", argv, env);
	runFunctionTest("../map_tests/equal_range.cpp", argv, env);
	runFunctionTest("../map_tests/key_comp.cpp", argv, env);
	runFunctionTest("../map_tests/operator==.cpp", argv, env);
	runFunctionTest("../map_tests/operator!=.cpp", argv, env);
	runFunctionTest("../map_tests/operator<.cpp", argv, env);
	runFunctionTest("../map_tests/operator>.cpp", argv, env);
	runFunctionTest("../map_tests/operator<=.cpp", argv, env);
	runFunctionTest("../map_tests/operator>=.cpp", argv, env);

	return (0);
}